#ifndef CML_CONSTS_HPP
#define CML_CONSTS_HPP

#include <string>
#include <unordered_map>
#include <vector>

// Collection of namespaces to define global constants.
// Please put your constants variable according 
// to the category provided below.
// If you need to define a new category, let me know.

// Naming of namespace should be one word and simple.
// Namespace name only have small letters, short, and concise.
// Constants name should have only capital letters and underscore
// as the separator.

namespace cml{
  
  namespace math{
    // Usually used for unit conversion/
    static const int METER_TO_MICROMETER = 1000000;
    static const int MILLI_TO_NANO = 1000000;
    static const int MICRO_TO_NANO = 1000;
    static const long int DAYS_TO_SECONDS = 86400;
    static const double SECONDS_TO_DAYS = 0.0000115741;
    static const double SECONDS_TO_MINUTES = 0.01666666667;
    static const double MILLISECONDS_TO_SECONDS = 0.001;
  }
  
  namespace commons{
    // the default constants of result folder
    static const char *RESULT_FOLDER = "./results/";
    // master node that usually used in the MPI program
    static const int MASTER_NODE = 0;
    static const std::unordered_map<std::string, std::string> MAP_CELL_NAME = {
        {"ORdstatic-Dutta_endo", "O'Hara-Rudy with Dutta Modification (2011) endocardium"},
        {"ORdstatic-Dutta_epi", "O'Hara-Rudy with Dutta Modification (2011) epicardium"},
        {"ORdstatic-Dutta_myo", "O'Hara-Rudy with Dutta Modification (2011) mid-myocardium"},
        {"CiPAORdv1.0_endo", "O'Hara-Rudy IKr-dynamic (2017) endocardium"},
        {"CiPAORdv1.0_epi", "O'Hara-Rudy IKr-dynamic (2017) epicardium"},
        {"CiPAORdv1.0_myo", "O'Hara-Rudy IKr-dynamic (2017) mid-myocardium"},
        {"ToR-ORd_endo", "Tomek et al. (2019) endocardium"},
        {"ToR-ORd_epi", "Tomek et al. (2019) epicardium"},
        {"ToR-ORd_myo", "Tomek et al. (2019) mid-myocardium"},
        {"ToR-ORd-dynCl_endo","Tomek model with dynamic chloride (2020) endocardium"},
        {"ToR-ORd-dynCl_epi","Tomek model with dynamic chloride (2020) epicardium"},
        {"ToR-ORd-dynCl_myo","Tomek model with dynamic chloride (2020) mid-myocardium"}
    };
  }

  namespace network{
    static const char *TIME_API_URL = "https://timeapi.io/api/Time/current/zone?timeZone=Asia/Seoul";
  }

  namespace security{
    static const char *MACHINE_UUID_FILE = "/etc/machine-id";
    static const char *MACHINE_UUID_BACKUP_FILE = "/var/lib/dbus/machine-id";
    static const char *SYSTEM_UUID_FILE = "/sys/class/dmi/id/product_uuid";
    static const long int TRIAL_PERIOD_DAYS = 30;
  }

  namespace tissue{
    static const int VTK_SCALAR_OUTPUT_SIZE = 4;
    static const char* VTK_SCALAR_OUTPUT_LABEL[4] = {"V","cai","qnet","qnet_apd"};
  }

}


#endif
