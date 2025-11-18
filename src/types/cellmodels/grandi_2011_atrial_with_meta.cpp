/*
   There are a total of 120 entries in the algebraic variable array.
   There are a total of 41 entries in each of the rate and state variable arrays.
   There are a total of 137 entries in the constant variable array.
 */

#include "grandi_2011_atrial_with_meta.hpp"
#include <cmath>
#include <cstdlib>
#include "../../functions/inputoutput.hpp"
#include "../../types/cml_consts.hpp"

/*
 * CONSTANTS[Bmax_CaM] is Bmax_CaM in component buffca (mM).
 * CONSTANTS[Bmax_SLhighj] is Bmax_SLhighj in component buffca (mM).
 * CONSTANTS[Bmax_SLhighsl] is Bmax_SLhighsl in component buffca (mM).
 * CONSTANTS[Bmax_SLlowj] is Bmax_SLlowj in component buffca (mM).
 * CONSTANTS[Bmax_SLlowsl] is Bmax_SLlowsl in component buffca (mM).
 * CONSTANTS[Bmax_SR] is Bmax_SR in component buffca (mM).
 * CONSTANTS[Bmax_TnChigh] is Bmax_TnChigh in component buffca (mM).
 * CONSTANTS[Bmax_TnClow] is Bmax_TnClow in component buffca (mM).
 * CONSTANTS[Bmax_myosin] is Bmax_myosin in component buffca (mM).
 * STATES[CaM] is CaM in component buffca (mM).
 * ALGEBRAIC[J_CaB_cytosol] is J_CaB_cytosol in component buffca (mM_per_ms).
 * ALGEBRAIC[J_CaB_jntion] is J_CaB_jntion in component buffca (mM_per_ms).
 * ALGEBRAIC[J_CaB_sl] is J_CaB_sl in component buffca (mM_per_ms).
 * STATES[Myoc] is Myoc in component buffca (mM).
 * STATES[Myom] is Myom in component buffca (mM).
 * STATES[SLH_jn] is SLH_jn in component buffca (mM).
 * STATES[SLH_sl] is SLH_sl in component buffca (mM).
 * STATES[SLL_jn] is SLL_jn in component buffca (mM).
 * STATES[SLL_sl] is SLL_sl in component buffca (mM).
 * STATES[SRB] is SRB in component buffca (mM).
 * STATES[TnCHc] is TnCHc in component buffca (mM).
 * STATES[TnCHm] is TnCHm in component buffca (mM).
 * STATES[TnCL] is TnCL in component buffca (mM).
 * CONSTANTS[koff_cam] is koff_cam in component buffca (mS_per_uF).
 * CONSTANTS[koff_myoca] is koff_myoca in component buffca (mS_per_uF).
 * CONSTANTS[koff_myomg] is koff_myomg in component buffca (mS_per_uF).
 * CONSTANTS[koff_slh] is koff_slh in component buffca (mS_per_uF).
 * CONSTANTS[koff_sll] is koff_sll in component buffca (mS_per_uF).
 * CONSTANTS[koff_sr] is koff_sr in component buffca (mS_per_uF).
 * CONSTANTS[koff_tnchca] is koff_tnchca in component buffca (mS_per_uF).
 * CONSTANTS[koff_tnchmg] is koff_tnchmg in component buffca (mS_per_uF).
 * CONSTANTS[koff_tncl] is koff_tncl in component buffca (mS_per_uF).
 * CONSTANTS[kon_cam] is kon_cam in component buffca (per_mM_per_ms).
 * CONSTANTS[kon_myoca] is kon_myoca in component buffca (per_mM_per_ms).
 * CONSTANTS[kon_myomg] is kon_myomg in component buffca (per_mM_per_ms).
 * CONSTANTS[kon_slh] is kon_slh in component buffca (per_mM_per_ms).
 * CONSTANTS[kon_sll] is kon_sll in component buffca (per_mM_per_ms).
 * CONSTANTS[kon_sr] is kon_sr in component buffca (per_mM_per_ms).
 * CONSTANTS[kon_tnchca] is kon_tnchca in component buffca (per_mM_per_ms).
 * CONSTANTS[kon_tnchmg] is kon_tnchmg in component buffca (per_mM_per_ms).
 * CONSTANTS[kon_tncl] is kon_tncl in component buffca (per_mM_per_ms).
 * CONSTANTS[Vjn] is Vjn in component geom (liter).
 * CONSTANTS[Vmyo] is Vmyo in component geom (liter).
 * CONSTANTS[Vsl] is Vsl in component geom (liter).
 * STATES[cai] is Ca_i in component calcium (mM).
 * TIME is time in component engine (ms).
 * CONSTANTS[Mg_i] is Mg_i in component ion (mM).
 * STATES[Ca_jn] is Ca_jn in component calcium (mM).
 * STATES[Ca_sl] is Ca_sl in component calcium (mM).
 * CONSTANTS[ISO] is ISO in component cell (dimensionless).
 * CONSTANTS[Bmax_Na_jn] is Bmax_Na_jn in component buffna (mM).
 * CONSTANTS[Bmax_Na_sl] is Bmax_Na_sl in component buffna (mM).
 * STATES[NaB_jn] is NaB_jn in component buffna (mM).
 * STATES[NaB_sl] is NaB_sl in component buffna (mM).
 * CONSTANTS[koff_na] is koff_na in component buffna (mS_per_uF).
 * CONSTANTS[kon_na] is kon_na in component buffna (per_mM_per_ms).
 * STATES[Na_jn] is Na_jn in component sodium (mM).
 * STATES[Na_sl] is Na_sl in component sodium (mM).
 * STATES[Ca_sr] is Ca_sr in component calcium (mM).
 * STATES[Csqn] is Csqn in component calcium (mM).
 * ALGEBRAIC[ICa_tot_jn] is ICa_tot_jn in component calcium (A_per_F).
 * ALGEBRAIC[ICa_tot_sl] is ICa_tot_sl in component calcium (A_per_F).
 * CONSTANTS[JCa_slmyo] is JCa_slmyo in component geom (m3_per_s).
 * CONSTANTS[Vsr] is Vsr in component geom (liter).
 * ALGEBRAIC[J_serca] is J_serca in component ryr (mM_per_ms).
 * CONSTANTS[C] is C in component cell (farad).
 * CONSTANTS[JCa_jnsl] is JCa_jnsl in component geom (m3_per_s).
 * CONSTANTS[F] is F in component phys (C_per_mol).
 * ALGEBRAIC[J_SRCarel] is J_SRCarel in component ryr (mM_per_ms).
 * ALGEBRAIC[J_SR_leak] is J_SR_leak in component ryr (mM_per_ms).
 * CONSTANTS[Bmax_Csqn] is Bmax_Csqn in component calcium_Csqn (mM).
 * CONSTANTS[koff_csqn] is koff_csqn in component calcium_Csqn (mS_per_uF).
 * CONSTANTS[kon_csqn] is kon_csqn in component calcium_Csqn (per_mM_per_ms).
 * ALGEBRAIC[ICaB_jn] is ICaB_jn in component icab (A_per_F).
 * ALGEBRAIC[ICaL_Ca_jn] is ICaL_Ca_jn in component ical (A_per_F).
 * ALGEBRAIC[INaCa_jn] is INaCa_jn in component inaca (A_per_F).
 * ALGEBRAIC[IpCa_jn] is IpCa_jn in component ipca (A_per_F).
 * ALGEBRAIC[ICaB_sl] is ICaB_sl in component icab (A_per_F).
 * ALGEBRAIC[ICaL_Ca_sl] is ICaL_Ca_sl in component ical (A_per_F).
 * ALGEBRAIC[INaCa_sl] is INaCa_sl in component inaca (A_per_F).
 * ALGEBRAIC[IpCa_sl] is IpCa_sl in component ipca (A_per_F).
 * CONSTANTS[AF] is AF in component cell (dimensionless).
 * CONSTANTS[RA] is RA in component cell (dimensionless).
 * CONSTANTS[JNa_jnsl] is JNa_jnsl in component geom (m3_per_s).
 * CONSTANTS[JNa_slmyo] is JNa_slmyo in component geom (m3_per_s).
 * CONSTANTS[Vcell] is Vcell in component geom (liter).
 * CONSTANTS[cell_length] is cell_length in component geom (um).
 * CONSTANTS[cell_radius] is cell_radius in component geom (um).
 * CONSTANTS[pi] is pi in component geom (dimensionless).
 * ALGEBRAIC[ICaB] is ICaB in component icab (A_per_F).
 * CONSTANTS[gCaB] is gCaB in component icab (mS_per_uF).
 * CONSTANTS[Fjn] is Fjn in component junc (dimensionless).
 * STATES[V] is V in component membrane (mV).
 * ALGEBRAIC[ECa_jn] is ECa_jn in component nernst (mV).
 * CONSTANTS[Fsl] is Fsl in component junc (dimensionless).
 * ALGEBRAIC[ECa_sl] is ECa_sl in component nernst (mV).
 * ALGEBRAIC[ICaL] is ICaL in component ical (A_per_F).
 * ALGEBRAIC[ICaL_Ca] is ICaL_Ca in component ical (A_per_F).
 * ALGEBRAIC[ICaL_K] is ICaL_K in component ical (A_per_F).
 * ALGEBRAIC[ICaL_Na] is ICaL_Na in component ical (A_per_F).
 * ALGEBRAIC[ICaL_Na_jn] is ICaL_Na_jn in component ical (A_per_F).
 * ALGEBRAIC[ICaL_Na_sl] is ICaL_Na_sl in component ical (A_per_F).
 * CONSTANTS[Q10CaL] is Q10CaL in component ical (dimensionless).
 * STATES[d] is d in component ical (dimensionless).
 * STATES[f] is f in component ical (dimensionless).
 * STATES[fCaB_jn] is fCaB_jn in component ical (dimensionless).
 * STATES[fCaB_sl] is fCaB_sl in component ical (dimensionless).
 * CONSTANTS[f_conducting] is f_conducting in component ical (dimensionless).
 * CONSTANTS[fcaCaMSL] is fcaCaMSL in component ical (dimensionless).
 * CONSTANTS[fcaCaj] is fcaCaj in component ical (dimensionless).
 * ALGEBRAIC[ibarca_jn] is ibarca_jn in component ical (uA_per_cm2).
 * ALGEBRAIC[ibarca_sl] is ibarca_sl in component ical (uA_per_cm2).
 * ALGEBRAIC[ibark] is ibark in component ical (uA_per_cm2).
 * ALGEBRAIC[ibarna_jn] is ibarna_jn in component ical (uA_per_cm2).
 * ALGEBRAIC[ibarna_sl] is ibarna_sl in component ical (uA_per_cm2).
 * CONSTANTS[pCa] is pCa in component ical (cm_per_s).
 * CONSTANTS[pCa_max] is pCa_max in component ical (cm_per_s).
 * CONSTANTS[pK] is pK in component ical (cm_per_s).
 * CONSTANTS[pK_max] is pK_max in component ical (cm_per_s).
 * CONSTANTS[pNa] is pNa in component ical (cm_per_s).
 * CONSTANTS[pNa_max] is pNa_max in component ical (cm_per_s).
 * CONSTANTS[Fjn_CaL] is Fjn_CaL in component junc (dimensionless).
 * CONSTANTS[Q] is Q in component phys (dimensionless).
 * CONSTANTS[Fsl_CaL] is Fsl_CaL in component junc (dimensionless).
 * ALGEBRAIC[ical_d_inf] is ical_d_inf in component ical_d (dimensionless).
 * ALGEBRAIC[ical_d_tau] is ical_d_tau in component ical_d (ms).
 * ALGEBRAIC[ical_f_inf] is ical_f_inf in component ical_f (dimensionless).
 * ALGEBRAIC[ical_f_tau] is ical_f_tau in component ical_f (ms).
 * CONSTANTS[Ca_o] is Ca_o in component ion (mM).
 * CONSTANTS[FRT] is FRT in component phys (per_mV).
 * CONSTANTS[K_o] is K_o in component ion (mM).
 * STATES[K_i] is K_i in component potassium (mM).
 * CONSTANTS[Na_o] is Na_o in component ion (mM).
 * ALGEBRAIC[IClB] is IClB in component iclb (A_per_F).
 * CONSTANTS[gClB] is gClB in component iclb (mS_per_uF).
 * CONSTANTS[ECl] is ECl in component nernst (mV).
 * CONSTANTS[GClCa] is GClCa in component iclca (mS_per_uF).
 * ALGEBRAIC[IClCa] is IClCa in component iclca (A_per_F).
 * ALGEBRAIC[IClCa_jn] is IClCa_jn in component iclca (A_per_F).
 * ALGEBRAIC[IClCa_sl] is IClCa_sl in component iclca (A_per_F).
 * CONSTANTS[KdClCa] is KdClCa in component iclca (mM).
 * ALGEBRAIC[IK1] is IK1 in component ik1 (A_per_F).
 * CONSTANTS[gK1] is gK1 in component ik1 (mS_per_uF).
 * CONSTANTS[gK1_max] is gK1_max in component ik1 (mS_per_uF).
 * ALGEBRAIC[ik1_inf] is ik1_inf in component ik1 (dimensionless).
 * ALGEBRAIC[EK] is EK in component nernst (mV).
 * ALGEBRAIC[ik1_inf_a] is ik1_inf_a in component ik1_ik1_inf (mS_per_uF).
 * ALGEBRAIC[ik1_inf_b] is ik1_inf_b in component ik1_ik1_inf (mS_per_uF).
 * ALGEBRAIC[IKp] is IKp in component ikp (A_per_F).
 * ALGEBRAIC[IKp_jn] is IKp_jn in component ikp (A_per_F).
 * ALGEBRAIC[IKp_sl] is IKp_sl in component ikp (A_per_F).
 * CONSTANTS[gKp] is gKp in component ikp (mS_per_uF).
 * ALGEBRAIC[kp] is kp in component ikp (dimensionless).
 * ALGEBRAIC[IKr] is IKr in component ikr (A_per_F).
 * CONSTANTS[gKr] is gKr in component ikr (mS_per_uF).
 * CONSTANTS[gKr_max] is gKr_max in component ikr (mS_per_uF).
 * ALGEBRAIC[rr] is rr in component ikr (dimensionless).
 * STATES[xr] is xr in component ikr (dimensionless).
 * ALGEBRAIC[ikr_xr_inf] is ikr_xr_inf in component ikr_xr (dimensionless).
 * ALGEBRAIC[ikr_xr_tau] is ikr_xr_tau in component ikr_xr (ms).
 * ALGEBRAIC[EKs] is EKs in component iks (mV).
 * ALGEBRAIC[IKs] is IKs in component iks (A_per_F).
 * ALGEBRAIC[IKs_jn] is IKs_jn in component iks (A_per_F).
 * ALGEBRAIC[IKs_sl] is IKs_sl in component iks (A_per_F).
 * CONSTANTS[gKs_jn] is gKs_jn in component iks (mS_per_uF).
 * CONSTANTS[gKs_max] is gKs_max in component iks (mS_per_uF).
 * CONSTANTS[gKs_sl] is gKs_sl in component iks (mS_per_uF).
 * CONSTANTS[pNaK] is pNaK in component iks (dimensionless).
 * STATES[xs] is xs in component iks (dimensionless).
 * STATES[Na_i] is Na_i in component sodium (mM).
 * ALGEBRAIC[iks_xs_inf] is iks_xs_inf in component iks_xs (dimensionless).
 * ALGEBRAIC[iks_xs_tau] is iks_xs_tau in component iks_xs (ms).
 * ALGEBRAIC[IKur] is IKur in component ikur (A_per_F).
 * CONSTANTS[gKur] is gKur in component ikur (mS_per_uF).
 * CONSTANTS[gKur_max] is gKur_max in component ikur (mS_per_uF).
 * STATES[ikur_r] is ikur_r in component ikur (dimensionless).
 * STATES[s] is s in component ikur (dimensionless).
 * ALGEBRAIC[ikur_r_inf] is ikur_r_inf in component ikur_ikur_r (dimensionless).
 * ALGEBRAIC[ikur_r_tau] is ikur_r_tau in component ikur_ikur_r (ms).
 * ALGEBRAIC[ikur_s_inf] is ikur_s_inf in component ikur_s (dimensionless).
 * ALGEBRAIC[ikur_s_tau] is ikur_s_tau in component ikur_s (ms).
 * ALGEBRAIC[INa] is INa in component ina (A_per_F).
 * ALGEBRAIC[INa_jn] is INa_jn in component ina (A_per_F).
 * ALGEBRAIC[INa_sl] is INa_sl in component ina (A_per_F).
 * CONSTANTS[gNa] is gNa in component ina (mS_per_uF).
 * CONSTANTS[gNa_max] is gNa_max in component ina (mS_per_uF).
 * STATES[h] is h in component ina (dimensionless).
 * STATES[j] is j in component ina (dimensionless).
 * STATES[m] is m in component ina (dimensionless).
 * ALGEBRAIC[ENa_jn] is ENa_jn in component nernst (mV).
 * ALGEBRAIC[ENa_sl] is ENa_sl in component nernst (mV).
 * ALGEBRAIC[ina_h_inf] is ina_h_inf in component ina_h (dimensionless).
 * ALGEBRAIC[ina_h_tau] is ina_h_tau in component ina_h (ms).
 * ALGEBRAIC[ina_j_inf] is ina_j_inf in component ina_j (dimensionless).
 * ALGEBRAIC[ina_j_tau] is ina_j_tau in component ina_j (ms).
 * ALGEBRAIC[ina_m_inf] is ina_m_inf in component ina_m (dimensionless).
 * ALGEBRAIC[ina_m_tau] is ina_m_tau in component ina_m (ms).
 * ALGEBRAIC[ina_h_a] is ina_h_a in component ina_h (mS_per_uF).
 * ALGEBRAIC[ina_h_b] is ina_h_b in component ina_h (mS_per_uF).
 * ALGEBRAIC[ina_j_a] is ina_j_a in component ina_j (mS_per_uF).
 * ALGEBRAIC[ina_j_b] is ina_j_b in component ina_j (mS_per_uF).
 * ALGEBRAIC[INaB] is INaB in component inab (A_per_F).
 * ALGEBRAIC[INaB_jn] is INaB_jn in component inab (A_per_F).
 * ALGEBRAIC[INaB_sl] is INaB_sl in component inab (A_per_F).
 * CONSTANTS[gNaB] is gNaB in component inab (mS_per_uF).
 * ALGEBRAIC[INaCa] is INaCa in component inaca (A_per_F).
 * CONSTANTS[IbarNCX] is IbarNCX in component inaca (A_per_F).
 * CONSTANTS[IbarNCX_max] is IbarNCX_max in component inaca (A_per_F).
 * ALGEBRAIC[Ka_jn] is Ka_jn in component inaca (dimensionless).
 * ALGEBRAIC[Ka_sl] is Ka_sl in component inaca (dimensionless).
 * CONSTANTS[Kdact] is Kdact in component inaca (mM).
 * CONSTANTS[KmCai] is KmCai in component inaca (mM).
 * CONSTANTS[KmCao] is KmCao in component inaca (mM).
 * CONSTANTS[KmNai] is KmNai in component inaca (mM).
 * CONSTANTS[KmNao] is KmNao in component inaca (mM).
 * CONSTANTS[Q10NCX] is Q10NCX in component inaca (dimensionless).
 * CONSTANTS[ksat] is ksat in component inaca (dimensionless).
 * CONSTANTS[nu] is nu in component inaca (dimensionless).
 * ALGEBRAIC[s1_jn] is s1_jn in component inaca_INaCa_jn (mol4_per_m12).
 * ALGEBRAIC[s2_jn] is s2_jn in component inaca_INaCa_jn (mol4_per_m12).
 * ALGEBRAIC[s3_jn] is s3_jn in component inaca_INaCa_jn (mol4_per_m12).
 * ALGEBRAIC[s1_sl] is s1_sl in component inaca_INaCa_sl (mol4_per_m12).
 * ALGEBRAIC[s2_sl] is s2_sl in component inaca_INaCa_sl (mol4_per_m12).
 * ALGEBRAIC[s3_sl] is s3_sl in component inaca_INaCa_sl (mol4_per_m12).
 * ALGEBRAIC[INaK] is INaK in component inak (A_per_F).
 * ALGEBRAIC[INaK_jn] is INaK_jn in component inak (A_per_F).
 * ALGEBRAIC[INaK_sl] is INaK_sl in component inak (A_per_F).
 * CONSTANTS[IbarNaK] is IbarNaK in component inak (A_per_F).
 * CONSTANTS[KmKo] is KmKo in component inak (mM).
 * CONSTANTS[KmNaip] is KmNaip in component inak (mM).
 * ALGEBRAIC[fnak] is fnak in component inak (dimensionless).
 * CONSTANTS[sigma] is sigma in component inak (dimensionless).
 * ALGEBRAIC[INaL] is INaL in component inal (A_per_F).
 * ALGEBRAIC[INaL_jn] is INaL_jn in component inal (A_per_F).
 * ALGEBRAIC[INaL_sl] is INaL_sl in component inal (A_per_F).
 * CONSTANTS[gNaL] is gNaL in component inal (mS_per_uF).
 * CONSTANTS[gNaL_max] is gNaL_max in component inal (mS_per_uF).
 * STATES[hl] is hl in component inal (dimensionless).
 * STATES[ml] is ml in component inal (dimensionless).
 * ALGEBRAIC[inal_hl_inf] is inal_hl_inf in component inal_hl (dimensionless).
 * CONSTANTS[inal_hl_tau] is inal_hl_tau in component inal_hl (ms).
 * ALGEBRAIC[inal_ml_a] is inal_ml_a in component inal_ml (mS_per_uF).
 * ALGEBRAIC[inal_ml_b] is inal_ml_b in component inal_ml (mS_per_uF).
 * CONSTANTS[Cl_i] is Cl_i in component ion (mM).
 * CONSTANTS[Cl_o] is Cl_o in component ion (mM).
 * CONSTANTS[IbarSLCaP] is IbarSLCaP in component ipca (A_per_F).
 * ALGEBRAIC[IpCa] is IpCa in component ipca (A_per_F).
 * CONSTANTS[KmPCa] is KmPCa in component ipca (mM).
 * CONSTANTS[Q10SLCaP] is Q10SLCaP in component ipca (dimensionless).
 * ALGEBRAIC[ipca_IpCa_jn_a] is ipca_IpCa_jn_a in component ipca_IpCa_jn (dimensionless).
 * CONSTANTS[ipca_IpCa_jn_b] is ipca_IpCa_jn_b in component ipca_IpCa_jn (dimensionless).
 * ALGEBRAIC[ipca_IpCa_sl_a] is ipca_IpCa_sl_a in component ipca_IpCa_sl (dimensionless).
 * CONSTANTS[ipca_IpCa_sl_b] is ipca_IpCa_sl_b in component ipca_IpCa_sl (dimensionless).
 * ALGEBRAIC[Ito] is Ito in component ito (A_per_F).
 * CONSTANTS[gto] is gto in component ito (mS_per_uF).
 * CONSTANTS[gto_max] is gto_max in component ito (mS_per_uF).
 * STATES[x] is x in component ito (dimensionless).
 * STATES[y] is y in component ito (dimensionless).
 * ALGEBRAIC[ito_x_inf] is ito_x_inf in component ito_x (dimensionless).
 * ALGEBRAIC[ito_x_tau] is ito_x_tau in component ito_x (ms).
 * ALGEBRAIC[ito_y_inf] is ito_y_inf in component ito_y (dimensionless).
 * ALGEBRAIC[ito_y_tau] is ito_y_tau in component ito_y (ms).
 * ALGEBRAIC[ICa_tot] is ICa_tot in component membrane (A_per_F).
 * ALGEBRAIC[ICl_tot] is ICl_tot in component membrane (A_per_F).
 * ALGEBRAIC[INa_tot] is INa_tot in component membrane (A_per_F).
 * ALGEBRAIC[I_tot] is I_tot in component membrane (A_per_F).
 * ALGEBRAIC[INa_tot_jn] is INa_tot_jn in component sodium (A_per_F).
 * ALGEBRAIC[INa_tot_sl] is INa_tot_sl in component sodium (A_per_F).
 * ALGEBRAIC[IK_tot] is IK_tot in component potassium (A_per_F).
 * ALGEBRAIC[I_stim] is I_stim in component stimulus (A_per_F).
 * CONSTANTS[R] is R in component phys (mJ_per_mol_per_K).
 * CONSTANTS[T] is T in component phys (kelvin).
 * CONSTANTS[J_SR_leak_max] is J_SR_leak_max in component ryr (mS_per_uF).
 * CONSTANTS[Kmf] is Kmf in component ryr (mM).
 * CONSTANTS[Kmr] is Kmr in component ryr (mM).
 * CONSTANTS[MaxSR] is MaxSR in component ryr (dimensionless).
 * CONSTANTS[MinSR] is MinSR in component ryr (dimensionless).
 * CONSTANTS[Q10SRCaP] is Q10SRCaP in component ryr (dimensionless).
 * ALGEBRAIC[RI] is RI in component ryr (dimensionless).
 * CONSTANTS[Vmax_SRCaP] is Vmax_SRCaP in component ryr (mM_per_ms).
 * CONSTANTS[ec50SR] is ec50SR in component ryr (mM).
 * CONSTANTS[hillSRCaP] is hillSRCaP in component ryr (dimensionless).
 * STATES[i] is i in component ryr (dimensionless).
 * ALGEBRAIC[kCaSR] is kCaSR in component ryr (dimensionless).
 * CONSTANTS[kiCa] is kiCa in component ryr (per_mM_per_ms).
 * ALGEBRAIC[kiSRCa] is kiSRCa in component ryr (per_mM_per_ms).
 * CONSTANTS[kim] is kim in component ryr (mS_per_uF).
 * CONSTANTS[koCa] is koCa in component ryr (per_mM2_per_ms).
 * ALGEBRAIC[koSRCa] is koSRCa in component ryr (per_mM2_per_ms).
 * CONSTANTS[kom] is kom in component ryr (mS_per_uF).
 * CONSTANTS[ks] is ks in component ryr (mS_per_uF).
 * STATES[o] is o in component ryr (dimensionless).
 * STATES[ryr_r] is ryr_r in component ryr (dimensionless).
 * CONSTANTS[amp] is amp in component stimulus (A_per_F).
 * ALGEBRAIC[pace] is pace in component stimulus (dimensionless).
 * CONSTANTS[duration] is duration in component stimulus (ms).
 * CONSTANTS[stim_start] is stim_start in component stimulus (ms).
 * CONSTANTS[BCL] is BCL in component stimulus (ms).
 * RATES[CaM] is d/dt CaM in component buffca (mM).
 * RATES[TnCL] is d/dt TnCL in component buffca (mM).
 * RATES[TnCHc] is d/dt TnCHc in component buffca (mM).
 * RATES[TnCHm] is d/dt TnCHm in component buffca (mM).
 * RATES[Myoc] is d/dt Myoc in component buffca (mM).
 * RATES[Myom] is d/dt Myom in component buffca (mM).
 * RATES[SRB] is d/dt SRB in component buffca (mM).
 * RATES[SLL_jn] is d/dt SLL_jn in component buffca (mM).
 * RATES[SLH_jn] is d/dt SLH_jn in component buffca (mM).
 * RATES[SLL_sl] is d/dt SLL_sl in component buffca (mM).
 * RATES[SLH_sl] is d/dt SLH_sl in component buffca (mM).
 * RATES[NaB_jn] is d/dt NaB_jn in component buffna (mM).
 * RATES[NaB_sl] is d/dt NaB_sl in component buffna (mM).
 * RATES[cai] is d/dt Ca_i in component calcium (mM).
 * RATES[Ca_jn] is d/dt Ca_jn in component calcium (mM).
 * RATES[Ca_sl] is d/dt Ca_sl in component calcium (mM).
 * RATES[Ca_sr] is d/dt Ca_sr in component calcium (mM).
 * RATES[Csqn] is d/dt Csqn in component calcium (mM).
 * RATES[d] is d/dt d in component ical (dimensionless).
 * RATES[f] is d/dt f in component ical (dimensionless).
 * RATES[fCaB_jn] is d/dt fCaB_jn in component ical (dimensionless).
 * RATES[fCaB_sl] is d/dt fCaB_sl in component ical (dimensionless).
 * RATES[xr] is d/dt xr in component ikr (dimensionless).
 * RATES[xs] is d/dt xs in component iks (dimensionless).
 * RATES[ikur_r] is d/dt ikur_r in component ikur (dimensionless).
 * RATES[s] is d/dt s in component ikur (dimensionless).
 * RATES[h] is d/dt h in component ina (dimensionless).
 * RATES[j] is d/dt j in component ina (dimensionless).
 * RATES[m] is d/dt m in component ina (dimensionless).
 * RATES[hl] is d/dt hl in component inal (dimensionless).
 * RATES[ml] is d/dt ml in component inal (dimensionless).
 * RATES[x] is d/dt x in component ito (dimensionless).
 * RATES[y] is d/dt y in component ito (dimensionless).
 * RATES[V] is d/dt V in component membrane (mV).
 * RATES[K_i] is d/dt K_i in component potassium (mM).
 * RATES[i] is d/dt i in component ryr (dimensionless).
 * RATES[o] is d/dt o in component ryr (dimensionless).
 * RATES[ryr_r] is d/dt ryr_r in component ryr (dimensionless).
 * RATES[Na_i] is d/dt Na_i in component sodium (mM).
 * RATES[Na_jn] is d/dt Na_jn in component sodium (mM).
 * RATES[Na_sl] is d/dt Na_sl in component sodium (mM).
 */


