#include "Histograms.h"
#include "Variables.h"
#include "CMS_lumi.h"
#include <TROOT.h>
#include <sstream>

using namespace std;

// Constructor
//======================================
Histograms::Histograms( double lumi, string blinding )
{
   _lumi = lumi;
   _blinding = blinding;
   
   _s_process.push_back("Data");
   _s_process.push_back("H125");
   _s_process.push_back("H125VBF");
   _s_process.push_back("H125VH");
   _s_process.push_back("H125other");
   _s_process.push_back("qqZZ");
   _s_process.push_back("ggZZ");
   _s_process.push_back("DY");
   _s_process.push_back("ttbar");
   
   _s_final_state.push_back("4e");
   _s_final_state.push_back("4mu");
   _s_final_state.push_back("2e2mu");
   _s_final_state.push_back("2mu2e");
   _s_final_state.push_back("4l");
   
   _s_category.push_back("UnTagged");
   _s_category.push_back("VBF1jTagged");
   _s_category.push_back("VBF2jTagged");
   _s_category.push_back("VHLeptTagged");
   _s_category.push_back("VHHadrTagged");
   _s_category.push_back("ttHTagged");
   _s_category.push_back("VHMETTagged");
   _s_category.push_back("Inclusive");
   
   _s_category_label.push_back("Untagged category");
   _s_category_label.push_back("VBF-1j tagged category");
   _s_category_label.push_back("VBF-2j tagged category");
   _s_category_label.push_back("VH-leptonic tagged category");
   _s_category_label.push_back("VH-hadronic tagged category");
   _s_category_label.push_back("ttH tagged category");
   _s_category_label.push_back("VH-MET tagged category");
   _s_category_label.push_back("Inclusive category");
   
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
               //=====
               // M4l
               //=====
               _histo_name = "M4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::M4lMain().var_X_label + ";" + Variables::M4lMain().var_Y_label;     
               histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);
               
               _histo_name = "M4l_zoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::M4lMainZoomed().var_X_label + ";" + Variables::M4lMainZoomed().var_Y_label;
               histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMainZoomed().var_N_bin, Variables::M4lMainZoomed().var_min, Variables::M4lMainZoomed().var_max);
               
               _histo_name = "M4l_HighMass" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::M4lMainHighMass().var_X_label + ";" + Variables::M4lMainHighMass().var_Y_label;
               histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMainHighMass().var_N_bin, Variables::M4lMainHighMass().var_min, Variables::M4lMainHighMass().var_max);

               //=====
               // MZ1
               //=====
               _histo_name = "MZ1" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ1().var_X_label + ";" + Variables::MZ1().var_Y_label;
               histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ1().var_N_bin, Variables::MZ1().var_min, Variables::MZ1().var_max);
               
               _histo_name = "MZ1_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ1_M4L118130().var_X_label + ";" + Variables::MZ1_M4L118130().var_Y_label;
               histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ1_M4L118130().var_N_bin, Variables::MZ1_M4L118130().var_min, Variables::MZ1_M4L118130().var_max);
               
               //=====
               // MZ2
               //=====
               _histo_name = "MZ2" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ2().var_X_label + ";" + Variables::MZ2().var_Y_label;
               histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ2().var_N_bin, Variables::MZ2().var_min, Variables::MZ2().var_max);
               
               _histo_name = "MZ2_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ2_M4L118130().var_X_label + ";" + Variables::MZ2_M4L118130().var_Y_label;
               histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ2_M4L118130().var_N_bin, Variables::MZ2_M4L118130().var_min, Variables::MZ2_M4L118130().var_max);
               
               //====
               // KD
               //====
               _histo_name = "KD" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::KD().var_X_label + ";" + Variables::KD().var_Y_label;
               histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::KD().var_N_bin, Variables::KD().var_min, Variables::KD().var_max);
               
               _histo_name = "KD_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::KD_M4L118130().var_X_label + ";" + Variables::KD_M4L118130().var_Y_label;
               histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::KD_M4L118130().var_N_bin, Variables::KD_M4L118130().var_min, Variables::KD_M4L118130().var_max);
               
               _histo_name = "D1jet" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::D1jet().var_X_label + ";" + Variables::D1jet().var_Y_label;
               histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::D1jet().var_N_bin, Variables::D1jet().var_min, Variables::D1jet().var_max);
               
               _histo_name = "D1jet_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::D1jet_M4L118130().var_X_label + ";" + Variables::D1jet_M4L118130().var_Y_label;
               histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::D1jet_M4L118130().var_N_bin, Variables::D1jet_M4L118130().var_min, Variables::D1jet_M4L118130().var_max);
               
               _histo_name = "D2jet" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::D2jet().var_X_label + ";" + Variables::D2jet().var_Y_label;
               histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::D2jet().var_N_bin, Variables::D2jet().var_min, Variables::D2jet().var_max);
               
               _histo_name = "D2jet_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::D2jet_M4L118130().var_X_label + ";" + Variables::D2jet_M4L118130().var_Y_label;
               histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::D2jet_M4L118130().var_N_bin, Variables::D2jet_M4L118130().var_min, Variables::D2jet_M4L118130().var_max);
               
               _histo_name = "DWH" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::DWH().var_X_label + ";" + Variables::DWH().var_Y_label;
               histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::DWH().var_N_bin, Variables::DWH().var_min, Variables::DWH().var_max);
               
               _histo_name = "DWH_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::DWH_M4L118130().var_X_label + ";" + Variables::DWH_M4L118130().var_Y_label;
               histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::DWH_M4L118130().var_N_bin, Variables::DWH_M4L118130().var_min, Variables::DWH_M4L118130().var_max);
               
               _histo_name = "DZH" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::DZH().var_X_label + ";" + Variables::DZH().var_Y_label;
               histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::DZH().var_N_bin, Variables::DZH().var_min, Variables::DZH().var_max);
               
               _histo_name = "DZH_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::DZH_M4L118130().var_X_label + ";" + Variables::DZH_M4L118130().var_Y_label;
               histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::DZH_M4L118130().var_N_bin, Variables::DZH_M4L118130().var_min, Variables::DZH_M4L118130().var_max);
               
               //===========
               // MZ1 vs MZ2
               //===========
               _histo_name = "MZ1vsMZ2" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ1vsMZ2().var_X_label + ";" + Variables::MZ1vsMZ2().var_Y_label;
               histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ1vsMZ2().var_X_N_bin, Variables::MZ1vsMZ2().var_X_min, Variables::MZ1vsMZ2().var_X_max, Variables::MZ1vsMZ2().var_Y_N_bin, Variables::MZ1vsMZ2().var_Y_min, Variables::MZ1vsMZ2().var_Y_max);
               
               _histo_name = "MZ1vsMZ2_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ1vsMZ2_M4L118130().var_X_label + ";" + Variables::MZ1vsMZ2_M4L118130().var_Y_label;
               histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ1vsMZ2_M4L118130().var_X_N_bin, Variables::MZ1vsMZ2_M4L118130().var_X_min, Variables::MZ1vsMZ2_M4L118130().var_X_max, Variables::MZ1vsMZ2_M4L118130().var_Y_N_bin, Variables::MZ1vsMZ2_M4L118130().var_Y_min, Variables::MZ1vsMZ2_M4L118130().var_Y_max);
               
               //===========
               // KD vs M4l
               //===========
               _histo_name = "KDvsM4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::KDvsM4l().var_X_label + ";" + Variables::KDvsM4l().var_Y_label;
               histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::KDvsM4l().var_X_N_bin, Variables::KDvsM4l().var_X_min, Variables::KDvsM4l().var_X_max, Variables::KDvsM4l().var_Y_N_bin, Variables::KDvsM4l().var_Y_min, Variables::KDvsM4l().var_Y_max);
               
               _histo_name = "KDvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::KDvsM4lZoomed().var_X_label + ";" + Variables::KDvsM4lZoomed().var_Y_label;
               histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::KDvsM4lZoomed().var_X_N_bin, Variables::KDvsM4lZoomed().var_X_min, Variables::KDvsM4lZoomed().var_X_max, Variables::KDvsM4lZoomed().var_Y_N_bin, Variables::KDvsM4lZoomed().var_Y_min, Variables::KDvsM4lZoomed().var_Y_max);
               
               _histo_name = "KDvsM4lHighMass" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::KDvsM4lHighMass().var_X_label + ";" + Variables::KDvsM4lHighMass().var_Y_label;
               histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::KDvsM4lHighMass().var_X_N_bin, Variables::KDvsM4lHighMass().var_X_min, Variables::KDvsM4lHighMass().var_X_max, Variables::KDvsM4lHighMass().var_Y_N_bin, Variables::KDvsM4lHighMass().var_Y_min, Variables::KDvsM4l().var_Y_max);
               
               _histo_name = "D1jetvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::D1jetvsM4lZoomed().var_X_label + ";" + Variables::D1jetvsM4lZoomed().var_Y_label;
               histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::D1jetvsM4lZoomed().var_X_N_bin, Variables::D1jetvsM4lZoomed().var_X_min, Variables::D1jetvsM4lZoomed().var_X_max, Variables::D1jetvsM4lZoomed().var_Y_N_bin, Variables::D1jetvsM4lZoomed().var_Y_min, Variables::D1jetvsM4lZoomed().var_Y_max);
               
               _histo_name = "D2jetvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::D2jetvsM4lZoomed().var_X_label + ";" + Variables::D2jetvsM4lZoomed().var_Y_label;
               histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::D2jetvsM4lZoomed().var_X_N_bin, Variables::D2jetvsM4lZoomed().var_X_min, Variables::D2jetvsM4lZoomed().var_X_max, Variables::D2jetvsM4lZoomed().var_Y_N_bin, Variables::D2jetvsM4lZoomed().var_Y_min, Variables::D2jetvsM4lZoomed().var_Y_max);
               
               _histo_name = "DWHvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::DWHvsM4lZoomed().var_X_label + ";" + Variables::DWHvsM4lZoomed().var_Y_label;
               histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::DWHvsM4lZoomed().var_X_N_bin, Variables::DWHvsM4lZoomed().var_X_min, Variables::DWHvsM4lZoomed().var_X_max, Variables::DWHvsM4lZoomed().var_Y_N_bin, Variables::DWHvsM4lZoomed().var_Y_min, Variables::DWHvsM4lZoomed().var_Y_max);
               
               _histo_name = "DZHvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::DZHvsM4lZoomed().var_X_label + ";" + Variables::DZHvsM4lZoomed().var_Y_label;
               histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::DZHvsM4lZoomed().var_X_N_bin, Variables::DZHvsM4lZoomed().var_X_min, Variables::DZHvsM4lZoomed().var_X_max, Variables::DZHvsM4lZoomed().var_Y_N_bin, Variables::DZHvsM4lZoomed().var_Y_min, Variables::DZHvsM4lZoomed().var_Y_max);
               
            }
         }
      }
   }
   
   
   // Z+X
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         //=====
         // M4l
         //=====
         _histo_name = "M4l_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::M4lMain][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);
         
         _histo_name = "M4l_zoomed_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMainZoomed().var_N_bin, Variables::M4lMainZoomed().var_min, Variables::M4lMainZoomed().var_max);
         
         _histo_name = "M4l_HighMass_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMainHighMass().var_N_bin, Variables::M4lMainHighMass().var_min, Variables::M4lMainHighMass().var_max);

         _histo_name = "M4l_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);
         
         _histo_name = "M4l_zoomed_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMainZoomed][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMainZoomed().var_N_bin, Variables::M4lMainZoomed().var_min, Variables::M4lMainZoomed().var_max);
         
         _histo_name = "M4l_HighMass_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMainHighMass][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMainHighMass().var_N_bin, Variables::M4lMainHighMass().var_min, Variables::M4lMainHighMass().var_max);

         
         //=====
         // MZ1
         //=====
         _histo_name = "MZ1_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ1][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::MZ1().var_N_bin, Variables::MZ1().var_min, Variables::MZ1().var_max);
         
         _histo_name = "MZ1_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::MZ1_M4L118130().var_N_bin, Variables::MZ1_M4L118130().var_min, Variables::MZ1_M4L118130().var_max);
         
         //=====
         // MZ2
         //=====
         _histo_name = "MZ2_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ2][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::MZ2().var_N_bin, Variables::MZ2().var_min, Variables::MZ2().var_max);
         
         _histo_name = "MZ2_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::MZ2_M4L118130().var_N_bin, Variables::MZ2_M4L118130().var_min, Variables::MZ2_M4L118130().var_max);
         
         //====
         // KD
         //====
         _histo_name = "KD_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::KD][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::KD().var_N_bin, Variables::KD().var_min, Variables::KD().var_max);
         
         _histo_name = "KD_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::KD_M4L118130().var_N_bin, Variables::KD_M4L118130().var_min, Variables::KD_M4L118130().var_max);
         
         _histo_name = "D1jet_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::D1jet][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::D1jet().var_N_bin, Variables::D1jet().var_min, Variables::D1jet().var_max);
         
         _histo_name = "D1jet_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::D1jet_M4L118130().var_N_bin, Variables::D1jet_M4L118130().var_min, Variables::D1jet_M4L118130().var_max);
         
         _histo_name = "D2jet_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::D2jet][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::D2jet().var_N_bin, Variables::D2jet().var_min, Variables::D2jet().var_max);
         
         _histo_name = "D2jet_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::D2jet_M4L118130().var_N_bin, Variables::D2jet_M4L118130().var_min, Variables::D2jet_M4L118130().var_max);
         
         _histo_name = "DWH_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::DWH][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::DWH().var_N_bin, Variables::DWH().var_min, Variables::DWH().var_max);
         
         _histo_name = "DWH_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::DWH_M4L118130().var_N_bin, Variables::DWH_M4L118130().var_min, Variables::DWH_M4L118130().var_max);
         
         _histo_name = "DZH_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::DZH][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::DZH().var_N_bin, Variables::DZH().var_min, Variables::DZH().var_max);
         
         _histo_name = "DZH_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::DZH_M4L118130().var_N_bin, Variables::DZH_M4L118130().var_min, Variables::DZH_M4L118130().var_max);
         
      }
   }
}
//======================================



//Constructor
//======================
Histograms::Histograms( double lumi)
{
   _lumi = lumi;
   _blinding = "Unblinded";
   
   _s_process.push_back("Data");
   _s_process.push_back("H120");
   _s_process.push_back("H124");
   _s_process.push_back("H125");
   _s_process.push_back("H126");
   _s_process.push_back("H130");
   
   _s_process.push_back("H120ggH");
   _s_process.push_back("H124ggH");
   _s_process.push_back("H125ggH");
   _s_process.push_back("H126ggH");
   _s_process.push_back("H130ggH");
   
   _s_process.push_back("H120VBF");
   _s_process.push_back("H124VBF");
   _s_process.push_back("H125VBF");
   _s_process.push_back("H126VBF");
   _s_process.push_back("H130VBF");
   
   _s_process.push_back("H120WH");
   _s_process.push_back("H124WH");
   _s_process.push_back("H125WH");
   _s_process.push_back("H126WH");
   _s_process.push_back("H130WH");
   
   _s_process.push_back("H120ZH");
   _s_process.push_back("H124ZH");
   _s_process.push_back("H125ZH");
   _s_process.push_back("H126ZH");
   _s_process.push_back("H130ZH");
   
   _s_process.push_back("H120ttH");
   _s_process.push_back("H124ttH");
   _s_process.push_back("H125ttH");
   _s_process.push_back("H126ttH");
   _s_process.push_back("H130ttH");
      
   _s_process.push_back("qqZZ");
   _s_process.push_back("ggZZ");
   _s_process.push_back("DY");
   _s_process.push_back("ttbar");
   
   _s_final_state.push_back("4e");
   _s_final_state.push_back("4mu");
   _s_final_state.push_back("2e2mu");
   _s_final_state.push_back("2mu2e");
   _s_final_state.push_back("4l");
   
   _s_category.push_back("UnTagged");
   _s_category.push_back("VBF1jTagged");
   _s_category.push_back("VBF2jTagged");
   _s_category.push_back("VHLeptTagged");
   _s_category.push_back("VHHadrTagged");
   _s_category.push_back("ttHTagged");
   _s_category.push_back("VHMETTagged");
   _s_category.push_back("Inclusive");
   
   _s_resonant_status.push_back("resonant");
   _s_resonant_status.push_back("nonresonant");
   _s_resonant_status.push_back("allres");
   
   _s_production_mode.push_back("ggH");
   _s_production_mode.push_back("qqH");
   _s_production_mode.push_back("WH");
   _s_production_mode.push_back("ZH");
   _s_production_mode.push_back("ttH");
   

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
            {
               //=============
               // M4l
               //=============
               _histo_name = "M4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + "_" + _blinding;
               _histo_labels = ";" + Variables::M4lYields().var_X_label + ";" + Variables::M4lYields().var_Y_label;     
               histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lYields().var_N_bin, Variables::M4lYields().var_min, Variables::M4lYields().var_max);
            }
         }
      }
   }    
}
//======================



//=======================
Histograms::~Histograms()
{
}
//=======================



