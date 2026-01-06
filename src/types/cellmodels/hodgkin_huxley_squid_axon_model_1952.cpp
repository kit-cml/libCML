/*
   There are a total of 10 entries in the algebraic variable array.
   There are a total of 4 entries in each of the rate and state variable arrays.
   There are a total of 8+4 entries in the constant variable array.
 */

#include "hodgkin_huxley_squid_axon_model_1952.hpp"
#include <cmath>
#include <cstdlib>

/*
 * TIME is time in component environment (millisecond).
 * STATES[V] is V in component membrane (millivolt).
 * CONSTANTS[E_R] is E_R in component membrane (millivolt).
 * CONSTANTS[Cm] is Cm in component membrane (microF_per_cm2).
 * ALGEBRAIC[i_Na] is i_Na in component sodium_channel (microA_per_cm2).
 * ALGEBRAIC[i_K] is i_K in component potassium_channel (microA_per_cm2).
 * ALGEBRAIC[i_L] is i_L in component leakage_current (microA_per_cm2).
 * ALGEBRAIC[i_Stim] is i_Stim in component membrane (microA_per_cm2).
 * CONSTANTS[g_Na] is g_Na in component sodium_channel (milliS_per_cm2).
 * CONSTANTS[E_Na] is E_Na in component sodium_channel (millivolt).
 * STATES[m] is m in component sodium_channel_m_gate (dimensionless).
 * STATES[h] is h in component sodium_channel_h_gate (dimensionless).
 * ALGEBRAIC[alpha_m] is alpha_m in component sodium_channel_m_gate (per_millisecond).
 * ALGEBRAIC[beta_m] is beta_m in component sodium_channel_m_gate (per_millisecond).
 * ALGEBRAIC[alpha_h] is alpha_h in component sodium_channel_h_gate (per_millisecond).
 * ALGEBRAIC[beta_h] is beta_h in component sodium_channel_h_gate (per_millisecond).
 * CONSTANTS[g_K] is g_K in component potassium_channel (milliS_per_cm2).
 * CONSTANTS[E_K] is E_K in component potassium_channel (millivolt).
 * STATES[n] is n in component potassium_channel_n_gate (dimensionless).
 * ALGEBRAIC[alpha_n] is alpha_n in component potassium_channel_n_gate (per_millisecond).
 * ALGEBRAIC[beta_n] is beta_n in component potassium_channel_n_gate (per_millisecond).
 * CONSTANTS[g_L] is g_L in component leakage_current (milliS_per_cm2).
 * CONSTANTS[E_L] is E_L in component leakage_current (millivolt).
 * RATES[V] is d/dt V in component membrane (millivolt).
 * RATES[m] is d/dt m in component sodium_channel_m_gate (dimensionless).
 * RATES[h] is d/dt h in component sodium_channel_h_gate (dimensionless).
 * RATES[n] is d/dt n in component potassium_channel_n_gate (dimensionless).
 */


hodgkin_huxley_squid_axon_model_1952::hodgkin_huxley_squid_axon_model_1952()
{
algebraic_size = 10;
constants_size = 8+4;
states_size = 4;
ALGEBRAIC = new double[algebraic_size];
CONSTANTS = new double[constants_size];
RATES = new double[states_size];
STATES = new double[states_size];
}

hodgkin_huxley_squid_axon_model_1952::~hodgkin_huxley_squid_axon_model_1952()
{
delete []ALGEBRAIC;
delete []CONSTANTS;
delete []RATES;
delete []STATES;
}

void hodgkin_huxley_squid_axon_model_1952::initConsts()
{
STATES[V] = -75;
CONSTANTS[E_R] = -75;
CONSTANTS[Cm] = 1;
CONSTANTS[g_Na] = 120;
STATES[m] = 0.05;
STATES[h] = 0.6;
CONSTANTS[g_K] = 36;
STATES[n] = 0.325;
CONSTANTS[g_L] = 0.3;
CONSTANTS[E_Na] = CONSTANTS[E_R]+115.000;
CONSTANTS[E_K] = CONSTANTS[E_R] - 12.0000;
CONSTANTS[E_L] = CONSTANTS[E_R]+10.6130;
CONSTANTS[stim_start] = 10.00;
CONSTANTS[BCL] = 5.0;
CONSTANTS[duration] = 2.0;
CONSTANTS[amp] = 20.000;
}


void hodgkin_huxley_squid_axon_model_1952::computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC )
{
ALGEBRAIC[alpha_m] = ( - 0.100000*(STATES[V]+50.0000))/(exp(- (STATES[V]+50.0000)/10.0000) - 1.00000);
ALGEBRAIC[beta_m] =  4.00000*exp(- (STATES[V]+75.0000)/18.0000);
ALGEBRAIC[alpha_h] =  0.0700000*exp(- (STATES[V]+75.0000)/20.0000);
ALGEBRAIC[beta_h] = 1.00000/(exp(- (STATES[V]+45.0000)/10.0000)+1.00000);
ALGEBRAIC[alpha_n] = ( - 0.0100000*(STATES[V]+65.0000))/(exp(- (STATES[V]+65.0000)/10.0000) - 1.00000);
ALGEBRAIC[beta_n] =  0.125000*exp((STATES[V]+75.0000)/80.0000);
ALGEBRAIC[i_Na] =  CONSTANTS[g_Na]*pow(STATES[m], 3.00000)*STATES[h]*(STATES[V] - CONSTANTS[E_Na]);
ALGEBRAIC[i_K] =  CONSTANTS[g_K]*pow(STATES[n], 4.00000)*(STATES[V] - CONSTANTS[E_K]);
ALGEBRAIC[i_L] =  CONSTANTS[g_L]*(STATES[V] - CONSTANTS[E_L]);
//ALGEBRAIC[i_Stim] = (TIME>=10.0000&&TIME<=10.5000 ? 20.0000 : 0.00000);
ALGEBRAIC[i_Stim] = (TIME>=CONSTANTS[stim_start]&&(TIME - CONSTANTS[stim_start]) -  floor((TIME - CONSTANTS[stim_start])/CONSTANTS[BCL])*CONSTANTS[BCL]<=CONSTANTS[duration] ? CONSTANTS[amp] : 0.000000);


RATES[m] =  ALGEBRAIC[alpha_m]*(1.00000 - STATES[m]) -  ALGEBRAIC[beta_m]*STATES[m];
RATES[h] =  ALGEBRAIC[alpha_h]*(1.00000 - STATES[h]) -  ALGEBRAIC[beta_h]*STATES[h];
RATES[n] =  ALGEBRAIC[alpha_n]*(1.00000 - STATES[n]) -  ALGEBRAIC[beta_n]*STATES[n];
RATES[V] = - (- ALGEBRAIC[i_Stim]+ALGEBRAIC[i_Na]+ALGEBRAIC[i_K]+ALGEBRAIC[i_L])/CONSTANTS[Cm];
}

void hodgkin_huxley_squid_axon_model_1952::solveAnalytical(double dt)
{
}
