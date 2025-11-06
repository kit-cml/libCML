#ifndef GRANDI_2011_ATRIAL_WITH_META_HPP
#define GRANDI_2011_ATRIAL_WITH_META_HPP

#include "cellmodel.hpp"
#include "enums/enum_grandi_2011.hpp"

class grandi_2011_atrial_with_meta : public Cellmodel
{
public:
  grandi_2011_atrial_with_meta();
  ~grandi_2011_atrial_with_meta();
  void initConsts ();
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveAnalytical( double dt );
};


#endif

