#include "Histograms.h"
#include "Variables.h"
#include "CMS_lumi.h"
#include <TROOT.h>
#include <sstream>

using namespace std;

// Constructor
//======================================
Histograms::Histograms( string blinding)
{
   _blinding = blinding;
   
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
   

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               //=============
               // M4l
               //=============
               _histo_name = "M4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::M4lMain().var_X_label + ";" + Variables::M4lMain().var_Y_label;     
               histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);
               
               _histo_name = "M4l_zoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::M4lMainZoomed().var_X_label + ";" + Variables::M4lMainZoomed().var_Y_label;
               histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMainZoomed().var_N_bin, Variables::M4lMainZoomed().var_min, Variables::M4lMainZoomed().var_max);
               
               //=============
               // MZ1
               //=============
               _histo_name = "MZ1" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ1().var_X_label + ";" + Variables::MZ1().var_Y_label;
               histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ1().var_N_bin, Variables::MZ1().var_min, Variables::MZ1().var_max);
            }
         }
      }
   }
   
   
   // Z+X
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         //=============
         // M4l
         //=============
         _histo_name = "M4l_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::M4lMain][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);
         
         _histo_name = "M4l_zoomed_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMainZoomed().var_N_bin, Variables::M4lMainZoomed().var_min, Variables::M4lMainZoomed().var_max);

         _histo_name = "M4l_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);
         
         _histo_name = "M4l_zoomed_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMainZoomed][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMainZoomed().var_N_bin, Variables::M4lMainZoomed().var_min, Variables::M4lMainZoomed().var_max);
         
         //=============
         // MZ1
         //=============
         _histo_name = "MZ1_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ1][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::MZ1().var_N_bin, Variables::MZ1().var_min, Variables::MZ1().var_max);
      }
   }
}
//======================================



//=======================
Histograms::~Histograms()
{
  
/* 
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {                           
               delete M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc];
            }
         }
      }
   }
   
   // Z+X
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         delete M4lMain_ZX[Settings::M4lMain][i_fs][i_cat];
         delete M4lMain_ZX_shape[Settings::M4lMain][i_fs][i_cat];
      }
   }
*/
   
}
//=======================



//====================================================================================
void Histograms::FillM4l( float M4l, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::M4lMain][fs][cat][rs][proc]->Fill(M4l, (proc == Settings::Data) ? 1. : weight);
   histos_1D[Settings::M4lMainZoomed][fs][cat][rs][proc]->Fill(M4l, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================



//====================================================================
void Histograms::FillM4lZX( float M4l, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::M4lMain][fs][cat]->Fill(M4l, weight);
   histos_1D_ZX[Settings::M4lMainZoomed][fs][cat]->Fill(M4l, weight);
}
//====================================================================


//====================================================================================
void Histograms::FillMZ1( float MZ1, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::MZ1][fs][cat][rs][proc]->Fill(MZ1, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================



//====================================================================
void Histograms::FillMZ1ZX( float MZ1, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::MZ1][fs][cat]->Fill(MZ1, weight);
}
//====================================================================



//=======================================================================================
void Histograms::MakeZXShape( int current_final_state, int current_category, float lumi )
{
   M4lZX *ZXShape = new M4lZX();
   
   current_final_state = (current_final_state == 3) ? 2 : current_final_state;
   histos_1D_ZX_shape[Settings::M4lMain][current_final_state][current_category]->Add(ZXShape->GetM4lZX(Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max, current_final_state, current_category, lumi));
   
   ZXShape->~M4lZX();
   
   M4lZX *ZXShape_zoomed = new M4lZX();
   
   histos_1D_ZX_shape[Settings::M4lMainZoomed][current_final_state][current_category]->Add(ZXShape_zoomed->GetM4lZX(Variables::M4lMainZoomed().var_N_bin, Variables::M4lMainZoomed().var_min, Variables::M4lMainZoomed().var_max, current_final_state, current_category, lumi));
   
   ZXShape_zoomed->~M4lZX();
    
}
//=======================================================================================



