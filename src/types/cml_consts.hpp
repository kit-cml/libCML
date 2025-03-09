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
    // to normalize the small values
    // so it can compressed the file size.
    // Information of the scaling should be
    // described in the header result.
    static const int METER_TO_MICROMETER = 1000000;
    static const int MILLI_TO_NANO = 1000000;
    static const int MICRO_TO_NANO = 1000;
    static const double SECOND_TO_MINUTE = 0.01666666667;
    static const double MILLISECOND_TO_SECOND = 0.001;
  }
  
  namespace commons{
    // the default constants of result folder
    static const char *RESULT_FOLDER = "./result/";
    // master node that usually used in the MPI program
    static const int MASTER_NODE = 0;
    static const std::unordered_map<std::string, std::string> MAP_CELL_NAME = {
        {"ordstatic", "O'Hara-Rudy (ORd) (2011)"},
        {"ord", "O'Hara-Rudy IKr-dynamic (2017)"},
        {"tomek", "Tomek et al. (ToR-ORd) (2019)"},
        {"tomekdyncl","Tomek Cl-dynamic  (ToR-ORd-dynCl) (2020) "}
    };
    static const std::vector<std::string> VECTOR_CELL_TYPE = {"endocardium", "epicardium", "mid-myocardium"};
  }

  namespace tissue{
    static const int VTK_SCALAR_OUTPUT_SIZE = 4;
    static const char* VTK_SCALAR_OUTPUT_LABEL[4] = {"V","cai","qnet","qnet_apd"};
  }

}


#endif
