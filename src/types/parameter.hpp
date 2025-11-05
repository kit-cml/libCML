#ifndef PARAMETER_HPP
#define PARAMETER_HPP

struct Parameter
{
  double cycle_length; // period for one cycle
  short number_pacing; // pace number of the simulation
  short number_pacing_write; // pace number for writing result
  char solver_type[50]; // for now, only Euler or CVode are available
  char cell_model[50]; // cell model type and the type of the cell (if exist)
  short prior_risk; // 0: low, 1: intermediate, 2: high
  double time_step_min;    // acting as the default time step
  double time_step_max;    // used only for CVode solver
  double writing_step;
  double stimulus_duration;
  double stimulus_amplitude_scale;
  bool is_postprocessing;
  bool is_cvar;
  
  // begin conductance scaling vars
  double gks_scale;
  double gkr_scale;
  double gk1_scale;
  double gto_scale;
  double pca_scale;
  double gna_scale;
  double gnal_scale;
  double pnab_scale;
  double pcab_scale;
  double gncx_scale;
  double gk_scale;
  double gcl_scale;
  double gcat_scale;
  double gh_scale;
  double gk2_scale;
  double gka_scale;
  double gkca_scale;
  double gb_scale;
  double gns_scale;
  double tau_h_scale;
  // end conductance scaling vars
  char mutation_type[20];
  char hill_file[100];
  char herg_file[100];
  char cvar_file[100]; // CVAR
  char drug_name[100];
  char drug_concentrations[50];
  char user_name[20];
  char initial_values_zip_file[100];
  // restitution protocol
  double cl_decrement;
  double cl_end;
  double rest_pace_max;
#ifdef TISSUE
  // from this point on,
  // these parameters are belonging to
  // the 2D/3D simulations.
  bool is_crt;
  bool is_ecg;
  bool is_bspm;
  bool is_lbbb;
  bool is_rbbb;
  bool is_s1s2;
  bool is_using_output;
  char fiber_mesh_dir[255];
  char fiber_mesh_file[255];
  char heart_mesh_file[255];
  char torso_mesh_file[255];
  char mesh_type[50];
  char s1_nodes_file[255];
  char s2_nodes_file[255];
  char surface_mesh_file[255];
  char output_mesh_type[50];
  double diffusion_scale;
  double diffusion_scale_fiber;
  double apd_fiber;
  double erp_fiber;
  double twrite_vtk;
  double tmax; // maximum simulation time for 2D/3D
  int dimension;
  int ecgnode[9];
#endif  

  void init();
  void show_val();
};

#endif
