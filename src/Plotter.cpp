// Include classes
#include "Plotter.h"

// Constructor
//============================================================
Plotter::Plotter():Tree()
{
//   blinded_histos = new Histograms();
   blinded_histos_110_150 = new Histograms();

   g_FR_mu_EB = 0;
   g_FR_mu_EE = 0;
   g_FR_e_EB = 0;
   g_FR_e_EE = 0;

   _lumi = 12.9;
   _current_process = -999;
   _k_factor = 1;
   _current_final_state = -999;
   _current_category = -999;
   
   _debug = false;
	_do_1D_plots = true;
	_do_2D_plots = true;
		
	_apply_K_factors = true;
   _rescale_to_SMP_signal_strength = true;
	_SMP_signal_strength = 0.99;
	
   _use_DY_and_ttbar = false;
   _rebin_DY_and_ttbar = false;
	
   _mask_H125_for_low_mass = true;
   _mask_H125_for_high_mass = true;
   _mask_data_for_high_mass = false;
		
   _draw_lines = false;
   _draw_label_by_hand = true;
   _draw_data_MC_ratio = false;
   _use_gray_scale = false;
		
   _var_name.push_back("M4lV1");
   _var_name.push_back("M4lV2");
   _var_name.push_back("M4lV3");
   _var_name.push_back("M4lV4");
   _var_name.push_back("M4lV5");
   _var_name.push_back("M4l_70110B4");
   _var_name.push_back("M4l_70110B5");
   _var_name.push_back("M4l_70109");
   _var_name.push_back("M4l_70181");
   _var_name.push_back("M4l_above150");
   _var_name.push_back("MZ1V1");
   _var_name.push_back("MZ1V1Log");
   _var_name.push_back("MZ1V2");
   _var_name.push_back("MZ2V1");
   _var_name.push_back("MZ2V1Log");
   _var_name.push_back("MZ2V2");
   _var_name.push_back("KD");
   _var_name.push_back("Fisher");
   _var_name.push_back("VbfMela");
   _var_name.push_back("Pt4l");
   _var_name.push_back("Eta4l");
   _var_name.push_back("NExtraLep");
   _var_name.push_back("NJets");
   _var_name.push_back("NJetsBTagged");
   _var_name.push_back("M4l_100180_HighKD");

   _var_pair_name.push_back("M4lVsKD");
   _var_pair_name.push_back("M4lVsKD_M4L70110");
   _var_pair_name.push_back("M4lVsKD_M4L114180");
   _var_pair_name.push_back("M4lVsKD_M4L180780");
   _var_pair_name.push_back("M4lVsKD_M4L150700");
   _var_pair_name.push_back("MZ1VsMZ2V1");
   _var_pair_name.push_back("MZ1VsMZ2V2");
   _var_pair_name.push_back("MZ1VsMZ2V3");
   
   _var_pair_X_label.push_back("m_{4#font[12]{l}} (GeV)");
   _var_pair_X_label.push_back("m_{4#font[12]{l}} (GeV)");
   _var_pair_X_label.push_back("m_{4#font[12]{l}} (GeV)");
   _var_pair_X_label.push_back("m_{4#font[12]{l}} (GeV)");
   _var_pair_X_label.push_back("m_{4#font[12]{l}} (GeV)");
   _var_pair_X_label.push_back("m_{Z_{1}} (GeV)");
   _var_pair_X_label.push_back("m_{Z_{1}} (GeV)");
   _var_pair_X_label.push_back("m_{Z_{1}} (GeV)");
   
   _var_pair_Y_label.push_back("D_{bkg}^{kin}");
   _var_pair_Y_label.push_back("D_{bkg}^{kin}");
   _var_pair_Y_label.push_back("D_{bkg}^{kin}");
   _var_pair_Y_label.push_back("D_{bkg}^{kin}");
   _var_pair_Y_label.push_back("D_{bkg}^{kin}");
   _var_pair_Y_label.push_back("m_{Z_{2}} (GeV)");
   _var_pair_Y_label.push_back("m_{Z_{2}} (GeV)");
   _var_pair_Y_label.push_back("m_{Z_{2}} (GeV)");
   
   _var_pair_X_N_bin = { 262, 40, 33, 120, 110, 40, 80, 60 };
   _var_pair_X_min = { 100, 70, 114, 180, 150, 40, 40, 75 };
   _var_pair_X_max = { 886, 110, 180, 780, 700, 120, 120, 105 };
   
   _var_pair_Y_N_bin = { 30, 30, 30, 30, 30, 54, 108, 60 };
   _var_pair_Y_min = { 0, 0, 0, 0, 0, 12, 12, 75 };
   _var_pair_Y_max = { 1, 1, 1, 1, 1, 120, 120, 105 };
   
   _var_pair_log_x = { 1, 0, 0, 0, 0, 0, 0, 0 };
   _var_pair_log_y = { 0, 0, 0, 0, 0, 0, 0, 0 };
   
   _var_pair_leg_pos = { 33, 33, 33, 33, 33, 11, 11, 11 };
   _var_pair_leg_is_white = { 1, 1, 1, 1, 1, 0, 0, 0 };
   _var_pair_use_gray_style = { 0, 0, 0, 0, 0, 1, 1, 1};
   
   bool _plot_this_var_pair[3][_n_var_pairs] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 1, 0, 0, 1, 0, 1, 1 },
      { 1, 1, 1, 1, 1, 1, 1, 1 }
   };

   