//====
// M4l
//====================================================================================
void Histograms::FillM4l( float M4l, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::M4lMain][fs][cat][rs][proc]->Fill(M4l, (proc == Settings::Data) ? 1. : weight);
   histos_1D[Settings::M4lMainZoomed][fs][cat][rs][proc]->Fill(M4l, (proc == Settings::Data) ? 1. : weight);
   histos_1D[Settings::M4lMainHighMass][fs][cat][rs][proc]->Fill(M4l, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================

//====================================================================
void Histograms::FillM4lZX( float M4l, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::M4lMain][fs][cat]->Fill(M4l, weight);
   histos_1D_ZX[Settings::M4lMainZoomed][fs][cat]->Fill(M4l, weight);
   histos_1D_ZX[Settings::M4lMainHighMass][fs][cat]->Fill(M4l, weight);
}
//====================================================================



//====
// MZ1
//====================================================================================
void Histograms::FillMZ1( float M4l, float MZ1, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::MZ1][fs][cat][rs][proc]->Fill(MZ1, (proc == Settings::Data) ? 1. : weight);
   
   if( M4l >= Variables::MZ1_M4L118130().cut_d && M4l <= Variables::MZ1_M4L118130().cut_u)
   {
      histos_1D[Settings::MZ1_M4L118130][fs][cat][rs][proc]->Fill(MZ1, (proc == Settings::Data) ? 1. : weight);
   }
}
//====================================================================================

//====================================================================
void Histograms::FillMZ1ZX( float M4l, float MZ1, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::MZ1][fs][cat]->Fill(MZ1, weight);
   
   if( M4l >= Variables::MZ1_M4L118130().cut_d && M4l <= Variables::MZ1_M4L118130().cut_u)
   {
      histos_1D_ZX[Settings::MZ1_M4L118130][fs][cat]->Fill(MZ1, weight);
   }
}
//====================================================================



//====
// MZ2
//===============================================================================================
void Histograms::FillMZ2( float M4l, float MZ2, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::MZ2][fs][cat][rs][proc]->Fill(MZ2, (proc == Settings::Data) ? 1. : weight);
   
   if( M4l >= Variables::MZ2_M4L118130().cut_d && M4l <= Variables::MZ2_M4L118130().cut_u)
   {
      histos_1D[Settings::MZ2_M4L118130][fs][cat][rs][proc]->Fill(MZ2, (proc == Settings::Data) ? 1. : weight);
   }
}
//===============================================================================================

//===============================================================================
void Histograms::FillMZ2ZX( float M4l, float MZ2, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::MZ2][fs][cat]->Fill(MZ2, weight);
   
   if( M4l >= Variables::MZ2_M4L118130().cut_d && M4l <= Variables::MZ2_M4L118130().cut_u)
   {
      histos_1D_ZX[Settings::MZ2_M4L118130][fs][cat]->Fill(MZ2, weight);
   }
}
//===============================================================================



//===
// KD
//===
//====================================================================================
void Histograms::FillKD( float M4l, float KD, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::KD][fs][cat][rs][proc]->Fill(KD, (proc == Settings::Data) ? 1. : weight);
   
   if( M4l >= Variables::KD_M4L118130().cut_d && M4l <= Variables::KD_M4L118130().cut_u)
   {
      histos_1D[Settings::KD_M4L118130][fs][cat][rs][proc]->Fill(KD, (proc == Settings::Data) ? 1. : weight);
   }
}
//====================================================================================

//====================================================================
void Histograms::FillKDZX( float M4l, float KD, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::KD][fs][cat]->Fill(KD, weight);
   
   if( M4l >= Variables::KD_M4L118130().cut_d && M4l <= Variables::KD_M4L118130().cut_u)
   {
      histos_1D_ZX[Settings::KD_M4L118130][fs][cat]->Fill(KD, weight);
   }
}
//====================================================================



//======
// D1jet
//====================================================================================
void Histograms::FillD1jet( float M4l, float D1jet, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::D1jet][fs][cat][rs][proc]->Fill(D1jet, (proc == Settings::Data) ? 1. : weight);
   
   if( M4l >= Variables::D1jet_M4L118130().cut_d && M4l <= Variables::D1jet_M4L118130().cut_u)
   {
      histos_1D[Settings::D1jet_M4L118130][fs][cat][rs][proc]->Fill(D1jet, (proc == Settings::Data) ? 1. : weight);
   }
}
//====================================================================================

//====================================================================
void Histograms::FillD1jetZX( float M4l, float D1jet, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::D1jet][fs][cat]->Fill(D1jet, weight);
   
   if( M4l >= Variables::D1jet_M4L118130().cut_d && M4l <= Variables::D1jet_M4L118130().cut_u)
   {
      histos_1D_ZX[Settings::D1jet_M4L118130][fs][cat]->Fill(D1jet, weight);
   }
}
//====================================================================



//======
// D2jet
//====================================================================================
void Histograms::FillD2jet( float M4l, float D2jet, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::D2jet][fs][cat][rs][proc]->Fill(D2jet, (proc == Settings::Data) ? 1. : weight);
   
   if( M4l >= Variables::D2jet_M4L118130().cut_d && M4l <= Variables::D2jet_M4L118130().cut_u)
   {
      histos_1D[Settings::D2jet_M4L118130][fs][cat][rs][proc]->Fill(D2jet, (proc == Settings::Data) ? 1. : weight);
   }
}
//====================================================================================

//====================================================================
void Histograms::FillD2jetZX( float M4l, float D2jet, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::D2jet][fs][cat]->Fill(D2jet, weight);
   
   if( M4l >= Variables::D2jet_M4L118130().cut_d && M4l <= Variables::D2jet_M4L118130().cut_u)
   {
      histos_1D_ZX[Settings::D2jet_M4L118130][fs][cat]->Fill(D2jet, weight);
   }
}
//====================================================================



//=====
// DWH
//====================================================================================
void Histograms::FillDWH( float M4l, float DWH, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::DWH][fs][cat][rs][proc]->Fill(DWH, (proc == Settings::Data) ? 1. : weight);
   
   if( M4l >= Variables::DWH_M4L118130().cut_d && M4l <= Variables::DWH_M4L118130().cut_u)
   {
      histos_1D[Settings::DWH_M4L118130][fs][cat][rs][proc]->Fill(DWH, (proc == Settings::Data) ? 1. : weight);
   }
}
//====================================================================================

//====================================================================
void Histograms::FillDWHZX( float M4l, float DWH, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::DWH][fs][cat]->Fill(DWH, weight);
   
   if( M4l >= Variables::DWH_M4L118130().cut_d && M4l <= Variables::DWH_M4L118130().cut_u)
   {
      histos_1D_ZX[Settings::DWH_M4L118130][fs][cat]->Fill(DWH, weight);
   }
}
//====================================================================



//====
// DZH
//====================================================================================
void Histograms::FillDZH( float M4l, float DZH, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::DZH][fs][cat][rs][proc]->Fill(DZH, (proc == Settings::Data) ? 1. : weight);
   
   if( M4l >= Variables::DZH_M4L118130().cut_d && M4l <= Variables::DZH_M4L118130().cut_u)
   {
      histos_1D[Settings::DZH_M4L118130][fs][cat][rs][proc]->Fill(DZH, (proc == Settings::Data) ? 1. : weight);
   }
}
//====================================================================================

//====================================================================
void Histograms::FillDZHZX( float M4l, float DZH, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::DZH][fs][cat]->Fill(DZH, weight);
   
   if( M4l >= Variables::DZH_M4L118130().cut_d && M4l <= Variables::DZH_M4L118130().cut_u)
   {
      histos_1D_ZX[Settings::DZH_M4L118130][fs][cat]->Fill(DZH, weight);
   }
}
//====================================================================



//=========
// MZ1vsMZ2
//====================================================================================
void Histograms::FillMZ1vsMZ2( float M4l, float MZ1, float MZ2, float weight, int fs, int cat, int rs, int proc )
{
   histos_2D[Settings::MZ1vsMZ2][fs][cat][rs][proc]->Fill(MZ1, MZ2, (proc == Settings::Data) ? 1. : weight);
   
   if( M4l >= Variables::MZ1vsMZ2_M4L118130().cut_d && M4l <= Variables::MZ1vsMZ2_M4L118130().cut_u)
   {
      histos_2D[Settings::MZ1vsMZ2_M4L118130][fs][cat][rs][proc]->Fill(MZ1, MZ2, (proc == Settings::Data) ? 1. : weight);
   }
}
//====================================================================================



//====================================================================================
void Histograms::FillVectors( float M4l, float ZZMassErrCorr, float KD, int nCleanedJetsPt30, float D1jet, float D2jet, float DWH, float DZH, int fs, int cat)
{
   vector_X[Settings::KDvsM4l][fs][cat].push_back(M4l);
   vector_Y[Settings::KDvsM4l][fs][cat].push_back(KD);
   vector_EX[Settings::KDvsM4l][fs][cat].push_back(ZZMassErrCorr);
   vector_EY[Settings::KDvsM4l][fs][cat].push_back(0.);
   
   vector_X[Settings::KDvsM4lZoomed][fs][cat].push_back(M4l);
   vector_Y[Settings::KDvsM4lZoomed][fs][cat].push_back(KD);
   vector_EX[Settings::KDvsM4lZoomed][fs][cat].push_back(ZZMassErrCorr);
   vector_EY[Settings::KDvsM4lZoomed][fs][cat].push_back(0.);
   
   vector_X[Settings::KDvsM4lHighMass][fs][cat].push_back(M4l);
   vector_Y[Settings::KDvsM4lHighMass][fs][cat].push_back(KD);
   vector_EX[Settings::KDvsM4lHighMass][fs][cat].push_back(ZZMassErrCorr);
   vector_EY[Settings::KDvsM4lHighMass][fs][cat].push_back(0.);
   
   
   if (nCleanedJetsPt30 == 1)
   {
      vector_X[Settings::D1jetvsM4lZoomed][fs][cat].push_back(M4l);
      vector_Y[Settings::D1jetvsM4lZoomed][fs][cat].push_back(D1jet);
      vector_EX[Settings::D1jetvsM4lZoomed][fs][cat].push_back(ZZMassErrCorr);
      vector_EY[Settings::D1jetvsM4lZoomed][fs][cat].push_back(0.);
   }

   if (nCleanedJetsPt30 >= 2)
   {
      vector_X[Settings::D2jetvsM4lZoomed][fs][cat].push_back(M4l);
      vector_Y[Settings::D2jetvsM4lZoomed][fs][cat].push_back(D2jet);
      vector_EX[Settings::D2jetvsM4lZoomed][fs][cat].push_back(ZZMassErrCorr);
      vector_EY[Settings::D2jetvsM4lZoomed][fs][cat].push_back(0.);
      
      vector_X[Settings::DWHvsM4lZoomed][fs][cat].push_back(M4l);
      vector_Y[Settings::DWHvsM4lZoomed][fs][cat].push_back(DWH);
      vector_EX[Settings::DWHvsM4lZoomed][fs][cat].push_back(ZZMassErrCorr);
      vector_EY[Settings::DWHvsM4lZoomed][fs][cat].push_back(0.);
      
      vector_X[Settings::DZHvsM4lZoomed][fs][cat].push_back(M4l);
      vector_Y[Settings::DZHvsM4lZoomed][fs][cat].push_back(DZH);
      vector_EX[Settings::DZHvsM4lZoomed][fs][cat].push_back(ZZMassErrCorr);
      vector_EY[Settings::DZHvsM4lZoomed][fs][cat].push_back(0.);
   }
   
}
//====================================================================================



