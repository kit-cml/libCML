#ifndef ORD2017_ALI_HPP
#define ORD2017_ALI_HPP

#include "cellmodel.hpp"
#include "enums/enum_ord_ali.hpp"

#define EULER

class ord2017_ali : public Cellmodel
{
public:
  ord2017_ali();
  ~ord2017_ali();
  void initConsts ();
  void initConsts(double type);
  // void initConsts(double type, double conc, const double *hill, const double *herg );
  // void initConsts(double type, double bcl, double conc, double *ic50, bool is_dutta );
  void initConsts (double type, double bcl, double conc, double *hill, double *herg);
  void computeRates();
  void computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC, double land_trpn );
  void solveAnalytical( int forward_euler_only, double dt, double *CONSTANTS, double *RATES, double* STATES, double* ALGEBRAIC );
  double tryDt( double dt,
               double TIME,
               double *CONSTANTS,
               double *RATES,
               double* STATES,
               double* ALGEBRAIC );
  void gaussElimination(double *A, double *b, double *x, int N);
//  void gaussSeidel(double **a, double *b, double *x, int n, int maxIterations, double tolerance);
  // void solveRK4(double TIME,double dt);
  double set_time_step(double TIME,
                       double time_point,
                       double min_time_step,
                       double max_time_step,
                       double min_dV,
                       double max_dV,
                       double* CONSTANTS,
                       double* RATES,
                       double* STATES,
                       double* ALGEBRAIC);
private:
  void ___applyDrugEffect(double conc, const double *hill);
  void ___applyHERGBinding(double conc, const double *herg);
  void ___initConsts(double type, double bcl);
};


#endif