// ========
// Blinding
// ========
   
   _s_blinding = { "fullyblind", "M4l70To110", "M4l150ToInf", "blind110150", "unblinded" };
   
   bool _plot_this_blinding[5][_n_blindings] = {
      {1, 1, 1, 1, 0,},
      {1, 0, 0, 0, 0,},
      {0, 1, 0, 0, 0,},
      {0, 0, 1, 0, 0,},
      {0, 0, 0, 1, 0},
   };
   
   _blinding_label.push_back("");
   _blinding_label.push_back("70 < m_{4#font[12]{l}} < 110 GeV");
   _blinding_label.push_back("m_{4#font[12]{l}} > 150 GeV");
   _blinding_label.push_back("#splitline{m_{4#font[12]{l}} > 70 GeV}{m_{4#font[12]{l}} #notin [110, 150] GeV}");
   _blinding_label.push_back("");
   
   _x_histo_blind_low = { 0., 110., 0., 110., 0. };
   _x_histo_blind_up = { -1., 1000., 150., 150., -1. };
   
   _process_fill_color.push_back(_tclr->GetColor("#000000"));
   _process_fill_color.push_back(_draw_lines?_tclr->GetColor("#ffafaf"):_tclr->GetColor("#ff9090"));
   _process_fill_color.push_back(_draw_lines?_tclr->GetColor("#99ccff"):_tclr->GetColor("#8bc5ff"));
   _process_fill_color.push_back(_draw_lines?_tclr->GetColor("#3366ff"):_tclr->GetColor("#2c5Df0"));
   _process_fill_color.push_back(_draw_lines?_tclr->GetColor("#669966"):_tclr->GetColor("#6dae6d"));
   _process_fill_color.push_back(_tclr->GetColor("#9a6666"));
   
   _process_line_color.push_back(_tclr->GetColor("#000000"));
   _process_line_color.push_back(_tclr->GetColor("#cc0000"));
   _process_line_color.push_back(_tclr->GetColor("#000099"));
   _process_line_color.push_back(_tclr->GetColor("#000099"));
   _process_line_color.push_back(_tclr->GetColor("#003300"));
   _process_line_color.push_back(_tclr->GetColor("#5f3f3f"));
   
   _use_process = { 1, 1, 1, 1, _use_DY_and_ttbar, _use_DY_and_ttbar };
   
   _fs_marker_style = {20, 22, 21, 33, 29 };
   _fs_marker_color = { kRed, kGreen + 1, kAzure + 1, kViolet, kBlack };
   
   // Z+X SS factors
   // FIXME: recompute this for Run II
   _fs_ROS_SS.push_back(1.22);
   _fs_ROS_SS.push_back(0.97);
   _fs_ROS_SS.push_back(1.30);
   _fs_ROS_SS.push_back(0.98);
   
   _s_process_label.push_back("Data");
   _s_process_label.push_back("H(125)");
   _s_process_label.push_back("H(125), VBF");
   _s_process_label.push_back("H(125), other");
   _s_process_label.push_back("q#bar{q}#rightarrowZZ");
   _s_process_label.push_back("Z#gamma*");
   _s_process_label.push_back("gg#rightarrowZZ, Z#gamma*");
   _s_process_label.push_back("Z + jets");
   _s_process_label.push_back("t#bar{t}");
   
   _s_fs_label_for_SS.push_back("Z1->mu+mu- + mumu(SS)");
   _s_fs_label_for_SS.push_back("Z1->e+e- + ee(SS)");
   _s_fs_label_for_SS.push_back("Z1->e+e- + mumu(SS)");
   _s_fs_label_for_SS.push_back("Z1->mu+mu- + ee(SS)");
   
   _s_fs_label.push_back("4#mu");
   _s_fs_label.push_back("4e");
   _s_fs_label.push_back("2e2#mu");
   _s_fs_label.push_back("2#mu2e");
   _s_fs_label.push_back("4#font[12]{l}");
   
   
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      _expected_yield_SR.push_back(0);
      _number_of_events_CR.push_back(0);
   }

}
//============================================================



