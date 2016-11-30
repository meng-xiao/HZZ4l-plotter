#include "Histograms.h"
#include "Variables.h"
#include "CMS_lumi.h"
#include <TROOT.h>
#include <sstream>

using namespace std;

// Constructor
//==========================================
Histograms::Histograms( string blinding)
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
   

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               _histo_name = _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + blinding;
               _histo_labels = ";" + Variables::M4lMain().var_X_label + ";" + Variables::M4lMain().var_Y_label;
                           
               M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMain().var_N_bin,
                                                           Variables::M4lMain().var_min, Variables::M4lMain().var_max);
            }
         }
      }
   }
   
   
   // Z+X
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         _histo_name = "ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + blinding;
         M4lMain_ZX[Settings::M4lMain][i_fs][i_cat] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);

         _histo_name = "ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + blinding;
         M4lMain_ZX_shape[Settings::M4lMain][i_fs][i_cat] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);
      }
   }
   
}
//==========================================



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

//   cout << fs << cat << rs << proc << endl;
   M4lMain[Settings::M4lMain][fs][cat][rs][proc]->Fill(M4l, (proc == Settings::Data) ? 1. : weight);

}
//====================================================================================



//====================================================================================
void Histograms::FillM4lZX( float M4l, float weight, int fs, int cat )
{
   M4lMain_ZX[Settings::M4lMain][fs][cat]->Fill(M4l, weight);
}
//====================================================================================



//====================================================================================
void Histograms::MakeZXShape( int current_final_state, int current_category, float lumi )
{
	M4lZX *ZXShape = new M4lZX();
    current_final_state = (current_final_state==3) ? 2 : current_final_state;
   M4lMain_ZX_shape[Settings::M4lMain][current_final_state][current_category]->Add(ZXShape->GetM4lZX(Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max, current_final_state, current_category, lumi));
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
            M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125VBF]);
            M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125NOVBF]);
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
               M4lMain[Settings::M4lMain][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
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
               M4lMain[Settings::M4lMain][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
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
               M4lMain[Settings::M4lMain][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
            }
         }
      }
   }


   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         M4lMain_ZX[Settings::M4lMain][num_of_final_states - 1][i_cat]->Add(M4lMain_ZX[Settings::M4lMain][i_fs][i_cat]);
      }
   }

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         M4lMain_ZX[Settings::M4lMain][i_fs][num_of_categories - 1]->Add(M4lMain_ZX[Settings::M4lMain][i_fs][i_cat]);
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
         integral = M4lMain_ZX[Settings::M4lMain][i_fs][i_cat]->Integral();
         M4lMain_ZX[Settings::M4lMain][i_fs][i_cat]->Smooth(1);
         M4lMain_ZX[Settings::M4lMain][i_fs][i_cat]->Scale( integral / M4lMain_ZX[Settings::M4lMain][i_fs][i_cat]->Integral() );
      }
   }
}
//=================================



//=================================
void Histograms::RenormalizeZX( )
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
         M4lMain_ZX[Settings::M4lMain][i_fs][i_cat]->Scale( norm_ZX_comb_SR[i_fs] / norm_ZX_full_SR[i_fs] );
      }
   }
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
         M4lMain_ZX[Settings::M4lMain][i_fs][i_cat]->Write();
         M4lMain_ZX_shape[Settings::M4lMain][i_fs][i_cat]->Write();
         delete M4lMain_ZX[Settings::M4lMain][i_fs][i_cat];
         delete M4lMain_ZX_shape[Settings::M4lMain][i_fs][i_cat];
      
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
//               if ( file_name == "Blinded_110_150_500_test.root" ) cout << i_fs << endl;
               M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]->Write();
               delete M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc];
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
               _histo_name = _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc);
            
               M4lMain[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
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
         M4lMain_ZX[Settings::M4lMain][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
      
			_histo_name = "ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat);
			M4lMain_ZX_shape[Settings::M4lMain][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
			
         M4lMain_ZX[Settings::M4lMain][i_fs][i_cat]->SetFillColor(kGreen + 2);
         M4lMain_ZX_shape[Settings::M4lMain][i_fs][i_cat]->SetFillColor(kGreen + 2);
      }
   }

}
//============================================



