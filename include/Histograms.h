#ifndef Histograms_h
#define Histograms_h

// C++
#include <iostream>
#include <vector>

// ROOT
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TString.h"
#include "TFile.h"
#include "TCanvas.h"
#include "THStack.h"

// Include classes
#include "Settings.h"
#include "M4lZX.h"

using namespace std;

const int num_of_processes = Settings::num_of_processes;
const int num_of_final_states = Settings::num_of_final_states;
const int num_of_resonant_statuses = Settings::num_of_res_statuses;
const int num_of_categories = Settings::num_of_categories;


class Histograms
{
   
public:
   Histograms ();
   ~Histograms();
   void FillM4l( float, float, int, int, int, int );
   void FillM4lZX( float, float, int, int );
   void FillOther();
   void SaveHistos( string );
   void FillInclusive();
   void SmoothHistograms();
   void RenormalizeZX( vector<float> );
   void GetHistos( string );
   void Plot1D( string, int, int );
   
private:

   vector<string> _s_category, _s_resonant_status, _s_final_state, _s_process;
   string _histo_name, _histo_labels;
   
   TH1F *M4lV1[num_of_final_states][num_of_categories][num_of_resonant_statuses][num_of_processes];
   TH1F *M4lV1b;
   TH1F *M4lV2[num_of_final_states][num_of_categories][num_of_resonant_statuses][num_of_processes];
   TH1F *M4lV2Refit;
   TH1F *M4lV2b;
   TH1F *M4lV3;
   TH1F *M4lV4;
   TH1F *M4lV5;
   TH1F *M4l_70110B4;
   TH1F *M4l_70110B5;
   TH1F *M4l_110150;
   TH1F *M4l_105140;
   TH1F *M4l_70182;
   TH1F *M4l_above150;
   
   TH1F *MZ1V1;
   TH1F *MZ1V1Log;
   TH1F *MZ1V1_M4L118130;
   TH1F *MZ1V2;
   TH1F *MZ2V1;
   TH1F *MZ2V1Log;
   TH1F *MZ2V1_M4L118130;
   TH1F *MZ2V2;
   
   TH1F *KD;
   TH1F *KD_M4L118130;
   TH1F *DjetFisher;
   TH1F *DjetVbfMela;
   TH1F *DjetVbfMela_M4L118130;
   TH1F *DjetVbfMelaLog_M4L118130;
   
   TH1F *Pt4l;
   TH1F *Eta4l;
   TH1F *NExtraLep;
   TH1F *NJets;
   TH1F *NJetsBTagged;
   TH1F *M4l_100180_HighKD;
   TH1F *M4l_110150_HighKD;
   
   // Z+X
   TH1F *M4lV2_ZX[num_of_final_states][num_of_categories];
   
};

#endif