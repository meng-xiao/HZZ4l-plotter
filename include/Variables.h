#ifndef Variables_h
#define Variables_h

// C++
#include <iostream>
#include <vector>

// ROOT
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TString.h"
#include "TFile.h"

using namespace std;

class Variables
{
   
public:
   Variables ();
   ~Variables();
   
   struct M4lV1
   {
      TString var_name = "M4lV1";
      string var_X_label = "m_{4#font[12]{l}} (GeV)";
      string var_Y_label = "Events / 3 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 272;
      Float_t var_min = 70;
      Float_t var_max = 886;
      Bool_t var_log_x = 1;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 16;
   };
   
   struct M4lV1b
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 3 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 333;
      Float_t var_min = 1.5;
      Float_t var_max = 1000.5;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4lV2
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 4 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 204;
      Float_t var_min = 70;
      Float_t var_max = 886;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 0;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4lV2Refit
   {
      TString var_X_label = "m_{4#font[12]{l}}^{refit} (GeV)";
      TString var_Y_label = "Events / 4 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 204;
      Float_t var_min = 70;
      Float_t var_max = 886;
      Bool_t var_log_x = 1;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4lV2b
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 4 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 204;
      Float_t var_min = 71;
      Float_t var_max = 887;
      Bool_t var_log_x = 1;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4lV3
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 4 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 163;
      Float_t var_min = 70;
      Float_t var_max = 885;
      Bool_t var_log_x = 1;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };

