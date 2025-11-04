#ifndef SOFTDONGLE_HPP
#define SOFTDONGLE_HPP

#include <ctime>
#include <string>

#include "../types/cml_consts.hpp"

// softdongle.hpp
//
// Contains functions for locking the software
// based on the hardware ID and/or time period.
//
// Hardware ID will use POSIX functions for retrieving
// the device ID (MAC Address or any other component).
// Google NTP will be used for time period checking.

// All functions related to the time-locking.
typedef struct MemoryStruct{
  char *memory;
  size_t size;
}ApiResponse;
static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);
int get_response_from_api(ApiResponse *p_response);
time_t get_unix_time_from_json(ApiResponse *p_response);
time_t datetime_to_unixtime(const char *datetime_str );
void unixtime_to_datetime(time_t unix_time, char *datetime_str, size_t buf_size);

// All functions related to the hardware.
std::string get_machine_uuid();
std::string get_system_uuid();
std::string get_hardware_id();

// main function header for validating license
int validate_license();

#endif
