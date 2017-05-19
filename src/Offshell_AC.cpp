// Include classes
#include "Offshell_AC.h"

// Constructor
//=======================
Offshell_AC::Offshell_AC( double lumi ):Tree()
{
   Offshell_AC_histos = new Histograms( lumi , 0);
   histo_map["Offshell_AC"] = Offshell_AC_histos;

   _lumi = lumi;
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
   _fs_ROS_SS.push_back(0.97);//4e
   _fs_ROS_SS.push_back(1.22);//4mu
   _fs_ROS_SS.push_back(1.30);//2e2mu
   _fs_ROS_SS.push_back(0.98);//2mu2e
   
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
Offshell_AC::~Offshell_AC()
{
}
//====================



//=====================================================
void Offshell_AC::MakeHistograms( TString input_file_name )
{

   input_file = new TFile("./" + input_file_name);
   
   hCounters = (TH1F*)input_file->Get("ZZTree/Counters");
   n_gen_events = (Long64_t)hCounters->GetBinContent(1);
   gen_sum_weights = (Long64_t)hCounters->GetBinContent(40);
   
   input_tree = (TTree*)input_file->Get("ZZTree/candTree");
   Init( input_tree, input_file_name );
   
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

      _current_category = categoryAnomalousCouplings(nExtraLep,
                                                     nExtraZ,
                                                     nCleanedJetsPt30,
                                                     nCleanedJetsPt30BTagged_bTagSF,
                                                     p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal,
                                                     p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal,
                                                     p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal,
                                                     p_HadWH_SIG_ghw1_1_JHUGen_JECNominal,
                                                     p_HadZH_SIG_ghz1_1_JHUGen_JECNominal,
                                                     p_HadWH_SIG_ghw4_1_JHUGen_JECNominal,
                                                     p_HadZH_SIG_ghz4_1_JHUGen_JECNominal,
                                                     ZZMass);
      
      //cout << _current_category << endl;
      // K factors
      if ( APPLY_K_FACTORS ) _k_factor = calculate_K_factor(input_file_name);

      // Final event weight
      
      _event_weight = (_lumi * 1000 * xsec * _k_factor * overallEventWeight) / gen_sum_weights;
      
      // Fill discriminant histograms
      
      Offshell_AC_histos->FillACHistos(_current_category, _current_final_state, _current_process, ZZMass, _event_weight,
                                       p_GG_SIG_ghg2_1_ghz1_1_JHUGen, p_GG_SIG_ghg2_1_ghz4_1_JHUGen, p_GG_SIG_ghg2_1_ghz2_1_JHUGen, p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen,
                                       p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal, p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal, p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal, p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal,
                                       p_HadZH_SIG_ghz1_1_JHUGen_JECNominal, p_HadZH_SIG_ghz4_1_JHUGen_JECNominal, p_HadZH_SIG_ghz2_1_JHUGen_JECNominal, p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal,
                                       p_HadWH_SIG_ghw1_1_JHUGen_JECNominal, p_HadWH_SIG_ghw4_1_JHUGen_JECNominal, p_HadWH_SIG_ghw2_1_JHUGen_JECNominal, p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal);

   } // end for loop
   
   cout << "[INFO] Histograms for " << input_file_name << " filled." << endl;
}
//=====================================================



