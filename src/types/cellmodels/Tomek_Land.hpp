#ifndef TOMEK_LAND_HPP
#define TOMEK_LAND_HPP

#include "cellmodel.hpp"
#include "enums/enum_Tomek_Land.hpp"

class Tomek_Land : public Cellmodel
{
public:
  Tomek_Land();
  ~Tomek_Land();
  void initConsts ();
  void initConsts (double ctype);
  void initConsts (double ctype, double conc, double *hill);
  void initConsts (double ctype, double conc, double *hill, double *cvar);
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );

private:
  void ___applyDrugEffect(double conc, double *hill);
  void ___initConsts(double ctype);
  void ___applyCVar(double *cvar);
};



#endif