grandi_2011_atrial_with_meta::grandi_2011_atrial_with_meta()
{
algebraic_size = 120;
constants_size = 137;
states_size = 41;
ALGEBRAIC = new double[algebraic_size];
CONSTANTS = new double[constants_size];
RATES = new double[states_size];
STATES = new double[states_size];
}

grandi_2011_atrial_with_meta::~grandi_2011_atrial_with_meta()
{
delete []ALGEBRAIC;
delete []CONSTANTS;
delete []RATES;
delete []STATES;
}

void grandi_2011_atrial_with_meta::___initConsts()
{
CONSTANTS[Bmax_CaM] = 0.024;
CONSTANTS[Bmax_SR] = 0.0171;
CONSTANTS[Bmax_TnChigh] = 0.14;
CONSTANTS[Bmax_TnClow] = 0.07;
CONSTANTS[Bmax_myosin] = 0.14;
STATES[CaM] =  7.02128101897185673e-04;
STATES[Myoc] =  3.94923428392655786e-03;
STATES[Myom] =  1.35538532457244482e-01;
STATES[SLH_jn] =  1.03674364292988680e-01;
STATES[SLH_sl] =  1.90759804527589089e-01;
STATES[SLL_jn] =  1.35640688636079511e-02;
STATES[SLL_sl] =  2.14063418881809235e-02;
STATES[SRB] =  4.45327242854324807e-03;
STATES[TnCHc] =  1.27856586024588575e-01;
STATES[TnCHm] =  5.69999505293381902e-03;
STATES[TnCL] =  1.83143535034222225e-02;
CONSTANTS[koff_cam] = 0.238;
CONSTANTS[koff_myoca] = 0.00046;
CONSTANTS[koff_myomg] = 5.7e-05;
CONSTANTS[koff_slh] = 0.03;
CONSTANTS[koff_sll] = 1.3;
CONSTANTS[koff_sr] = 0.06;
CONSTANTS[koff_tnchca] = 3.2e-05;
CONSTANTS[koff_tnchmg] = 0.00333;
CONSTANTS[kon_cam] = 34.0;
CONSTANTS[kon_myoca] = 13.8;
CONSTANTS[kon_myomg] = 0.0157;
CONSTANTS[kon_slh] = 100.0;
CONSTANTS[kon_sll] = 100.0;
CONSTANTS[kon_sr] = 100.0;
CONSTANTS[kon_tnchca] = 2.37;
CONSTANTS[kon_tnchmg] = 0.003;
CONSTANTS[kon_tncl] = 32.7;
STATES[cai] =  2.10808768153058460e-04;
CONSTANTS[Mg_i] = 1.0;
STATES[Ca_jn] =  3.25814677291117296e-04;
STATES[Ca_sl] =  2.33018340557575125e-04;
CONSTANTS[ISO] = 0.0;
CONSTANTS[Bmax_Na_jn] = 7.561;
CONSTANTS[Bmax_Na_sl] = 1.65;
STATES[NaB_jn] =  3.61396062660070427e+00;
STATES[NaB_sl] =  7.88607791910409195e-01;
CONSTANTS[koff_na] = 0.001;
CONSTANTS[kon_na] = 0.0001;
STATES[Na_jn] =  9.15153381546177336e+00;
STATES[Na_sl] =  9.15182798281732346e+00;
STATES[Ca_sr] =  5.02305826642838293e-01;
STATES[Csqn] =  1.13337536953687845e+00;
CONSTANTS[JCa_slmyo] =  3.72425607984805052e-12;
CONSTANTS[C] = 1.1e-10;
CONSTANTS[JCa_jnsl] =  8.24130542277896849e-13;
CONSTANTS[F] = 96485.0;
CONSTANTS[koff_csqn] = 65.0;
CONSTANTS[kon_csqn] = 100.0;
CONSTANTS[AF] = 0.0;
CONSTANTS[RA] = 0.0;
CONSTANTS[JNa_jnsl] =  1.83127823220607955e-14;
CONSTANTS[JNa_slmyo] =  1.63862792221979433e-12;
CONSTANTS[cell_length] = 100.0;
CONSTANTS[cell_radius] = 10.25;
CONSTANTS[pi] =  3.14159265358979312e+00;
CONSTANTS[gCaB] =  6.06430000000000033e-04;
CONSTANTS[Fjn] = 0.11;
STATES[V] = -7.34336366728778671e+01;
CONSTANTS[Q10CaL] = 1.8;
STATES[d] =  2.16850216379767157e-05;
STATES[f] =  9.98384427312367095e-01;
STATES[fCaB_jn] =  4.49572164109603364e-02;
STATES[fCaB_sl] =  3.28512098597005947e-02;
CONSTANTS[f_conducting] = 1.0;
CONSTANTS[fcaCaMSL] = 0.0;
CONSTANTS[fcaCaj] = 0.0;
CONSTANTS[pCa_max] = 0.00027;
CONSTANTS[pK_max] = 1.35e-07;
CONSTANTS[pNa_max] = 7.5e-09;
CONSTANTS[Fjn_CaL] = 0.9;
CONSTANTS[Ca_o] = 1.8;
CONSTANTS[K_o] = 5.4;
STATES[K_i] = 120.0;
CONSTANTS[Na_o] = 140.0;
CONSTANTS[gClB] = 0.009;
CONSTANTS[GClCa] = 0.0548;
CONSTANTS[KdClCa] = 0.1;
CONSTANTS[gK1_max] = 0.0525;
CONSTANTS[gKp] = 0.002;
CONSTANTS[gKr_max] = 0.035;
STATES[xr] =  1.31290096227093382e-03;
CONSTANTS[gKs_max] = 0.0035;
CONSTANTS[pNaK] = 0.01833;
STATES[xs] =  7.49436760722081534e-03;
STATES[Na_i] =  9.15199678386256998e+00;
CONSTANTS[gKur_max] = 0.045;
STATES[ikur_r] =  3.93548562883350357e-04;
STATES[s] =  9.58234428284286399e-01;
CONSTANTS[gNa_max] = 23.0;
STATES[h] =  3.15482710277587786e-01;
STATES[j] =  2.48034071360795916e-01;
STATES[m] =  1.89326933812916480e-02;
CONSTANTS[gNaB] = 0.000597;
CONSTANTS[IbarNCX_max] = 3.15;
CONSTANTS[Kdact] = 0.000384;
CONSTANTS[KmCai] = 0.00359;
CONSTANTS[KmCao] = 1.3;
CONSTANTS[KmNai] = 12.29;
CONSTANTS[KmNao] = 87.5;
CONSTANTS[Q10NCX] = 1.57;
CONSTANTS[ksat] = 0.27;
CONSTANTS[nu] = 0.35;
CONSTANTS[IbarNaK] = 1.26;
CONSTANTS[KmKo] = 1.5;
CONSTANTS[gNaL_max] = 0.0025;
STATES[hl] =  3.79829335413739144e-02;
STATES[ml] =  1.01974216400706526e-02;
CONSTANTS[inal_hl_tau] = 600.0;
CONSTANTS[Cl_i] = 15.0;
CONSTANTS[Cl_o] = 150.0;
CONSTANTS[IbarSLCaP] = 0.0471;
CONSTANTS[KmPCa] = 0.0005;
CONSTANTS[Q10SLCaP] = 2.35;
CONSTANTS[gto_max] = 0.165;
STATES[x] =  1.37939236359928058e-03;
STATES[y] =  9.45874848392074696e-01;
CONSTANTS[R] = 8314.0;
CONSTANTS[T] = 310.0;
CONSTANTS[J_SR_leak_max] = 5.348e-06;
CONSTANTS[Kmr] = 1.7;
CONSTANTS[MaxSR] = 15.0;
CONSTANTS[MinSR] = 1.0;
CONSTANTS[Q10SRCaP] = 2.6;
CONSTANTS[Vmax_SRCaP] = 0.0053114;
CONSTANTS[ec50SR] = 0.45;
CONSTANTS[hillSRCaP] = 1.787;
STATES[i] =  5.01323282772066123e-07;
CONSTANTS[kiCa] = 0.5;
CONSTANTS[kim] = 0.005;
CONSTANTS[kom] = 0.06;
CONSTANTS[ks] = 25.0;
STATES[o] =  2.01567245823636694e-06;
STATES[ryr_r] =  8.00819151705148946e-01;
CONSTANTS[amp] = -12.5;
CONSTANTS[duration] = 5.0;
//CONSTANTS[stim_start] = 50.0;
CONSTANTS[stim_start] = 10.0;
CONSTANTS[BCL] = 1000.0;
CONSTANTS[koff_tncl] =  (1.00000+ 0.500000*CONSTANTS[ISO])*0.0196000;
CONSTANTS[Vcell] =  ( ( CONSTANTS[pi]*pow(CONSTANTS[cell_radius], 2.00000))*CONSTANTS[cell_length])*1.00000e-15;
CONSTANTS[ipca_IpCa_jn_b] = pow( CONSTANTS[KmPCa]*1.00000, 1.60000);
CONSTANTS[pCa] =  ( (1.00000+ 0.500000*CONSTANTS[ISO])*(1.00000 -  0.500000*CONSTANTS[AF]))*CONSTANTS[pCa_max];
CONSTANTS[pK] =  ( (1.00000+ 0.500000*CONSTANTS[ISO])*(1.00000 -  0.500000*CONSTANTS[AF]))*CONSTANTS[pK_max];
CONSTANTS[pNa] =  ( (1.00000+ 0.500000*CONSTANTS[ISO])*(1.00000 -  0.500000*CONSTANTS[AF]))*CONSTANTS[pNa_max];
CONSTANTS[Fsl_CaL] = 1.00000 - CONSTANTS[Fjn_CaL];
CONSTANTS[FRT] = (CONSTANTS[F]/CONSTANTS[R])/CONSTANTS[T];
CONSTANTS[gK1] =  ( (1.00000+CONSTANTS[AF])* pow((CONSTANTS[K_o]/5.40000), 1.0 / 2))*CONSTANTS[gK1_max];
CONSTANTS[gKr] =  CONSTANTS[gKr_max]* pow((CONSTANTS[K_o]/5.40000), 1.0 / 2);
CONSTANTS[gKs_jn] =  ((1.00000+CONSTANTS[AF])+ 2.00000*CONSTANTS[ISO])*CONSTANTS[gKs_max];
CONSTANTS[gKs_sl] =  ((1.00000+CONSTANTS[AF])+ 2.00000*CONSTANTS[ISO])*CONSTANTS[gKs_max];
CONSTANTS[gKur] =  ( ( (1.00000 -  0.500000*CONSTANTS[AF])*(1.00000+ 2.00000*CONSTANTS[ISO]))*(1.00000+ 0.200000*CONSTANTS[RA]))*CONSTANTS[gKur_max];
CONSTANTS[gNa] =  CONSTANTS[gNa_max]*(1.00000 -  0.100000*CONSTANTS[AF]);
CONSTANTS[IbarNCX] =  (1.00000+ 0.400000*CONSTANTS[AF])*CONSTANTS[IbarNCX_max];
CONSTANTS[KmNaip] =  11.0000*(1.00000 -  0.250000*CONSTANTS[ISO]);
CONSTANTS[sigma] = (exp(CONSTANTS[Na_o]/67.3000) - 1.00000)/7.00000;
CONSTANTS[gNaL] =  CONSTANTS[gNaL_max]*CONSTANTS[AF];
CONSTANTS[gto] =  (1.00000 -  0.700000*CONSTANTS[AF])*CONSTANTS[gto_max];
CONSTANTS[Kmf] =  (2.50000 -  1.25000*CONSTANTS[ISO])*0.000246000;
CONSTANTS[koCa] =  ((10.0000+ 20.0000*CONSTANTS[AF])+ ( 10.0000*CONSTANTS[ISO])*(1.00000 - CONSTANTS[AF]))*1.00000;
CONSTANTS[Vjn] =  ( 0.0539000*0.0100000)*CONSTANTS[Vcell];
CONSTANTS[ipca_IpCa_sl_b] = pow( CONSTANTS[KmPCa]*1.00000, 1.60000);
CONSTANTS[ECl] =  (1.00000/CONSTANTS[FRT])*log(CONSTANTS[Cl_i]/CONSTANTS[Cl_o]);
CONSTANTS[Vmyo] =  0.650000*CONSTANTS[Vcell];
CONSTANTS[Fsl] = 1.00000 - CONSTANTS[Fjn];
CONSTANTS[Bmax_SLhighj] =  (( 0.00165000*CONSTANTS[Vmyo])/CONSTANTS[Vjn])*0.100000;
CONSTANTS[Bmax_SLlowj] =  (( 0.00460000*CONSTANTS[Vmyo])/CONSTANTS[Vjn])*0.100000;
CONSTANTS[Vsl] =  0.0200000*CONSTANTS[Vcell];
CONSTANTS[Vsr] =  0.0350000*CONSTANTS[Vcell];
CONSTANTS[Q] = (CONSTANTS[T] - 310.000)/10.0000;
CONSTANTS[Bmax_SLhighsl] =  (CONSTANTS[Vmyo]/CONSTANTS[Vsl])*0.0134000;
CONSTANTS[Bmax_SLlowsl] =  (CONSTANTS[Vmyo]/CONSTANTS[Vsl])*0.0374000;
CONSTANTS[Bmax_Csqn] =  (CONSTANTS[Vmyo]/CONSTANTS[Vsr])*0.140000;
}