// Destructor
//====================
Plotter::~Plotter()
{
}
//====================



//=====================================================
void Plotter::MakeHistograms( TString input_file_name )
{

   input_file = new TFile("./" + input_file_name);
   
   cout << input_file_name << endl;
   
   hCounters = (TH1F*)input_file->Get("ZZTree/Counters");
   n_gen_events = (Long64_t)hCounters->GetBinContent(1);
   gen_sum_weights = (Long64_t)hCounters->GetBinContent(40);
   
   input_tree = (TTree*)input_file->Get("ZZTree/candTree");
   Init(input_tree);
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   
   for (Long64_t jentry=0; jentry<nentries;jentry++)
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);
      nbytes += nb;
   
      if ( LepEta->size() != 4 )
      {
         cout << "[ERROR] in event " << RunNumber << ":" << LumiNumber << ":" << EventNumber << ", stored " << LepEta->size() << " leptons instead of 4" << endl;
         continue;
      }

      if ( !(ZZsel >= 90) ) continue;

      // Find current process
      _current_process = find_current_process( input_file_name );
   
      // Final states
      _current_final_state = FindFinalState();
   
      // Categories
   
      for ( int j = 0; j < nCleanedJetsPt30; j++)
      {
         jetPt[j] = JetPt->at(j);
         jetEta[j] = JetEta->at(j);
         jetPhi[j] = JetPhi->at(j);
         jetMass[j] = JetMass->at(j);
         jetQGL[j] = JetQGLikelihood->at(j);
         jetPgOverPq[j] = 1./JetQGLikelihood->at(j) - 1.;
      }

      _current_category = categoryIchep16( nExtraLep, nExtraZ, nCleanedJetsPt30, nCleanedJetsPt30BTagged, jetQGL, phjj_VAJHU_highestPTJets,
      phj_VAJHU, pvbf_VAJHU_highestPTJets, pAux_vbf_VAJHU, pwh_hadronic_VAJHU, pzh_hadronic_VAJHU, jetPhi, ZZMass, false );
   
      // Resonant status
      _current_resonant_status = find_resonant_status();
   
      // K factors
      if ( APPLY_K_FACTORS ) _k_factor = calculate_K_factor();
   
      // Final event weight
      _event_weight = (_lumi * 1000 * xsec * _k_factor * overallEventWeight) / gen_sum_weights;
   
   
      // Fill histograms
      if ( _current_process != Settings::Data )
      {
//         blinded_histos->FillM4l( ZZMass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      }
      if ( (_current_process == Settings::Data && (ZZMass < 110 || ZZMass > 150)) || _current_process != Settings::Data )
       {
           blinded_histos_110_150->FillM4l( ZZMass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
       }
   } // end for loop
   
}
//=====================================================



//=======================
void Plotter::MakeM4lZX()
{
    for (int i_fs = 0; i_fs < num_of_final_states; i_fs++)
    {
        for(int i_cat = 0; i_cat < num_of_categories; i_cat++)
        {
            blinded_histos_110_150->MakeZXShape( i_fs, i_cat, _lumi );
        }
    }
	
}
//=======================



