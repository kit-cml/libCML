#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "Tomek_Land.hpp"

Tomek_Land::Tomek_Land()
{
  algebraic_size = 242;
  constants_size = 188; // Add 2 constant for scaling factor, Jtr and Jleak
  states_size = 49;
  ALGEBRAIC = new double[algebraic_size];
  CONSTANTS = new double[constants_size];
  RATES = new double[states_size];
  STATES = new double[states_size];
}


Tomek_Land::~Tomek_Land()
{
  delete[] ALGEBRAIC;
  delete[] CONSTANTS;
  delete[] RATES;
  delete[] STATES;
}

void Tomek_Land::___initConsts(double type) {
  CONSTANTS[celltype] = type;
  CONSTANTS[nao] = 140.0;
  CONSTANTS[cao] = 1.8;
  CONSTANTS[ko] = 5.0;
  CONSTANTS[clo] = 150.0;
  CONSTANTS[R] = 8314;
  CONSTANTS[T] = 310;
  CONSTANTS[F] = 96485;
  CONSTANTS[zna] = 1;
  CONSTANTS[zca] = 2;
  CONSTANTS[zk] = 1;
  CONSTANTS[zcl] = -1;
  CONSTANTS[L] = 0.01;
  CONSTANTS[rad] = 0.0011;
  STATES[V] = (CONSTANTS[celltype] == 1.00000 ? -89.14 : CONSTANTS[celltype] == 2.00000 ? -89.1704 : -88.7638);
  CONSTANTS[stim_start] = 10;
#ifdef TISSUE
  CONSTANTS[stim_start] = 0.4;
#endif
  CONSTANTS[stim_end] = 100000000000000000;
  CONSTANTS[amp] = -53;
  CONSTANTS[BCL] = 1000;
  CONSTANTS[duration] = 1.0;
  CONSTANTS[KmCaMK] = 0.15;
  CONSTANTS[aCaMK] = 0.05;
  CONSTANTS[bCaMK] = 0.00068;
  CONSTANTS[CaMKo] = 0.05;
  CONSTANTS[KmCaM] = 0.0015;
  STATES[CaMKt] = (CONSTANTS[celltype] == 1.00000 ? 0.0129 : CONSTANTS[celltype] == 2.00000 ? 0.0192 : 0.0111);
  STATES[cass] = (CONSTANTS[celltype] == 1.00000 ? 5.77E-05 : CONSTANTS[celltype] == 2.00000 ? 6.58E-05 : 7.0305e-5);
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
  STATES[nai] = (CONSTANTS[celltype] == 1.00000 ? 12.1025 : CONSTANTS[celltype] == 2.00000 ? 15.0038 : 12.1025);
  STATES[nass] = (CONSTANTS[celltype] == 1.00000 ? 12.8366 : CONSTANTS[celltype] == 2.00000 ? 15.0043 : 12.1029);
  STATES[ki] = (CONSTANTS[celltype] == 1.00000 ? 142.6951 : CONSTANTS[celltype] == 2.00000 ? 143.0403 : 142.3002);
  STATES[kss] = (CONSTANTS[celltype] == 1.00000 ? 142.6951 : CONSTANTS[celltype] == 2.00000 ? 143.0402 : 142.3002);
  STATES[cansr] = (CONSTANTS[celltype] == 1.00000 ? 1.8119 : CONSTANTS[celltype] == 2.00000 ? 1.9557 : 1.5211);
  STATES[cajsr] = (CONSTANTS[celltype] == 1.00000 ? 1.8102 : CONSTANTS[celltype] == 2.00000 ? 1.9593 : 1.5214);
  STATES[cai] = (CONSTANTS[celltype] == 1.00000 ? 6.63E-05 : CONSTANTS[celltype] == 2.00000 ? 8.17E-05 : 8.1583e-05);
  CONSTANTS[cli] = 24.0;
  CONSTANTS[PKNa] = 0.01833;
  CONSTANTS[gkatp] = 4.3195;
  CONSTANTS[fkatp] = 0.0;
  CONSTANTS[K_o_n] = 5;
  CONSTANTS[A_atp] = 2;
  CONSTANTS[K_atp] = 0.25;
  STATES[m] = (CONSTANTS[celltype] == 1.00000 ? 7.43E-04 : CONSTANTS[celltype] == 2.00000 ? 7.38E-04 : 8.0572e-4);
  STATES[h] = (CONSTANTS[celltype] == 1.00000 ? 0.836 : CONSTANTS[celltype] == 2.00000 ? 0.8365 : 0.8286);
  STATES[j] = (CONSTANTS[celltype] == 1.00000 ? 0.8359 : CONSTANTS[celltype] == 2.00000 ? 0.8363 : 0.8284);
  STATES[hp] = (CONSTANTS[celltype] == 1.00000 ? 0.6828 : CONSTANTS[celltype] == 2.00000 ? 0.6838 : 0.6707);
  STATES[jp] = (CONSTANTS[celltype] == 1.00000 ? 0.8357 : CONSTANTS[celltype] == 2.00000 ? 0.8358 : 0.8281);
  CONSTANTS[GNa] = 11.7802;
  STATES[mL] = (CONSTANTS[celltype] == 1.00000 ? 1.52E-04 : CONSTANTS[celltype] == 2.00000 ? 1.51E-04 : 1.629e-4);
  CONSTANTS[thL] = 200;
  STATES[hL] = (CONSTANTS[celltype] == 1.00000 ? 0.5401 : CONSTANTS[celltype] == 2.00000 ? 0.5327 : 0.5255);
  STATES[hLp] = (CONSTANTS[celltype] == 1.00000 ? 0.3034 : CONSTANTS[celltype] == 2.00000 ? 0.2834 : 0.2872);
  CONSTANTS[GNaL_b] = 0.0279;
  CONSTANTS[Gto_b] = 0.16;
  STATES[a] = (CONSTANTS[celltype] == 1.00000 ? 9.27E-04 : CONSTANTS[celltype] == 2.00000 ? 9.25E-04 : 9.5098e-4);
  CONSTANTS[EKshift] = 0;
  STATES[iF] = 0.9996;
  STATES[iS] = (CONSTANTS[celltype] == 1.00000 ? 0.9996 : CONSTANTS[celltype] == 2.00000 ? 0.5671 : 0.5936);
  STATES[ap] = (CONSTANTS[celltype] == 1.00000 ? 4.72E-04 : CONSTANTS[celltype] == 2.00000 ? 4.71E-04 : 4.8454e-4);
  STATES[iFp] = 0.9996;
  STATES[iSp] = (CONSTANTS[celltype] == 1.00000 ? 0.9996 : CONSTANTS[celltype] == 2.00000 ? 0.6261 : 0.6538);
  CONSTANTS[Kmn] = 0.002;
  CONSTANTS[k2n] = 500;
  CONSTANTS[PCa_b] = 8.3757e-05;
  STATES[d] = (CONSTANTS[celltype] == 1.00000 ? 0.0 : CONSTANTS[celltype] == 2.00000 ? 0.0 : 8.1084e-9);
  CONSTANTS[Aff] = 0.6;
  STATES[ff] = 1.0;
  STATES[fs] = (CONSTANTS[celltype] == 1.00000 ? 0.9485 : CONSTANTS[celltype] == 2.00000 ? 0.92 : 0.939);
  STATES[fcaf] = 1.0;
  STATES[fcas] = 0.9999;
  STATES[jca] = 1.0;
  STATES[ffp] = 1.0;
  STATES[fcafp] = 1.0;
  STATES[nca_ss] = (CONSTANTS[celltype] == 1.00000 ? 3.09E-04 : CONSTANTS[celltype] == 2.00000 ? 5.14E-04 : 6.6462e-4);
  STATES[nca_i] = (CONSTANTS[celltype] == 1.00000 ? 5.30E-04 : CONSTANTS[celltype] == 2.00000 ? 0.0012 : 0.0012);
  CONSTANTS[tjca] = 75;
  CONSTANTS[vShift] = 0;
  CONSTANTS[offset] = 0;
  CONSTANTS[dielConstant] = 74;
  CONSTANTS[ICaL_fractionSS] = 0.8;
  CONSTANTS[GKr_b] = 0.0321;
  STATES[C1] = (CONSTANTS[celltype] == 1.00000 ? 6.79E-04 : CONSTANTS[celltype] == 2.00000 ? 6.96E-04 : 7.0344e-4);
  STATES[C2] = (CONSTANTS[celltype] == 1.00000 ? 8.29E-04 : CONSTANTS[celltype] == 2.00000 ? 8.27E-04 : 8.5109e-4);
  STATES[C3] = (CONSTANTS[celltype] == 1.00000 ? 0.9982 : CONSTANTS[celltype] == 2.00000 ? 0.9979 : 0.9981);
  STATES[I] = (CONSTANTS[celltype] == 1.00000 ? 9.54E-06 : CONSTANTS[celltype] == 2.00000 ? 1.88E-05 : 1.3289e-5);
  STATES[O] = (CONSTANTS[celltype] == 1.00000 ? 2.76E-04 : CONSTANTS[celltype] == 2.00000 ? 5.42E-04 : 3.7585e-4);
  CONSTANTS[alpha_1] = 0.154375;
  CONSTANTS[beta_1] = 0.1911;
  CONSTANTS[GKs_b] = 0.0011;
  STATES[xs1] = (CONSTANTS[celltype] == 1.00000 ? 0.2309 : CONSTANTS[celltype] == 2.00000 ? 0.2653 : 0.248);
  STATES[xs2] = (CONSTANTS[celltype] == 1.00000 ? 1.70E-04 : CONSTANTS[celltype] == 2.00000 ? 1.69E-04 : 1.7707e-4);
  CONSTANTS[GK1_b] = 0.6992;
  CONSTANTS[INaCa_fractionSS] = 0.35;
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
  CONSTANTS[Gncx_b] = 0.0034;
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
  CONSTANTS[Pnak_b] = 15.4509;
  CONSTANTS[GKb_b] = 0.0189;
  CONSTANTS[PNab] = 1.9239e-09;
  CONSTANTS[PCab] = 5.9194e-08;
  CONSTANTS[GpCa] = 5e-04;
  CONSTANTS[KmCap] = 0.0005;
  CONSTANTS[GClCa] = 0.2843;
  CONSTANTS[GClb] = 1.98e-3;
  CONSTANTS[KdClCa] = 0.1;
  CONSTANTS[Fjunc] = 1;
  CONSTANTS[tauNa] = 2.0;
  CONSTANTS[tauK] = 2.0;
  CONSTANTS[tauCa] = 0.2;
  CONSTANTS[bt] = 4.75;
  STATES[Jrel_np] = (CONSTANTS[celltype] == 1.00000 ? 2.82E-24 : CONSTANTS[celltype] == 2.00000 ? 0. : 1.6129e-22);
  STATES[Jrel_p] = (CONSTANTS[celltype] == 1.00000 ? 0. : CONSTANTS[celltype] == 2.00000 ? 0. : 1.2475e-20);
  CONSTANTS[cajsr_half] = 1.7;
  CONSTANTS[Jrel_b] = 1.5378;
  CONSTANTS[Jup_b] = 1.0;
  // CVAR: Additional scaling factor for Jleak and Jtr
  CONSTANTS[Jtr_b] = 1.0;    // Trans_Total (NSR to JSR translocation)
  CONSTANTS[Jleak_b] = 1.0;  // Leak_Total (Ca leak from NSR)
  CONSTANTS[vcell] = 1000.00 * 3.14000 * CONSTANTS[rad] * CONSTANTS[rad] * CONSTANTS[L];
  CONSTANTS[cmdnmax] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[cmdnmax_b] * 1.30000 : CONSTANTS[cmdnmax_b]);
  CONSTANTS[ECl] = ((CONSTANTS[R] * CONSTANTS[T]) / (CONSTANTS[zcl] * CONSTANTS[F])) * log(CONSTANTS[clo] / CONSTANTS[cli]);
  CONSTANTS[akik] = pow(CONSTANTS[ko] / CONSTANTS[K_o_n], 0.240000);
  CONSTANTS[bkik] = 1.00000 / (1.00000 + pow(CONSTANTS[A_atp] / CONSTANTS[K_atp], 2.00000));
  CONSTANTS[thLp] = 3.00000 * CONSTANTS[thL];
  CONSTANTS[GNaL] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GNaL_b] * 0.600000 : CONSTANTS[GNaL_b]);
  CONSTANTS[Gto] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[Gto_b] * 2.00000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[Gto_b] * 2.00000
                                                     : CONSTANTS[Gto_b]);
  CONSTANTS[Afs] = 1.00000 - CONSTANTS[Aff];
  CONSTANTS[PCa] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[PCa_b] * 1.20000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[PCa_b] * 2.00000
                                                     : CONSTANTS[PCa_b]);
  CONSTANTS[Io] = (0.500000 * (CONSTANTS[nao] + CONSTANTS[ko] + CONSTANTS[clo] + 4.00000 * CONSTANTS[cao])) / 1000.00;
  CONSTANTS[GKr] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[GKr_b] * 1.30000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[GKr_b] * 0.800000
                                                     : CONSTANTS[GKr_b]);
  CONSTANTS[GKs] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GKs_b] * 1.40000 : CONSTANTS[GKs_b]);
  CONSTANTS[GK1] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[GK1_b] * 1.20000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[GK1_b] * 1.30000
                                                     : CONSTANTS[GK1_b]);
  CONSTANTS[GKb] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GKb_b] * 0.600000 : CONSTANTS[GKb_b]);
  CONSTANTS[a_rel] = (0.500000 * CONSTANTS[bt]) / 1.00000;
  CONSTANTS[btp] = 1.25000 * CONSTANTS[bt];
  CONSTANTS[upScale] = (CONSTANTS[celltype] == 1.00000 ? 1.30000 : 1.00000);
  CONSTANTS[Ageo] = 2.00000 * 3.14000 * CONSTANTS[rad] * CONSTANTS[rad] + 2.00000 * 3.14000 * CONSTANTS[rad] * CONSTANTS[L];
  CONSTANTS[PCap] = 1.10000 * CONSTANTS[PCa];
  CONSTANTS[PCaNa] = 0.00125000 * CONSTANTS[PCa];
  CONSTANTS[PCaK] = 0.000357400 * CONSTANTS[PCa];
  CONSTANTS[constA] = 1.82000e+06 * pow(CONSTANTS[dielConstant] * CONSTANTS[T], -1.50000);
  CONSTANTS[a_relp] = (0.500000 * CONSTANTS[btp]) / 1.00000;
  CONSTANTS[Acap] = 2.00000 * CONSTANTS[Ageo];
  CONSTANTS[PCaNap] = 0.00125000 * CONSTANTS[PCap];
  CONSTANTS[PCaKp] = 0.000357400 * CONSTANTS[PCap];
  CONSTANTS[gamma_cao] =
      exp(-CONSTANTS[constA] * 4.00000 * (pow(CONSTANTS[Io], 1.0 / 2) / (1.00000 + pow(CONSTANTS[Io], 1.0 / 2)) - 0.300000 * CONSTANTS[Io]));
  CONSTANTS[gamma_nao] =
      exp(-CONSTANTS[constA] * 1.00000 * (pow(CONSTANTS[Io], 1.0 / 2) / (1.00000 + pow(CONSTANTS[Io], 1.0 / 2)) - 0.300000 * CONSTANTS[Io]));
  CONSTANTS[gamma_ko] =
      exp(-CONSTANTS[constA] * 1.00000 * (pow(CONSTANTS[Io], 1.0 / 2) / (1.00000 + pow(CONSTANTS[Io], 1.0 / 2)) - 0.300000 * CONSTANTS[Io]));
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
  CONSTANTS[ktm_unblock] = 0.021;  // Tomek: 0.021, ORd: 0.04

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
  CONSTANTS[nperm] = 2.036;  // Tomek: 2.036, ORd: 2.4
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

