/*
   There are a total of 82 entries in the algebraic variable array.
   There are a total of 22 entries in each of the rate and state variable arrays.
   There are a total of 83 entries in the constant variable array.
 */

#include "Tong_Choi_Kharche_Holden_Zhang_Taggart_2011.hpp"
#include <cmath>
#include <cstdlib>

/*
 * CONSTANTS[I_hold] is I_hold in component interface (pA_per_pF).
 * CONSTANTS[I_test] is I_test in component interface (pA_per_pF).
 * CONSTANTS[test_start] is test_start in component interface (msec).
 * CONSTANTS[test_end] is test_end in component interface (msec).
 * ALGEBRAIC[Ist] is Ist in component interface (pA_per_pF).
 * TIME is time in component environment (msec).
 * ALGEBRAIC[I_tot] is I_tot in component membrane_potential (pA_per_pF).
 * ALGEBRAIC[I_Ca_tot] is I_Ca_tot in component membrane_potential (pA_per_pF).
 * STATES[v] is v in component membrane_potential (mV).
 * CONSTANTS[Cm] is Cm in component parameters (uF_per_cm2).
 * ALGEBRAIC[ina] is ina in component I_Na (pA_per_pF).
 * ALGEBRAIC[ical] is ical in component I_CaL (pA_per_pF).
 * ALGEBRAIC[icat] is icat in component I_CaT (pA_per_pF).
 * ALGEBRAIC[ib] is ib in component I_b (pA_per_pF).
 * ALGEBRAIC[ik1] is ik1 in component I_K1 (pA_per_pF).
 * ALGEBRAIC[ik2] is ik2 in component I_K2 (pA_per_pF).
 * ALGEBRAIC[ika] is ika in component I_Ka (pA_per_pF).
 * ALGEBRAIC[iBKa] is iBKa in component I_BKa (pA_per_pF).
 * ALGEBRAIC[iBKab] is iBKab in component I_BKab (pA_per_pF).
 * ALGEBRAIC[ih] is ih in component I_h (pA_per_pF).
 * ALGEBRAIC[icl] is icl in component I_Cl (pA_per_pF).
 * ALGEBRAIC[insna] is insna in component I_ns (pA_per_pF).
 * ALGEBRAIC[insca] is insca in component I_ns (pA_per_pF).
 * ALGEBRAIC[insk] is insk in component I_ns (pA_per_pF).
 * ALGEBRAIC[inak] is inak in component I_NaK (pA_per_pF).
 * ALGEBRAIC[inaca] is inaca in component I_NaCa (pA_per_pF).
 * ALGEBRAIC[J_tot] is J_tot in component Ca_Concentrations (mM_per_msec).
 * ALGEBRAIC[J_Ca_mem] is J_Ca_mem in component Ca_Concentrations (mM_per_msec).
 * STATES[cai] is cai in component Ca_Concentrations (mM).
 * ALGEBRAIC[jnaca] is jnaca in component J_NaCa (mM_per_msec).
 * ALGEBRAIC[jpmca] is jpmca in component J_PMCA (mM_per_msec).
 * CONSTANTS[buff] is buff in component parameters (dimensionless).
 * CONSTANTS[AV] is AV in component parameters (cm2_per_uL).
 * CONSTANTS[zca] is zca in component parameters (dimensionless).
 * CONSTANTS[frdy] is frdy in component parameters (coulomb_per_mole).
 * ALGEBRAIC[jcamem_plot] is jcamem_plot in component Ca_Concentrations (M_per_msec).
 * ALGEBRAIC[jpmca_plot] is jpmca_plot in component Ca_Concentrations (M_per_msec).
 * ALGEBRAIC[jnaca_plot] is jnaca_plot in component Ca_Concentrations (M_per_msec).
 * CONSTANTS[conversion_Ca_Concentrations] is conversion_Ca_Concentrations in component Ca_Concentrations (mM_to_M).
 * CONSTANTS[ki] is ki in component parameters (mM).
 * CONSTANTS[nai] is nai in component parameters (mM).
 * CONSTANTS[cli] is cli in component parameters (mM).
 * CONSTANTS[ko] is ko in component parameters (mM).
 * CONSTANTS[cao] is cao in component parameters (mM).
 * CONSTANTS[nao] is nao in component parameters (mM).
 * CONSTANTS[clo] is clo in component parameters (mM).
 * CONSTANTS[mgo] is mgo in component parameters (mM).
 * CONSTANTS[zna] is zna in component parameters (dimensionless).
 * CONSTANTS[zk] is zk in component parameters (dimensionless).
 * CONSTANTS[R] is R in component parameters (joule_per_kelvin_per_kilomole).
 * CONSTANTS[temp] is temp in component parameters (kelvin).
 * CONSTANTS[gna] is gna in component parameters (nS_per_pF).
 * CONSTANTS[gcal] is gcal in component parameters (nS_per_pF).
 * CONSTANTS[ecal] is ecal in component parameters (mV).
 * CONSTANTS[kmca] is kmca in component parameters (mM).
 * CONSTANTS[gcat] is gcat in component parameters (nS_per_pF).
 * CONSTANTS[ecat] is ecat in component parameters (mV).
 * CONSTANTS[gkca] is gkca in component parameters (nS_per_pF).
 * CONSTANTS[gb] is gb in component parameters (nS_per_pF).
 * CONSTANTS[gk1] is gk1 in component parameters (nS_per_pF).
 * CONSTANTS[gk2] is gk2 in component parameters (nS_per_pF).
 * CONSTANTS[gbka] is gbka in component parameters (dimensionless).
 * CONSTANTS[gbkab] is gbkab in component parameters (dimensionless).
 * CONSTANTS[gka] is gka in component parameters (nS_per_pF).
 * CONSTANTS[gcl] is gcl in component parameters (nS_per_pF).
 * CONSTANTS[gh] is gh in component parameters (nS_per_pF).
 * CONSTANTS[gns] is gns in component parameters (nS_per_pF).
 * CONSTANTS[PnsK] is PnsK in component parameters (dimensionless).
 * CONSTANTS[PnsNa] is PnsNa in component parameters (dimensionless).
 * CONSTANTS[PnsCa] is PnsCa in component parameters (dimensionless).
 * CONSTANTS[PnsCs] is PnsCs in component parameters (dimensionless).
 * CONSTANTS[gnsCa] is gnsCa in component parameters (dimensionless).
 * CONSTANTS[gnsNa] is gnsNa in component parameters (dimensionless).
 * CONSTANTS[gnsK] is gnsK in component parameters (dimensionless).
 * CONSTANTS[gnsCs] is gnsCs in component parameters (dimensionless).
 * CONSTANTS[ginak] is ginak in component parameters (pA_per_pF).
 * CONSTANTS[nakKmko] is nakKmko in component parameters (mM).
 * CONSTANTS[nakKmnai] is nakKmnai in component parameters (mM).
 * CONSTANTS[PK] is PK in component parameters (dimensionless).
 * CONSTANTS[PNa] is PNa in component parameters (dimensionless).
 * CONSTANTS[Jpmca] is Jpmca in component parameters (mM_per_msec).
 * CONSTANTS[Kmpmca] is Kmpmca in component parameters (mM).
 * CONSTANTS[npmca] is npmca in component parameters (dimensionless).
 * CONSTANTS[Jnaca] is Jnaca in component parameters (mM_per_msec).
 * CONSTANTS[Kmallo] is Kmallo in component parameters (mM).
 * CONSTANTS[nallo] is nallo in component parameters (dimensionless).
 * CONSTANTS[ksat] is ksat in component parameters (dimensionless).
 * CONSTANTS[xgamma] is xgamma in component parameters (dimensionless).
 * CONSTANTS[Kmnai] is Kmnai in component parameters (mM).
 * CONSTANTS[Kmcai] is Kmcai in component parameters (mM).
 * CONSTANTS[Kmnao] is Kmnao in component parameters (mM).
 * CONSTANTS[Kmcao] is Kmcao in component parameters (mM).
 * CONSTANTS[Fmax] is Fmax in component parameters (uN).
 * CONSTANTS[FKm] is FKm in component parameters (nM).
 * CONSTANTS[Fn] is Fn in component parameters (dimensionless).
 * ALGEBRAIC[vFRT] is vFRT in component parameters (dimensionless).
 * CONSTANTS[ena] is ena in component parameters (mV).
 * CONSTANTS[ek] is ek in component parameters (mV).
 * CONSTANTS[eh] is eh in component parameters (mV).
 * CONSTANTS[ecl] is ecl in component parameters (mV).
 * ALGEBRAIC[enscc] is enscc in component parameters (mV).
 * ALGEBRAIC[wss] is wss in component Ca_dependent_Force (dimensionless).
 * ALGEBRAIC[wtc] is wtc in component Ca_dependent_Force (msec).
 * CONSTANTS[conversion_Ca_dependent_Force] is conversion_Ca_dependent_Force in component Ca_dependent_Force (nM_to_mM).
 * ALGEBRAIC[Force] is Force in component Ca_dependent_Force (uN).
 * STATES[w] is w in component Ca_dependent_Force (dimensionless).
 * ALGEBRAIC[mss] is mss in component I_Na (dimensionless).
 * ALGEBRAIC[hss] is hss in component I_Na (dimensionless).
 * ALGEBRAIC[mtc] is mtc in component I_Na (msec).
 * ALGEBRAIC[htc] is htc in component I_Na (msec).
 * STATES[m] is m in component I_Na (dimensionless).
 * STATES[h] is h in component I_Na (dimensionless).
 * ALGEBRAIC[dss] is dss in component I_CaL (dimensionless).
 * ALGEBRAIC[fss] is fss in component I_CaL (dimensionless).
 * ALGEBRAIC[fca] is fca in component I_CaL (dimensionless).
 * ALGEBRAIC[dtc] is dtc in component I_CaL (msec).
 * CONSTANTS[f1tc] is f1tc in component I_CaL (msec).
 * ALGEBRAIC[f2tc] is f2tc in component I_CaL (msec).
 * STATES[d] is d in component I_CaL (dimensionless).
 * STATES[f1] is f1 in component I_CaL (dimensionless).
 * STATES[f2] is f2 in component I_CaL (dimensionless).
 * ALGEBRAIC[bss] is bss in component I_CaT (dimensionless).
 * ALGEBRAIC[gss] is gss in component I_CaT (dimensionless).
 * ALGEBRAIC[btc] is btc in component I_CaT (msec).
 * ALGEBRAIC[gtc] is gtc in component I_CaT (msec).
 * STATES[b] is b in component I_CaT (dimensionless).
 * STATES[g] is g in component I_CaT (dimensionless).
 * ALGEBRAIC[qss] is qss in component I_K1 (dimensionless).
 * ALGEBRAIC[rss] is rss in component I_K1 (dimensionless).
 * ALGEBRAIC[qtc] is qtc in component I_K1 (msec).
 * ALGEBRAIC[r1tc] is r1tc in component I_K1 (msec).
 * ALGEBRAIC[r2tc] is r2tc in component I_K1 (msec).
 * STATES[q] is q in component I_K1 (dimensionless).
 * STATES[r1] is r1 in component I_K1 (dimensionless).
 * STATES[r2] is r2 in component I_K1 (dimensionless).
 * ALGEBRAIC[pss] is pss in component I_K2 (dimensionless).
 * ALGEBRAIC[kss] is kss in component I_K2 (dimensionless).
 * ALGEBRAIC[ptc] is ptc in component I_K2 (msec).
 * ALGEBRAIC[k1tc] is k1tc in component I_K2 (msec).
 * ALGEBRAIC[k2tc] is k2tc in component I_K2 (msec).
 * STATES[p] is p in component I_K2 (dimensionless).
 * STATES[k1] is k1 in component I_K2 (dimensionless).
 * STATES[k2] is k2 in component I_K2 (dimensionless).
 * ALGEBRAIC[sss] is sss in component I_Ka (dimensionless).
 * ALGEBRAIC[xss] is xss in component I_Ka (dimensionless).
 * ALGEBRAIC[stc] is stc in component I_Ka (msec).
 * ALGEBRAIC[xtc] is xtc in component I_Ka (msec).
 * STATES[s] is s in component I_Ka (dimensionless).
 * STATES[x] is x in component I_Ka (dimensionless).
 * ALGEBRAIC[xass_z] is xass_z in component I_BKa (dimensionless).
 * ALGEBRAIC[xass_vh] is xass_vh in component I_BKa (mV).
 * CONSTANTS[conversion_I_BKa] is conversion_I_BKa in component I_BKa (mM_to_M).
 * ALGEBRAIC[xass] is xass in component I_BKa (dimensionless).
 * ALGEBRAIC[xatc] is xatc in component I_BKa (msec).
 * STATES[xa] is xa in component I_BKa (dimensionless).
 * ALGEBRAIC[xabss_z] is xabss_z in component I_BKab (dimensionless).
 * ALGEBRAIC[xabss_vh] is xabss_vh in component I_BKab (mV).
 * CONSTANTS[conversion_I_BKab] is conversion_I_BKab in component I_BKab (mM_to_M).
 * ALGEBRAIC[xabss] is xabss in component I_BKab (dimensionless).
 * ALGEBRAIC[xabtc] is xabtc in component I_BKab (msec).
 * STATES[xab] is xab in component I_BKab (dimensionless).
 * ALGEBRAIC[yss] is yss in component I_h (dimensionless).
 * ALGEBRAIC[ytc] is ytc in component I_h (msec).
 * ALGEBRAIC[ya] is ya in component I_h (per_msec).
 * ALGEBRAIC[yb] is yb in component I_h (per_msec).
 * STATES[y] is y in component I_h (dimensionless).
 * ALGEBRAIC[css] is css in component I_Cl (dimensionless).
 * ALGEBRAIC[ctc] is ctc in component I_Cl (msec).
 * ALGEBRAIC[K1cl] is K1cl in component I_Cl (mM).
 * ALGEBRAIC[K2cl] is K2cl in component I_Cl (dimensionless).
 * STATES[c] is c in component I_Cl (dimensionless).
 * CONSTANTS[fmg] is fmg in component I_ns (dimensionless).
 * CONSTANTS[gs_nao] is gs_nao in component I_ns (dimensionless).
 * CONSTANTS[gs_cao] is gs_cao in component I_ns (dimensionless).
 * CONSTANTS[gs_ko] is gs_ko in component I_ns (dimensionless).
 * CONSTANTS[tinyamount] is tinyamount in component I_ns (mM).
 * ALGEBRAIC[fnak] is fnak in component I_NaK (dimensionless).
 * CONSTANTS[knak] is knak in component I_NaK (dimensionless).
 * CONSTANTS[nnak] is nnak in component I_NaK (dimensionless).
 * CONSTANTS[inaca_sign] is inaca_sign in component I_NaCa (dimensionless).
 * ALGEBRAIC[f1naca] is f1naca in component J_NaCa (dimensionless).
 * ALGEBRAIC[f2naca] is f2naca in component J_NaCa (dimensionless).
 * ALGEBRAIC[fallo] is fallo in component J_NaCa (dimensionless).
 * ALGEBRAIC[naca_Eup] is naca_Eup in component J_NaCa (mM4).
 * ALGEBRAIC[naca_Ed1] is naca_Ed1 in component J_NaCa (dimensionless).
 * ALGEBRAIC[naca_Ed2] is naca_Ed2 in component J_NaCa (mM4).
 * ALGEBRAIC[naca_Ed3] is naca_Ed3 in component J_NaCa (mM4).
 * CONSTANTS[jnaca_sign] is jnaca_sign in component J_NaCa (dimensionless).
 * RATES[v] is d/dt v in component membrane_potential (mV).
 * RATES[cai] is d/dt cai in component Ca_Concentrations (mM).
 * RATES[w] is d/dt w in component Ca_dependent_Force (dimensionless).
 * RATES[m] is d/dt m in component I_Na (dimensionless).
 * RATES[h] is d/dt h in component I_Na (dimensionless).
 * RATES[d] is d/dt d in component I_CaL (dimensionless).
 * RATES[f1] is d/dt f1 in component I_CaL (dimensionless).
 * RATES[f2] is d/dt f2 in component I_CaL (dimensionless).
 * RATES[b] is d/dt b in component I_CaT (dimensionless).
 * RATES[g] is d/dt g in component I_CaT (dimensionless).
 * RATES[q] is d/dt q in component I_K1 (dimensionless).
 * RATES[r1] is d/dt r1 in component I_K1 (dimensionless).
 * RATES[r2] is d/dt r2 in component I_K1 (dimensionless).
 * RATES[p] is d/dt p in component I_K2 (dimensionless).
 * RATES[k1] is d/dt k1 in component I_K2 (dimensionless).
 * RATES[k2] is d/dt k2 in component I_K2 (dimensionless).
 * RATES[s] is d/dt s in component I_Ka (dimensionless).
 * RATES[x] is d/dt x in component I_Ka (dimensionless).
 * RATES[xa] is d/dt xa in component I_BKa (dimensionless).
 * RATES[xab] is d/dt xab in component I_BKab (dimensionless).
 * RATES[y] is d/dt y in component I_h (dimensionless).
 * RATES[c] is d/dt c in component I_Cl (dimensionless).
 */


