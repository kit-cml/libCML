#ifndef TONG_CHOI_KHARCHE_HOLDEN_ZHANG_TAGGART_2011_HPP
#define TONG_CHOI_KHARCHE_HOLDEN_ZHANG_TAGGART_2011_HPP

#include "cellmodel.hpp"
#include "enums/enum_Tong_Choi_Kharche_Holden_Zhang_Taggart_2011.hpp"

class Tong_Choi_Kharche_Holden_Zhang_Taggart_2011 : public Cellmodel
{
public:
  Tong_Choi_Kharche_Holden_Zhang_Taggart_2011();
  ~Tong_Choi_Kharche_Holden_Zhang_Taggart_2011();
  void initConsts ();
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveAnalytical( double dt );
};


#endif