//===============================================================================
void Offshell_AC::Calculate_SS_ZX_Yields( TString input_file_data_name, TString  input_file_FR_name )
{
   
   FakeRates *FR = new FakeRates( input_file_FR_name );
   
   input_file_data = new TFile("./" + input_file_data_name);
   input_tree_data = (TTree*)input_file_data->Get("CRZLLTree/candTree");
   Init( input_tree_data, input_file_data_name );
   
   
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
      
      _current_category = categoryMor17(nExtraLep, nExtraZ, nCleanedJetsPt30, nCleanedJetsPt30BTagged_bTagSF, jetQGL,
                                        p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal, p_JQCD_SIG_ghg2_1_JHUGen_JECNominal, p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal,
                                        p_JVBF_SIG_ghv1_1_JHUGen_JECNominal, pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal, p_HadWH_SIG_ghw1_1_JHUGen_JECNominal,
                                        p_HadZH_SIG_ghz1_1_JHUGen_JECNominal, jetPhi, ZZMass, PFMET, true, false);
      
      
      // Calculate yield
      _yield_SR = _fs_ROS_SS.at(_current_final_state)*FR->GetFakeRate(LepPt->at(2),LepEta->at(2),LepLepId->at(2))*FR->GetFakeRate(LepPt->at(3),LepEta->at(3),LepLepId->at(3));
      
      _expected_yield_SR[_current_final_state][_current_category] += _yield_SR; // this number needs to be used when renormalizing histograms that have some cut/blinding
      _number_of_events_CR[_current_final_state][_current_category]++;
      
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
   cout << endl;
   cout << "========================================================================================" << endl;
   cout << "[INFO] Control printout." << endl << "!!! Numbers shoud be identical to yields from SS method !!!" << endl;
   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      if ( MERGE_2E2MU && i_fs == Settings::fs2mu2e) continue;
      cout << "Category: " << Settings::inclusive << "   Final state: " << i_fs << endl;
      cout << _expected_yield_SR[i_fs][Settings::inclusive] << " +/- " <<
      _expected_yield_SR[i_fs][Settings::inclusive]/sqrt(_number_of_events_CR[i_fs][Settings::inclusive]) << " (stat., evt: " <<
      _number_of_events_CR[i_fs][Settings::inclusive] << ")" << " +/- " << _expected_yield_SR[i_fs][Settings::inclusive]*0.50 << " (syst.)" << endl;
   }
   
   cout << "[INFO] Total = " << _expected_yield_SR[Settings::fs4l][Settings::inclusive] << endl;
   cout << "========================================================================================" << endl;
   cout << endl;
   
   cout << "[INFO] Z+X yields calculated using SS method." << endl;
}
//===============================================================================



//=========================================
void Offshell_AC::GetHistos( TString file_name )
{
   histo_map[file_name]->GetACHistos( file_name + ".root" );
   
   cout << "[INFO] Got all histograms." << endl;
}
//=========================================



//===========================
void Offshell_AC::FillInclusive()
{
   Offshell_AC_histos->FillInclusiveAC();
   
   cout << "[INFO] Summing of histograms finished." << endl;
}
//===========================



//==================
void Offshell_AC::Save()
{
   Offshell_AC_histos->ConditionalizeInM4L();
   Offshell_AC_histos->SaveACHistos("Offshell_AC.root");
   
   cout << "[INFO] All yield histograms are saved in a root file." << endl;
}
//==================



//==================
void Offshell_AC::Delete()
{
   Offshell_AC_histos->DeleteACHistos();
   
   cout << "[INFO] Memory clean-up done." << endl;
}
//==================

//==================
void Offshell_AC::Plot1D_AC( TString variable_name, TString folder )
{
   Offshell_AC_histos->Plot1D_AC( variable_name, folder );

}
//==================

//==================
void Offshell_AC::Plot2D_AC( TString variable_name, TString folder )
{
   Offshell_AC_histos->Plot2D_AC( variable_name, folder );
   
}
//==================


