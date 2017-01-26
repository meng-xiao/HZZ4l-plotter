// Include classes
#include "Plotter.h"

// Constructor
//============================================================
Plotter::Plotter(bool yields):Tree()
{
   if (yields)
   {
      yields_histos = new Histograms();
      histo_map["Yields"] = yields_histos;
   }
   else
   {
      unblinded_histos = new Histograms("Unblinded");
      blinded_histos = new Histograms("Blinded");
      histo_map["Unblinded"] = unblinded_histos;
      histo_map["Blinded"] = blinded_histos;
   }
      
   _lumi = 36.8;
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
   // FIXME: recompute this for Run II, OS/SS ratio taken when computing fake rates in SS method
   _fs_ROS_SS.push_back(1.22);
   _fs_ROS_SS.push_back(0.97);
   _fs_ROS_SS.push_back(1.30);
   _fs_ROS_SS.push_back(0.98);
   
   vector<float> temp;
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         temp.push_back(0);
      }
      _expected_yield_SR.push_back(temp);
      _number_of_events_CR.push_back(temp);
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
      if ( (_current_process == Settings::Data && !blind(ZZMass)) || _current_process != Settings::Data )
       {
           blinded_histos->FillM4l( ZZMass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
           
       }
       
       unblinded_histos->FillM4l( ZZMass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
      // Fill MZ1 histograms
      if ( !blind(ZZMass) )
      {
         blinded_histos->FillMZ1( ZZMass, Z1Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      }
      
      unblinded_histos->FillMZ1( ZZMass, Z1Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
      // Fill MZ2 histograms
      if ( !blind(ZZMass) )
      {
         blinded_histos->FillMZ2( ZZMass, Z2Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      }
      
      unblinded_histos->FillMZ2( ZZMass, Z2Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
      // Fill KD histograms
      if ( blind(ZZMass) )
      {
         blinded_histos->FillKD( ZZMass, KD, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
         if(nCleanedJetsPt30==1) blinded_histos->FillD1jet( ZZMass, D1jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
         if(nCleanedJetsPt30>=2) blinded_histos->FillD2jet( ZZMass, D2jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
         if(nCleanedJetsPt30>=2) blinded_histos->FillDWH( ZZMass, DWH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
         if(nCleanedJetsPt30>=2) blinded_histos->FillDZH( ZZMass, DZH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      }
      
      unblinded_histos->FillKD( ZZMass, KD, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30==1) unblinded_histos->FillD1jet( ZZMass, D1jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30>=2) unblinded_histos->FillD2jet( ZZMass, D2jet, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30>=2) unblinded_histos->FillDWH( ZZMass, DWH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      if(nCleanedJetsPt30>=2) unblinded_histos->FillDZH( ZZMass, DZH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
      // Fill MZ1vsMZ2 histograms
      if ( !blind(ZZMass) )
      {
         blinded_histos->FillMZ1vsMZ2( ZZMass, Z1Mass, Z2Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      }
      
      unblinded_histos->FillMZ1vsMZ2( ZZMass, Z1Mass, Z2Mass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
      // Fill 2D histograms vs M4l with error
      if ( !blind(ZZMass) || _current_process != Settings::Data )
      {
         if(_current_process == Settings::Data) blinded_histos->FillVectors( ZZMass, ZZMassErrCorr, KD, nCleanedJetsPt30, D1jet, D2jet, DWH, DZH, _current_final_state, _current_category);
         blinded_histos->FillDvsM4l( ZZMass, KD, nCleanedJetsPt30, D1jet, D2jet, DWH, DZH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      }
      
      if(_current_process == Settings::Data) unblinded_histos->FillVectors( ZZMass, ZZMassErrCorr, KD, nCleanedJetsPt30, D1jet, D2jet, DWH, DZH, _current_final_state, _current_category );
      unblinded_histos->FillDvsM4l( ZZMass, KD, nCleanedJetsPt30, D1jet, D2jet, DWH, DZH, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
      
   } // end for loop
   
   cout << "[INFO] Histograms for " << input_file_name << " filled." << endl;
}
//=====================================================



//=====================================================
void Plotter::MakeYieldsHistograms( TString input_file_name )
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
      _current_process = find_current_process_yields( input_file_name );
      
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
   
   
      // Fill M4l histograms
       yields_histos->FillYields( ZZMass, _event_weight, _current_final_state, _current_category, _current_resonant_status, _current_process );
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
            blinded_histos->MakeZXShape( i_fs, i_cat);
            unblinded_histos->MakeZXShape( i_fs, i_cat);
        }
    }
   cout << "[INFO] Z+X shape for M4l done." << endl;
}
//=======================



//=======================
void Plotter::MakeYieldsM4lZX()
{
    for (int i_fs = 0; i_fs < num_of_final_states; i_fs++)
    {
        for(int i_cat = 0; i_cat < num_of_categories; i_cat++)
        {
            yields_histos->MakeZXShapeYields( i_fs, i_cat );
        }
    }
   cout << "[INFO] Z+X shape for M4l done." << endl;
}
//=======================


//===================================================================
void Plotter::SetBlinding(float blinding_lower, float blinding_upper)
{
   _blinding_lower[0] = blinding_lower;
   _blinding_upper[0] = blinding_upper;
   _blinding_lower[1] = 0.;
   _blinding_upper[1] = 0.;
}
//===================================================================

//===================================================================
void Plotter::SetBlinding(float blinding_lower_0, float blinding_upper_0, float blinding_lower_1, float blinding_upper_1)
{
   _blinding_lower[0] = blinding_lower_0;
   _blinding_upper[0] = blinding_upper_0;
   _blinding_lower[1] = blinding_lower_1;
   _blinding_upper[1] = blinding_upper_1;
}
//===================================================================



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
      
      _expected_yield_SR[_current_final_state][_current_category] += _yield_SR; // this number needs to be used when renormalizing histograms that have some cut/blinding
      _number_of_events_CR[_current_final_state][_current_category]++;
      
      if ( MERGE_2E2MU && _current_final_state == Settings::fs2mu2e ) _current_final_state = Settings::fs2e2mu; //We can only do this after _yield_SR is calculated
      
      // Calculate kinematic discriminants
      KD = p0plus_VAJHU / ( p0plus_VAJHU + bkg_VAMCFM*getDbkgkinConstant(Z1Flav*Z2Flav,ZZMass) );
      D2jet = (nCleanedJetsPt30>=2) ? pvbf_VAJHU_highestPTJets / ( pvbf_VAJHU_highestPTJets + phjj_VAJHU_highestPTJets*getDVBF2jetsConstant(ZZMass) ) : -2 ;
      D1jet = (nCleanedJetsPt30==1) ? pvbf_VAJHU_highestPTJets*pAux_vbf_VAJHU / ( pvbf_VAJHU_highestPTJets*pAux_vbf_VAJHU + phj_VAJHU*getDVBF1jetConstant(ZZMass) ) : -2 ;
      DWH = (nCleanedJetsPt30>=2) ? pwh_hadronic_VAJHU / ( pwh_hadronic_VAJHU + CUSTOMCCONSTWH*1e5*phjj_VAJHU_highestPTJets ) : -2 ;
      DZH = (nCleanedJetsPt30>=2) ? pzh_hadronic_VAJHU / ( pzh_hadronic_VAJHU + CUSTOMCCONSTZH*1e4*phjj_VAJHU_highestPTJets ) : -2 ;
   
      // Fill m4l Z+X histograms
      unblinded_histos->FillM4lZX( ZZMass, _yield_SR, _current_final_state, _current_category );
      blinded_histos->FillM4lZX( ZZMass, _yield_SR, _current_final_state, _current_category);
      
      // Fill mZ1 Z+X histograms
      unblinded_histos->FillMZ1ZX( ZZMass, Z1Mass, _yield_SR, _current_final_state, _current_category );
      
      if ( !blind(ZZMass))
      {
         blinded_histos->FillMZ1ZX( ZZMass, Z1Mass, _yield_SR, _current_final_state, _current_category);
      }
      
      // Fill mZ2 Z+X histograms
      unblinded_histos->FillMZ2ZX( ZZMass, Z2Mass, _yield_SR, _current_final_state, _current_category );
      
      if ( !blind(ZZMass))
      {
         blinded_histos->FillMZ2ZX( ZZMass, Z2Mass, _yield_SR, _current_final_state, _current_category);
      }
      
      // Fill KD Z+X histograms
      unblinded_histos->FillKDZX( ZZMass, KD, _yield_SR, _current_final_state, _current_category );
      
      if(nCleanedJetsPt30 == 1) unblinded_histos->FillD1jetZX( ZZMass, D1jet, _yield_SR, _current_final_state, _current_category );
      if(nCleanedJetsPt30 >= 2) unblinded_histos->FillD2jetZX( ZZMass, D2jet, _yield_SR, _current_final_state, _current_category );
      if(nCleanedJetsPt30 >= 2) unblinded_histos->FillDWHZX( ZZMass, DWH, _yield_SR, _current_final_state, _current_category );
      if(nCleanedJetsPt30 >= 2) unblinded_histos->FillDZHZX( ZZMass, DZH, _yield_SR, _current_final_state, _current_category );
      
      if ( !blind(ZZMass) )
      {
         blinded_histos->FillKDZX( ZZMass, KD, _yield_SR, _current_final_state, _current_category);
         if(nCleanedJetsPt30 == 1) blinded_histos->FillD1jetZX( ZZMass, D1jet, _yield_SR, _current_final_state, _current_category);
         if(nCleanedJetsPt30 >= 2) blinded_histos->FillD2jetZX( ZZMass, D2jet, _yield_SR, _current_final_state, _current_category);
         if(nCleanedJetsPt30 >= 2) blinded_histos->FillDWHZX( ZZMass, DWH, _yield_SR, _current_final_state, _current_category);
         if(nCleanedJetsPt30 >= 2) blinded_histos->FillDZHZX( ZZMass, DZH, _yield_SR, _current_final_state, _current_category);
      }

   
   } // END events loop
   
   for (  int i_cat = 0; i_cat < num_of_categories - 1; i_cat++  )
   {
      for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++  )
      {
         _expected_yield_SR[Settings::fs4l][i_cat]       += _expected_yield_SR[i_fs][i_cat];   //calculate expected yield for inclusive 4l final state
         _number_of_events_CR[Settings::fs4l][i_cat]     += _number_of_events_CR[i_fs][i_cat];
         _expected_yield_SR[i_fs][Settings::inclusive]   += _expected_yield_SR[i_fs][i_cat];   //calculate expected yield for inclusive category
         _number_of_events_CR[i_fs][Settings::inclusive] += _number_of_events_CR[i_fs][i_cat];
         
         if ( MERGE_2E2MU )
         {
            _expected_yield_SR[Settings::fs2e2mu][i_cat]       += _expected_yield_SR[Settings::fs2mu2e][i_cat];   //merge 2e2mu and 2mu2e final state
            _number_of_events_CR[Settings::fs2e2mu][i_cat]     += _number_of_events_CR[Settings::fs2mu2e][i_cat];
            _expected_yield_SR[Settings::fs2mu2e][i_cat]        = 0.;
            _number_of_events_CR[Settings::fs2mu2e][i_cat]      = 0.;
         }
         
      }
   }
   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++  )
   {
      _expected_yield_SR[Settings::fs4l][Settings::inclusive] += _expected_yield_SR[i_fs][Settings::inclusive];
   }
  
   // Print Z + X expected yields for inclusive category
   cout << "[INFO] Control printout (numbers shoud be similar to yields from SS method)." << endl;
   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      if ( MERGE_2E2MU && i_fs == Settings::fs2mu2e) continue;
      cout << "Category: " << Settings::inclusive << "   Final state: " << i_fs << endl;
      cout << _expected_yield_SR[i_fs][Settings::inclusive] << " +/- " <<
      _expected_yield_SR[i_fs][Settings::inclusive]/sqrt(_number_of_events_CR[i_fs][Settings::inclusive]) << " (stat., evt: " <<
      _number_of_events_CR[i_fs][Settings::inclusive] << ")" << " +/- " << _expected_yield_SR[i_fs][Settings::inclusive]*0.50 << " (syst.)" << endl;
   }
  
   cout << "[INFO] Total = " << _expected_yield_SR[Settings::fs4l][Settings::inclusive] << endl;
  
   // Smooth histograms
   if ( SMOOTH_ZX_FULL_RUN2_SS )
   {
      cout << "[INFO] Smoothing Z+X histograms..." << endl;
      blinded_histos->SmoothHistograms();
      unblinded_histos->SmoothHistograms();
   }
    
   unblinded_histos->RenormalizeZX( _expected_yield_SR );
   blinded_histos->RenormalizeZX( _expected_yield_SR );
   
   cout << "[INFO] Z+X histograms filled." << endl;
}
//===============================================================================



//=========================================
void Plotter::GetHistos( TString file_name )
{
   histo_map[file_name]->GetHistos( file_name + ".root" );
   
   cout << "[INFO] Got all histograms." << endl;
}
//=========================================



//=========================================
void Plotter::GetYieldsHistos( TString file_name )
{
   histo_map[file_name]->GetYieldsHistos( file_name + ".root" );
   
   cout << "[INFO] Got all histograms." << endl;
}
//=========================================



//===========================
void Plotter::FillInclusive()
{
   unblinded_histos->FillInclusive();
   blinded_histos->FillInclusive();
   
   cout << "[INFO] Summing of histograms finished." << endl;
}
//===========================



//===========================
void Plotter::FillInclusiveYields()
{
   yields_histos->FillInclusiveYields();
}
//===========================



//==================
void Plotter::Save()
{
   unblinded_histos->SaveHistos("Unblinded.root");
   blinded_histos->SaveHistos("Blinded.root");
   
   cout << "[INFO] All histograms are saved in a root file." << endl;
}
//==================



//==================
void Plotter::SaveYields()
{
   yields_histos->SaveYieldHistos("Yields.root");
   
   cout << "[INFO] All yield histograms are saved in a root file." << endl;
}
//==================



//==================
void Plotter::Delete()
{
   unblinded_histos->DeleteHistos();
   blinded_histos->DeleteHistos();
   
   cout << "[INFO] Memory clean-up done." << endl;
}
//==================



//==================
void Plotter::DeleteYields()
{
   yields_histos->DeleteYieldsHistos();
   
   cout << "[INFO] Memory clean-up done." << endl;
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



//==================
void Plotter::Plot2D_single( TString file_name, TString variable_name, TString folder, int cat )
{
   histo_map[file_name]->Plot2D_single( file_name, variable_name, folder, cat );
   
}
//==================



//==================
void Plotter::Plot2DError_single( TString file_name, TString variable_name, TString folder, int cat )
{
   histo_map[file_name]->Plot2DError_single( file_name, variable_name, folder, cat );
   
}
//==================

//==================
void Plotter::PrintYields( TString file_name )
{
   histo_map[file_name]->PrintYields( );
   
}
//==================

//==================
void Plotter::PrintYields( TString file_name, float M4l_down, float M4l_up  )
{
   histo_map[file_name]->PrintYields( M4l_down, M4l_up);
   
}
//==================

//==========================================================
int Plotter::find_current_process( TString input_file_name )
{
   
   int current_process = -999;
   
   // Assign dataset to correct process
   if ( input_file_name.Contains("Data") )           current_process = Settings::Data;
   if ( input_file_name.Contains("ggH125") )         current_process = Settings::H125other;
   if ( input_file_name.Contains("VBFH125") )        current_process = Settings::H125VBF;
   if ( input_file_name.Contains("WplusH125") )      current_process = Settings::H125VH;
   if ( input_file_name.Contains("WminusH125") )     current_process = Settings::H125VH;
   if ( input_file_name.Contains("ZH125") )          current_process = Settings::H125VH;
   if ( input_file_name.Contains("ttH125") )         current_process = Settings::H125other;
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


//==========================================================
int Plotter::find_current_process_yields( TString input_file_name )
{

   int current_process = -999;
   
   // Assign dataset to correct process
   if ( input_file_name.Contains("Data") )           current_process = Settings::yData;
   
   if ( input_file_name.Contains("ggH120") )         current_process = Settings::yH120other;
   if ( input_file_name.Contains("ggH124") )         current_process = Settings::yH124other;
   if ( input_file_name.Contains("ggH125") )         current_process = Settings::yH125other;
   if ( input_file_name.Contains("ggH126") )         current_process = Settings::yH126other;
   if ( input_file_name.Contains("ggH130") )         current_process = Settings::yH130other;
   
   if ( input_file_name.Contains("VBFH120") )        current_process = Settings::yH120VBF;
   if ( input_file_name.Contains("VBFH124") )        current_process = Settings::yH124VBF;
   if ( input_file_name.Contains("VBFH125") )        current_process = Settings::yH125VBF;
   if ( input_file_name.Contains("VBFH126") )        current_process = Settings::yH126VBF;
   if ( input_file_name.Contains("VBFH130") )        current_process = Settings::yH130VBF;
   
   if ( input_file_name.Contains("WplusH120") )      current_process = Settings::yH120VH;
   if ( input_file_name.Contains("WplusH124") )      current_process = Settings::yH124VH;
   if ( input_file_name.Contains("WplusH125") )      current_process = Settings::yH125VH;
   if ( input_file_name.Contains("WplusH126") )      current_process = Settings::yH126VH;
   if ( input_file_name.Contains("WplusH130") )      current_process = Settings::yH130VH;
   
   if ( input_file_name.Contains("WminusH120") )     current_process = Settings::yH120VH;
   if ( input_file_name.Contains("WminusH124") )     current_process = Settings::yH124VH;
   if ( input_file_name.Contains("WminusH125") )     current_process = Settings::yH125VH;
   if ( input_file_name.Contains("WminusH126") )     current_process = Settings::yH126VH;
   if ( input_file_name.Contains("WminusH130") )     current_process = Settings::yH130VH;
      
   if ( input_file_name.Contains("ZH120") )          current_process = Settings::yH120VH;
   if ( input_file_name.Contains("ZH124") )          current_process = Settings::yH124VH;
   if ( input_file_name.Contains("ZH125") )          current_process = Settings::yH125VH;
   if ( input_file_name.Contains("ZH126") )          current_process = Settings::yH126VH;
   if ( input_file_name.Contains("ZH130") )          current_process = Settings::yH130VH;
   
   if ( input_file_name.Contains("ttH120") )         current_process = Settings::yH120other;
   if ( input_file_name.Contains("ttH124") )         current_process = Settings::yH124other;
   if ( input_file_name.Contains("ttH125") )         current_process = Settings::yH125other;
   if ( input_file_name.Contains("ttH126") )         current_process = Settings::yH126other;
   if ( input_file_name.Contains("ttH130") )         current_process = Settings::yH130other;
      
   if ( input_file_name.Contains("ZZTo4l") )         current_process = Settings::yqqZZ;
   if ( input_file_name.Contains("ggTo4e") )         current_process = Settings::yggZZ;
   if ( input_file_name.Contains("ggTo4mu") )        current_process = Settings::yggZZ;
   if ( input_file_name.Contains("ggTo4tau") )       current_process = Settings::yggZZ;
   if ( input_file_name.Contains("ggTo2e2mu") )      current_process = Settings::yggZZ;
   if ( input_file_name.Contains("ggTo2e2tau") )     current_process = Settings::yggZZ;
   if ( input_file_name.Contains("ggTo2mu2tau") )    current_process = Settings::yggZZ;
   if ( input_file_name.Contains("DYJetsToLL_M50") ) current_process = Settings::yDY;
   if ( input_file_name.Contains("TTJets") )         current_process = Settings::yttbar;
   if ( input_file_name.Contains("TTTo2L2Nu") )      current_process = Settings::yttbar;
   // End assign dataset to correct process

   return current_process;
}
//==========================================================



//=================================
float Plotter::calculate_K_factor()
{

   float k_factor = 1;
   
   if ( _current_process == Settings::qqZZ || _current_process == Settings::yqqZZ)
   {
      k_factor = KFactor_EW_qqZZ * KFactor_QCD_qqZZ_M; // As of Moriond2016
   }
   else if ( _current_process == Settings::ggZZ || _current_process == Settings::yggZZ)
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

//=================================
bool Plotter::blind( float ZZMass)
{
   if( ((ZZMass < _blinding_lower[0]) || (ZZMass > _blinding_upper[0])) && ((ZZMass < _blinding_lower[1]) || (ZZMass > _blinding_upper[1]))) return false;
   else return true;
   
}
//=================================
