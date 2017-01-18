// Include classes
#include "Plotter.h"

// Constructor
//============================================================
Plotter::Plotter():Tree()
{
   unblinded_histos = new Histograms("Unblinded");
   blinded_histos = new Histograms("Blinded");
   
   histo_map["Unblinded"] = unblinded_histos;
   histo_map["Blinded"] = blinded_histos;

   _lumi = 12.9;
   _current_process = -999;
   _k_factor = 1;
   _current_final_state = -999;
   _current_category = -999;
   
   //Get colours needed for plots
   _tclr->GetColor("#000000");
   _tclr->GetColor("#ffafaf");
   _tclr->GetColor("#ff9090");
   _tclr->GetColor("#99ccff");
   _tclr->GetColor("#8bc5ff");
   _tclr->GetColor("#3366ff");
   _tclr->GetColor("#2c5Df0");
   _tclr->GetColor("#669966");
   _tclr->GetColor("#6dae6d");
   _tclr->GetColor("#9a6666");
   _tclr->GetColor("#cc0000");
   _tclr->GetColor("#000099");
   _tclr->GetColor("#003300");
   _tclr->GetColor("#5f3f3f");
   
   // Z+X SS factors
   // FIXME: recompute this for Run II, WHAT ARE THESE????
   _fs_ROS_SS.push_back(1.22);
   _fs_ROS_SS.push_back(0.97);
   _fs_ROS_SS.push_back(1.30);
   _fs_ROS_SS.push_back(0.98);
   
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
   
      // Calculate kinematic discriminants
      KD = p0plus_VAJHU / ( p0plus_VAJHU + bkg_VAMCFM*getDbkgkinConstant(Z1Flav*Z2Flav,ZZMass) );
      D2jet = (nCleanedJetsPt30>=2) ? pvbf_VAJHU_highestPTJets / ( pvbf_VAJHU_highestPTJets + phjj_VAJHU_highestPTJets*getDVBF2jetsConstant(ZZMass) ) : -2 ;
      D1jet = (nCleanedJetsPt30==1) ? pvbf_VAJHU_highestPTJets*pAux_vbf_VAJHU / ( pvbf_VAJHU_highestPTJets*pAux_vbf_VAJHU + phj_VAJHU*getDVBF1jetConstant(ZZMass) ) : -2 ;
      DWH = (nCleanedJetsPt30>=2) ? pwh_hadronic_VAJHU / ( pwh_hadronic_VAJHU + CUSTOMCCONSTWH*1e5*phjj_VAJHU_highestPTJets ) : -2 ;
      DZH = (nCleanedJetsPt30>=2) ? pzh_hadronic_VAJHU / ( pzh_hadronic_VAJHU + CUSTOMCCONSTZH*1e4*phjj_VAJHU_highestPTJets ) : -2 ;
   
      // Fill M4l histograms
      if ( (_current_process == Settings::Data && (ZZMass < _blinding_lower || ZZMass > _blinding_upper)) || _current_process != Settings::Data )
       {
           blinded_histos->FillM4l( ZZMass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
           
       }
       
       unblinded_histos->FillM4l( ZZMass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
      // Fill MZ1 histograms
      if ( (ZZMass < _blinding_lower) || (ZZMass > _blinding_upper) )
      {
         blinded_histos->FillMZ1( Z1Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      }
      
      unblinded_histos->FillMZ1( Z1Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      unblinded_histos->FillMZ1_cut( ZZMass, Z1Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
      // Fill MZ2 histograms
      if ( (ZZMass < _blinding_lower) || (ZZMass > _blinding_upper) )
      {
         blinded_histos->FillMZ2( Z2Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      }
      
      unblinded_histos->FillMZ2( Z2Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      unblinded_histos->FillMZ2_cut( ZZMass, Z2Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
      // Fill KD histograms
      if ( (ZZMass < _blinding_lower) || (ZZMass > _blinding_upper) )
      {
         blinded_histos->FillKD( KD, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
         if(nCleanedJetsPt30==1) blinded_histos->FillD1jet( D1jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
         if(nCleanedJetsPt30>=2) blinded_histos->FillD2jet( D2jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
         if(nCleanedJetsPt30>=2) blinded_histos->FillDWH( DWH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
         if(nCleanedJetsPt30>=2) blinded_histos->FillDZH( DZH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      }
      
      unblinded_histos->FillKD( KD, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30==1) unblinded_histos->FillD1jet( D1jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30>=2) unblinded_histos->FillD2jet( D2jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30>=2) unblinded_histos->FillDWH( DWH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30>=2) unblinded_histos->FillDZH( DZH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
      unblinded_histos->FillKD_cut( ZZMass, KD, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30==1) unblinded_histos->FillD1jet_cut( ZZMass, D1jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30>=2) unblinded_histos->FillD2jet_cut( ZZMass, D2jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30>=2) unblinded_histos->FillDWH_cut( ZZMass, DWH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30>=2) unblinded_histos->FillDZH_cut( ZZMass, DZH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
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
            blinded_histos->MakeZXShape( i_fs, i_cat, _lumi );
            unblinded_histos->MakeZXShape( i_fs, i_cat, _lumi);
        }
    }
}
//=======================

void Plotter::SetBlinding(float blinding_lower, float blinding_upper)
{
   _blinding_lower = blinding_lower;
   _blinding_upper = blinding_upper;
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
   
      // Calculate kinematic discriminants
      KD = p0plus_VAJHU / ( p0plus_VAJHU + bkg_VAMCFM*getDbkgkinConstant(Z1Flav*Z2Flav,ZZMass) );
      D2jet = (nCleanedJetsPt30>=2) ? pvbf_VAJHU_highestPTJets / ( pvbf_VAJHU_highestPTJets + phjj_VAJHU_highestPTJets*getDVBF2jetsConstant(ZZMass) ) : -2 ;
      D1jet = (nCleanedJetsPt30==1) ? pvbf_VAJHU_highestPTJets*pAux_vbf_VAJHU / ( pvbf_VAJHU_highestPTJets*pAux_vbf_VAJHU + phj_VAJHU*getDVBF1jetConstant(ZZMass) ) : -2 ;
      DWH = (nCleanedJetsPt30>=2) ? pwh_hadronic_VAJHU / ( pwh_hadronic_VAJHU + CUSTOMCCONSTWH*1e5*phjj_VAJHU_highestPTJets ) : -2 ;
      DZH = (nCleanedJetsPt30>=2) ? pzh_hadronic_VAJHU / ( pzh_hadronic_VAJHU + CUSTOMCCONSTZH*1e4*phjj_VAJHU_highestPTJets ) : -2 ;
      
      // START fill histograms
      //cout << "[INFO] Filling Z+X histograms..." << endl;
   
      // Fill m4l Z+X histograms
      unblinded_histos->FillM4lZX( ZZMass, _yield_SR, _current_final_state, _current_category );
      blinded_histos->FillM4lZX( ZZMass, _yield_SR, _current_final_state, _current_category);
      
      // Fill mZ1 Z+X histograms
      unblinded_histos->FillMZ1ZX( Z1Mass, _yield_SR, _current_final_state, _current_category );
      unblinded_histos->FillMZ1ZX_cut( ZZMass, Z1Mass, _yield_SR, _current_final_state, _current_category );
      
      if ( (ZZMass < _blinding_lower) || (ZZMass > _blinding_upper) )
      {
         blinded_histos->FillMZ1ZX( Z1Mass, _yield_SR, _current_final_state, _current_category);
      }
      
      // Fill mZ2 Z+X histograms
      unblinded_histos->FillMZ2ZX( Z2Mass, _yield_SR, _current_final_state, _current_category );
      unblinded_histos->FillMZ2ZX_cut( ZZMass, Z2Mass, _yield_SR, _current_final_state, _current_category );
      
      if ( (ZZMass < _blinding_lower) || (ZZMass > _blinding_upper) )
      {
         blinded_histos->FillMZ2ZX( Z2Mass, _yield_SR, _current_final_state, _current_category);
      }
      
      // Fill KD Z+X histograms
      unblinded_histos->FillKDZX( KD, _yield_SR, _current_final_state, _current_category );
      unblinded_histos->FillKDZX_cut( ZZMass, KD, _yield_SR, _current_final_state, _current_category );
      
      if(nCleanedJetsPt30 == 1) unblinded_histos->FillD1jetZX( D1jet, _yield_SR, _current_final_state, _current_category );
      if(nCleanedJetsPt30 == 1) unblinded_histos->FillD1jetZX_cut( ZZMass, D1jet, _yield_SR, _current_final_state, _current_category );
      
      if(nCleanedJetsPt30 >= 2) unblinded_histos->FillD2jetZX( D2jet, _yield_SR, _current_final_state, _current_category );
      if(nCleanedJetsPt30 >= 2) unblinded_histos->FillD2jetZX_cut( ZZMass, D2jet, _yield_SR, _current_final_state, _current_category );
      
      if(nCleanedJetsPt30 >= 2) unblinded_histos->FillDWHZX( DWH, _yield_SR, _current_final_state, _current_category );
      if(nCleanedJetsPt30 >= 2) unblinded_histos->FillDWHZX_cut( ZZMass, DWH, _yield_SR, _current_final_state, _current_category );

      if(nCleanedJetsPt30 >= 2) unblinded_histos->FillDZHZX( DZH, _yield_SR, _current_final_state, _current_category );
      if(nCleanedJetsPt30 >= 2) unblinded_histos->FillDZHZX_cut( ZZMass, DZH, _yield_SR, _current_final_state, _current_category );

      
      if ( (ZZMass < _blinding_lower) || (ZZMass > _blinding_upper) )
      {
         blinded_histos->FillKDZX( KD, _yield_SR, _current_final_state, _current_category);
         if(nCleanedJetsPt30 == 1) blinded_histos->FillD1jetZX( D1jet, _yield_SR, _current_final_state, _current_category);
         if(nCleanedJetsPt30 >= 2) blinded_histos->FillD2jetZX( D2jet, _yield_SR, _current_final_state, _current_category);
         if(nCleanedJetsPt30 >= 2) blinded_histos->FillDWHZX( DWH, _yield_SR, _current_final_state, _current_category);
         if(nCleanedJetsPt30 >= 2) blinded_histos->FillDZHZX( DZH, _yield_SR, _current_final_state, _current_category);
      }

   
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
      cout << i_fs << " : " << _expected_yield_SR.at(i_fs) << " +/- " <<
      _expected_yield_SR.at(i_fs)/sqrt(_number_of_events_CR.at(i_fs)) << " (stat., evt: " <<
      _number_of_events_CR.at(i_fs) << ")" << " +/- " << _expected_yield_SR.at(i_fs)*0.50 << " (syst.)" << endl;
   }
  
   cout << "[INFO] Total = " << _expected_yield_SR.at(num_of_final_states - 1) << endl;
   
   // Smooth histograms
   if ( SMOOTH_ZX_FULL_RUN2_SS )
   {
      cout << "[INFO] Smoothing Z+X histograms..." << endl;
      blinded_histos->SmoothHistograms();
      unblinded_histos->SmoothHistograms();
   }
    
   unblinded_histos->RenormalizeZX();
   blinded_histos->RenormalizeZX();
   
    
}
//===============================================================================



//=========================================
void Plotter::GetHistos( TString file_name )
{
   histo_map[file_name]->GetHistos( file_name + ".root" );
}
//=========================================



//===========================
void Plotter::FillInclusive()
{
   unblinded_histos->FillInclusive();
   blinded_histos->FillInclusive();
}
//===========================



//==================
void Plotter::Save()
{
   unblinded_histos->SaveHistos("Unblinded.root");
   blinded_histos->SaveHistos("Blinded.root");
}
//==================



//==================
void Plotter::Plot1D_single( TString file_name, TString variable_name, TString folder, int fs, int cat )
{
   histo_map[file_name]->Plot1D_single( file_name, variable_name, folder, fs, cat );
   
}
//==================

//==================
void Plotter::Plot1D_allCAT( TString file_name, TString variable_name, TString folder)
{
   histo_map[file_name]->Plot1D_allCAT( file_name, variable_name, folder);
   
}
//==================

//==================
void Plotter::Plot1D_allFS( TString file_name, TString variable_name, TString folder)
{
   histo_map[file_name]->Plot1D_allFS( file_name, variable_name, folder);
   
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
      k_factor = KFactor_EW_qqZZ * KFactor_QCD_qqZZ_M; // As of Moriond2016
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
   
   if ( MERGE_2E2MU && final_state == Settings::fs2mu2e ) final_state = Settings::fs2e2mu;

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
   
   if ( MERGE_2E2MU && final_state == Settings::fs2mu2e ) final_state = Settings::fs2e2mu;
   
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
