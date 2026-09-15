#ifndef TEN_TUSSCHER_MODEL_2004_EPI_UNITS_HPP
#define TEN_TUSSCHER_MODEL_2004_EPI_UNITS_HPP

#include "cellmodel.hpp"
#include "enums/enum_ten_tusscher_model_2004.hpp"

class ten_tusscher_model_2004_epi_units : public Cellmodel
{
public:
  ten_tusscher_model_2004_epi_units();
  ~ten_tusscher_model_2004_epi_units();
  void initConsts ();
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveAnalytical( double dt );
};


#endif