//====================================================================================
void Histograms::FillDvsM4l( float M4l, float KD, int nCleanedJetsPt30, float D1jet, float D2jet, float DWH, float DZH, float weight, int fs, int cat, int rs, int proc )
{
   histos_2DError[Settings::KDvsM4l][fs][cat][rs][proc]        ->Fill(M4l, KD, (proc == Settings::Data) ? 1. : weight);
   histos_2DError[Settings::KDvsM4lZoomed][fs][cat][rs][proc]  ->Fill(M4l, KD, (proc == Settings::Data) ? 1. : weight);
   histos_2DError[Settings::KDvsM4lHighMass][fs][cat][rs][proc]->Fill(M4l, KD, (proc == Settings::Data) ? 1. : weight);
   
   if (nCleanedJetsPt30 == 1) histos_2DError[Settings::D1jetvsM4lZoomed][fs][cat][rs][proc]->Fill(M4l, D1jet, (proc == Settings::Data) ? 1. : weight);
   if (nCleanedJetsPt30 >= 2) histos_2DError[Settings::D2jetvsM4lZoomed][fs][cat][rs][proc]->Fill(M4l, D2jet, (proc == Settings::Data) ? 1. : weight);
   if (nCleanedJetsPt30 >= 2) histos_2DError[Settings::DWHvsM4lZoomed][fs][cat][rs][proc]  ->Fill(M4l, DWH, (proc == Settings::Data) ? 1. : weight);
   if (nCleanedJetsPt30 >= 2) histos_2DError[Settings::DZHvsM4lZoomed][fs][cat][rs][proc]  ->Fill(M4l, DZH, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================



//====================================================================================
void Histograms::FillYields( float M4l, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::M4lYields][fs][cat][rs][proc]->Fill(M4l, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================



//=======================================================================================
void Histograms::MakeZXShape( vector< vector <float> > _expected_yield_SR, int current_category)
{
   
   M4lZX *ZXShape = new M4lZX();
   
   ZXShape->GetM4lZX(Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max, current_category, _expected_yield_SR,
                     histos_1D_ZX_shape[Settings::M4lMain][Settings::fs4e][current_category],
                     histos_1D_ZX_shape[Settings::M4lMain][Settings::fs4mu][current_category],
                     histos_1D_ZX_shape[Settings::M4lMain][Settings::fs2e2mu][current_category],
                     histos_1D_ZX_shape[Settings::M4lMain][Settings::fs4l][current_category]);
   
   
   M4lZX *ZXShape_zoomed = new M4lZX();
   
   ZXShape_zoomed->GetM4lZX(Variables::M4lMainZoomed().var_N_bin, Variables::M4lMainZoomed().var_min, Variables::M4lMainZoomed().var_max, current_category, _expected_yield_SR,
                            histos_1D_ZX_shape[Settings::M4lMainZoomed][Settings::fs4e][current_category],
                            histos_1D_ZX_shape[Settings::M4lMainZoomed][Settings::fs4mu][current_category],
                            histos_1D_ZX_shape[Settings::M4lMainZoomed][Settings::fs2e2mu][current_category],
                            histos_1D_ZX_shape[Settings::M4lMainZoomed][Settings::fs4l][current_category]);
   
      
   M4lZX *ZXShape_HighMass = new M4lZX();
   
   ZXShape_HighMass->GetM4lZX(Variables::M4lMainHighMass().var_N_bin, Variables::M4lMainHighMass().var_min, Variables::M4lMainHighMass().var_max, current_category, _expected_yield_SR,
                              histos_1D_ZX_shape[Settings::M4lMainHighMass][Settings::fs4e][current_category],
                              histos_1D_ZX_shape[Settings::M4lMainHighMass][Settings::fs4mu][current_category],
                              histos_1D_ZX_shape[Settings::M4lMainHighMass][Settings::fs2e2mu][current_category],
                              histos_1D_ZX_shape[Settings::M4lMainHighMass][Settings::fs4l][current_category]);
   
}
//=======================================================================================

//==============================
void Histograms::FillInclusive()
{
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ ) // Change to num_of_final_states - 1
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ ) // Change to num_of_categories - 1
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ ) // Remove
         {
            //=====
            // M4l
            //=====
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125other]);
            
            //=====
            // MZ1
            //=====
            histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            //=====
            // MZ2
            //=====
            histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            //====
            // KD
            //====
            histos_1D[Settings::KD][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::KD][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::KD][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::KD][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::KD][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::KD][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::DWH][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DWH][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::DWH][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DWH][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::DWH][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DWH][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::DZH][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DZH][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::DZH][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DZH][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::DZH][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DZH][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            //============
            // MZ1 vs MZ2
            //============
            histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            //==========================
            // 2D plots with mass error
            //==========================
            histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][Settings::H125other]);
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
               //=====
               // M4l
               //=====
               histos_1D[Settings::M4lMain][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainZoomed][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainHighMass][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               //=====
               // MZ1
               //=====
               histos_1D[Settings::MZ1][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ1_M4L118130][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=====
               // MZ2
               //=====
               histos_1D[Settings::MZ2][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ2_M4L118130][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //====
               // KD
               //====
               histos_1D[Settings::KD][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::KD_M4L118130][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D1jet][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D1jet_M4L118130][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D2jet][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D2jet_M4L118130][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DWH][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DWH_M4L118130][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DZH][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DZH_M4L118130][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //============
               // MZ1 vs MZ2
               //============
               histos_2D[Settings::MZ1vsMZ2][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2D[Settings::MZ1vsMZ2_M4L118130][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);

               //==========================
               // 2D plots with mass error
               //==========================
               histos_2DError[Settings::KDvsM4l][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lZoomed][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lHighMass][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2DError[Settings::D1jetvsM4lZoomed][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::D2jetvsM4lZoomed][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DWHvsM4lZoomed][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DZHvsM4lZoomed][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);

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
               //=====
               // M4l
               //=====
               histos_1D[Settings::M4lMain][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainZoomed][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainHighMass][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               //=====
               // MZ1
               //=====
               histos_1D[Settings::MZ1][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ1_M4L118130][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=====
               // MZ2
               //=====
               histos_1D[Settings::MZ2][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ2_M4L118130][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //====
               // KD
               //====
               histos_1D[Settings::KD][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::KD_M4L118130][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D1jet][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D1jet_M4L118130][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D2jet][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D2jet_M4L118130][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DWH][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DWH_M4L118130][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DZH][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DZH_M4L118130][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //============
               // MZ1 vs MZ2
               //============
               histos_2D[Settings::MZ1vsMZ2][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);

               //==========================
               // 2D plots with mass error
               //==========================
               histos_2DError[Settings::KDvsM4l][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lZoomed][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lHighMass][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DWHvsM4lZoomed][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DZHvsM4lZoomed][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
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
               histos_1D[Settings::M4lMain][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1
               //=============
               histos_1D[Settings::MZ1][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ2
               //=============
               histos_1D[Settings::MZ2][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // KD
               //=============
               histos_1D[Settings::KD][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::KD_M4L118130][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D1jet][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D2jet][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DWH][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DZH][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1vsMZ2
               //=============
               histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //==========================
               // 2D plots with mass error
               //==========================
               histos_2DError[Settings::KDvsM4l][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
            }
         }
      }
   }

   //====================
   // Sum Z+X histograms
   //====================
   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         //=====
         // M4l
         //=====
         histos_1D_ZX[Settings::M4lMain][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]);
         histos_1D_ZX[Settings::M4lMainZoomed][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]);
         histos_1D_ZX[Settings::M4lMainHighMass][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat]);
         
         //=====
         // MZ1
         //=====
         histos_1D_ZX[Settings::MZ1][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::MZ1][i_fs][i_cat]);
         histos_1D_ZX[Settings::MZ1_M4L118130][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat]);
         
         //=====
         // MZ2
         //=====
         histos_1D_ZX[Settings::MZ2][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::MZ2][i_fs][i_cat]);
         histos_1D_ZX[Settings::MZ2_M4L118130][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat]);
         
         //====
         // KD
         //====
         histos_1D_ZX[Settings::KD][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::KD][i_fs][i_cat]);
         histos_1D_ZX[Settings::KD_M4L118130][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::D1jet][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::D1jet][i_fs][i_cat]);
         histos_1D_ZX[Settings::D1jet_M4L118130][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::D2jet][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::D2jet][i_fs][i_cat]);
         histos_1D_ZX[Settings::D2jet_M4L118130][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::DWH][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::DWH][i_fs][i_cat]);
         histos_1D_ZX[Settings::DWH_M4L118130][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::DZH][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::DZH][i_fs][i_cat]);
         histos_1D_ZX[Settings::DZH_M4L118130][Settings::fs4l][i_cat]->Add(histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat]);
         
         //==========================
         // 2D plots with mass error
         //==========================
         vector_X[Settings::KDvsM4l][Settings::fs4l][i_cat].insert(vector_X[Settings::KDvsM4l][Settings::fs4l][i_cat].end(),vector_X[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4l][Settings::fs4l][i_cat].insert(vector_Y[Settings::KDvsM4l][Settings::fs4l][i_cat].end(),vector_Y[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4l][Settings::fs4l][i_cat].insert(vector_EX[Settings::KDvsM4l][Settings::fs4l][i_cat].end(),vector_EX[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4l][Settings::fs4l][i_cat].insert(vector_EY[Settings::KDvsM4l][Settings::fs4l][i_cat].end(),vector_EY[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4l][i_fs][i_cat].end());
         
         vector_X[Settings::KDvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_X[Settings::KDvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_Y[Settings::KDvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_Y[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EX[Settings::KDvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EX[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EY[Settings::KDvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EY[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::KDvsM4lHighMass][Settings::fs4l][i_cat].insert(vector_X[Settings::KDvsM4lHighMass][Settings::fs4l][i_cat].end(),vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4lHighMass][Settings::fs4l][i_cat].insert(vector_Y[Settings::KDvsM4lHighMass][Settings::fs4l][i_cat].end(),vector_Y[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4lHighMass][Settings::fs4l][i_cat].insert(vector_EX[Settings::KDvsM4lHighMass][Settings::fs4l][i_cat].end(),vector_EX[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4lHighMass][Settings::fs4l][i_cat].insert(vector_EY[Settings::KDvsM4lHighMass][Settings::fs4l][i_cat].end(),vector_EY[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         
         vector_X[Settings::D1jetvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_X[Settings::D1jetvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::D1jetvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_Y[Settings::D1jetvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_Y[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::D1jetvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EX[Settings::D1jetvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EX[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::D1jetvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EY[Settings::D1jetvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EY[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::D2jetvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_X[Settings::D2jetvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::D2jetvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_Y[Settings::D2jetvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_Y[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::D2jetvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EX[Settings::D2jetvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EX[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::D2jetvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EY[Settings::D2jetvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EY[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::DWHvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_X[Settings::DWHvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::DWHvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_Y[Settings::DWHvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_Y[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::DWHvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EX[Settings::DWHvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EX[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::DWHvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EY[Settings::DWHvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EY[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::DZHvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_X[Settings::DZHvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::DZHvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_Y[Settings::DZHvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_Y[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::DZHvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EX[Settings::DZHvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EX[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::DZHvsM4lZoomed][Settings::fs4l][i_cat].insert(vector_EY[Settings::DZHvsM4lZoomed][Settings::fs4l][i_cat].end(),vector_EY[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
      }
   }

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         //=====
         // M4l
         //=====
         histos_1D_ZX[Settings::M4lMain][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]);
         histos_1D_ZX[Settings::M4lMainZoomed][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]);
         histos_1D_ZX[Settings::M4lMainHighMass][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat]);
         
         //=====
         // MZ1
         //=====
         histos_1D_ZX[Settings::MZ1][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::MZ1][i_fs][i_cat]);
         histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat]);
         
         //=====
         // MZ2
         //=====
         histos_1D_ZX[Settings::MZ2][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::MZ2][i_fs][i_cat]);
         histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat]);
         
         //====
         // KD
         //====
         histos_1D_ZX[Settings::KD][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::KD][i_fs][i_cat]);
         histos_1D_ZX[Settings::KD_M4L118130][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::D1jet][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::D1jet][i_fs][i_cat]);
         histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::D2jet][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::D2jet][i_fs][i_cat]);
         histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::DWH][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::DWH][i_fs][i_cat]);
         histos_1D_ZX[Settings::DWH_M4L118130][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::DZH][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::DZH][i_fs][i_cat]);
         histos_1D_ZX[Settings::DZH_M4L118130][i_fs][Settings::inclusive]->Add(histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat]);
         
         //==========================
         // 2D plots with mass error
         //==========================
         vector_X[Settings::KDvsM4l][i_fs][Settings::inclusive].insert(vector_X[Settings::KDvsM4l][i_fs][Settings::inclusive].end(),vector_X[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4l][i_fs][Settings::inclusive].insert(vector_Y[Settings::KDvsM4l][i_fs][Settings::inclusive].end(),vector_Y[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4l][i_fs][Settings::inclusive].insert(vector_EX[Settings::KDvsM4l][i_fs][Settings::inclusive].end(),vector_EX[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4l][i_fs][Settings::inclusive].insert(vector_EY[Settings::KDvsM4l][i_fs][Settings::inclusive].end(),vector_EY[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4l][i_fs][i_cat].end());
         
         vector_X[Settings::KDvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_X[Settings::KDvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_Y[Settings::KDvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_Y[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EX[Settings::KDvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EX[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EY[Settings::KDvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EY[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::KDvsM4lHighMass][i_fs][Settings::inclusive].insert(vector_X[Settings::KDvsM4lHighMass][i_fs][Settings::inclusive].end(),vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4lHighMass][i_fs][Settings::inclusive].insert(vector_Y[Settings::KDvsM4lHighMass][i_fs][Settings::inclusive].end(),vector_Y[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4lHighMass][i_fs][Settings::inclusive].insert(vector_EX[Settings::KDvsM4lHighMass][i_fs][Settings::inclusive].end(),vector_EX[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4lHighMass][i_fs][Settings::inclusive].insert(vector_EY[Settings::KDvsM4lHighMass][i_fs][Settings::inclusive].end(),vector_EY[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         
         vector_X[Settings::D1jetvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_X[Settings::D1jetvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::D1jetvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_Y[Settings::D1jetvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_Y[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::D1jetvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EX[Settings::D1jetvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EX[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::D1jetvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EY[Settings::D1jetvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EY[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::D2jetvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_X[Settings::D2jetvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::D2jetvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_Y[Settings::D2jetvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_Y[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::D2jetvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EX[Settings::D2jetvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EX[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::D2jetvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EY[Settings::D2jetvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EY[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::DWHvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_X[Settings::DWHvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::DWHvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_Y[Settings::DWHvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_Y[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::DWHvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EX[Settings::DWHvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EX[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::DWHvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EY[Settings::DWHvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EY[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::DZHvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_X[Settings::DZHvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::DZHvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_Y[Settings::DZHvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_Y[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::DZHvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EX[Settings::DZHvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EX[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::DZHvsM4lZoomed][i_fs][Settings::inclusive].insert(vector_EY[Settings::DZHvsM4lZoomed][i_fs][Settings::inclusive].end(),vector_EY[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
      }
   }
}
//==============================




//==============================
void Histograms::FillInclusiveYields()
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
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120ggH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120VBF]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120WH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120ZH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH120ttH]);
            
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124ggH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124VBF]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124WH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124ZH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH124ttH]);
            
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125ggH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125VBF]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125WH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125ZH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH125ttH]);
            
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126ggH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126VBF]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126WH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126ZH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH126ttH]);
            
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130ggH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130VBF]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130WH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130ZH]);
            histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][Settings::yH130ttH]);
         }
      }
   }

   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses - 1; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
            {
               //=============
               // M4l
               //=============
               histos_1D[Settings::M4lYields][Settings::fs4l][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][i_proc]);
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
            for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
            {
               //=============
               // M4l
               //=============
               histos_1D[Settings::M4lYields][i_fs][Settings::inclusive][i_rs][i_proc]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][i_proc]);
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
            for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
            {
               //=============
               // M4l
               //=============
               histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][i_proc]->Add(histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][i_proc]);
            }
         }
      }
   }

}
//==============================



//=================================
void Histograms::SmoothHistograms()
{
   float integral = 0;
   TH1F* CheckSmoothing;
   
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         //=============
         // M4l
         //=============
         integral = histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::M4lMain][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::M4lMain][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat]->Integral() );
         }

         
         //=============
         // MZ1
         //=============
         integral = histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::MZ1][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat]->Integral() );
         }
         
         //=============
         // MZ2
         //=============
         integral = histos_1D_ZX[Settings::MZ2][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::MZ2][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            
            histos_1D_ZX[Settings::MZ2][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::MZ2][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::MZ2][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat]->Integral() );
         }

         //=============
         // KD
         //=============
         integral = histos_1D_ZX[Settings::KD][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::KD][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            
            histos_1D_ZX[Settings::KD][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::KD][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::KD][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat]->Integral() );
         }
         
         //=============
         // D1jet
         //=============
         integral = histos_1D_ZX[Settings::D1jet][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::D1jet][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            
            histos_1D_ZX[Settings::D1jet][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::D1jet][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::D1jet][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat]->Integral() );
         }
         
         //=============
         // D2jet
         //=============
         integral = histos_1D_ZX[Settings::D2jet][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::D2jet][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            
            histos_1D_ZX[Settings::D2jet][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::D2jet][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::D2jet][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat]->Integral() );
         }
         
         //=============
         // DWH
         //=============
         integral = histos_1D_ZX[Settings::DWH][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::DWH][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            
            histos_1D_ZX[Settings::DWH][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::DWH][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::DWH][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat]->Integral() );
         }
         
         //=============
         // DZH
         //=============
         integral = histos_1D_ZX[Settings::DZH][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::DZH][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            
            histos_1D_ZX[Settings::DZH][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::DZH][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::DZH][i_fs][i_cat]->Integral() );
         }
         
         integral = histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat]->Integral();
         CheckSmoothing = histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat];
         CheckSmoothing->Smooth(1);
         if(integral > 0. && CheckSmoothing->Integral() > 0.)
         {
            histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat]->Smooth(1);
            histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat]->Scale( integral / histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat]->Integral() );
         }
      }
   }
}
//=================================



//==============================
void Histograms::RenormalizeZX( vector< vector <float> > _expected_yield_SR )
{
   M4lZX *ZX = new M4lZX();
   
   for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
   {
      // M4l
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::M4lMain][Settings::fs4e][i_cat], histos_1D_ZX[Settings::M4lMain][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::M4lMain][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::M4lMainZoomed][Settings::fs4e][i_cat], histos_1D_ZX[Settings::M4lMainZoomed][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::M4lMainZoomed][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::M4lMainHighMass][Settings::fs4e][i_cat], histos_1D_ZX[Settings::M4lMainHighMass][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::M4lMainHighMass][Settings::fs2e2mu][i_cat]);
         
      // MZ1
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::MZ1][Settings::fs4e][i_cat], histos_1D_ZX[Settings::MZ1][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::MZ1][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::MZ1_M4L118130][Settings::fs4e][i_cat], histos_1D_ZX[Settings::MZ1_M4L118130][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::MZ1_M4L118130][Settings::fs2e2mu][i_cat]);

      // MZ2
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::MZ2][Settings::fs4e][i_cat], histos_1D_ZX[Settings::MZ2][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::MZ2][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::MZ2_M4L118130][Settings::fs4e][i_cat], histos_1D_ZX[Settings::MZ2_M4L118130][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::MZ2_M4L118130][Settings::fs2e2mu][i_cat]);
         
      // KD
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::KD][Settings::fs4e][i_cat], histos_1D_ZX[Settings::KD][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::KD][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::KD_M4L118130][Settings::fs4e][i_cat], histos_1D_ZX[Settings::KD_M4L118130][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::KD_M4L118130][Settings::fs2e2mu][i_cat]);
         
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::D1jet][Settings::fs4e][i_cat], histos_1D_ZX[Settings::D1jet][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::D1jet][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::D1jet_M4L118130][Settings::fs4e][i_cat], histos_1D_ZX[Settings::D1jet_M4L118130][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::D1jet_M4L118130][Settings::fs2e2mu][i_cat]);
         
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::D2jet][Settings::fs4e][i_cat], histos_1D_ZX[Settings::D2jet][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::D2jet][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::D2jet_M4L118130][Settings::fs4e][i_cat], histos_1D_ZX[Settings::D2jet_M4L118130][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::D2jet_M4L118130][Settings::fs2e2mu][i_cat]);
         
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::DWH][Settings::fs4e][i_cat], histos_1D_ZX[Settings::DWH][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::DWH][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::DWH_M4L118130][Settings::fs4e][i_cat], histos_1D_ZX[Settings::DWH_M4L118130][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::DWH_M4L118130][Settings::fs2e2mu][i_cat]);
         
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::DZH][Settings::fs4e][i_cat], histos_1D_ZX[Settings::DZH][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::DZH][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::DZH_M4L118130][Settings::fs4e][i_cat], histos_1D_ZX[Settings::DZH_M4L118130][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::DZH_M4L118130][Settings::fs2e2mu][i_cat]);
   }
   
   ZX->~M4lZX();   
}
//==============================