//============================================
void Histograms::Plot1D_single( TString filename, TString variable_name, TString folder, int fs, int cat )
{
   int plot_index = SetPlotName( variable_name);
   
   TCanvas *c = new TCanvas(variable_name, variable_name, 700, 700);
   
   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
   
   M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::H125]->SetFillColor(kRed+1);
   M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ]->SetFillColor(kAzure-9);
   M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ]->SetFillColor(kAzure);
   M4lMain_ZX_shape[plot_index][fs][cat]->SetFillColor(kGreen + 2);
   
   M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.7);
   M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(20);
   M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetBinErrorOption(TH1::kPoisson);
   M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetLineColor(kBlack);
   
   THStack *stack = new THStack( "stack", "stack" );
   stack->Add(M4lMain_ZX_shape[plot_index][fs][cat]);
   stack->Add(M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ]);
   stack->Add(M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ]);
   stack->Add(M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::H125]);
   
   stack->Draw("HIST");
   
   float data_max = M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetBinContent(M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
   float data_max_error = M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetBinErrorUp(M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      
   stack->SetMinimum(1e-5);      
   stack->SetMaximum((data_max + data_max_error)*1.1);
   
   stack->GetXaxis()->SetTitle(M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetXaxis()->GetTitle());
   stack->GetYaxis()->SetTitle(M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
   
   M4lMain[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->Draw("SAME p E1 X0");
      
   stringstream ss;
   ss << folder << "/" << variable_name << "_" << filename;

   c->SaveAs((ss.str() + ".pdf").c_str());
   c->SaveAs((ss.str() + ".png").c_str());
   c->SaveAs((ss.str() + ".jpeg").c_str());
   c->SaveAs((ss.str() + ".root").c_str());
   c->SaveAs((ss.str() + ".C").c_str());
   c->SaveAs((ss.str() + ".eps").c_str());

}
//============================================



//============================================
void Histograms::Plot1D_all( TString filename, TString variable_name , TString folder)
{
      
   int plot_index = SetPlotName( variable_name);
    
   TCanvas *c = new TCanvas(variable_name, variable_name, 700, 700);

   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
       
   for( int i_cat = 0; i_cat < num_of_categories; i_cat++)
   {  
      M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125]->SetFillColor(kRed+1);
      M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ]->SetFillColor(kAzure-9);
      M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ]->SetFillColor(kAzure);
      M4lMain_ZX_shape[plot_index][Settings::fs4l][i_cat]->SetFillColor(kGreen + 2);
      
      M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.7);
      M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(20);
      M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetBinErrorOption(TH1::kPoisson);
      M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetLineColor(kBlack);
      
      THStack *stack = new THStack( "stack", "stack" );
      stack->Add(M4lMain_ZX_shape[plot_index][Settings::fs4l][i_cat]);
      stack->Add(M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ]);
      stack->Add(M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ]);
      stack->Add(M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125]);
      
      stack->Draw("HIST");  
      
      float data_max = M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetBinContent(M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      float data_max_error = M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetBinErrorUp(M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      
      stack->SetMinimum(1e-15);      
      stack->SetMaximum((data_max + data_max_error)*1.1);
         
      stack->GetXaxis()->SetTitle(M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetXaxis()->GetTitle());
      stack->GetYaxis()->SetTitle(M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
      
      M4lMain[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->Draw("SAME p E1 X0");
      
      CMS_lumi *lumi = new CMS_lumi;
      lumi->set_lumi(c, 0, 0);
         
      stringstream ss;
      ss << folder << "/" << variable_name << "_" <<filename << "_" << i_cat;

      c->SaveAs((ss.str() + ".pdf").c_str());
      c->SaveAs((ss.str() + ".png").c_str());
      c->SaveAs((ss.str() + ".jpeg").c_str());
      c->SaveAs((ss.str() + ".root").c_str());
      c->SaveAs((ss.str() + ".C").c_str());
      c->SaveAs((ss.str() + ".eps").c_str());   
   }
}

//=================================
int Histograms::SetPlotName(TString variable_name)
{
   if(variable_name == "M4lMain")                return Settings::M4lMain;
   else if (variable_name == "M4lMainZoomed")    return Settings::M4lMainZoomed;
   else
   {
      cout << "[ERROR] Wrong variable name choosen! Setting it to M4lMain. Only possible implementations for now are: \n - M4lMain \n - M4lMainZoomed" << endl;
      abort;
      return Settings::M4lMain;
   }
}
//=================================


//=================================
bool Histograms::GetVarLogX ( TString variable_name)
{
   if(variable_name == "M4lMain")                return bool(Variables::M4lMain().var_log_x);
   else if (variable_name == "M4lMainZoomed")    return bool(Variables::M4lMainZoomed().var_log_x);
   else
   {
      cout << "[ERROR] Wrong variable name choosen! Setting it to M4lMain. Only possible implementations for now are: \n - M4lMain \n - M4lMainZoomed" << endl;
      abort;
      return bool(Variables::M4lMain().var_log_x);
   }
}
//=================================


//=================================

bool Histograms::GetVarLogY ( TString variable_name)
{
   if(variable_name == "M4lMain")                return bool(Variables::M4lMain().var_log_y);
   else if (variable_name == "M4lMainZoomed")    return bool(Variables::M4lMainZoomed().var_log_y);
   else
   {
      cout << "[ERROR] Wrong variable name choosen! Setting it to M4lMain. Only possible implementations for now are: \n - M4lMain \n - M4lMainZoomed" << endl;
      abort;
      return bool(Variables::M4lMain().var_log_y);
   }
}
//=================================