//==========================================================
int Offshell_AC::find_current_process( TString input_file_name )
{

   int current_process = -999;
   
   // Assign dataset to correct process
   if ( input_file_name.Contains("Data") )                             current_process = Settings::acData;
   else if ( input_file_name.Contains("ggH125") )                      current_process = Settings::acH125ggH;
   else if ( input_file_name.Contains("VBFH125") )                     current_process = Settings::acH125VBF;
   else if ( input_file_name.Contains("WplusH125") )                   current_process = Settings::acH125VH;
   else if ( input_file_name.Contains("WminusH125") )                  current_process = Settings::acH125VH;
   else if ( input_file_name.Contains("ZH125") )                       current_process = Settings::acH125VH;
   else if ( input_file_name.Contains("ttH125") )                      current_process = Settings::acH125ttH;
   
   else if ( input_file_name.Contains("ggTo4e_0MHH125_MCFM701") )       current_process = Settings::acH125_0MH;
   else if ( input_file_name.Contains("ggTo4mu_0MHH125_MCFM701") )      current_process = Settings::acH125_0MH;
   else if ( input_file_name.Contains("ggTo2e2mu_0MHH125_MCFM701") )    current_process = Settings::acH125_0MH;
   
   else if ( input_file_name.Contains("ggTo4e_0PHH125_MCFM701") )      current_process = Settings::acH125_0PH;
   else if ( input_file_name.Contains("ggTo4mu_0PHH125_MCFM701") )     current_process = Settings::acH125_0PH;
   else if ( input_file_name.Contains("ggTo2e2mu_0PHH125_MCFM701") )   current_process = Settings::acH125_0PH;

   else if ( input_file_name.Contains("ggTo4e_0PL1H125_MCFM701") )     current_process = Settings::acH125_0PL1;
   else if ( input_file_name.Contains("ggTo4mu_0PL1H125_MCFM701") )    current_process = Settings::acH125_0PL1;
   else if ( input_file_name.Contains("ggTo2e2mu_0PL1H125_MCFM701") )  current_process = Settings::acH125_0PL1;
   
   else if ( input_file_name.Contains("ggTo4e_0MHf05ph0H125_MCFM701") )       current_process = Settings::acH125_0MHf05;
   else if ( input_file_name.Contains("ggTo4mu_0MHf05ph0H125_MCFM701") )      current_process = Settings::acH125_0MHf05;
   else if ( input_file_name.Contains("ggTo2e2mu_0MHf05ph0H125_MCFM701") )    current_process = Settings::acH125_0MHf05;
   
   else if ( input_file_name.Contains("ggTo4e_0PHf05ph0H125_MCFM701") )      current_process = Settings::acH125_0PHf05;
   else if ( input_file_name.Contains("ggTo4mu_0PHf05ph0H125_MCFM701") )     current_process = Settings::acH125_0PHf05;
   else if ( input_file_name.Contains("ggTo2e2mu_0PHf05ph0H125_MCFM701") )   current_process = Settings::acH125_0PHf05;
   
   else if ( input_file_name.Contains("ggTo4e_0PL1f05ph0H125_MCFM701") )     current_process = Settings::acH125_0PL1f05;
   else if ( input_file_name.Contains("ggTo4mu_0PL1f05ph0H125_MCFM701") )    current_process = Settings::acH125_0PL1f05;
   else if ( input_file_name.Contains("ggTo2e2mu_0PL1f05ph0H125_MCFM701") )  current_process = Settings::acH125_0PL1f05;
   
   else if ( input_file_name.Contains("ZZTo4l") )                      current_process = Settings::acqqZZ;
   else if ( input_file_name.Contains("ggTo4e") )                      current_process = Settings::acggZZ;
   else if ( input_file_name.Contains("ggTo4mu") )                     current_process = Settings::acggZZ;
   else if ( input_file_name.Contains("ggTo4tau") )                    current_process = Settings::acggZZ;
   else if ( input_file_name.Contains("ggTo2e2mu") )                   current_process = Settings::acggZZ;
   else if ( input_file_name.Contains("ggTo2e2tau") )                  current_process = Settings::acggZZ;
   else if ( input_file_name.Contains("ggTo2mu2tau") )                 current_process = Settings::acggZZ;
   // End assign dataset to correct process

   return current_process;
}
//==========================================================



//=================================
float Offshell_AC::calculate_K_factor(TString input_file_name)
{

   float k_factor = 1;
   
   if ( input_file_name.Contains("ZZTo4l"))
   {
      k_factor = KFactor_EW_qqZZ * KFactor_QCD_qqZZ_M; // As of Moriond2016
   }
   else if ( input_file_name.Contains("ggTo") && !input_file_name.Contains("MCFM701"))
   {
      k_factor = KFactor_QCD_ggZZ_Nominal; // as of Moriond2016
   }
   return k_factor;
}
//=================================



//===========================
int Offshell_AC::FindFinalState()
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
int Offshell_AC::FindFinalStateZX()
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