//=============================================
void Histograms::SaveHistos( string file_name )
{
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
         histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat]->Write();
         histos_1D_ZX_shape[Settings::M4lMainHighMass][i_fs][i_cat]->Write();
         
         //=============
         // MZ1
         //=============
         histos_1D_ZX[Settings::MZ1][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat]->Write();
         
         //=============
         // MZ2
         //=============
         histos_1D_ZX[Settings::MZ2][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat]->Write();
         
         //=============
         // KD
         //=============
         histos_1D_ZX[Settings::KD][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::D1jet][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::D2jet][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::DWH][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::DZH][i_fs][i_cat]->Write();
         histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat]->Write();
                                                                                                                                                                                    
         //==========================
         // 2D plots with mass error
         //==========================
         histos_2DError_data[Settings::KDvsM4l][i_fs][i_cat] = new TGraphErrors (vector_X[Settings::KDvsM4l][i_fs][i_cat].size(),
                                                                                    &(vector_X[Settings::KDvsM4l][i_fs][i_cat][0]),
                                                                                    &(vector_Y[Settings::KDvsM4l][i_fs][i_cat][0]),
                                                                                    &(vector_EX[Settings::KDvsM4l][i_fs][i_cat][0]),
                                                                                    &(vector_EY[Settings::KDvsM4l][i_fs][i_cat][0]));
         _histo_name = "KDvsM4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::KDvsM4l][i_fs][i_cat]->SetName(_histo_name.c_str());
         histos_2DError_data[Settings::KDvsM4l][i_fs][i_cat]->Write();
         
         histos_2DError_data[Settings::KDvsM4lZoomed][i_fs][i_cat] = new TGraphErrors (vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat].size(),
                                                                                 &(vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_Y[Settings::KDvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EX[Settings::KDvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EY[Settings::KDvsM4lZoomed][i_fs][i_cat][0]));
         _histo_name = "KDvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::KDvsM4lZoomed][i_fs][i_cat]->SetName(_histo_name.c_str());
         histos_2DError_data[Settings::KDvsM4lZoomed][i_fs][i_cat]->Write();
         
         histos_2DError_data[Settings::KDvsM4lHighMass][i_fs][i_cat] = new TGraphErrors (vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat].size(),
                                                                                 &(vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat][0]),
                                                                                 &(vector_Y[Settings::KDvsM4lHighMass][i_fs][i_cat][0]),
                                                                                 &(vector_EX[Settings::KDvsM4lHighMass][i_fs][i_cat][0]),
                                                                                 &(vector_EY[Settings::KDvsM4lHighMass][i_fs][i_cat][0]));
         _histo_name = "KDvsM4lHighMass" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::KDvsM4lHighMass][i_fs][i_cat]->SetName(_histo_name.c_str());
         histos_2DError_data[Settings::KDvsM4lHighMass][i_fs][i_cat]->Write();
         
         histos_2DError_data[Settings::D1jetvsM4lZoomed][i_fs][i_cat] = new TGraphErrors (vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat].size(),
                                                                                 &(vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_Y[Settings::D1jetvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EX[Settings::D1jetvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EY[Settings::D1jetvsM4lZoomed][i_fs][i_cat][0]));
         _histo_name = "D1jetvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::D1jetvsM4lZoomed][i_fs][i_cat]->SetName(_histo_name.c_str());
         histos_2DError_data[Settings::D1jetvsM4lZoomed][i_fs][i_cat]->Write();
         
         histos_2DError_data[Settings::D2jetvsM4lZoomed][i_fs][i_cat] = new TGraphErrors (vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat].size(),
                                                                                 &(vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_Y[Settings::D2jetvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EX[Settings::D2jetvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EY[Settings::D2jetvsM4lZoomed][i_fs][i_cat][0]));
         _histo_name = "D2jetvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::D2jetvsM4lZoomed][i_fs][i_cat]->SetName(_histo_name.c_str());
         histos_2DError_data[Settings::D2jetvsM4lZoomed][i_fs][i_cat]->Write();
         
         histos_2DError_data[Settings::DWHvsM4lZoomed][i_fs][i_cat] = new TGraphErrors (vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat].size(),
                                                                                 &(vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_Y[Settings::DWHvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EX[Settings::DWHvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EY[Settings::DWHvsM4lZoomed][i_fs][i_cat][0]));
         _histo_name = "DWHvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::DWHvsM4lZoomed][i_fs][i_cat]->SetName(_histo_name.c_str());
         histos_2DError_data[Settings::DWHvsM4lZoomed][i_fs][i_cat]->Write();
         
         histos_2DError_data[Settings::DZHvsM4lZoomed][i_fs][i_cat] = new TGraphErrors (vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat].size(),
                                                                                 &(vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_Y[Settings::DZHvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EX[Settings::DZHvsM4lZoomed][i_fs][i_cat][0]),
                                                                                 &(vector_EY[Settings::DZHvsM4lZoomed][i_fs][i_cat][0]));
         _histo_name = "DZHvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::DZHvsM4lZoomed][i_fs][i_cat]->SetName(_histo_name.c_str());
         histos_2DError_data[Settings::DZHvsM4lZoomed][i_fs][i_cat]->Write();
      
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               //=============
               // M4l
               //=============
               histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc]->Write();
               
               //=============
               // MZ1
               //=============
               histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc]->Write();
               
               //=============
               // MZ2
               //=============
               histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]->Write();
               
               //=============
               // KD
               //=============
               histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc]->Write();
               
               //=============
               // MZ1vsMZ2
               //=============
               histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]->Write();
               
               //=============
               // KDvsM4l
               //=============
               histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]->Write();
               histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]->Write();
            }
         }
      }
   }
   
   fOutHistos->Close();
   delete fOutHistos;
}
//=============================================




//=============================================
void Histograms::SaveYieldHistos( string file_name )
{
   
   cout << "[INFO] Saving yield histograms to ROOT file." << endl;
   
   TFile* fOutHistos = new TFile(file_name.c_str(), "recreate");
   fOutHistos->cd();
   
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {

         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
            {
               histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][i_proc]->Write();
            }
         }
      }
   }
   
   cout << "[INFO] Closing ROOT file." << endl;
   
   fOutHistos->Close();
   delete fOutHistos;
}
//=============================================



//=============================
void Histograms::DeleteHistos()
{
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         //=============
         // M4l
         //=============
         delete histos_1D_ZX[Settings::M4lMain][i_fs][i_cat];
         delete histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat];
         delete histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat];
         delete histos_1D_ZX_shape[Settings::M4lMainZoomed][i_fs][i_cat];
         delete histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat];
         delete histos_1D_ZX_shape[Settings::M4lMainHighMass][i_fs][i_cat];
         
         //=============
         // MZ1
         //=============
         delete histos_1D_ZX[Settings::MZ1][i_fs][i_cat];
         delete histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat];
         
         //=============
         // MZ2
         //=============
         delete histos_1D_ZX[Settings::MZ2][i_fs][i_cat];
         delete histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat];
         
         //=============
         // KD
         //=============
         delete histos_1D_ZX[Settings::KD][i_fs][i_cat];
         delete histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat];
         delete histos_1D_ZX[Settings::D1jet][i_fs][i_cat];
         delete histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat];
         delete histos_1D_ZX[Settings::D2jet][i_fs][i_cat];
         delete histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat];
         delete histos_1D_ZX[Settings::DWH][i_fs][i_cat];
         delete histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat];
         delete histos_1D_ZX[Settings::DZH][i_fs][i_cat];
         delete histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat];
         
         //==========================
         // 2D plots with mass error
         //==========================
         delete histos_2DError_data[Settings::KDvsM4l][i_fs][i_cat];
         delete histos_2DError_data[Settings::KDvsM4lZoomed][i_fs][i_cat];
         delete histos_2DError_data[Settings::KDvsM4lHighMass][i_fs][i_cat];
         delete histos_2DError_data[Settings::D1jetvsM4lZoomed][i_fs][i_cat];
         delete histos_2DError_data[Settings::D2jetvsM4lZoomed][i_fs][i_cat];
         delete histos_2DError_data[Settings::DWHvsM4lZoomed][i_fs][i_cat];
         delete histos_2DError_data[Settings::DZHvsM4lZoomed][i_fs][i_cat];
         
         
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               //=============
               // M4l
               //=============
               delete histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc];
               
               //=============
               // MZ1
               //=============
               delete histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc];
               
               //=============
               // MZ2
               //=============
               delete histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc];
               
               //=============
               // KD
               //=============
               delete histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc];
               delete histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc];
               
               //=============
               // MZ1vsMZ2
               //=============
               delete histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc];
               delete histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc];
               
               //=============
               // KDvsM4l
               //=============
               delete histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc];
               delete histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc];
               delete histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc];
               delete histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc];
               delete histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc];
               delete histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc];
               delete histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc];
               
            }
         }
      }
   }

}
//=============================



//===================================
void Histograms::DeleteYieldsHistos()
{
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         //=============
         // M4l
         //=============
         
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
            {
               //=============
               // M4l
               //=============
               delete histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][i_proc];               
            }
         }
      }
   }
}
//===================================



//=============================================
void Histograms::GetHistos( TString file_name )
{
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
               
               _histo_name = "M4l_HighMass" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               //=============
               // MZ1
               //=============
               _histo_name = "MZ1" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "MZ1_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               //=============
               // MZ2
               //=============
               _histo_name = "MZ2" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "MZ2_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               //=============
               // KD
               //=============
               _histo_name = "KD" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "KD_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "D1jet" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "D1jet_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "D2jet" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "D2jet_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "DWH" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "DWH_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "DZH" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "DZH_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
               
               //=============
               // MZ1vsMZ2
               //=============
               _histo_name = "MZ1vsMZ2" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc] = (TH2F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "MZ1vsMZ2_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc] = (TH2F*)histo_file->Get(_histo_name.c_str());
               
               //=============
               // KDvsM4l
               //=============
               _histo_name = "KDvsM4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc] = (TH2F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "KDvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = (TH2F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "KDvsM4lHighMass" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc] = (TH2F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "D1jetvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = (TH2F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "D2jetvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = (TH2F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "DWHvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = (TH2F*)histo_file->Get(_histo_name.c_str());
               
               _histo_name = "DZHvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc] = (TH2F*)histo_file->Get(_histo_name.c_str());
            
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
         
         _histo_name = "M4l_zoomed_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::M4lMainZoomed][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "M4l_zoomed_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMainZoomed][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "M4l_HighMass_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "M4l_HighMass_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMainHighMass][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());

         
         //=============
         // MZ1
         //=============
         _histo_name = "MZ1_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ1][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "MZ1_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         //=============
         // MZ2
         //=============
         _histo_name = "MZ2_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ2][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "MZ2_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         //=============
         // KD
         //=============
         _histo_name = "KD_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::KD][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "KD_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "D1jet_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::D1jet][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "D1jet_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "D2jet_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::D2jet][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "D2jet_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "DWH_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::DWH][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "DWH_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "DZH_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::DZH][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "DZH_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
                                                                                                                                                                                    
         //==========================
         // 2D plots with mass error
         //==========================
         _histo_name = "KDvsM4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::KDvsM4l][i_fs][i_cat] = (TGraphErrors*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "KDvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::KDvsM4lZoomed][i_fs][i_cat] = (TGraphErrors*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "KDvsM4lHighMass" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::KDvsM4lHighMass][i_fs][i_cat] = (TGraphErrors*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "D1jetvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::D1jetvsM4lZoomed][i_fs][i_cat] = (TGraphErrors*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "D2jetvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::D2jetvsM4lZoomed][i_fs][i_cat] = (TGraphErrors*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "DWHvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::DWHvsM4lZoomed][i_fs][i_cat] = (TGraphErrors*)histo_file->Get(_histo_name.c_str());
         
         _histo_name = "DZHvsM4lZoomed" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_2DError_data[Settings::DZHvsM4lZoomed][i_fs][i_cat] = (TGraphErrors*)histo_file->Get(_histo_name.c_str());
         
      }
   }
}
//=============================================



//=============================================
void Histograms::GetYieldsHistos( TString file_name )
{
   TFile* histo_file = TFile::Open(file_name);

   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
            {
               //=============
               // M4l
               //=============
               _histo_name = "M4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + "_" + _blinding;
               histos_1D[Settings::M4lYields][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
            }
         }
      }
   }
      
}
//=============================================



//========================================================================================================
void Histograms::Plot1D_single( TString filename, TString variable_name, TString folder, int fs, int cat )
{
   int plot_index = SetPlotName( variable_name);
   
   gStyle->SetPadLeftMargin(0.10);
   gStyle->SetPadRightMargin(0.01);
   
   TCanvas *c = new TCanvas(variable_name, variable_name, 650, 500);
   
   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
   
   if( plot_index == Settings::D1jet_M4L118130 || plot_index == Settings::D2jet_M4L118130 || plot_index == Settings::D1jet || plot_index == Settings::D2jet)
   {
      histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VBF]->SetFillColor(1180);
      histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VH]->SetFillColor(kRed-10);
      histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other]->SetFillColor(kRed-10);
   }
   else if( plot_index == Settings::DWH_M4L118130 || plot_index == Settings::DZH_M4L118130 || plot_index == Settings::DWH || plot_index == Settings::DZH )
   {
      histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VH]->SetFillColor(1180);
      histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VBF]->SetFillColor(kRed-10);
      histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other]->SetFillColor(kRed-10);
   }
   else histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125]->SetFillColor(1180);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ]->SetFillColor(851);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ]->SetFillColor(858);
   if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass") histos_1D_ZX_shape[plot_index][fs][cat]->SetFillColor(411);
   else histos_1D_ZX[plot_index][fs][cat]->SetFillColor(411);
   
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125]->SetLineColor(633);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VBF]->SetLineColor(633);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VH]->SetLineColor(633);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other]->SetLineColor(633);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ]->SetLineColor(602);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ]->SetLineColor(602);
   if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass") histos_1D_ZX_shape[plot_index][fs][cat]->SetLineColor(420);
   else histos_1D_ZX[plot_index][fs][cat]->SetLineColor(420);
   
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.7);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(20);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetBinErrorOption(TH1::kPoisson);
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->SetLineColor(kBlack);
   
   THStack *stack = new THStack( "stack", "stack" );
   if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass") stack->Add(histos_1D_ZX_shape[plot_index][fs][cat]);
   else stack->Add(histos_1D_ZX[plot_index][fs][cat]);
   stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ]);
   stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ]);
   if( plot_index == Settings::D1jet_M4L118130 || plot_index == Settings::D2jet_M4L118130 || plot_index == Settings::D1jet || plot_index == Settings::D2jet)
   {
      histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other]->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VH]);
      stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other]);
      stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VBF]);
   }
   else if( plot_index == Settings::DWH_M4L118130 || plot_index == Settings::DZH_M4L118130 || plot_index == Settings::DWH || plot_index == Settings::DZH )
   {
      histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other]->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VBF]);
      stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other]);
      stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VH]);
   }
   else stack->Add(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125]);
   
   stack->Draw("HIST");
   
   float data_max = histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetBinContent(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
   float data_max_error = histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetBinErrorUp(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
   
   if( GetVarLogY( variable_name) )
   {
      stack->SetMinimum(0.2);
      stack->SetMaximum((data_max + data_max_error)*100);
   }
   
   else
   {
      stack->SetMinimum(1e-5);
      stack->SetMaximum((data_max + data_max_error)*1.1);
   }
   
   if ( (plot_index == Settings::M4lMain || plot_index == Settings::M4lMainZoomed) && fs == Settings::fs4e) _fs_label = "m_{4#font[12]{e}} (GeV)";
   if ( (plot_index == Settings::M4lMain || plot_index == Settings::M4lMainZoomed) && fs == Settings::fs4mu) _fs_label = "m_{4#font[12]{#mu}} (GeV)";
   if ( (plot_index == Settings::M4lMain || plot_index == Settings::M4lMainZoomed) && fs == Settings::fs2e2mu) _fs_label = "m_{2#font[12]{e}2#font[12]{#mu}} (GeV)";
   stack->GetXaxis()->SetTitle(((plot_index == Settings::M4lMain || plot_index == Settings::M4lMainZoomed) && fs != Settings::fs4l ) ? _fs_label : (TString)histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetXaxis()->GetTitle());
   stack->GetXaxis()->SetTitleSize(0.05);
   stack->GetXaxis()->SetLabelSize(0.05);
   stack->GetYaxis()->SetTitle(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
   stack->GetYaxis()->SetTitleSize(0.05);
   stack->GetYaxis()->SetLabelSize(0.05);
   
   stack->GetXaxis()->SetTitleOffset(1.2);
   stack->GetYaxis()->SetTitleOffset(1.);
   
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->Draw("SAME p E1 X0");
   
   TLegend *legend;
   if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass" )
   {
      legend  = CreateLegend("right",histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX_shape[plot_index][fs][cat]);
   }
   else if ( plot_index == Settings::D1jet_M4L118130 || plot_index == Settings::D1jet )
   {
      legend  = CreateLegendVBF("left",histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VBF],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][fs][cat]);
   }
   else if ( plot_index == Settings::D2jet_M4L118130 || plot_index == Settings::D2jet )
   {
      legend  = CreateLegendVBF("right",histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VBF],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][fs][cat]);
   }
   else if ( plot_index == Settings::DWH_M4L118130 || plot_index == Settings::DZH_M4L118130 || plot_index == Settings::DWH || plot_index == Settings::DZH  )
   {
      legend  = CreateLegendVH("right",histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VH],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][fs][cat]);
   }
   else
   {
      legend = CreateLegend((plot_index == Settings::MZ1 || plot_index == Settings::MZ1_M4L118130 || plot_index == Settings::MZ2 || plot_index == Settings::KD_M4L118130)?"left":"right",histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][fs][cat]);
   }

   legend->Draw();
   
   TPaveText *text;
   if ( plot_index == Settings::D1jet_M4L118130 || plot_index == Settings::KD_M4L118130    || plot_index == Settings::MZ1_M4L118130 )
   {
      text = CreateCutText("left under legend", "118 < m_{4#font[12]{l}} < 130 GeV");
   }
   else if ( plot_index == Settings::D2jet_M4L118130 || plot_index == Settings::DWH_M4L118130 || plot_index == Settings::DZH_M4L118130 ||  plot_index == Settings::MZ2_M4L118130)
   {
      text = CreateCutText("right under legend", "118 < m_{4#font[12]{l}} < 130 GeV");
   }
   text->Draw();
   
   // Draw lumi
   CMS_lumi *lumi = new CMS_lumi;
   lumi->set_lumi(c, _lumi, 0);
   
   // Draw X-axis log scale
   if ( plot_index == Settings::M4lMain )
   {
      stack->GetXaxis()->SetNdivisions(10);
      stack->GetXaxis()->SetLabelSize(0);
      DrawLogX(c, cat);
   }

   stringstream ss;
   ss << folder << "/" << variable_name << "_" << filename << "_" << _s_final_state.at(fs) << "_" << _s_category.at(cat);

   SavePlots ( c, ss.str() );

}
//========================================================================================================



