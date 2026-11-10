#ifndef TENTUSSCHER_NOBLE_NOBLE_PANFILOV_2004_ENDO_HPP
#define TENTUSSCHER_NOBLE_NOBLE_PANFILOV_2004_ENDO_HPP

#include "cellmodel.hpp"
#include "enums/enum_tentusscher_noble_noble_panfilov_2004.hpp"

class tentusscher_noble_noble_panfilov_2004_endo : public Cellmodel
{
public:
  tentusscher_noble_noble_panfilov_2004_endo();
  ~tentusscher_noble_noble_panfilov_2004_endo();
  void initConsts ();
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveAnalytical( double dt );
};


#endif

