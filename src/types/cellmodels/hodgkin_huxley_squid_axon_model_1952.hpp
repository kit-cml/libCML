#ifndef HODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_HPP
#define HODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_HPP

#include "cellmodel.hpp"
#include "enums/enum_hodgkin_huxley_squid_axon_model_1952.hpp"

class hodgkin_huxley_squid_axon_model_1952 : public Cellmodel
{
public:
  hodgkin_huxley_squid_axon_model_1952();
  ~hodgkin_huxley_squid_axon_model_1952();
  void initConsts ();
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveAnalytical( double dt );
};


#endif

