#ifndef INDIVIDUAL_DRUG_INPUT_HPP
#define INDIVIDUAL_DRUG_INPUT_HPP

#include "cvar_input.hpp"
#include "drug_block_input.hpp"

#include <tuple>
#include <vector>

typedef std::tuple<Cvar_Row, Drug_Row> Cvar_Drug_Tuple_Row;
typedef std::vector<Cvar_Drug_Tuple_Row> Individual_Drug_Input;

#endif