//=====================================================================================
void Histograms::Plot1D_allCAT( TString filename, TString variable_name , TString folder )
{
   int plot_index = SetPlotName( variable_name);
   
   gStyle->SetPadLeftMargin(0.10);
   gStyle->SetPadRightMargin(0.01);
   
   
   TCanvas *c = new TCanvas(variable_name, variable_name, 650, 500);

   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
       
   for( int i_cat = Settings::inclusive; i_cat >= 0; i_cat--)
   {  
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125]->SetFillColor(1180);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ]->SetFillColor(851);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ]->SetFillColor(858);
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass") histos_1D_ZX_shape[plot_index][Settings::fs4l][i_cat]->SetFillColor(411);
      else histos_1D_ZX[plot_index][Settings::fs4l][i_cat]->SetFillColor(411);

      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125]->SetLineColor(633);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ]->SetLineColor(602);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ]->SetLineColor(602);
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass") histos_1D_ZX_shape[plot_index][Settings::fs4l][i_cat]->SetLineColor(420);
      else histos_1D_ZX[plot_index][Settings::fs4l][i_cat]->SetLineColor(420);
      
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.7);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(20);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetBinErrorOption(TH1::kPoisson);
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->SetLineColor(kBlack);
      
      THStack *stack = new THStack( "stack", "stack" );
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass") stack->Add(histos_1D_ZX_shape[plot_index][Settings::fs4l][i_cat]);
      else stack->Add(histos_1D_ZX[plot_index][Settings::fs4l][i_cat]);
      stack->Add(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ]);
      stack->Add(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ]);
      stack->Add(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125]);
      
      stack->Draw("HIST");  

      float data_max = histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetBinContent(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      float data_max_error = histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetBinErrorUp(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      
      if( GetVarLogY( variable_name) )
      {
         stack->SetMinimum(0.5);
         stack->SetMaximum((data_max + data_max_error)*100);
      }
      
      else
      {
         stack->SetMinimum(1e-5);
         stack->SetMaximum((data_max + data_max_error)*1.1);
      }

      stack->GetXaxis()->SetTitle(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetXaxis()->GetTitle());
      stack->GetXaxis()->SetTitleSize(0.05);
      stack->GetXaxis()->SetLabelSize(0.05);
      stack->GetYaxis()->SetTitle(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
      stack->GetYaxis()->SetTitleSize(0.05);
      stack->GetYaxis()->SetLabelSize(0.05);
      
      stack->GetXaxis()->SetTitleOffset(1.2);
      stack->GetYaxis()->SetTitleOffset(1.);
      
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->Draw("SAME p E1 X0");

      TLegend *legend;
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass" || variable_name == "MZ2_M4L118130")
      {
        legend  = CreateLegend("right",histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX_shape[plot_index][Settings::fs4l][i_cat]);
      }
      
      else
      {
         legend = CreateLegend("right",histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][Settings::fs4l][i_cat]);
      }
      legend->Draw();
      
      TPaveText *text;
      if ( (plot_index == Settings::M4lMainZoomed || plot_index == Settings::M4lMain ) && i_cat != Settings::inclusive)
      {
         text = CreateCatText("top left", _s_category_label.at(i_cat));
         text->Draw();
      }
      
      
      // Draw lumi
      CMS_lumi *lumi = new CMS_lumi;
      lumi->set_lumi(c, _lumi, 0);
      
      // Draw X-axis log scale
      if ( plot_index == Settings::M4lMain )
      {
         stack->GetXaxis()->SetNdivisions(10);
         stack->GetXaxis()->SetLabelSize(0);
         DrawLogX(c, i_cat);
      }
      
      stringstream ss;
      ss << folder << "/" << variable_name << "_" <<filename << "_" << _s_final_state.at(Settings::fs4l) << "_" << _s_category.at(i_cat);

      SavePlots ( c, ss.str() );
      
   }
   delete c;
}
//=====================================================================================



//=====================================================================================
void Histograms::Plot1D_allFS( TString filename, TString variable_name , TString folder )
{
   int plot_index = SetPlotName( variable_name);
   
   gStyle->SetPadLeftMargin(0.10);
   gStyle->SetPadRightMargin(0.01);
   
   TCanvas *c = new TCanvas(variable_name, variable_name, 650, 500);
   
   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
   
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      if( i_fs == Settings::fs2mu2e) continue;
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::H125]->SetFillColor(1180);
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::qqZZ]->SetFillColor(851);
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::ggZZ]->SetFillColor(858);
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass") histos_1D_ZX_shape[plot_index][i_fs][Settings::inclusive]->SetFillColor(411);
      else histos_1D_ZX[plot_index][i_fs][Settings::inclusive]->SetFillColor(411);
      
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::H125]->SetLineColor(633);
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::qqZZ]->SetLineColor(602);
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::ggZZ]->SetLineColor(602);
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass") histos_1D_ZX_shape[plot_index][i_fs][Settings::inclusive]->SetLineColor(420);
      else histos_1D_ZX[plot_index][i_fs][Settings::inclusive]->SetLineColor(420);
      
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.7);
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->SetMarkerStyle(20);
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->SetBinErrorOption(TH1::kPoisson);
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->SetLineColor(kBlack);
      
      THStack *stack = new THStack( "stack", "stack" );
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass") stack->Add(histos_1D_ZX_shape[plot_index][i_fs][Settings::inclusive]);
      else stack->Add(histos_1D_ZX[plot_index][i_fs][Settings::inclusive]);
      stack->Add(histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::ggZZ]);
      stack->Add(histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::qqZZ]);
      stack->Add(histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::H125]);
      
      stack->Draw("HIST");
      
      float data_max = histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->GetBinContent(histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      float data_max_error = histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->GetBinErrorUp(histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->GetMaximumBin());
      
      if( GetVarLogY( variable_name) )
      {
         stack->SetMinimum(0.5);
         stack->SetMaximum((data_max + data_max_error)*100);
      }
      
      else
      {
         stack->SetMinimum(1e-5);
         stack->SetMaximum((data_max + data_max_error)*1.1);
      }
      
      if ( (plot_index == Settings::M4lMain || plot_index == Settings::M4lMainZoomed) && i_fs == Settings::fs4e) _fs_label = "m_{4#font[12]{e}} (GeV)";
      if ( (plot_index == Settings::M4lMain || plot_index == Settings::M4lMainZoomed) && i_fs == Settings::fs4mu) _fs_label = "m_{4#font[12]{#mu}} (GeV)";
      if ( (plot_index == Settings::M4lMain || plot_index == Settings::M4lMainZoomed) && i_fs == Settings::fs2e2mu) _fs_label = "m_{2#font[12]{e}2#font[12]{#mu}} (GeV)";
      stack->GetXaxis()->SetTitle(((plot_index == Settings::M4lMain || plot_index == Settings::M4lMainZoomed) && i_fs != Settings::fs4l ) ? _fs_label : (TString)histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->GetXaxis()->GetTitle());
      stack->GetXaxis()->SetTitleSize(0.05);
      stack->GetXaxis()->SetLabelSize(0.05);
      stack->GetYaxis()->SetTitle(histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
      stack->GetYaxis()->SetTitleSize(0.05);
      stack->GetYaxis()->SetLabelSize(0.05);
      
      stack->GetXaxis()->SetTitleOffset(1.2);
      stack->GetYaxis()->SetTitleOffset(1.);
      
      histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->Draw("SAME p E1 X0");
      
      TLegend *legend;
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass")
      {
         legend  = CreateLegend("right",histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data],histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::H125],histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX_shape[plot_index][i_fs][Settings::inclusive]);
      }
      
      else
      {
         legend = CreateLegend("right",histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data],histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::H125],histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][i_fs][Settings::inclusive]);
      }
      legend->Draw();
      
      // Draw lumi
      CMS_lumi *lumi = new CMS_lumi;
      lumi->set_lumi(c, _lumi, 0);
      
      // Draw X-axis log scale
      if ( plot_index == Settings::M4lMain )
      {
         stack->GetXaxis()->SetNdivisions(10);
         stack->GetXaxis()->SetLabelSize(0);
         DrawLogX(c, i_fs);
      }
      
      stringstream ss;
      ss << folder << "/" << variable_name << "_" <<filename << "_" << _s_final_state.at(i_fs) << "_" << _s_category.at(Settings::inclusive);

      SavePlots ( c, ss.str() );
   }
   delete c;
}
//=====================================================================================