//==============================
void Histograms::FillInclusive()
{

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            //=============
            // M4l
            //=============
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125NOVBF]);
            
            histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125NOVBF]);
            
            //=============
            // MZ1
            //=============
            histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125NOVBF]);
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
               //=============
               // M4l
               //=============
               histos_1D[Settings::M4lMain][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainZoomed][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1
               //=============
               histos_1D[Settings::MZ1][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]);
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
               //=============
               // M4l
               //=============
               histos_1D[Settings::M4lMain][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainZoomed][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1
               //=============
               histos_1D[Settings::MZ1][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]);
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
               //=============
               // M4l
               //=============
               histos_1D[Settings::M4lMain][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1
               //=============
               histos_1D[Settings::MZ1][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]);
            }
         }
      }
   }


   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         //=============
         // M4l
         //=============
         histos_1D_ZX[Settings::M4lMain][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]);
         histos_1D_ZX[Settings::M4lMainZoomed][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]);
         
         //=============
         // MZ1
         //=============
         histos_1D_ZX[Settings::MZ1][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::MZ1][i_fs][i_cat]);
      }
   }

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         //=============
         // M4l
         //=============
         histos_1D_ZX[Settings::M4lMain][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]);
         histos_1D_ZX[Settings::M4lMainZoomed][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]);
         
         //=============
         // MZ1
         //=============
         histos_1D_ZX[Settings::MZ1][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::MZ1][i_fs][i_cat]);
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
         //=============
         // M4l
         //=============
         integral = histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Integral();
         if(integral > 0.)
         {
            histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Integral();
         if(integral > 0.)
         {
            histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Integral() );
         }

         
         //=============
         // MZ1
         //=============
         integral = histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Integral();
         if(integral > 0.)
         {
            histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Integral() );
         }

      }
   }
}
//=================================



//==============================
void Histograms::RenormalizeZX()
{
   
   M4lZX *ZX = new M4lZX();
   
   float norm_ZX_full_SR[num_of_final_states];   
   norm_ZX_full_SR[Settings::fs4e]    = ZX->GetNormZXFullSR4e();
   norm_ZX_full_SR[Settings::fs4mu]   = ZX->GetNormZXFullSR4mu();
   norm_ZX_full_SR[Settings::fs2e2mu] = ZX->GetNormZXFullSR2e2mu();
   norm_ZX_full_SR[num_of_final_states - 1] = ZX->GetNormZXFullSR4e() + ZX->GetNormZXFullSR4mu() + ZX->GetNormZXFullSR2e2mu() ;
   
   ZX->SetNormalization(Settings::inclusive);
    
   float norm_ZX_comb_SR[num_of_final_states];
   norm_ZX_comb_SR[Settings::fs4e]    = ZX->GetNormZXFullSR4e();
   norm_ZX_comb_SR[Settings::fs4mu]   = ZX->GetNormZXFullSR4mu();
   norm_ZX_comb_SR[Settings::fs2e2mu] = ZX->GetNormZXFullSR2e2mu();
   norm_ZX_comb_SR[num_of_final_states - 1] = ZX->GetNormZXFullSR4e() + ZX->GetNormZXFullSR4mu() + ZX->GetNormZXFullSR2e2mu() ;
    
   for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
   {
      for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
      {
         if( i_fs == Settings::fs2mu2e) continue;
         //=============
         // M4l
         //=============
         histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Scale( norm_ZX_comb_SR[i_fs] / norm_ZX_full_SR[i_fs] );
         histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Scale( norm_ZX_comb_SR[i_fs] / norm_ZX_full_SR[i_fs] );
         
         //=============
         // MZ1
         //=============
         histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Scale( norm_ZX_comb_SR[i_fs] / norm_ZX_full_SR[i_fs] );
      }
   }
}
//==============================



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
         //=============
         // M4l
         //=============
         histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Write();
         histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Write();
         histos_1D_ZX_shape[Settings::M4lMainZoomed][i_fs][i_cat]->Write();
         
         delete histos_1D_ZX[Settings::M4lMain][i_fs][i_cat];
         delete histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat];
         delete histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat];
         delete histos_1D_ZX_shape[Settings::M4lMainZoomed][i_fs][i_cat];
         
         //=============
         // MZ1
         //=============
         histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Write();
         
         delete histos_1D_ZX[Settings::MZ1][i_fs][i_cat];
      
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               //=============
               // M4l
               //=============
               histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc]->Write();
                           
               delete histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc];
               
               //=============
               // MZ1
               //=============
               histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]->Write();
               
               delete histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc];
            }
         }
      }
   }
   
   cout << "[INFO] Closing ROOT file." << endl;
   
   fOutHistos->Close();
   delete fOutHistos;
}
//=============================================



//=============================================
void Histograms::GetHistos( TString file_name )
{

   cout << "[INFO] Getting histograms from ROOT file." << endl;
   
   TFile* histo_file = TFile::Open(file_name);

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               //=============
               // M4l
               //=============
               _histo_name = "M4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "M4l_zoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               //=============
               // MZ1
               //=============
               _histo_name = "MZ1" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
            }
         }
      }
   }
      
   // Z+X
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         //=============
         // M4l
         //=============
         _histo_name = "M4l_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::M4lMain][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
      
         _histo_name = "M4l_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "M4l_zoomed_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMainZoomed][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());

         
         //=============
         // MZ1
         //=============
         _histo_name = "MZ1_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ1][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
      }
   }
}
//=============================================



