#ifndef ORDSTATIC_LAND_HPP
#define ORDSTATIC_LAND_HPP

#include "cellmodel.hpp"
#include "enums/enum_ORdstatic_Land.hpp"

class ORdstatic_Land : public Cellmodel
{
public:
  ORdstatic_Land();
  ~ORdstatic_Land();
  void initConsts();
  void initConsts(double ctype);
  void initConsts(double ctype, bool is_dutta);
  void initConsts(double ctype, double conc, double *hill, bool is_dutta);
  void initConsts(double ctype, double conc, double *hill, bool is_dutta, double *cvar);
  void computeRates(double TIME, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC);

private:
  void ___applyCVar(double *cvar);
  void ___applyDrugEffect(double conc, double *hill);
  void ___applyDutta();
  void ___initConsts(double ctype);
};

#endif

