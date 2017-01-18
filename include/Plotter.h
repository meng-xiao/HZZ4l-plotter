#ifndef Plotter_h
#define Plotter_h

// C++
#include <iostream>
#include <fstream>
#include <iomanip> // For setprecision
#include <vector>
#include <map>

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
#define RENORMALIZE_ZX_FULL_RUN2_SS 1
#define SMOOTH_ZX_FULL_RUN2_SS 1

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
   void GetHistos( TString );
   void Plot1D_single( TString, TString, TString, int, int );
   void Plot1D_allCAT( TString, TString, TString);
   void Plot1D_allFS( TString, TString, TString);
   void SetBlinding( float, float);
   
private:

   TFile *input_file, *input_file_data;
   TTree *input_tree, *input_tree_data;

   Histograms *blinded_histos, *unblinded_histos;
   
   map<TString, Histograms*> histo_map;
   
   TColor *_tclr;

   TH1F* hCounters;
   
   Long64_t n_gen_events;
   
   float jetPt[99];
   float jetEta[99];
   float jetPhi[99];
   float jetMass[99];
   float jetQGL[99];
   float jetPgOverPq[99];
	
   
   float _blinding_lower = 110, _blinding_upper = 150;
   
   int _current_process, _current_final_state, _current_category, _current_resonant_status;
   float _lumi, _k_factor, _SMP_signal_strength, _yield_SR, partial_sample_weight;
   double gen_sum_weights, _event_weight;
   

   
   vector<float> _expected_yield_SR, _number_of_events_CR, _fs_ROS_SS;
   


};

#endif
