#include "parameter.hpp"

#include <cstdio>
#include "cml_consts.hpp"
#include "../functions/inputoutput.hpp"

void Parameter::init()
{
  cycle_length = 2000.;
  number_pacing = 1000;
  number_pacing_write = 0;
  time_step_min = 0.005;
  time_step_max = 1.;
  writing_step = 2.0;
  stimulus_duration = 0.5;
  stimulus_amplitude_scale = 1.0;
  prior_risk = 2;
  gks_scale = 1.;
  gkr_scale = 1.;
  gk1_scale = 1.;
  gto_scale = 1.;
  pca_scale = 1.;
  gna_scale = 1.;
  gnal_scale = 1.;
  gnab_scale = 1.;
  gcab_scale = 1.;
  gncx_scale = 1.;
  tau_h_scale = 1.;
  is_postprocessing = 0;
  is_cvar = 0;
  // restitution protocol
  cl_decrement = 10;
  cl_end = 100;
  rest_pace_max = 20;
  snprintf(cell_model, sizeof(cell_model), "%s", "CiPAORdv1.0_endo");
  snprintf(solver_type, sizeof(solver_type), "%s", "CVode");
  snprintf(mutation_type, sizeof(mutation_type), "%s", "CTL");
  snprintf(user_name, sizeof(user_name), "%s", "johndoe");
  snprintf(hill_file, sizeof(hill_file), "%s", "./chantest_hill/bepridil/IC50_samples10.csv");
  snprintf(herg_file, sizeof(herg_file), "%s", "./chantest_herg/bepridil/boot_pars10.csv");
// CVAR
  snprintf(cvar_file, sizeof(cvar_file), "%s", "./population/control.csv");
  snprintf(drug_name, sizeof(drug_name), "%s", "bepridil");
  snprintf(initial_values_zip_file, sizeof(initial_values_zip_file), "bepridil_CiPAORdv1.0_endo_initial_values.zip");
  snprintf(drug_concentrations, sizeof(drug_concentrations), "%s", "99.0");

#ifdef TISSUE
  is_crt = false;
  is_ecg = false;
  is_bspm = false;
  is_lbbb = false;
  is_rbbb = false;
  is_s1s2 = false;
  is_using_output = false;
  diffusion_scale = 1.5;
  diffusion_scale_fiber = 0.4;
  apd_fiber = 300.;
  erp_fiber = 350.;
  twrite_vtk = 0.0;
  tmax = 2000.0;
  dimension = 3;
  ecgnode[0]   = 472; // ECG nodes
  ecgnode[1]   = 393;
  ecgnode[2]   = 239;
  ecgnode[3]   = 28;
  ecgnode[4]   = 29;
  ecgnode[5]   = 30;
  ecgnode[6]   = 480;
  ecgnode[7]   = 254;
  ecgnode[8]   = 252;
  snprintf(mesh_type, sizeof(mesh_type), "%s", "tet");
  snprintf(output_mesh_type, sizeof(output_mesh_type), "%s", "surface");
  snprintf(fiber_mesh_dir, sizeof(fiber_mesh_dir), "%s", "./mesh/human_hf_214319/purkinje");
  snprintf(fiber_mesh_file, sizeof(fiber_mesh_file), "%s", "./mesh/human_hf_214319/purkinje/line.inp");
  snprintf(heart_mesh_file, sizeof(fiber_mesh_file), "%s", "./mesh/human_hf_214319/heart_het.inp");
  snprintf(torso_mesh_file, sizeof(fiber_mesh_file), "%s", "./mesh/torso/p+torso48_closed.inp");
  snprintf(surface_mesh_file, sizeof(surface_mesh_file), "%s", "./mesh/human_hf_214319/surf.inp");
  snprintf(s1_nodes_file, sizeof(s1_nodes_file), "%s", "./mesh/human_hf_214319/heart_apex.dat");
  snprintf(s2_nodes_file, sizeof(s2_nodes_file), "%s", "./mesh/human_hf_214319/heart_L.dat");
#endif
}