void grandi_2011_atrial_with_meta::___applyCVar(const double *cvar) {
  mpi_printf(0, "Before population:\n");
  mpi_printf(0, "%s,%s,%s,%s,%s,%s:\n",
             "gNa","gNaL","gto","gKr","gKs_jn","gKs_sl","gK1");
  mpi_printf(0, "%.4lf,%.4lf,%.4lf,%.4lf,%.4lf,%.4lf\n",
             CONSTANTS[gNa],CONSTANTS[gNaL],CONSTANTS[gto],CONSTANTS[gKr],CONSTANTS[gKs_jn],CONSTANTS[gKs_sl],CONSTANTS[gK1]);

  CONSTANTS[gNa] *= cvar[0];
  CONSTANTS[gNaL] *= cvar[1];
  CONSTANTS[gto] *= cvar[2];
  CONSTANTS[gKr] *= cvar[3];
  CONSTANTS[gKs_jn] *= cvar[4];
  CONSTANTS[gKs_sl] *= cvar[4];
  CONSTANTS[gK1] *= cvar[5];

  mpi_printf(0, "After population:\n");
  mpi_printf(0, "%s,%s,%s,%s,%s,%s:\n",
             "gNa","gNaL","gto","gKr","gKs","gK1");
  mpi_printf(0, "%.4lf,%.4lf,%.4lf,%.4lf,%.4lf,%.4lf\n",
             CONSTANTS[gNa],CONSTANTS[gNaL],CONSTANTS[gto],CONSTANTS[gKr],CONSTANTS[gKs_jn],CONSTANTS[gKs_sl],CONSTANTS[gK1]);

}