void Tomek_Land::___applyCVar(double *cvar)
{
  CONSTANTS[GNa] *= cvar[0];     // GNa
  CONSTANTS[GNaL_b] *= cvar[1];  // GNaL
  CONSTANTS[Gto_b] *= cvar[2];   // Gto
  CONSTANTS[GKr_b] *= cvar[3];   // GKr
  CONSTANTS[GKs_b] *= cvar[4];   // GKs
  CONSTANTS[GK1_b] *= cvar[5];   // GK1
  CONSTANTS[Gncx_b] *= cvar[6];  // GNaCa
  CONSTANTS[GKb_b] *= cvar[7];   // GKb
  CONSTANTS[PCa_b] *= cvar[8];   // PCa
  CONSTANTS[Pnak_b] *= cvar[9];  // INaK
  CONSTANTS[PNab] *= cvar[10];   // PNab
  CONSTANTS[PCab] *= cvar[11];   // PCab
  CONSTANTS[GpCa] *= cvar[12];   // GpCa
  CONSTANTS[KmCaMK] *= cvar[17]; // KCaMK

  // Additional constants
  CONSTANTS[Jrel_b] *= cvar[13];  // SERCA_Total (release)
  CONSTANTS[Jup_b] *= cvar[14];   // RyR_Total (uptake)
  CONSTANTS[Jtr_b] *= cvar[15];   // Trans_Total (NSR to JSR translocation)
  CONSTANTS[Jleak_b] *= cvar[16]; // Leak_Total (Ca leak from NSR)
}

void Tomek_Land::___applyDrugEffect(double conc, double *hill)
{
  CONSTANTS[PCa_b] = CONSTANTS[PCa_b] * ((hill[0] > 10E-14 && hill[1] > 10E-14) ? 1. / (1. + pow(conc / hill[0], hill[1])) : 1.);
  CONSTANTS[GK1_b] = CONSTANTS[GK1_b] * ((hill[2] > 10E-14 && hill[3] > 10E-14) ? 1. / (1. + pow(conc / hill[2], hill[3])) : 1.);
  CONSTANTS[GKs_b] = CONSTANTS[GKs_b] * ((hill[4] > 10E-14 && hill[5] > 10E-14) ? 1. / (1. + pow(conc / hill[4], hill[5])) : 1.);
  CONSTANTS[GNa] = CONSTANTS[GNa] * ((hill[6] > 10E-14 && hill[7] > 10E-14) ? 1. / (1. + pow(conc / hill[6], hill[7])) : 1.);
  CONSTANTS[GNaL_b] = CONSTANTS[GNaL_b] * ((hill[8] > 10E-14 && hill[9] > 10E-14) ? 1. / (1. + pow(conc / hill[8], hill[9])) : 1.);
  CONSTANTS[Gto_b] = CONSTANTS[Gto_b] * ((hill[10] > 10E-14 && hill[11] > 10E-14) ? 1. / (1. + pow(conc / hill[10], hill[11])) : 1.);
  CONSTANTS[GKr_b] = CONSTANTS[GKr_b] * ((hill[12] > 10E-14 && hill[13] > 10E-14) ? 1. / (1. + pow(conc / hill[12], hill[13])) : 1.);
}

