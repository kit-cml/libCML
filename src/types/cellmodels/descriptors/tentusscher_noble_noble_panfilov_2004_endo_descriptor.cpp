// Model description of tentusscher_noble_noble_panfilov_2004_endo (see cellmodel_descriptor.hpp).
// Hand-written; kept separate from the generated model files.

#include "tentusscher_noble_noble_panfilov_2004_endo_descriptor.hpp"
#include "../tentusscher_noble_noble_panfilov_2004_endo.hpp"   // the model's enum names

#include <cstddef>

namespace {

// name, description, state, x_inf, tau, voltage_dependent
const GateDescriptor ina_gates[] = {
  {"m",   "INa activation",              m,   m_inf,   tau_m,   true},
  {"h",   "INa inactivation",            h,   h_inf,   tau_h,   true},
  {"j",   "INa inactivation (slow)",     j,   j_inf,   tau_j,   true},
};
const GateDescriptor ical_gates[] = {
  {"d",   "ICaL activation",             d,   d_inf,   tau_d,   true},
  {"f",   "ICaL inactivation",           f,   f_inf,   tau_f,   true},
  {"fCa", "ICaL Ca-inactivation",        fCa, fCa_inf, CML_NO_INDEX, false},  // tau_fCa is a CONSTANT; depends on Ca_i
};
const GateDescriptor ito_gates[] = {
  {"r",   "Ito activation",              r,   r_inf,   tau_r,   true},
  {"s",   "Ito inactivation",            s,   s_inf,   tau_s,   true},
};
const GateDescriptor ikr_gates[] = {
  {"Xr1", "IKr activation",              Xr1, xr1_inf, tau_xr1, true},
  {"Xr2", "IKr inactivation",            Xr2, xr2_inf, tau_xr2, true},
};
const GateDescriptor iks_gates[] = {
  {"Xs",  "IKs activation",              Xs,  xs_inf,  tau_xs,  true},
};

// name, current name, current, conductance, gates, n_gates
const ChannelDescriptor channels[] = {
  {"INa",  "i_Na",  i_Na,  g_Na,  ina_gates,  3},
  {"ICaL", "i_CaL", i_CaL, g_CaL, ical_gates, 3},
  {"Ito",  "i_to",  i_to,  g_to,  ito_gates,  2},
  {"IKr",  "i_Kr",  i_Kr,  g_Kr,  ikr_gates,  2},
  {"IKs",  "i_Ks",  i_Ks,  g_Ks,  iks_gates,  1},
  {"IK1",  "i_K1",  i_K1,  g_K1,  NULL,       0},   // instantaneous rectification, no gate state
};

const ConcentrationDescriptor concentrations[] = {
  {"Na_i", Na_i}, {"K_i", K_i}, {"Ca_i", Ca_i}, {"Ca_SR", Ca_SR},
};

const double singular_voltages[] = { 0.0 };          // i_CaL (GHK) is 0/0 at V = 0 mV

const CellmodelDescriptor descriptor = {
  "tn2004_endo", V, stim_amplitude,
  channels,          sizeof(channels) / sizeof(channels[0]),
  concentrations,    sizeof(concentrations) / sizeof(concentrations[0]),
  singular_voltages, sizeof(singular_voltages) / sizeof(singular_voltages[0]),
};

} // namespace

const CellmodelDescriptor& tentusscher_noble_noble_panfilov_2004_endo_descriptor()
{
  return descriptor;
}
