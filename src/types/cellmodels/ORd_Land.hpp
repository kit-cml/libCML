#ifndef ORD_LAND_CUH
#define ORD_LAND_CUH

#include "cellmodel.hpp"
#include "enums/enum_ORd_Land.hpp"

class ORd_Land : public Cellmodel
{
public:
    ORd_Land();
	~ORd_Land();
	void initConsts ();
	void initConsts(double type);
	void initConsts(double type, double conc, double *hill, double *herg);
 	void initConsts(double type, double conc, double *hill, double *herg, double *cvar);
	void computeRates(double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC);

private:
    void ___applyCVar(double *cvar);
	void ___applyDrugEffect(double conc, double *ic50);
	void ___applyHERGBinding(double conc, double *herg);
	void ___initConsts(double type);
};


#endif

