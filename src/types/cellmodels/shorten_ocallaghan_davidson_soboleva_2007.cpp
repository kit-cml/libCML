/*
   There are a total of 71 entries in the algebraic variable array.
   There are a total of 56 entries in each of the rate and state variable arrays.
   There are a total of 105 entries in the constant variable array.
 */

#include "shorten_ocallaghan_davidson_soboleva_2007.hpp"
#include <cmath>
#include <cstdlib>

/*
 * TIME is time in component cell (millisecond).
 * CONSTANTS[C_m] is C_m in component wal_environment (microF_per_cm2).
 * CONSTANTS[gam] is gam in component wal_environment (dimensionless).
 * CONSTANTS[R_a] is R_a in component wal_environment (ohm_cm2).
 * CONSTANTS[tsi] is tsi in component wal_environment (centi_metre).
 * CONSTANTS[tsi2] is tsi2 in component wal_environment (centi_metre).
 * CONSTANTS[tsi3] is tsi3 in component wal_environment (centi_metre).
 * CONSTANTS[FF] is FF in component wal_environment (C_per_mol).
 * CONSTANTS[tau_K] is tau_K in component wal_environment (millisecond).
 * CONSTANTS[tau_Na] is tau_Na in component wal_environment (millisecond).
 * CONSTANTS[f_T] is f_T in component wal_environment (dimensionless).
 * CONSTANTS[tau_K2] is tau_K2 in component wal_environment (millisecond).
 * CONSTANTS[tau_Na2] is tau_Na2 in component wal_environment (millisecond).
 * CONSTANTS[I_K_rest] is I_K_rest in component wal_environment (microA_per_cm2).
 * CONSTANTS[I_Na_rest] is I_Na_rest in component wal_environment (microA_per_cm2).
 * CONSTANTS[alpha_h_bar] is alpha_h_bar in component wal_environment (per_millisecond).
 * CONSTANTS[alpha_m_bar] is alpha_m_bar in component wal_environment (per_millisecond_per_millivolt).
 * CONSTANTS[alpha_n_bar] is alpha_n_bar in component wal_environment (per_millisecond_per_millivolt).
 * CONSTANTS[beta_h_bar] is beta_h_bar in component wal_environment (per_millisecond).
 * CONSTANTS[beta_m_bar] is beta_m_bar in component wal_environment (per_millisecond).
 * CONSTANTS[beta_n_bar] is beta_n_bar in component wal_environment (per_millisecond).
 * CONSTANTS[V_m] is V_m in component wal_environment (millivolt).
 * CONSTANTS[V_n] is V_n in component wal_environment (millivolt).
 * CONSTANTS[V_h] is V_h in component wal_environment (millivolt).
 * CONSTANTS[V_a] is V_a in component wal_environment (millivolt).
 * CONSTANTS[V_S_inf] is V_S_inf in component wal_environment (millivolt).
 * CONSTANTS[V_h_K_inf] is V_h_K_inf in component wal_environment (millivolt).
 * CONSTANTS[A_a] is A_a in component wal_environment (millivolt).
 * CONSTANTS[A_S_inf] is A_S_inf in component wal_environment (millivolt).
 * CONSTANTS[A_h_K_inf] is A_h_K_inf in component wal_environment (millivolt).
 * CONSTANTS[K_alpha_h] is K_alpha_h in component wal_environment (millivolt).
 * CONSTANTS[K_beta_h] is K_beta_h in component wal_environment (millivolt).
 * CONSTANTS[K_alpha_m] is K_alpha_m in component wal_environment (millivolt).
 * CONSTANTS[K_alpha_n] is K_alpha_n in component wal_environment (millivolt).
 * CONSTANTS[K_beta_m] is K_beta_m in component wal_environment (millivolt).
 * CONSTANTS[K_beta_n] is K_beta_n in component wal_environment (millivolt).
 * CONSTANTS[RR] is RR in component wal_environment (milliJ_per_degreeK_per_mol).
 * CONSTANTS[TT] is TT in component wal_environment (degreeK).
 * CONSTANTS[g_Cl_bar] is g_Cl_bar in component wal_environment (milliS_per_cm2).
 * CONSTANTS[g_K_bar] is g_K_bar in component wal_environment (milliS_per_cm2).
 * CONSTANTS[g_Na_bar] is g_Na_bar in component wal_environment (milliS_per_cm2).
 * CONSTANTS[G_K] is G_K in component wal_environment (milliS_per_cm2).
 * CONSTANTS[del] is del in component wal_environment (dimensionless).
 * CONSTANTS[K_K] is K_K in component wal_environment (milliM2).
 * CONSTANTS[K_S] is K_S in component wal_environment (milliM2).
 * CONSTANTS[K_m_K] is K_m_K in component wal_environment (milliM).
 * CONSTANTS[K_m_Na] is K_m_Na in component wal_environment (milliM).
 * CONSTANTS[S_i] is S_i in component wal_environment (milliM).
 * CONSTANTS[J_NaK_bar] is J_NaK_bar in component wal_environment (micro_mol_per_cm2_per_second).
 * CONSTANTS[V_tau] is V_tau in component wal_environment (millivolt).
 * ALGEBRAIC[I_T] is I_T in component wal_environment (microA_per_cm2).
 * STATES[vS] is vS in component wal_environment (millivolt).
 * STATES[vT] is vT in component wal_environment (millivolt).
 * ALGEBRAIC[I_ionic_s] is I_ionic_s in component wal_environment (microA_per_cm2).
 * ALGEBRAIC[I_ionic_t] is I_ionic_t in component wal_environment (microA_per_cm2).
 * STATES[K_t] is K_t in component wal_environment (milliM).
 * STATES[K_i] is K_i in component wal_environment (milliM).
 * STATES[K_e] is K_e in component wal_environment (milliM).
 * STATES[Na_i] is Na_i in component wal_environment (milliM).
 * STATES[Na_t] is Na_t in component wal_environment (milliM).
 * STATES[Na_e] is Na_e in component wal_environment (milliM).
 * ALGEBRAIC[E_K] is E_K in component wal_environment (millivolt).
 * ALGEBRAIC[E_K_t] is E_K_t in component wal_environment (millivolt).
 * ALGEBRAIC[Cl_i] is Cl_i in component wal_environment (milliM).
 * ALGEBRAIC[Cl_o] is Cl_o in component wal_environment (milliM).
 * ALGEBRAIC[Cl_i_t] is Cl_i_t in component wal_environment (milliM).
 * ALGEBRAIC[Cl_o_t] is Cl_o_t in component wal_environment (milliM).
 * ALGEBRAIC[J_K] is J_K in component wal_environment (milliV_milliM).
 * ALGEBRAIC[J_K_t] is J_K_t in component wal_environment (milliV_milliM).
 * CONSTANTS[eta_Cl] is eta_Cl in component wal_environment (dimensionless).
 * CONSTANTS[eta_IR] is eta_IR in component wal_environment (dimensionless).
 * CONSTANTS[eta_DR] is eta_DR in component wal_environment (dimensionless).
 * CONSTANTS[eta_Na] is eta_Na in component wal_environment (dimensionless).
 * CONSTANTS[eta_NaK] is eta_NaK in component wal_environment (dimensionless).
 * ALGEBRAIC[I_Cl] is I_Cl in component sarco_Cl_channel (microA_per_cm2).
 * ALGEBRAIC[I_IR] is I_IR in component sarco_IR_channel (microA_per_cm2).
 * ALGEBRAIC[I_DR] is I_DR in component sarco_DR_channel (microA_per_cm2).
 * ALGEBRAIC[I_Na] is I_Na in component sarco_Na_channel (microA_per_cm2).
 * ALGEBRAIC[I_NaK] is I_NaK in component sarco_NaK_channel (microA_per_cm2).
 * ALGEBRAIC[I_Cl_t] is I_Cl_t in component t_Cl_channel (microA_per_cm2).
 * ALGEBRAIC[I_IR_t] is I_IR_t in component t_IR_channel (microA_per_cm2).
 * ALGEBRAIC[I_DR_t] is I_DR_t in component t_DR_channel (microA_per_cm2).
 * ALGEBRAIC[I_Na_t] is I_Na_t in component t_Na_channel (microA_per_cm2).
 * ALGEBRAIC[I_NaK_t] is I_NaK_t in component t_NaK_channel (microA_per_cm2).
 * ALGEBRAIC[I_HH] is I_HH in component wal_environment (microA_per_cm2).
 * ALGEBRAIC[a] is a in component sarco_Cl_channel (dimensionless).
 * ALGEBRAIC[J_Cl] is J_Cl in component sarco_Cl_channel (milliV_milliM).
 * ALGEBRAIC[g_Cl] is g_Cl in component sarco_Cl_channel (milliS_per_cm2).
 * ALGEBRAIC[K_R] is K_R in component sarco_IR_channel (milliM).
 * ALGEBRAIC[g_IR_bar] is g_IR_bar in component sarco_IR_channel (milliS_per_cm2).
 * ALGEBRAIC[y] is y in component sarco_IR_channel (dimensionless).
 * ALGEBRAIC[g_IR] is g_IR in component sarco_IR_channel (milliS_per_cm2).
 * ALGEBRAIC[alpha_n] is alpha_n in component sarco_DR_channel (per_millisecond).
 * ALGEBRAIC[beta_n] is beta_n in component sarco_DR_channel (per_millisecond).
 * ALGEBRAIC[h_K_inf] is h_K_inf in component sarco_DR_channel (dimensionless).
 * ALGEBRAIC[tau_h_K] is tau_h_K in component sarco_DR_channel (millisecond).
 * STATES[n] is n in component sarco_DR_channel (dimensionless).
 * STATES[h_K] is h_K in component sarco_DR_channel (dimensionless).
 * ALGEBRAIC[g_DR] is g_DR in component sarco_DR_channel (milliS_per_cm2).
 * ALGEBRAIC[alpha_h] is alpha_h in component sarco_Na_channel (per_millisecond).
 * ALGEBRAIC[beta_h] is beta_h in component sarco_Na_channel (per_millisecond).
 * ALGEBRAIC[alpha_m] is alpha_m in component sarco_Na_channel (per_millisecond).
 * ALGEBRAIC[beta_m] is beta_m in component sarco_Na_channel (per_millisecond).
 * ALGEBRAIC[S_inf] is S_inf in component sarco_Na_channel (dimensionless).
 * ALGEBRAIC[tau_S] is tau_S in component sarco_Na_channel (millisecond).
 * STATES[m] is m in component sarco_Na_channel (dimensionless).
 * STATES[h] is h in component sarco_Na_channel (dimensionless).
 * STATES[S] is S in component sarco_Na_channel (dimensionless).
 * ALGEBRAIC[g_Na] is g_Na in component sarco_Na_channel (milliS_per_cm2).
 * ALGEBRAIC[J_Na] is J_Na in component sarco_Na_channel (milliV_milliM).
 * ALGEBRAIC[sig] is sig in component sarco_NaK_channel (dimensionless).
 * ALGEBRAIC[f1] is f1 in component sarco_NaK_channel (dimensionless).
 * ALGEBRAIC[I_NaK_bar] is I_NaK_bar in component sarco_NaK_channel (microA_per_cm2).
 * ALGEBRAIC[a_t] is a_t in component t_Cl_channel (dimensionless).
 * ALGEBRAIC[J_Cl_t] is J_Cl_t in component t_Cl_channel (milliV_milliM).
 * ALGEBRAIC[g_Cl_t] is g_Cl_t in component t_Cl_channel (milliS_per_cm2).
 * ALGEBRAIC[K_R_t] is K_R_t in component t_IR_channel (milliM).
 * ALGEBRAIC[g_IR_bar_t] is g_IR_bar_t in component t_IR_channel (milliS_per_cm2).
 * ALGEBRAIC[y_t] is y_t in component t_IR_channel (dimensionless).
 * ALGEBRAIC[g_IR_t] is g_IR_t in component t_IR_channel (milliS_per_cm2).
 * ALGEBRAIC[alpha_n_t] is alpha_n_t in component t_DR_channel (per_millisecond).
 * ALGEBRAIC[beta_n_t] is beta_n_t in component t_DR_channel (per_millisecond).
 * ALGEBRAIC[h_K_inf_t] is h_K_inf_t in component t_DR_channel (dimensionless).
 * ALGEBRAIC[tau_h_K_t] is tau_h_K_t in component t_DR_channel (millisecond).
 * STATES[n_t] is n_t in component t_DR_channel (dimensionless).
 * STATES[h_K_t] is h_K_t in component t_DR_channel (dimensionless).
 * ALGEBRAIC[g_DR_t] is g_DR_t in component t_DR_channel (milliS_per_cm2).
 * ALGEBRAIC[alpha_h_t] is alpha_h_t in component t_Na_channel (per_millisecond).
 * ALGEBRAIC[beta_h_t] is beta_h_t in component t_Na_channel (per_millisecond).
 * ALGEBRAIC[alpha_m_t] is alpha_m_t in component t_Na_channel (per_millisecond).
 * ALGEBRAIC[beta_m_t] is beta_m_t in component t_Na_channel (per_millisecond).
 * ALGEBRAIC[S_inf_t] is S_inf_t in component t_Na_channel (dimensionless).
 * ALGEBRAIC[tau_S_t] is tau_S_t in component t_Na_channel (millisecond).
 * STATES[m_t] is m_t in component t_Na_channel (dimensionless).
 * STATES[h_t] is h_t in component t_Na_channel (dimensionless).
 * STATES[S_t] is S_t in component t_Na_channel (dimensionless).
 * ALGEBRAIC[g_Na_t] is g_Na_t in component t_Na_channel (milliS_per_cm2).
 * ALGEBRAIC[J_Na_t] is J_Na_t in component t_Na_channel (milliV_milliM).
 * ALGEBRAIC[sig_t] is sig_t in component t_NaK_channel (dimensionless).
 * ALGEBRAIC[f1_t] is f1_t in component t_NaK_channel (dimensionless).
 * ALGEBRAIC[I_NaK_bar_t] is I_NaK_bar_t in component t_NaK_channel (microA_per_cm2).
 * STATES[O_0] is O_0 in component sternrios (dimensionless).
 * STATES[O_1] is O_1 in component sternrios (dimensionless).
 * STATES[O_2] is O_2 in component sternrios (dimensionless).
 * STATES[O_3] is O_3 in component sternrios (dimensionless).
 * STATES[O_4] is O_4 in component sternrios (dimensionless).
 * CONSTANTS[k_L] is k_L in component sternrios (per_millisecond).
 * CONSTANTS[k_Lm] is k_Lm in component sternrios (per_millisecond).
 * CONSTANTS[f] is f in component sternrios (dimensionless).
 * CONSTANTS[alpha1] is alpha1 in component sternrios (per_millisecond).
 * CONSTANTS[K] is K in component sternrios (millivolt).
 * CONSTANTS[Vbar] is Vbar in component sternrios (millivolt).
 * STATES[C_0] is C_0 in component sternrios (dimensionless).
 * STATES[C_1] is C_1 in component sternrios (dimensionless).
 * STATES[C_2] is C_2 in component sternrios (dimensionless).
 * STATES[C_3] is C_3 in component sternrios (dimensionless).
 * STATES[C_4] is C_4 in component sternrios (dimensionless).
 * ALGEBRAIC[k_C] is k_C in component sternrios (per_millisecond).
 * ALGEBRAIC[k_Cm] is k_Cm in component sternrios (per_millisecond).
 * CONSTANTS[nu_SR] is nu_SR in component razumova (micromolar_per_millisecond_micrometre3).
 * CONSTANTS[K_SR] is K_SR in component razumova (micromolar).
 * CONSTANTS[L_e] is L_e in component razumova (micrometre3_per_millisecond).
 * CONSTANTS[tau_R] is tau_R in component razumova (micrometre3_per_millisecond).
 * CONSTANTS[tau_SR_R] is tau_SR_R in component razumova (micrometre3_per_millisecond).
 * CONSTANTS[L_x] is L_x in component razumova (micrometre).
 * CONSTANTS[R_R] is R_R in component razumova (micrometre).
 * CONSTANTS[V_o] is V_o in component razumova (micrometre3).
 * CONSTANTS[V_1] is V_1 in component razumova (micrometre3).
 * CONSTANTS[V_2] is V_2 in component razumova (micrometre3).
 * CONSTANTS[V_SR] is V_SR in component razumova (micrometre3).
 * CONSTANTS[V_SR1] is V_SR1 in component razumova (micrometre3).
 * CONSTANTS[V_SR2] is V_SR2 in component razumova (micrometre3).
 * CONSTANTS[k_T_on] is k_T_on in component razumova (per_micromolar_per_millisecond).
 * CONSTANTS[k_T_off] is k_T_off in component razumova (per_millisecond).
 * CONSTANTS[T_tot] is T_tot in component razumova (micromolar).
 * CONSTANTS[k_P_on] is k_P_on in component razumova (per_micromolar_per_millisecond).
 * CONSTANTS[k_P_off] is k_P_off in component razumova (per_millisecond).
 * CONSTANTS[P_tot] is P_tot in component razumova (micromolar).
 * CONSTANTS[k_Mg_on] is k_Mg_on in component razumova (per_micromolar_per_millisecond).
 * CONSTANTS[k_Mg_off] is k_Mg_off in component razumova (per_millisecond).
 * CONSTANTS[k_Cs_on] is k_Cs_on in component razumova (per_micromolar_per_millisecond).
 * CONSTANTS[k_Cs_off] is k_Cs_off in component razumova (per_millisecond).
 * CONSTANTS[Cs_tot] is Cs_tot in component razumova (micromolar).
 * CONSTANTS[k_CATP_on] is k_CATP_on in component razumova (per_micromolar_per_millisecond).
 * CONSTANTS[k_CATP_off] is k_CATP_off in component razumova (per_millisecond).
 * CONSTANTS[k_MATP_on] is k_MATP_on in component razumova (per_micromolar_per_millisecond).
 * CONSTANTS[k_MATP_off] is k_MATP_off in component razumova (per_millisecond).
 * CONSTANTS[tau_ATP] is tau_ATP in component razumova (micrometre3_per_millisecond).
 * CONSTANTS[tau_Mg] is tau_Mg in component razumova (micrometre3_per_millisecond).
 * CONSTANTS[k_0_on] is k_0_on in component razumova (per_millisecond).
 * CONSTANTS[k_0_off] is k_0_off in component razumova (per_millisecond).
 * CONSTANTS[k_Ca_on] is k_Ca_on in component razumova (per_millisecond).
 * CONSTANTS[k_Ca_off] is k_Ca_off in component razumova (per_millisecond).
 * CONSTANTS[f_o] is f_o in component razumova (per_millisecond).
 * CONSTANTS[f_p] is f_p in component razumova (per_millisecond).
 * CONSTANTS[h_o] is h_o in component razumova (per_millisecond).
 * CONSTANTS[h_p] is h_p in component razumova (per_millisecond).
 * CONSTANTS[g_o] is g_o in component razumova (per_millisecond).
 * CONSTANTS[b_p] is b_p in component razumova (per_millisecond).
 * CONSTANTS[k_p] is k_p in component razumova (micrometre3_per_millisecond).
 * CONSTANTS[A_p] is A_p in component razumova (per_milliM3_per_millisecond).
 * CONSTANTS[B_p] is B_p in component razumova (per_milliM2_per_millisecond).
 * CONSTANTS[PP] is PP in component razumova (milliM2).
 * ALGEBRAIC[T_0] is T_0 in component razumova (micromolar).
 * STATES[Ca_1] is Ca_1 in component razumova (micromolar).
 * STATES[Ca_SR1] is Ca_SR1 in component razumova (micromolar).
 * STATES[Ca_2] is Ca_2 in component razumova (micromolar).
 * STATES[Ca_SR2] is Ca_SR2 in component razumova (micromolar).
 * STATES[Ca_T_2] is Ca_T_2 in component razumova (micromolar).
 * STATES[Ca_P1] is Ca_P1 in component razumova (micromolar).
 * STATES[Ca_P2] is Ca_P2 in component razumova (micromolar).
 * STATES[Mg_P1] is Mg_P1 in component razumova (micromolar).
 * STATES[Mg_P2] is Mg_P2 in component razumova (micromolar).
 * STATES[Ca_Cs1] is Ca_Cs1 in component razumova (micromolar).
 * STATES[Ca_Cs2] is Ca_Cs2 in component razumova (micromolar).
 * STATES[Ca_ATP1] is Ca_ATP1 in component razumova (micromolar).
 * STATES[Ca_ATP2] is Ca_ATP2 in component razumova (micromolar).
 * STATES[Mg_ATP1] is Mg_ATP1 in component razumova (micromolar).
 * STATES[Mg_ATP2] is Mg_ATP2 in component razumova (micromolar).
 * STATES[ATP1] is ATP1 in component razumova (micromolar).
 * STATES[ATP2] is ATP2 in component razumova (micromolar).
 * STATES[Mg1] is Mg1 in component razumova (micromolar).
 * STATES[Mg2] is Mg2 in component razumova (micromolar).
 * STATES[Ca_CaT2] is Ca_CaT2 in component razumova (micromolar).
 * STATES[D_0] is D_0 in component razumova (micromolar).
 * STATES[D_1] is D_1 in component razumova (micromolar).
 * STATES[D_2] is D_2 in component razumova (micromolar).
 * STATES[A_1] is A_1 in component razumova (micromolar).
 * STATES[A_2] is A_2 in component razumova (micromolar).
 * STATES[P] is P in component razumova (milliM).
 * STATES[P_SR] is P_SR in component razumova (milliM).
 * STATES[P_C_SR] is P_C_SR in component razumova (milliM).
 * CONSTANTS[i2] is i2 in component razumova (micrometre3_per_millisecond).
 * RATES[vS] is d/dt vS in component wal_environment (millivolt).
 * RATES[vT] is d/dt vT in component wal_environment (millivolt).
 * RATES[K_i] is d/dt K_i in component wal_environment (milliM).
 * RATES[K_t] is d/dt K_t in component wal_environment (milliM).
 * RATES[K_e] is d/dt K_e in component wal_environment (milliM).
 * RATES[Na_i] is d/dt Na_i in component wal_environment (milliM).
 * RATES[Na_t] is d/dt Na_t in component wal_environment (milliM).
 * RATES[Na_e] is d/dt Na_e in component wal_environment (milliM).
 * RATES[n] is d/dt n in component sarco_DR_channel (dimensionless).
 * RATES[h_K] is d/dt h_K in component sarco_DR_channel (dimensionless).
 * RATES[m] is d/dt m in component sarco_Na_channel (dimensionless).
 * RATES[h] is d/dt h in component sarco_Na_channel (dimensionless).
 * RATES[S] is d/dt S in component sarco_Na_channel (dimensionless).
 * RATES[n_t] is d/dt n_t in component t_DR_channel (dimensionless).
 * RATES[h_K_t] is d/dt h_K_t in component t_DR_channel (dimensionless).
 * RATES[m_t] is d/dt m_t in component t_Na_channel (dimensionless).
 * RATES[h_t] is d/dt h_t in component t_Na_channel (dimensionless).
 * RATES[S_t] is d/dt S_t in component t_Na_channel (dimensionless).
 * RATES[C_0] is d/dt C_0 in component sternrios (dimensionless).
 * RATES[O_0] is d/dt O_0 in component sternrios (dimensionless).
 * RATES[C_1] is d/dt C_1 in component sternrios (dimensionless).
 * RATES[O_1] is d/dt O_1 in component sternrios (dimensionless).
 * RATES[C_2] is d/dt C_2 in component sternrios (dimensionless).
 * RATES[O_2] is d/dt O_2 in component sternrios (dimensionless).
 * RATES[C_3] is d/dt C_3 in component sternrios (dimensionless).
 * RATES[O_3] is d/dt O_3 in component sternrios (dimensionless).
 * RATES[C_4] is d/dt C_4 in component sternrios (dimensionless).
 * RATES[O_4] is d/dt O_4 in component sternrios (dimensionless).
 * RATES[Ca_1] is d/dt Ca_1 in component razumova (micromolar).
 * RATES[Ca_SR1] is d/dt Ca_SR1 in component razumova (micromolar).
 * RATES[Ca_2] is d/dt Ca_2 in component razumova (micromolar).
 * RATES[Ca_SR2] is d/dt Ca_SR2 in component razumova (micromolar).
 * RATES[Ca_T_2] is d/dt Ca_T_2 in component razumova (micromolar).
 * RATES[Ca_P1] is d/dt Ca_P1 in component razumova (micromolar).
 * RATES[Ca_P2] is d/dt Ca_P2 in component razumova (micromolar).
 * RATES[Mg_P1] is d/dt Mg_P1 in component razumova (micromolar).
 * RATES[Mg_P2] is d/dt Mg_P2 in component razumova (micromolar).
 * RATES[Ca_Cs1] is d/dt Ca_Cs1 in component razumova (micromolar).
 * RATES[Ca_Cs2] is d/dt Ca_Cs2 in component razumova (micromolar).
 * RATES[Ca_ATP1] is d/dt Ca_ATP1 in component razumova (micromolar).
 * RATES[Ca_ATP2] is d/dt Ca_ATP2 in component razumova (micromolar).
 * RATES[Mg_ATP1] is d/dt Mg_ATP1 in component razumova (micromolar).
 * RATES[Mg_ATP2] is d/dt Mg_ATP2 in component razumova (micromolar).
 * RATES[ATP1] is d/dt ATP1 in component razumova (micromolar).
 * RATES[ATP2] is d/dt ATP2 in component razumova (micromolar).
 * RATES[Mg1] is d/dt Mg1 in component razumova (micromolar).
 * RATES[Mg2] is d/dt Mg2 in component razumova (micromolar).
 * RATES[Ca_CaT2] is d/dt Ca_CaT2 in component razumova (micromolar).
 * RATES[D_0] is d/dt D_0 in component razumova (micromolar).
 * RATES[D_1] is d/dt D_1 in component razumova (micromolar).
 * RATES[D_2] is d/dt D_2 in component razumova (micromolar).
 * RATES[A_1] is d/dt A_1 in component razumova (micromolar).
 * RATES[A_2] is d/dt A_2 in component razumova (micromolar).
 * RATES[P] is d/dt P in component razumova (milliM).
 * RATES[P_SR] is d/dt P_SR in component razumova (milliM).
 * RATES[P_C_SR] is d/dt P_C_SR in component razumova (milliM).
 */


