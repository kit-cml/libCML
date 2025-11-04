#ifndef SHORTEN_OCALLAGHAN_DAVIDSON_SOBOLEVA_2007_HPP
#define SHORTEN_OCALLAGHAN_DAVIDSON_SOBOLEVA_2007_HPP

#include "cellmodel.hpp"
#include "enums/enum_shorten_ocallaghan_davidson_soboleva_2007.hpp"

class shorten_ocallaghan_davidson_soboleva_2007 : public Cellmodel
{
public:
  shorten_ocallaghan_davidson_soboleva_2007();
  ~shorten_ocallaghan_davidson_soboleva_2007();
  void initConsts ();
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveAnalytical( double dt );
};


#endif

