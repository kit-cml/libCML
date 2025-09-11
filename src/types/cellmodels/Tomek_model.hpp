#ifndef TOMEK_MODEL_ENDO_HPP
#define TOMEK_MODEL_ENDO_HPP

#include "cellmodel.hpp"
#include "enums/enum_Tomek_model.hpp"

class Tomek_model : public Cellmodel
{
public:
  Tomek_model();
  ~Tomek_model();
  void initConsts ();
  void initConsts (double ctype);
  void initConsts (double ctype, double conc, const double *hill);
  void initConsts (double ctype, double conc, const double *hill, const double *cvar);
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC );
  void solveAnalytical( double dt );
private:
  void ___applyDrugEffect(double conc, const double *hill);
  void ___initConsts(double ctype);
  void ___applyCVar(const double *cvar);
};



#endif