void Tomek_Land::initConsts()
{
  ___initConsts(0.);
}

void Tomek_Land::initConsts(double type)
{
  ___initConsts(type);
}

void Tomek_Land::initConsts(double type, double conc, double *hill)
{
  ___initConsts(type);
  ___applyDrugEffect(conc, hill);
}

void Tomek_Land::initConsts(double type, double conc, double *hill, double *cvar)
{
  initConsts(type, conc, hill);
  ___applyCVar(cvar);
}

void Tomek_Land::computeRates(double TIME, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC)
{
  CONSTANTS[cmdnmax] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[cmdnmax_b] * 1.30000 : CONSTANTS[cmdnmax_b]);
  CONSTANTS[GNaL] = (CONSTANTS[celltype] == 1.00000 ? CONSTANTS[GNaL_b] * 0.600000 : CONSTANTS[GNaL_b]);
  CONSTANTS[Gto] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[Gto_b] * 2.00000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[Gto_b] * 2.00000
                                                     : CONSTANTS[Gto_b]);
  CONSTANTS[PCa] = (CONSTANTS[celltype] == 1.00000   ? CONSTANTS[PCa_b] * 1.20000
                    : CONSTANTS[celltype] == 2.00000 ? CONSTANTS[PCa_b] * 1.80000
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
  if (isS1)
    ALGEBRAIC[Istim] = CONSTANTS[amp];
  else
    ALGEBRAIC[Istim] = 0.0;
#else
  ALGEBRAIC[Istim] =
      (TIME >= CONSTANTS[stim_start] && TIME <= CONSTANTS[stim_end] &&
               (TIME - CONSTANTS[stim_start]) - floor((TIME - CONSTANTS[stim_start]) / CONSTANTS[BCL]) * CONSTANTS[BCL] <= CONSTANTS[duration]
           ? CONSTANTS[amp]
           : 0.00000);
#endif

  ALGEBRAIC[vffrt] = (STATES[V] * CONSTANTS[F] * CONSTANTS[F]) / (CONSTANTS[R] * CONSTANTS[T]);
  ALGEBRAIC[vfrt] = (STATES[V] * CONSTANTS[F]) / (CONSTANTS[R] * CONSTANTS[T]);

  ALGEBRAIC[ENa] = ((CONSTANTS[R] * CONSTANTS[T]) / (CONSTANTS[zna] * CONSTANTS[F])) * log(CONSTANTS[nao] / STATES[nai]);
  ALGEBRAIC[EK] = ((CONSTANTS[R] * CONSTANTS[T]) / (CONSTANTS[zk] * CONSTANTS[F])) * log(CONSTANTS[ko] / STATES[ki]);
  ALGEBRAIC[EKs] = ((CONSTANTS[R] * CONSTANTS[T]) / (CONSTANTS[zk] * CONSTANTS[F])) *
                   log((CONSTANTS[ko] + CONSTANTS[PKNa] * CONSTANTS[nao]) / (STATES[ki] + CONSTANTS[PKNa] * STATES[nai]));

  ALGEBRAIC[CaMKb] = (CONSTANTS[CaMKo] * (1.00000 - STATES[CaMKt])) / (1.00000 + CONSTANTS[KmCaM] / STATES[cass]);
  ALGEBRAIC[CaMKa] = ALGEBRAIC[CaMKb] + STATES[CaMKt];

  ALGEBRAIC[fINap] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[fINaLp] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[fICaLp] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[fJrelp] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[fItop] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[fJupp] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[fItop] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);
  ALGEBRAIC[fJrelp] = 1.00000 / (1.00000 + CONSTANTS[KmCaMK] / ALGEBRAIC[CaMKa]);

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
  // Computing INa...
  ALGEBRAIC[mss] = 1.00000 / pow(1.00000 + exp(-(STATES[V] + 56.8600) / 9.03000), 2.00000);
  ALGEBRAIC[tm] = 0.129200 * exp(-pow((STATES[V] + 45.7900) / 15.5400, 2.00000)) + 0.0648700 * exp(-pow((STATES[V] - 4.82300) / 51.1200, 2.00000));

  ALGEBRAIC[ah] = (STATES[V] >= -40.0000 ? 0.00000 : 0.0570000 * exp(-(STATES[V] + 80.0000) / 6.80000));
  ALGEBRAIC[bh] = (STATES[V] >= -40.0000 ? 0.770000 / (0.130000 * (1.00000 + exp(-(STATES[V] + 10.6600) / 11.1000)))
                                         : 2.70000 * exp(0.0790000 * STATES[V]) + 310000. * exp(0.348500 * STATES[V]));
  ALGEBRAIC[th] = 1.00000 / (ALGEBRAIC[ah] + ALGEBRAIC[bh]);
  ALGEBRAIC[hss] = 1.00000 / pow(1.00000 + exp((STATES[V] + 71.5500) / 7.43000), 2.00000);
  ALGEBRAIC[aj] =
      (STATES[V] >= -40.0000 ? 0.00000
                             : ((-25428.0 * exp(0.244400 * STATES[V]) - 6.94800e-06 * exp(-0.0439100 * STATES[V])) * (STATES[V] + 37.7800)) /
                                   (1.00000 + exp(0.311000 * (STATES[V] + 79.2300))));
  ALGEBRAIC[bj] = (STATES[V] >= -40.0000 ? (0.600000 * exp(0.0570000 * STATES[V])) / (1.00000 + exp(-0.100000 * (STATES[V] + 32.0000)))
                                         : (0.0242400 * exp(-0.0105200 * STATES[V])) / (1.00000 + exp(-0.137800 * (STATES[V] + 40.1400))));
  ALGEBRAIC[tj] = 1.00000 / (ALGEBRAIC[aj] + ALGEBRAIC[bj]);
  ALGEBRAIC[jss] = ALGEBRAIC[hss];
  ALGEBRAIC[hssp] = 1.00000 / pow(1.00000 + exp((STATES[V] + 77.5500) / 7.43000), 2.00000);
  ALGEBRAIC[tjp] = 1.46000 * ALGEBRAIC[tj];
  ALGEBRAIC[INa] = CONSTANTS[GNa] * (STATES[V] - ALGEBRAIC[ENa]) * pow(STATES[m], 3.00000) *
                   ((1.00000 - ALGEBRAIC[fINap]) * STATES[h] * STATES[j] + ALGEBRAIC[fINap] * STATES[hp] * STATES[jp]);
  // Computing INa done..

  // printf("Computing INaL...\n");
  ALGEBRAIC[mLss] = 1.00000 / (1.00000 + exp(-(STATES[V] + 42.8500) / 5.26400));
  ALGEBRAIC[tmL] = 0.129200 * exp(-pow((STATES[V] + 45.7900) / 15.5400, 2.00000)) + 0.0648700 * exp(-pow((STATES[V] - 4.82300) / 51.1200, 2.00000));
  ALGEBRAIC[hLss] = 1.00000 / (1.00000 + exp((STATES[V] + 87.6100) / 7.48800));
  ALGEBRAIC[hLssp] = 1.00000 / (1.00000 + exp((STATES[V] + 93.8100) / 7.48800));
  ALGEBRAIC[jcass] = 1.00000 / (1.00000 + exp((STATES[V] + 18.0800) / 2.79160));
  ALGEBRAIC[INaL] =
      CONSTANTS[GNaL] * (STATES[V] - ALGEBRAIC[ENa]) * STATES[mL] * ((1.00000 - ALGEBRAIC[fINaLp]) * STATES[hL] + ALGEBRAIC[fINaLp] * STATES[hLp]);
  // Computing INaL done..

  // printf("Computing Ito...\n");
  ALGEBRAIC[ass] = 1.00000 / (1.00000 + exp(-((STATES[V] + CONSTANTS[EKshift]) - 14.3400) / 14.8200));
  ALGEBRAIC[ta] = 1.05150 / (1.00000 / (1.20890 * (1.00000 + exp(-((STATES[V] + CONSTANTS[EKshift]) - 18.4099) / 29.3814))) +
                             3.50000 / (1.00000 + exp((STATES[V] + CONSTANTS[EKshift] + 100.000) / 29.3814)));
  ALGEBRAIC[iss] = 1.00000 / (1.00000 + exp((STATES[V] + CONSTANTS[EKshift] + 43.9400) / 5.71100));
  ALGEBRAIC[delta_epi] =
      (CONSTANTS[celltype] == 1.00000 ? 1.00000 - 0.950000 / (1.00000 + exp((STATES[V] + CONSTANTS[EKshift] + 70.0000) / 5.00000)) : 1.00000);
  ALGEBRAIC[tiF_b] = 4.56200 + 1.00000 / (0.393300 * exp(-(STATES[V] + CONSTANTS[EKshift] + 100.000) / 100.000) +
                                          0.0800400 * exp((STATES[V] + CONSTANTS[EKshift] + 50.0000) / 16.5900));
  ALGEBRAIC[tiF] = ALGEBRAIC[tiF_b] * ALGEBRAIC[delta_epi];
  ALGEBRAIC[tiS_b] = 23.6200 + 1.00000 / (0.00141600 * exp(-(STATES[V] + CONSTANTS[EKshift] + 96.5200) / 59.0500) +
                                          1.78000e-08 * exp((STATES[V] + CONSTANTS[EKshift] + 114.100) / 8.07900));
  ALGEBRAIC[tiS] = ALGEBRAIC[tiS_b] * ALGEBRAIC[delta_epi];
  ALGEBRAIC[AiF] = 1.00000 / (1.00000 + exp(((STATES[V] + CONSTANTS[EKshift]) - 213.600) / 151.200));
  ALGEBRAIC[AiS] = 1.00000 - ALGEBRAIC[AiF];
  ALGEBRAIC[i] = ALGEBRAIC[AiF] * STATES[iF] + ALGEBRAIC[AiS] * STATES[iS];
  ALGEBRAIC[assp] = 1.00000 / (1.00000 + exp(-((STATES[V] + CONSTANTS[EKshift]) - 24.3400) / 14.8200));
  ALGEBRAIC[dti_develop] = 1.35400 + 0.000100000 / (exp(((STATES[V] + CONSTANTS[EKshift]) - 167.400) / 15.8900) +
                                                    exp(-((STATES[V] + CONSTANTS[EKshift]) - 12.2300) / 0.215400));
  ALGEBRAIC[dti_recover] = 1.00000 - 0.500000 / (1.00000 + exp((STATES[V] + CONSTANTS[EKshift] + 70.0000) / 20.0000));
  ALGEBRAIC[tiFp] = ALGEBRAIC[dti_develop] * ALGEBRAIC[dti_recover] * ALGEBRAIC[tiF];
  ALGEBRAIC[tiSp] = ALGEBRAIC[dti_develop] * ALGEBRAIC[dti_recover] * ALGEBRAIC[tiS];
  ALGEBRAIC[ip] = ALGEBRAIC[AiF] * STATES[iFp] + ALGEBRAIC[AiS] * STATES[iSp];
  ALGEBRAIC[Ito] = CONSTANTS[Gto] * (STATES[V] - ALGEBRAIC[EK]) *
                   ((1.00000 - ALGEBRAIC[fItop]) * STATES[a] * ALGEBRAIC[i] + ALGEBRAIC[fItop] * STATES[ap] * ALGEBRAIC[ip]);
  // Computing Ito done..

  // printf("Computing ICaL...\n");
  ALGEBRAIC[dss] = (STATES[V] >= 31.4978 ? 1.00000 : 1.07630 * exp(-1.00700 * exp(-0.0829000 * STATES[V])));
  ALGEBRAIC[td] =
      CONSTANTS[offset] + 0.600000 +
      1.00000 / (exp(-0.0500000 * (STATES[V] + CONSTANTS[vShift] + 6.00000)) + exp(0.0900000 * (STATES[V] + CONSTANTS[vShift] + 14.0000)));
  ALGEBRAIC[fss] = 1.00000 / (1.00000 + exp((STATES[V] + 19.5800) / 3.69600));
  ALGEBRAIC[tff] = 7.00000 + 1.00000 / (0.00450000 * exp(-(STATES[V] + 20.0000) / 10.0000) + 0.00450000 * exp((STATES[V] + 20.0000) / 10.0000));
  ALGEBRAIC[tfs] = 1000.00 + 1.00000 / (3.50000e-05 * exp(-(STATES[V] + 5.00000) / 4.00000) + 3.50000e-05 * exp((STATES[V] + 5.00000) / 6.00000));
  ALGEBRAIC[f] = CONSTANTS[Aff] * STATES[ff] + CONSTANTS[Afs] * STATES[fs];
  ALGEBRAIC[fcass] = ALGEBRAIC[fss];
  ALGEBRAIC[tfcaf] = 7.00000 + 1.00000 / (0.0400000 * exp(-(STATES[V] - 4.00000) / 7.00000) + 0.0400000 * exp((STATES[V] - 4.00000) / 7.00000));
  ALGEBRAIC[tfcas] = 100.000 + 1.00000 / (0.000120000 * exp(-STATES[V] / 3.00000) + 0.000120000 * exp(STATES[V] / 7.00000));
  ALGEBRAIC[Afcaf] = 0.300000 + 0.600000 / (1.00000 + exp((STATES[V] - 10.0000) / 10.0000));
  ALGEBRAIC[Afcas] = 1.00000 - ALGEBRAIC[Afcaf];
  ALGEBRAIC[fca] = ALGEBRAIC[Afcaf] * STATES[fcaf] + ALGEBRAIC[Afcas] * STATES[fcas];
  ALGEBRAIC[tffp] = 2.50000 * ALGEBRAIC[tff];
  ALGEBRAIC[fp] = CONSTANTS[Aff] * STATES[ffp] + CONSTANTS[Afs] * STATES[fs];
  ALGEBRAIC[tfcafp] = 2.50000 * ALGEBRAIC[tfcaf];
  ALGEBRAIC[fcap] = ALGEBRAIC[Afcaf] * STATES[fcafp] + ALGEBRAIC[Afcas] * STATES[fcas];
  ALGEBRAIC[km2n] = STATES[jca] * 1.00000;
  ALGEBRAIC[anca_ss] = 1.00000 / (CONSTANTS[k2n] / ALGEBRAIC[km2n] + pow(1.00000 + CONSTANTS[Kmn] / STATES[cass], 4.00000));
  ALGEBRAIC[anca_i] = 1.00000 / (CONSTANTS[k2n] / ALGEBRAIC[km2n] + pow(1.00000 + CONSTANTS[Kmn] / STATES[cai], 4.00000));
  ALGEBRAIC[Ii] = (0.500000 * (STATES[nai] + STATES[ki] + CONSTANTS[cli] + 4.00000 * STATES[cai])) / 1000.00;
  ALGEBRAIC[Iss] = (0.500000 * (STATES[nass] + STATES[kss] + CONSTANTS[cli] + 4.00000 * STATES[cass])) / 1000.00;
  ALGEBRAIC[gamma_cai] =
      exp(-CONSTANTS[constA] * 4.00000 * (pow(ALGEBRAIC[Ii], 1.0 / 2) / (1.00000 + pow(ALGEBRAIC[Ii], 1.0 / 2)) - 0.300000 * ALGEBRAIC[Ii]));
  ALGEBRAIC[gamma_nai] =
      exp(-CONSTANTS[constA] * 1.00000 * (pow(ALGEBRAIC[Ii], 1.0 / 2) / (1.00000 + pow(ALGEBRAIC[Ii], 1.0 / 2)) - 0.300000 * ALGEBRAIC[Ii]));
  ALGEBRAIC[gamma_ki] =
      exp(-CONSTANTS[constA] * 1.00000 * (pow(ALGEBRAIC[Ii], 1.0 / 2) / (1.00000 + pow(ALGEBRAIC[Ii], 1.0 / 2)) - 0.300000 * ALGEBRAIC[Ii]));
  ALGEBRAIC[gamma_cass] =
      exp(-CONSTANTS[constA] * 4.00000 * (pow(ALGEBRAIC[Iss], 1.0 / 2) / (1.00000 + pow(ALGEBRAIC[Iss], 1.0 / 2)) - 0.300000 * ALGEBRAIC[Iss]));
  ALGEBRAIC[gamma_kss] =
      exp(-CONSTANTS[constA] * 1.00000 * (pow(ALGEBRAIC[Iss], 1.0 / 2) / (1.00000 + pow(ALGEBRAIC[Iss], 1.0 / 2)) - 0.300000 * ALGEBRAIC[Iss]));
  ALGEBRAIC[gamma_nass] =
      exp(-CONSTANTS[constA] * 1.00000 * (pow(ALGEBRAIC[Iss], 1.0 / 2) / (1.00000 + pow(ALGEBRAIC[Iss], 1.0 / 2)) - 0.300000 * ALGEBRAIC[Iss]));
  ALGEBRAIC[PhiCaL_ss] =
      (4.00000 * ALGEBRAIC[vffrt] * (ALGEBRAIC[gamma_cass] * STATES[cass] * exp(2.00000 * ALGEBRAIC[vfrt]) - CONSTANTS[gamma_cao] * CONSTANTS[cao])) /
      (exp(2.00000 * ALGEBRAIC[vfrt]) - 1.00000);
  ALGEBRAIC[PhiCaNa_ss] =
      (1.00000 * ALGEBRAIC[vffrt] * (ALGEBRAIC[gamma_nass] * STATES[nass] * exp(1.00000 * ALGEBRAIC[vfrt]) - CONSTANTS[gamma_nao] * CONSTANTS[nao])) /
      (exp(1.00000 * ALGEBRAIC[vfrt]) - 1.00000);
  ALGEBRAIC[PhiCaK_ss] =
      (1.00000 * ALGEBRAIC[vffrt] * (ALGEBRAIC[gamma_kss] * STATES[kss] * exp(1.00000 * ALGEBRAIC[vfrt]) - CONSTANTS[gamma_ko] * CONSTANTS[ko])) /
      (exp(1.00000 * ALGEBRAIC[vfrt]) - 1.00000);
  ALGEBRAIC[PhiCaL_i] =
      (4.00000 * ALGEBRAIC[vffrt] * (ALGEBRAIC[gamma_cai] * STATES[cai] * exp(2.00000 * ALGEBRAIC[vfrt]) - CONSTANTS[gamma_cao] * CONSTANTS[cao])) /
      (exp(2.00000 * ALGEBRAIC[vfrt]) - 1.00000);
  ALGEBRAIC[ICaL_ss] =
      CONSTANTS[ICaL_fractionSS] * ((1.00000 - ALGEBRAIC[fICaLp]) * CONSTANTS[PCa] * ALGEBRAIC[PhiCaL_ss] * STATES[d] *
                                        (ALGEBRAIC[f] * (1.00000 - STATES[nca_ss]) + STATES[jca] * ALGEBRAIC[fca] * STATES[nca_ss]) +
                                    ALGEBRAIC[fICaLp] * CONSTANTS[PCap] * ALGEBRAIC[PhiCaL_ss] * STATES[d] *
                                        (ALGEBRAIC[fp] * (1.00000 - STATES[nca_ss]) + STATES[jca] * ALGEBRAIC[fcap] * STATES[nca_ss]));
  ALGEBRAIC[ICaL_i] =
      (1.00000 - CONSTANTS[ICaL_fractionSS]) * ((1.00000 - ALGEBRAIC[fICaLp]) * CONSTANTS[PCa] * ALGEBRAIC[PhiCaL_i] * STATES[d] *
                                                    (ALGEBRAIC[f] * (1.00000 - STATES[nca_i]) + STATES[jca] * ALGEBRAIC[fca] * STATES[nca_i]) +
                                                ALGEBRAIC[fICaLp] * CONSTANTS[PCap] * ALGEBRAIC[PhiCaL_i] * STATES[d] *
                                                    (ALGEBRAIC[fp] * (1.00000 - STATES[nca_i]) + STATES[jca] * ALGEBRAIC[fcap] * STATES[nca_i]));
  ALGEBRAIC[PhiCaK_i] =
      (1.00000 * ALGEBRAIC[vffrt] * (ALGEBRAIC[gamma_ki] * STATES[ki] * exp(1.00000 * ALGEBRAIC[vfrt]) - CONSTANTS[gamma_ko] * CONSTANTS[ko])) /
      (exp(1.00000 * ALGEBRAIC[vfrt]) - 1.00000);
  ALGEBRAIC[ICaK_ss] =
      CONSTANTS[ICaL_fractionSS] * ((1.00000 - ALGEBRAIC[fICaLp]) * CONSTANTS[PCaK] * ALGEBRAIC[PhiCaK_ss] * STATES[d] *
                                        (ALGEBRAIC[f] * (1.00000 - STATES[nca_ss]) + STATES[jca] * ALGEBRAIC[fca] * STATES[nca_ss]) +
                                    ALGEBRAIC[fICaLp] * CONSTANTS[PCaKp] * ALGEBRAIC[PhiCaK_ss] * STATES[d] *
                                        (ALGEBRAIC[fp] * (1.00000 - STATES[nca_ss]) + STATES[jca] * ALGEBRAIC[fcap] * STATES[nca_ss]));
  ALGEBRAIC[ICaK_i] =
      (1.00000 - CONSTANTS[ICaL_fractionSS]) * ((1.00000 - ALGEBRAIC[fICaLp]) * CONSTANTS[PCaK] * ALGEBRAIC[PhiCaK_i] * STATES[d] *
                                                    (ALGEBRAIC[f] * (1.00000 - STATES[nca_i]) + STATES[jca] * ALGEBRAIC[fca] * STATES[nca_i]) +
                                                ALGEBRAIC[fICaLp] * CONSTANTS[PCaKp] * ALGEBRAIC[PhiCaK_i] * STATES[d] *
                                                    (ALGEBRAIC[fp] * (1.00000 - STATES[nca_i]) + STATES[jca] * ALGEBRAIC[fcap] * STATES[nca_i]));
  ALGEBRAIC[PhiCaNa_i] =
      (1.00000 * ALGEBRAIC[vffrt] * (ALGEBRAIC[gamma_nai] * STATES[nai] * exp(1.00000 * ALGEBRAIC[vfrt]) - CONSTANTS[gamma_nao] * CONSTANTS[nao])) /
      (exp(1.00000 * ALGEBRAIC[vfrt]) - 1.00000);
  ALGEBRAIC[ICaNa_i] =
      (1.00000 - CONSTANTS[ICaL_fractionSS]) * ((1.00000 - ALGEBRAIC[fICaLp]) * CONSTANTS[PCaNa] * ALGEBRAIC[PhiCaNa_i] * STATES[d] *
                                                    (ALGEBRAIC[f] * (1.00000 - STATES[nca_i]) + STATES[jca] * ALGEBRAIC[fca] * STATES[nca_i]) +
                                                ALGEBRAIC[fICaLp] * CONSTANTS[PCaNap] * ALGEBRAIC[PhiCaNa_i] * STATES[d] *
                                                    (ALGEBRAIC[fp] * (1.00000 - STATES[nca_i]) + STATES[jca] * ALGEBRAIC[fcap] * STATES[nca_i]));
  ALGEBRAIC[ICaNa_ss] =
      CONSTANTS[ICaL_fractionSS] * ((1.00000 - ALGEBRAIC[fICaLp]) * CONSTANTS[PCaNa] * ALGEBRAIC[PhiCaNa_ss] * STATES[d] *
                                        (ALGEBRAIC[f] * (1.00000 - STATES[nca_ss]) + STATES[jca] * ALGEBRAIC[fca] * STATES[nca_ss]) +
                                    ALGEBRAIC[fICaLp] * CONSTANTS[PCaNap] * ALGEBRAIC[PhiCaNa_ss] * STATES[d] *
                                        (ALGEBRAIC[fp] * (1.00000 - STATES[nca_ss]) + STATES[jca] * ALGEBRAIC[fcap] * STATES[nca_ss]));

  ALGEBRAIC[ICaL] = ALGEBRAIC[ICaL_ss] + ALGEBRAIC[ICaL_i];
  ALGEBRAIC[ICaNa] = ALGEBRAIC[ICaNa_ss] + ALGEBRAIC[ICaNa_i];
  ALGEBRAIC[ICaK] = ALGEBRAIC[ICaK_ss] + ALGEBRAIC[ICaK_i];
  // Computing ICaL done..

  // printf("Computing IKr...\n");

  ALGEBRAIC[alpha] = 0.116100 * exp(0.299000 * ALGEBRAIC[vfrt]);
  ALGEBRAIC[beta] = 0.244200 * exp(-1.60400 * ALGEBRAIC[vfrt]);
  ALGEBRAIC[alpha_2] = 0.0578000 * exp(0.971000 * ALGEBRAIC[vfrt]);
  ALGEBRAIC[beta_2] = 0.000349000 * exp(-1.06200 * ALGEBRAIC[vfrt]);
  ALGEBRAIC[alpha_i] = 0.253300 * exp(0.595300 * ALGEBRAIC[vfrt]);
  ALGEBRAIC[beta_i] = 0.0652500 * exp(-0.820900 * ALGEBRAIC[vfrt]);
  ALGEBRAIC[alpha_C2ToI] = 5.20000e-05 * exp(1.52500 * ALGEBRAIC[vfrt]);
  ALGEBRAIC[beta_ItoC2] = (ALGEBRAIC[beta_2] * ALGEBRAIC[beta_i] * ALGEBRAIC[alpha_C2ToI]) / (ALGEBRAIC[alpha_2] * ALGEBRAIC[alpha_i]);

  ALGEBRAIC[IKr] = CONSTANTS[GKr] * pow((CONSTANTS[ko] / 5.00000), 1.0 / 2) * STATES[O] * (STATES[V] - ALGEBRAIC[EK]);
  // Computing IKr done..

  // printf("Computing IKs...\n");
  ALGEBRAIC[xs1ss] = 1.00000 / (1.00000 + exp(-(STATES[V] + 11.6000) / 8.93200));
  ALGEBRAIC[txs1] = 817.300 + 1.00000 / (0.000232600 * exp((STATES[V] + 48.2800) / 17.8000) + 0.00129200 * exp(-(STATES[V] + 210.000) / 230.000));
  ALGEBRAIC[xs2ss] = ALGEBRAIC[xs1ss];
  ALGEBRAIC[txs2] = 1.00000 / (0.0100000 * exp((STATES[V] - 50.0000) / 20.0000) + 0.0193000 * exp(-(STATES[V] + 66.5400) / 31.0000));
  ALGEBRAIC[KsCa] = 1.00000 + 0.600000 / (1.00000 + pow(3.80000e-05 / STATES[cai], 1.40000));
  ALGEBRAIC[IKs] = CONSTANTS[GKs] * ALGEBRAIC[KsCa] * STATES[xs1] * STATES[xs2] * (STATES[V] - ALGEBRAIC[EKs]);
  // Computing IKs done..

  // printf("Computing IK1...\n");
  ALGEBRAIC[aK1] = 4.09400 / (1.00000 + exp(0.121700 * ((STATES[V] - ALGEBRAIC[EK]) - 49.9340)));
  ALGEBRAIC[bK1] = (15.7200 * exp(0.0674000 * ((STATES[V] - ALGEBRAIC[EK]) - 3.25700)) + exp(0.0618000 * ((STATES[V] - ALGEBRAIC[EK]) - 594.310))) /
                   (1.00000 + exp(-0.162900 * ((STATES[V] - ALGEBRAIC[EK]) + 14.2070)));
  ALGEBRAIC[K1ss] = ALGEBRAIC[aK1] / (ALGEBRAIC[aK1] + ALGEBRAIC[bK1]);
  ALGEBRAIC[IK1] = CONSTANTS[GK1] * pow((CONSTANTS[ko] / 5.00000), 1.0 / 2) * ALGEBRAIC[K1ss] * (STATES[V] - ALGEBRAIC[EK]);
  // Computing IK1 done..

  // printf("Computing INaCa...\n");
  ALGEBRAIC[hca] = exp(CONSTANTS[qca] * ALGEBRAIC[vfrt]);
  ALGEBRAIC[hna] = exp(CONSTANTS[qna] * ALGEBRAIC[vfrt]);
  ALGEBRAIC[h1_i] = 1.00000 + (STATES[nai] / CONSTANTS[kna3]) * (1.00000 + ALGEBRAIC[hna]);
  ALGEBRAIC[h2_i] = (STATES[nai] * ALGEBRAIC[hna]) / (CONSTANTS[kna3] * ALGEBRAIC[h1_i]);
  ALGEBRAIC[h3_i] = 1.00000 / ALGEBRAIC[h1_i];
  ALGEBRAIC[h4_i] = 1.00000 + (STATES[nai] / CONSTANTS[kna1]) * (1.00000 + STATES[nai] / CONSTANTS[kna2]);
  ALGEBRAIC[h5_i] = (STATES[nai] * STATES[nai]) / (ALGEBRAIC[h4_i] * CONSTANTS[kna1] * CONSTANTS[kna2]);
  ALGEBRAIC[h6_i] = 1.00000 / ALGEBRAIC[h4_i];
  ALGEBRAIC[h7_i] = 1.00000 + (CONSTANTS[nao] / CONSTANTS[kna3]) * (1.00000 + 1.00000 / ALGEBRAIC[hna]);
  ALGEBRAIC[h8_i] = CONSTANTS[nao] / (CONSTANTS[kna3] * ALGEBRAIC[hna] * ALGEBRAIC[h7_i]);
  ALGEBRAIC[h9_i] = 1.00000 / ALGEBRAIC[h7_i];
  ALGEBRAIC[k3p_i] = ALGEBRAIC[h9_i] * CONSTANTS[wca];
  ALGEBRAIC[k3pp_i] = ALGEBRAIC[h8_i] * CONSTANTS[wnaca];
  ALGEBRAIC[k3_i] = ALGEBRAIC[k3p_i] + ALGEBRAIC[k3pp_i];
  ALGEBRAIC[k4p_i] = (ALGEBRAIC[h3_i] * CONSTANTS[wca]) / ALGEBRAIC[hca];
  ALGEBRAIC[k4pp_i] = ALGEBRAIC[h2_i] * CONSTANTS[wnaca];
  ALGEBRAIC[k4_i] = ALGEBRAIC[k4p_i] + ALGEBRAIC[k4pp_i];
  ALGEBRAIC[k6_i] = ALGEBRAIC[h6_i] * STATES[cai] * CONSTANTS[kcaon];
  ALGEBRAIC[k7_i] = ALGEBRAIC[h5_i] * ALGEBRAIC[h2_i] * CONSTANTS[wna];
  ALGEBRAIC[k8_i] = ALGEBRAIC[h8_i] * CONSTANTS[h11_i] * CONSTANTS[wna];
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
  ALGEBRAIC[allo_i] = 1.00000 / (1.00000 + pow(CONSTANTS[KmCaAct] / STATES[cai], 2.00000));
  ALGEBRAIC[JncxNa_i] = (3.00000 * (ALGEBRAIC[E4_i] * ALGEBRAIC[k7_i] - ALGEBRAIC[E1_i] * ALGEBRAIC[k8_i]) + ALGEBRAIC[E3_i] * ALGEBRAIC[k4pp_i]) -
                        ALGEBRAIC[E2_i] * ALGEBRAIC[k3pp_i];
  ALGEBRAIC[JncxCa_i] = ALGEBRAIC[E2_i] * CONSTANTS[k2_i] - ALGEBRAIC[E1_i] * CONSTANTS[k1_i];
  ALGEBRAIC[INaCa_i] = (1.00000 - CONSTANTS[INaCa_fractionSS]) * CONSTANTS[Gncx] * ALGEBRAIC[allo_i] *
                       (CONSTANTS[zna] * ALGEBRAIC[JncxNa_i] + CONSTANTS[zca] * ALGEBRAIC[JncxCa_i]);
  ALGEBRAIC[h1_ss] = 1.00000 + (STATES[nass] / CONSTANTS[kna3]) * (1.00000 + ALGEBRAIC[hna]);
  ALGEBRAIC[h2_ss] = (STATES[nass] * ALGEBRAIC[hna]) / (CONSTANTS[kna3] * ALGEBRAIC[h1_ss]);

  ALGEBRAIC[h3_ss] = 1.00000 / ALGEBRAIC[h1_ss];

  ALGEBRAIC[h4_ss] = 1.00000 + (STATES[nass] / CONSTANTS[kna1]) * (1.00000 + STATES[nass] / CONSTANTS[kna2]);
  ALGEBRAIC[h5_ss] = (STATES[nass] * STATES[nass]) / (ALGEBRAIC[h4_ss] * CONSTANTS[kna1] * CONSTANTS[kna2]);

  ALGEBRAIC[h6_ss] = 1.00000 / ALGEBRAIC[h4_ss];
  ALGEBRAIC[h7_ss] = 1.00000 + (CONSTANTS[nao] / CONSTANTS[kna3]) * (1.00000 + 1.00000 / ALGEBRAIC[hna]);
  ALGEBRAIC[h8_ss] = CONSTANTS[nao] / (CONSTANTS[kna3] * ALGEBRAIC[hna] * ALGEBRAIC[h7_ss]);
  ALGEBRAIC[h9_ss] = 1.00000 / ALGEBRAIC[h7_ss];
  ALGEBRAIC[k3p_ss] = ALGEBRAIC[h9_ss] * CONSTANTS[wca];
  ALGEBRAIC[k3pp_ss] = ALGEBRAIC[h8_ss] * CONSTANTS[wnaca];
  ALGEBRAIC[k3_ss] = ALGEBRAIC[k3p_ss] + ALGEBRAIC[k3pp_ss];
  ALGEBRAIC[k4p_ss] = (ALGEBRAIC[h3_ss] * CONSTANTS[wca]) / ALGEBRAIC[hca];
  ALGEBRAIC[k4pp_ss] = ALGEBRAIC[h2_ss] * CONSTANTS[wnaca];
  ALGEBRAIC[k4_ss] = ALGEBRAIC[k4p_ss] + ALGEBRAIC[k4pp_ss];
  ALGEBRAIC[k6_ss] = ALGEBRAIC[h6_ss] * STATES[cass] * CONSTANTS[kcaon];
  ALGEBRAIC[k7_ss] = ALGEBRAIC[h5_ss] * ALGEBRAIC[h2_ss] * CONSTANTS[wna];
  ALGEBRAIC[k8_ss] = ALGEBRAIC[h8_ss] * CONSTANTS[h11_ss] * CONSTANTS[wna];
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
  ALGEBRAIC[allo_ss] = 1.00000 / (1.00000 + pow(CONSTANTS[KmCaAct] / STATES[cass], 2.00000));
  ALGEBRAIC[JncxNa_ss] =
      (3.00000 * (ALGEBRAIC[E4_ss] * ALGEBRAIC[k7_ss] - ALGEBRAIC[E1_ss] * ALGEBRAIC[k8_ss]) + ALGEBRAIC[E3_ss] * ALGEBRAIC[k4pp_ss]) -
      ALGEBRAIC[E2_ss] * ALGEBRAIC[k3pp_ss];
  ALGEBRAIC[JncxCa_ss] = ALGEBRAIC[E2_ss] * CONSTANTS[k2_ss] - ALGEBRAIC[E1_ss] * CONSTANTS[k1_ss];
  ALGEBRAIC[INaCa_ss] = CONSTANTS[INaCa_fractionSS] * CONSTANTS[Gncx] * ALGEBRAIC[allo_ss] *
                        (CONSTANTS[zna] * ALGEBRAIC[JncxNa_ss] + CONSTANTS[zca] * ALGEBRAIC[JncxCa_ss]);
  // Computing INaCa done..

  // printf("Computing INaK...\n");
  ALGEBRAIC[Knai] = CONSTANTS[Knai0] * exp((CONSTANTS[delta] * ALGEBRAIC[vfrt]) / 3.00000);
  ALGEBRAIC[Knao] = CONSTANTS[Knao0] * exp(((1.00000 - CONSTANTS[delta]) * ALGEBRAIC[vfrt]) / 3.00000);
  ALGEBRAIC[P] = CONSTANTS[eP] / (1.00000 + CONSTANTS[H] / CONSTANTS[Khp] + STATES[nai] / CONSTANTS[Knap] + STATES[ki] / CONSTANTS[Kxkur]);
  ALGEBRAIC[a1] = (CONSTANTS[k1p] * pow(STATES[nai] / ALGEBRAIC[Knai], 3.00000)) /
                  ((pow(1.00000 + STATES[nai] / ALGEBRAIC[Knai], 3.00000) + pow(1.00000 + STATES[ki] / CONSTANTS[Kki], 2.00000)) - 1.00000);
  ALGEBRAIC[b2] = (CONSTANTS[k2m] * pow(CONSTANTS[nao] / ALGEBRAIC[Knao], 3.00000)) /
                  ((pow(1.00000 + CONSTANTS[nao] / ALGEBRAIC[Knao], 3.00000) + pow(1.00000 + CONSTANTS[ko] / CONSTANTS[Kko], 2.00000)) - 1.00000);
  ALGEBRAIC[a3] = (CONSTANTS[k3p] * pow(CONSTANTS[ko] / CONSTANTS[Kko], 2.00000)) /
                  ((pow(1.00000 + CONSTANTS[nao] / ALGEBRAIC[Knao], 3.00000) + pow(1.00000 + CONSTANTS[ko] / CONSTANTS[Kko], 2.00000)) - 1.00000);

  ALGEBRAIC[b3] = (CONSTANTS[k3m] * ALGEBRAIC[P] * CONSTANTS[H]) / (1.00000 + CONSTANTS[MgATP] / CONSTANTS[Kmgatp]);
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
  ALGEBRAIC[E3] = ALGEBRAIC[x3] / (ALGEBRAIC[x1] + ALGEBRAIC[x2] + ALGEBRAIC[x3] + ALGEBRAIC[x4]);
  ALGEBRAIC[E4] = ALGEBRAIC[x4] / (ALGEBRAIC[x1] + ALGEBRAIC[x2] + ALGEBRAIC[x3] + ALGEBRAIC[x4]);
  ALGEBRAIC[JnakNa] = 3.00000 * (ALGEBRAIC[E1] * ALGEBRAIC[a3] - ALGEBRAIC[E2] * ALGEBRAIC[b3]);
  ALGEBRAIC[JnakK] = 2.00000 * (ALGEBRAIC[E4] * CONSTANTS[b1] - ALGEBRAIC[E3] * ALGEBRAIC[a1]);
  ALGEBRAIC[INaK] = CONSTANTS[Pnak] * (CONSTANTS[zna] * ALGEBRAIC[JnakNa] + CONSTANTS[zk] * ALGEBRAIC[JnakK]);
  ALGEBRAIC[xkb] = 1.00000 / (1.00000 + exp(-(STATES[V] - 10.8968) / 23.9871));
  ALGEBRAIC[IKb] = CONSTANTS[GKb] * ALGEBRAIC[xkb] * (STATES[V] - ALGEBRAIC[EK]);
  ALGEBRAIC[INab] = (CONSTANTS[PNab] * ALGEBRAIC[vffrt] * (STATES[nai] * exp(ALGEBRAIC[vfrt]) - CONSTANTS[nao])) / (exp(ALGEBRAIC[vfrt]) - 1.00000);
  ALGEBRAIC[ICab] = (CONSTANTS[PCab] * 4.00000 * ALGEBRAIC[vffrt] *
                     (ALGEBRAIC[gamma_cai] * STATES[cai] * exp(2.00000 * ALGEBRAIC[vfrt]) - CONSTANTS[gamma_cao] * CONSTANTS[cao])) /
                    (exp(2.00000 * ALGEBRAIC[vfrt]) - 1.00000);
  ALGEBRAIC[IpCa] = (CONSTANTS[GpCa] * STATES[cai]) / (CONSTANTS[KmCap] + STATES[cai]);
  ALGEBRAIC[IClCa_junc] = ((CONSTANTS[Fjunc] * CONSTANTS[GClCa]) / (1.00000 + CONSTANTS[KdClCa] / STATES[cass])) * (STATES[V] - CONSTANTS[ECl]);
  ALGEBRAIC[IClCa_sl] =
      (((1.00000 - CONSTANTS[Fjunc]) * CONSTANTS[GClCa]) / (1.00000 + CONSTANTS[KdClCa] / STATES[cai])) * (STATES[V] - CONSTANTS[ECl]);
  ALGEBRAIC[IClCa] = ALGEBRAIC[IClCa_junc] + ALGEBRAIC[IClCa_sl];
  ALGEBRAIC[IClb] = CONSTANTS[GClb] * (STATES[V] - CONSTANTS[ECl]);
  // Computing INaK done..

  // printf("Computing Jrel...\n");
  ALGEBRAIC[Jrel_inf_b] = ((-CONSTANTS[a_rel] * ALGEBRAIC[ICaL_ss]) / 1.00000) / (1.00000 + pow(CONSTANTS[cajsr_half] / STATES[cajsr], 8.00000));
  ALGEBRAIC[Jrel_inf] = (CONSTANTS[celltype] == 2.00000 ? ALGEBRAIC[Jrel_inf_b] * 1.70000 : ALGEBRAIC[Jrel_inf_b]);
  ALGEBRAIC[tau_rel_b] = CONSTANTS[bt] / (1.00000 + 0.0123000 / STATES[cajsr]);
  ALGEBRAIC[tau_rel] = (ALGEBRAIC[tau_rel_b] < 0.00100000 ? 0.00100000 : ALGEBRAIC[tau_rel_b]);
  ALGEBRAIC[Jrel_infp_b] = ((-CONSTANTS[a_relp] * ALGEBRAIC[ICaL_ss]) / 1.00000) / (1.00000 + pow(CONSTANTS[cajsr_half] / STATES[cajsr], 8.00000));
  ALGEBRAIC[Jrel_infp] = (CONSTANTS[celltype] == 2.00000 ? ALGEBRAIC[Jrel_infp_b] * 1.70000 : ALGEBRAIC[Jrel_infp_b]);
  ALGEBRAIC[tau_relp_b] = CONSTANTS[btp] / (1.00000 + 0.0123000 / STATES[cajsr]);
  ALGEBRAIC[tau_relp] = (ALGEBRAIC[tau_relp_b] < 0.00100000 ? 0.00100000 : ALGEBRAIC[tau_relp_b]);
  ALGEBRAIC[Jrel] = CONSTANTS[Jrel_b] * ((1.00000 - ALGEBRAIC[fJrelp]) * STATES[Jrel_np] + ALGEBRAIC[fJrelp] * STATES[Jrel_p]);
  ALGEBRAIC[Jleak] = CONSTANTS[Jleak_b] * (0.00488250 * STATES[cansr]) / 15.0000;
  ALGEBRAIC[Jupnp] = (CONSTANTS[upScale] * 0.00542500 * STATES[cai]) / (STATES[cai] + 0.000920000);
  ALGEBRAIC[Jupp] = (CONSTANTS[upScale] * 2.75000 * 0.00542500 * STATES[cai]) / ((STATES[cai] + 0.000920000) - 0.000170000);
  ALGEBRAIC[Jup] = CONSTANTS[Jup_b] * (((1.00000 - ALGEBRAIC[fJupp]) * ALGEBRAIC[Jupnp] + ALGEBRAIC[fJupp] * ALGEBRAIC[Jupp]) - ALGEBRAIC[Jleak]);
  ALGEBRAIC[Jtr] = CONSTANTS[Jtr_b] * (STATES[cansr] - STATES[cajsr]) / 60.0000;
  ALGEBRAIC[JdiffNa] = (STATES[nass] - STATES[nai]) / CONSTANTS[tauNa];
  ALGEBRAIC[JdiffK] = (STATES[kss] - STATES[ki]) / CONSTANTS[tauK];
  ALGEBRAIC[Jdiff] = (STATES[cass] - STATES[cai]) / CONSTANTS[tauCa];
  // Computing Jrel done..

  ALGEBRAIC[Bcai] = 1.00000 / (1.00000 + (CONSTANTS[cmdnmax] * CONSTANTS[kmcmdn]) / pow(CONSTANTS[kmcmdn] + STATES[cai], 2.00000));
  ALGEBRAIC[Bcass] = 1.00000 / (1.00000 + (CONSTANTS[BSRmax] * CONSTANTS[KmBSR]) / pow(CONSTANTS[KmBSR] + STATES[cass], 2.00000) +
                                (CONSTANTS[BSLmax] * CONSTANTS[KmBSL]) / pow(CONSTANTS[KmBSL] + STATES[cass], 2.00000));
  ALGEBRAIC[Bcajsr] = 1.00000 / (1.00000 + (CONSTANTS[csqnmax] * CONSTANTS[kmcsqn]) / pow(CONSTANTS[kmcsqn] + STATES[cajsr], 2.00000));
  ALGEBRAIC[I_katp] = CONSTANTS[fkatp] * CONSTANTS[gkatp] * CONSTANTS[akik] * CONSTANTS[bkik] * (STATES[V] - ALGEBRAIC[EK]);

  // ComputeRates
  // printf("Computing Rates...\n");
  RATES[hL] = (ALGEBRAIC[hLss] - STATES[hL]) / CONSTANTS[thL];
  RATES[hLp] = (ALGEBRAIC[hLssp] - STATES[hLp]) / CONSTANTS[thLp];
  RATES[jca] = (ALGEBRAIC[jcass] - STATES[jca]) / CONSTANTS[tjca];
  RATES[m] = (ALGEBRAIC[mss] - STATES[m]) / ALGEBRAIC[tm];
  RATES[mL] = (ALGEBRAIC[mLss] - STATES[mL]) / ALGEBRAIC[tmL];
  RATES[a] = (ALGEBRAIC[ass] - STATES[a]) / ALGEBRAIC[ta];
  RATES[d] = (ALGEBRAIC[dss] - STATES[d]) / ALGEBRAIC[td];
  RATES[ff] = (ALGEBRAIC[fss] - STATES[ff]) / ALGEBRAIC[tff];
  RATES[fs] = (ALGEBRAIC[fss] - STATES[fs]) / ALGEBRAIC[tfs];
  RATES[nca_ss] = ALGEBRAIC[anca_ss] * CONSTANTS[k2n] - STATES[nca_ss] * ALGEBRAIC[km2n];
  RATES[nca_i] = ALGEBRAIC[anca_i] * CONSTANTS[k2n] - STATES[nca_i] * ALGEBRAIC[km2n];
  RATES[xs1] = (ALGEBRAIC[xs1ss] - STATES[xs1]) / ALGEBRAIC[txs1];
  RATES[ap] = (ALGEBRAIC[assp] - STATES[ap]) / ALGEBRAIC[ta];
  RATES[fcaf] = (ALGEBRAIC[fcass] - STATES[fcaf]) / ALGEBRAIC[tfcaf];
  RATES[fcas] = (ALGEBRAIC[fcass] - STATES[fcas]) / ALGEBRAIC[tfcas];
  RATES[ffp] = (ALGEBRAIC[fss] - STATES[ffp]) / ALGEBRAIC[tffp];
  RATES[xs2] = (ALGEBRAIC[xs2ss] - STATES[xs2]) / ALGEBRAIC[txs2];
  RATES[CaMKt] = CONSTANTS[aCaMK] * ALGEBRAIC[CaMKb] * (ALGEBRAIC[CaMKb] + STATES[CaMKt]) - CONSTANTS[bCaMK] * STATES[CaMKt];
  RATES[h] = (ALGEBRAIC[hss] - STATES[h]) / ALGEBRAIC[th];
  RATES[fcafp] = (ALGEBRAIC[fcass] - STATES[fcafp]) / ALGEBRAIC[tfcafp];
  RATES[j] = (ALGEBRAIC[jss] - STATES[j]) / ALGEBRAIC[tj];
  RATES[hp] = (ALGEBRAIC[hssp] - STATES[hp]) / ALGEBRAIC[th];
  RATES[iF] = (ALGEBRAIC[iss] - STATES[iF]) / ALGEBRAIC[tiF];
  RATES[C3] = ALGEBRAIC[beta] * STATES[C2] - ALGEBRAIC[alpha] * STATES[C3];
  RATES[C2] = (ALGEBRAIC[alpha] * STATES[C3] + CONSTANTS[beta_1] * STATES[C1]) - (ALGEBRAIC[beta] + CONSTANTS[alpha_1]) * STATES[C2];
  RATES[jp] = (ALGEBRAIC[jss] - STATES[jp]) / ALGEBRAIC[tjp];
  RATES[iS] = (ALGEBRAIC[iss] - STATES[iS]) / ALGEBRAIC[tiS];
  RATES[O] = (ALGEBRAIC[alpha_2] * STATES[C1] + ALGEBRAIC[beta_i] * STATES[I]) - (ALGEBRAIC[beta_2] + ALGEBRAIC[alpha_i]) * STATES[O];
  RATES[iFp] = (ALGEBRAIC[iss] - STATES[iFp]) / ALGEBRAIC[tiFp];
  RATES[iSp] = (ALGEBRAIC[iss] - STATES[iSp]) / ALGEBRAIC[tiSp];
  RATES[C1] = (CONSTANTS[alpha_1] * STATES[C2] + ALGEBRAIC[beta_2] * STATES[O] + ALGEBRAIC[beta_ItoC2] * STATES[I]) -
              (CONSTANTS[beta_1] + ALGEBRAIC[alpha_2] + ALGEBRAIC[alpha_C2ToI]) * STATES[C1];
  RATES[I] = (ALGEBRAIC[alpha_C2ToI] * STATES[C1] + ALGEBRAIC[alpha_i] * STATES[O]) - (ALGEBRAIC[beta_ItoC2] + ALGEBRAIC[beta_i]) * STATES[I];
  RATES[Jrel_np] = (ALGEBRAIC[Jrel_inf] - STATES[Jrel_np]) / ALGEBRAIC[tau_rel];
  RATES[Jrel_p] = (ALGEBRAIC[Jrel_infp] - STATES[Jrel_p]) / ALGEBRAIC[tau_relp];
  RATES[ki] = (-(((ALGEBRAIC[Ito] + ALGEBRAIC[IKr] + ALGEBRAIC[IKs] + ALGEBRAIC[IK1] + ALGEBRAIC[IKb] + ALGEBRAIC[I_katp] + ALGEBRAIC[Istim]) -
                  2.00000 * ALGEBRAIC[INaK]) +
                 ALGEBRAIC[ICaK_i]) *
               CONSTANTS[Acap]) /
                  (CONSTANTS[F] * CONSTANTS[vmyo]) +
              (ALGEBRAIC[JdiffK] * CONSTANTS[vss]) / CONSTANTS[vmyo];
  RATES[kss] = (-ALGEBRAIC[ICaK_ss] * CONSTANTS[Acap]) / (CONSTANTS[F] * CONSTANTS[vss]) - ALGEBRAIC[JdiffK];
  RATES[nai] =
      (-(ALGEBRAIC[INa] + ALGEBRAIC[INaL] + 3.00000 * ALGEBRAIC[INaCa_i] + ALGEBRAIC[ICaNa_i] + 3.00000 * ALGEBRAIC[INaK] + ALGEBRAIC[INab]) *
       CONSTANTS[Acap]) /
          (CONSTANTS[F] * CONSTANTS[vmyo]) +
      (ALGEBRAIC[JdiffNa] * CONSTANTS[vss]) / CONSTANTS[vmyo];
  RATES[nass] = (-(ALGEBRAIC[ICaNa_ss] + 3.00000 * ALGEBRAIC[INaCa_ss]) * CONSTANTS[Acap]) / (CONSTANTS[F] * CONSTANTS[vss]) - ALGEBRAIC[JdiffNa];
  RATES[cass] =
      ALGEBRAIC[Bcass] * (((-(ALGEBRAIC[ICaL_ss] - 2.00000 * ALGEBRAIC[INaCa_ss]) * CONSTANTS[Acap]) / (2.00000 * CONSTANTS[F] * CONSTANTS[vss]) +
                           (ALGEBRAIC[Jrel] * CONSTANTS[vjsr]) / CONSTANTS[vss]) -
                          ALGEBRAIC[Jdiff]);
  RATES[V] = -(ALGEBRAIC[INa] + ALGEBRAIC[INaL] + ALGEBRAIC[Ito] + ALGEBRAIC[ICaL] + ALGEBRAIC[ICaNa] + ALGEBRAIC[ICaK] + ALGEBRAIC[IKr] +
               ALGEBRAIC[IKs] + ALGEBRAIC[IK1] + ALGEBRAIC[INaCa_i] + ALGEBRAIC[INaCa_ss] + ALGEBRAIC[INaK] + ALGEBRAIC[INab] + ALGEBRAIC[IKb] +
               ALGEBRAIC[IpCa] + ALGEBRAIC[ICab] + ALGEBRAIC[IClCa] + ALGEBRAIC[IClb] + ALGEBRAIC[I_katp] + ALGEBRAIC[Istim]);
  // new for coupling
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
  RATES[cai] = ALGEBRAIC[Bcai] * (-(ALGEBRAIC[ICaL_i] + ALGEBRAIC[IpCa] + ALGEBRAIC[ICab] - 2.00000 * ALGEBRAIC[INaCa_i]) * CONSTANTS[Acap] /
                                      (2.00000 * CONSTANTS[F] * CONSTANTS[vmyo]) -
                                  ALGEBRAIC[Jup] * CONSTANTS[vnsr] / CONSTANTS[vmyo] + ALGEBRAIC[Jdiff] * CONSTANTS[vss] / CONSTANTS[vmyo] -
                                  RATES[Ca_TRPN] * CONSTANTS[trpnmax]);  // Adding TRPN term
  RATES[cansr] = ALGEBRAIC[Jup] - (ALGEBRAIC[Jtr] * CONSTANTS[vjsr]) / CONSTANTS[vnsr];
  RATES[cajsr] = ALGEBRAIC[Bcajsr] * (ALGEBRAIC[Jtr] - ALGEBRAIC[Jrel]);
}