shorten_ocallaghan_davidson_soboleva_2007::shorten_ocallaghan_davidson_soboleva_2007()
{
algebraic_size = 71;
constants_size = 105;
states_size = 56;
ALGEBRAIC = new double[algebraic_size];
CONSTANTS = new double[constants_size];
RATES = new double[states_size];
STATES = new double[states_size];
}

shorten_ocallaghan_davidson_soboleva_2007::~shorten_ocallaghan_davidson_soboleva_2007()
{
delete []ALGEBRAIC;
delete []CONSTANTS;
delete []RATES;
delete []STATES;
}

void shorten_ocallaghan_davidson_soboleva_2007::initConsts()
{
CONSTANTS[C_m] = 1.0;
CONSTANTS[gam] = 4.8;
CONSTANTS[R_a] = 150;
CONSTANTS[tsi] = 0.000001;
CONSTANTS[tsi2] = 0.0025;
CONSTANTS[tsi3] = 0.0005;
CONSTANTS[FF] = 96485;
CONSTANTS[tau_K] = 350;
CONSTANTS[tau_Na] = 350;
CONSTANTS[f_T] = 0.0032;
CONSTANTS[tau_K2] = 21875;
CONSTANTS[tau_Na2] = 21875;
CONSTANTS[I_K_rest] = 1.02;
CONSTANTS[I_Na_rest] = -1.29;
CONSTANTS[alpha_h_bar] = 0.0081;
CONSTANTS[alpha_m_bar] = 0.288;
CONSTANTS[alpha_n_bar] = 0.0131;
CONSTANTS[beta_h_bar] = 4.38;
CONSTANTS[beta_m_bar] = 1.38;
CONSTANTS[beta_n_bar] = 0.067;
CONSTANTS[V_m] = -46;
CONSTANTS[V_n] = -40;
CONSTANTS[V_h] = -45;
CONSTANTS[V_a] = 70;
CONSTANTS[V_S_inf] = -78;
CONSTANTS[V_h_K_inf] = -40;
CONSTANTS[A_a] = 150;
CONSTANTS[A_S_inf] = 5.8;
CONSTANTS[A_h_K_inf] = 7.5;
CONSTANTS[K_alpha_h] = 14.7;
CONSTANTS[K_beta_h] = 9;
CONSTANTS[K_alpha_m] = 10;
CONSTANTS[K_alpha_n] = 7;
CONSTANTS[K_beta_m] = 18;
CONSTANTS[K_beta_n] = 40;
CONSTANTS[RR] = 8314.41;
CONSTANTS[TT] = 293;
CONSTANTS[g_Cl_bar] = 19.65;
CONSTANTS[g_K_bar] = 64.8;
CONSTANTS[g_Na_bar] = 804;
CONSTANTS[G_K] = 11.1;
CONSTANTS[del] = 0.4;
CONSTANTS[K_K] = 950;
CONSTANTS[K_S] = 1;
CONSTANTS[K_m_K] = 1;
CONSTANTS[K_m_Na] = 13;
CONSTANTS[S_i] = 10;
CONSTANTS[J_NaK_bar] = 0.000621;
CONSTANTS[V_tau] = 90;
STATES[vS] = -79.974;
STATES[vT] = -80.2;
STATES[K_t] = 5.9;
STATES[K_i] = 150.9;
STATES[K_e] = 5.9;
STATES[Na_i] = 12.7;
STATES[Na_t] = 133;
STATES[Na_e] = 133;
CONSTANTS[eta_Cl] = 0.1;
CONSTANTS[eta_IR] = 1.0;
CONSTANTS[eta_DR] = 0.45;
CONSTANTS[eta_Na] = 0.1;
CONSTANTS[eta_NaK] = 0.1;
STATES[n] = 0.009466;
STATES[h_K] = 0.9952;
STATES[m] = 0.0358;
STATES[h] = 0.4981;
STATES[S] = 0.581;
STATES[n_t] = 0.009466;
STATES[h_K_t] = 0.9952;
STATES[m_t] = 0.0358;
STATES[h_t] = 0.4981;
STATES[S_t] = 0.581;
STATES[O_0] = 0;
STATES[O_1] = 0;
STATES[O_2] = 0;
STATES[O_3] = 0;
STATES[O_4] = 0;
CONSTANTS[k_L] = 0.002;
CONSTANTS[k_Lm] = 1000;
CONSTANTS[f] = 0.2;
CONSTANTS[alpha1] = 0.2;
CONSTANTS[K] = 4.5;
CONSTANTS[Vbar] = -20;
STATES[C_0] = 1;
STATES[C_1] = 0;
STATES[C_2] = 0;
STATES[C_3] = 0;
STATES[C_4] = 0;
CONSTANTS[nu_SR] = 4.875;
CONSTANTS[K_SR] = 1;
CONSTANTS[L_e] = 0.00002;
CONSTANTS[tau_R] = 0.75;
CONSTANTS[tau_SR_R] = 0.75;
CONSTANTS[L_x] = 1.1;
CONSTANTS[R_R] = 0.5;
CONSTANTS[k_T_on] = 0.04425;
CONSTANTS[k_T_off] = 0.115;
CONSTANTS[T_tot] = 140;
CONSTANTS[k_P_on] = 0.0417;
CONSTANTS[k_P_off] = 0.0005;
CONSTANTS[P_tot] = 1500;
CONSTANTS[k_Mg_on] = 0.000033;
CONSTANTS[k_Mg_off] = 0.003;
CONSTANTS[k_Cs_on] = 0.000004;
CONSTANTS[k_Cs_off] = 0.005;
CONSTANTS[Cs_tot] = 31000;
CONSTANTS[k_CATP_on] = 0.15;
CONSTANTS[k_CATP_off] = 30;
CONSTANTS[k_MATP_on] = 0.0015;
CONSTANTS[k_MATP_off] = 0.15;
CONSTANTS[tau_ATP] = 0.375;
CONSTANTS[tau_Mg] = 1.5;
CONSTANTS[k_0_on] = 0;
CONSTANTS[k_0_off] = 0.15;
CONSTANTS[k_Ca_on] = 0.15;
CONSTANTS[k_Ca_off] = 0.05;
CONSTANTS[f_o] = 1.5;
CONSTANTS[f_p] = 15;
CONSTANTS[h_o] = 0.24;
CONSTANTS[h_p] = 0.18;
CONSTANTS[g_o] = 0.12;
CONSTANTS[b_p] = 0.00002867;
CONSTANTS[k_p] = 0.00000362;
CONSTANTS[A_p] = 1;
CONSTANTS[B_p] = 0.0001;
CONSTANTS[PP] = 6;
STATES[Ca_1] = 0.1;
STATES[Ca_SR1] = 1500;
STATES[Ca_2] = 0.1;
STATES[Ca_SR2] = 1500;
STATES[Ca_T_2] = 25;
STATES[Ca_P1] = 615;
STATES[Ca_P2] = 615;
STATES[Mg_P1] = 811;
STATES[Mg_P2] = 811;
STATES[Ca_Cs1] = 16900;
STATES[Ca_Cs2] = 16900;
STATES[Ca_ATP1] = 0.4;
STATES[Ca_ATP2] = 0.4;
STATES[Mg_ATP1] = 7200;
STATES[Mg_ATP2] = 7200;
STATES[ATP1] = 799.6;
STATES[ATP2] = 799.6;
STATES[Mg1] = 1000;
STATES[Mg2] = 1000;
STATES[Ca_CaT2] = 3;
STATES[D_0] = 0.8;
STATES[D_1] = 1.2;
STATES[D_2] = 3;
STATES[A_1] = 0.3;
STATES[A_2] = 0.23;
STATES[P] = 0.23;
STATES[P_SR] = 0.23;
STATES[P_C_SR] = 0.23;
CONSTANTS[i2] = 300;
CONSTANTS[V_o] =  0.950000*CONSTANTS[L_x]* 3.14159265358979*pow(CONSTANTS[R_R], 2.00000);
CONSTANTS[V_SR] =  0.0500000*CONSTANTS[L_x]* 3.14159265358979*pow(CONSTANTS[R_R], 2.00000);
CONSTANTS[V_1] =  0.0100000*CONSTANTS[V_o];
CONSTANTS[V_2] =  0.990000*CONSTANTS[V_o];
CONSTANTS[V_SR1] =  0.0100000*CONSTANTS[V_SR];
CONSTANTS[V_SR2] =  0.990000*CONSTANTS[V_SR];
}