//===============================================================================
void Plotter::MakeHistogramsZX( TString input_file_data_name, TString  input_file_FR_name )
{

   FakeRates *FR = new FakeRates( input_file_FR_name );

   input_file_data = new TFile("./" + input_file_data_name);

   input_tree_data = (TTree*)input_file_data->Get("CRZLLTree/candTree");
   Init(input_tree_data);

   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   
   for (Long64_t jentry=0; jentry<nentries;jentry++)
   {
   
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);
      nbytes += nb;
   
      if ( !CRflag ) continue;
      if ( !test_bit(CRflag, CRZLLss) ) continue;
   
      _current_final_state = FindFinalStateZX();
   
      _current_category = categoryIchep16( nExtraLep, nExtraZ, nCleanedJetsPt30, nCleanedJetsPt30BTagged, jetQGL, phjj_VAJHU_highestPTJets,
      phj_VAJHU, pvbf_VAJHU_highestPTJets, pAux_vbf_VAJHU, pwh_hadronic_VAJHU, pzh_hadronic_VAJHU, jetPhi, ZZMass, false );
   
      // Calculate yield
      _yield_SR = _fs_ROS_SS.at(_current_final_state)*FR->GetFakeRate(LepPt->at(2),LepEta->at(2),LepLepId->at(2))*FR->GetFakeRate(LepPt->at(3),LepEta->at(3),LepLepId->at(3));
   
   
      // START fill histograms
      // cout << "[INFO] Filling Z+X histograms..." << endl;
   
//      blinded_histos->FillM4lZX( ZZMass, _yield_SR, _current_final_state, _current_category );
      blinded_histos_110_150->FillM4lZX( ZZMass, _yield_SR, _current_final_state, _current_category);
   
      _expected_yield_SR.at(_current_final_state) += _yield_SR;
      _number_of_events_CR.at(_current_final_state)++;
   
   } // END events loop
   
   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      _expected_yield_SR.at(num_of_final_states - 1) += _expected_yield_SR.at(i_fs);
      _number_of_events_CR.at(num_of_final_states - 1) += _number_of_events_CR.at(i_fs);
   }

   // Print Z + X expected yields
   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      cout << _s_fs_label_for_SS.at(i_fs) << " : " << _expected_yield_SR.at(i_fs) << " +/- " <<
      _expected_yield_SR.at(i_fs)/sqrt(_number_of_events_CR.at(i_fs)) << " (stat., evt: " <<
      _number_of_events_CR.at(i_fs) << ")" << " +/- " << _expected_yield_SR.at(i_fs)*0.50 << " (syst.)" << endl;
   }
  
   cout << "[INFO] Total = " << _expected_yield_SR.at(num_of_final_states - 1) << endl;
   
   // Smooth histograms
   if ( SMOOTH_ZX_FULL_RUN2_SS )
   {
      cout << "[INFO] Smoothing Z+X histograms..." << endl;
      blinded_histos_110_150->SmoothHistograms();
   }
   
   // Renormalize Z+X histograms
   if ( RENORMALIZE_ZX_FULL_RUN2_SS )
   {
      if ( MERGE_2E2MU )
      {
         cout << "[INFO] Renormalizing Z+X histograms..." << endl;
         blinded_histos_110_150->RenormalizeZX( _expected_yield_SR );
      }
   }


}
//===============================================================================



//=========================================
void Plotter::GetHistos( string file_name )
{
   blinded_histos_110_150->GetHistos( file_name );
}
//=========================================



//===========================
void Plotter::FillInclusive()
{
//   blinded_histos->FillInclusive();
   blinded_histos_110_150->FillInclusive();
}
//===========================



//==================
void Plotter::Save()
{
//   blinded_histos->SaveHistos("Blinded_test.root");
   blinded_histos_110_150->SaveHistos("Blinded_110_150_test.root");
}
//==================



//==================
void Plotter::Plot1D( string variable_name, int fs, int cat )
{
   blinded_histos_110_150->Plot1D( variable_name, fs, cat );
}
//==================



//==========================================================
int Plotter::find_current_process( TString input_file_name )
{

   int current_process = -999;
   
   // Assign dataset to correct process
   if ( input_file_name.Contains("Data") )           current_process = Settings::Data;
   if ( input_file_name.Contains("ggH125") )         current_process = Settings::H125NOVBF;
   if ( input_file_name.Contains("VBFH125") )        current_process = Settings::H125VBF;
   if ( input_file_name.Contains("WpH125") )         current_process = Settings::H125NOVBF;
   if ( input_file_name.Contains("WmH125") )         current_process = Settings::H125NOVBF;
   if ( input_file_name.Contains("ZH125") )          current_process = Settings::H125NOVBF;
   if ( input_file_name.Contains("ttH125") )         current_process = Settings::H125NOVBF;
   if ( input_file_name.Contains("ZZTo4l") )         current_process = Settings::qqZZ;
   if ( input_file_name.Contains("ggTo4e") )         current_process = Settings::ggZZ;
   if ( input_file_name.Contains("ggTo4mu") )        current_process = Settings::ggZZ;
   if ( input_file_name.Contains("ggTo4tau") )       current_process = Settings::ggZZ;
   if ( input_file_name.Contains("ggTo2e2mu") )      current_process = Settings::ggZZ;
   if ( input_file_name.Contains("ggTo2e2tau") )     current_process = Settings::ggZZ;
   if ( input_file_name.Contains("ggTo2mu2tau") )    current_process = Settings::ggZZ;
   if ( input_file_name.Contains("DYJetsToLL_M50") ) current_process = Settings::DY;
   if ( input_file_name.Contains("TTJets") )         current_process = Settings::ttbar;
   if ( input_file_name.Contains("TTTo2L2Nu") )      current_process = Settings::ttbar;
   // End assign dataset to correct process

   return current_process;
}
//==========================================================



