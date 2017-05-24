#ifndef Offshell_AC_h
#define Offshell_AC_h

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

using namespace std;

class Offshell_AC: public Tree
{

public:

   Offshell_AC( double );
   ~Offshell_AC();
   
   void MakeHistograms( TString );
   void MakeHistogramsZX( TString, TString );
   float calculate_K_factor( TString );
   int FindFinalState();
   int FindFinalStateZX();
   int find_current_process( TString );
   void FillInclusive();
   void Save();
   void Delete();
   void GetHistos( TString );
   void Plot1D_AC_SMvsBSM( TString, TString );
   void Plot1D_AC_SMvsBSM_bkg( TString, TString );
   void Plot2D_AC_SMvsBSM( TString, TString );
   
private:

   TFile *input_file, *input_file_data;
   TTree *input_tree, *input_tree_data;

   Histograms *Offshell_AC_histos;
   
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

   int _current_process, _current_final_state, _current_category;
   float _lumi, _k_factor, _SMP_signal_strength, _yield_SR, partial_sample_weight;
   double gen_sum_weights, _event_weight;
   
   vector< vector <float> > _expected_yield_SR, _number_of_events_CR;
   vector<float> _fs_ROS_SS;
   
};
#endif
