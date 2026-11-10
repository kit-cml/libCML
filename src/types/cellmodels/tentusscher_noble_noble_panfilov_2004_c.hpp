#ifndef TENTUSSCHER_NOBLE_NOBLE_PANFILOV_2004_C_HPP
#define TENTUSSCHER_NOBLE_NOBLE_PANFILOV_2004_C_HPP

#include "cellmodel.hpp"
#include "enums/enum_tentusscher_noble_noble_panfilov_2004.hpp"

class tentusscher_noble_noble_panfilov_2004_c : public Cellmodel
{
public:
  tentusscher_noble_noble_panfilov_2004_c();
  ~tentusscher_noble_noble_panfilov_2004_c();
  void initConsts ();
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveAnalytical( double dt );
};


#endif