   struct M4lV4
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 5 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 163;
      Float_t var_min = 70;
      Float_t var_max = 885;
      Bool_t var_log_x = 1;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4lV5
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 10 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 82;
      Float_t var_min = 70;
      Float_t var_max = 890;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4l_70110B4
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 4 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 10;
      Float_t var_min = 70;
      Float_t var_max = 110;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 2;
   };
   
   struct M4l_70110B5
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 5 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 8;
      Float_t var_min = 70;
      Float_t var_max = 110;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 2;
   };
   
   struct M4l_110150
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 2 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 20;
      Float_t var_min = 110;
      Float_t var_max = 150;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4l_105140
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 1 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 35;
      Float_t var_min = 105;
      Float_t var_max = 140;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
      
   struct M4l_70182
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 4 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 28;
      Float_t var_min = 70;
      Float_t var_max = 182;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 0;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4l_above150
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 20 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 30;
      Float_t var_min = 150;
      Float_t var_max = 750;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 3;
   };
   
   struct MZ1V1
   {
      TString var_X_label = "m_{Z1} (GeV)";
      TString var_Y_label = "Events / 2 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 40;
      Float_t var_min = 40;
      Float_t var_max = 120;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 0;
      Int_t varLegPos = 11;
      Int_t rebinningDYTTbar = 5;
   };
   
   struct MZ1V1Log
   {
      TString var_X_label = "m_{Z1} (GeV)";
      TString var_Y_label = "Events / 2 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 40;
      Float_t var_min = 40;
      Float_t var_max = 120;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 1;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 2000;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 11;
      Int_t rebinningDYTTbar = 5;
   };
   
   struct MZ1V1_M4L118130
   {
      TString var_X_label = "m_{Z1} (GeV)";
      TString var_Y_label = "Events / 4 GeV";
      TString var_cut_label = "118 < m_{4#font[12]{l}} < 130 GeV";
      Int_t var_N_bin = 20;
      Float_t var_min = 40;
      Float_t var_max = 120;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 0;
      Int_t varLegPos = 11;
      Int_t rebinningDYTTbar = 2;
   };
   
   struct MZ1V2
   {
      TString var_X_label = "m_{Z1} (GeV)";
      TString var_Y_label = "Events / 5 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 30;
      Float_t var_min = 0;
      Float_t var_max = 150;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 11;
      Int_t rebinningDYTTbar = 2;
   };
   
   struct MZ2V1
   {
      TString var_X_label = "m_{Z2} (GeV)";
      TString var_Y_label = "Events / 2 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 54;
      Float_t var_min = 12;
      Float_t var_max = 120;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 0;
      Int_t varLegPos = 11;
      Int_t rebinningDYTTbar = 5;
   };
   
   struct MZ2V1Log
   {
      TString var_X_label = "m_{Z2} (GeV)";
      TString var_Y_label = "Events / 2 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 54;
      Float_t var_min = 12;
      Float_t var_max = 120;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 1;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 2000;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 11;
      Int_t rebinningDYTTbar = 5;
   };
   
   struct MZ2V1_M4L118130
   {
      TString var_X_label = "m_{Z2} (GeV)";
      TString var_Y_label = "Events / 4 GeV";
      TString var_cut_label = "118 < m_{4#font[12]{l}} < 130 GeV";
      Int_t var_N_bin = 27;
      Float_t var_min = 12;
      Float_t var_max = 120;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 0;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 5;
   };
   
   struct MZ2V2
   {
      TString var_X_label = "m_{Z2} (GeV)";
      TString var_Y_label = "Events / 5 GeV";
      TString var_cut_label = "";
      Int_t var_N_bin = 30;
      Float_t var_min = 0;
      Float_t var_max = 150;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 11;
      Int_t rebinningDYTTbar = 2;
   };
   
   struct KD
   {
      TString var_X_label = "D_{bkg}^{kin}";
      TString var_Y_label = "Events / 0.05";
      TString var_cut_label = "";
      Int_t var_N_bin = 20;
      Float_t var_min = 0;
      Float_t var_max = 1;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 0;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 4;
   };
   
   struct KD_M4L118130
   {
      TString var_X_label = "D_{bkg}^{kin}";
      TString var_Y_label = "Events / 0.1";
      TString var_cut_label = "118 < m_{4#font[12]{l}} < 130 GeV";
      Int_t var_N_bin = 10;
      Float_t var_min = 0;
      Float_t var_max = 1;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 0;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 4;
   };
   
   struct DjetFisher
   {
      TString var_X_label = "D_{jet}";
      TString var_Y_label = "Events / 0.1";
      TString var_cut_label = "";
      Int_t var_N_bin = 20;
      Float_t var_min = 0;
      Float_t var_max = 2;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 4;
   };
   
   struct DjetVbfMela
   {
      TString var_X_label = "D_{jet}";
      TString var_Y_label = "Events / 0.05";
      TString var_cut_label = "";
      Int_t var_N_bin = 20;
      Float_t var_min = 0;
      Float_t var_max = 1;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 4;
   };
   
   struct DjetVbfMela_M4L118130
   {
      TString var_X_label = "D_{jet}";
      TString var_Y_label = "Events / 0.05";
      TString var_cut_label = "118 < m_{4#font[12]{l}} < 130 GeV";
      Int_t var_N_bin = 20;
      Float_t var_min = 0;
      Float_t var_max = 1;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 4;
   };
   
   struct DjetVbfMelaLog_M4L118130
   {
      TString var_X_label = "D_{jet}";
      TString var_Y_label = "Events / 0.05";
      TString var_cut_label = "118 < m_{4#font[12]{l}} < 130 GeV";
      Int_t var_N_bin = 20;
      Float_t var_min = 0;
      Float_t var_max = 1;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 1;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 70;
      Int_t var_CMS_pos = 0;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 2;
   };
   
   struct Pt4l
   {
      TString var_X_label = "p_{T}^{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 10";
      TString var_cut_label = "";
      Int_t var_N_bin = 40;
      Float_t var_min = 0;
      Float_t var_max = 400;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 33;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 2;
   };
   
   struct Eta4l
   {
      TString var_X_label = "#eta^{4#font[12]{l}}";
      TString var_Y_label = "Events / 0.5";
      TString var_cut_label = "";
      Int_t var_N_bin = 20;
      Float_t var_min = -10;
      Float_t var_max = 10;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 2;
   };
   
   struct NExtraLep
   {
      TString var_X_label = "number of additional leptons";
      TString var_Y_label = "Events";
      TString var_cut_label = "";
      Int_t var_N_bin = 6;
      Float_t var_min = 0;
      Float_t var_max = 6;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 1;
      Int_t restrict_count_var = 2;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct NJets
   {
      TString var_X_label = "number of jets";
      TString var_Y_label = "Events";
      TString var_cut_label = "";
      Int_t var_N_bin = 17;
      Float_t var_min = 0;
      Float_t var_max = 17;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 1;
      Int_t restrict_count_var = 4;
      Float_t var_min_factor = 20000;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct NJetsBTagged
   {
      TString var_X_label = "number of tagged b jets";
      TString var_Y_label = "Events";
      TString var_cut_label = "";
      Int_t var_N_bin = 8;
      Float_t var_min = 0;
      Float_t var_max = 8;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 1;
      Int_t restrict_count_var = 2;
      Float_t var_min_factor = 2000;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4l_100180_HighKD
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 3 GeV";
      TString var_cut_label = "D_{bkg}^{kin} > 0.5";
      Int_t var_N_bin = 27;
      Float_t var_min = 100;
      Float_t var_max = 181;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 100000;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };
   
   struct M4l_110150_HighKD
   {
      TString var_X_label = "m_{4#font[12]{l}} (GeV)";
      TString var_Y_label = "Events / 2 GeV";
      TString var_cut_label = "D_{bkg}^{kin} > 0.5";
      Int_t var_N_bin = 20;
      Float_t var_min = 110;
      Float_t var_max = 150;
      Bool_t var_log_x = 0;
      Bool_t var_log_y = 0;
      Int_t restrict_count_var = 0;
      Float_t var_min_factor = 0;
      Int_t var_CMS_pos = 11;
      Int_t varLegPos = 33;
      Int_t rebinningDYTTbar = 1;
   };

   
private:

};

#endif
