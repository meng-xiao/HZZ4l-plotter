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
#include "cConstants.h"

// BOOLS
#define APPLY_K_FACTORS 1
#define MERGE_2E2MU 1
#define USE_ZX_RUN2_COMBINED_SHAPE 0
#define USE_ZX_FULL_RUN2_SS 1
#define RENORMALIZE_ZX_FULL_RUN2_SS 1
#define SMOOTH_ZX_FULL_RUN2_SS 0

// These are the same 4 WP as in Category.cc
#define WP2J 0.437 // This is the value at 125GeV of 1.043-460./(ZZMass+634.). The latter is also hardcoded in the definition of varPairExprWP.
#define WP1J 0.699
#define OLDWPWH 0.959
#define OLDWPZH 0.9946
// Let's change the c-constants of D_WP and D_ZH for visualization purposes (????)
#define NEWWPWH 0.8
#define NEWWPZH 0.8
#define CUSTOMCCONSTWH ((1.-NEWWPWH)/(NEWWPWH/OLDWPWH-NEWWPWH))
#define CUSTOMCCONSTZH ((1.-NEWWPZH)/(NEWWPZH/OLDWPZH-NEWWPZH))

using namespace std;

class Plotter: public Tree
{

public:
	
	Plotter( bool );
	~Plotter();
   
   void MakeHistograms( TString );
   void MakeYieldsHistograms( TString );
   void MakeHistogramsZX( TString, TString );
   void MakeM4lZX();
   void MakeYieldsM4lZX();
   float calculate_K_factor();
   int FindFinalState();
   int FindFinalStateZX();
   int find_current_process( TString );
   int find_current_process_yields( TString );
   int find_resonant_status();
   bool blind( float );
   void FillInclusive();
   void FillInclusiveYields();
   void Save();
   void SaveYields();
   void Delete();
   void DeleteYields();
   void GetHistos( TString );
   void GetYieldsHistos( TString );
   void Plot1D_single( TString, TString, TString, int, int );
   void Plot1D_allCAT( TString, TString, TString);
   void Plot1D_allFS( TString, TString, TString);
   void Plot2D_single( TString, TString, TString, int );
   void Plot2DError_single( TString, TString, TString, int );
   void PrintYields( TString);
   void PrintYields( TString, float, float);
   void SetBlinding( float, float);
   void SetBlinding( float, float, float, float);
   
private:

   TFile *input_file, *input_file_data;
   TTree *input_tree, *input_tree_data;

   Histograms *blinded_histos, *unblinded_histos, *yields_histos;
   
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
   
   Float_t KD;
   Float_t D2jet;
   Float_t D1jet;
   Float_t DWH;
   Float_t DZH;
	
   
   float _blinding_lower[2], _blinding_upper[2];
   
   int _current_process, _current_final_state, _current_category, _current_resonant_status;
   float _lumi, _k_factor, _SMP_signal_strength, _yield_SR, partial_sample_weight;
   double gen_sum_weights, _event_weight;
   

   
   vector< vector <float> > _expected_yield_SR, _number_of_events_CR;
   vector<float> _fs_ROS_SS;
   


};

#endif