Tong_Choi_Kharche_Holden_Zhang_Taggart_2011::Tong_Choi_Kharche_Holden_Zhang_Taggart_2011()
{
algebraic_size = 82;
constants_size = 83;
states_size = 22;
ALGEBRAIC = new double[algebraic_size];
CONSTANTS = new double[constants_size];
RATES = new double[states_size];
STATES = new double[states_size];
}

Tong_Choi_Kharche_Holden_Zhang_Taggart_2011::~Tong_Choi_Kharche_Holden_Zhang_Taggart_2011()
{
delete []ALGEBRAIC;
delete []CONSTANTS;
delete []RATES;
delete []STATES;
}

void Tong_Choi_Kharche_Holden_Zhang_Taggart_2011::initConsts()
{
CONSTANTS[I_hold] = 0;
CONSTANTS[I_test] = -0.5;
CONSTANTS[test_start] = 1000;
CONSTANTS[test_end] = 3000;
STATES[v] = -53.90915441282156;
STATES[cai] = 0.0001161881607214449;
CONSTANTS[conversion_Ca_Concentrations] = 1000;
CONSTANTS[conversion_Ca_dependent_Force] = 1e-6;
STATES[w] = 0.2345238135343783;
STATES[m] = 0.1253518889572223;
STATES[h] = 0.404599170710196;
STATES[d] = 0.01036961357784695;
STATES[f1] = 0.9065941499695301;
STATES[f2] = 0.9065967263076083;
STATES[b] = 0.508117603077852;
STATES[g] = 0.03582573962705717;
STATES[q] = 0.2060363247740295;
STATES[r1] = 0.1922244113609531;
STATES[r2] = 0.1932803618375963;
STATES[p] = 0.1174074734567931;
STATES[k1] = 0.9968385770271651;
STATES[k2] = 0.9968408069904307;
STATES[s] = 0.0307583106982354;
STATES[x] = 0.08785242843398365;
CONSTANTS[conversion_I_BKa] = 1000.0;
STATES[xa] = 0.0003569126518797985;
CONSTANTS[conversion_I_BKab] = 1000.0;
STATES[xab] = 0.002220456569762898;
STATES[y] = 0.002604864867063448;
STATES[c] = 0.0003764413740731269;
CONSTANTS[tinyamount] = 1e-8;
CONSTANTS[inaca_sign] = -1;
CONSTANTS[jnaca_sign] = -1;
CONSTANTS[ki] = 140.000;
CONSTANTS[cao] = 2.50000;
CONSTANTS[mgo] = 0.500000;
CONSTANTS[zna] = 1.00000;
CONSTANTS[zk] = 1.00000;
CONSTANTS[gna] = 0.00000;
CONSTANTS[gcal] = 0.600000;
CONSTANTS[ecal] = 45.0000;
CONSTANTS[kmca] = 0.00100000;
CONSTANTS[gcat] = 0.0580000;
CONSTANTS[ecat] = 42.0000;
CONSTANTS[gkca] = 0.800000;
CONSTANTS[gb] = 0.00400000;
CONSTANTS[gk1] = 0.520000;
CONSTANTS[gk2] = 0.0320000;
CONSTANTS[gbka] = 0.200000;
CONSTANTS[gbkab] = 0.100000;
CONSTANTS[gka] = 0.160000;
CONSTANTS[gcl] = 0.187500;
CONSTANTS[gh] = 0.0542000;
CONSTANTS[gns] = 0.0123000;
CONSTANTS[PnsK] = 1.30000;
CONSTANTS[PnsNa] = 0.900000;
CONSTANTS[PnsCa] = 0.890000;
CONSTANTS[PnsCs] = 1.00000;
CONSTANTS[gnsCa] = 0.500000;
CONSTANTS[gnsNa] = 1.00000;
CONSTANTS[gnsK] = 1.19000;
CONSTANTS[gnsCs] = 1.60000;
CONSTANTS[Jpmca] = 3.50000e-07;
CONSTANTS[Kmpmca] = 0.000500000;
CONSTANTS[npmca] = 2.00000;
CONSTANTS[Kmallo] = 0.000300000;
CONSTANTS[nallo] = 4.00000;
CONSTANTS[Kmnai] = 30.0000;
CONSTANTS[Kmcai] = 0.00700000;
CONSTANTS[Kmnao] = 87.5000;
CONSTANTS[Kmcao] = 1.30000;
CONSTANTS[Fmax] = 3.00000;
CONSTANTS[FKm] = 161.301;
CONSTANTS[Fn] = 3.60205;
CONSTANTS[f1tc] = 12.0000;
CONSTANTS[nai] = 4.00000;
CONSTANTS[fmg] = 0.108043+0.903902/(1.00000+pow(CONSTANTS[mgo]/0.281007, 1.29834));
CONSTANTS[gs_cao] = ( (1.00000/0.000525000)*0.0300000)/(1.00000+pow(150.000/(CONSTANTS[cao]+CONSTANTS[tinyamount]), 2.00000));
CONSTANTS[cli] = 46.0000;
CONSTANTS[ko] = 6.00000;
CONSTANTS[nao] = 130.000;
CONSTANTS[gs_ko] = ( (1.00000/0.0123000)*0.0300000)/(1.00000+pow(150.000/(CONSTANTS[ko]+CONSTANTS[tinyamount]), 2.00000));
CONSTANTS[clo] = 130.000;
CONSTANTS[gs_nao] = ( (1.00000/0.0123000)*0.0300000)/(1.00000+pow(150.000/(CONSTANTS[nao]+CONSTANTS[tinyamount]), 2.00000));
CONSTANTS[buff] = 0.0150000;
CONSTANTS[AV] = 4.00000;
CONSTANTS[zca] = 2.00000;
CONSTANTS[R] = 8314.00;
CONSTANTS[frdy] = 96485.0;
CONSTANTS[Cm] = 1.00000;
CONSTANTS[temp] = 308.000;
CONSTANTS[ginak] = 1.70000;
CONSTANTS[PK] = 1.00000;
CONSTANTS[ena] =  (( CONSTANTS[R]*CONSTANTS[temp])/CONSTANTS[frdy])*log(CONSTANTS[nao]/CONSTANTS[nai]);
CONSTANTS[ek] =  (( CONSTANTS[R]*CONSTANTS[temp])/CONSTANTS[frdy])*log(CONSTANTS[ko]/CONSTANTS[ki]);
CONSTANTS[ecl] =  (( CONSTANTS[R]*CONSTANTS[temp])/CONSTANTS[frdy])*log(CONSTANTS[cli]/CONSTANTS[clo]);
CONSTANTS[nakKmko] = 2.00000;
CONSTANTS[PNa] = 0.350000;
CONSTANTS[nakKmnai] = 22.0000;
CONSTANTS[eh] =  (( CONSTANTS[R]*CONSTANTS[temp])/CONSTANTS[frdy])*log((CONSTANTS[ko]+ (CONSTANTS[PNa]/CONSTANTS[PK])*CONSTANTS[nao])/(CONSTANTS[ki]+ (CONSTANTS[PNa]/CONSTANTS[PK])*CONSTANTS[nai]));
CONSTANTS[Jnaca] = 3.50000e-06;
CONSTANTS[ksat] = 0.270000;
CONSTANTS[xgamma] = 0.350000;
CONSTANTS[knak] = 1.00000/(1.00000+pow(CONSTANTS[nakKmko]/CONSTANTS[ko], 1.50000));
CONSTANTS[nnak] = 1.00000/(1.00000+pow(CONSTANTS[nakKmnai]/CONSTANTS[nai], 2.00000));
}


