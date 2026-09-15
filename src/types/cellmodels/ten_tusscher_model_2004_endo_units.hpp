#ifndef TEN_TUSSCHER_MODEL_2004_ENDO_UNITS_HPP
#define TEN_TUSSCHER_MODEL_2004_ENDO_UNITS_HPP

#include "cellmodel.hpp"
#include "enums/enum_ten_tusscher_model_2004.hpp"

class ten_tusscher_model_2004_endo_units : public Cellmodel
{
public:
  ten_tusscher_model_2004_endo_units();
  ~ten_tusscher_model_2004_endo_units();
  void initConsts ();
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveAnalytical( double dt );
};


#endif
