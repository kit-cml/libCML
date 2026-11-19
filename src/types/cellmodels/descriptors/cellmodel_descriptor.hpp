#ifndef CELLMODEL_DESCRIPTOR_HPP
#define CELLMODEL_DESCRIPTOR_HPP

// Description of a cell model's ionic channels, gates and concentrations,
// as indices into the model's STATES / ALGEBRAIC / CONSTANTS arrays.
//
// Data only: no simulation logic. One table per cell model, written in its own
// file next to the (generated) model files, e.g.
//   cellmodels/tentusscher_noble_noble_panfilov_2004_endo_descriptor.cpp
// so that regenerating a model from CellML never overwrites it.
//
// Used by drivers such as EPSim's vc_bench (voltage clamp): which currents and
// gates a channel has, where x_inf and tau are stored (for Rush-Larsen and the
// steady-state table), which concentrations to freeze, which conductance to
// switch off, and which voltages must be avoided.

// Marks an index that the model does not have (e.g. a gate without x_inf/tau).
const short CML_NO_INDEX = -1;

// One gate (a state variable 0..1 that opens/closes the channel).
struct GateDescriptor
{
  const char *name;         // short name used in headers, e.g. "m"
  const char *description;  // e.g. "INa activation"
  short state;              // index in STATES
  short inf;                // index in ALGEBRAIC of the steady state x_inf, or CML_NO_INDEX
  short tau;                // index in ALGEBRAIC of the time constant tau, or CML_NO_INDEX
  bool voltage_dependent;   // true: x_inf/tau depend on V only (Rush-Larsen exact under clamp,
                            //       included in the steady-state table)
                            // false: depends on something else, e.g. Ca_i (fCa, g)
};

// One ionic channel = one current + its gates.
struct ChannelDescriptor
{
  const char *name;         // channel name used for selection, e.g. "INa"
  const char *current_name; // e.g. "i_Na"
  short current;            // index in ALGEBRAIC of the current (pA/pF)
  short conductance;        // index in CONSTANTS of the maximal conductance/permeability,
                            // or CML_NO_INDEX (used to switch the channel off)
  const GateDescriptor *gates;    // array of n_gates gates (may be NULL when n_gates == 0)
  short n_gates;
};

// One concentration state (e.g. Na_i), frozen in voltage clamp if requested.
struct ConcentrationDescriptor
{
  const char *name;         // e.g. "Na_i"
  short state;              // index in STATES
};

// The whole description of one cell model.
struct CellmodelDescriptor
{
  const char *model_name;   // e.g. "tn2004_endo"
  short v;                  // index in STATES of the membrane potential
  short stim_amplitude;     // index in CONSTANTS of the stimulus amplitude, or CML_NO_INDEX

  const ChannelDescriptor *channels;
  short n_channels;

  const ConcentrationDescriptor *concentrations;
  short n_concentrations;

  // Voltages (mV) at which a current formula is singular (e.g. 0/0 of a GHK term
  // at exactly 0 mV); a driver should shift such a command voltage slightly.
  const double *singular_voltages;
  short n_singular_voltages;
};

#endif