//========================================================================================================
void Histograms::Plot1D_single( TString filename, TString variable_name, TString folder, int fs, int cat )
{
   int plot_index = SetPlotName( variable_name);
   
   TCanvas *c = new TCanvas(variable_name, variable_name, 650, 500);
   
   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
   
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125]->SetFillColor(kRed-9);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ]->SetFillColor(kAzure-9);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ]->SetFillColor(kAzure+2);
   if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed") histos_1D_ZX_shape[plot_index][fs][cat]->SetFillColor(kTeal-6);
   else histos_1D_ZX[plot_index][fs][cat]->SetFillColor(kTeal-6);
   
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.7);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(20);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetBinErrorOption(TH1::kPoisson);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetLineColor(kBlack);
   
   THStack *stack = new THStack( "stack", "stack" );
   if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed") stack->Add(histos_1D_ZX_shape[plot_index][fs][cat]);
   else stack->Add(histos_1D_ZX[plot_index][fs][cat]);
   stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ]);
   stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ]);
   stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125]);
   
   stack->Draw("HIST");
   
   float data_max = histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetBinContent(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
   float data_max_error = histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetBinErrorUp(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      
   stack->SetMinimum(1e-5);      
   stack->SetMaximum((data_max + data_max_error)*1.1);
   
   stack->GetXaxis()->SetTitle(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetXaxis()->GetTitle());
   stack->GetYaxis()->SetTitle(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
   
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->Draw("SAME p E1 X0");
      
   stringstream ss;
   ss << folder << "/" << variable_name << "_" << filename;

   c->SaveAs((ss.str() + ".pdf").c_str());
   c->SaveAs((ss.str() + ".png").c_str());
   c->SaveAs((ss.str() + ".jpeg").c_str());
   c->SaveAs((ss.str() + ".root").c_str());
   c->SaveAs((ss.str() + ".C").c_str());
   c->SaveAs((ss.str() + ".eps").c_str());

}
//========================================================================================================



//=====================================================================================
void Histograms::Plot1D_all( TString filename, TString variable_name , TString folder )
{
   int plot_index = SetPlotName( variable_name);
    
   TCanvas *c = new TCanvas(variable_name, variable_name, 650, 500);

   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
       
   for( int i_cat = num_of_categories - 1; i_cat >= 0; i_cat--)
   {  
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125]->SetFillColor(1180);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ]->SetFillColor(851);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ]->SetFillColor(858);
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed") histos_1D_ZX_shape[plot_index][Settings::fs4l][i_cat]->SetFillColor(411);
      else histos_1D_ZX[plot_index][Settings::fs4l][i_cat]->SetFillColor(411);

      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125]->SetLineColor(633);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ]->SetLineColor(602);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ]->SetLineColor(602);
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed") histos_1D_ZX_shape[plot_index][Settings::fs4l][i_cat]->SetLineColor(420);
      else histos_1D_ZX[plot_index][Settings::fs4l][i_cat]->SetLineColor(420);
      
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.7);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(20);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetBinErrorOption(TH1::kPoisson);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetLineColor(kBlack);
      
      THStack *stack = new THStack( "stack", "stack" );
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed") stack->Add(histos_1D_ZX_shape[plot_index][Settings::fs4l][i_cat]);
      else stack->Add(histos_1D_ZX[plot_index][Settings::fs4l][i_cat]);
      stack->Add(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ]);
      stack->Add(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ]);
      stack->Add(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125]);
      
      stack->Draw("HIST");  

      float data_max = histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetBinContent(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      float data_max_error = histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetBinErrorUp(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      
      stack->SetMinimum(1e-15);      
      stack->SetMaximum((data_max + data_max_error)*1.1);

      stack->GetXaxis()->SetTitle(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetXaxis()->GetTitle());
      stack->GetYaxis()->SetTitle(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
      
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->Draw("SAME p E1 X0");

      TLegend *legend;
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed")
      {
        legend  = CreateLegend(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX_shape[plot_index][Settings::fs4l][i_cat]);
      }
      
      else
      {
         legend = CreateLegend(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][Settings::fs4l][i_cat]);
      }
      legend->Draw();
      
      // Draw lumi
      CMS_lumi *lumi = new CMS_lumi;
      lumi->set_lumi(c, 0, 0);
      
      // Draw X-axis log scale
      if ( plot_index == Settings::M4lMain )
      {
         stack->GetXaxis()->SetNdivisions(0);
         DrawLogX(c, i_cat);  
      }
      
      stringstream ss;
      ss << folder << "/" << variable_name << "_" <<filename << "_" << i_cat;
      cout << ss.str() << endl;
      c->SaveAs((ss.str() + ".pdf").c_str());
      c->SaveAs((ss.str() + ".png").c_str());
      c->SaveAs((ss.str() + ".jpeg").c_str());
      c->SaveAs((ss.str() + ".root").c_str());
      c->SaveAs((ss.str() + ".C").c_str());
      c->SaveAs((ss.str() + ".eps").c_str());
//      c->SaveAs("test.pdf");
   }
   delete c;
}
//=====================================================================================