//========================================================================================================
void Histograms::Plot2D_single( TString filename, TString variable_name, TString folder, int cat )
{
   int plot_index = SetPlotName( variable_name);

   gStyle->SetPadLeftMargin(0.12);
   gStyle->SetPadRightMargin(0.14);

   TCanvas *c = new TCanvas(variable_name, variable_name, 650, 500);
   
   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
   
   // Plot MC histogram
   TH2F* stack;
   stack = (TH2F*)histos_2D[plot_index][Settings::fs4l][cat][Settings::all_resonant][Settings::H125]->Clone();
   stack->Add(histos_2D[plot_index][Settings::fs4l][cat][Settings::all_resonant][Settings::qqZZ]);
   stack->Add(histos_2D[plot_index][Settings::fs4l][cat][Settings::all_resonant][Settings::ggZZ]);
   
   stack->GetXaxis()->SetTitleOffset(1.2);
   stack->GetYaxis()->SetTitleOffset(1.4);
   stack->GetZaxis()->SetTitleOffset(1.15);

   stack->SetMinimum(+1e-10);
   MakeCOLZGrey(true);
   stack->Draw("COLZ");

   //Plot data histograms
   histos_2D[plot_index][Settings::fs2e2mu][cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(21);
   histos_2D[plot_index][Settings::fs2e2mu][cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.9);
   histos_2D[plot_index][Settings::fs2e2mu][cat][Settings::all_resonant][Settings::Data]->SetMarkerColor(kBlue);
   histos_2D[plot_index][Settings::fs2e2mu][cat][Settings::all_resonant][Settings::Data]->SetLineColor(kBlue);
   
   histos_2D[plot_index][Settings::fs2e2mu][cat][Settings::all_resonant][Settings::Data]->Draw("SAME XP");
   
   histos_2D[plot_index][Settings::fs4mu][cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(20);
   histos_2D[plot_index][Settings::fs4mu][cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.9);
   histos_2D[plot_index][Settings::fs4mu][cat][Settings::all_resonant][Settings::Data]->SetMarkerColor(kRed+1);
   histos_2D[plot_index][Settings::fs4mu][cat][Settings::all_resonant][Settings::Data]->SetLineColor(kRed+1);
   
   histos_2D[plot_index][Settings::fs4mu][cat][Settings::all_resonant][Settings::Data]->Draw("SAME XP");
   
   histos_2D[plot_index][Settings::fs4e][cat][Settings::all_resonant][Settings::Data]->SetMarkerStyle(22);
   histos_2D[plot_index][Settings::fs4e][cat][Settings::all_resonant][Settings::Data]->SetMarkerSize(0.9);
   histos_2D[plot_index][Settings::fs4e][cat][Settings::all_resonant][Settings::Data]->SetMarkerColor(kGreen+2);
   histos_2D[plot_index][Settings::fs4e][cat][Settings::all_resonant][Settings::Data]->SetLineColor(kGreen+2);
   
   histos_2D[plot_index][Settings::fs4e][cat][Settings::all_resonant][Settings::Data]->Draw("SAME XP");

   //Draw legend
   TLegend *legend;
   legend = Create2DLegend("left",histos_2D[plot_index][Settings::fs4e][cat][Settings::all_resonant][Settings::Data],histos_2D[plot_index][Settings::fs4mu][cat][Settings::all_resonant][Settings::Data],histos_2D[plot_index][Settings::fs2e2mu][cat][Settings::all_resonant][Settings::Data]);
   legend->Draw();

   //----- adjust color axis
   c->Update();
   TPaletteAxis* pal = (TPaletteAxis*)stack->GetListOfFunctions()->FindObject("palette");
   pal->SetX1NDC(0.875);
   pal->SetX2NDC(0.90);
   
   // Draw lumi
   CMS_lumi *lumi = new CMS_lumi;
   lumi->set_lumi(c, _lumi, 0);
   
   stringstream ss;
   ss << folder << "/" << variable_name << "_" << filename << "_" << _s_category.at(cat);
   
   SavePlots ( c, ss.str() );
   
}
//========================================================================================================



//========================================================================================================
void Histograms::Plot2DError_single( TString filename, TString variable_name, TString folder, int cat )
{
   int plot_index = SetPlotName( variable_name);
   
   gStyle->SetPadLeftMargin(0.12);
   gStyle->SetPadRightMargin(0.14);
   gStyle->SetEndErrorSize(0.);
   
   TCanvas *c = new TCanvas(variable_name, variable_name, 650, 500);
   
   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
   
   // Plot MC histogram
   TH2F* stack;
   stack = (TH2F*)histos_2DError[plot_index][Settings::fs4l][cat][Settings::all_resonant][Settings::H125]->Clone();
   stack->Add(histos_2DError[plot_index][Settings::fs4l][cat][Settings::all_resonant][Settings::qqZZ]);
   stack->Add(histos_2DError[plot_index][Settings::fs4l][cat][Settings::all_resonant][Settings::ggZZ]);
   
   stack->GetXaxis()->SetTitleOffset(1.2);
   stack->GetYaxis()->SetTitleOffset(1.4);
   stack->GetZaxis()->SetTitleOffset(1.15);
   
   MakeCOLZGrey(false);
   stack->Draw("COLZ");
   
   //Plot data histograms
   histos_2DError_data[plot_index][Settings::fs2e2mu][cat]->SetMarkerStyle(21);
   histos_2DError_data[plot_index][Settings::fs2e2mu][cat]->SetMarkerSize(0.7);
   histos_2DError_data[plot_index][Settings::fs2e2mu][cat]->SetMarkerColor(kBlue);
   histos_2DError_data[plot_index][Settings::fs2e2mu][cat]->SetLineColor(kBlue);
   
   histos_2DError_data[plot_index][Settings::fs2e2mu][cat]->Draw("SAME P");
   
   histos_2DError_data[plot_index][Settings::fs4mu][cat]->SetMarkerStyle(20);
   histos_2DError_data[plot_index][Settings::fs4mu][cat]->SetMarkerSize(0.7);
   histos_2DError_data[plot_index][Settings::fs4mu][cat]->SetMarkerColor(kRed+1);
   histos_2DError_data[plot_index][Settings::fs4mu][cat]->SetLineColor(kRed+1);
   
   histos_2DError_data[plot_index][Settings::fs4mu][cat]->Draw("SAME P");
   
   histos_2DError_data[plot_index][Settings::fs4e][cat]->SetMarkerStyle(22);
   histos_2DError_data[plot_index][Settings::fs4e][cat]->SetMarkerSize(0.7);
   histos_2DError_data[plot_index][Settings::fs4e][cat]->SetMarkerColor(kGreen+2);
   histos_2DError_data[plot_index][Settings::fs4e][cat]->SetLineColor(kGreen+2);
   
   histos_2DError_data[plot_index][Settings::fs4e][cat]->Draw("SAME P");
   
   //Draw legend
   TLegend *legend;
   legend = Create2DErrorLegend("right",histos_2DError_data[plot_index][Settings::fs4e][cat],histos_2DError_data[plot_index][Settings::fs4mu][cat],histos_2DError_data[plot_index][Settings::fs2e2mu][cat]);
   legend->Draw();
   
   //----- adjust color axis
   c->Update();
   TPaletteAxis* pal = (TPaletteAxis*)stack->GetListOfFunctions()->FindObject("palette");
   pal->SetX1NDC(0.875);
   pal->SetX2NDC(0.90);
   pal->SetY2NDC(0.78);
   
   // Draw lumi
   CMS_lumi *lumi = new CMS_lumi;
   lumi->set_lumi(c, _lumi, 0);
   
   stringstream ss;
   ss << folder << "/" << variable_name << "_" << filename << "_" << _s_category.at(cat);
   
   SavePlots ( c, ss.str() );
   
}
//========================================================================================================



//===========================================================================================
void Histograms::Plot2DErrorAllCat( TString filename, TString variable_name, TString folder )
{
   int plot_index = SetPlotName( variable_name);
   
   gStyle->SetPadLeftMargin(0.12);
   gStyle->SetPadRightMargin(0.14);
   gStyle->SetEndErrorSize(0.);
   
   TCanvas *c = new TCanvas(variable_name, variable_name, 650, 500);
   
   if ( GetVarLogX( variable_name) ) c->SetLogx();
   if ( GetVarLogY( variable_name) ) c->SetLogy();
   
   // Plot MC histogram
   TH2F* stack;
   stack = (TH2F*)histos_2DError[plot_index][Settings::fs4l][Settings::inclusive][Settings::all_resonant][Settings::H125]->Clone();
   stack->Add(histos_2DError[plot_index][Settings::fs4l][Settings::inclusive][Settings::all_resonant][Settings::qqZZ]);
   stack->Add(histos_2DError[plot_index][Settings::fs4l][Settings::inclusive][Settings::all_resonant][Settings::ggZZ]);
   
   stack->GetXaxis()->SetTitleOffset(1.2);
   stack->GetYaxis()->SetTitleOffset(1.4);
   stack->GetZaxis()->SetTitleOffset(1.15);
   
   MakeCOLZGrey(false);
   stack->Draw("COLZ");
   
   //Plot data histograms
   for (int i_fs = 0; i_fs < Settings::fs4l; i_fs++)
   {
      histos_2DError_data[plot_index][i_fs][Settings::untagged]->SetMarkerStyle(20);
      histos_2DError_data[plot_index][i_fs][Settings::untagged]->SetMarkerSize(0.7);
      
      histos_2DError_data[plot_index][i_fs][Settings::VBF_1j_tagged]->SetMarkerStyle(26);
      histos_2DError_data[plot_index][i_fs][Settings::VBF_1j_tagged]->SetMarkerSize(0.7);
  
      histos_2DError_data[plot_index][i_fs][Settings::VBF_2j_tagged]->SetMarkerStyle(32);
      histos_2DError_data[plot_index][i_fs][Settings::VBF_2j_tagged]->SetMarkerSize(0.7);
        
      histos_2DError_data[plot_index][i_fs][Settings::VH_lepton_tagged]->SetMarkerStyle(28);
      histos_2DError_data[plot_index][i_fs][Settings::VH_lepton_tagged]->SetMarkerSize(0.7);
              
      histos_2DError_data[plot_index][i_fs][Settings::VH_hadron_tagged]->SetMarkerStyle(27);
      histos_2DError_data[plot_index][i_fs][Settings::VH_hadron_tagged]->SetMarkerSize(0.7);
  
      histos_2DError_data[plot_index][i_fs][Settings::ttH_tagged]->SetMarkerStyle(30);
      histos_2DError_data[plot_index][i_fs][Settings::ttH_tagged]->SetMarkerSize(0.7);
  
      histos_2DError_data[plot_index][i_fs][Settings::VH_MET_tagged]->SetMarkerStyle(25);
      histos_2DError_data[plot_index][i_fs][Settings::VH_MET_tagged]->SetMarkerSize(0.7);
   }
   
   for (int i_cat = 0; i_cat < Settings::inclusive; i_cat++)
   {
      
      histos_2DError_data[plot_index][Settings::fs4e][i_cat]->SetMarkerColor(kGreen);
      histos_2DError_data[plot_index][Settings::fs4e][i_cat]->SetLineColor(kGreen);  
 
      histos_2DError_data[plot_index][Settings::fs4mu][i_cat]->SetMarkerColor(kRed);
      histos_2DError_data[plot_index][Settings::fs4mu][i_cat]->SetLineColor(kRed); 
      
      histos_2DError_data[plot_index][Settings::fs2e2mu][i_cat]->SetMarkerColor(kBlue);
      histos_2DError_data[plot_index][Settings::fs2e2mu][i_cat]->SetLineColor(kBlue);   
   }
      
   for (int i_fs = 0; i_fs < Settings::fs4l; i_fs++)
   {   
      for (int i_cat = 0; i_cat < Settings::inclusive; i_cat++)
      {
         histos_2DError_data[plot_index][i_fs][i_cat]->Draw("SAME P");
      }
   }
   
   
   //Draw legend
   TLegend *legend;
   legend = Create2DErrorLegend("right",histos_2DError_data[plot_index][Settings::fs4e][Settings::untagged],histos_2DError_data[plot_index][Settings::fs4mu][Settings::untagged],histos_2DError_data[plot_index][Settings::fs2e2mu][Settings::untagged]);
   legend->Draw();
   
   // Adjust axis color
   c->Update();
   TPaletteAxis* pal = (TPaletteAxis*)stack->GetListOfFunctions()->FindObject("palette");
   pal->SetX1NDC(0.875);
   pal->SetX2NDC(0.90);
   pal->SetY2NDC(0.78);
   
   // Draw lumi
   CMS_lumi *lumi = new CMS_lumi;
   lumi->set_lumi(c, _lumi, 0);
   
   TString out_file_name;
   out_file_name = folder + "/" + variable_name + "_" + filename + "_" + "all_categories";
   
   c->SaveAs(out_file_name + ".pdf");
   c->SaveAs(out_file_name + ".png");
   c->SaveAs(out_file_name + ".root");
//   c->SaveAs(out_file_name + ".C"); why does it segfault here???
   c->SaveAs(out_file_name + ".eps");
   
}
//===========================================================================================



//========================================================================================================
void Histograms::FillYieldGraphs( float M4l_down, float M4l_up)
{ 
   TFile *f_signal_fits = new TFile("Signal_fits.root", "recreate");
   
   gStyle->SetOptFit(0);
   
   TPaveText* pav = new TPaveText(0.13,0.93,0.8,1.,"brNDC");
   pav->SetFillStyle(0);
   pav->SetBorderSize(0);
   pav->SetTextAlign(11);
   pav->SetTextSize(0.04);
   
   TLegend* lgd;
   lgd = new TLegend(0.2,0.73,0.4,0.88);
   lgd->SetFillStyle(0);
   
   
   
   int process = 0;
   double temp_yield;
   double temp_error;
   vector<double> yield;
   vector<double> error;
   
   int fs_marker[num_of_final_states] = {20, 22, 21, 33, 29};
   Color_t catColor[num_of_categories] = {kBlue-9, kCyan-6, kGreen-6, kRed-7, kOrange+6, kMagenta-6, kYellow - 3 ,kBlack};
   
   for ( int i_prod_mode = 0; i_prod_mode < num_of_production_modes; i_prod_mode++ )
   {      
      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         cout << endl;
         
         for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
         {
            if( i_fs == Settings::fs2mu2e ) continue;
            
            cout << _s_production_mode.at(i_prod_mode) << " " << _s_category.at(i_cat) << " " << _s_final_state.at(i_fs);
               
            for( int i_mass_point = 0; i_mass_point < 5; i_mass_point++)
            {
               process = SetProcess(i_mass_point, i_prod_mode);
               
               if ( process == Settings::yH124WH || process == Settings::yH124ttH ) continue;
                  
               temp_yield = histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][process]->IntegralAndError(
                            histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][process]->FindBin(M4l_down),
                            histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][process]->FindBin(M4l_up) - 1, temp_error);
               
               cout << " " << temp_yield;
               
               yield.push_back(temp_yield);
               error.push_back(temp_error);
               mass_points.push_back(SetMassPoint(i_mass_point));                  
            
            } // i_mass_point
            
            cout << endl;
            
            yields_graph[i_fs][i_cat][i_prod_mode] = new TGraphErrors(yield.size(), &(mass_points[0]), &(yield[0]), 0, &(error[0]));
            
            yield.clear();
            error.clear();
            mass_points.clear();
            
            // Cosmetics
            yields_graph[i_fs][i_cat][i_prod_mode]->GetXaxis()->SetLimits( 115, 135);
            yields_graph[i_fs][i_cat][i_prod_mode]->SetMinimum(0.);
            yields_graph[i_fs][i_cat][i_prod_mode]->SetMarkerStyle(22);
            yields_graph[i_fs][i_cat][i_prod_mode]->SetMarkerSize(3);
            yields_graph[i_fs][i_cat][i_prod_mode]->GetXaxis()->SetTitle("generated m_{H}");
            yields_graph[i_fs][i_cat][i_prod_mode]->GetYaxis()->SetTitle(Form("expected yield in %.1f fb^{-1}", _lumi));
            yields_graph[i_fs][i_cat][i_prod_mode]->SetMarkerStyle(fs_marker[i_fs]);
            yields_graph[i_fs][i_cat][i_prod_mode]->SetMarkerColor(catColor[i_cat]);
            yields_graph[i_fs][i_cat][i_prod_mode]->SetLineColor(kBlack);
            yields_graph[i_fs][i_cat][i_prod_mode]->SetLineWidth(2);

            
            // Set fit model
            TString fit_model;
            fit_model = "pol2";
            if (i_cat == Settings::VH_lepton_tagged && i_prod_mode != Settings::WH) fit_model = "pol1";
            if (i_cat == Settings::VH_hadron_tagged) fit_model = "pol1";
            if (i_cat == Settings::ttH_tagged) fit_model = "pol1";
            if (i_cat == Settings::VH_MET_tagged) fit_model = "pol1";
            if (i_prod_mode == Settings::ttH) fit_model = "pol1";
            if (i_prod_mode == Settings::WH && i_cat == Settings::VBF_2j_tagged && i_fs == Settings::fs4e) fit_model = "pol1";
            if (i_prod_mode == Settings::ZH && i_cat == Settings::VBF_1j_tagged && i_fs == Settings::fs4e) fit_model = "pol1";
            if (i_prod_mode == Settings::ZH && i_cat == Settings::VBF_1j_tagged && i_fs == Settings::fs4mu) fit_model = "pol1";    
            if (i_prod_mode == Settings::ttH && i_cat == Settings::untagged && i_fs == Settings::fs2e2mu) fit_model = "pol2";
            if (i_prod_mode == Settings::ttH && i_cat == Settings::ttH_tagged) fit_model = "pol2";
            if (i_prod_mode == Settings::ZH && i_cat == Settings::VBF_2j_tagged) fit_model = "pol1";    
                        
            TF1 *fit_function = new TF1("fit_function", fit_model, 119, 131);
            fit_function->SetLineColor(catColor[i_cat]);
            fit_function->SetLineWidth(2);
            
            yields_graph[i_fs][i_cat][i_prod_mode]->Fit(fit_function, "R");
         
            _fit_funct_name = "f_" + _s_production_mode.at(i_prod_mode) + "_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat);
            fit_function->SetName(_fit_funct_name);
            fit_function->Write();
            
             _graph_name = "g_" + _s_production_mode.at(i_prod_mode) + "_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat);
            yields_graph[i_fs][i_cat][i_prod_mode]->SetName(_graph_name);
            yields_graph[i_fs][i_cat][i_prod_mode]->Write();
            
            lgd->AddEntry(yields_graph[i_fs][i_cat][i_prod_mode],_s_final_state[i_fs].c_str(),"P");
            
         } // i_fs 
         
            TCanvas *c = new TCanvas("", "", 1500, 1500);
            
            pav->AddText((_s_production_mode[i_prod_mode] + ", " + _s_category[i_cat]).c_str());
            
            yields_graph[Settings::fs2e2mu][i_cat][i_prod_mode]->Draw("AP");
            yields_graph[Settings::fs4e][i_cat][i_prod_mode]->Draw("P");
            yields_graph[Settings::fs4mu][i_cat][i_prod_mode]->Draw("P");
            pav->Draw();
            lgd->Draw();
            
            TString fit_name = _s_production_mode.at(i_prod_mode) + "_" + _s_category.at(i_cat);
            c->SaveAs("Fits/" + fit_name + ".pdf");
            c->SaveAs("Fits/" + fit_name + ".eps");
            c->SaveAs("Fits/" + fit_name + ".png");
            c->SaveAs("Fits/" + fit_name + ".root");
            c->SaveAs("Fits/" + fit_name + ".C");
            
            pav->Clear();    
            lgd->Clear();
            
      } // i_cat
   } // i_prod_mode
   
   f_signal_fits->Close();
   delete f_signal_fits;
}
//========================================================================================================



//========================================================================================================
void Histograms::PrepareYamlFiles( TString sqrt, float M4l_down, float M4l_up, vector< vector <float> > _expected_yield_SR)
{
   
   TString out_file_name[Settings::fs4l];
   ofstream out_file[Settings::fs4l];
   
   TFile *f_signal_fits;
   f_signal_fits = TFile::Open("Signal_fits.root");
   
   TF1* fit_function;
   M4lZX *ZXYields = new M4lZX();
   
   int num_of_parameters;
  
   for ( int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++ )
   {
      if( i_fs == Settings::fs2mu2e ) continue;
      
      out_file_name[i_fs] = "yields_per_tag_category_" + sqrt + "_TeV_" + _s_final_state.at(i_fs) + ".yaml";
      out_file[i_fs].open(out_file_name[i_fs]);
    
      out_file[i_fs] << "---" << endl;
      out_file[i_fs] << "# sqrt(s) = " << sqrt << " TeV" << endl;
      out_file[i_fs] << "# integrated luminosity = " << _lumi << " fb-1" << endl;
      out_file[i_fs] << endl;
      out_file[i_fs] << "mass_range: '" << M4l_down << ", " << M4l_up << "'" << endl;
      out_file[i_fs] << "kd_range: '0, 1'"<<endl;
      out_file[i_fs] << endl;

      for ( int i_cat = 0; i_cat < num_of_categories - 1; i_cat++ )
      {
         out_file[i_fs] << _s_category.at(i_cat) << ":" << endl;

         for ( int i_prod_mode = 0; i_prod_mode < num_of_production_modes; i_prod_mode++ )
         {
            out_file[i_fs] << _s_production_mode.at(i_prod_mode) << ": ";
            
            _fit_funct_name = "f_" + _s_production_mode.at(i_prod_mode) + "_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat);
            fit_function = (TF1*)f_signal_fits->Get(_fit_funct_name);
            num_of_parameters = fit_function->GetNpar();
            
            for ( int i_par = 0; i_par <= 2; i_par++ )
            {
               double parameter = 0;
               if(i_par < num_of_parameters) parameter = fit_function->GetParameter(i_par);
               
               out_file[i_fs] << "(" << (parameter);
               
               for ( int i_par_2 = 0; i_par_2 <= i_par-1; i_par_2++)
                  out_file[i_fs] << "*@0";
               
               out_file[i_fs]<<")";
               
               if ( i_par < 2)
               {
                  out_file[i_fs] << "+";
               }
            }
            out_file[i_fs] << endl;
         }
         out_file[i_fs] << _s_process.at(Settings::yqqZZ) << ": '" << histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][Settings::yqqZZ]->Integral(
                                                                      histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][Settings::yqqZZ]->FindBin(M4l_down),
                                                                      histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][Settings::yqqZZ]->FindBin(M4l_up) - 1) << "'" << endl;
         
         out_file[i_fs] << _s_process.at(Settings::yggZZ) << ": '" << histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][Settings::yggZZ]->Integral(
                                                                     histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][Settings::yggZZ]->FindBin(M4l_down),
                                                                     histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][Settings::yggZZ]->FindBin(M4l_up) - 1) << "'" << endl;
         
         out_file[i_fs] << "zjets: '" << ZXYields->GetM4lZX_Yields(_expected_yield_SR, M4l_down, M4l_up, i_fs, i_cat) << endl;
         out_file[i_fs] << endl;
      
      } // end i_cat
   
      out_file[i_fs].close();
   
   } // end i_fs
}
//========================================================================================================
   



//========================================================================================================
void Histograms::PrintYields( vector< vector <float> > _expected_yield_SR)
{
   
   //cout << std::setprecision(2) << fixed;
   
   cout << endl;
   cout << "=========================" << endl;
   cout << "Yields in full mass range" << endl;
   cout << "=========================" << endl;
   cout << _s_final_state.at(0) << "   " << _s_final_state.at(1) << "   " << _s_final_state.at(2) << "   " << _s_final_state.at(4) << endl;
   
   for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
   {
      
      if (i_proc > Settings::yH130 && i_proc < Settings::yqqZZ || i_proc == Settings::yH120 || i_proc == Settings::yH124
          || i_proc == Settings::yH126 || i_proc == Settings::yH130 || i_proc == Settings::yDY || i_proc == Settings::yttbar) continue;
      
      cout << endl;
      
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         cout << _s_process.at(i_proc) << "   " << _s_category.at(i_cat) << "   ";
         
         for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
         {
            if( i_fs == Settings::fs2mu2e ) continue;
      
            cout << histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][i_proc]->Integral() << "   ";
         }
         cout << endl;
      }
   }
   
   // Z+X
   
   M4lZX *ZXYields = new M4lZX();
   
   cout << endl;
      
   for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
   {         
      cout << "Z+X" << "   " << _s_category.at(i_cat) << "   ";
               
      for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
      {
         if( i_fs == Settings::fs2mu2e ) continue;
         
          cout << ZXYields->GetM4lZX_Yields(_expected_yield_SR, 0, 3000, i_fs, i_cat) << "   ";
      }
      cout << endl;
   }
   
   delete ZXYields;
}
//========================================================================================================