void Parameter::show_val()
{
  mpi_printf( 0, "%s -- %s\n", "user_name", user_name);
  mpi_printf( 0, "%s -- %s\n", "hill_file", hill_file );
  mpi_printf( 0, "%s -- %s\n", "herg_file", herg_file );
  mpi_printf( 0, "%s -- %s\n", "is_cvar", is_cvar ? "true" : "false" );
  mpi_printf( 0, "%s -- %s\n", "cvar_file", cvar_file );
  mpi_printf( 0, "%s -- %s\n", "initial_values_zip_file", initial_values_zip_file);
  mpi_printf( 0, "%s -- %s\n", "solver_type", solver_type);
  mpi_printf( 0, "%s -- %s\n", "is_postprocessing", is_postprocessing ? "true" : "false" );
  mpi_printf( 0, "%s -- %lf\n", "cycle_length", cycle_length);
  mpi_printf( 0, "%s -- %hd\n", "number_pacing", number_pacing);
  mpi_printf( 0, "%s -- %hd\n", "number_pacing_write", number_pacing_write);
  mpi_printf( 0, "-------- Restitution Protocol (if applied) -------------\n");
  mpi_printf( 0, "%s -- %hd\n", "cl_decrement", cl_decrement);
  mpi_printf( 0, "%s -- %hd\n", "cl_end", cl_end);
  mpi_printf( 0, "%s -- %hd\n", "rest_pace_max", rest_pace_max);
  mpi_printf( 0, "--------------------------------------------------------\n");
  mpi_printf( 0, "%s -- %lf\n", "time_step_min", time_step_min);
  mpi_printf( 0, "%s -- %lf\n", "time_step_max", time_step_max);
  mpi_printf( 0, "%s -- %lf\n", "writing_step", writing_step);
  mpi_printf( 0, "%s -- %lf\n", "stimulus_duration", stimulus_duration);
  mpi_printf( 0, "%s -- %lf\n", "stimulus_amplitude_scale", stimulus_amplitude_scale);
  mpi_printf( 0, "%s -- %lf\n", "gks_scale", gks_scale);
  mpi_printf( 0, "%s -- %lf\n", "gkr_scale", gkr_scale);
  mpi_printf( 0, "%s -- %lf\n", "gk1_scale", gk1_scale);
  mpi_printf( 0, "%s -- %lf\n", "gto_scale", gto_scale);
  mpi_printf( 0, "%s -- %lf\n", "pca_scale", pca_scale);
  mpi_printf( 0, "%s -- %lf\n", "gna_scale", gna_scale);
  mpi_printf( 0, "%s -- %lf\n", "gnaL_scale", gnal_scale);
  mpi_printf( 0, "%s -- %lf\n", "gnab_scale", gnab_scale);
  mpi_printf( 0, "%s -- %lf\n", "gcab_scale", gcab_scale);
  mpi_printf( 0, "%s -- %lf\n", "gncx_scale", gncx_scale);
  mpi_printf( 0, "%s -- %lf\n", "tau_h_scale", tau_h_scale);
  mpi_printf( 0, "%s -- %s\n", "mutation_type", mutation_type);
  mpi_printf( 0, "%s -- %s\n", "drug_name", drug_name);
  mpi_printf( 0, "%s -- %s\n", "cell_model", cell_model);
  mpi_printf( 0, "%s -- %hd\n", "prior_risk", prior_risk);
  mpi_printf( 0, "%s -- %s\n", "drug_concentrations", drug_concentrations);
#ifdef TISSUE
  mpi_printf( 0, "%s -- %s\n", "is_crt", is_crt ? "true" : "false" );
  mpi_printf( 0, "%s -- %s\n", "is_ecg", is_ecg ? "true" : "false" );
  mpi_printf( 0, "%s -- %s\n", "is_bspm", is_bspm ? "true" : "false" );
  mpi_printf( 0, "%s -- %s\n", "is_lbbb", is_lbbb ? "true" : "false" );
  mpi_printf( 0, "%s -- %s\n", "is_rbbb", is_rbbb ? "true" : "false" );
  mpi_printf( 0, "%s -- %s\n", "is_s1s2", is_s1s2 ? "true" : "false" );
  mpi_printf( 0, "%s -- %s\n", "is_using_output", is_using_output ? "true" : "false" );
  mpi_printf( 0, "%s -- %.2lf\n", "diffusion_scale", diffusion_scale );
  mpi_printf( 0, "%s -- %.2lf\n", "diffusion_scale_fiber", diffusion_scale_fiber );
  mpi_printf( 0, "%s -- %.2lf\n", "apd_fiber", apd_fiber );
  mpi_printf( 0, "%s -- %.2lf\n", "erp_fiber", erp_fiber );
  mpi_printf( 0, "%s -- %.2lf\n", "twrite_vtk", twrite_vtk );
  mpi_printf( 0, "%s -- %.2lf\n", "tmax", tmax );
  mpi_printf( 0, "%s -- %d\n", "dimension", dimension );
  for( int idx = 0; idx < 9; idx++  ){
    mpi_printf( 0, "ecgnode[%d] -- %d\n", idx, ecgnode[idx] );
  }
  mpi_printf( 0, "%s -- %s\n", "mesh_type", mesh_type );
  mpi_printf( 0, "%s -- %s\n", "output_mesh_type", output_mesh_type );
  mpi_printf( 0, "%s -- %s\n", "fiber_mesh_dir", fiber_mesh_dir );
  mpi_printf( 0, "%s -- %s\n", "fiber_mesh_file", fiber_mesh_file );
  mpi_printf( 0, "%s -- %s\n", "heart_mesh_file", heart_mesh_file );
  mpi_printf( 0, "%s -- %s\n", "torso_mesh_file", torso_mesh_file );
  mpi_printf( 0, "%s -- %s\n", "surface_mesh_file", surface_mesh_file );
  mpi_printf( 0, "%s -- %s\n", "s1_nodes_file", s1_nodes_file );
  mpi_printf( 0, "%s -- %s\n", "s2_nodes_file", s2_nodes_file );
#endif
}