//==================================================
int Histograms::SetPlotName( TString variable_name )
{
   //=============
   // M4l
   //=============
   if ( variable_name == "M4lMain" )            return Settings::M4lMain;
   else if ( variable_name == "M4lMainZoomed" ) return Settings::M4lMainZoomed;
   
   //=============
   // MZ1
   //=============
   else if ( variable_name == "MZ1" ) return Settings::MZ1;
   else
   {
      cout << "[ERROR] Wrong variable name choosen! Setting it to M4lMain. Only possible implementations for now are: \n - M4lMain \n - M4lMainZoomed" << endl;
      abort;
      return Settings::M4lMain;
   }
}
//==================================================



//===================================================
bool Histograms::GetVarLogX ( TString variable_name )
{
   //=============
   // M4l
   //=============
   if(variable_name == "M4lMain")                return bool(Variables::M4lMain().var_log_x);
   else if (variable_name == "M4lMainZoomed")    return bool(Variables::M4lMainZoomed().var_log_x);
   
   //=============
   // MZ1
   //=============
   else if (variable_name == "MZ1")    return bool(Variables::MZ1().var_log_x);
   else
   {
      cout << "[ERROR] Wrong variable name choosen! Setting it to M4lMain. Only possible implementations for now are: \n - M4lMain \n - M4lMainZoomed" << endl;
      abort;
      return bool(Variables::M4lMain().var_log_x);
   }
}
//===================================================



//===================================================
bool Histograms::GetVarLogY ( TString variable_name )
{
   //=============
   // M4l
   //=============
   if(variable_name == "M4lMain")                return bool(Variables::M4lMain().var_log_y);
   else if (variable_name == "M4lMainZoomed")    return bool(Variables::M4lMainZoomed().var_log_y);
   
   //=============
   // MZ1
   //=============
   else if (variable_name == "MZ1")    return bool(Variables::MZ1().var_log_y);
   else
   {
      cout << "[ERROR] Wrong variable name choosen! Setting it to M4lMain. Only possible implementations for now are: \n - M4lMain \n - M4lMainZoomed" << endl;
      abort;
      return bool(Variables::M4lMain().var_log_y);
   }
}
//===================================================



//========================================================================================
TLegend* Histograms::CreateLegend( TH1F *data, TH1F *h125,TH1F *qqZZ,TH1F *ggZZ,TH1F *ZX )
{
   TLegend *leg = new TLegend( .70, .72, .95, .9 );
   leg->SetFillColor(0);
   leg->SetBorderSize(0);
   
   leg->AddEntry( data, "Data", "p" );
   leg->AddEntry( h125,"H(125)","f");
   leg->AddEntry( qqZZ, "q#bar{q}#rightarrowZZ, Z#gamma*", "f" );
   leg->AddEntry( ggZZ, "gg#rightarrowZZ, Z#gamma*", "f" );
   leg->AddEntry( ZX, "Z+X", "f" );
   
   return leg;
}
//========================================================================================


//================================================
void Histograms::DrawLogX( TCanvas *c, int i_cat )
{
   int x_low = 100;
   int x_up  = 700;
   int step  = 100;
      
   float u_y_max = c->GetUymax();
   
   if ( i_cat == 6 ) _y_max = u_y_max;
   
   float factor = u_y_max/_y_max;
   float y_latex = -0.4;
       
   TLatex *latex_80 = new TLatex(80, y_latex*factor, "80");  
   latex_80->SetTextAlign(23);
   latex_80->SetTextFont (42);
   latex_80->SetTextSize (0.035);
   latex_80->Draw();
    
   TLatex *latex_800 = new TLatex(800, y_latex*factor, "800");  
   latex_800->SetTextAlign(23);
   latex_800->SetTextFont (42);
   latex_800->SetTextSize (0.035);
   latex_800->Draw();
    
   for ( int i = x_low; i < x_up; i += step )
   {
      float i_x = i;
      
      TLatex *latex = new TLatex(i, y_latex*factor, Form("%.0f", i_x));
      
      latex->SetTextAlign(23);
      latex->SetTextFont (42);
      latex->SetTextSize (0.035);
      latex->Draw();
   }
}
//================================================