//========================================================
void Histograms::PrintYields(float M4l_down, float M4l_up, vector< vector <float> > _expected_yield_SR)
{
   //cout << std::setprecision(2) << fixed;
   
   cout << endl;
   cout << "===============================" << endl;
   cout << "Yields in [" << M4l_down << ", " << M4l_up << "] mass range" << endl;
   cout << "===============================" << endl;
   cout << _s_final_state.at(0) << "   " << _s_final_state.at(1) << "   " << _s_final_state.at(2) << "   " << _s_final_state.at(4) << endl;
   
   for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
   {
      
      if (i_proc > Settings::yH130 && i_proc < Settings::yqqZZ || i_proc == Settings::yH120 || i_proc == Settings::yH124
          || i_proc == Settings::yH126 || i_proc == Settings::yH130 || i_proc == Settings::yDY || i_proc == Settings::yttbar) continue;
      
      cout << endl;
      
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         cout << _s_process.at(i_proc) << "   " << _s_category.at(i_cat) << "   ";
                  
         for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
         {
            if( i_fs == Settings::fs2mu2e ) continue;
      
            cout << histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][i_proc]->Integral(
                    histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][i_proc]->FindBin(M4l_down),
                    histos_1D[Settings::M4lYields][i_fs][i_cat][Settings::all_resonant][i_proc]->FindBin(M4l_up) - 1)
            << "   ";
         }
         cout << endl;
      }
   }
   
   // Z+X
   M4lZX *ZXYields = new M4lZX();
   
   cout << endl;
   
   for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
   {         
      cout << "Z+X" << "   " << _s_category.at(i_cat) << "   ";
            
      for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
      {
         if( i_fs == Settings::fs2mu2e ) continue;
         
         cout << ZXYields->GetM4lZX_Yields(_expected_yield_SR, M4l_down, M4l_up, i_fs, i_cat) << "   ";
      }
      cout << endl;
   }

   delete ZXYields;
}
//========================================================



//========================================================
void Histograms::PrintLatexTables(float M4l_down, float M4l_up, vector< vector <float> > _expected_yield_SR)
{
   cout << std::setprecision(2) << fixed;
   
   map<int, vector<float>> yields_map;
   vector<float> yields_ZX;
   float temp_yield;
   
   // Z+X
   M4lZX *ZXYields = new M4lZX();

   cout << endl << endl; 
   cout << "//==============" << endl;
   cout << "// T a b l e  1 " << endl;
   cout << "//==============" << endl;
   cout << endl;
   
//==============
// T a b l e  1
//==============
   
  for (int i_proc = 0; i_proc < num_of_processes_yields; i_proc++)
   {
      if (i_proc == Settings::yH125 || i_proc == Settings::yqqZZ || i_proc == Settings::yggZZ)
      {
         for (int i_fs = 0; i_fs < num_of_final_states; i_fs++)
         {
            if ( i_fs == Settings::fs2mu2e) continue;
            temp_yield = histos_1D[Settings::M4lYields][i_fs][Settings::inclusive][Settings::all_resonant][i_proc]->Integral();
            yields_map[i_proc].push_back(temp_yield);
         }
      }
   }
   
   // Z+X
   for (int i_fs = 0; i_fs < num_of_final_states; i_fs++)
   {
      if ( i_fs == Settings::fs2mu2e) continue;
      temp_yield = ZXYields->GetM4lZX_Yields(_expected_yield_SR, 30., 3000., i_fs, Settings::inclusive);
      yields_ZX.push_back(temp_yield);
   }

   
   cout << "\\begin{tabular}{l|c|c|c|c}" << endl;
   cout << "\\hline" << endl;
   cout << "\\hline" << endl;
   cout << "\\textbf{Channel} & $4\\Pe$ & $4\\Pgm$ & $2\\Pe2\\Pgm$ & $4\\ell$ \\\\" << endl;
   cout << "\\hline" << endl; 
   
   
   cout << "\\qqZZ ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yqqZZ].at(i_fs) << "^{+ y.y}_{- z.z}$ ";
   }   
   cout << "\\\\" << endl;
   
   cout << "\\ggZZ ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yggZZ].at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }   
   cout << "\\\\" << endl;
   
   cout << "\\cPZ\\ + X ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_ZX.at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }   
   cout << "\\\\" << endl;
       
   cout << "\\hline" << endl; 
   
   cout << "Sum of backgrounds ";      
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yqqZZ].at(i_fs) + yields_map[Settings::yggZZ].at(i_fs)+ yields_ZX.at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }
   cout << "\\\\" << endl;
      
   cout << "\\hline" << endl;
   
   cout << "Signal ($\\mH=125~\\GeV$) ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yH125].at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }   
   cout << "\\\\" << endl;   
   
   cout << "\\hline" << endl; 
   
   cout << "Total expected ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yH125].at(i_fs) + yields_map[Settings::yqqZZ].at(i_fs) + yields_map[Settings::yggZZ].at(i_fs)+ yields_ZX.at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }
   cout << "\\\\" << endl;
   
   cout << "\\hline" << endl;
   cout << "Observed & XXX & XXX & XXX & XXX \\\\" << endl;
   
   cout << "\\hline" << endl; 
   cout << "\\hline" << endl;
   cout << "\\end{tabular}" << endl; 

   
   cout << endl << endl; 
   cout << "//==============" << endl;
   cout << "// T a b l e  2 " << endl;
   cout << "//==============" << endl;
   cout << endl; 
   
//==============
// T a b l e  2
//==============   
   
   yields_map.clear();
   yields_ZX.clear();
   
     
   for (int i_proc = 0; i_proc < num_of_processes_yields; i_proc++)
   {
      if (i_proc == Settings::yH125 || i_proc == Settings::yqqZZ || i_proc == Settings::yggZZ)
      {
         for (int i_fs = 0; i_fs < num_of_final_states; i_fs++)
         {
            if ( i_fs == Settings::fs2mu2e) continue;
            temp_yield = histos_1D[Settings::M4lYields][i_fs][Settings::inclusive][Settings::all_resonant][i_proc]->Integral(
                         histos_1D[Settings::M4lYields][i_fs][Settings::inclusive][Settings::all_resonant][i_proc]->FindBin(M4l_down),
                         histos_1D[Settings::M4lYields][i_fs][Settings::inclusive][Settings::all_resonant][i_proc]->FindBin(M4l_up)-1);
            yields_map[i_proc].push_back(temp_yield);
         }
      }
   }
   
   // Z+X
   for (int i_fs = 0; i_fs < num_of_final_states; i_fs++)
   {
      if ( i_fs == Settings::fs2mu2e) continue;
      temp_yield = ZXYields->GetM4lZX_Yields(_expected_yield_SR, M4l_down, M4l_up, i_fs, Settings::inclusive);
      yields_ZX.push_back(temp_yield);
   }

   
   cout << "\\begin{tabular}{l|c|c|c|c}" << endl;
   cout << "\\hline" << endl;
   cout << "\\hline" << endl;
   cout << "\\textbf{Channel} & $4\\Pe$ & $4\\Pgm$ & $2\\Pe2\\Pgm$ & $4\\ell$ \\\\" << endl;
   cout << "\\hline" << endl; 
   
   
   cout << "\\qqZZ ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yqqZZ].at(i_fs) << "^{+ y.y}_{- z.z}$ ";
   }   
   cout << "\\\\" << endl;
   
   cout << "\\ggZZ ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yggZZ].at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }   
   cout << "\\\\" << endl;
   
   cout << "\\cPZ\\ + X ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_ZX.at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }   
   cout << "\\\\" << endl;
       
   cout << "\\hline" << endl; 
   
   cout << "Sum of backgrounds ";      
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yqqZZ].at(i_fs) + yields_map[Settings::yggZZ].at(i_fs)+ yields_ZX.at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }
   cout << "\\\\" << endl;
      
   cout << "\\hline" << endl;
   
   cout << "Signal ($\\mH=125~\\GeV$) ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yH125].at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }   
   cout << "\\\\" << endl;   
   
   cout << "\\hline" << endl; 
   
   cout << "Total expected ";
   for (int i_fs = 0; i_fs < num_of_final_states - 1; i_fs++)          
   {
      cout << "& $" << yields_map[Settings::yH125].at(i_fs) + yields_map[Settings::yqqZZ].at(i_fs) + yields_map[Settings::yggZZ].at(i_fs)+ yields_ZX.at(i_fs) << "$^{+ y.y}_{- z.z} ";
   }
   cout << "\\\\" << endl;
   
   cout << "\\hline" << endl;
   cout << "Observed & XXX & XXX & XXX & XXX \\\\" << endl;
   
   cout << "\\hline" << endl; 
   cout << "\\hline" << endl;
   cout << "\\end{tabular}" << endl;  
   
   
   cout << endl << endl; 
   cout << "//==============" << endl;
   cout << "// T a b l e  3 " << endl;
   cout << "//==============" << endl;
   cout << endl;  
   
//==============
// T a b l e  3
//==============
   
   yields_map.clear();
   yields_ZX.clear();
   double total;
    
   for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
   {
      for ( int i_proc = 0; i_proc < num_of_processes_yields; i_proc++ )
      {
         if (i_proc == Settings::yH125ggH || i_proc == Settings::yH125VBF || i_proc == Settings::yH125WH || i_proc == Settings::yH125ZH 
         || i_proc == Settings::yH125ttH || i_proc == Settings::yqqZZ || i_proc == Settings::yggZZ)
         {
            temp_yield = histos_1D[Settings::M4lYields][Settings::fs4l][i_cat][Settings::all_resonant][i_proc]->Integral(
                         histos_1D[Settings::M4lYields][Settings::fs4l][i_cat][Settings::all_resonant][i_proc]->FindBin(M4l_down),
                         histos_1D[Settings::M4lYields][Settings::fs4l][i_cat][Settings::all_resonant][i_proc]->FindBin(M4l_up) - 1);
         
            yields_map[i_cat].push_back(temp_yield);
         }
      }
   }
   
   // Z+X
   for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
   {
      temp_yield = ZXYields->GetM4lZX_Yields(_expected_yield_SR, M4l_down, M4l_up, Settings::fs4l, i_cat);
      yields_ZX.push_back(temp_yield);
   }
      
   
   cout << "\\begin{tabular}{c|ccccc|ccc|c|c}" << endl;
   cout << "\\hline" << endl;
   cout << "\\hline" << endl;
   cout << "Event & \\multicolumn{5}{c|}{Signal} & \\multicolumn{3}{c|}{Background} & Total & Observed \\\\" << endl;
   cout << "category & $\\ggH$ & VBF & WH & ZH & $\\ttH$ & \\qqZZ & \\ggZZ & \\cPZ\\ + X & expected & \\\\" << endl;
   cout << "\\hline" << endl; 
   
   
   cout << "Untagged ";
   total = 0;
   for ( int i_proc = 0; i_proc < yields_map[Settings::untagged].size(); i_proc++ )
   {
      cout << "& $" << yields_map[Settings::untagged].at(i_proc) << "$ ";
      total += yields_map[Settings::untagged].at(i_proc);
   }
   cout << "& $" << yields_ZX.at(Settings::untagged) << "& $" << total + yields_ZX.at(Settings::untagged) << "$ & XXX \\\\" << endl;
   
   
   cout << "VBF-1j ";
   total = 0;
   for ( int i_proc = 0; i_proc < yields_map[Settings::VBF_1j_tagged].size(); i_proc++ )
   {
      cout << "& $" << yields_map[Settings::VBF_1j_tagged].at(i_proc) << "$ ";
      total += yields_map[Settings::VBF_1j_tagged].at(i_proc);
   }
   cout << "& $" << yields_ZX.at(Settings::VBF_1j_tagged) << "& $" << total + yields_ZX.at(Settings::VBF_1j_tagged) << "$ & XXX \\\\" << endl;
   
   
   cout << "VBF-2j ";
   total = 0;
   for ( int i_proc = 0; i_proc < yields_map[Settings::VBF_2j_tagged].size(); i_proc++ )
   {
      cout << "& $" << yields_map[Settings::VBF_2j_tagged].at(i_proc) << "$ ";
      total += yields_map[Settings::VBF_2j_tagged].at(i_proc);
   }
   cout << "& $" << yields_ZX.at(Settings::VBF_2j_tagged) << "& $" << total + yields_ZX.at(Settings::VBF_1j_tagged) << "$ & XXX \\\\" << endl;
   
   
   cout << "VH-lept. ";
   total = 0;
   for ( int i_proc = 0; i_proc < yields_map[Settings::VH_lepton_tagged].size(); i_proc++ )
   {
      cout << "& $" << yields_map[Settings::VH_lepton_tagged].at(i_proc) << "$ ";
      total += yields_map[Settings::VH_lepton_tagged].at(i_proc);
   }
   cout << "& $" << yields_ZX.at(Settings::VH_lepton_tagged) << "& $" << total + yields_ZX.at(Settings::VH_lepton_tagged) << "$ & XXX \\\\" << endl;
   
   
   cout << "VH-hadr. ";
   total = 0;
   for ( int i_proc = 0; i_proc < yields_map[Settings::VH_hadron_tagged].size(); i_proc++ )
   {
      cout << "& $" << yields_map[Settings::VH_hadron_tagged].at(i_proc) << "$ ";
      total += yields_map[Settings::VH_hadron_tagged].at(i_proc);
   }
   cout << "& $" << yields_ZX.at(Settings::VH_hadron_tagged) << "& $" << total + yields_ZX.at(Settings::VH_hadron_tagged) << "$ & XXX \\\\" << endl;
   
   
   cout << "ttH ";
   total = 0;
   for ( int i_proc = 0; i_proc < yields_map[Settings::ttH_tagged].size(); i_proc++ )
   {
      cout << "& $" << yields_map[Settings::ttH_tagged].at(i_proc) << "$ ";
      total += yields_map[Settings::ttH_tagged].at(i_proc);
   }
   cout << "& $" << yields_ZX.at(Settings::ttH_tagged) << "& $" << total + yields_ZX.at(Settings::ttH_tagged) << "$ & XXX \\\\" << endl;
   
  
   cout << "VH-MET ";
   total = 0;
   for ( int i_proc = 0; i_proc < yields_map[Settings::VH_MET_tagged].size(); i_proc++ )
   {
      cout << "& $" << yields_map[Settings::VH_MET_tagged].at(i_proc) << "$ ";
      total += yields_map[Settings::VH_MET_tagged].at(i_proc);
   }
   cout << "& $" << yields_ZX.at(Settings::VH_MET_tagged) << "& $" << total + yields_ZX.at(Settings::VH_MET_tagged) << "$ & XXX \\\\" << endl;
   
   cout << "\\hline" << endl; 
   
   
   cout << "Total ";
   total = 0;
   for ( int i_proc = 0; i_proc < yields_map[Settings::inclusive].size(); i_proc++ )
   {
      cout << "& $" << yields_map[Settings::inclusive].at(i_proc) << "$ ";
      total += yields_map[Settings::inclusive].at(i_proc);
   }
   cout << "& $" << yields_ZX.at(Settings::inclusive) << "& $" << total + yields_ZX.at(Settings::inclusive) << "$ & XXX \\\\" << endl;
   
   cout << "\\hline" << endl;
   cout << "\\hline" << endl;
   cout << "\\end{tabular}" << endl;
   
   delete ZXYields;
}
//========================================================


//=======================================
void Histograms::SavePlots( TCanvas *c, string ss)
{
   c->SaveAs((ss + ".pdf").c_str());
   c->SaveAs((ss + ".root").c_str());
   c->SaveAs((ss + ".C").c_str());
   c->SaveAs((ss + ".eps").c_str());
   gSystem->Exec(("convert -density 150 -quality 100 "+ss+".eps "+ss+".png").c_str());
}
//=======================================