void shorten_ocallaghan_davidson_soboleva_2007::computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC )
{
ALGEBRAIC[T_0] = CONSTANTS[T_tot]+- STATES[Ca_T_2]+- STATES[Ca_CaT2]+- STATES[D_0]+- STATES[D_1]+- STATES[D_2]+- STATES[A_1]+- STATES[A_2];
ALGEBRAIC[alpha_n] =  CONSTANTS[alpha_n_bar]*((STATES[vS] - CONSTANTS[V_n])/(1.00000 - exp(- ((STATES[vS] - CONSTANTS[V_n])/CONSTANTS[K_alpha_n]))));
ALGEBRAIC[beta_n] =  CONSTANTS[beta_n_bar]*exp(- ((STATES[vS] - CONSTANTS[V_n])/CONSTANTS[K_beta_n]));
ALGEBRAIC[h_K_inf] = 1.00000/(1.00000+exp((STATES[vS] - CONSTANTS[V_h_K_inf])/CONSTANTS[A_h_K_inf]));
ALGEBRAIC[tau_h_K] =  1000.00*exp(- ((STATES[vS]+40.0000)/25.7500));
ALGEBRAIC[alpha_m] =  CONSTANTS[alpha_m_bar]*((STATES[vS] - CONSTANTS[V_m])/(1.00000 - exp(- ((STATES[vS] - CONSTANTS[V_m])/CONSTANTS[K_alpha_m]))));
ALGEBRAIC[beta_m] =  CONSTANTS[beta_m_bar]*exp(- ((STATES[vS] - CONSTANTS[V_m])/CONSTANTS[K_beta_m]));
ALGEBRAIC[alpha_h] =  CONSTANTS[alpha_h_bar]*exp(- ((STATES[vS] - CONSTANTS[V_h])/CONSTANTS[K_alpha_h]));
ALGEBRAIC[beta_h] = CONSTANTS[beta_h_bar]/(1.00000+exp(- ((STATES[vS] - CONSTANTS[V_h])/CONSTANTS[K_beta_h])));
ALGEBRAIC[S_inf] = 1.00000/(1.00000+exp((STATES[vS] - CONSTANTS[V_S_inf])/CONSTANTS[A_S_inf]));
ALGEBRAIC[tau_S] = 8571.00/(0.200000+ 5.65000*pow((STATES[vS]+CONSTANTS[V_tau])/100.000, 2.00000));
ALGEBRAIC[alpha_n_t] =  CONSTANTS[alpha_n_bar]*((STATES[vT] - CONSTANTS[V_n])/(1.00000 - exp(- ((STATES[vT] - CONSTANTS[V_n])/CONSTANTS[K_alpha_n]))));
ALGEBRAIC[beta_n_t] =  CONSTANTS[beta_n_bar]*exp(- ((STATES[vT] - CONSTANTS[V_n])/CONSTANTS[K_beta_n]));
ALGEBRAIC[h_K_inf_t] = 1.00000/(1.00000+exp((STATES[vT] - CONSTANTS[V_h_K_inf])/CONSTANTS[A_h_K_inf]));
ALGEBRAIC[tau_h_K_t] =  1.00000*exp(- ((STATES[vT]+40.0000)/25.7500));
ALGEBRAIC[alpha_m_t] =  CONSTANTS[alpha_m_bar]*((STATES[vT] - CONSTANTS[V_m])/(1.00000 - exp(- ((STATES[vT] - CONSTANTS[V_m])/CONSTANTS[K_alpha_m]))));
ALGEBRAIC[beta_m_t] =  CONSTANTS[beta_m_bar]*exp(- ((STATES[vT] - CONSTANTS[V_m])/CONSTANTS[K_beta_m]));
ALGEBRAIC[alpha_h_t] =  CONSTANTS[alpha_h_bar]*exp(- ((STATES[vT] - CONSTANTS[V_h])/CONSTANTS[K_alpha_h]));
ALGEBRAIC[beta_h_t] = CONSTANTS[beta_h_bar]/(1.00000+exp(- ((STATES[vT] - CONSTANTS[V_h])/CONSTANTS[K_beta_h])));
ALGEBRAIC[S_inf_t] = 1.00000/(1.00000+exp((STATES[vT] - CONSTANTS[V_S_inf])/CONSTANTS[A_S_inf]));
ALGEBRAIC[tau_S_t] = 8571.00/(0.200000+ 5.65000*pow((STATES[vT]+CONSTANTS[V_tau])/100.000, 2.00000));
ALGEBRAIC[k_C] =  0.500000*CONSTANTS[alpha1]*exp((STATES[vT] - CONSTANTS[Vbar])/( 8.00000*CONSTANTS[K]));
ALGEBRAIC[k_Cm] =  0.500000*CONSTANTS[alpha1]*exp((CONSTANTS[Vbar] - STATES[vT])/( 8.00000*CONSTANTS[K]));
ALGEBRAIC[J_K] =  STATES[vS]*((STATES[K_i] -  STATES[K_e]*exp(( -1.00000*CONSTANTS[FF]*STATES[vS])/( CONSTANTS[RR]*CONSTANTS[TT])))/(1.00000 - exp(( -1.00000*CONSTANTS[FF]*STATES[vS])/( CONSTANTS[RR]*CONSTANTS[TT]))));
ALGEBRAIC[E_K] =  (( CONSTANTS[RR]*CONSTANTS[TT])/CONSTANTS[FF])*log(STATES[K_e]/STATES[K_i]);
ALGEBRAIC[K_R] =  STATES[K_e]*exp( ( - CONSTANTS[del]*ALGEBRAIC[E_K])*(CONSTANTS[FF]/( CONSTANTS[RR]*CONSTANTS[TT])));
ALGEBRAIC[g_IR_bar] =  CONSTANTS[G_K]*(pow(ALGEBRAIC[K_R], 2.00000)/(CONSTANTS[K_K]+pow(ALGEBRAIC[K_R], 2.00000)));
ALGEBRAIC[y] = 1.00000 - pow(1.00000+( CONSTANTS[K_S]*(1.00000+pow(ALGEBRAIC[K_R], 2.00000)/CONSTANTS[K_K]))/( pow(CONSTANTS[S_i], 2.00000)*exp(( 2.00000*(1.00000 - CONSTANTS[del])*STATES[vS]*CONSTANTS[FF])/( CONSTANTS[RR]*CONSTANTS[TT]))), -1.00000);
ALGEBRAIC[g_IR] =  ALGEBRAIC[g_IR_bar]*ALGEBRAIC[y];
ALGEBRAIC[I_IR] =  ALGEBRAIC[g_IR]*(ALGEBRAIC[J_K]>0.00000 ? 1.00000 : 0.00000)*(ALGEBRAIC[J_K]/50.0000);
ALGEBRAIC[g_DR] =  ( CONSTANTS[g_K_bar]*pow(STATES[n], 4.00000))*STATES[h_K];
ALGEBRAIC[I_DR] =  ALGEBRAIC[g_DR]*(ALGEBRAIC[J_K]/50.0000);
ALGEBRAIC[sig] =  (1.00000/7.00000)*(exp(STATES[Na_e]/67.3000) - 1.00000);
ALGEBRAIC[f1] = pow(1.00000+ 0.120000*exp( -0.100000*STATES[vS]*(CONSTANTS[FF]/( CONSTANTS[RR]*CONSTANTS[TT])))+ 0.0400000*ALGEBRAIC[sig]*exp(- ( STATES[vS]*(CONSTANTS[FF]/( CONSTANTS[RR]*CONSTANTS[TT])))), -1.00000);
ALGEBRAIC[I_NaK_bar] =  CONSTANTS[FF]*(CONSTANTS[J_NaK_bar]/( pow(1.00000+CONSTANTS[K_m_K]/STATES[K_e], 2.00000)*pow(1.00000+CONSTANTS[K_m_Na]/STATES[Na_i], 3.00000)));
ALGEBRAIC[I_NaK] =  ALGEBRAIC[I_NaK_bar]*ALGEBRAIC[f1];
ALGEBRAIC[g_Na] =  ( ( CONSTANTS[g_Na_bar]*pow(STATES[m], 3.00000))*STATES[h])*STATES[S];
ALGEBRAIC[J_Na] =  STATES[vS]*((STATES[Na_i] -  STATES[Na_e]*exp(( -1.00000*CONSTANTS[FF]*STATES[vS])/( CONSTANTS[RR]*CONSTANTS[TT])))/(1.00000 - exp(( -1.00000*CONSTANTS[FF]*STATES[vS])/( CONSTANTS[RR]*CONSTANTS[TT]))));
ALGEBRAIC[I_Na] =  ALGEBRAIC[g_Na]*(ALGEBRAIC[J_Na]/75.0000);
ALGEBRAIC[I_T] =  (1000.00/1.00000)*((STATES[vS] - STATES[vT])/CONSTANTS[R_a]);
ALGEBRAIC[Cl_i] = 156.500/(5.00000+exp(( - CONSTANTS[FF]*ALGEBRAIC[E_K])/( CONSTANTS[RR]*CONSTANTS[TT])));
ALGEBRAIC[Cl_o] = 156.500 -  5.00000*ALGEBRAIC[Cl_i];
ALGEBRAIC[J_Cl] =  STATES[vS]*((ALGEBRAIC[Cl_i] -  ALGEBRAIC[Cl_o]*exp(( CONSTANTS[FF]*STATES[vS])/( CONSTANTS[RR]*CONSTANTS[TT])))/(1.00000 - exp(( CONSTANTS[FF]*STATES[vS])/( CONSTANTS[RR]*CONSTANTS[TT]))));
ALGEBRAIC[a] = 1.00000/(1.00000+exp((STATES[vS] - CONSTANTS[V_a])/CONSTANTS[A_a]));
ALGEBRAIC[g_Cl] =  CONSTANTS[g_Cl_bar]*pow(ALGEBRAIC[a], 4.00000);
ALGEBRAIC[I_Cl] =  ALGEBRAIC[g_Cl]*(ALGEBRAIC[J_Cl]/45.0000);
ALGEBRAIC[I_HH] = (TIME>=0.00000&&TIME<0.500000 ? 150.000 : TIME>=50.0000&&TIME<50.5000 ? 150.000 : TIME>=100.000&&TIME<100.500 ? 150.000 : TIME>=150.000&&TIME<150.500 ? 150.000 : TIME>=200.000&&TIME<200.500 ? 150.000 : TIME>=250.000&&TIME<250.500 ? 150.000 : TIME>=300.000&&TIME<300.500 ? 150.000 : TIME>=350.000&&TIME<350.500 ? 150.000 : TIME>=400.000&&TIME<400.500 ? 150.000 : 0.00000);
ALGEBRAIC[I_ionic_s] = ALGEBRAIC[I_Cl]+ALGEBRAIC[I_IR]+ALGEBRAIC[I_DR]+ALGEBRAIC[I_Na]+ALGEBRAIC[I_NaK]+- ALGEBRAIC[I_HH];
ALGEBRAIC[J_K_t] =  STATES[vT]*((STATES[K_i] -  STATES[K_t]*exp(( -1.00000*CONSTANTS[FF]*STATES[vT])/( CONSTANTS[RR]*CONSTANTS[TT])))/(1.00000 - exp(( -1.00000*CONSTANTS[FF]*STATES[vT])/( CONSTANTS[RR]*CONSTANTS[TT]))));
ALGEBRAIC[E_K_t] =  (( CONSTANTS[RR]*CONSTANTS[TT])/CONSTANTS[FF])*log(STATES[K_t]/STATES[K_i]);
ALGEBRAIC[K_R_t] =  STATES[K_t]*exp( ( - CONSTANTS[del]*ALGEBRAIC[E_K_t])*(CONSTANTS[FF]/( CONSTANTS[RR]*CONSTANTS[TT])));
ALGEBRAIC[g_IR_bar_t] =  CONSTANTS[G_K]*(pow(ALGEBRAIC[K_R_t], 2.00000)/(CONSTANTS[K_K]+pow(ALGEBRAIC[K_R_t], 2.00000)));
ALGEBRAIC[y_t] = 1.00000 - pow(1.00000+( CONSTANTS[K_S]*(1.00000+pow(ALGEBRAIC[K_R_t], 2.00000)/CONSTANTS[K_K]))/( pow(CONSTANTS[S_i], 2.00000)*exp(( 2.00000*(1.00000 - CONSTANTS[del])*STATES[vT]*CONSTANTS[FF])/( CONSTANTS[RR]*CONSTANTS[TT]))), -1.00000);
ALGEBRAIC[g_IR_t] =  ALGEBRAIC[g_IR_bar_t]*ALGEBRAIC[y_t];
ALGEBRAIC[I_IR_t] =  CONSTANTS[eta_IR]*ALGEBRAIC[g_IR_t]*(ALGEBRAIC[J_K_t]/50.0000);
ALGEBRAIC[g_DR_t] =  ( CONSTANTS[g_K_bar]*pow(STATES[n_t], 4.00000))*STATES[h_K_t];
ALGEBRAIC[I_DR_t] =  CONSTANTS[eta_DR]*ALGEBRAIC[g_DR_t]*(ALGEBRAIC[J_K_t]/50.0000);
ALGEBRAIC[sig_t] =  (1.00000/7.00000)*(exp(STATES[Na_t]/67.3000) - 1.00000);
ALGEBRAIC[f1_t] = pow(1.00000+ 0.120000*exp( -0.100000*STATES[vT]*(CONSTANTS[FF]/( CONSTANTS[RR]*CONSTANTS[TT])))+ 0.0400000*ALGEBRAIC[sig_t]*exp(- ( STATES[vT]*(CONSTANTS[FF]/( CONSTANTS[RR]*CONSTANTS[TT])))), -1.00000);
ALGEBRAIC[I_NaK_bar_t] =  CONSTANTS[FF]*(CONSTANTS[J_NaK_bar]/( pow(1.00000+CONSTANTS[K_m_K]/STATES[K_t], 2.00000)*pow(1.00000+CONSTANTS[K_m_Na]/STATES[Na_i], 3.00000)));
ALGEBRAIC[I_NaK_t] =  CONSTANTS[eta_NaK]*ALGEBRAIC[I_NaK_bar_t]*ALGEBRAIC[f1_t];
ALGEBRAIC[g_Na_t] =  ( ( CONSTANTS[g_Na_bar]*pow(STATES[m_t], 3.00000))*STATES[h_t])*STATES[S_t];
ALGEBRAIC[J_Na_t] =  STATES[vT]*((STATES[Na_i] -  STATES[Na_t]*exp(( -1.00000*CONSTANTS[FF]*STATES[vT])/( CONSTANTS[RR]*CONSTANTS[TT])))/(1.00000 - exp(( -1.00000*CONSTANTS[FF]*STATES[vT])/( CONSTANTS[RR]*CONSTANTS[TT]))));
ALGEBRAIC[I_Na_t] =  CONSTANTS[eta_Na]*ALGEBRAIC[g_Na_t]*(ALGEBRAIC[J_Na_t]/75.0000);
ALGEBRAIC[Cl_i_t] = 156.500/(5.00000+exp(( - CONSTANTS[FF]*ALGEBRAIC[E_K_t])/( CONSTANTS[RR]*CONSTANTS[TT])));
ALGEBRAIC[Cl_o_t] = 156.500 -  5.00000*ALGEBRAIC[Cl_i_t];
ALGEBRAIC[J_Cl_t] =  STATES[vT]*((ALGEBRAIC[Cl_i_t] -  ALGEBRAIC[Cl_o_t]*exp(( CONSTANTS[FF]*STATES[vT])/( CONSTANTS[RR]*CONSTANTS[TT])))/(1.00000 - exp(( CONSTANTS[FF]*STATES[vT])/( CONSTANTS[RR]*CONSTANTS[TT]))));
ALGEBRAIC[a_t] = 1.00000/(1.00000+exp((STATES[vT] - CONSTANTS[V_a])/CONSTANTS[A_a]));
ALGEBRAIC[g_Cl_t] =  CONSTANTS[g_Cl_bar]*pow(ALGEBRAIC[a_t], 4.00000);
ALGEBRAIC[I_Cl_t] =  CONSTANTS[eta_Cl]*ALGEBRAIC[g_Cl_t]*(ALGEBRAIC[J_Cl_t]/45.0000);
ALGEBRAIC[I_ionic_t] = ALGEBRAIC[I_Cl_t]+ALGEBRAIC[I_IR_t]+ALGEBRAIC[I_DR_t]+ALGEBRAIC[I_Na_t]+ALGEBRAIC[I_NaK_t];

RATES[Ca_1] = (((( ( CONSTANTS[i2]*(STATES[O_0]+STATES[O_1]+STATES[O_2]+STATES[O_3]+STATES[O_4]))*((STATES[Ca_SR1] - STATES[Ca_1])/CONSTANTS[V_1]) -  CONSTANTS[nu_SR]*((STATES[Ca_1]/(STATES[Ca_1]+CONSTANTS[K_SR]))/CONSTANTS[V_1]))+ CONSTANTS[L_e]*((STATES[Ca_SR1] - STATES[Ca_1])/CONSTANTS[V_1]))+ - CONSTANTS[tau_R]*((STATES[Ca_1] - STATES[Ca_2])/CONSTANTS[V_1]))+- ( ( CONSTANTS[k_P_on]*STATES[Ca_1])*((CONSTANTS[P_tot]+- STATES[Ca_P1])+- STATES[Mg_P1])+ - CONSTANTS[k_P_off]*STATES[Ca_P1]))+- ( ( CONSTANTS[k_CATP_on]*STATES[Ca_1])*STATES[ATP1]+ - CONSTANTS[k_CATP_off]*STATES[Ca_ATP1]);
RATES[Ca_SR1] = ((( - ( CONSTANTS[i2]*(STATES[O_0]+STATES[O_1]+STATES[O_2]+STATES[O_3]+STATES[O_4]))*((STATES[Ca_SR1] - STATES[Ca_1])/CONSTANTS[V_SR1])+ CONSTANTS[nu_SR]*((STATES[Ca_1]/(STATES[Ca_1]+CONSTANTS[K_SR]))/CONSTANTS[V_SR1]))+ - CONSTANTS[L_e]*((STATES[Ca_SR1] - STATES[Ca_1])/CONSTANTS[V_SR1]))+ - CONSTANTS[tau_SR_R]*((STATES[Ca_SR1] - STATES[Ca_SR2])/CONSTANTS[V_SR1]))+- ( ( CONSTANTS[k_Cs_on]*STATES[Ca_SR1])*(CONSTANTS[Cs_tot] - STATES[Ca_Cs1])+ - CONSTANTS[k_Cs_off]*STATES[Ca_Cs1]);
RATES[Ca_SR2] = ((( CONSTANTS[nu_SR]*((STATES[Ca_2]/(STATES[Ca_2]+CONSTANTS[K_SR]))/CONSTANTS[V_SR2])+ - CONSTANTS[L_e]*((STATES[Ca_SR2]+- STATES[Ca_2])/CONSTANTS[V_SR2]))+ CONSTANTS[tau_SR_R]*((STATES[Ca_SR1]+- STATES[Ca_SR2])/CONSTANTS[V_SR2]))+- ( ( CONSTANTS[k_Cs_on]*STATES[Ca_SR2])*(CONSTANTS[Cs_tot]+- STATES[Ca_Cs2])+ - CONSTANTS[k_Cs_off]*STATES[Ca_Cs2])) -  (1000.00/1.00000)*( CONSTANTS[A_p]*( STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2] - CONSTANTS[PP])*( STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2] - CONSTANTS[PP]>0.00000 ? 1.00000 : 0.00000)*(0.00100000/1.00000)*STATES[P_SR]*STATES[Ca_SR2] -  CONSTANTS[B_p]*STATES[P_C_SR]*(CONSTANTS[PP] -  STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2])*(CONSTANTS[PP] -  STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2]>0.00000 ? 1.00000 : 0.00000));
RATES[Ca_P1] =  ( CONSTANTS[k_P_on]*STATES[Ca_1])*((CONSTANTS[P_tot]+- STATES[Ca_P1])+- STATES[Mg_P1])+ - CONSTANTS[k_P_off]*STATES[Ca_P1];
RATES[Ca_P2] =  ( CONSTANTS[k_P_on]*STATES[Ca_2])*((CONSTANTS[P_tot]+- STATES[Ca_P2])+- STATES[Mg_P2])+ - CONSTANTS[k_P_off]*STATES[Ca_P2];
RATES[Mg_P1] =  ( CONSTANTS[k_Mg_on]*(CONSTANTS[P_tot]+- STATES[Ca_P1]+- STATES[Mg_P1]))*STATES[Mg1]+ - CONSTANTS[k_Mg_off]*STATES[Mg_P1];
RATES[Mg_P2] =  ( CONSTANTS[k_Mg_on]*(CONSTANTS[P_tot]+- STATES[Ca_P2]+- STATES[Mg_P2]))*STATES[Mg2]+ - CONSTANTS[k_Mg_off]*STATES[Mg_P2];
RATES[Ca_Cs1] =  ( CONSTANTS[k_Cs_on]*STATES[Ca_SR1])*(CONSTANTS[Cs_tot]+- STATES[Ca_Cs1])+ - CONSTANTS[k_Cs_off]*STATES[Ca_Cs1];
RATES[Ca_Cs2] =  ( CONSTANTS[k_Cs_on]*STATES[Ca_SR2])*(CONSTANTS[Cs_tot]+- STATES[Ca_Cs2])+ - CONSTANTS[k_Cs_off]*STATES[Ca_Cs2];
RATES[Ca_ATP1] = ( ( CONSTANTS[k_CATP_on]*STATES[Ca_1])*STATES[ATP1]+ - CONSTANTS[k_CATP_off]*STATES[Ca_ATP1])+ - CONSTANTS[tau_ATP]*((STATES[Ca_ATP1]+- STATES[Ca_ATP2])/CONSTANTS[V_1]);
RATES[Ca_ATP2] = ( ( CONSTANTS[k_CATP_on]*STATES[Ca_2])*STATES[ATP2]+ - CONSTANTS[k_CATP_off]*STATES[Ca_ATP2])+ CONSTANTS[tau_ATP]*((STATES[Ca_ATP1]+- STATES[Ca_ATP2])/CONSTANTS[V_2]);
RATES[Mg_ATP1] = ( ( CONSTANTS[k_MATP_on]*STATES[Mg1])*STATES[ATP1]+ - CONSTANTS[k_MATP_off]*STATES[Mg_ATP1])+ - CONSTANTS[tau_ATP]*((STATES[Mg_ATP1]+- STATES[Mg_ATP2])/CONSTANTS[V_1]);
RATES[Mg_ATP2] = ( ( CONSTANTS[k_MATP_on]*STATES[Mg2])*STATES[ATP2]+ - CONSTANTS[k_MATP_off]*STATES[Mg_ATP2])+ CONSTANTS[tau_ATP]*((STATES[Mg_ATP1]+- STATES[Mg_ATP2])/CONSTANTS[V_2]);
RATES[ATP1] = (- ( ( CONSTANTS[k_CATP_on]*STATES[Ca_1])*STATES[ATP1]+ - CONSTANTS[k_CATP_off]*STATES[Ca_ATP1])+- ( ( CONSTANTS[k_MATP_on]*STATES[Mg1])*STATES[ATP1]+ - CONSTANTS[k_MATP_off]*STATES[Mg_ATP1]))+ - CONSTANTS[tau_ATP]*((STATES[ATP1]+- STATES[ATP2])/CONSTANTS[V_1]);
RATES[ATP2] = (- ( ( CONSTANTS[k_CATP_on]*STATES[Ca_2])*STATES[ATP2]+ - CONSTANTS[k_CATP_off]*STATES[Ca_ATP2])+- ( ( CONSTANTS[k_MATP_on]*STATES[Mg2])*STATES[ATP2]+ - CONSTANTS[k_MATP_off]*STATES[Mg_ATP2]))+ CONSTANTS[tau_ATP]*((STATES[ATP1]+- STATES[ATP2])/CONSTANTS[V_2]);
RATES[Mg1] = (- ( ( CONSTANTS[k_Mg_on]*(CONSTANTS[P_tot]+- STATES[Ca_P1]+- STATES[Mg_P1]))*STATES[Mg1]+ - CONSTANTS[k_Mg_off]*STATES[Mg_P1])+- ( ( CONSTANTS[k_MATP_on]*STATES[Mg1])*STATES[ATP1]+ - CONSTANTS[k_MATP_off]*STATES[Mg_ATP1]))+ - CONSTANTS[tau_Mg]*((STATES[Mg1]+- STATES[Mg2])/CONSTANTS[V_1]);
RATES[Mg2] = (- ( ( CONSTANTS[k_Mg_on]*(CONSTANTS[P_tot]+- STATES[Ca_P2]+- STATES[Mg_P2]))*STATES[Mg2]+ - CONSTANTS[k_Mg_off]*STATES[Mg_P2])+- ( ( CONSTANTS[k_MATP_on]*STATES[Mg2])*STATES[ATP2]+ - CONSTANTS[k_MATP_off]*STATES[Mg_ATP2]))+ CONSTANTS[tau_Mg]*((STATES[Mg1]+- STATES[Mg2])/CONSTANTS[V_2]);
RATES[Ca_CaT2] = (( ( CONSTANTS[k_T_on]*STATES[Ca_2])*STATES[Ca_T_2]+ - CONSTANTS[k_T_off]*STATES[Ca_CaT2])+ - CONSTANTS[k_Ca_on]*STATES[Ca_CaT2])+ CONSTANTS[k_Ca_off]*STATES[D_2];
RATES[D_1] = (((( CONSTANTS[k_T_on]*STATES[Ca_2]*STATES[D_0]+ - CONSTANTS[k_T_off]*STATES[D_1])+ CONSTANTS[k_0_on]*STATES[Ca_T_2])+ - CONSTANTS[k_0_off]*STATES[D_1])+ ( - CONSTANTS[k_T_on]*STATES[Ca_2])*STATES[D_1])+ CONSTANTS[k_T_off]*STATES[D_2];
RATES[D_2] = ((((( CONSTANTS[k_T_on]*STATES[Ca_2]*STATES[D_1]+ - CONSTANTS[k_T_off]*STATES[D_2])+ CONSTANTS[k_Ca_on]*STATES[Ca_CaT2])+ - CONSTANTS[k_Ca_off]*STATES[D_2])+ - CONSTANTS[f_o]*STATES[D_2])+ CONSTANTS[f_p]*STATES[A_1])+ CONSTANTS[g_o]*STATES[A_2];
RATES[A_1] = (( CONSTANTS[f_o]*STATES[D_2]+ - CONSTANTS[f_p]*STATES[A_1])+ CONSTANTS[h_p]*STATES[A_2])+ - CONSTANTS[h_o]*STATES[A_1];
RATES[A_2] = ( - CONSTANTS[h_p]*STATES[A_2]+ CONSTANTS[h_o]*STATES[A_1])+ - CONSTANTS[g_o]*STATES[A_2];
RATES[P] =  (0.00100000/1.00000)*( CONSTANTS[h_o]*STATES[A_1] -  CONSTANTS[h_p]*STATES[A_2])+ -1.00000*CONSTANTS[b_p]*STATES[P]+ -1.00000*CONSTANTS[k_p]*((STATES[P] - STATES[P_SR])/CONSTANTS[V_2]);
RATES[P_SR] =  CONSTANTS[k_p]*((STATES[P] - STATES[P_SR])/CONSTANTS[V_SR2]) -  1.00000*( CONSTANTS[A_p]*( STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2] - CONSTANTS[PP])*( STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2] - CONSTANTS[PP]>0.00000 ? 1.00000 : 0.00000)*(0.00100000/1.00000)*STATES[P_SR]*STATES[Ca_SR2] -  CONSTANTS[B_p]*STATES[P_C_SR]*(CONSTANTS[PP] -  STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2])*(CONSTANTS[PP] -  STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2]>0.00000 ? 1.00000 : 0.00000));
RATES[P_C_SR] =  1.00000*( CONSTANTS[A_p]*( STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2] - CONSTANTS[PP])*( STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2] - CONSTANTS[PP]>0.00000 ? 1.00000 : 0.00000)*(0.00100000/1.00000)*STATES[P_SR]*STATES[Ca_SR2] -  CONSTANTS[B_p]*STATES[P_C_SR]*(CONSTANTS[PP] -  STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2])*(CONSTANTS[PP] -  STATES[P_SR]*(0.00100000/1.00000)*STATES[Ca_SR2]>0.00000 ? 1.00000 : 0.00000));
RATES[Ca_2] = (((( - CONSTANTS[nu_SR]*((STATES[Ca_2]/(STATES[Ca_2]+CONSTANTS[K_SR]))/CONSTANTS[V_2])+ CONSTANTS[L_e]*((STATES[Ca_SR2]+- STATES[Ca_2])/CONSTANTS[V_2]))+ CONSTANTS[tau_R]*((STATES[Ca_1] - STATES[Ca_2])/CONSTANTS[V_2]))+- ((((((( CONSTANTS[k_T_on]*STATES[Ca_2]*ALGEBRAIC[T_0]+ - CONSTANTS[k_T_off]*STATES[Ca_T_2])+ CONSTANTS[k_T_on]*STATES[Ca_2]*STATES[Ca_T_2])+ - CONSTANTS[k_T_off]*STATES[Ca_CaT2])+ CONSTANTS[k_T_on]*STATES[Ca_2]*STATES[D_0])+ - CONSTANTS[k_T_off]*STATES[D_1])+ CONSTANTS[k_T_on]*STATES[Ca_2]*STATES[D_1])+ - CONSTANTS[k_T_off]*STATES[D_2]))+- ( ( CONSTANTS[k_P_on]*STATES[Ca_2])*(CONSTANTS[P_tot]+- STATES[Ca_P2]+- STATES[Mg_P2])+ - CONSTANTS[k_P_off]*STATES[Ca_P2]))+- ( ( CONSTANTS[k_CATP_on]*STATES[Ca_2])*STATES[ATP2]+ - CONSTANTS[k_CATP_off]*STATES[Ca_ATP2]);
RATES[Ca_T_2] = (((( ( CONSTANTS[k_T_on]*STATES[Ca_2])*ALGEBRAIC[T_0]+ - CONSTANTS[k_T_off]*STATES[Ca_T_2])+ ( - CONSTANTS[k_T_on]*STATES[Ca_2])*STATES[Ca_T_2])+ CONSTANTS[k_T_off]*STATES[Ca_CaT2])+ - CONSTANTS[k_0_on]*STATES[Ca_T_2])+ CONSTANTS[k_0_off]*STATES[D_1];
RATES[D_0] = (( ( - CONSTANTS[k_T_on]*STATES[Ca_2])*STATES[D_0]+ CONSTANTS[k_T_off]*STATES[D_1])+ CONSTANTS[k_0_on]*ALGEBRAIC[T_0])+ - CONSTANTS[k_0_off]*STATES[D_0];
RATES[n] =  ALGEBRAIC[alpha_n]*(1.00000 - STATES[n]) -  ALGEBRAIC[beta_n]*STATES[n];
RATES[h_K] = (ALGEBRAIC[h_K_inf] - STATES[h_K])/ALGEBRAIC[tau_h_K];
RATES[m] =  ALGEBRAIC[alpha_m]*(1.00000 - STATES[m]) -  ALGEBRAIC[beta_m]*STATES[m];
RATES[h] =  ALGEBRAIC[alpha_h]*(1.00000 - STATES[h]) -  ALGEBRAIC[beta_h]*STATES[h];
RATES[S] = (ALGEBRAIC[S_inf] - STATES[S])/ALGEBRAIC[tau_S];
RATES[n_t] =  ALGEBRAIC[alpha_n_t]*(1.00000 - STATES[n_t]) -  ALGEBRAIC[beta_n_t]*STATES[n_t];
RATES[h_K_t] = (ALGEBRAIC[h_K_inf_t] - STATES[h_K_t])/ALGEBRAIC[tau_h_K_t];
RATES[m_t] =  ALGEBRAIC[alpha_m_t]*(1.00000 - STATES[m_t]) -  ALGEBRAIC[beta_m_t]*STATES[m_t];
RATES[h_t] =  ALGEBRAIC[alpha_h_t]*(1.00000 - STATES[h_t]) -  ALGEBRAIC[beta_h_t]*STATES[h_t];
RATES[S_t] = (ALGEBRAIC[S_inf_t] - STATES[S_t])/ALGEBRAIC[tau_S_t];
RATES[C_0] =  - CONSTANTS[k_L]*STATES[C_0]+ CONSTANTS[k_Lm]*STATES[O_0]+ -4.00000*ALGEBRAIC[k_C]*STATES[C_0]+ ALGEBRAIC[k_Cm]*STATES[C_1];
RATES[O_0] =  CONSTANTS[k_L]*STATES[C_0]+ - CONSTANTS[k_Lm]*STATES[O_0]+( -4.00000*ALGEBRAIC[k_C]*STATES[O_0])/CONSTANTS[f]+ CONSTANTS[f]*ALGEBRAIC[k_Cm]*STATES[O_1];
RATES[C_1] =  4.00000*ALGEBRAIC[k_C]*STATES[C_0]+ - ALGEBRAIC[k_Cm]*STATES[C_1]+( - CONSTANTS[k_L]*STATES[C_1])/CONSTANTS[f]+ CONSTANTS[f]*CONSTANTS[k_Lm]*STATES[O_1]+ -3.00000*ALGEBRAIC[k_C]*STATES[C_1]+ 2.00000*ALGEBRAIC[k_Cm]*STATES[C_2];
RATES[O_1] = ( CONSTANTS[k_L]*STATES[C_1])/CONSTANTS[f]+ - CONSTANTS[k_Lm]*CONSTANTS[f]*STATES[O_1]+( 4.00000*ALGEBRAIC[k_C]*STATES[O_0])/CONSTANTS[f]+ - CONSTANTS[f]*ALGEBRAIC[k_Cm]*STATES[O_1]+( -3.00000*ALGEBRAIC[k_C]*STATES[O_1])/CONSTANTS[f]+ 2.00000*CONSTANTS[f]*ALGEBRAIC[k_Cm]*STATES[O_2];
RATES[C_2] =  3.00000*ALGEBRAIC[k_C]*STATES[C_1]+ -2.00000*ALGEBRAIC[k_Cm]*STATES[C_2]+( - CONSTANTS[k_L]*STATES[C_2])/pow(CONSTANTS[f], 2.00000)+ pow(CONSTANTS[f], 2.00000)*CONSTANTS[k_Lm]*STATES[O_2]+ -2.00000*ALGEBRAIC[k_C]*STATES[C_2]+ 3.00000*ALGEBRAIC[k_Cm]*STATES[C_3];
RATES[O_2] = ( 3.00000*ALGEBRAIC[k_C]*STATES[O_1])/CONSTANTS[f]+ -2.00000*CONSTANTS[f]*ALGEBRAIC[k_Cm]*STATES[O_2]+( CONSTANTS[k_L]*STATES[C_2])/pow(CONSTANTS[f], 2.00000)+ - CONSTANTS[k_Lm]*pow(CONSTANTS[f], 2.00000)*STATES[O_2]+( -2.00000*ALGEBRAIC[k_C]*STATES[O_2])/CONSTANTS[f]+ 3.00000*CONSTANTS[f]*ALGEBRAIC[k_Cm]*STATES[O_3];
RATES[C_3] =  2.00000*ALGEBRAIC[k_C]*STATES[C_2]+ -3.00000*ALGEBRAIC[k_Cm]*STATES[C_3]+( - CONSTANTS[k_L]*STATES[C_3])/pow(CONSTANTS[f], 3.00000)+ CONSTANTS[k_Lm]*pow(CONSTANTS[f], 3.00000)*STATES[O_3]+ - ALGEBRAIC[k_C]*STATES[C_3]+ 4.00000*ALGEBRAIC[k_Cm]*STATES[C_4];
RATES[O_3] = ( CONSTANTS[k_L]*STATES[C_3])/pow(CONSTANTS[f], 3.00000)+ - CONSTANTS[k_Lm]*pow(CONSTANTS[f], 3.00000)*STATES[O_3]+( 2.00000*ALGEBRAIC[k_C]*STATES[O_2])/CONSTANTS[f]+ -3.00000*ALGEBRAIC[k_Cm]*CONSTANTS[f]*STATES[O_3]+( - ALGEBRAIC[k_C]*STATES[O_3])/CONSTANTS[f]+ 4.00000*CONSTANTS[f]*ALGEBRAIC[k_Cm]*STATES[O_4];
RATES[C_4] =  ALGEBRAIC[k_C]*STATES[C_3]+ -4.00000*ALGEBRAIC[k_Cm]*STATES[C_4]+( - CONSTANTS[k_L]*STATES[C_4])/pow(CONSTANTS[f], 4.00000)+ CONSTANTS[k_Lm]*pow(CONSTANTS[f], 4.00000)*STATES[O_4];
RATES[O_4] = ( ALGEBRAIC[k_C]*STATES[O_3])/CONSTANTS[f]+ -4.00000*CONSTANTS[f]*ALGEBRAIC[k_Cm]*STATES[O_4]+( CONSTANTS[k_L]*STATES[C_4])/pow(CONSTANTS[f], 4.00000)+ - CONSTANTS[k_Lm]*pow(CONSTANTS[f], 4.00000)*STATES[O_4];
RATES[K_e] = (ALGEBRAIC[I_IR]+ALGEBRAIC[I_DR]+CONSTANTS[I_K_rest]+ - 2.00000*ALGEBRAIC[I_NaK])/( (1000.00/1.00000)*CONSTANTS[FF]*CONSTANTS[tsi3])+(STATES[K_t] - STATES[K_e])/CONSTANTS[tau_K2];
RATES[Na_e] = (ALGEBRAIC[I_Na]+CONSTANTS[I_Na_rest]+ 3.00000*ALGEBRAIC[I_NaK])/( (1000.00/1.00000)*CONSTANTS[FF]*CONSTANTS[tsi3])+(STATES[Na_t] - STATES[Na_e])/CONSTANTS[tau_Na2];
RATES[vS] = - ((ALGEBRAIC[I_ionic_s]+ALGEBRAIC[I_T])/CONSTANTS[C_m]);
RATES[K_i] =  - CONSTANTS[f_T]*((ALGEBRAIC[I_IR_t]+ALGEBRAIC[I_DR_t]+CONSTANTS[I_K_rest]+ - 2.00000*ALGEBRAIC[I_NaK_t])/( (1000.00/1.00000)*CONSTANTS[FF]*CONSTANTS[tsi])) - (ALGEBRAIC[I_IR]+ALGEBRAIC[I_DR]+CONSTANTS[I_K_rest]+ -2.00000*ALGEBRAIC[I_NaK])/( (1000.00/1.00000)*CONSTANTS[FF]*CONSTANTS[tsi2]);
RATES[K_t] = (ALGEBRAIC[I_IR_t]+ALGEBRAIC[I_DR_t]+CONSTANTS[I_K_rest]+ - 2.00000*ALGEBRAIC[I_NaK_t])/( (1000.00/1.00000)*CONSTANTS[FF]*CONSTANTS[tsi]) - (STATES[K_t] - STATES[K_e])/CONSTANTS[tau_K];
RATES[Na_i] =  - CONSTANTS[f_T]*((ALGEBRAIC[I_Na_t]+CONSTANTS[I_Na_rest]+ 3.00000*ALGEBRAIC[I_NaK_t])/( (1000.00/1.00000)*CONSTANTS[FF]*CONSTANTS[tsi])) - (ALGEBRAIC[I_Na]+CONSTANTS[I_Na_rest]+ 3.00000*ALGEBRAIC[I_NaK])/( (1000.00/1.00000)*CONSTANTS[FF]*CONSTANTS[tsi2]);
RATES[Na_t] = (ALGEBRAIC[I_Na_t]+CONSTANTS[I_Na_rest]+ 3.00000*ALGEBRAIC[I_NaK_t])/( (1000.00/1.00000)*CONSTANTS[FF]*CONSTANTS[tsi]) - (STATES[Na_t] - STATES[Na_e])/CONSTANTS[tau_Na];
RATES[vT] = - ((ALGEBRAIC[I_ionic_t] - ALGEBRAIC[I_T]/CONSTANTS[gam])/CONSTANTS[C_m]);
}

void shorten_ocallaghan_davidson_soboleva_2007::solveAnalytical(double dt)
{
}