void grandi_2011_atrial_with_meta::___applyDrugEffect(double conc, const double *hill)
{
CONSTANTS[gK1] *= ((hill[2] > cml::math::EPSILON && hill[3] > cml::math::EPSILON) ? 1./(1.+pow(conc/hill[2],hill[3])) : 1.);
CONSTANTS[gKs_jn] *= ((hill[4] > cml::math::EPSILON && hill[5] > cml::math::EPSILON) ? 1./(1.+pow(conc/hill[4],hill[5])) : 1.);
CONSTANTS[gKs_sl] *= ((hill[4] > cml::math::EPSILON && hill[5] > cml::math::EPSILON ) ? 1./(1.+pow(conc/hill[4],hill[5])) : 1.);
CONSTANTS[gNa] *= ((hill[6] > cml::math::EPSILON && hill[7] > cml::math::EPSILON ) ? 1./(1.+pow(conc/hill[6],hill[7])) : 1.);
CONSTANTS[gNaL] *= ((hill[8] > cml::math::EPSILON && hill[9] > cml::math::EPSILON) ? 1./(1.+pow(conc/hill[8],hill[9])) : 1.);
CONSTANTS[gto] *= ((hill[10] > cml::math::EPSILON && hill[11] > cml::math::EPSILON) ? 1./(1.+pow(conc/hill[10],hill[11])) : 1.);
CONSTANTS[gKr] *= ((hill[12] > cml::math::EPSILON && hill[13] > cml::math::EPSILON) ? 1./(1.+pow(conc/hill[12],hill[13])) : 1.);
}

