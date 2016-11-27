#include "Histograms.h"
#include "Variables.h"

using namespace std;

// Constructor
//==========================================
Histograms::Histograms()
{
   _s_process.push_back("Data");
   _s_process.push_back("H125");
   _s_process.push_back("H125VBF");
   _s_process.push_back("H125NOVBF");
   _s_process.push_back("qqZZ");
   _s_process.push_back("ggZZ");
   _s_process.push_back("DY");
   _s_process.push_back("ttbar");
   
   _s_final_state.push_back("4mu");
   _s_final_state.push_back("4e");
   _s_final_state.push_back("2e2mu");
   _s_final_state.push_back("2mu2e");
   _s_final_state.push_back("4l");
   
   _s_category.push_back("untagged");
   _s_category.push_back("VBF_1j_tagged");
   _s_category.push_back("VBF_2j_tagged");
   _s_category.push_back("VH_lepton_tagged");
   _s_category.push_back("VH_hadron_tagged");
   _s_category.push_back("ttH_tagged");
   _s_category.push_back("inclusive");
   
   _s_resonant_status.push_back("resonant");
   _s_resonant_status.push_back("nonresonant");
   _s_resonant_status.push_back("allres");


//   TH1F::SetDefaultSumw2(kTRUE);

//   cout << num_of_final_states << num_of_resonant_statuses << num_of_processes << endl;

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               _histo_name = _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc);
               _histo_labels = ";" + Variables::M4lV2().var_X_label + ";" + Variables::M4lV2().var_Y_label;
            
               M4lV2[i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lV2().var_N_bin,
                                                           Variables::M4lV2().var_min, Variables::M4lV2().var_max);
            }
         }
      }
   }
   
   
   // Z+X
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         _histo_name = "ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat);
         M4lV2_ZX[i_fs][i_cat] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lV2().var_N_bin, Variables::M4lV2().var_min, Variables::M4lV2().var_max);

         _histo_name = "ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat);
         M4lV2_ZX_shape[i_fs][i_cat] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lV2().var_N_bin, Variables::M4lV2().var_min, Variables::M4lV2().var_max);
      }
   }
   
}
//==========================================



//==========================
Histograms::~Histograms() {}
//==========================



//====================================================================================
void Histograms::FillM4l( float M4l, float weight, int fs, int cat, int rs, int proc )
{

//   cout << fs << cat << rs << proc << endl;
   M4lV2[fs][cat][rs][proc]->Fill(M4l, (proc == Settings::Data) ? 1. : weight);

}
//====================================================================================



//====================================================================================
void Histograms::FillM4lZX( float M4l, float weight, int fs, int cat )
{
   M4lV2_ZX[fs][cat]->Fill(M4l, weight);
}
//====================================================================================



//====================================================================================
void Histograms::MakeZXShape( int current_final_state, int current_category, float lumi )
{
	M4lZX *ZXShape = new M4lZX();
    current_final_state = (current_final_state==3) ? 2 : current_final_state;
   M4lV2_ZX_shape[current_final_state][current_category]->Add(ZXShape->GetM4lZX(Variables::M4lV2().var_N_bin, Variables::M4lV2().var_min, Variables::M4lV2().var_max, current_final_state, current_category, lumi));
    ZXShape->~M4lZX();
    
}
//====================================================================================



//==========================
void Histograms::FillOther()
{
}
//==========================



//==============================
void Histograms::FillInclusive()
{

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            M4lV2[i_fs][i_cat][i_rs][Settings::H125]->Add(M4lV2[i_fs][i_cat][i_rs][Settings::H125VBF]);
            M4lV2[i_fs][i_cat][i_rs][Settings::H125]->Add(M4lV2[i_fs][i_cat][i_rs][Settings::H125NOVBF]);
         }
      }
   }

   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses - 1; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               M4lV2[num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(M4lV2[i_fs][i_cat][i_rs][i_proc]);
            }
         }
      }
   }

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses - 1; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               M4lV2[i_fs][num_of_categories - 1][i_rs][i_proc]->Add(M4lV2[i_fs][i_cat][i_rs][i_proc]);
            }
         }
      }
   }

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses - 1; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               M4lV2[i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(M4lV2[i_fs][i_cat][i_rs][i_proc]);
            }
         }
      }
   }


   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         M4lV2_ZX[num_of_final_states - 1][i_cat]->Add(M4lV2_ZX[i_fs][i_cat]);
			//M4lV2_ZX_shape[num_of_final_states - 1][i_cat]->Add(M4lV2_ZX_shape[i_fs][i_cat]);
      }
   }

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         M4lV2_ZX[i_fs][num_of_categories - 1]->Add(M4lV2_ZX[i_fs][i_cat]);
			//M4lV2_ZX_shape[i_fs][num_of_categories - 1]->Add(M4lV2_ZX_shape[i_fs][i_cat]);
      }
   }

}
//==============================



//=================================
void Histograms::SmoothHistograms()
{
   float integral = 0;
   
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         integral = M4lV2_ZX[i_fs][i_cat]->Integral();
         M4lV2_ZX[i_fs][i_cat]->Smooth(1);
         M4lV2_ZX[i_fs][i_cat]->Scale( integral / M4lV2_ZX[i_fs][i_cat]->Integral() );
      }
   }
}
//=================================



