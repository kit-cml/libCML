#ifndef CVAR_INPUT_HPP
#define CVAR_INPUT_HPP

#include <vector>

// data structure for IC50-Hill pairs
// and also hERG parameters.
typedef struct row_data2 { double data[18]; } Cvar_Row;
typedef std::vector< Cvar_Row > Cvar_Input;

#endif