void grandi_2011_atrial_with_meta::initConsts()
{
  ___initConsts();
}

void grandi_2011_atrial_with_meta::initConsts(double conc, const double *hill)
{ 
  ___initConsts();
  mpi_printf(cml::commons::MASTER_NODE,"Concentration: %lf\n", conc);
  mpi_printf(cml::commons::MASTER_NODE, 
    "+------------+------------+------------+------------+------------+------------+------------+----------------+\n"
    "| Parameter  |    gK1     |    gKs_jn     |    gKs_sl     |    gNa    |    gNaL     |    gto    |    gKr    |\n"
    "+------------+------------+------------+------------+------------+------------+------------+----------------+\n"
    "| Control    | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf |\n"
    "+------------+------------+------------+------------+------------+------------+------------+----------------+\n",   
    CONSTANTS[gK1], CONSTANTS[gKs_jn], CONSTANTS[gKs_sl], CONSTANTS[gNa], CONSTANTS[gNaL], CONSTANTS[gto], CONSTANTS[gKr]); 
  ___applyDrugEffect(conc, hill);
  mpi_printf(cml::commons::MASTER_NODE,
    "| After-Drug | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf | %10.6lf |\n"
    "+------------+------------+------------+------------+------------+------------+------------+----------------+\n", 
    CONSTANTS[gK1], CONSTANTS[gKs_jn], CONSTANTS[gKs_sl], CONSTANTS[gNa], CONSTANTS[gNaL], CONSTANTS[gto], CONSTANTS[gKr]); 

}

void grandi_2011_atrial_with_meta::initConsts( double conc, const double *hill, const double *cvar)
{
  initConsts(conc, hill);

  mpi_printf(cml::commons::MASTER_NODE,"Implementing Inter-individual Variability\n");
  ___applyCVar(cvar);
}