//==================================================
int Histograms::SetPlotName( TString variable_name )
{
   //=============
   // M4l
   //=============
   if ( variable_name == "M4lMain" )              return Settings::M4lMain;
   else if ( variable_name == "M4lMainZoomed" )   return Settings::M4lMainZoomed;
   else if ( variable_name == "M4lMainHighMass" )   return Settings::M4lMainHighMass;
   
   //=============
   // MZ1
   //=============
   else if ( variable_name == "MZ1" )             return Settings::MZ1;
   else if ( variable_name == "MZ1_M4L118130" )   return Settings::MZ1_M4L118130;
   
   //=============
   // MZ2
   //=============
   else if ( variable_name == "MZ2" )             return Settings::MZ2;
   else if ( variable_name == "MZ2_M4L118130" )   return Settings::MZ2_M4L118130;
   
   //=============
   // KD
   //=============
   else if ( variable_name == "KD" )              return Settings::KD;
   else if ( variable_name == "KD_M4L118130" )    return Settings::KD_M4L118130;
   else if ( variable_name == "D1jet" )           return Settings::D1jet;
   else if ( variable_name == "D1jet_M4L118130" ) return Settings::D1jet_M4L118130;
   else if ( variable_name == "D2jet" )           return Settings::D2jet;
   else if ( variable_name == "D2jet_M4L118130" ) return Settings::D2jet_M4L118130;
   else if ( variable_name == "DWH" )             return Settings::DWH;
   else if ( variable_name == "DWH_M4L118130" )   return Settings::DWH_M4L118130;
   else if ( variable_name == "DZH" )             return Settings::DZH;
   else if ( variable_name == "DZH_M4L118130" )   return Settings::DZH_M4L118130;
   
   //=============
   // MZ1vsMZ2
   //=============
   else if ( variable_name == "MZ1vsMZ2" )        return Settings::MZ1vsMZ2;
   else if ( variable_name == "MZ1vsMZ2_M4L118130" )return Settings::MZ1vsMZ2_M4L118130;
   
   //=============
   // KDvsM4l
   //=============
   else if ( variable_name == "KDvsM4l" )         return Settings::KDvsM4l;
   else if ( variable_name == "KDvsM4lZoomed" )   return Settings::KDvsM4lZoomed;
   else if ( variable_name == "KDvsM4lHighMass" ) return Settings::KDvsM4lHighMass;
   else if ( variable_name == "D1jetvsM4lZoomed" )return Settings::D1jetvsM4lZoomed;
   else if ( variable_name == "D2jetvsM4lZoomed" )return Settings::D2jetvsM4lZoomed;
   else if ( variable_name == "DWHvsM4lZoomed" )  return Settings::DWHvsM4lZoomed;
   else if ( variable_name == "DZHvsM4lZoomed" )  return Settings::DZHvsM4lZoomed;
   
   else
   {
      cout << "[ERROR] Wrong variable name choosen!" << endl;
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
   else if (variable_name == "M4lMainHighMass")  return bool(Variables::M4lMainHighMass().var_log_x);
   
   //=============
   // MZ1
   //=============
   else if (variable_name == "MZ1")              return bool(Variables::MZ1().var_log_x);
   else if (variable_name == "MZ1_M4L118130")    return bool(Variables::MZ1_M4L118130().var_log_x);
   
   //=============
   // MZ2
   //=============
   else if (variable_name == "MZ2")              return bool(Variables::MZ2().var_log_x);
   else if (variable_name == "MZ2_M4L118130")    return bool(Variables::MZ2_M4L118130().var_log_x);
   
   //=============
   // KD
   //=============
   else if (variable_name == "KD")               return bool(Variables::KD().var_log_x);
   else if (variable_name == "KD_M4L118130")     return bool(Variables::KD_M4L118130().var_log_x);
   else if (variable_name == "D1jet")            return bool(Variables::D1jet().var_log_x);
   else if (variable_name == "D1jet_M4L118130")  return bool(Variables::D1jet_M4L118130().var_log_x);
   else if (variable_name == "D2jet")            return bool(Variables::D2jet().var_log_x);
   else if (variable_name == "D2jet_M4L118130")  return bool(Variables::D2jet_M4L118130().var_log_x);
   else if (variable_name == "DWH")              return bool(Variables::DWH().var_log_x);
   else if (variable_name == "DWH_M4L118130")    return bool(Variables::DWH_M4L118130().var_log_x);
   else if (variable_name == "DZH")              return bool(Variables::DZH().var_log_x);
   else if (variable_name == "DZH_M4L118130")    return bool(Variables::DZH_M4L118130().var_log_x);
   
   //=============
   // MZ1vsMZ2
   //=============
   else if (variable_name == "MZ1vsMZ2")         return bool(Variables::MZ1vsMZ2().var_log_x);
   else if (variable_name == "MZ1vsMZ2_M4L118130")return bool(Variables::MZ1vsMZ2_M4L118130().var_log_x);
   
   //=============
   // KDvsM4l
   //=============
   else if (variable_name == "KDvsM4l")         return bool(Variables::KDvsM4l().var_log_x);
   else if (variable_name == "KDvsM4lZoomed")   return bool(Variables::KDvsM4lZoomed().var_log_x);
   else if (variable_name == "KDvsM4lHighMass") return bool(Variables::KDvsM4lHighMass().var_log_x);
   else if (variable_name == "D1jetvsM4lZoomed")return bool(Variables::D1jetvsM4lZoomed().var_log_x);
   else if (variable_name == "D2jetvsM4lZoomed")return bool(Variables::D2jetvsM4lZoomed().var_log_x);
   else if (variable_name == "DWHvsM4lZoomed")  return bool(Variables::DWHvsM4lZoomed().var_log_x);
   else if (variable_name == "DZHvsM4lZoomed")  return bool(Variables::DZHvsM4lZoomed().var_log_x);
   
   else
   {
      cout << "[ERROR] Wrong variable name choosen!" << endl;
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
   else if (variable_name == "M4lMainHighMass")  return bool(Variables::M4lMainHighMass().var_log_y);
   
   //=============
   // MZ1
   //=============
   else if (variable_name == "MZ1")              return bool(Variables::MZ1().var_log_y);
   else if (variable_name == "MZ1_M4L118130")    return bool(Variables::MZ1_M4L118130().var_log_y);
   
   //=============
   // MZ2
   //=============
   else if (variable_name == "MZ2")              return bool(Variables::MZ2().var_log_y);
   else if (variable_name == "MZ2_M4L118130")    return bool(Variables::MZ2_M4L118130().var_log_y);
   
   //=============
   // KD
   //=============
   else if (variable_name == "KD")               return bool(Variables::KD().var_log_y);
   else if (variable_name == "KD_M4L118130")     return bool(Variables::KD_M4L118130().var_log_y);
   else if (variable_name == "D1jet")            return bool(Variables::D1jet().var_log_y);
   else if (variable_name == "D1jet_M4L118130")  return bool(Variables::D1jet_M4L118130().var_log_y);
   else if (variable_name == "D2jet")            return bool(Variables::D2jet().var_log_y);
   else if (variable_name == "D2jet_M4L118130")  return bool(Variables::D2jet_M4L118130().var_log_y);
   else if (variable_name == "DWH")              return bool(Variables::DWH().var_log_y);
   else if (variable_name == "DWH_M4L118130")    return bool(Variables::DWH_M4L118130().var_log_y);
   else if (variable_name == "DZH")              return bool(Variables::DZH().var_log_y);
   else if (variable_name == "DZH_M4L118130")    return bool(Variables::DZH_M4L118130().var_log_y);
   
   //=============
   // MZ1vsMZ2
   //=============
   else if (variable_name == "MZ1vsMZ2")         return bool(Variables::MZ1vsMZ2().var_log_y);
   else if (variable_name == "MZ1vsMZ2_M4L118130")return bool(Variables::MZ1vsMZ2_M4L118130().var_log_y);
   
   //=============
   // KDvsM4l
   //=============
   else if (variable_name == "KDvsM4l")         return bool(Variables::KDvsM4l().var_log_y);
   else if (variable_name == "KDvsM4lZoomed")   return bool(Variables::KDvsM4lZoomed().var_log_y);
   else if (variable_name == "KDvsM4lHighMass") return bool(Variables::KDvsM4lHighMass().var_log_y);
   else if (variable_name == "D1jetvsM4lZoomed")return bool(Variables::D1jetvsM4lZoomed().var_log_y);
   else if (variable_name == "D2jetvsM4lZoomed")return bool(Variables::D2jetvsM4lZoomed().var_log_y);
   else if (variable_name == "DWHvsM4lZoomed")  return bool(Variables::DWHvsM4lZoomed().var_log_y);
   else if (variable_name == "DZHvsM4lZoomed")  return bool(Variables::DZHvsM4lZoomed().var_log_y);

   else
   {
      cout << "[ERROR] Wrong variable name choosen!" << endl;
      abort;
      return bool(Variables::M4lMain().var_log_y);
   }
}
//===================================================



//=========================================================================================================
TLegend* Histograms::CreateLegend( string position, TH1F *data, TH1F *h125,TH1F *qqZZ,TH1F *ggZZ,TH1F *ZX )
{
   TLegend *leg;
   if(position == "right") leg = new TLegend( .63, .62, .97, .9 );
   else if(position == "left") leg = new TLegend(.14,.62,.48,.9);
   leg->SetFillColor(0);
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
   
   leg->AddEntry( data, "Data", "p" );
   leg->AddEntry( h125,"H(125)","f");
   leg->AddEntry( qqZZ, "q#bar{q}#rightarrowZZ, Z#gamma*", "f" );
   leg->AddEntry( ggZZ, "gg#rightarrowZZ, Z#gamma*", "f" );
   leg->AddEntry( ZX, "Z+X", "f" );
   
   return leg;
}
//=========================================================================================================



//==============================================================================================================================
TLegend* Histograms::CreateLegendVBF( string position, TH1F *data, TH1F *h125VBF, TH1F *h125other,TH1F *qqZZ,TH1F *ggZZ,TH1F *ZX )
{
   TLegend *leg;
   if(position == "right") leg = new TLegend( .60, .62, .95, .9 );
   else if(position == "left") leg = new TLegend(.14,.62,.48,.9);
   leg->SetFillColor(0);
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
   
   leg->AddEntry( data, "Data", "p" );
   leg->AddEntry( h125VBF,"H(125), VBF","f");
   leg->AddEntry( h125other,"H(125), other","f");
   leg->AddEntry( qqZZ, "q#bar{q}#rightarrowZZ, Z#gamma*", "f" );
   leg->AddEntry( ggZZ, "gg#rightarrowZZ, Z#gamma*", "f" );
   leg->AddEntry( ZX, "Z+X", "f" );
   
   return leg;
}
//==============================================================================================================================



//==============================================================================================================================
TLegend* Histograms::CreateLegendVH( string position, TH1F *data, TH1F *h125VH, TH1F *h125other,TH1F *qqZZ,TH1F *ggZZ,TH1F *ZX )
{
   TLegend *leg;
   if(position == "right") leg = new TLegend( .60, .62, .95, .9 );
   else if(position == "left") leg = new TLegend(.14,.62,.48,.9);
   leg->SetFillColor(0);
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
   
   leg->AddEntry( data, "Data", "p" );
   leg->AddEntry( h125VH,"H(125), VH","f");
   leg->AddEntry( h125other,"H(125), other","f");
   leg->AddEntry( qqZZ, "q#bar{q}#rightarrowZZ, Z#gamma*", "f" );
   leg->AddEntry( ggZZ, "gg#rightarrowZZ, Z#gamma*", "f" );
   leg->AddEntry( ZX, "Z+X", "f" );
   
   return leg;
}
//==============================================================================================================================



//==========================================================================================
TLegend* Histograms::Create2DLegend( string position, TH2F *fs4e, TH2F *fs4mu,TH2F *fs2e2mu)
{
   TLegend *leg;
   if(position == "left") leg = new TLegend(0.14,0.82,0.27,0.94);
   
   leg->SetFillStyle(0);
   leg->SetBorderSize(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.032);
   leg->AddEntry(fs4e,"4e","p");
   leg->AddEntry(fs4mu,"4mu","p");
   leg->AddEntry(fs2e2mu,"2e2mu","p");
   leg->Draw();

   return leg;
}
//==========================================================================================



//=======================================================================================================================
TLegend* Histograms::Create2DErrorLegend( string position, TGraphErrors *fs4e, TGraphErrors *fs4mu,TGraphErrors *fs2e2mu)
{
   TLegend *leg;
   if(position == "right") leg = new TLegend(0.87,0.82,0.97,0.94);
   
   leg->SetFillStyle(0);
   leg->SetBorderSize(0);
   leg->SetTextFont(42);
   leg->SetTextSize(0.032);
   leg->AddEntry(fs4e,"4e","lp");
   leg->AddEntry(fs4mu,"4mu","lp");
   leg->AddEntry(fs2e2mu,"2e2mu","lp");
   leg->Draw();
   
   return leg;
}
//=======================================================================================================================


//=======================================================================================================================
TPaveText* Histograms::CreateCutText( string position, TString cut_label)
{
   TPaveText *pav;
   if (position == "left under legend")  pav = new TPaveText(.14, .55, .48, .61,"brNDC");
   if (position == "right under legend") pav = new TPaveText(.63, .55, .97, .61 ,"brNDC");
   pav->SetFillStyle(0);
   pav->SetBorderSize(0);
   pav->SetTextAlign(11);
   pav->SetTextSize(0.037);
   pav->SetTextFont(42);
   pav->AddText(cut_label);
   
   return pav;
}
//=======================================================================================================================

//=======================================================================================================================
TPaveText* Histograms::CreateCatText( string position, TString cat_label)
{
   TPaveText *pav;
   if (position == "top left")  pav = new TPaveText(.14, .85, .48, .91,"brNDC");
   pav->SetFillStyle(0);
   pav->SetBorderSize(0);
   pav->SetTextAlign(11);
   pav->SetTextSize(0.037);
   pav->SetTextFont(42);
   pav->AddText(cat_label);
   
   return pav;
}
//=======================================================================================================================


//================================================
void Histograms::DrawLogX( TCanvas *c, int i_cat )
{
   int x_low = 100;
   int x_up  = 700;
   int step  = 100;
      
   float u_y_max = c->GetUymax();
   
   if ( i_cat == Settings::inclusive ) _y_max = u_y_max;
   
   float factor = u_y_max/_y_max;
   float y_latex = -0.6;
       
   TLatex *latex_80 = new TLatex(80, y_latex*factor, "80");  
   latex_80->SetTextAlign(23);
   latex_80->SetTextFont (42);
   latex_80->SetTextSize (0.05);
   latex_80->Draw();
    
   TLatex *latex_800 = new TLatex(800, y_latex*factor, "800");  
   latex_800->SetTextAlign(23);
   latex_800->SetTextFont (42);
   latex_800->SetTextSize (0.05);
   latex_800->Draw();
    
   for ( int i = x_low; i < x_up; i += step )
   {
      float i_x = i;
      
      TLatex *latex = new TLatex(i, y_latex*factor, Form("%.0f", i_x));
      
      latex->SetTextAlign(23);
      latex->SetTextFont (42);
      latex->SetTextSize (0.05);
      latex->Draw();
   }
}
//================================================



//=======================================
void Histograms::MakeCOLZGrey(bool shift)
{
   int col = 1;
   const Int_t NRGBs = 2;
   const Int_t NCont = 255;
   Double_t stops[NRGBs] = { 0.00, 1.00 };
   Double_t red[NRGBs]   = { 1., 0.5 };
   Double_t green[NRGBs] = { 1., 0.5 };
   Double_t blue[NRGBs]  = { 1., 0.5 };
   
   if(shift)
   {
      for(int i=0; i<NRGBs; i++){
         red  [i] -= 0.10;
         green[i] -= 0.10;
         blue [i] -= 0.10;
      }
   }
   TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
   gStyle->SetNumberContours(NCont);
}
//=======================================
                        

                          
//=======================================
float Histograms::SetMassPoint( int point)
{
   switch (point) {
      case 0:
         return 120.;
         break;
         
      case 1:
         return 124.;
         break;
         
      case 2:
         return 125;
         break;
         
      case 3:
         return 126;
         break;
         
      case 4:
         return 130;
         break;
         
      default:
         cout << "[ERROR] Mass point index out of range: " << point << endl;
         abort();
         break;
   }
}
//=======================================



//=======================================
int Histograms::SetProcess( int point, int production_mode)
{
   if (point == 0)
   {
      switch (production_mode) {
         case 0:
            return Settings::yH120ggH;
            break;
            
         case 1:
            return Settings::yH120VBF;
            break;
            
         case 2:
            return Settings::yH120WH;
            break;
            
         case 3:
            return Settings::yH120ZH;
            break;
            
         case 4:
            return Settings::yH120ttH;
            break;
            
         default:
            cout << "[ERROR] Mass point index out of range: " << production_mode << endl;
            abort();
            break;
      }
   }
      
   else if (point == 1)
   {
      switch (production_mode) {
         case 0:
            return Settings::yH124ggH;
            break;
            
         case 1:
            return Settings::yH124VBF;
            break;
            
         case 2:
            return Settings::yH124WH;
            break;
            
         case 3:
            return Settings::yH124ZH;
            break;
            
         case 4:
            return Settings::yH124ttH;
            break;
            
         default:
            cout << "[ERROR] Mass point index out of range: " << production_mode << endl;
            abort();
            break;
            
      }
   }
   
   else if (point == 2)
   {
      switch (production_mode) {
         case 0:
            return Settings::yH125ggH;
            break;
            
         case 1:
            return Settings::yH125VBF;
            break;
            
         case 2:
            return Settings::yH125WH;
            break;
            
         case 3:
            return Settings::yH125ZH;
            break;
            
         case 4:
            return Settings::yH125ttH;
            break;
            
         default:
            cout << "[ERROR] Mass point index out of range: " << production_mode << endl;
            abort();
            break;
            
      }
   }
   
   else if (point == 3)
   {
      switch (production_mode) {
         case 0:
            return Settings::yH126ggH;
            break;
            
         case 1:
            return Settings::yH126VBF;
            break;
            
         case 2:
            return Settings::yH126WH;
            break;
            
         case 3:
            return Settings::yH126ZH;
            break;
            
         case 4:
            return Settings::yH126ttH;
            break;
            
         default:
            cout << "[ERROR] Mass point index out of range: " << production_mode << endl;
            abort();
            break;
            
      }
   }
   
   else if (point == 4)
   {
      switch (production_mode) {
         case 0:
            return Settings::yH130ggH;
            break;
            
         case 1:
            return Settings::yH130VBF;
            break;
            
         case 2:
            return Settings::yH130WH;
            break;
            
         case 3:
            return Settings::yH130ZH;
            break;
            
         case 4:
            return Settings::yH130ttH;
            break;
            
         default:
            cout << "[ERROR] Mass point index out of range: " << production_mode << endl;
            abort();
            break;
            
      }
   }

   else
   {
      cout << "[ERROR] Mass point index out of range: " << point << endl;
      abort();

   }
}
//=======================================