void Tong_Choi_Kharche_Holden_Zhang_Taggart_2011::computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC )
{
ALGEBRAIC[fss] = 1.00000/(1.00000+exp((STATES[v]+38.0000)/7.00000));
ALGEBRAIC[wss] = 1.00000/(1.00000+pow(( CONSTANTS[FKm]*CONSTANTS[conversion_Ca_dependent_Force])/STATES[cai], CONSTANTS[Fn]));
ALGEBRAIC[wtc] =  4000.00*(0.234845+(1.00000 - 0.234845)/(1.00000+pow(STATES[cai]/( CONSTANTS[FKm]*CONSTANTS[conversion_Ca_dependent_Force]), CONSTANTS[Fn])));
ALGEBRAIC[mss] = 1.00000/(1.00000+exp(- (STATES[v]+35.9584)/9.24013));
ALGEBRAIC[mtc] = 0.250000+7.00000/(1.00000+exp((STATES[v]+38.0000)/10.0000));
ALGEBRAIC[hss] = 1.00000/(1.00000+exp((STATES[v]+57.0000)/8.00000));
ALGEBRAIC[htc] = 0.900000+1002.85/(1.00000+pow((STATES[v]+47.5000)/1.50000, 2.00000));
ALGEBRAIC[dss] = 1.00000/(1.00000+exp(- (STATES[v]+22.0000)/7.00000));
ALGEBRAIC[dtc] = 2.29000+5.70000/(1.00000+pow((STATES[v]+29.9700)/9.00000, 2.00000));
ALGEBRAIC[f2tc] =  90.9699*(1.00000 - 1.00000/( (1.00000+exp((STATES[v]+13.9629)/45.3782))*(1.00000+exp(- (STATES[v]+9.49866)/3.39450))));
ALGEBRAIC[bss] = 1.00000/(1.00000+exp(- (STATES[v]+54.2300)/9.88000));
ALGEBRAIC[btc] = 0.450000+3.90000/(1.00000+pow((STATES[v]+66.0000)/26.0000, 2.00000));
ALGEBRAIC[gss] = 0.0200000+0.980000/(1.00000+exp((STATES[v]+72.9780)/4.64000));
ALGEBRAIC[gtc] =  150.000*(1.00000 - 1.00000/( (1.00000+exp((STATES[v] - 417.430)/203.180))*(1.00000+exp(- (STATES[v]+61.1100)/8.07000))));
ALGEBRAIC[qss] = 0.978613/(1.00000+exp(- (STATES[v]+18.6736)/26.6606));
ALGEBRAIC[qtc] = 500.000/(1.00000+pow((STATES[v]+60.7100)/15.7900, 2.00000));
ALGEBRAIC[rss] = 1.00000/(1.00000+exp((STATES[v]+63.0000)/6.30000));
ALGEBRAIC[r1tc] = 5000.00/(1.00000+pow((STATES[v]+62.7133)/35.8611, 2.00000));
ALGEBRAIC[r2tc] = 30000.0+220000./(1.00000+exp((STATES[v]+22.0000)/4.00000));
ALGEBRAIC[pss] = 0.948000/(1.00000+exp(- (STATES[v]+17.9100)/18.4000));
ALGEBRAIC[ptc] = 100.000/(1.00000+pow((STATES[v]+64.1000)/28.6700, 2.00000));
ALGEBRAIC[kss] = 1.00000/(1.00000+exp((STATES[v]+21.2000)/5.70000));
ALGEBRAIC[k1tc] =  1.00000e+06*(1.00000 - 1.00000/( (1.00000+exp((STATES[v] - 315.000)/50.0000))*(1.00000+exp(- (STATES[v]+74.9000)/8.00000))));
ALGEBRAIC[k2tc] =  2.50000e+06*(1.00000 - 1.00000/( (1.00000+exp((STATES[v] - 132.868)/25.3992))*(1.00000+exp(- (STATES[v]+24.9203)/2.67915))));
ALGEBRAIC[sss] = 1.00000/(1.00000+exp(- (STATES[v]+27.7900)/7.57000));
ALGEBRAIC[stc] = 17.0000/(1.00000+pow((STATES[v]+20.5232)/35.0000, 2.00000));
ALGEBRAIC[xss] = 0.0200000+0.980000/(1.00000+exp((STATES[v]+69.5000)/6.00000));
ALGEBRAIC[xtc] = 7.50000+10.0000/(1.00000+pow((STATES[v]+34.1765)/120.000, 2.00000));
ALGEBRAIC[xass_z] = - 0.749234/(1.00000+pow(( STATES[cai]*CONSTANTS[conversion_I_BKa] - 0.0630535)/0.161942, 2.00000))+8.38384/(1.00000+pow(( STATES[cai]*CONSTANTS[conversion_I_BKa]+1538.29)/739.057, 2.00000));
ALGEBRAIC[xass_vh] = 5011.47/(1.00000+pow(( STATES[cai]*CONSTANTS[conversion_I_BKa]+0.237503)/0.000239278, 0.422910)) - 37.5137;
ALGEBRAIC[xass] = 1.00000/(1.00000+exp(( - ALGEBRAIC[xass_z]*CONSTANTS[frdy]*(STATES[v] - ALGEBRAIC[xass_vh]))/( CONSTANTS[R]*CONSTANTS[temp])));
ALGEBRAIC[xatc] = 2.40914/(1.00000+pow((STATES[v] - 158.779)/- 52.1497, 2.00000));
ALGEBRAIC[xabss_z] = - 0.681249/(1.00000+pow(( STATES[cai]*CONSTANTS[conversion_I_BKab] - 0.218988)/0.428335, 2.00000))+1.40001/(1.00000+pow(( STATES[cai]*CONSTANTS[conversion_I_BKab]+228.710)/684.946, 2.00000));
ALGEBRAIC[xabss_vh] = 8540.23/(1.00000+pow(( STATES[cai]*CONSTANTS[conversion_I_BKab]+0.401189)/0.00399115, 0.668054)) - 109.275;
ALGEBRAIC[xabss] = 1.00000/(1.00000+exp(( - ALGEBRAIC[xabss_z]*CONSTANTS[frdy]*(STATES[v] - ALGEBRAIC[xabss_vh]))/( CONSTANTS[R]*CONSTANTS[temp])));
ALGEBRAIC[xabtc] = 13.8049/(1.00000+pow((STATES[v] - 153.019)/66.4952, 2.00000));
ALGEBRAIC[yss] = 1.00000/(1.00000+exp((STATES[v]+105.390)/8.65530));
ALGEBRAIC[ya] =  3.50000e-06*exp( - 0.0497000*STATES[v]);
ALGEBRAIC[yb] =  0.0400300*exp( 0.0521100*STATES[v]);
ALGEBRAIC[ytc] = 1.00000/(ALGEBRAIC[ya]+ALGEBRAIC[yb]);
ALGEBRAIC[vFRT] = ( STATES[v]*CONSTANTS[frdy])/( CONSTANTS[R]*CONSTANTS[temp]);
ALGEBRAIC[K1cl] =  0.000600000*exp( 2.53000*ALGEBRAIC[vFRT]);
ALGEBRAIC[K2cl] =  0.100000*exp( - 5.00000*ALGEBRAIC[vFRT]);
ALGEBRAIC[css] = 1.00000/(1.00000+ ALGEBRAIC[K2cl]*(pow(ALGEBRAIC[K1cl]/STATES[cai], 2.00000)+ALGEBRAIC[K1cl]/STATES[cai]+1.00000));
ALGEBRAIC[ctc] = - 160.000+210.000/(1.00000+exp((STATES[v]+4.56000)/11.6200))+170.000/(1.00000+exp(- (STATES[v]+25.5000)/11.6200));
ALGEBRAIC[Ist] = (TIME>CONSTANTS[test_start]&&TIME<CONSTANTS[test_end] ? CONSTANTS[I_test] : CONSTANTS[I_hold]);
ALGEBRAIC[ina] =  CONSTANTS[gna]*STATES[m]*STATES[m]*STATES[m]*STATES[h]*(STATES[v] - CONSTANTS[ena]);
ALGEBRAIC[fca] = 1.00000/(1.00000+pow(STATES[cai]/CONSTANTS[kmca], 4.00000));
ALGEBRAIC[ical] =  CONSTANTS[gcal]*ALGEBRAIC[fca]*STATES[d]*STATES[d]*( 0.800000*STATES[f1]+ 0.200000*STATES[f2])*(STATES[v] - CONSTANTS[ecal]);
ALGEBRAIC[icat] =  CONSTANTS[gcat]*STATES[b]*STATES[b]*STATES[g]*(STATES[v] - CONSTANTS[ecat]);
ALGEBRAIC[ib] =  CONSTANTS[gb]*(STATES[v] - CONSTANTS[ek]);
ALGEBRAIC[ik1] =  CONSTANTS[gk1]*STATES[q]*STATES[q]*( 0.380000*STATES[r1]+ 0.630000*STATES[r2])*(STATES[v] - CONSTANTS[ek]);
ALGEBRAIC[ik2] =  CONSTANTS[gk2]*STATES[p]*STATES[p]*( 0.750000*STATES[k1]+ 0.250000*STATES[k2])*(STATES[v] - CONSTANTS[ek]);
ALGEBRAIC[ika] =  CONSTANTS[gka]*STATES[s]*STATES[x]*(STATES[v] - CONSTANTS[ek]);
ALGEBRAIC[iBKa] =  CONSTANTS[gkca]*CONSTANTS[gbka]*STATES[xa]*(STATES[v] - CONSTANTS[ek]);
ALGEBRAIC[iBKab] =  CONSTANTS[gkca]*CONSTANTS[gbkab]*STATES[xab]*(STATES[v] - CONSTANTS[ek]);
ALGEBRAIC[ih] =  CONSTANTS[gh]*STATES[y]*(STATES[v] - CONSTANTS[eh]);
ALGEBRAIC[icl] =  CONSTANTS[gcl]*STATES[c]*(STATES[v] - CONSTANTS[ecl]);
ALGEBRAIC[enscc] =  (( CONSTANTS[R]*CONSTANTS[temp])/CONSTANTS[frdy])*log(( CONSTANTS[PnsK]*CONSTANTS[ko]+ CONSTANTS[PnsNa]*CONSTANTS[nao]+( 4.00000*CONSTANTS[PnsCa]*CONSTANTS[cao])/(1.00000+exp(ALGEBRAIC[vFRT])))/( CONSTANTS[PnsK]*CONSTANTS[ki]+ CONSTANTS[PnsNa]*CONSTANTS[nai]+( 4.00000*CONSTANTS[PnsCa]*STATES[cai])/(1.00000+exp(ALGEBRAIC[vFRT]))));
ALGEBRAIC[insna] =  CONSTANTS[fmg]*CONSTANTS[gs_nao]*CONSTANTS[gnsNa]*CONSTANTS[gns]*(STATES[v] - ALGEBRAIC[enscc]);
ALGEBRAIC[insca] =  CONSTANTS[fmg]*CONSTANTS[gs_cao]*CONSTANTS[gnsCa]*CONSTANTS[gns]*(STATES[v] - ALGEBRAIC[enscc]);
ALGEBRAIC[insk] =  CONSTANTS[fmg]*CONSTANTS[gs_ko]*CONSTANTS[gnsK]*CONSTANTS[gns]*(STATES[v] - ALGEBRAIC[enscc]);
ALGEBRAIC[fnak] = 1.00000/(1.00000+ 0.124500*exp( - 0.100000*ALGEBRAIC[vFRT])+ 0.00219000*exp(CONSTANTS[nao]/49.7100)*exp( - 1.90000*ALGEBRAIC[vFRT]));
ALGEBRAIC[inak] =  CONSTANTS[ginak]*CONSTANTS[knak]*CONSTANTS[nnak]*ALGEBRAIC[fnak];
ALGEBRAIC[fallo] = 1.00000/(1.00000+pow(CONSTANTS[Kmallo]/STATES[cai], CONSTANTS[nallo]));
ALGEBRAIC[f1naca] = exp( (CONSTANTS[xgamma] - 1.00000)*ALGEBRAIC[vFRT]);
ALGEBRAIC[f2naca] = exp( CONSTANTS[xgamma]*ALGEBRAIC[vFRT]);
ALGEBRAIC[naca_Eup] =  pow(CONSTANTS[nai], 3.00000)*CONSTANTS[cao]*ALGEBRAIC[f2naca] -  pow(CONSTANTS[nao], 3.00000)*STATES[cai]*ALGEBRAIC[f1naca];
ALGEBRAIC[naca_Ed1] = 1.00000+ CONSTANTS[ksat]*ALGEBRAIC[f1naca];
ALGEBRAIC[naca_Ed2] =  CONSTANTS[Kmcao]*pow(CONSTANTS[nai], 3.00000)+ pow(CONSTANTS[Kmnao], 3.00000)*STATES[cai]+ pow(CONSTANTS[Kmnai], 3.00000)*CONSTANTS[cao]*(1.00000+STATES[cai]/CONSTANTS[Kmcai]);
ALGEBRAIC[naca_Ed3] =  CONSTANTS[cao]*pow(CONSTANTS[nai], 3.00000)+ pow(CONSTANTS[nao], 3.00000)*STATES[cai]+ pow(CONSTANTS[nao], 3.00000)*CONSTANTS[Kmcai]*(1.00000+pow(CONSTANTS[nai]/CONSTANTS[Kmnai], 3.00000));
ALGEBRAIC[jnaca] = ( CONSTANTS[jnaca_sign]*CONSTANTS[Jnaca]*ALGEBRAIC[fallo]*ALGEBRAIC[naca_Eup])/( ALGEBRAIC[naca_Ed1]*(ALGEBRAIC[naca_Ed2]+ALGEBRAIC[naca_Ed3]));
ALGEBRAIC[inaca] =  (( 0.500000*CONSTANTS[zca]*CONSTANTS[frdy])/( CONSTANTS[AV]*CONSTANTS[Cm]*CONSTANTS[buff]))*CONSTANTS[inaca_sign]*ALGEBRAIC[jnaca];
ALGEBRAIC[I_tot] = ALGEBRAIC[ina]+ALGEBRAIC[ih]+ALGEBRAIC[inaca]+ALGEBRAIC[inak]+ALGEBRAIC[ical]+ALGEBRAIC[icat]+ALGEBRAIC[icl]+ALGEBRAIC[ik1]+ALGEBRAIC[ik2]+ALGEBRAIC[ika]+ALGEBRAIC[iBKa]+ALGEBRAIC[iBKab]+ALGEBRAIC[insna]+ALGEBRAIC[insk]+ALGEBRAIC[insca]+ALGEBRAIC[ib];
ALGEBRAIC[I_Ca_tot] = ALGEBRAIC[ical]+ALGEBRAIC[icat]+ALGEBRAIC[insca];
ALGEBRAIC[J_Ca_mem] =  (( CONSTANTS[AV]*CONSTANTS[Cm]*CONSTANTS[buff])/( CONSTANTS[zca]*CONSTANTS[frdy]))*ALGEBRAIC[I_Ca_tot];
ALGEBRAIC[jpmca] = CONSTANTS[Jpmca]/(1.00000+pow(CONSTANTS[Kmpmca]/STATES[cai], CONSTANTS[npmca]));
ALGEBRAIC[J_tot] = ALGEBRAIC[J_Ca_mem]+ALGEBRAIC[jnaca]+ALGEBRAIC[jpmca];
ALGEBRAIC[Force] =  CONSTANTS[Fmax]*(STATES[w] - 0.234500);
ALGEBRAIC[jcamem_plot] =  ALGEBRAIC[J_Ca_mem]*CONSTANTS[conversion_Ca_Concentrations];
ALGEBRAIC[jnaca_plot] =  ALGEBRAIC[jnaca]*CONSTANTS[conversion_Ca_Concentrations];
ALGEBRAIC[jpmca_plot] =  ALGEBRAIC[jpmca]*CONSTANTS[conversion_Ca_Concentrations];

RATES[f1] = (ALGEBRAIC[fss] - STATES[f1])/CONSTANTS[f1tc];
RATES[w] = (ALGEBRAIC[wss] - STATES[w])/ALGEBRAIC[wtc];
RATES[m] = (ALGEBRAIC[mss] - STATES[m])/ALGEBRAIC[mtc];
RATES[h] = (ALGEBRAIC[hss] - STATES[h])/ALGEBRAIC[htc];
RATES[d] = (ALGEBRAIC[dss] - STATES[d])/ALGEBRAIC[dtc];
RATES[f2] = (ALGEBRAIC[fss] - STATES[f2])/ALGEBRAIC[f2tc];
RATES[b] = (ALGEBRAIC[bss] - STATES[b])/ALGEBRAIC[btc];
RATES[g] = (ALGEBRAIC[gss] - STATES[g])/ALGEBRAIC[gtc];
RATES[q] = (ALGEBRAIC[qss] - STATES[q])/ALGEBRAIC[qtc];
RATES[r1] = (ALGEBRAIC[rss] - STATES[r1])/ALGEBRAIC[r1tc];
RATES[r2] = (ALGEBRAIC[rss] - STATES[r2])/ALGEBRAIC[r2tc];
RATES[p] = (ALGEBRAIC[pss] - STATES[p])/ALGEBRAIC[ptc];
RATES[k1] = (ALGEBRAIC[kss] - STATES[k1])/ALGEBRAIC[k1tc];
RATES[k2] = (ALGEBRAIC[kss] - STATES[k2])/ALGEBRAIC[k2tc];
RATES[s] = (ALGEBRAIC[sss] - STATES[s])/ALGEBRAIC[stc];
RATES[x] = (ALGEBRAIC[xss] - STATES[x])/ALGEBRAIC[xtc];
RATES[xa] = (ALGEBRAIC[xass] - STATES[xa])/ALGEBRAIC[xatc];
RATES[xab] = (ALGEBRAIC[xabss] - STATES[xab])/ALGEBRAIC[xabtc];
RATES[y] = (ALGEBRAIC[yss] - STATES[y])/ALGEBRAIC[ytc];
RATES[c] = (ALGEBRAIC[css] - STATES[c])/ALGEBRAIC[ctc];
RATES[v] = - (ALGEBRAIC[I_tot]+ALGEBRAIC[Ist]);
RATES[cai] = - ALGEBRAIC[J_tot];
}

void Tong_Choi_Kharche_Holden_Zhang_Taggart_2011::solveAnalytical(double dt)
{
}
