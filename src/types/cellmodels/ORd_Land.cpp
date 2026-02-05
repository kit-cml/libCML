/*
   There are a total of 200 entries in the algebraic variable array.
   There are a total of 49 entries in each of the rate and state variable arrays.
   There are a total of 206 entries in the constant variable array.
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "ORd_Land.hpp"

ORd_Land::ORd_Land()
{
  algebraic_size = 219;
  constants_size = 231;
  states_size = 55;
  ALGEBRAIC = new double[algebraic_size];
  CONSTANTS = new double[constants_size];
  RATES = new double[states_size];
  STATES = new double[states_size];

}

ORd_Land::~ORd_Land()
{
  delete[] ALGEBRAIC;
  delete[] CONSTANTS;
  delete[] RATES;
  delete[] STATES;
}

void ORd_Land::___initConsts(double type)
{
  CONSTANTS[celltype] = type;
  CONSTANTS[nao] = 140;
  CONSTANTS[cao] = 1.8;
  CONSTANTS[ko] = 5.4;
  CONSTANTS[R] = 8314;
  CONSTANTS[T] = 310;
  CONSTANTS[F] = 96485;
  CONSTANTS[zna] = 1;
  CONSTANTS[zca] = 2;
  CONSTANTS[zk] = 1;
  CONSTANTS[L] = 0.01;
  CONSTANTS[rad] = 0.0011;
  STATES[V] = -88.00190;
  CONSTANTS[stim_start] = 10;
#ifdef TISSUE
  CONSTANTS[stim_start] = 0.4;
#endif
  CONSTANTS[stim_end] = 100000000000000000;
  CONSTANTS[amp] = -80;
  CONSTANTS[BCL] = 1000;
  CONSTANTS[duration] = 0.5;
  CONSTANTS[KmCaMK] = 0.15;
  CONSTANTS[aCaMK] = 0.05;
  CONSTANTS[bCaMK] = 0.00068;
  CONSTANTS[CaMKo] = 0.05;
  CONSTANTS[KmCaM] = 0.0015;
  STATES[CaMKt] = 0.0125840447;
  STATES[cass] = 8.49e-05;
  CONSTANTS[cmdnmax_b] = 0.05;
  CONSTANTS[kmcmdn] = 0.00238;
  CONSTANTS[trpnmax] = 0.07;
  CONSTANTS[kmtrpn] = 0.0005;
  CONSTANTS[BSRmax] = 0.047;
  CONSTANTS[KmBSR] = 0.00087;
  CONSTANTS[BSLmax] = 1.124;
  CONSTANTS[KmBSL] = 0.0087;
  CONSTANTS[csqnmax] = 10;
  CONSTANTS[kmcsqn] = 0.8;
  STATES[nai] = 7.268004498;
  STATES[nass] = 7.268089977;
  STATES[ki] = 144.6555918;
  STATES[kss] = 144.6555651;
  STATES[cansr] = 1.619574538;
  STATES[cajsr] = 1.571234014;
  STATES[cai] = 8.6e-05;
  CONSTANTS[cm] = 1;
  CONSTANTS[PKNa] = 0.01833;
  CONSTANTS[mssV1] = 39.57;
  CONSTANTS[mssV2] = 9.871;
  CONSTANTS[mtV1] = 11.64;
  CONSTANTS[mtV2] = 34.77;
  CONSTANTS[mtD1] = 6.765;
  CONSTANTS[mtD2] = 8.552;
  CONSTANTS[mtV3] = 77.42;
  CONSTANTS[mtV4] = 5.955;
  STATES[m] = 0.007344121102;
  CONSTANTS[hssV1] = 82.9;
  CONSTANTS[hssV2] = 6.086;
  CONSTANTS[Ahf] = 0.99;
  STATES[hf] = 0.6981071913;
  STATES[hs] = 0.6980895801;
  CONSTANTS[GNa] = 75;
  CONSTANTS[shift_INa_inact] = 0;
  STATES[j] = 0.6979908432;
  STATES[hsp] = 0.4549485525;
  STATES[jp] = 0.6979245865;
  STATES[mL] = 0.0001882617273;
  CONSTANTS[thL] = 200;
  STATES[hL] = 0.5008548855;
  STATES[hLp] = 0.2693065357;
  CONSTANTS[GNaL_b] = 0.019957499999999975;
  CONSTANTS[Gto_b] = 0.02;
  STATES[a] = 0.001001097687;
  STATES[iF] = 0.9995541745;
  STATES[iS] = 0.5865061736;
  STATES[ap] = 0.0005100862934;
  STATES[iFp] = 0.9995541823;
  STATES[iSp] = 0.6393399482;
  CONSTANTS[Kmn] = 0.002;
  CONSTANTS[k2n] = 1000;
  CONSTANTS[PCa_b] = 0.0001007;
  STATES[d] = 2.34e-9;
  STATES[ff] = 0.9999999909;
  STATES[fs] = 0.9102412777;
  STATES[fcaf] = 0.9999999909;
  STATES[fcas] = 0.9998046777;
  STATES[jca] = 0.9999738312;
  STATES[ffp] = 0.9999999909;
  STATES[fcafp] = 0.9999999909;
  STATES[nca] = 0.002749414044;
  CONSTANTS[GKr_b] = 0.04658545454545456;
  STATES[IC1] = 0.999637;
  STATES[IC2] = 6.83208e-05;
  STATES[C1] = 1.80145e-08;
  STATES[C2] = 8.26619e-05;
  STATES[O] = 0.00015551;
  STATES[IO] = 5.67623e-05;
  STATES[IObound] = 0;
  STATES[Obound] = 0;
  STATES[Cbound] = 0;
  STATES[D] = 0;
  CONSTANTS[A1] = 0.0264;
  CONSTANTS[B1] = 4.631E-05;
  CONSTANTS[q1] = 4.843;
  CONSTANTS[A2] = 4.986E-06;
  CONSTANTS[B2] = -0.004226;
  CONSTANTS[q2] = 4.23;
  CONSTANTS[A3] = 0.001214;
  CONSTANTS[B3] = 0.008516;
  CONSTANTS[q3] = 4.962;
  CONSTANTS[A4] = 1.854E-05;
  CONSTANTS[B4] = -0.04641;
  CONSTANTS[q4] = 3.769;
  CONSTANTS[A11] = 0.0007868;
  CONSTANTS[B11] = 1.535E-08;
  CONSTANTS[q11] = 4.942;
  CONSTANTS[A21] = 5.455E-06;
  CONSTANTS[B21] = -0.1688;
  CONSTANTS[q21] = 4.156;
  CONSTANTS[A31] = 0.005509;
  CONSTANTS[B31] = 7.771E-09;
  CONSTANTS[q31] = 4.22;
  CONSTANTS[A41] = 0.001416;
  CONSTANTS[B41] = -0.02877;
  CONSTANTS[q41] = 1.459;
  CONSTANTS[A51] = 0.4492;
  CONSTANTS[B51] = 0.008595;
  CONSTANTS[q51] = 5;
  CONSTANTS[A52] = 0.3181;
  CONSTANTS[B52] = 3.613E-08;
  CONSTANTS[q52] = 4.663;
  CONSTANTS[A53] = 0.149;
  CONSTANTS[B53] = 0.004668;
  CONSTANTS[q53] = 2.412;
  CONSTANTS[A61] = 0.01241;
  CONSTANTS[B61] = 0.1725;
  CONSTANTS[q61] = 5.568;
  CONSTANTS[A62] = 0.3226;
  CONSTANTS[B62] = -0.0006575;
  CONSTANTS[q62] = 5;
  CONSTANTS[A63] = 0.008978;
  CONSTANTS[B63] = -0.02215;
  CONSTANTS[q63] = 5.682;
  CONSTANTS[Kmax] = 0;
  CONSTANTS[Ku] = 0;
  CONSTANTS[n] = 1;
  CONSTANTS[halfmax] = 1;
  CONSTANTS[Kt] = 0;
  CONSTANTS[Vhalf] = 1;
  CONSTANTS[Temp] = 37;
  CONSTANTS[GKs_b] = 0.006358000000000001;
  CONSTANTS[txs1_max] = 817.3;
  STATES[xs1] = 0.2707758025;
  STATES[xs2] = 0.0001928503426;
  CONSTANTS[GK1_b] = 0.3239783999999998;
  STATES[xk1] = 0.9967597594;
  CONSTANTS[kna1] = 15;
  CONSTANTS[kna2] = 5;
  CONSTANTS[kna3] = 88.12;
  CONSTANTS[kasymm] = 12.5;
  CONSTANTS[wna] = 6e4;
  CONSTANTS[wca] = 6e4;
  CONSTANTS[wnaca] = 5e3;
  CONSTANTS[kcaon] = 1.5e6;
  CONSTANTS[kcaoff] = 5e3;
  CONSTANTS[qna] = 0.5224;
  CONSTANTS[qca] = 0.167;
  CONSTANTS[KmCaAct] = 150e-6;
  CONSTANTS[Gncx_b] = 0.0008;
  CONSTANTS[k1p] = 949.5;
  CONSTANTS[k1m] = 182.4;
  CONSTANTS[k2p] = 687.2;
  CONSTANTS[k2m] = 39.4;
  CONSTANTS[k3p] = 1899;
  CONSTANTS[k3m] = 79300;
  CONSTANTS[k4p] = 639;
  CONSTANTS[k4m] = 40;
  CONSTANTS[Knai0] = 9.073;
  CONSTANTS[Knao0] = 27.78;
  CONSTANTS[delta] = -0.155;
  CONSTANTS[Kki] = 0.5;
  CONSTANTS[Kko] = 0.3582;
  CONSTANTS[MgADP] = 0.05;
  CONSTANTS[MgATP] = 9.8;
  CONSTANTS[Kmgatp] = 1.698e-7;
  CONSTANTS[H] = 1e-7;
  CONSTANTS[eP] = 4.2;
  CONSTANTS[Khp] = 1.698e-7;
  CONSTANTS[Knap] = 224;
  CONSTANTS[Kxkur] = 292;
  CONSTANTS[Pnak_b] = 30;
  CONSTANTS[GKb_b] = 0.003;
  CONSTANTS[PNab] = 3.75e-10;
  CONSTANTS[PCab] = 2.5e-8;
  CONSTANTS[GpCa] = 0.0005;
  CONSTANTS[KmCap] = 0.0005;
  CONSTANTS[bt] = 4.75;
  STATES[Jrelnp] = 2.5e-7;
  STATES[Jrelp] = 3.12e-7;
  CONSTANTS[Jrel_b] = 1.0;
  CONSTANTS[Jup_b] = 1.0;
  // CVAR: 2 scaling factor to satisfy CVar (Jtr and Jleak)
  CONSTANTS[Jtr_b] = 1.0;
  CONSTANTS[Jleak_b] = 1.0;
  CONSTANTS[frt] = CONSTANTS[F] / (CONSTANTS[R] * CONSTANTS[T]);
  CONSTANTS[cmdnmax] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[cmdnmax_b] * 1.30000 : CONSTANTS[cmdnmax_b]);
  CONSTANTS[Ahs] = 1.00000 - CONSTANTS[Ahf];
  CONSTANTS[thLp] = 3.00000 * CONSTANTS[thL];
  CONSTANTS[GNaL] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GNaL_b] * 0.600000 : CONSTANTS[GNaL_b]);
  CONSTANTS[Gto] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[Gto_b] * 4.00000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[Gto_b] * 4.00000
                                                     : CONSTANTS[Gto_b]);
  CONSTANTS[Aff] = 0.600000;
  CONSTANTS[PCa] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[PCa_b] * 1.20000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[PCa_b] * 1.80000
                                                     : CONSTANTS[PCa_b]);
  CONSTANTS[tjca] = 75.0000;
  CONSTANTS[v0_CaL] = 0.000000;
  CONSTANTS[GKr] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[GKr_b] * 1.30000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[GKr_b] * 0.800000
                                                     : CONSTANTS[GKr_b]);
  CONSTANTS[GKs] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GKs_b] * 1.40000 : CONSTANTS[GKs_b]);
  CONSTANTS[GK1] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[GK1_b] * 1.20000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[GK1_b] * 1.30000
                                                     : CONSTANTS[GK1_b]);
  CONSTANTS[vcell] = 1000.00 * 3.14000 * CONSTANTS[rad] * CONSTANTS[rad] * CONSTANTS[L];
  CONSTANTS[GKb] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GKb_b] * 0.600000 : CONSTANTS[GKb_b]);
  CONSTANTS[v0_Nab] = 0.000000;
  CONSTANTS[v0_Cab] = 0.000000;
  CONSTANTS[a_rel] = 0.500000 * CONSTANTS[bt];
  CONSTANTS[btp] = 1.25000 * CONSTANTS[bt];
  CONSTANTS[upScale] = (CONSTANTS[celltype] == 1.00000 ? 1.30000 : 1.00000);
  CONSTANTS[cnc] = 0.000000;
  CONSTANTS[ffrt] = CONSTANTS[F] * CONSTANTS[frt];
  CONSTANTS[Afs] = 1.00000 - CONSTANTS[Aff];
  CONSTANTS[PCap] = 1.10000 * CONSTANTS[PCa];
  CONSTANTS[PCaNa] = 0.00125000 * CONSTANTS[PCa];
  CONSTANTS[PCaK] = 0.000357400 * CONSTANTS[PCa];
  CONSTANTS[B_1] = 2.00000 * CONSTANTS[frt];
  CONSTANTS[B_2] = CONSTANTS[frt];
  CONSTANTS[B_3] = CONSTANTS[frt];
  CONSTANTS[Ageo] = 2.00000 * 3.14000 * CONSTANTS[rad] * CONSTANTS[rad] + 2.00000 * 3.14000 * CONSTANTS[rad] * CONSTANTS[L];
  CONSTANTS[B_Nab] = CONSTANTS[frt];
  CONSTANTS[B_Cab] = 2.00000 * CONSTANTS[frt];
  CONSTANTS[a_relp] = 0.500000 * CONSTANTS[btp];
  CONSTANTS[PCaNap] = 0.00125000 * CONSTANTS[PCap];
  CONSTANTS[PCaKp] = 0.000357400 * CONSTANTS[PCap];
  CONSTANTS[Acap] = 2.00000 * CONSTANTS[Ageo];
  CONSTANTS[vmyo] = 0.680000 * CONSTANTS[vcell];
  CONSTANTS[vnsr] = 0.0552000 * CONSTANTS[vcell];
  CONSTANTS[vjsr] = 0.00480000 * CONSTANTS[vcell];
  CONSTANTS[vss] = 0.0200000 * CONSTANTS[vcell];
  CONSTANTS[h10_i] = CONSTANTS[kasymm] + 1.00000 + (CONSTANTS[nao] / CONSTANTS[kna1]) * (1.00000 + CONSTANTS[nao] / CONSTANTS[kna2]);
  CONSTANTS[h11_i] = (CONSTANTS[nao] * CONSTANTS[nao]) / (CONSTANTS[h10_i] * CONSTANTS[kna1] * CONSTANTS[kna2]);
  CONSTANTS[h12_i] = 1.00000 / CONSTANTS[h10_i];
  CONSTANTS[k1_i] = CONSTANTS[h12_i] * CONSTANTS[cao] * CONSTANTS[kcaon];
  CONSTANTS[k2_i] = CONSTANTS[kcaoff];
  CONSTANTS[k5_i] = CONSTANTS[kcaoff];
  CONSTANTS[Gncx] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[Gncx_b] * 1.10000
                     : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[Gncx_b] * 1.40000
                                                      : CONSTANTS[Gncx_b]);
  CONSTANTS[h10_ss] = CONSTANTS[kasymm] + 1.00000 + (CONSTANTS[nao] / CONSTANTS[kna1]) * (1.00000 + CONSTANTS[nao] / CONSTANTS[kna2]);
  CONSTANTS[h11_ss] = (CONSTANTS[nao] * CONSTANTS[nao]) / (CONSTANTS[h10_ss] * CONSTANTS[kna1] * CONSTANTS[kna2]);
  CONSTANTS[h12_ss] = 1.00000 / CONSTANTS[h10_ss];
  CONSTANTS[k1_ss] = CONSTANTS[h12_ss] * CONSTANTS[cao] * CONSTANTS[kcaon];
  CONSTANTS[k2_ss] = CONSTANTS[kcaoff];
  CONSTANTS[k5_ss] = CONSTANTS[kcaoff];
  CONSTANTS[b1] = CONSTANTS[k1m] * CONSTANTS[MgADP];
  CONSTANTS[a2] = CONSTANTS[k2p];
  CONSTANTS[a4] = ((CONSTANTS[k4p] * CONSTANTS[MgATP]) / CONSTANTS[Kmgatp]) / (1.00000 + CONSTANTS[MgATP] / CONSTANTS[Kmgatp]);
  CONSTANTS[Pnak] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[Pnak_b] * 0.900000
                     : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[Pnak_b] * 0.700000
                                                      : CONSTANTS[Pnak_b]);

  // Land Model
  CONSTANTS[lambda_rate] = 0;
  CONSTANTS[lambda] = 1.0;
  CONSTANTS[lambda_min] = 0.87;
  CONSTANTS[lambda_max] = 1.2;

  CONSTANTS[perm50] = 0.35;
  CONSTANTS[TRPN_n] = 2;
  CONSTANTS[koff] = 0.1;
  CONSTANTS[dr] = 0.25;
  CONSTANTS[wfrac] = 0.5;

  CONSTANTS[TOT_A] = 25;
  CONSTANTS[ktm_unblock] = 0.04;  // Tomek: 0.021, ORd: 0.04

  CONSTANTS[land_beta_1] = -2.4;
  CONSTANTS[land_beta_0] = 2.3;
  CONSTANTS[gamma_idx] = 0.0085;
  CONSTANTS[gamma_wu] = 0.615;
  CONSTANTS[phi] = 2.23;

  //   bool isSkinned = true;  // Hardcoded for skinned model, change if needed
  //   CONSTANTS[nperm] = isSkinned ? 2.2 : 2.4;
  //   CONSTANTS[ca50] = isSkinned ? 2.5 : 0.805;
  //   CONSTANTS[ca50] = 0.805 + CONSTANTS[land_beta_1] * fmin(0.2, CONSTANTS[lambda] - 1);
  //   CONSTANTS[Tref] = isSkinned ? 40.5 : 120.0;
  //   CONSTANTS[nu] = isSkinned ? 1.0 : 7.0;
  //   CONSTANTS[mu] = isSkinned ? 1.0 : 3.0;

  // Based on Julia code
  CONSTANTS[nperm] = 2.4;  // Tomek: 2.036, ORd: 2.4
  CONSTANTS[ca50] = 0.805 + CONSTANTS[land_beta_1] * fmin(0.2, CONSTANTS[lambda] - 1);
  CONSTANTS[Tref] = 120;
  CONSTANTS[nu] = 7.0;
  CONSTANTS[mu] = 3.0;

  CONSTANTS[k_ws] = 0.004 * CONSTANTS[mu];
  CONSTANTS[k_uw] = 0.026 * CONSTANTS[nu];

  // double y[7] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0};
  STATES[XS] = 0;
  STATES[XW] = 0;
  STATES[Ca_TRPN] = 0;
  STATES[TmBlocked] = 1;
  STATES[ZETAS] = 0;
  STATES[ZETAW] = 0;
}

void ORd_Land::initConsts()
{
	___initConsts(0.);
}

void ORd_Land::initConsts(double type)
{
	___initConsts(type);
}

void ORd_Land::initConsts(double type, double conc, double *ic50, double *herg)
{
	___initConsts(type);
	___applyDrugEffect(conc, ic50);
 if( conc > 10E-14 ) ___applyHERGBinding(conc, herg);
}

void ORd_Land::initConsts(double type, double conc, double *hill, double *herg, double *cvar)
{
  initConsts(type, conc, hill, herg);
  ___applyCVar(cvar);
}

void ORd_Land::computeRates( double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC ) {
  CONSTANTS[cmdnmax] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[cmdnmax_b] * 1.30000 : CONSTANTS[cmdnmax_b]);
  CONSTANTS[GNaL] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GNaL_b] * 0.600000 : CONSTANTS[GNaL_b]);
  CONSTANTS[Gto] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[Gto_b] * 4.00000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[Gto_b] * 4.00000
                                                     : CONSTANTS[Gto_b]);
  CONSTANTS[PCa] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[PCa_b] * 1.20000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[PCa_b] * 2.50000
                                                     : CONSTANTS[PCa_b]);
  CONSTANTS[GKr] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[GKr_b] * 1.30000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[GKr_b] * 0.800000
                                                     : CONSTANTS[GKr_b]);
  CONSTANTS[GKs] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GKs_b] * 1.40000 : CONSTANTS[GKs_b]);
  CONSTANTS[GK1] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[GK1_b] * 1.20000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[GK1_b] * 1.30000
                                                     : CONSTANTS[GK1_b]);
  CONSTANTS[GKb] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GKb_b] * 0.600000 : CONSTANTS[GKb_b]);
  CONSTANTS[upScale] = (CONSTANTS[celltype] == 1.00000 ? 1.30000 : 1.00000);
  CONSTANTS[Gncx] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[Gncx_b] * 1.10000
                     : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[Gncx_b] * 1.40000
                                                      : CONSTANTS[Gncx_b]);
  CONSTANTS[Pnak] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[Pnak_b] * 0.900000
                     : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[Pnak_b] * 0.700000
                                                      : CONSTANTS[Pnak_b]);

#ifdef TISSUE
  if(isS1) ALGEBRAIC[Istim] = CONSTANTS[amp];
  else ALGEBRAIC[Istim] = 0.0;
#else
  ALGEBRAIC[Istim] = (TIME>=CONSTANTS[stim_start]&&TIME<=CONSTANTS[stim_end]&&(TIME - CONSTANTS[stim_start]) -  floor((TIME - CONSTANTS[stim_start])/CONSTANTS[BCL])*CONSTANTS[BCL]<=CONSTANTS[duration] ? CONSTANTS[amp] : 0.000000);
#endif

  STATES[XS] = STATES[XS] > 0.0 ? STATES[XS] : 0.0;
  STATES[XW] = STATES[XW] > 0.0 ? STATES[XW] : 0.0;
  STATES[Ca_TRPN] = STATES[Ca_TRPN] > 0.0 ? STATES[Ca_TRPN] : 0.0;

  //   cdw = phi * k_uw * (1 - dr) * (1 - wfrac) / ((1 - dr) * wfrac)
  //   cds = phi * k_ws * (1 - dr) * wfrac / dr
  //   k_wu = k_uw * (1 / wfrac - 1) - k_ws
  //   k_su = k_ws * (1 / dr - 1) * wfrac
  //   A = (0.25 * TOT_A) / ((1 - dr) * wfrac + dr) * (dr / 0.25)
  ALGEBRAIC[cdw] = CONSTANTS[phi] * CONSTANTS[k_uw] * (1 - CONSTANTS[dr]) * (1 - CONSTANTS[wfrac]) / ((1 - CONSTANTS[dr]) * CONSTANTS[wfrac]);
  ALGEBRAIC[cds] = CONSTANTS[phi] * CONSTANTS[k_ws] * (1 - CONSTANTS[dr]) * CONSTANTS[wfrac] / CONSTANTS[dr];
  ALGEBRAIC[k_wu] = CONSTANTS[k_uw] * (1 / CONSTANTS[wfrac] - 1) - CONSTANTS[k_ws];
  ALGEBRAIC[k_su] = CONSTANTS[k_ws] * (1 / CONSTANTS[dr] - 1) * CONSTANTS[wfrac];
  ALGEBRAIC[A] = (0.25 * CONSTANTS[TOT_A]) / ((1 - CONSTANTS[dr]) * CONSTANTS[wfrac] + CONSTANTS[dr]) * (CONSTANTS[dr] / 0.25);

  //   XU = (1 - TmBlocked) - XW - XS
  //   xb_ws = k_ws * XW
  //   xb_uw = k_uw * XU * MyoG
  //   xb_wu = k_wu * XW
  //   xb_su = k_su * XS
  ALGEBRAIC[XU] = (1 - STATES[TmBlocked]) - STATES[XW] - STATES[XS];
  ALGEBRAIC[xb_ws] = CONSTANTS[k_ws] * STATES[XW];
  ALGEBRAIC[xb_uw] = CONSTANTS[k_uw] * ALGEBRAIC[XU];
  ALGEBRAIC[xb_wu] = ALGEBRAIC[k_wu] * STATES[XW];
  ALGEBRAIC[xb_su] = ALGEBRAIC[k_su] * STATES[XS];

  //   gamma_rate = gamma * max((ZETAS .> 0) .* ZETAS, (ZETAS .< -1) .* (-ZETAS - 1))
  //   xb_su_gamma = gamma_rate .* XS
  //   gamma_rate_w = gamma_wu * abs.(ZETAW)
  //   xb_wu_gamma = gamma_rate_w .* XW
  ALGEBRAIC[gamma_rate] = CONSTANTS[gamma_idx] * fmax((STATES[ZETAS] > 0) * STATES[ZETAS], (STATES[ZETAS] < -1) * (-STATES[ZETAS] - 1));
  ALGEBRAIC[xb_su_gamma] = ALGEBRAIC[gamma_rate] * STATES[XS];
  ALGEBRAIC[gamma_rate_w] = CONSTANTS[gamma_wu] * fabs(STATES[ZETAW]);
  ALGEBRAIC[xb_wu_gamma] = ALGEBRAIC[gamma_rate_w] * STATES[XW];

  //   XSSS = dr * 0.5
  //   XWSS = (1 - dr) * wfrac * 0.5
  //   ktm_block = ktm_unblock * (perm50^nperm) * 0.5 / (0.5 - XSSS - XWSS)
  ALGEBRAIC[XSSS] = CONSTANTS[dr] * 0.5;
  ALGEBRAIC[XWSS] = (1 - CONSTANTS[dr]) * CONSTANTS[wfrac] * 0.5;
  ALGEBRAIC[ktm_block] = CONSTANTS[ktm_unblock] * pow(CONSTANTS[perm50], CONSTANTS[nperm]) * 0.5 / (0.5 - ALGEBRAIC[XSSS] - ALGEBRAIC[XWSS]);

  // Lfac = max(0, 1 + beta_0 * (lambda0 + min(lambda_min, lambda0) - (1 + lambda_min)))
  // T = Lfac * (Tref/dr) * ((1 .+ ZETAS) .* XS + ZETAW .* XW)
  // dTdt = Lfac * (Tref/dr) * ((1 .+ ZETAS) .* dXS + dZETAS .* XS + ZETAW .* dXW + dZETAW .* XW)
  double lambda0 = fmin(CONSTANTS[lambda], CONSTANTS[lambda_max]);
  double lam_min = fmin(CONSTANTS[lambda_min], lambda0);
  double lfac_b = 1.0 + CONSTANTS[land_beta_0] * (lambda0 + lam_min - (1 + CONSTANTS[lambda_min]));
  ALGEBRAIC[Lfac] = fmax(0.0, lfac_b);
  ALGEBRAIC[land_T] = ALGEBRAIC[Lfac] * (CONSTANTS[Tref] / CONSTANTS[dr]) * ((STATES[ZETAS] + 1) * STATES[XS] + STATES[ZETAW] * STATES[XW]);

  ALGEBRAIC[hLss] = 1.00000 / (1.00000 + exp((STATES[V] + 87.6100) / 7.48800));
  ALGEBRAIC[hLssp] = 1.00000 / (1.00000 + exp((STATES[V] + 93.8100) / 7.48800));
  ALGEBRAIC[mss] = 1.00000 / (1.00000 + exp(-(STATES[V] + CONSTANTS[mssV1]) / CONSTANTS[mssV2]));
  ALGEBRAIC[tm] = 1.00000 / (CONSTANTS[mtD1] * exp((STATES[V] + CONSTANTS[mtV1]) / CONSTANTS[mtV2]) +
                             CONSTANTS[mtD2] * exp(-(STATES[V] + CONSTANTS[mtV3]) / CONSTANTS[mtV4]));
  ALGEBRAIC[hss] = 1.00000 / (1.00000 + exp(((STATES[V] + CONSTANTS[hssV1]) - CONSTANTS[shift_INa_inact]) / CONSTANTS[hssV2]));
  ALGEBRAIC[thf] = 1.00000 / (1.43200e-05 * exp(-((STATES[V] + 1.19600) - CONSTANTS[shift_INa_inact]) / 6.28500) +
                              6.14900 * exp(((STATES[V] + 0.509600) - CONSTANTS[shift_INa_inact]) / 20.2700));
  ALGEBRAIC[ths] = 1.00000 / (0.00979400 * exp(-((STATES[V] + 17.9500) - CONSTANTS[shift_INa_inact]) / 28.0500) +
                              0.334300 * exp(((STATES[V] + 5.73000) - CONSTANTS[shift_INa_inact]) / 56.6600));
  ALGEBRAIC[ass] = 1.00000 / (1.00000 + exp(-(STATES[V] - 14.3400) / 14.8200));
  ALGEBRAIC[ta] = 1.05150 / (1.00000 / (1.20890 * (1.00000 + exp(-(STATES[V] - 18.4099) / 29.3814))) +
                             3.50000 / (1.00000 + exp((STATES[V] + 100.000) / 29.3814)));
  ALGEBRAIC[dss] = 1.00000 / (1.00000 + exp(-(STATES[V] + 3.94000) / 4.23000));
  ALGEBRAIC[td] = 0.600000 + 1.00000 / (exp(-0.0500000 * (STATES[V] + 6.00000)) + exp(0.0900000 * (STATES[V] + 14.0000)));
  ALGEBRAIC[fss] = 1.00000 / (1.00000 + exp((STATES[V] + 19.5800) / 3.69600));
  ALGEBRAIC[tff] = 7.00000 + 1.00000 / (0.00450000 * exp(-(STATES[V] + 20.0000) / 10.0000) + 0.00450000 * exp((STATES[V] + 20.0000) / 10.0000));
  ALGEBRAIC[tfs] = 1000.00 + 1.00000 / (3.50000e-05 * exp(-(STATES[V] + 5.00000) / 4.00000) + 3.50000e-05 * exp((STATES[V] + 5.00000) / 6.00000));
  ALGEBRAIC[fcass] = ALGEBRAIC[fss];
  ALGEBRAIC[km2n] = STATES[jca] * 1.00000;
  ALGEBRAIC[anca] = 1.00000 / (CONSTANTS[k2n] / ALGEBRAIC[km2n] + pow(1.00000 + CONSTANTS[Kmn] / STATES[cass], 4.00000));
  ALGEBRAIC[xs1ss] = 1.00000 / (1.00000 + exp(-(STATES[V] + 11.6000) / 8.93200));
  ALGEBRAIC[txs1] =
      CONSTANTS[txs1_max] + 1.00000 / (0.000232600 * exp((STATES[V] + 48.2800) / 17.8000) + 0.00129200 * exp(-(STATES[V] + 210.000) / 230.000));
  ALGEBRAIC[xk1ss] = 1.00000 / (1.00000 + exp(-(STATES[V] + 2.55380 * CONSTANTS[ko] + 144.590) / (1.56920 * CONSTANTS[ko] + 3.81150)));
  ALGEBRAIC[txk1] = 122.200 / (exp(-(STATES[V] + 127.200) / 20.3600) + exp((STATES[V] + 236.800) / 69.3300));
  ALGEBRAIC[CaMKb] = (CONSTANTS[CaMKo] * (1.00000 - STATES[CaMKt])) / (1.00000 + CONSTANTS[KmCaM] / STATES[cass]);
  ALGEBRAIC[jss] = ALGEBRAIC[hss];
  ALGEBRAIC[tj] = 2.03800 + 1.00000 / (0.0213600 * exp(-((STATES[V] + 100.600) - CONSTANTS[shift_INa_inact]) / 8.28100) +
                                       0.305200 * exp(((STATES[V] + 0.994100) - CONSTANTS[shift_INa_inact]) / 38.4500));
  ALGEBRAIC[assp] = 1.00000 / (1.00000 + exp(-(STATES[V] - 24.3400) / 14.8200));
  ALGEBRAIC[tfcaf] = 7.00000 + 1.00000 / (0.0400000 * exp(-(STATES[V] - 4.00000) / 7.00000) + 0.0400000 * exp((STATES[V] - 4.00000) / 7.00000));
  ALGEBRAIC[tfcas] = 100.000 + 1.00000 / (0.000120000 * exp(-STATES[V] / 3.00000) + 0.000120000 * exp(STATES[V] / 7.00000));
  ALGEBRAIC[tffp] = 2.50000 * ALGEBRAIC[tff];
  ALGEBRAIC[xs2ss] = ALGEBRAIC[xs1ss];
  ALGEBRAIC[txs2] = 1.00000 / (0.0100000 * exp((STATES[V] - 50.0000) / 20.0000) + 0.0193000 * exp(-(STATES[V] + 66.5400) / 31.0000));
  ALGEBRAIC[hssp] = 1.00000 / (1.00000 + exp(((STATES[V] + 89.1000) - CONSTANTS[shift_INa_inact]) / 6.08600));
  ALGEBRAIC[thsp] = 3.00000 * ALGEBRAIC[ths];
  ALGEBRAIC[tjp] = 1.46000 * ALGEBRAIC[tj];
  ALGEBRAIC[mLss] = 1.00000 / (1.00000 + exp(-(STATES[V] + 42.8500) / 5.26400));
  ALGEBRAIC[tmL] = ALGEBRAIC[tm];
  ALGEBRAIC[tfcafp] = 2.50000 * ALGEBRAIC[tfcaf];
  ALGEBRAIC[iss] = 1.00000 / (1.00000 + exp((STATES[V] + 43.9400) / 5.71100));
  ALGEBRAIC[delta_epi] = (CONSTANTS[celltype] == 1.00000 ? 1.00000 - 0.950000 / (1.00000 + exp((STATES[V] + 70.0000) / 5.00000)) : 1.00000);
  ALGEBRAIC[tiF_b] = 4.56200 + 1.00000 / (0.393300 * exp(-(STATES[V] + 100.000) / 100.000) + 0.0800400 * exp((STATES[V] + 50.0000) / 16.5900));
  ALGEBRAIC[tiF] = ALGEBRAIC[tiF_b] * ALGEBRAIC[delta_epi];
  ALGEBRAIC[tiS_b] = 23.6200 + 1.00000 / (0.00141600 * exp(-(STATES[V] + 96.5200) / 59.0500) + 1.78000e-08 * exp((STATES[V] + 114.100) / 8.07900));
  ALGEBRAIC[tiS] = ALGEBRAIC[tiS_b] * ALGEBRAIC[delta_epi];
  ALGEBRAIC[dti_develop] = 1.35400 + 0.000100000 / (exp((STATES[V] - 167.400) / 15.8900) + exp(-(STATES[V] - 12.2300) / 0.215400));
  ALGEBRAIC[dti_recover] = 1.00000 - 0.500000 / (1.00000 + exp((STATES[V] + 70.0000) / 20.0000));
  ALGEBRAIC[tiFp] = ALGEBRAIC[dti_develop] * ALGEBRAIC[dti_recover] * ALGEBRAIC[tiF];
  ALGEBRAIC[tiSp] = ALGEBRAIC[dti_develop] * ALGEBRAIC[dti_recover] * ALGEBRAIC[tiS];
  ALGEBRAIC[f] = CONSTANTS[Aff] * STATES[ff] + CONSTANTS[Afs] * STATES[fs];
  ALGEBRAIC[Afcaf] = 0.300000 + 0.600000 / (1.00000 + exp((STATES[V] - 10.0000) / 10.0000));
  ALGEBRAIC[Afcas] = 1.00000 - ALGEBRAIC[Afcaf];
  ALGEBRAIC[fca] = ALGEBRAIC[Afcaf] * STATES[fcaf] + ALGEBRAIC[Afcas] * STATES[fcas];
  ALGEBRAIC[fp] = CONSTANTS[Aff] * STATES[ffp] + CONSTANTS[Afs] * STATES[fs];
  ALGEBRAIC[fcap] = ALGEBRAIC[Afcaf] * STATES[fcafp] + ALGEBRAIC[Afcas] * STATES[fcas];
  ALGEBRAIC[vfrt] = STATES[V] * CONSTANTS[frt];
  ALGEBRAIC[A_1] = (4.00000 * CONSTANTS[ffrt] * (STATES[cass] * exp(2.00000 * ALGEBRAIC[vfrt]) - 0.341000 * CONSTANTS[cao])) / CONSTANTS[B_1];
  ALGEBRAIC[U_1] = CONSTANTS[B_1] * (STATES[V] - CONSTANTS[v0_CaL]);
  ALGEBRAIC[PhiCaL] =
      (-1.00000e-07 <= ALGEBRAIC[U_1] && ALGEBRAIC[U_1] <= 1.00000e-07 ? ALGEBRAIC[A_1] * (1.00000 - 0.500000 * ALGEBRAIC[U_1])
                                                                       : (ALGEBRAIC[A_1] * ALGEBRAIC[U_1]) / (exp(ALGEBRAIC[U_1]) - 1.00000));
  ALGEBRAIC[CaMKa] = ALGEBRAIC[CaMKb] + STATES[CaMKt];
  ALGEBRAIC[fICaLp] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[ICaL] = (1.00000 - ALGEBRAIC[fICaLp]) * CONSTANTS[PCa] * ALGEBRAIC[PhiCaL] * STATES[d] *
                        (ALGEBRAIC[f] * (1.00000 - STATES[nca]) + STATES[jca] * ALGEBRAIC[fca] * STATES[nca]) +
                    ALGEBRAIC[fICaLp] * CONSTANTS[PCap] * ALGEBRAIC[PhiCaL] * STATES[d] *
                        (ALGEBRAIC[fp] * (1.00000 - STATES[nca]) + STATES[jca] * ALGEBRAIC[fcap] * STATES[nca]);
  ALGEBRAIC[Jrel_inf_temp] = (CONSTANTS[a_rel] * -ALGEBRAIC[ICaL]) / (1.00000 + 1.00000 * pow(1.50000 / STATES[cajsr], 8.00000));
  ALGEBRAIC[Jrel_inf] = (CONSTANTS[celltype] == 2.00000 ? ALGEBRAIC[Jrel_inf_temp] * 1.70000 : ALGEBRAIC[Jrel_inf_temp]);
  ALGEBRAIC[tau_rel_temp] = CONSTANTS[bt] / (1.00000 + 0.0123000 / STATES[cajsr]);
  ALGEBRAIC[tau_rel] = (ALGEBRAIC[tau_rel_temp] < 0.00100000 ? 0.00100000 : ALGEBRAIC[tau_rel_temp]);
  ALGEBRAIC[Jrel_temp] = (CONSTANTS[a_relp] * -ALGEBRAIC[ICaL]) / (1.00000 + pow(1.50000 / STATES[cajsr], 8.00000));
  ALGEBRAIC[Jrel_infp] = (CONSTANTS[celltype] == 2.00000 ? ALGEBRAIC[Jrel_temp] * 1.70000 : ALGEBRAIC[Jrel_temp]);
  ALGEBRAIC[tau_relp_temp] = CONSTANTS[btp] / (1.00000 + 0.0123000 / STATES[cajsr]);
  ALGEBRAIC[tau_relp] = (ALGEBRAIC[tau_relp_temp] < 0.00100000 ? 0.00100000 : ALGEBRAIC[tau_relp_temp]);
  ALGEBRAIC[EK] = ((CONSTANTS[R] * CONSTANTS[T]) / CONSTANTS[F]) * log(CONSTANTS[ko] / STATES[ki]);
  ALGEBRAIC[AiF] = 1.00000 / (1.00000 + exp((STATES[V] - 213.600) / 151.200));
  ALGEBRAIC[AiS] = 1.00000 - ALGEBRAIC[AiF];
  ALGEBRAIC[i] = ALGEBRAIC[AiF] * STATES[iF] + ALGEBRAIC[AiS] * STATES[iS];
  ALGEBRAIC[ip] = ALGEBRAIC[AiF] * STATES[iFp] + ALGEBRAIC[AiS] * STATES[iSp];
  ALGEBRAIC[fItop] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[Ito] = CONSTANTS[Gto] * (STATES[V] - ALGEBRAIC[EK]) *
                   ((1.00000 - ALGEBRAIC[fItop]) * STATES[a] * ALGEBRAIC[i] + ALGEBRAIC[fItop] * STATES[ap] * ALGEBRAIC[ip]);
  ALGEBRAIC[IKr] = CONSTANTS[GKr] * pow((CONSTANTS[ko] / 5.40000), 1.0 / 2) * STATES[O] * (STATES[V] - ALGEBRAIC[EK]);
  ALGEBRAIC[EKs] = ((CONSTANTS[R] * CONSTANTS[T]) / CONSTANTS[F]) *
                   log((CONSTANTS[ko] + CONSTANTS[PKNa] * CONSTANTS[nao]) / (STATES[ki] + CONSTANTS[PKNa] * STATES[nai]));
  ALGEBRAIC[KsCa] = 1.00000 + 0.600000 / (1.00000 + pow(3.80000e-05 / STATES[cai], 1.40000));
  ALGEBRAIC[IKs] = CONSTANTS[GKs] * ALGEBRAIC[KsCa] * STATES[xs1] * STATES[xs2] * (STATES[V] - ALGEBRAIC[EKs]);
  ALGEBRAIC[rk1] = 1.00000 / (1.00000 + exp(((STATES[V] + 105.800) - 2.60000 * CONSTANTS[ko]) / 9.49300));
  ALGEBRAIC[IK1] = CONSTANTS[GK1] * pow(CONSTANTS[ko], 1.0 / 2) * ALGEBRAIC[rk1] * STATES[xk1] * (STATES[V] - ALGEBRAIC[EK]);
  ALGEBRAIC[Knao] = CONSTANTS[Knao0] * exp(((1.00000 - CONSTANTS[delta]) * STATES[V] * CONSTANTS[F]) / (3.00000 * CONSTANTS[R] * CONSTANTS[T]));
  ALGEBRAIC[a3] = (CONSTANTS[k3p] * pow(CONSTANTS[ko] / CONSTANTS[Kko], 2.00000)) /
                  ((pow(1.00000 + CONSTANTS[nao] / ALGEBRAIC[Knao], 3.00000) + pow(1.00000 + CONSTANTS[ko] / CONSTANTS[Kko], 2.00000)) - 1.00000);
  ALGEBRAIC[P] = CONSTANTS[eP] / (1.00000 + CONSTANTS[H] / CONSTANTS[Khp] + STATES[nai] / CONSTANTS[Knap] + STATES[ki] / CONSTANTS[Kxkur]);
  ALGEBRAIC[b3] = (CONSTANTS[k3m] * ALGEBRAIC[P] * CONSTANTS[H]) / (1.00000 + CONSTANTS[MgATP] / CONSTANTS[Kmgatp]);
  ALGEBRAIC[Knai] = CONSTANTS[Knai0] * exp((CONSTANTS[delta] * STATES[V] * CONSTANTS[F]) / (3.00000 * CONSTANTS[R] * CONSTANTS[T]));
  ALGEBRAIC[a1] = (CONSTANTS[k1p] * pow(STATES[nai] / ALGEBRAIC[Knai], 3.00000)) /
                  ((pow(1.00000 + STATES[nai] / ALGEBRAIC[Knai], 3.00000) + pow(1.00000 + STATES[ki] / CONSTANTS[Kki], 2.00000)) - 1.00000);
  ALGEBRAIC[b2] = (CONSTANTS[k2m] * pow(CONSTANTS[nao] / ALGEBRAIC[Knao], 3.00000)) /
                  ((pow(1.00000 + CONSTANTS[nao] / ALGEBRAIC[Knao], 3.00000) + pow(1.00000 + CONSTANTS[ko] / CONSTANTS[Kko], 2.00000)) - 1.00000);
  ALGEBRAIC[b4] = (CONSTANTS[k4m] * pow(STATES[ki] / CONSTANTS[Kki], 2.00000)) /
                  ((pow(1.00000 + STATES[nai] / ALGEBRAIC[Knai], 3.00000) + pow(1.00000 + STATES[ki] / CONSTANTS[Kki], 2.00000)) - 1.00000);
  ALGEBRAIC[x1] = CONSTANTS[a4] * ALGEBRAIC[a1] * CONSTANTS[a2] + ALGEBRAIC[b2] * ALGEBRAIC[b4] * ALGEBRAIC[b3] +
                  CONSTANTS[a2] * ALGEBRAIC[b4] * ALGEBRAIC[b3] + ALGEBRAIC[b3] * ALGEBRAIC[a1] * CONSTANTS[a2];
  ALGEBRAIC[x2] = ALGEBRAIC[b2] * CONSTANTS[b1] * ALGEBRAIC[b4] + ALGEBRAIC[a1] * CONSTANTS[a2] * ALGEBRAIC[a3] +
                  ALGEBRAIC[a3] * CONSTANTS[b1] * ALGEBRAIC[b4] + CONSTANTS[a2] * ALGEBRAIC[a3] * ALGEBRAIC[b4];
  ALGEBRAIC[x3] = CONSTANTS[a2] * ALGEBRAIC[a3] * CONSTANTS[a4] + ALGEBRAIC[b3] * ALGEBRAIC[b2] * CONSTANTS[b1] +
                  ALGEBRAIC[b2] * CONSTANTS[b1] * CONSTANTS[a4] + ALGEBRAIC[a3] * CONSTANTS[a4] * CONSTANTS[b1];
  ALGEBRAIC[x4] = ALGEBRAIC[b4] * ALGEBRAIC[b3] * ALGEBRAIC[b2] + ALGEBRAIC[a3] * CONSTANTS[a4] * ALGEBRAIC[a1] +
                  ALGEBRAIC[b2] * CONSTANTS[a4] * ALGEBRAIC[a1] + ALGEBRAIC[b3] * ALGEBRAIC[b2] * ALGEBRAIC[a1];
  ALGEBRAIC[E1] = ALGEBRAIC[x1] / (ALGEBRAIC[x1] + ALGEBRAIC[x2] + ALGEBRAIC[x3] + ALGEBRAIC[x4]);
  ALGEBRAIC[E2] = ALGEBRAIC[x2] / (ALGEBRAIC[x1] + ALGEBRAIC[x2] + ALGEBRAIC[x3] + ALGEBRAIC[x4]);
  ALGEBRAIC[JnakNa] = 3.00000 * (ALGEBRAIC[E1] * ALGEBRAIC[a3] - ALGEBRAIC[E2] * ALGEBRAIC[b3]);
  ALGEBRAIC[E3] = ALGEBRAIC[x3] / (ALGEBRAIC[x1] + ALGEBRAIC[x2] + ALGEBRAIC[x3] + ALGEBRAIC[x4]);
  ALGEBRAIC[E4] = ALGEBRAIC[x4] / (ALGEBRAIC[x1] + ALGEBRAIC[x2] + ALGEBRAIC[x3] + ALGEBRAIC[x4]);
  ALGEBRAIC[JnakK] = 2.00000 * (ALGEBRAIC[E4] * CONSTANTS[b1] - ALGEBRAIC[E3] * ALGEBRAIC[a1]);
  ALGEBRAIC[INaK] = CONSTANTS[Pnak] * (CONSTANTS[zna] * ALGEBRAIC[JnakNa] + CONSTANTS[zk] * ALGEBRAIC[JnakK]);
  ALGEBRAIC[xkb] = 1.00000 / (1.00000 + exp(-(STATES[V] - 14.4800) / 18.3400));
  ALGEBRAIC[IKb] = CONSTANTS[GKb] * ALGEBRAIC[xkb] * (STATES[V] - ALGEBRAIC[EK]);
  ALGEBRAIC[JdiffK] = (STATES[kss] - STATES[ki]) / 2.00000;
  ALGEBRAIC[A_3] = (0.750000 * CONSTANTS[ffrt] * (STATES[kss] * exp(ALGEBRAIC[vfrt]) - CONSTANTS[ko])) / CONSTANTS[B_3];
  ALGEBRAIC[U_3] = CONSTANTS[B_3] * (STATES[V] - CONSTANTS[v0_CaL]);
  ALGEBRAIC[PhiCaK] =
      (-1.00000e-07 <= ALGEBRAIC[U_3] && ALGEBRAIC[U_3] <= 1.00000e-07 ? ALGEBRAIC[A_3] * (1.00000 - 0.500000 * ALGEBRAIC[U_3])
                                                                       : (ALGEBRAIC[A_3] * ALGEBRAIC[U_3]) / (exp(ALGEBRAIC[U_3]) - 1.00000));
  ALGEBRAIC[ICaK] = (1.00000 - ALGEBRAIC[fICaLp]) * CONSTANTS[PCaK] * ALGEBRAIC[PhiCaK] * STATES[d] *
                        (ALGEBRAIC[f] * (1.00000 - STATES[nca]) + STATES[jca] * ALGEBRAIC[fca] * STATES[nca]) +
                    ALGEBRAIC[fICaLp] * CONSTANTS[PCaKp] * ALGEBRAIC[PhiCaK] * STATES[d] *
                        (ALGEBRAIC[fp] * (1.00000 - STATES[nca]) + STATES[jca] * ALGEBRAIC[fcap] * STATES[nca]);
  ALGEBRAIC[ENa] = ((CONSTANTS[R] * CONSTANTS[T]) / CONSTANTS[F]) * log(CONSTANTS[nao] / STATES[nai]);
  ALGEBRAIC[h] = CONSTANTS[Ahf] * STATES[hf] + CONSTANTS[Ahs] * STATES[hs];
  ALGEBRAIC[hp] = CONSTANTS[Ahf] * STATES[hf] + CONSTANTS[Ahs] * STATES[hsp];
  ALGEBRAIC[fINap] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[INa] = CONSTANTS[GNa] * (STATES[V] - ALGEBRAIC[ENa]) * pow(STATES[m], 3.00000) *
                   ((1.00000 - ALGEBRAIC[fINap]) * ALGEBRAIC[h] * STATES[j] + ALGEBRAIC[fINap] * ALGEBRAIC[hp] * STATES[jp]);
  ALGEBRAIC[fINaLp] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[INaL] =
      CONSTANTS[GNaL] * (STATES[V] - ALGEBRAIC[ENa]) * STATES[mL] * ((1.00000 - ALGEBRAIC[fINaLp]) * STATES[hL] + ALGEBRAIC[fINaLp] * STATES[hLp]);
  ALGEBRAIC[allo_i] = 1.00000 / (1.00000 + pow(CONSTANTS[KmCaAct] / STATES[cai], 2.00000));
  ALGEBRAIC[hna] = exp((CONSTANTS[qna] * STATES[V] * CONSTANTS[F]) / (CONSTANTS[R] * CONSTANTS[T]));
  ALGEBRAIC[h7_i] = 1.00000 + (CONSTANTS[nao] / CONSTANTS[kna3]) * (1.00000 + 1.00000 / ALGEBRAIC[hna]);
  ALGEBRAIC[h8_i] = CONSTANTS[nao] / (CONSTANTS[kna3] * ALGEBRAIC[hna] * ALGEBRAIC[h7_i]);
  ALGEBRAIC[k3pp_i] = ALGEBRAIC[h8_i] * CONSTANTS[wnaca];
  ALGEBRAIC[h1_i] = 1.00000 + (STATES[nai] / CONSTANTS[kna3]) * (1.00000 + ALGEBRAIC[hna]);
  ALGEBRAIC[h2_i] = (STATES[nai] * ALGEBRAIC[hna]) / (CONSTANTS[kna3] * ALGEBRAIC[h1_i]);
  ALGEBRAIC[k4pp_i] = ALGEBRAIC[h2_i] * CONSTANTS[wnaca];
  ALGEBRAIC[h4_i] = 1.00000 + (STATES[nai] / CONSTANTS[kna1]) * (1.00000 + STATES[nai] / CONSTANTS[kna2]);
  ALGEBRAIC[h5_i] = (STATES[nai] * STATES[nai]) / (ALGEBRAIC[h4_i] * CONSTANTS[kna1] * CONSTANTS[kna2]);
  ALGEBRAIC[k7_i] = ALGEBRAIC[h5_i] * ALGEBRAIC[h2_i] * CONSTANTS[wna];
  ALGEBRAIC[k8_i] = ALGEBRAIC[h8_i] * CONSTANTS[h11_i] * CONSTANTS[wna];
  ALGEBRAIC[h9_i] = 1.00000 / ALGEBRAIC[h7_i];
  ALGEBRAIC[k3p_i] = ALGEBRAIC[h9_i] * CONSTANTS[wca];
  ALGEBRAIC[k3_i] = ALGEBRAIC[k3p_i] + ALGEBRAIC[k3pp_i];
  ALGEBRAIC[hca] = exp((CONSTANTS[qca] * STATES[V] * CONSTANTS[F]) / (CONSTANTS[R] * CONSTANTS[T]));
  ALGEBRAIC[h3_i] = 1.00000 / ALGEBRAIC[h1_i];
  ALGEBRAIC[k4p_i] = (ALGEBRAIC[h3_i] * CONSTANTS[wca]) / ALGEBRAIC[hca];
  ALGEBRAIC[k4_i] = ALGEBRAIC[k4p_i] + ALGEBRAIC[k4pp_i];
  ALGEBRAIC[h6_i] = 1.00000 / ALGEBRAIC[h4_i];
  ALGEBRAIC[k6_i] = ALGEBRAIC[h6_i] * STATES[cai] * CONSTANTS[kcaon];
  ALGEBRAIC[x1_i] = CONSTANTS[k2_i] * ALGEBRAIC[k4_i] * (ALGEBRAIC[k7_i] + ALGEBRAIC[k6_i]) +
                    CONSTANTS[k5_i] * ALGEBRAIC[k7_i] * (CONSTANTS[k2_i] + ALGEBRAIC[k3_i]);
  ALGEBRAIC[x2_i] = CONSTANTS[k1_i] * ALGEBRAIC[k7_i] * (ALGEBRAIC[k4_i] + CONSTANTS[k5_i]) +
                    ALGEBRAIC[k4_i] * ALGEBRAIC[k6_i] * (CONSTANTS[k1_i] + ALGEBRAIC[k8_i]);
  ALGEBRAIC[x3_i] = CONSTANTS[k1_i] * ALGEBRAIC[k3_i] * (ALGEBRAIC[k7_i] + ALGEBRAIC[k6_i]) +
                    ALGEBRAIC[k8_i] * ALGEBRAIC[k6_i] * (CONSTANTS[k2_i] + ALGEBRAIC[k3_i]);
  ALGEBRAIC[x4_i] = CONSTANTS[k2_i] * ALGEBRAIC[k8_i] * (ALGEBRAIC[k4_i] + CONSTANTS[k5_i]) +
                    ALGEBRAIC[k3_i] * CONSTANTS[k5_i] * (CONSTANTS[k1_i] + ALGEBRAIC[k8_i]);
  ALGEBRAIC[E1_i] = ALGEBRAIC[x1_i] / (ALGEBRAIC[x1_i] + ALGEBRAIC[x2_i] + ALGEBRAIC[x3_i] + ALGEBRAIC[x4_i]);
  ALGEBRAIC[E2_i] = ALGEBRAIC[x2_i] / (ALGEBRAIC[x1_i] + ALGEBRAIC[x2_i] + ALGEBRAIC[x3_i] + ALGEBRAIC[x4_i]);
  ALGEBRAIC[E3_i] = ALGEBRAIC[x3_i] / (ALGEBRAIC[x1_i] + ALGEBRAIC[x2_i] + ALGEBRAIC[x3_i] + ALGEBRAIC[x4_i]);
  ALGEBRAIC[E4_i] = ALGEBRAIC[x4_i] / (ALGEBRAIC[x1_i] + ALGEBRAIC[x2_i] + ALGEBRAIC[x3_i] + ALGEBRAIC[x4_i]);
  ALGEBRAIC[JncxNa_i] = (3.00000 * (ALGEBRAIC[E4_i] * ALGEBRAIC[k7_i] - ALGEBRAIC[E1_i] * ALGEBRAIC[k8_i]) + ALGEBRAIC[E3_i] * ALGEBRAIC[k4pp_i]) -
                        ALGEBRAIC[E2_i] * ALGEBRAIC[k3pp_i];
  ALGEBRAIC[JncxCa_i] = ALGEBRAIC[E2_i] * CONSTANTS[k2_i] - ALGEBRAIC[E1_i] * CONSTANTS[k1_i];
  ALGEBRAIC[INaCa_i] = 0.800000 * CONSTANTS[Gncx] * ALGEBRAIC[allo_i] * (CONSTANTS[zna] * ALGEBRAIC[JncxNa_i] + CONSTANTS[zca] * ALGEBRAIC[JncxCa_i]);
  ALGEBRAIC[A_Nab] = (CONSTANTS[PNab] * CONSTANTS[ffrt] * (STATES[nai] * exp(ALGEBRAIC[vfrt]) - CONSTANTS[nao])) / CONSTANTS[B_Nab];
  ALGEBRAIC[U_Nab] = CONSTANTS[B_Nab] * (STATES[V] - CONSTANTS[v0_Nab]);
  ALGEBRAIC[INab] = (-1.00000e-07 <= ALGEBRAIC[U_Nab] && ALGEBRAIC[U_Nab] <= 1.00000e-07
                         ? ALGEBRAIC[A_Nab] * (1.00000 - 0.500000 * ALGEBRAIC[U_Nab])
                         : (ALGEBRAIC[A_Nab] * ALGEBRAIC[U_Nab]) / (exp(ALGEBRAIC[U_Nab]) - 1.00000));
  ALGEBRAIC[JdiffNa] = (STATES[nass] - STATES[nai]) / 2.00000;
  ALGEBRAIC[A_2] = (0.750000 * CONSTANTS[ffrt] * (STATES[nass] * exp(ALGEBRAIC[vfrt]) - CONSTANTS[nao])) / CONSTANTS[B_2];
  ALGEBRAIC[U_2] = CONSTANTS[B_2] * (STATES[V] - CONSTANTS[v0_CaL]);
  ALGEBRAIC[PhiCaNa] =
      (-1.00000e-07 <= ALGEBRAIC[U_2] && ALGEBRAIC[U_2] <= 1.00000e-07 ? ALGEBRAIC[A_2] * (1.00000 - 0.500000 * ALGEBRAIC[U_2])
                                                                       : (ALGEBRAIC[A_2] * ALGEBRAIC[U_2]) / (exp(ALGEBRAIC[U_2]) - 1.00000));
  ALGEBRAIC[ICaNa] = (1.00000 - ALGEBRAIC[fICaLp]) * CONSTANTS[PCaNa] * ALGEBRAIC[PhiCaNa] * STATES[d] *
                         (ALGEBRAIC[f] * (1.00000 - STATES[nca]) + STATES[jca] * ALGEBRAIC[fca] * STATES[nca]) +
                     ALGEBRAIC[fICaLp] * CONSTANTS[PCaNap] * ALGEBRAIC[PhiCaNa] * STATES[d] *
                         (ALGEBRAIC[fp] * (1.00000 - STATES[nca]) + STATES[jca] * ALGEBRAIC[fcap] * STATES[nca]);
  ALGEBRAIC[allo_ss] = 1.00000 / (1.00000 + pow(CONSTANTS[KmCaAct] / STATES[cass], 2.00000));
  ALGEBRAIC[h7_ss] = 1.00000 + (CONSTANTS[nao] / CONSTANTS[kna3]) * (1.00000 + 1.00000 / ALGEBRAIC[hna]);
  ALGEBRAIC[h8_ss] = CONSTANTS[nao] / (CONSTANTS[kna3] * ALGEBRAIC[hna] * ALGEBRAIC[h7_ss]);
  ALGEBRAIC[k3pp_ss] = ALGEBRAIC[h8_ss] * CONSTANTS[wnaca];
  ALGEBRAIC[h1_ss] = 1.00000 + (STATES[nass] / CONSTANTS[kna3]) * (1.00000 + ALGEBRAIC[hna]);
  ALGEBRAIC[h2_ss] = (STATES[nass] * ALGEBRAIC[hna]) / (CONSTANTS[kna3] * ALGEBRAIC[h1_ss]);
  ALGEBRAIC[k4pp_ss] = ALGEBRAIC[h2_ss] * CONSTANTS[wnaca];
  ALGEBRAIC[h4_ss] = 1.00000 + (STATES[nass] / CONSTANTS[kna1]) * (1.00000 + STATES[nass] / CONSTANTS[kna2]);
  ALGEBRAIC[h5_ss] = (STATES[nass] * STATES[nass]) / (ALGEBRAIC[h4_ss] * CONSTANTS[kna1] * CONSTANTS[kna2]);
  ALGEBRAIC[k7_ss] = ALGEBRAIC[h5_ss] * ALGEBRAIC[h2_ss] * CONSTANTS[wna];
  ALGEBRAIC[k8_ss] = ALGEBRAIC[h8_ss] * CONSTANTS[h11_ss] * CONSTANTS[wna];
  ALGEBRAIC[h9_ss] = 1.00000 / ALGEBRAIC[h7_ss];
  ALGEBRAIC[k3p_ss] = ALGEBRAIC[h9_ss] * CONSTANTS[wca];
  ALGEBRAIC[k3_ss] = ALGEBRAIC[k3p_ss] + ALGEBRAIC[k3pp_ss];
  ALGEBRAIC[h3_ss] = 1.00000 / ALGEBRAIC[h1_ss];
  ALGEBRAIC[k4p_ss] = (ALGEBRAIC[h3_ss] * CONSTANTS[wca]) / ALGEBRAIC[hca];
  ALGEBRAIC[k4_ss] = ALGEBRAIC[k4p_ss] + ALGEBRAIC[k4pp_ss];
  ALGEBRAIC[h6_ss] = 1.00000 / ALGEBRAIC[h4_ss];
  ALGEBRAIC[k6_ss] = ALGEBRAIC[h6_ss] * STATES[cass] * CONSTANTS[kcaon];
  ALGEBRAIC[x1_ss] = CONSTANTS[k2_ss] * ALGEBRAIC[k4_ss] * (ALGEBRAIC[k7_ss] + ALGEBRAIC[k6_ss]) +
                     CONSTANTS[k5_ss] * ALGEBRAIC[k7_ss] * (CONSTANTS[k2_ss] + ALGEBRAIC[k3_ss]);
  ALGEBRAIC[x2_ss] = CONSTANTS[k1_ss] * ALGEBRAIC[k7_ss] * (ALGEBRAIC[k4_ss] + CONSTANTS[k5_ss]) +
                     ALGEBRAIC[k4_ss] * ALGEBRAIC[k6_ss] * (CONSTANTS[k1_ss] + ALGEBRAIC[k8_ss]);
  ALGEBRAIC[x3_ss] = CONSTANTS[k1_ss] * ALGEBRAIC[k3_ss] * (ALGEBRAIC[k7_ss] + ALGEBRAIC[k6_ss]) +
                     ALGEBRAIC[k8_ss] * ALGEBRAIC[k6_ss] * (CONSTANTS[k2_ss] + ALGEBRAIC[k3_ss]);
  ALGEBRAIC[x4_ss] = CONSTANTS[k2_ss] * ALGEBRAIC[k8_ss] * (ALGEBRAIC[k4_ss] + CONSTANTS[k5_ss]) +
                     ALGEBRAIC[k3_ss] * CONSTANTS[k5_ss] * (CONSTANTS[k1_ss] + ALGEBRAIC[k8_ss]);
  ALGEBRAIC[E1_ss] = ALGEBRAIC[x1_ss] / (ALGEBRAIC[x1_ss] + ALGEBRAIC[x2_ss] + ALGEBRAIC[x3_ss] + ALGEBRAIC[x4_ss]);
  ALGEBRAIC[E2_ss] = ALGEBRAIC[x2_ss] / (ALGEBRAIC[x1_ss] + ALGEBRAIC[x2_ss] + ALGEBRAIC[x3_ss] + ALGEBRAIC[x4_ss]);
  ALGEBRAIC[E3_ss] = ALGEBRAIC[x3_ss] / (ALGEBRAIC[x1_ss] + ALGEBRAIC[x2_ss] + ALGEBRAIC[x3_ss] + ALGEBRAIC[x4_ss]);
  ALGEBRAIC[E4_ss] = ALGEBRAIC[x4_ss] / (ALGEBRAIC[x1_ss] + ALGEBRAIC[x2_ss] + ALGEBRAIC[x3_ss] + ALGEBRAIC[x4_ss]);
  ALGEBRAIC[JncxNa_ss] =
      (3.00000 * (ALGEBRAIC[E4_ss] * ALGEBRAIC[k7_ss] - ALGEBRAIC[E1_ss] * ALGEBRAIC[k8_ss]) + ALGEBRAIC[E3_ss] * ALGEBRAIC[k4pp_ss]) -
      ALGEBRAIC[E2_ss] * ALGEBRAIC[k3pp_ss];
  ALGEBRAIC[JncxCa_ss] = ALGEBRAIC[E2_ss] * CONSTANTS[k2_ss] - ALGEBRAIC[E1_ss] * CONSTANTS[k1_ss];
  ALGEBRAIC[INaCa_ss] =
      0.200000 * CONSTANTS[Gncx] * ALGEBRAIC[allo_ss] * (CONSTANTS[zna] * ALGEBRAIC[JncxNa_ss] + CONSTANTS[zca] * ALGEBRAIC[JncxCa_ss]);
  ALGEBRAIC[IpCa] = (CONSTANTS[GpCa] * STATES[cai]) / (CONSTANTS[KmCap] + STATES[cai]);
  ALGEBRAIC[A_Cab] =
      (CONSTANTS[PCab] * 4.00000 * CONSTANTS[ffrt] * (STATES[cai] * exp(2.00000 * ALGEBRAIC[vfrt]) - 0.341000 * CONSTANTS[cao])) / CONSTANTS[B_Cab];
  ALGEBRAIC[U_Cab] = CONSTANTS[B_Cab] * (STATES[V] - CONSTANTS[v0_Cab]);
  ALGEBRAIC[ICab] = (-1.00000e-07 <= ALGEBRAIC[U_Cab] && ALGEBRAIC[U_Cab] <= 1.00000e-07
                         ? ALGEBRAIC[A_Cab] * (1.00000 - 0.500000 * ALGEBRAIC[U_Cab])
                         : (ALGEBRAIC[A_Cab] * ALGEBRAIC[U_Cab]) / (exp(ALGEBRAIC[U_Cab]) - 1.00000));
  ALGEBRAIC[Jdiff] = (STATES[cass] - STATES[cai]) / 0.200000;
  ALGEBRAIC[fJrelp] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[Jrel] = CONSTANTS[Jrel_b] * ((1.00000 - ALGEBRAIC[fJrelp]) * STATES[Jrelnp] + ALGEBRAIC[fJrelp] * STATES[Jrelp]);
  ALGEBRAIC[Bcass] = 1.00000 / (1.00000 + (CONSTANTS[BSRmax] * CONSTANTS[KmBSR]) / pow(CONSTANTS[KmBSR] + STATES[cass], 2.00000) +
                                (CONSTANTS[BSLmax] * CONSTANTS[KmBSL]) / pow(CONSTANTS[KmBSL] + STATES[cass], 2.00000));
  ALGEBRAIC[Jupnp] = (CONSTANTS[upScale] * 0.00437500 * STATES[cai]) / (STATES[cai] + 0.000920000);
  ALGEBRAIC[Jupp] = (CONSTANTS[upScale] * 2.75000 * 0.00437500 * STATES[cai]) / ((STATES[cai] + 0.000920000) - 0.000170000);
  ALGEBRAIC[fJupp] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  // CVAR : Multiply Jleak with Jleak_b
  ALGEBRAIC[Jleak] = CONSTANTS[Jleak_b] * (0.00393750 * STATES[cansr]) / 15.0000;
  ALGEBRAIC[Jup] = CONSTANTS[Jup_b] * (((1.00000 - ALGEBRAIC[fJupp]) * ALGEBRAIC[Jupnp] + ALGEBRAIC[fJupp] * ALGEBRAIC[Jupp]) - ALGEBRAIC[Jleak]);
  ALGEBRAIC[Bcai] = 1.00000 / (1.00000 + (CONSTANTS[cmdnmax] * CONSTANTS[kmcmdn]) / pow(CONSTANTS[kmcmdn] + STATES[cai], 2.00000));
  // CVAR : Multiply Jtr with Jtr_b
  ALGEBRAIC[Jtr] = CONSTANTS[Jtr_b] * (STATES[cansr] - STATES[cajsr]) / 100.000;
  ALGEBRAIC[Bcajsr] = 1.00000 / (1.00000 + (CONSTANTS[csqnmax] * CONSTANTS[kmcsqn]) / pow(CONSTANTS[kmcsqn] + STATES[cajsr], 2.00000));

  // RATES[D] = CONSTANTS[cnc];
  RATES[D] = 0.;
  RATES[IC1] =
      (-(CONSTANTS[A11] * exp(CONSTANTS[B11] * STATES[V]) * STATES[IC1] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q11])) / 10.0000) -
         CONSTANTS[A21] * exp(CONSTANTS[B21] * STATES[V]) * STATES[IC2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q21])) / 10.0000)) +
       CONSTANTS[A51] * exp(CONSTANTS[B51] * STATES[V]) * STATES[C1] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q51])) / 10.0000)) -
      CONSTANTS[A61] * exp(CONSTANTS[B61] * STATES[V]) * STATES[IC1] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q61])) / 10.0000);
  RATES[IC2] =
      (((CONSTANTS[A11] * exp(CONSTANTS[B11] * STATES[V]) * STATES[IC1] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q11])) / 10.0000) -
         CONSTANTS[A21] * exp(CONSTANTS[B21] * STATES[V]) * STATES[IC2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q21])) / 10.0000)) -
        (CONSTANTS[A3] * exp(CONSTANTS[B3] * STATES[V]) * STATES[IC2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q3])) / 10.0000) -
         CONSTANTS[A4] * exp(CONSTANTS[B4] * STATES[V]) * STATES[IO] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q4])) / 10.0000))) +
       CONSTANTS[A52] * exp(CONSTANTS[B52] * STATES[V]) * STATES[C2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q52])) / 10.0000)) -
      CONSTANTS[A62] * exp(CONSTANTS[B62] * STATES[V]) * STATES[IC2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q62])) / 10.0000);
  RATES[C1] = -(CONSTANTS[A1] * exp(CONSTANTS[B1] * STATES[V]) * STATES[C1] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q1])) / 10.0000) -
                CONSTANTS[A2] * exp(CONSTANTS[B2] * STATES[V]) * STATES[C2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q2])) / 10.0000)) -
              (CONSTANTS[A51] * exp(CONSTANTS[B51] * STATES[V]) * STATES[C1] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q51])) / 10.0000) -
               CONSTANTS[A61] * exp(CONSTANTS[B61] * STATES[V]) * STATES[IC1] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q61])) / 10.0000));
  RATES[C2] = ((CONSTANTS[A1] * exp(CONSTANTS[B1] * STATES[V]) * STATES[C1] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q1])) / 10.0000) -
                CONSTANTS[A2] * exp(CONSTANTS[B2] * STATES[V]) * STATES[C2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q2])) / 10.0000)) -
               (CONSTANTS[A31] * exp(CONSTANTS[B31] * STATES[V]) * STATES[C2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q31])) / 10.0000) -
                CONSTANTS[A41] * exp(CONSTANTS[B41] * STATES[V]) * STATES[O] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q41])) / 10.0000))) -
              (CONSTANTS[A52] * exp(CONSTANTS[B52] * STATES[V]) * STATES[C2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q52])) / 10.0000) -
               CONSTANTS[A62] * exp(CONSTANTS[B62] * STATES[V]) * STATES[IC2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q62])) / 10.0000));
  RATES[O] = ((CONSTANTS[A31] * exp(CONSTANTS[B31] * STATES[V]) * STATES[C2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q31])) / 10.0000) -
               CONSTANTS[A41] * exp(CONSTANTS[B41] * STATES[V]) * STATES[O] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q41])) / 10.0000)) -
              (CONSTANTS[A53] * exp(CONSTANTS[B53] * STATES[V]) * STATES[O] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q53])) / 10.0000) -
               CONSTANTS[A63] * exp(CONSTANTS[B63] * STATES[V]) * STATES[IO] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q63])) / 10.0000))) -
             (((CONSTANTS[Kmax] * CONSTANTS[Ku] * pow(STATES[D], CONSTANTS[n])) / (pow(STATES[D], CONSTANTS[n]) + CONSTANTS[halfmax])) * STATES[O] -
              CONSTANTS[Ku] * STATES[Obound]);
  RATES[IO] =
      (((CONSTANTS[A3] * exp(CONSTANTS[B3] * STATES[V]) * STATES[IC2] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q3])) / 10.0000) -
         CONSTANTS[A4] * exp(CONSTANTS[B4] * STATES[V]) * STATES[IO] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q4])) / 10.0000)) +
        CONSTANTS[A53] * exp(CONSTANTS[B53] * STATES[V]) * STATES[O] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q53])) / 10.0000)) -
       CONSTANTS[A63] * exp(CONSTANTS[B63] * STATES[V]) * STATES[IO] * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q63])) / 10.0000)) -
      (((CONSTANTS[Kmax] * CONSTANTS[Ku] * pow(STATES[D], CONSTANTS[n])) / (pow(STATES[D], CONSTANTS[n]) + CONSTANTS[halfmax])) * STATES[IO] -
       ((CONSTANTS[Ku] * CONSTANTS[A53] * exp(CONSTANTS[B53] * STATES[V]) * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q53])) / 10.0000)) /
        (CONSTANTS[A63] * exp(CONSTANTS[B63] * STATES[V]) * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q63])) / 10.0000))) *
           STATES[IObound]);
  RATES[IObound] =
      ((((CONSTANTS[Kmax] * CONSTANTS[Ku] * pow(STATES[D], CONSTANTS[n])) / (pow(STATES[D], CONSTANTS[n]) + CONSTANTS[halfmax])) * STATES[IO] -
        ((CONSTANTS[Ku] * CONSTANTS[A53] * exp(CONSTANTS[B53] * STATES[V]) * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q53])) / 10.0000)) /
         (CONSTANTS[A63] * exp(CONSTANTS[B63] * STATES[V]) * exp(((CONSTANTS[Temp] - 20.0000) * log(CONSTANTS[q63])) / 10.0000))) *
            STATES[IObound]) +
       (CONSTANTS[Kt] / (1.00000 + exp(-(STATES[V] - CONSTANTS[Vhalf]) / 6.78900))) * STATES[Cbound]) -
      CONSTANTS[Kt] * STATES[IObound];
  RATES[Obound] =
      ((((CONSTANTS[Kmax] * CONSTANTS[Ku] * pow(STATES[D], CONSTANTS[n])) / (pow(STATES[D], CONSTANTS[n]) + CONSTANTS[halfmax])) * STATES[O] -
        CONSTANTS[Ku] * STATES[Obound]) +
       (CONSTANTS[Kt] / (1.00000 + exp(-(STATES[V] - CONSTANTS[Vhalf]) / 6.78900))) * STATES[Cbound]) -
      CONSTANTS[Kt] * STATES[Obound];
  RATES[Cbound] = -((CONSTANTS[Kt] / (1.00000 + exp(-(STATES[V] - CONSTANTS[Vhalf]) / 6.78900))) * STATES[Cbound] - CONSTANTS[Kt] * STATES[Obound]) -
                  ((CONSTANTS[Kt] / (1.00000 + exp(-(STATES[V] - CONSTANTS[Vhalf]) / 6.78900))) * STATES[Cbound] - CONSTANTS[Kt] * STATES[IObound]);
  RATES[hL] = (ALGEBRAIC[hLss] - STATES[hL]) / CONSTANTS[thL];
  RATES[hLp] = (ALGEBRAIC[hLssp] - STATES[hLp]) / CONSTANTS[thLp];
  RATES[m] = (ALGEBRAIC[mss] - STATES[m]) / ALGEBRAIC[tm];
  RATES[hf] = (ALGEBRAIC[hss] - STATES[hf]) / ALGEBRAIC[thf];
  RATES[hs] = (ALGEBRAIC[hss] - STATES[hs]) / ALGEBRAIC[ths];
  RATES[a] = (ALGEBRAIC[ass] - STATES[a]) / ALGEBRAIC[ta];
  RATES[d] = (ALGEBRAIC[dss] - STATES[d]) / ALGEBRAIC[td];
  RATES[ff] = (ALGEBRAIC[fss] - STATES[ff]) / ALGEBRAIC[tff];
  RATES[fs] = (ALGEBRAIC[fss] - STATES[fs]) / ALGEBRAIC[tfs];
  RATES[jca] = (ALGEBRAIC[fcass] - STATES[jca]) / CONSTANTS[tjca];
  RATES[nca] = ALGEBRAIC[anca] * CONSTANTS[k2n] - STATES[nca] * ALGEBRAIC[km2n];
  RATES[xs1] = (ALGEBRAIC[xs1ss] - STATES[xs1]) / ALGEBRAIC[txs1];
  RATES[xk1] = (ALGEBRAIC[xk1ss] - STATES[xk1]) / ALGEBRAIC[txk1];
  RATES[CaMKt] = CONSTANTS[aCaMK] * ALGEBRAIC[CaMKb] * (ALGEBRAIC[CaMKb] + STATES[CaMKt]) - CONSTANTS[bCaMK] * STATES[CaMKt];
  RATES[j] = (ALGEBRAIC[jss] - STATES[j]) / ALGEBRAIC[tj];
  RATES[ap] = (ALGEBRAIC[assp] - STATES[ap]) / ALGEBRAIC[ta];
  RATES[fcaf] = (ALGEBRAIC[fcass] - STATES[fcaf]) / ALGEBRAIC[tfcaf];
  RATES[fcas] = (ALGEBRAIC[fcass] - STATES[fcas]) / ALGEBRAIC[tfcas];
  RATES[ffp] = (ALGEBRAIC[fss] - STATES[ffp]) / ALGEBRAIC[tffp];
  RATES[xs2] = (ALGEBRAIC[xs2ss] - STATES[xs2]) / ALGEBRAIC[txs2];
  RATES[hsp] = (ALGEBRAIC[hssp] - STATES[hsp]) / ALGEBRAIC[thsp];
  RATES[jp] = (ALGEBRAIC[jss] - STATES[jp]) / ALGEBRAIC[tjp];
  RATES[mL] = (ALGEBRAIC[mLss] - STATES[mL]) / ALGEBRAIC[tmL];
  RATES[fcafp] = (ALGEBRAIC[fcass] - STATES[fcafp]) / ALGEBRAIC[tfcafp];
  RATES[iF] = (ALGEBRAIC[iss] - STATES[iF]) / ALGEBRAIC[tiF];
  RATES[iS] = (ALGEBRAIC[iss] - STATES[iS]) / ALGEBRAIC[tiS];
  RATES[iFp] = (ALGEBRAIC[iss] - STATES[iFp]) / ALGEBRAIC[tiFp];
  RATES[iSp] = (ALGEBRAIC[iss] - STATES[iSp]) / ALGEBRAIC[tiSp];
  RATES[Jrelnp] = (ALGEBRAIC[Jrel_inf] - STATES[Jrelnp]) / ALGEBRAIC[tau_rel];
  RATES[Jrelp] = (ALGEBRAIC[Jrel_infp] - STATES[Jrelp]) / ALGEBRAIC[tau_relp];
  RATES[ki] =
      (-((ALGEBRAIC[Ito] + ALGEBRAIC[IKr] + ALGEBRAIC[IKs] + ALGEBRAIC[IK1] + ALGEBRAIC[IKb] + ALGEBRAIC[Istim]) - 2.00000 * ALGEBRAIC[INaK]) *
       CONSTANTS[cm] * CONSTANTS[Acap]) /
          (CONSTANTS[F] * CONSTANTS[vmyo]) +
      (ALGEBRAIC[JdiffK] * CONSTANTS[vss]) / CONSTANTS[vmyo];
  RATES[kss] = (-ALGEBRAIC[ICaK] * CONSTANTS[cm] * CONSTANTS[Acap]) / (CONSTANTS[F] * CONSTANTS[vss]) - ALGEBRAIC[JdiffK];
  RATES[nai] = (-(ALGEBRAIC[INa] + ALGEBRAIC[INaL] + 3.00000 * ALGEBRAIC[INaCa_i] + 3.00000 * ALGEBRAIC[INaK] + ALGEBRAIC[INab]) * CONSTANTS[Acap] *
                CONSTANTS[cm]) /
                   (CONSTANTS[F] * CONSTANTS[vmyo]) +
               (ALGEBRAIC[JdiffNa] * CONSTANTS[vss]) / CONSTANTS[vmyo];
  RATES[nass] =
      (-(ALGEBRAIC[ICaNa] + 3.00000 * ALGEBRAIC[INaCa_ss]) * CONSTANTS[cm] * CONSTANTS[Acap]) / (CONSTANTS[F] * CONSTANTS[vss]) - ALGEBRAIC[JdiffNa];
  RATES[V] = -(ALGEBRAIC[INa] + ALGEBRAIC[INaL] + ALGEBRAIC[Ito] + ALGEBRAIC[ICaL] + ALGEBRAIC[ICaNa] + ALGEBRAIC[ICaK] + ALGEBRAIC[IKr] +
               ALGEBRAIC[IKs] + ALGEBRAIC[IK1] + ALGEBRAIC[INaCa_i] + ALGEBRAIC[INaCa_ss] + ALGEBRAIC[INaK] + ALGEBRAIC[INab] + ALGEBRAIC[IKb] +
               ALGEBRAIC[IpCa] + ALGEBRAIC[ICab] + ALGEBRAIC[Istim]);
  RATES[cass] = ALGEBRAIC[Bcass] *
                (((-(ALGEBRAIC[ICaL] - 2.00000 * ALGEBRAIC[INaCa_ss]) * CONSTANTS[cm] * CONSTANTS[Acap]) / (2.00000 * CONSTANTS[F] * CONSTANTS[vss]) +
                  (ALGEBRAIC[Jrel] * CONSTANTS[vjsr]) / CONSTANTS[vss]) -
                 ALGEBRAIC[Jdiff]);

  //   dXS = xb_ws - xb_su - xb_su_gamma
  //   dXW = xb_uw - xb_wu - xb_ws - xb_wu_gamma
  RATES[XS] = ALGEBRAIC[xb_ws] - ALGEBRAIC[xb_su] - ALGEBRAIC[xb_su_gamma];
  RATES[XW] = ALGEBRAIC[xb_uw] - ALGEBRAIC[xb_wu] - ALGEBRAIC[xb_ws] - ALGEBRAIC[xb_wu_gamma];

  // dCa_TRPN = koff * (((cai * 1000) / ca50)^TRPN_n * (1 - Ca_TRPN) - Ca_TRPN)
  RATES[Ca_TRPN] = CONSTANTS[koff] * (pow(((STATES[cai] * 1000) / CONSTANTS[ca50]), CONSTANTS[TRPN_n]) * (1 - STATES[Ca_TRPN]) - STATES[Ca_TRPN]);

  // dTmBlocked = ktm_block * min(100, (Ca_TRPN^-(nperm / 2))) * XU - ktm_unblock * (Ca_TRPN^(nperm / 2)) * TmBlocked
  //   dZETAS = A * lambda_rate - cds * ZETAS
  //   dZETAW = A * lambda_rate - cdw * ZETAW
  double invCaPerm = pow(STATES[Ca_TRPN], -(CONSTANTS[nperm] / 2));
  double invCaPermCap = fmin(invCaPerm, 100.0);
  RATES[TmBlocked] =
      ALGEBRAIC[ktm_block] * invCaPermCap * ALGEBRAIC[XU] - CONSTANTS[ktm_unblock] * pow(STATES[Ca_TRPN], (CONSTANTS[nperm] / 2)) * STATES[TmBlocked];
  RATES[ZETAS] = CONSTANTS[A] * CONSTANTS[lambda_rate] - ALGEBRAIC[cds] * STATES[ZETAS];
  RATES[ZETAW] = CONSTANTS[A] * CONSTANTS[lambda_rate] - ALGEBRAIC[cdw] * STATES[ZETAW];

  // dcai = Bcai * (-(ICaL_i + IpCa + ICab - 2.0 * INaCa_i) * Acap / (2.0 * F * vmyo) - Jup * vnsr / vmyo + Jdiff * vss / vmyo - dCa_TRPN * trpnmax)
  RATES[cai] =
      ALGEBRAIC[Bcai] * (-(ALGEBRAIC[IpCa] + ALGEBRAIC[ICab] - 2.00000 * ALGEBRAIC[INaCa_i]) * CONSTANTS[cm] * CONSTANTS[Acap] /
                              (2.00000 * CONSTANTS[F] * CONSTANTS[vmyo]) - ALGEBRAIC[Jup] * CONSTANTS[vnsr] / CONSTANTS[vmyo] +
                         ALGEBRAIC[Jdiff] * CONSTANTS[vss] / CONSTANTS[vmyo] - RATES[Ca_TRPN] * CONSTANTS[trpnmax]);  // Adding TRPN term
      RATES[cansr] = ALGEBRAIC[Jup] - (ALGEBRAIC[Jtr] * CONSTANTS[vjsr]) / CONSTANTS[vnsr];
  RATES[cajsr] = ALGEBRAIC[Bcajsr] * (ALGEBRAIC[Jtr] - ALGEBRAIC[Jrel]);
}

void ORd_Land::___applyDrugEffect(double conc, double *hill)
{
 CONSTANTS[PCa_b] *= ((hill[0] > 10E-14 && hill[1] > 10E-14) ? 1./(1.+pow(conc/hill[0],hill[1])) : 1.);
 CONSTANTS[GK1_b] *= ((hill[2] > 10E-14 && hill[3] > 10E-14) ? 1./(1.+pow(conc/hill[2],hill[3])) : 1.);
 CONSTANTS[GKs_b] *= ((hill[4] > 10E-14 && hill[5] > 10E-14) ? 1./(1.+pow(conc/hill[4],hill[5])) : 1.);
 CONSTANTS[GNa] *= ((hill[6] > 10E-14 && hill[7] > 10E-14) ? 1./(1.+pow(conc/hill[6],hill[7])) : 1.);
 CONSTANTS[GNaL_b] *= ((hill[8] > 10E-14 && hill[9] > 10E-14) ? 1./(1.+pow(conc/hill[8],hill[9])) : 1.);
 CONSTANTS[Gto_b] *= ((hill[10] > 10E-14 && hill[11] > 10E-14) ? 1./(1.+pow(conc/hill[10],hill[11])) : 1.);
 //CONSTANTS[GKr_b] = CONSTANTS[GKr_b] * ((hill[12] > 10E-14 && hill[13] > 10E-14) ? 1./(1.+pow(conc/hill[12],hill[13])) : 1.);
}

void ORd_Land::___applyHERGBinding(double conc, double *herg)
{
  CONSTANTS[Kmax] = herg[0];
  CONSTANTS[Ku] = herg[1];
  CONSTANTS[n] = herg[2];
  CONSTANTS[halfmax] = herg[3];
  CONSTANTS[Vhalf] = herg[4];
  CONSTANTS[cnc] = conc;
  STATES[D] = CONSTANTS[cnc];
  CONSTANTS[Kt] = 0.000035;
}

void ORd_Land::___applyCVar(double* cvar) {
  CONSTANTS[GNa] *= cvar[0];		// GNa
  CONSTANTS[GNaL] *= cvar[1];		// GNaL
  CONSTANTS[Gto] *= cvar[2];		// Gto
  CONSTANTS[GKr] *= cvar[3];		// GKr
  CONSTANTS[GKs] *= cvar[4];		// GKs
  CONSTANTS[GK1] *= cvar[5];		// GK1
  CONSTANTS[Gncx] *= cvar[6];		// GNaCa
  CONSTANTS[GKb] *= cvar[7];		// GKb
  CONSTANTS[PCa] *= cvar[8];		// PCa
  CONSTANTS[Pnak] *= cvar[9];		// INaK
  CONSTANTS[PNab] *= cvar[10];		// PNab
  CONSTANTS[PCab] *= cvar[11];		// PCab
  CONSTANTS[GpCa] *= cvar[12];		// GpCa
  CONSTANTS[KmCaMK] *= cvar[17];	// KCaMK

  // Additional constants
  CONSTANTS[Jrel_b] *= cvar[13];	// SERCA_Total (release)
  CONSTANTS[Jup_b] *= cvar[14];	// RyR_Total (uptake)
  CONSTANTS[Jtr_b] *= cvar[15];	// Trans_Total (NSR to JSR translocation)
  CONSTANTS[Jleak_b] *= cvar[16];	// Leak_Total (Ca leak from NSR)
}