//=================================
void Histograms::RenormalizeZX( vector<float> expected_yield_SR )
{
   
   M4lZX *ZX = new M4lZX();
   
   float norm_ZX_full_SR[num_of_final_states];
   
   norm_ZX_full_SR[Settings::fs4e] = ZX->GetNormZXFullSR4e();
   norm_ZX_full_SR[Settings::fs4mu] = ZX->GetNormZXFullSR4mu();
   norm_ZX_full_SR[Settings::fs2e2mu] = ZX->GetNormZXFullSR2e2mu();
   
   norm_ZX_full_SR[num_of_final_states - 1] = ZX->GetNormZXFullSR4e() + ZX->GetNormZXFullSR4mu() + ZX->GetNormZXFullSR2e2mu() ;
   
   expected_yield_SR.at(Settings::fs2e2mu) += expected_yield_SR.at(Settings::fs2mu2e); // MERGE2E2MU imposed
   
   for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
   {
      for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
      {
         if ( i_fs == Settings::fs2mu2e) continue;
         M4lV2_ZX[i_fs][i_cat]->Scale( norm_ZX_full_SR[i_fs] / expected_yield_SR.at(i_fs) );
      }
   }

   delete ZX;

}
//=================================



//=============================================
void Histograms::SaveHistos( string file_name )
{

   cout << "[INFO] Saving histograms to ROOT file." << endl;
   
   TFile* fOutHistos = new TFile(file_name.c_str(), "recreate");
   fOutHistos->cd();
   
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         M4lV2_ZX[i_fs][i_cat]->Write();
			M4lV2_ZX_shape[i_fs][i_cat]->Write();
         delete M4lV2_ZX[i_fs][i_cat];
			delete M4lV2_ZX_shape[i_fs][i_cat];
      
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
//               if ( file_name == "Blinded_110_150_500_test.root" ) cout << i_fs << endl;
               M4lV2[i_fs][i_cat][i_rs][i_proc]->Write();
               delete M4lV2[i_fs][i_cat][i_rs][i_proc];
            }
         }
      }
   }
   
   cout << "[INFO] Closing ROOT file." << endl;
   
   fOutHistos->Close();
   delete fOutHistos;

}
//=============================================



//============================================
void Histograms::GetHistos( string file_name )
{

   cout << "[INFO] Getting histograms from ROOT file." << endl;
   
   TFile* histo_file = TFile::Open(file_name.c_str());

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               _histo_name = _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc);
            
               M4lV2[i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
            }
         }
      }
   }
   
//   TCanvas *c1 = new TCanvas();
//   M4lV2[num_of_final_states - 1][num_of_categories - 1][num_of_resonant_statuses - 1][1]->Draw();
//   c1->SaveAs("Test.pdf");
      
   // Z+X
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         _histo_name = "ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat);
         M4lV2_ZX[i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
      
			_histo_name = "ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat);
			M4lV2_ZX_shape[i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
			
         M4lV2_ZX[i_fs][i_cat]->SetFillColor(kGreen + 2);
			M4lV2_ZX_shape[i_fs][i_cat]->SetFillColor(kGreen + 2);
      }
   }

}
//============================================



//============================================
void Histograms::Plot1D( string variable_name, int fs, int cat )
{
   
   TCanvas *c = new TCanvas(variable_name.c_str(), variable_name.c_str(), 500, 500);
   
   if ( Variables::M4lV2().var_log_x ) c->SetLogx(); // Generalize
   if ( Variables::M4lV2().var_log_y ) c->SetLogy(); // Generalize
   
   M4lV2[fs][cat][Settings::all_resonant][Settings::H125]->SetFillColor(kRed+1);
   M4lV2[fs][cat][Settings::all_resonant][Settings::qqZZ]->SetFillColor(kAzure-9);
   M4lV2[fs][cat][Settings::all_resonant][Settings::ggZZ]->SetFillColor(kAzure);
   M4lV2_ZX_shape[fs][cat]->SetFillColor(kGreen + 2);
   
   THStack *stack = new THStack( "stack", "stack" );
   stack->Add(M4lV2_ZX_shape[fs][cat]);
   stack->Add(M4lV2[fs][cat][Settings::all_resonant][Settings::ggZZ]);
   stack->Add(M4lV2[fs][cat][Settings::all_resonant][Settings::qqZZ]);
   stack->Add(M4lV2[fs][cat][Settings::all_resonant][Settings::H125]);
   
   stack->Draw("HIST");
   stack->SetMinimum(0);
   stack->SetMaximum(2);
	
   M4lV2[fs][cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.7);
   M4lV2[fs][cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(20);
   M4lV2[fs][cat][Settings::all_resonant][Settings::Data]->SetBinErrorOption(TH1::kPoisson);

   M4lV2[fs][cat][Settings::all_resonant][Settings::Data]->Draw("SAMEpE");

   c->SaveAs("Test.pdf");
}