//=================================
float Plotter::calculate_K_factor()
{

   float k_factor = 1;
   
   if ( _current_process == Settings::qqZZ )
   {
//      k_factor = KFactor_EW_qqZZ * KFactor_QCD_qqZZ_M; // As of Moriond2016
   }
   else if ( _current_process == Settings::ggZZ )
   {
      k_factor = KFactor_QCD_ggZZ_Nominal; // as of Moriond2016
   }
   return k_factor;
}
//=================================



//===========================
int Plotter::FindFinalState()
{
   int final_state = -999;

   if ( Z1Flav == -121 )
   {
      if ( Z2Flav == -121 )
         final_state = Settings::fs4e;
      else if ( Z2Flav == -169 )
         final_state = Settings::fs2e2mu;
      else
         cerr << "[ERROR] in event " << RunNumber << ":" << LumiNumber << ":" << EventNumber << ", Z2Flav = " << Z2Flav << endl;
      }
   else if ( Z1Flav == -169 )
   {
      if ( Z2Flav == -121 )
         final_state = Settings::fs2mu2e;
      else if ( Z2Flav == -169 )
         final_state = Settings::fs4mu;
      else
         cerr << "[ERROR] in event " << RunNumber << ":" << LumiNumber << ":" << EventNumber << ", Z2Flav = " << Z2Flav << endl;
   }
   else
   {
      cerr << "[ERROR] in event " << RunNumber << ":" << LumiNumber << ":" << EventNumber << ", Z1Flav = " << Z1Flav << endl;
   }
   
   if ( MERGE_2E2MU && final_state == Settings::Settings::fs2mu2e ) final_state = Settings::fs2e2mu;

   return final_state;
}
//===========================



//=============================
int Plotter::FindFinalStateZX()
{
   int final_state = -999;

   if ( Z1Flav == -121 )
   {
      if ( Z2Flav == +121 )
         final_state = Settings::fs4e;
      else if ( Z2Flav == +169 )
         final_state = Settings::fs2e2mu;
      else
         cerr << "[ERROR] in event " << RunNumber << ":" << LumiNumber << ":" << EventNumber << ", Z2Flav = " << Z2Flav << endl;
      }
   else if ( Z1Flav == -169 )
   {
      if ( Z2Flav == +121 )
         final_state = Settings::fs2mu2e;
      else if ( Z2Flav == +169 )
         final_state = Settings::fs4mu;
      else
         cerr << "[ERROR] in event " << RunNumber << ":" << LumiNumber << ":" << EventNumber << ", Z2Flav = " << Z2Flav << endl;
   }
   else
   {
      cerr << "[ERROR] in event " << RunNumber << ":" << LumiNumber << ":" << EventNumber << ", Z1Flav = " << Z1Flav << endl;
   }
   
   if ( MERGE_2E2MU && final_state == Settings::Settings::fs2mu2e ) final_state = Settings::fs2e2mu;
   
   return final_state;
}
//=============================



//=================================
int Plotter::find_resonant_status()
{

   int current_resonant_status = -999;
   
   if ( _current_process == Settings::Data )
   {
      current_resonant_status = Settings::resonant;
   }
   else
   {
      Short_t GenHLepId[4] = { GenLep1Id, GenLep2Id, GenLep3Id, GenLep4Id };
      Int_t nGenHLep = 0;
	
      for ( Int_t iGenHLep = 0; iGenHLep < 4; iGenHLep++ )
      {
         if ( abs(GenHLepId[iGenHLep]) == 11 || abs(GenHLepId[iGenHLep]) == 13 ) nGenHLep++;
      }
   
      current_resonant_status = (nGenHLep == 4) ? Settings::resonant : Settings::nonresonant;
   }
   
   return current_resonant_status;

}
//=================================
