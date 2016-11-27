#ifndef Plotter_h
#define Plotter_h

// C++
#include <iostream>
#include <fstream>
#include <iomanip> // For setprecision
#include <vector>

// ROOT
#include "TApplication.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TColor.h"

// Include classes
#include "Tree.h"
#include "Histograms.h"
#include "Category.h"
#include "FinalStates.h"
#include "bitops.h"
#include "FakeRates.h"

// BOOLS
#define APPLY_K_FACTORS 1
#define MERGE_2E2MU 1
#define USE_ZX_RUN2_COMBINED_SHAPE 0
#define USE_ZX_FULL_RUN2_SS 1
#define RENORMALIZE_ZX_FULL_RUN2_SS 0
#define SMOOTH_ZX_FULL_RUN2_SS 0

using namespace std;

class Plotter: public Tree
{

public:
	
	Plotter();
	~Plotter();
   
   void MakeHistograms( TString );
   void MakeHistogramsZX( TString, TString );
   void MakeM4lZX();
   float calculate_K_factor();
   int FindFinalState();
   int FindFinalStateZX();
   int find_current_process( TString );
   int find_resonant_status();
   void FillInclusive();
   void Save();
   void GetHistos( string );
   void Plot1D( string, int, int );
   
private:

   TFile *input_file, *input_file_data;
   TTree *input_tree, *input_tree_data;
   
   TGraph *g_FR_mu_EB, *g_FR_mu_EE, *g_FR_e_EB, *g_FR_e_EE;

   Histograms *blinded_histos, *unblinded_histos, *blinded_histos_110_150;
   
   TColor *_tclr;

   TH1F* hCounters;
   
   Long64_t n_gen_events;
   
   float jetPt[99];
   float jetEta[99];
   float jetPhi[99];
   float jetMass[99];
   float jetQGL[99];
   float jetPgOverPq[99];
	
   const static int _n_variables = 25, _n_blindings = 5, _n_var_pairs = 8;
   
   int _current_process, _current_final_state, _current_category, _current_resonant_status;
   float _lumi, _k_factor, _SMP_signal_strength, _yield_SR, partial_sample_weight;
   double gen_sum_weights, _event_weight;
   
	bool _debug, _do_1D_plots, _do_2D_plots, _apply_K_factors, _rescale_to_SMP_signal_strength, _use_DY_and_ttbar, _rebin_DY_and_ttbar;
	bool _mask_H125_for_low_mass, _mask_H125_for_high_mass, _mask_data_for_high_mass;
   bool _draw_lines, _draw_label_by_hand, _draw_data_MC_ratio, _use_gray_scale;
   
   vector<TString> _s_blinding, _s_process_label, _s_fs_label, _s_fs_label_for_SS, _blinding_label, _var_pair_name;
   vector<TString> _var_pair_Y_label, _var_pair_X_label, _var_cut_label, _var_X_label, _var_Y_label, _var_name;
   
   vector<float> _fs_ROS_SS, _x_histo_blind_low, _x_histo_blind_up, _var_min, _var_max, _expected_yield_SR, _number_of_events_CR;
   
   vector<int> _fs_marker_color, _fs_marker_style, _process_line_color, _process_fill_color, _var_pair_leg_pos, _var_pair_X_N_bin;
   vector<int> _var_pair_X_min, _var_pair_X_max, _var_pair_Y_N_bin, _var_pair_Y_min, _var_pair_Y_max, _rebinning, _var_leg_pos, _var_CMS_pos;
   vector<int> _var_min_factor, _restrict_count_var, _var_N_bin;
   
   vector<bool> _use_process, _var_pair_use_gray_style, _var_pair_leg_is_white, _var_pair_log_x, _var_pair_log_y, _var_log_x, _var_log_y;

};

#endif
