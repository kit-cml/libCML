#include "softdongle.hpp"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <curl/curl.h>
#include <json-c/json.h>
#include <string>

#include "../types/cml_consts.hpp"
#include "inputoutput.hpp"

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t total_size = size * nmemb;
  ApiResponse *response = (ApiResponse*)userp;

  char *ptr = (char*)realloc(response->memory, response->size + total_size + 1);
  if (ptr == NULL) return 0;

  response->memory = ptr;
  memcpy(&(response->memory[response->size]), contents, total_size);
  response->size += total_size;
  response->memory[response->size] = 0;

  return total_size;
}

int get_response_from_api(ApiResponse *p_response)
{
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if(curl == NULL){
    mpi_fprintf(cml::commons::MASTER_NODE, stderr, "Problem occured on cURL initialization!!\n");
    return -1;
  }

  curl_easy_setopt(curl, CURLOPT_URL, cml::network::TIME_API_URL);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)p_response);


  res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    mpi_fprintf(cml::commons::MASTER_NODE, stderr, "Failed to fetch time: %s\n", curl_easy_strerror(res));
    free(p_response->memory);
    curl_easy_cleanup(curl);
    return -1;
  }

  curl_easy_cleanup(curl);
  return 0;
}

time_t get_unix_time_from_json(ApiResponse *p_response)
{
  struct json_object *parsed_json;
  struct json_object *date_time_obj;

  printf("JSON: %s\n", p_response->memory);
  parsed_json = json_tokener_parse(p_response->memory);
  if (!parsed_json) {
    mpi_fprintf(cml::commons::MASTER_NODE, stderr, "Error parsing JSON\n");
    return -1;
  }

  if (!json_object_object_get_ex(parsed_json, "dateTime", &date_time_obj)) {
    mpi_fprintf(cml::commons::MASTER_NODE, stderr, "JSON key 'dateTime' not found\n");
    json_object_put(parsed_json);
    return -1;
  }

  const char *date_time_str;
  date_time_str = json_object_get_string(date_time_obj);
  time_t unix_time = datetime_to_unixtime(date_time_str);
  return unix_time;
}

time_t datetime_to_unixtime(const char *datetime_str )
{
  struct tm tm;
  double fractional_seconds;
    
  // Parse the date string without fractional seconds
  if (strptime(datetime_str, "%Y-%m-%dT%H:%M:%S", &tm) == NULL) {
    mpi_fprintf(cml::commons::MASTER_NODE, stderr, "Error parsing the date string.\n");
    return -1;
  }

  // Uncomment these 3 lines for debugging.
  //printf("Today is %d - %d %d, %d ---- %d:%d:%d\n", 
  //      tm.tm_wday, tm.tm_mon+1,tm.tm_mday,1900 + tm.tm_year,
  //      tm.tm_hour, tm.tm_min, tm.tm_sec);

  // Convert the tm structure to time_t (Unix timestamp)
  time_t unix_time = mktime(&tm);
    
  // Uncomment for debugging.
  //mpi_printf(cml::commons::MASTER_NODE, "Unix Timestamp: %ld\n", unix_time);

  return unix_time;
}

std::string get_machine_uuid() {
  FILE *fp_machine_uuid = fopen(cml::security::MACHINE_UUID_FILE,"r");
  if (fp_machine_uuid == NULL) {
    fp_machine_uuid = fopen(cml::security::MACHINE_UUID_BACKUP_FILE,"r");
    if (fp_machine_uuid == NULL) {
      return "MACHINE_UUID_ERROR";
    }
  }
  char buffer[255];
  fgets(buffer, sizeof(buffer), fp_machine_uuid);
  fclose(fp_machine_uuid);
  std::string uuid(buffer);
  if (!uuid.empty() && uuid.back() == '\n') {
    uuid.pop_back();  // Removes the last character if it's '\n'
  }
  return uuid;
}

// if this one failed,
// change the permission with this command.
//
// sudo chmod +r /sys/class/dmi/id/product_uuid
std::string get_system_uuid() {
  FILE *fp_system_uuid = fopen(cml::security::SYSTEM_UUID_FILE,"r");
  if (fp_system_uuid == NULL) {
    return "SYSTEM_UUID_ERROR";
  }
  char buffer[255];
  fgets(buffer, sizeof(buffer), fp_system_uuid);
  fclose(fp_system_uuid);
  std::string uuid(buffer);
  if (!uuid.empty() && uuid.back() == '\n') {
    uuid.pop_back();  // Removes the last character if it's '\n'
  }
  return uuid;
}

std::string get_hardware_id()
{
	return get_machine_uuid() + "==" + get_system_uuid();
}

int validate_license()
{
  ApiResponse p_response = {0};

  int api_retval = get_response_from_api(&p_response);
  if(api_retval < 0){
    return -1;
  }
  printf("API message: %s\n", p_response.memory);
  time_t unix_time = get_unix_time_from_json(&p_response);
  printf("UnixTime: %ld\n", unix_time);

  std::string hardware_id = get_hardware_id();
  printf("Hardware ID: %s\n", hardware_id.c_str());

  FILE *fp_license = fopen("cardiosim_license.dat","rb");
  if(fp_license == NULL){
    printf("Cannot open license file! Make sure the cardiosim_license.dat is existing!\n");
    return -1;
  }
  // Read the length of the string
  size_t size;
  fread(&size, sizeof(size_t), 1, fp_license);

  // Read the string data
  char* buffer = new char[size + 1];  // Allocate buffer (+1 for null-terminator)
  fread(buffer, sizeof(char), size, fp_license);
  buffer[size] = '\0';  // Null-terminate the string
  std::string license_hardware_id = std::string(buffer);  // Assign buffer to std::string
  delete[] buffer;  // Free memory

  // Read the timestamp
  time_t license_unix_time;
  fread(&license_unix_time, sizeof(std::time_t), 1, fp_license);

  fclose(fp_license);

  // uncomment only for debugging.
  printf("%ld\n%s\n%ld\n", size, license_hardware_id.c_str(), license_unix_time);
  printf("Correct hardware: %d\nPeriod passed from the beginning: %lf days\n",
  license_hardware_id.compare(hardware_id),
  abs(license_unix_time-unix_time) * cml::math::SECONDS_TO_DAYS);
  if( license_hardware_id.compare(hardware_id) != 0 || abs(license_unix_time-unix_time) > (cml::security::TRIAL_PERIOD_DAYS * cml::math::DAYS_TO_SECONDS)  ){
    mpi_fprintf(cml::commons::MASTER_NODE, stderr, "Please renew the license by contacting MetaHeart!\n");
    return -1;
  }

  return 0;
}