void grandi_2011_atrial_with_meta::computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC )
{
RATES[25] = 0.;
RATES[0] =  ( CONSTANTS[13]*STATES[11])*(CONSTANTS[0] - STATES[0]) -  CONSTANTS[5]*STATES[0];
RATES[23] =  ( ( 1.70000*STATES[12])*(1.00000 - STATES[23]) -  0.0119000*STATES[23])*1.00000;
RATES[24] =  ( ( 1.70000*STATES[13])*(1.00000 - STATES[24]) -  0.0119000*STATES[24])*1.00000;
RATES[28] =  (CONSTANTS[37]/CONSTANTS[126])*(STATES[17] - STATES[28]);
RATES[1] =  ( CONSTANTS[14]*STATES[11])*((CONSTANTS[4] - STATES[1]) - STATES[2]) -  CONSTANTS[6]*STATES[1];
ALGEBRAIC[9] = 1.00000/(1.00000+exp((STATES[20]+91.0000)/6.10000));
RATES[34] = (ALGEBRAIC[9] - STATES[34])/CONSTANTS[77];
RATES[2] =  ( CONSTANTS[15]*CONSTANTS[22])*((CONSTANTS[4] - STATES[1]) - STATES[2]) -  CONSTANTS[7]*STATES[2];
ALGEBRAIC[0] = 1.00000/(1.00000+exp(- ((STATES[20]+ 3.00000*CONSTANTS[23])+9.00000)/6.00000));
ALGEBRAIC[14] = ( ALGEBRAIC[0]*(1.00000 - exp(- ((STATES[20]+ 3.00000*CONSTANTS[23])+9.00000)/6.00000)))/( 0.0350000*((STATES[20]+ 3.00000*CONSTANTS[23])+9.00000));
RATES[21] = (ALGEBRAIC[0] - STATES[21])/ALGEBRAIC[14];
ALGEBRAIC[1] = 1.00000/(1.00000+exp(((STATES[20]+ 3.00000*CONSTANTS[23])+30.0000)/7.00000))+0.200000/(1.00000+exp(((50.0000 - STATES[20]) -  3.00000*CONSTANTS[23])/20.0000));
ALGEBRAIC[15] = 1.00000/( 0.0197000*exp(- pow( 0.0337000*((STATES[20]+ 3.00000*CONSTANTS[23])+25.0000), 2.00000))+0.0200000);
RATES[22] = (ALGEBRAIC[1] - STATES[22])/ALGEBRAIC[15];
ALGEBRAIC[2] = 1.00000/(1.00000+exp(- (STATES[20]+10.0000)/5.00000));
ALGEBRAIC[16] = ( ((550.000)/(1.00000+exp((- 22.0000 - STATES[20])/9.00000)))*6.00000)/(1.00000+exp((STATES[20]+11.0000)/9.00000))+230.000/(1.00000+exp((STATES[20]+40.0000)/20.0000));
RATES[26] = (ALGEBRAIC[2] - STATES[26])/ALGEBRAIC[16];
ALGEBRAIC[3] = 1.00000/(1.00000+exp(- ((STATES[20]+ 40.0000*CONSTANTS[23])+3.80000)/14.2500));
ALGEBRAIC[17] = 990.100/(1.00000+exp(- ((STATES[20]+ 40.0000*CONSTANTS[23])+2.43600)/14.1200));
RATES[27] = (ALGEBRAIC[3] - STATES[27])/ALGEBRAIC[17];
ALGEBRAIC[4] = 1.00000/(1.00000+exp((STATES[20]+6.00000)/- 8.60000));
ALGEBRAIC[18] = 9.00000/(1.00000+exp((STATES[20]+5.00000)/12.0000))+0.500000;
RATES[29] = (ALGEBRAIC[4] - STATES[29])/ALGEBRAIC[18];
ALGEBRAIC[5] = 1.00000/(1.00000+exp((STATES[20]+7.50000)/10.0000));
ALGEBRAIC[19] = 590.000/(1.00000+exp((STATES[20]+60.0000)/10.0000))+3050.00;
RATES[30] = (ALGEBRAIC[5] - STATES[30])/ALGEBRAIC[19];
ALGEBRAIC[8] = 1.00000/pow(1.00000+exp(- (56.8600+STATES[20])/9.03000), 2.00000);
ALGEBRAIC[22] =  0.129200*exp(- pow((STATES[20]+45.7900)/15.5400, 2.00000))+ 0.0648700*exp(- pow((STATES[20] - 4.82300)/51.1200, 2.00000));
RATES[33] = (ALGEBRAIC[8] - STATES[33])/ALGEBRAIC[22];
ALGEBRAIC[10] = ( 0.320000*(STATES[20]+47.1300))/(1.00000 - exp( - 0.100000*(STATES[20]+47.1300)));
ALGEBRAIC[23] =  0.0800000*exp(- STATES[20]/11.0000);
RATES[35] =  ALGEBRAIC[10]*(1.00000 - STATES[35]) -  ALGEBRAIC[23]*STATES[35];
ALGEBRAIC[11] = 1.00000/(1.00000+exp(- (STATES[20]+1.00000)/11.0000));
ALGEBRAIC[24] =  3.50000*exp(- pow(STATES[20]/30.0000, 2.00000))+1.50000;
RATES[36] = (ALGEBRAIC[11] - STATES[36])/ALGEBRAIC[24];
ALGEBRAIC[12] = 1.00000/(1.00000+exp((STATES[20]+40.5000)/11.5000));
ALGEBRAIC[25] =  25.6350*exp(- pow((STATES[20]+52.4500)/15.8827, 2.00000))+24.1400;
RATES[37] = (ALGEBRAIC[12] - STATES[37])/ALGEBRAIC[25];
RATES[3] =  ( CONSTANTS[16]*STATES[12])*(CONSTANTS[128] - STATES[3]) -  CONSTANTS[8]*STATES[3];
RATES[4] =  ( CONSTANTS[16]*STATES[13])*(CONSTANTS[133] - STATES[4]) -  CONSTANTS[8]*STATES[4];
ALGEBRAIC[27] = 1.00000/pow(1.00000+exp((STATES[20]+71.5500)/7.43000), 2.00000);
ALGEBRAIC[6] =  (STATES[20]>=- 40.0000 ? 0.00000 :  0.0570000*exp(- (STATES[20]+80.0000)/6.80000))*1.00000;
ALGEBRAIC[20] =  (STATES[20]>=- 40.0000 ? 0.770000/( 0.130000*(1.00000+exp(- (STATES[20]+10.6600)/11.1000))) :  2.70000*exp( 0.0790000*STATES[20])+ ( 3.10000*pow(10.0000, 5.00000))*exp( 0.348500*STATES[20]))*1.00000;
ALGEBRAIC[30] = 1.00000/(ALGEBRAIC[6]+ALGEBRAIC[20]);
RATES[31] = (ALGEBRAIC[27] - STATES[31])/ALGEBRAIC[30];
ALGEBRAIC[28] = 1.00000/pow(1.00000+exp((STATES[20]+71.5500)/7.43000), 2.00000);
ALGEBRAIC[7] =  (STATES[20]>=- 40.0000 ? 0.00000 :  (( ( ( - 2.54280*pow(10.0000, 4.00000))*exp( 0.244400*STATES[20]) -  ( 6.94800*pow(10.0000, - 6.00000))*exp( - 0.0439100*STATES[20]))*(STATES[20]+37.7800))/(1.00000+exp( 0.311000*(STATES[20]+79.2300))))*1.00000)*1.00000;
ALGEBRAIC[21] =  (STATES[20]>=- 40.0000 ? ( 0.600000*exp( 0.0570000*STATES[20]))/(1.00000+exp( - 0.100000*(STATES[20]+32.0000))) : ( 0.0242400*exp( - 0.0105200*STATES[20]))/(1.00000+exp( - 0.137800*(STATES[20]+40.1400))))*1.00000;
ALGEBRAIC[31] = 1.00000/(ALGEBRAIC[7]+ALGEBRAIC[21]);
RATES[32] = (ALGEBRAIC[28] - STATES[32])/ALGEBRAIC[31];
ALGEBRAIC[13] = ((1.00000 - STATES[40]) - STATES[39]) - STATES[38];
ALGEBRAIC[26] = CONSTANTS[88] - (CONSTANTS[88] - CONSTANTS[89])/(1.00000+pow(CONSTANTS[92]/STATES[18], 2.50000));
ALGEBRAIC[29] =  CONSTANTS[94]*ALGEBRAIC[26];
ALGEBRAIC[32] = CONSTANTS[122]/ALGEBRAIC[26];
RATES[38] = ( ( ALGEBRAIC[29]*STATES[12])*STATES[39] -  CONSTANTS[95]*STATES[38]) - ( CONSTANTS[96]*STATES[38] -  ( ALGEBRAIC[32]*pow(STATES[12], 2.00000))*ALGEBRAIC[13]);
RATES[39] = ( ( ALGEBRAIC[32]*pow(STATES[12], 2.00000))*STATES[40] -  CONSTANTS[96]*STATES[39]) - ( ( ALGEBRAIC[29]*STATES[12])*STATES[39] -  CONSTANTS[95]*STATES[38]);
RATES[40] = ( CONSTANTS[95]*ALGEBRAIC[13] -  ( ALGEBRAIC[29]*STATES[12])*STATES[40]) - ( ( ALGEBRAIC[32]*pow(STATES[12], 2.00000))*STATES[40] -  CONSTANTS[96]*STATES[39]);
RATES[5] =  ( CONSTANTS[17]*STATES[12])*(CONSTANTS[129] - STATES[5]) -  CONSTANTS[9]*STATES[5];
RATES[6] =  ( CONSTANTS[17]*STATES[13])*(CONSTANTS[134] - STATES[6]) -  CONSTANTS[9]*STATES[6];
RATES[7] =  ( CONSTANTS[18]*STATES[11])*(CONSTANTS[1] - STATES[7]) -  CONSTANTS[10]*STATES[7];
RATES[8] =  ( CONSTANTS[19]*STATES[11])*((CONSTANTS[2] - STATES[8]) - STATES[9]) -  CONSTANTS[11]*STATES[8];
RATES[9] =  ( CONSTANTS[20]*CONSTANTS[22])*((CONSTANTS[2] - STATES[8]) - STATES[9]) -  CONSTANTS[12]*STATES[9];
RATES[10] =  ( CONSTANTS[21]*STATES[11])*(CONSTANTS[3] - STATES[10]) -  CONSTANTS[102]*STATES[10];
RATES[14] =  ( CONSTANTS[27]*STATES[16])*(CONSTANTS[24] - STATES[14]) -  CONSTANTS[26]*STATES[14];
RATES[15] =  ( CONSTANTS[27]*STATES[17])*(CONSTANTS[25] - STATES[15]) -  CONSTANTS[26]*STATES[15];
RATES[19] =  ( CONSTANTS[33]*STATES[18])*(CONSTANTS[135] - STATES[19]) -  CONSTANTS[32]*STATES[19];
ALGEBRAIC[33] = RATES[5]+RATES[3];
ALGEBRAIC[80] =  ((1.00000/CONSTANTS[109])/2.00000)*log(CONSTANTS[51]/STATES[12]);
ALGEBRAIC[81] =  ( CONSTANTS[42]*CONSTANTS[41])*(STATES[20] - ALGEBRAIC[80]);
ALGEBRAIC[36] =  (( ( ( CONSTANTS[105]*4.00000)*( ( STATES[20]*CONSTANTS[31])*CONSTANTS[109]))*( ( 0.341000*STATES[12])*exp( ( 2.00000*STATES[20])*CONSTANTS[109]) -  0.341000*CONSTANTS[51]))/(exp( ( 2.00000*STATES[20])*CONSTANTS[109]) - 1.00000))*CONSTANTS[44];
ALGEBRAIC[37] =  ( ( ( ( ( CONSTANTS[50]*ALGEBRAIC[36])*STATES[21])*STATES[22])*((1.00000 - STATES[23])+CONSTANTS[46]))*pow(CONSTANTS[43], CONSTANTS[132]))*0.450000;
ALGEBRAIC[59] = 1.00000/(1.00000+pow(CONSTANTS[66]/STATES[12], 2.00000));
ALGEBRAIC[61] =  ( exp( ( CONSTANTS[73]*STATES[20])*CONSTANTS[109])*pow(STATES[16], 3.00000))*CONSTANTS[51];
ALGEBRAIC[62] =  ( exp( ( (CONSTANTS[73] - 1.00000)*STATES[20])*CONSTANTS[109])*pow(CONSTANTS[53], 3.00000))*STATES[12];
ALGEBRAIC[63] = ((( ( CONSTANTS[67]*pow(CONSTANTS[53], 3.00000))*(1.00000+pow(STATES[16]/CONSTANTS[69], 3.00000))+ ( pow(CONSTANTS[70], 3.00000)*STATES[12])*(1.00000+STATES[12]/CONSTANTS[67]))+ CONSTANTS[68]*pow(STATES[16], 3.00000))+ pow(STATES[16], 3.00000)*CONSTANTS[51])+ pow(CONSTANTS[53], 3.00000)*STATES[12];
ALGEBRAIC[64] = (( ( ( ( CONSTANTS[42]*CONSTANTS[116])*pow(CONSTANTS[71], CONSTANTS[132]))*ALGEBRAIC[59])*(ALGEBRAIC[61] - ALGEBRAIC[62]))/ALGEBRAIC[63])/(1.00000+ CONSTANTS[72]*exp( ( (CONSTANTS[73] - 1.00000)*STATES[20])*CONSTANTS[109]));
ALGEBRAIC[74] = pow( STATES[12]*1.00000, 1.60000);
ALGEBRAIC[75] = ( ( ( CONSTANTS[42]*pow(CONSTANTS[82], CONSTANTS[132]))*CONSTANTS[80])*ALGEBRAIC[74])/(ALGEBRAIC[74]+CONSTANTS[104]);
ALGEBRAIC[82] = ((ALGEBRAIC[37]+ALGEBRAIC[81])+ALGEBRAIC[75]) -  2.00000*ALGEBRAIC[64];
ALGEBRAIC[83] =  ( CONSTANTS[97]*STATES[39])*(STATES[18] - STATES[12]);
ALGEBRAIC[85] =  ( (1.00000+ 0.250000*CONSTANTS[34])*(STATES[18] - STATES[12]))*CONSTANTS[86];
RATES[12] = (((( - ALGEBRAIC[82]*CONSTANTS[29])/( ( CONSTANTS[123]*2.00000)*CONSTANTS[31])+ (CONSTANTS[30]/CONSTANTS[123])*(STATES[13] - STATES[12])) - ALGEBRAIC[33])+( ALGEBRAIC[83]*CONSTANTS[131])/CONSTANTS[123])+( ALGEBRAIC[85]*CONSTANTS[126])/CONSTANTS[123];
ALGEBRAIC[35] = (((((RATES[10]+RATES[8])+RATES[9])+RATES[0])+RATES[1])+RATES[2])+RATES[7];
ALGEBRAIC[87] = ( ( pow(CONSTANTS[90], CONSTANTS[132])*CONSTANTS[91])*(pow(STATES[11]/CONSTANTS[121], CONSTANTS[93]) - pow(STATES[18]/CONSTANTS[87], CONSTANTS[93])))/((1.00000+pow(STATES[11]/CONSTANTS[121], CONSTANTS[93]))+pow(STATES[18]/CONSTANTS[87], CONSTANTS[93]));
RATES[11] = (( - ALGEBRAIC[87]*CONSTANTS[131])/CONSTANTS[126] - ALGEBRAIC[35])+ (CONSTANTS[28]/CONSTANTS[126])*(STATES[13] - STATES[11]);
ALGEBRAIC[34] = RATES[6]+RATES[4];
ALGEBRAIC[84] =  ((1.00000/CONSTANTS[109])/2.00000)*log(CONSTANTS[51]/STATES[13]);
ALGEBRAIC[86] =  ( CONSTANTS[127]*CONSTANTS[41])*(STATES[20] - ALGEBRAIC[84]);
ALGEBRAIC[38] =  (( ( ( CONSTANTS[105]*4.00000)*( ( STATES[20]*CONSTANTS[31])*CONSTANTS[109]))*( ( 0.341000*STATES[13])*exp( ( 2.00000*STATES[20])*CONSTANTS[109]) -  0.341000*CONSTANTS[51]))/(exp( ( 2.00000*STATES[20])*CONSTANTS[109]) - 1.00000))*CONSTANTS[44];
ALGEBRAIC[39] =  ( ( ( ( ( CONSTANTS[108]*ALGEBRAIC[38])*STATES[21])*STATES[22])*((1.00000 - STATES[24])+CONSTANTS[45]))*pow(CONSTANTS[43], CONSTANTS[132]))*0.450000;
ALGEBRAIC[60] = 1.00000/(1.00000+pow(CONSTANTS[66]/STATES[13], 2.00000));
ALGEBRAIC[65] =  ( exp( ( CONSTANTS[73]*STATES[20])*CONSTANTS[109])*pow(STATES[17], 3.00000))*CONSTANTS[51];
ALGEBRAIC[66] =  ( exp( ( (CONSTANTS[73] - 1.00000)*STATES[20])*CONSTANTS[109])*pow(CONSTANTS[53], 3.00000))*STATES[13];
ALGEBRAIC[67] = ((( ( CONSTANTS[67]*pow(CONSTANTS[53], 3.00000))*(1.00000+pow(STATES[17]/CONSTANTS[69], 3.00000))+ ( pow(CONSTANTS[70], 3.00000)*STATES[13])*(1.00000+STATES[13]/CONSTANTS[67]))+ CONSTANTS[68]*pow(STATES[17], 3.00000))+ pow(STATES[17], 3.00000)*CONSTANTS[51])+ pow(CONSTANTS[53], 3.00000)*STATES[13];
ALGEBRAIC[68] = (( ( ( ( CONSTANTS[127]*CONSTANTS[116])*pow(CONSTANTS[71], CONSTANTS[132]))*ALGEBRAIC[60])*(ALGEBRAIC[65] - ALGEBRAIC[66]))/ALGEBRAIC[67])/(1.00000+ CONSTANTS[72]*exp( ( (CONSTANTS[73] - 1.00000)*STATES[20])*CONSTANTS[109]));
ALGEBRAIC[76] = pow( STATES[13]*1.00000, 1.60000);
ALGEBRAIC[77] = ( ( ( CONSTANTS[127]*pow(CONSTANTS[82], CONSTANTS[132]))*CONSTANTS[80])*ALGEBRAIC[76])/(ALGEBRAIC[76]+CONSTANTS[124]);
ALGEBRAIC[89] = ((ALGEBRAIC[39]+ALGEBRAIC[86])+ALGEBRAIC[77]) -  2.00000*ALGEBRAIC[68];
RATES[13] = ((( - ALGEBRAIC[89]*CONSTANTS[29])/( ( CONSTANTS[130]*2.00000)*CONSTANTS[31])+ (CONSTANTS[30]/CONSTANTS[130])*(STATES[12] - STATES[13]))+ (CONSTANTS[28]/CONSTANTS[130])*(STATES[11] - STATES[13])) - ALGEBRAIC[34];
RATES[18] = (ALGEBRAIC[87] - (( ALGEBRAIC[85]*CONSTANTS[126])/CONSTANTS[131]+ALGEBRAIC[83])) - RATES[19];
ALGEBRAIC[43] =  (( ( ( ( CONSTANTS[107]*STATES[20])*CONSTANTS[31])*CONSTANTS[109])*( ( 0.750000*STATES[16])*exp( STATES[20]*CONSTANTS[109]) -  0.750000*CONSTANTS[53]))/(exp( STATES[20]*CONSTANTS[109]) - 1.00000))*CONSTANTS[44];
ALGEBRAIC[44] =  ( ( ( ( ( CONSTANTS[50]*ALGEBRAIC[43])*STATES[21])*STATES[22])*((1.00000 - STATES[23])+CONSTANTS[46]))*pow(CONSTANTS[43], CONSTANTS[132]))*0.450000;
ALGEBRAIC[102] =  (1.00000/CONSTANTS[109])*log(CONSTANTS[53]/STATES[16]);
ALGEBRAIC[103] =  ( ( ( ( CONSTANTS[42]*CONSTANTS[115])*pow(STATES[33], 3.00000))*STATES[31])*STATES[32])*(STATES[20] - ALGEBRAIC[102]);
ALGEBRAIC[104] =  ( CONSTANTS[42]*CONSTANTS[64])*(STATES[20] - ALGEBRAIC[102]);
ALGEBRAIC[69] = 1.00000/((1.00000+ 0.124500*exp( ( - 0.100000*STATES[20])*CONSTANTS[109]))+ ( 0.0365000*CONSTANTS[118])*exp( - STATES[20]*CONSTANTS[109]));
ALGEBRAIC[71] = (( ( ( CONSTANTS[42]*CONSTANTS[74])*ALGEBRAIC[69])*CONSTANTS[52])/(1.00000+pow(CONSTANTS[117]/STATES[16], 4.00000)))/(CONSTANTS[52]+CONSTANTS[75]);
ALGEBRAIC[105] =  ( ( ( CONSTANTS[42]*CONSTANTS[119])*pow(STATES[35], 3.00000))*STATES[34])*(STATES[20] - ALGEBRAIC[102]);
ALGEBRAIC[114] = ((((ALGEBRAIC[103]+ALGEBRAIC[104])+ 3.00000*ALGEBRAIC[64])+ 3.00000*ALGEBRAIC[71])+ALGEBRAIC[44])+ALGEBRAIC[105];
RATES[16] = (( - ALGEBRAIC[114]*CONSTANTS[29])/( CONSTANTS[123]*CONSTANTS[31])+ (CONSTANTS[36]/CONSTANTS[123])*(STATES[17] - STATES[16])) - RATES[14];
ALGEBRAIC[45] =  (( ( ( ( CONSTANTS[107]*STATES[20])*CONSTANTS[31])*CONSTANTS[109])*( ( 0.750000*STATES[17])*exp( STATES[20]*CONSTANTS[109]) -  0.750000*CONSTANTS[53]))/(exp( STATES[20]*CONSTANTS[109]) - 1.00000))*CONSTANTS[44];
ALGEBRAIC[46] =  ( ( ( ( ( CONSTANTS[108]*ALGEBRAIC[45])*STATES[21])*STATES[22])*((1.00000 - STATES[24])+CONSTANTS[45]))*pow(CONSTANTS[43], CONSTANTS[132]))*0.450000;
ALGEBRAIC[106] =  (1.00000/CONSTANTS[109])*log(CONSTANTS[53]/STATES[17]);
ALGEBRAIC[107] =  ( ( ( ( CONSTANTS[127]*CONSTANTS[115])*pow(STATES[33], 3.00000))*STATES[31])*STATES[32])*(STATES[20] - ALGEBRAIC[106]);
ALGEBRAIC[109] =  ( CONSTANTS[127]*CONSTANTS[64])*(STATES[20] - ALGEBRAIC[106]);
ALGEBRAIC[72] = (( ( ( CONSTANTS[127]*CONSTANTS[74])*ALGEBRAIC[69])*CONSTANTS[52])/(1.00000+pow(CONSTANTS[117]/STATES[17], 4.00000)))/(CONSTANTS[52]+CONSTANTS[75]);
ALGEBRAIC[111] =  ( ( ( CONSTANTS[127]*CONSTANTS[119])*pow(STATES[35], 3.00000))*STATES[34])*(STATES[20] - ALGEBRAIC[106]);
ALGEBRAIC[115] = ((((ALGEBRAIC[107]+ALGEBRAIC[109])+ 3.00000*ALGEBRAIC[68])+ 3.00000*ALGEBRAIC[72])+ALGEBRAIC[46])+ALGEBRAIC[111];
RATES[17] = ((( - ALGEBRAIC[115]*CONSTANTS[29])/( CONSTANTS[130]*CONSTANTS[31])+ (CONSTANTS[36]/CONSTANTS[130])*(STATES[16] - STATES[17]))+ (CONSTANTS[37]/CONSTANTS[130])*(STATES[28] - STATES[17])) - RATES[15];
ALGEBRAIC[90] = ALGEBRAIC[82]+ALGEBRAIC[89];
ALGEBRAIC[47] =  CONSTANTS[54]*(STATES[20] - CONSTANTS[125]);
ALGEBRAIC[49] =  (( CONSTANTS[42]*CONSTANTS[55])/(1.00000+CONSTANTS[56]/STATES[12]))*(STATES[20] - CONSTANTS[125]);
ALGEBRAIC[51] =  (( CONSTANTS[127]*CONSTANTS[55])/(1.00000+CONSTANTS[56]/STATES[13]))*(STATES[20] - CONSTANTS[125]);
ALGEBRAIC[52] = ALGEBRAIC[49]+ALGEBRAIC[51];
ALGEBRAIC[78] = ALGEBRAIC[52]+ALGEBRAIC[47];
ALGEBRAIC[116] = ALGEBRAIC[114]+ALGEBRAIC[115];
ALGEBRAIC[41] =  (( ( ( ( CONSTANTS[106]*STATES[20])*CONSTANTS[31])*CONSTANTS[109])*( ( 0.750000*STATES[25])*exp( STATES[20]*CONSTANTS[109]) -  0.750000*CONSTANTS[52]))/(exp( STATES[20]*CONSTANTS[109]) - 1.00000))*CONSTANTS[44];
ALGEBRAIC[42] =  ( ( ( ( ALGEBRAIC[41]*STATES[21])*STATES[22])*( CONSTANTS[50]*(CONSTANTS[46]+(1.00000 - STATES[23]))+ CONSTANTS[108]*(CONSTANTS[45]+(1.00000 - STATES[24]))))*pow(CONSTANTS[43], CONSTANTS[132]))*0.450000;
ALGEBRAIC[91] =  (1.00000/CONSTANTS[109])*log(CONSTANTS[52]/STATES[25]);
ALGEBRAIC[92] =  1.00000*(1.02000/(1.00000+exp( 0.238500*((STATES[20] - ALGEBRAIC[91]) - 59.2150))));
ALGEBRAIC[93] =  1.00000*(( 0.491240*exp( 0.0803200*((STATES[20]+5.47600) - ALGEBRAIC[91]))+exp( 0.0617500*((STATES[20] - ALGEBRAIC[91]) - 594.310)))/(1.00000+exp( - 0.514300*((STATES[20] - ALGEBRAIC[91])+4.75300))));
ALGEBRAIC[94] = ALGEBRAIC[92]/(ALGEBRAIC[92]+ALGEBRAIC[93]);
ALGEBRAIC[95] =  ( CONSTANTS[110]*ALGEBRAIC[94])*(STATES[20] - ALGEBRAIC[91]);
ALGEBRAIC[53] = 1.00000/(1.00000+exp(7.48800 - STATES[20]/5.98000));
ALGEBRAIC[96] =  ( ( CONSTANTS[42]*CONSTANTS[58])*ALGEBRAIC[53])*(STATES[20] - ALGEBRAIC[91]);
ALGEBRAIC[97] =  ( ( CONSTANTS[127]*CONSTANTS[58])*ALGEBRAIC[53])*(STATES[20] - ALGEBRAIC[91]);
ALGEBRAIC[98] = ALGEBRAIC[96]+ALGEBRAIC[97];
ALGEBRAIC[54] = 1.00000/(1.00000+exp((STATES[20]+74.0000)/24.0000));
ALGEBRAIC[99] =  ( ( CONSTANTS[111]*STATES[26])*ALGEBRAIC[54])*(STATES[20] - ALGEBRAIC[91]);
ALGEBRAIC[55] =  (1.00000/CONSTANTS[109])*log((CONSTANTS[52]+ CONSTANTS[61]*CONSTANTS[53])/(STATES[25]+ CONSTANTS[61]*STATES[28]));
ALGEBRAIC[56] =  ( ( CONSTANTS[42]*CONSTANTS[112])*pow(STATES[27], 2.00000))*(STATES[20] - ALGEBRAIC[55]);
ALGEBRAIC[57] =  ( ( CONSTANTS[127]*CONSTANTS[113])*pow(STATES[27], 2.00000))*(STATES[20] - ALGEBRAIC[55]);
ALGEBRAIC[58] = ALGEBRAIC[56]+ALGEBRAIC[57];
ALGEBRAIC[100] =  ( ( CONSTANTS[114]*STATES[29])*STATES[30])*(STATES[20] - ALGEBRAIC[91]);
ALGEBRAIC[73] = ALGEBRAIC[71]+ALGEBRAIC[72];
ALGEBRAIC[101] =  ( ( CONSTANTS[120]*STATES[36])*STATES[37])*(STATES[20] - ALGEBRAIC[91]);
ALGEBRAIC[113] = ((((((ALGEBRAIC[101]+ALGEBRAIC[99])+ALGEBRAIC[58])+ALGEBRAIC[95]) -  2.00000*ALGEBRAIC[73])+ALGEBRAIC[42])+ALGEBRAIC[98])+ALGEBRAIC[100];
ALGEBRAIC[117] = ((ALGEBRAIC[116]+ALGEBRAIC[78])+ALGEBRAIC[90])+ALGEBRAIC[113];
ALGEBRAIC[118] = ((TIME - CONSTANTS[100]) -  CONSTANTS[101]*floor((TIME - CONSTANTS[100])/CONSTANTS[101])<CONSTANTS[99] ? 1.00000 : 0.00000);
ALGEBRAIC[119] =  ALGEBRAIC[118]*CONSTANTS[98];
RATES[20] = - (ALGEBRAIC[117]+ALGEBRAIC[119]);
ALGEBRAIC[40] = ALGEBRAIC[37]+ALGEBRAIC[39];
ALGEBRAIC[48] = ALGEBRAIC[44]+ALGEBRAIC[46]; 
ALGEBRAIC[50] = (ALGEBRAIC[40]+ALGEBRAIC[42])+ALGEBRAIC[48];
ALGEBRAIC[70] = ALGEBRAIC[64]+ALGEBRAIC[68];
ALGEBRAIC[79] = ALGEBRAIC[75]+ALGEBRAIC[77];
ALGEBRAIC[88] = ALGEBRAIC[81]+ALGEBRAIC[86];
ALGEBRAIC[108] = ALGEBRAIC[103]+ALGEBRAIC[107];
ALGEBRAIC[110] = ALGEBRAIC[104]+ALGEBRAIC[109];
ALGEBRAIC[112] = ALGEBRAIC[105]+ALGEBRAIC[111];
}

void grandi_2011_atrial_with_meta::solveAnalytical(double dt)
{
}
