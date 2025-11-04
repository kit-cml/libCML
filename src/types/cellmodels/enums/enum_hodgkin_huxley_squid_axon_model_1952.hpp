#ifndef EN_HODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_HPP
#define EN_HODGKIN_HUXLEY_SQUID_AXON_MODEL_1952_HPP

enum E_ALGEBRAIC_T{
  i_Stim = 0,
  alpha_m = 1,
  alpha_h = 2,
  alpha_n = 3,
  i_Na = 4,
  beta_m = 5,
  beta_h = 6,
  beta_n = 7,
  i_K = 8,
  i_L = 9,
};


enum E_CONSTANTS_T{
  E_R = 0,
  Cm = 1,
  g_Na = 2,
  g_K = 3,
  g_L = 4,
  E_Na = 5,
  E_K = 6,
  E_L = 7,
};


enum E_STATES_T{
  V = 0,
  m = 1,
  h = 2,
  n = 3,
};


#endif