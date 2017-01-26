#include "Histograms.h"
#include "Variables.h"
#include "CMS_lumi.h"
#include <TROOT.h>
#include <sstream>

using namespace std;

// Constructor
//======================================
Histograms::Histograms( string blinding )
{
   _blinding = blinding;
   
   _s_process.push_back("Data");
   _s_process.push_back("H120");
   _s_process.push_back("H124");
   _s_process.push_back("H125");
   _s_process.push_back("H126");
   _s_process.push_back("H130");
   
   _s_process.push_back("H120VBF");
   _s_process.push_back("H124VBF");
   _s_process.push_back("H125VBF");
   _s_process.push_back("H126VBF");
   _s_process.push_back("H130VBF");
   
   _s_process.push_back("H120VH");
   _s_process.push_back("H124VH");
   _s_process.push_back("H125VH");
   _s_process.push_back("H126VH");
   _s_process.push_back("H130VH");
   
   _s_process.push_back("H120other");
   _s_process.push_back("H124other");
   _s_process.push_back("H125other");
   _s_process.push_back("H126other");
   _s_process.push_back("H130other");
      
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
               
               _histo_name = "M4l_HighMass" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::M4lMainHighMass().var_X_label + ";" + Variables::M4lMainHighMass().var_Y_label;
               histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMainHighMass().var_N_bin, Variables::M4lMainHighMass().var_min, Variables::M4lMainHighMass().var_max);

               //=============
               // MZ1
               //=============
               _histo_name = "MZ1" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ1().var_X_label + ";" + Variables::MZ1().var_Y_label;
               histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ1().var_N_bin, Variables::MZ1().var_min, Variables::MZ1().var_max);
               
               _histo_name = "MZ1_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ1_M4L118130().var_X_label + ";" + Variables::MZ1_M4L118130().var_Y_label;
               histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ1_M4L118130().var_N_bin, Variables::MZ1_M4L118130().var_min, Variables::MZ1_M4L118130().var_max);
               
               //=============
               // MZ2
               //=============
               _histo_name = "MZ2" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ2().var_X_label + ";" + Variables::MZ2().var_Y_label;
               histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ2().var_N_bin, Variables::MZ2().var_min, Variables::MZ2().var_max);
               
               _histo_name = "MZ2_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ2_M4L118130().var_X_label + ";" + Variables::MZ2_M4L118130().var_Y_label;
               histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ2_M4L118130().var_N_bin, Variables::MZ2_M4L118130().var_min, Variables::MZ2_M4L118130().var_max);
               
               //=============
               // KD
               //=============
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
               
               //=============
               // MZ1vsMZ2
               //=============
               _histo_name = "MZ1vsMZ2" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ1vsMZ2().var_X_label + ";" + Variables::MZ1vsMZ2().var_Y_label;
               histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ1vsMZ2().var_X_N_bin, Variables::MZ1vsMZ2().var_X_min, Variables::MZ1vsMZ2().var_X_max, Variables::MZ1vsMZ2().var_Y_N_bin, Variables::MZ1vsMZ2().var_Y_min, Variables::MZ1vsMZ2().var_Y_max);
               
               _histo_name = "MZ1vsMZ2_M4L118130" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + _blinding;
               _histo_labels = ";" + Variables::MZ1vsMZ2_M4L118130().var_X_label + ";" + Variables::MZ1vsMZ2_M4L118130().var_Y_label;
               histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc] = new TH2F(_histo_name.c_str(), _histo_labels.c_str(), Variables::MZ1vsMZ2_M4L118130().var_X_N_bin, Variables::MZ1vsMZ2_M4L118130().var_X_min, Variables::MZ1vsMZ2_M4L118130().var_X_max, Variables::MZ1vsMZ2_M4L118130().var_Y_N_bin, Variables::MZ1vsMZ2_M4L118130().var_Y_min, Variables::MZ1vsMZ2_M4L118130().var_Y_max);
               
               //=============
               // KDvsM4l
               //=============
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
         //=============
         // M4l
         //=============
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

         
         //=============
         // MZ1
         //=============
         _histo_name = "MZ1_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ1][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::MZ1().var_N_bin, Variables::MZ1().var_min, Variables::MZ1().var_max);
         
         _histo_name = "MZ1_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::MZ1_M4L118130().var_N_bin, Variables::MZ1_M4L118130().var_min, Variables::MZ1_M4L118130().var_max);
         
         //=============
         // MZ2
         //=============
         _histo_name = "MZ2_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ2][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::MZ2().var_N_bin, Variables::MZ2().var_min, Variables::MZ2().var_max);
         
         _histo_name = "MZ2_M4L118130_ZX_SS_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::MZ2_M4L118130().var_N_bin, Variables::MZ2_M4L118130().var_min, Variables::MZ2_M4L118130().var_max);
         
         //=============
         // KD
         //=============
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
Histograms::Histograms()
{  
   _blinding = "Unblinded";
   
   _s_process.push_back("Data");
   _s_process.push_back("H120");
   _s_process.push_back("H124");
   _s_process.push_back("H125");
   _s_process.push_back("H126");
   _s_process.push_back("H130");
   
   _s_process.push_back("H120VBF");
   _s_process.push_back("H124VBF");
   _s_process.push_back("H125VBF");
   _s_process.push_back("H126VBF");
   _s_process.push_back("H130VBF");
   
   _s_process.push_back("H120VH");
   _s_process.push_back("H124VH");
   _s_process.push_back("H125VH");
   _s_process.push_back("H126VH");
   _s_process.push_back("H130VH");
   
   _s_process.push_back("H120other");
   _s_process.push_back("H124other");
   _s_process.push_back("H125other");
   _s_process.push_back("H126other");
   _s_process.push_back("H130other");
      
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
               _histo_name = "M4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + "_" + _blinding;
               _histo_labels = ";" + Variables::M4lMain().var_X_label + ";" + Variables::M4lMain().var_Y_label;     
               histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc] = new TH1F(_histo_name.c_str(), _histo_labels.c_str(), Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);
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
         
         _histo_name = "M4l_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat] = new TH1F(_histo_name.c_str(), "Z+X", Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max);
      }
   }
}
//======================




//=======================
Histograms::~Histograms()
{
}
//=======================


//=============
// M4l
//=============
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

//=============
// MZ1
//=============
//====================================================================================
void Histograms::FillMZ1( float M4l, float MZ1, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::MZ1][fs][cat][rs][proc]->Fill(MZ1, (proc == Settings::Data) ? 1. : weight);
   if( M4l >= Variables::MZ1_M4L118130().cut_d && M4l <= Variables::MZ1_M4L118130().cut_u) histos_1D[Settings::MZ1_M4L118130][fs][cat][rs][proc]->Fill(MZ1, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================


//====================================================================
void Histograms::FillMZ1ZX( float M4l, float MZ1, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::MZ1][fs][cat]->Fill(MZ1, weight);
   if( M4l >= Variables::MZ1_M4L118130().cut_d && M4l <= Variables::MZ1_M4L118130().cut_u) histos_1D_ZX[Settings::MZ1_M4L118130][fs][cat]->Fill(MZ1, weight);
}
//====================================================================


//=============
// MZ2
//=============
//====================================================================================
void Histograms::FillMZ2( float M4l, float MZ2, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::MZ2][fs][cat][rs][proc]->Fill(MZ2, (proc == Settings::Data) ? 1. : weight);
   if( M4l >= Variables::MZ2_M4L118130().cut_d && M4l <= Variables::MZ2_M4L118130().cut_u) histos_1D[Settings::MZ2_M4L118130][fs][cat][rs][proc]->Fill(MZ2, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================

//====================================================================
void Histograms::FillMZ2ZX( float M4l, float MZ2, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::MZ2][fs][cat]->Fill(MZ2, weight);
   if( M4l >= Variables::MZ2_M4L118130().cut_d && M4l <= Variables::MZ2_M4L118130().cut_u) histos_1D_ZX[Settings::MZ2_M4L118130][fs][cat]->Fill(MZ2, weight);
}
//====================================================================


//=============
// KD
//=============
//====================================================================================
void Histograms::FillKD( float M4l, float KD, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::KD][fs][cat][rs][proc]->Fill(KD, (proc == Settings::Data) ? 1. : weight);
   if( M4l >= Variables::KD_M4L118130().cut_d && M4l <= Variables::KD_M4L118130().cut_u) histos_1D[Settings::KD_M4L118130][fs][cat][rs][proc]->Fill(KD, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================

//====================================================================
void Histograms::FillKDZX( float M4l, float KD, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::KD][fs][cat]->Fill(KD, weight);
   if( M4l >= Variables::KD_M4L118130().cut_d && M4l <= Variables::KD_M4L118130().cut_u) histos_1D_ZX[Settings::KD_M4L118130][fs][cat]->Fill(KD, weight);
}
//====================================================================



//=============
// D1jet
//=============
//====================================================================================
void Histograms::FillD1jet( float M4l, float D1jet, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::D1jet][fs][cat][rs][proc]->Fill(D1jet, (proc == Settings::Data) ? 1. : weight);
   if( M4l >= Variables::D1jet_M4L118130().cut_d && M4l <= Variables::D1jet_M4L118130().cut_u) histos_1D[Settings::D1jet_M4L118130][fs][cat][rs][proc]->Fill(D1jet, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================

//====================================================================
void Histograms::FillD1jetZX( float M4l, float D1jet, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::D1jet][fs][cat]->Fill(D1jet, weight);
   if( M4l >= Variables::D1jet_M4L118130().cut_d && M4l <= Variables::D1jet_M4L118130().cut_u) histos_1D_ZX[Settings::D1jet_M4L118130][fs][cat]->Fill(D1jet, weight);
}
//====================================================================



//=============
// D2jet
//=============
//====================================================================================
void Histograms::FillD2jet( float M4l, float D2jet, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::D2jet][fs][cat][rs][proc]->Fill(D2jet, (proc == Settings::Data) ? 1. : weight);
   if( M4l >= Variables::D2jet_M4L118130().cut_d && M4l <= Variables::D2jet_M4L118130().cut_u) histos_1D[Settings::D2jet_M4L118130][fs][cat][rs][proc]->Fill(D2jet, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================

//====================================================================
void Histograms::FillD2jetZX( float M4l, float D2jet, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::D2jet][fs][cat]->Fill(D2jet, weight);
   if( M4l >= Variables::D2jet_M4L118130().cut_d && M4l <= Variables::D2jet_M4L118130().cut_u) histos_1D_ZX[Settings::D2jet_M4L118130][fs][cat]->Fill(D2jet, weight);
}
//====================================================================


//=============
// DWH
//=============
//====================================================================================
void Histograms::FillDWH( float M4l, float DWH, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::DWH][fs][cat][rs][proc]->Fill(DWH, (proc == Settings::Data) ? 1. : weight);
   if( M4l >= Variables::DWH_M4L118130().cut_d && M4l <= Variables::DWH_M4L118130().cut_u) histos_1D[Settings::DWH_M4L118130][fs][cat][rs][proc]->Fill(DWH, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================

//====================================================================
void Histograms::FillDWHZX( float M4l, float DWH, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::DWH][fs][cat]->Fill(DWH, weight);
   if( M4l >= Variables::DWH_M4L118130().cut_d && M4l <= Variables::DWH_M4L118130().cut_u) histos_1D_ZX[Settings::DWH_M4L118130][fs][cat]->Fill(DWH, weight);
}
//====================================================================

//=============
// DZH
//=============
//====================================================================================
void Histograms::FillDZH( float M4l, float DZH, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::DZH][fs][cat][rs][proc]->Fill(DZH, (proc == Settings::Data) ? 1. : weight);
   if( M4l >= Variables::DZH_M4L118130().cut_d && M4l <= Variables::DZH_M4L118130().cut_u) histos_1D[Settings::DZH_M4L118130][fs][cat][rs][proc]->Fill(DZH, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================


//====================================================================
void Histograms::FillDZHZX( float M4l, float DZH, float weight, int fs, int cat )
{
   histos_1D_ZX[Settings::DZH][fs][cat]->Fill(DZH, weight);
   if( M4l >= Variables::DZH_M4L118130().cut_d && M4l <= Variables::DZH_M4L118130().cut_u) histos_1D_ZX[Settings::DZH_M4L118130][fs][cat]->Fill(DZH, weight);
}
//====================================================================



//=============
// MZ1vsMZ2
//=============
//====================================================================================
void Histograms::FillMZ1vsMZ2( float M4l, float MZ1, float MZ2, float weight, int fs, int cat, int rs, int proc )
{
   histos_2D[Settings::MZ1vsMZ2][fs][cat][rs][proc]->Fill(MZ1, MZ2, (proc == Settings::Data) ? 1. : weight);
   if( M4l >= Variables::MZ1vsMZ2_M4L118130().cut_d && M4l <= Variables::MZ1vsMZ2_M4L118130().cut_u) histos_2D[Settings::MZ1vsMZ2_M4L118130][fs][cat][rs][proc]->Fill(MZ1, MZ2, (proc == Settings::Data) ? 1. : weight);
   
}
//====================================================================================

//=============
// Fill vectors
//=============
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
   
   if(nCleanedJetsPt30==1)
   {
      vector_X[Settings::D1jetvsM4lZoomed][fs][cat].push_back(M4l);
      vector_Y[Settings::D1jetvsM4lZoomed][fs][cat].push_back(D1jet);
      vector_EX[Settings::D1jetvsM4lZoomed][fs][cat].push_back(ZZMassErrCorr);
      vector_EY[Settings::D1jetvsM4lZoomed][fs][cat].push_back(0.);
   }

   if(nCleanedJetsPt30>=2)
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

//=============
// KDvsM4l
//=============
//====================================================================================
void Histograms::FillDvsM4l( float M4l, float KD, int nCleanedJetsPt30, float D1jet, float D2jet, float DWH, float DZH, float weight, int fs, int cat, int rs, int proc )
{
   histos_2DError[Settings::KDvsM4l][fs][cat][rs][proc]        ->Fill(M4l, KD, (proc == Settings::Data) ? 1. : weight);
   histos_2DError[Settings::KDvsM4lZoomed][fs][cat][rs][proc]  ->Fill(M4l, KD, (proc == Settings::Data) ? 1. : weight);
   histos_2DError[Settings::KDvsM4lHighMass][fs][cat][rs][proc]->Fill(M4l, KD, (proc == Settings::Data) ? 1. : weight);
   
   if(nCleanedJetsPt30==1) histos_2DError[Settings::D1jetvsM4lZoomed][fs][cat][rs][proc]->Fill(M4l, D1jet, (proc == Settings::Data) ? 1. : weight);
   if(nCleanedJetsPt30>=2) histos_2DError[Settings::D2jetvsM4lZoomed][fs][cat][rs][proc]->Fill(M4l, D2jet, (proc == Settings::Data) ? 1. : weight);
   if(nCleanedJetsPt30>=2) histos_2DError[Settings::DWHvsM4lZoomed][fs][cat][rs][proc]  ->Fill(M4l, DWH, (proc == Settings::Data) ? 1. : weight);
   if(nCleanedJetsPt30>=2) histos_2DError[Settings::DZHvsM4lZoomed][fs][cat][rs][proc]  ->Fill(M4l, DZH, (proc == Settings::Data) ? 1. : weight);
   
}
//====================================================================================

//====================================================================================
void Histograms::FillYields( float M4l, float weight, int fs, int cat, int rs, int proc )
{
   histos_1D[Settings::M4lMain][fs][cat][rs][proc]->Fill(M4l, (proc == Settings::Data) ? 1. : weight);
}
//====================================================================================






//=======================================================================================
void Histograms::MakeZXShape( int current_final_state, int current_category)
{
   M4lZX *ZXShape = new M4lZX();
   
   current_final_state = (current_final_state == 3) ? 2 : current_final_state;
   histos_1D_ZX_shape[Settings::M4lMain][current_final_state][current_category]->Add(ZXShape->GetM4lZX(Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max, current_final_state, current_category));
   
   ZXShape->~M4lZX();
   
   M4lZX *ZXShape_zoomed = new M4lZX();
   
   histos_1D_ZX_shape[Settings::M4lMainZoomed][current_final_state][current_category]->Add(ZXShape_zoomed->GetM4lZX(Variables::M4lMainZoomed().var_N_bin, Variables::M4lMainZoomed().var_min, Variables::M4lMainZoomed().var_max, current_final_state, current_category));
   
   ZXShape_zoomed->~M4lZX();
   
   M4lZX *ZXShape_HighMass = new M4lZX();
   
   histos_1D_ZX_shape[Settings::M4lMainHighMass][current_final_state][current_category]->Add(ZXShape_HighMass->GetM4lZX(Variables::M4lMainHighMass().var_N_bin, Variables::M4lMainHighMass().var_min, Variables::M4lMainHighMass().var_max, current_final_state, current_category));
   
   ZXShape_HighMass->~M4lZX();
   
}
//=======================================================================================

//=======================================================================================
void Histograms::MakeZXShapeYields( int current_final_state, int current_category)
{
   M4lZX *ZXShape = new M4lZX();
   
   current_final_state = (current_final_state == 3) ? 2 : current_final_state;
   histos_1D_ZX_shape[Settings::M4lMain][current_final_state][current_category]->Add(ZXShape->GetM4lZX(Variables::M4lMain().var_N_bin, Variables::M4lMain().var_min, Variables::M4lMain().var_max, current_final_state, current_category));
   
   ZXShape->~M4lZX();
   
   
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
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][Settings::H125other]);
            
            //=============
            // MZ1
            //=============
            histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            //=============
            // MZ2
            //=============
            histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][Settings::H125other]);
            
            //=============
            // KD
            //=============
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
            
            //=============
            // MZ1vsMZ2
            //=============
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
               //=============
               // M4l
               //=============
               histos_1D[Settings::M4lMain][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainZoomed][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::M4lMainZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::M4lMainHighMass][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1
               //=============
               histos_1D[Settings::MZ1][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ1_M4L118130][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ2
               //=============
               histos_1D[Settings::MZ2][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ2_M4L118130][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // KD
               //=============
               histos_1D[Settings::KD][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::KD_M4L118130][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D1jet][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D1jet_M4L118130][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D2jet][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D2jet_M4L118130][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DWH][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DWH_M4L118130][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DZH][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DZH_M4L118130][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1vsMZ2
               //=============
               histos_2D[Settings::MZ1vsMZ2][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2D[Settings::MZ1vsMZ2_M4L118130][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);

               //==========================
               // 2D plots with mass error
               //==========================
               histos_2DError[Settings::KDvsM4l][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lZoomed][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lHighMass][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2DError[Settings::D1jetvsM4lZoomed][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::D2jetvsM4lZoomed][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DWHvsM4lZoomed][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DZHvsM4lZoomed][num_of_final_states - 1][i_cat][i_rs][i_proc]->Add(histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);

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
               histos_1D[Settings::M4lMainHighMass][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1
               //=============
               histos_1D[Settings::MZ1][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ1_M4L118130][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ2
               //=============
               histos_1D[Settings::MZ2][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ2_M4L118130][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // KD
               //=============
               histos_1D[Settings::KD][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::KD_M4L118130][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D1jet][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D1jet_M4L118130][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D2jet][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D2jet_M4L118130][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DWH][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DWH_M4L118130][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DZH][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DZH_M4L118130][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1vsMZ2
               //=============
               histos_2D[Settings::MZ1vsMZ2][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);

               //==========================
               // 2D plots with mass error
               //==========================
               histos_2DError[Settings::KDvsM4l][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lZoomed][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lHighMass][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DWHvsM4lZoomed][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DZHvsM4lZoomed][i_fs][num_of_categories - 1][i_rs][i_proc]->Add(histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);

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
               histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::M4lMainHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1
               //=============
               histos_1D[Settings::MZ1][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::MZ1][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::MZ1_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ2
               //=============
               histos_1D[Settings::MZ2][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::MZ2][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::MZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // KD
               //=============
               histos_1D[Settings::KD][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::KD][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::KD_M4L118130][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::KD_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D1jet][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::D1jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::D1jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::D2jet][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::D2jet][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::D2jet_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DWH][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::DWH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::DWH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               histos_1D[Settings::DZH][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::DZH][i_fs][i_cat][i_rs][i_proc]);
               histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_1D[Settings::DZH_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //=============
               // MZ1vsMZ2
               //=============
               histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_2D[Settings::MZ1vsMZ2_M4L118130][i_fs][i_cat][i_rs][i_proc]);
               
               //==========================
               // 2D plots with mass error
               //==========================
               histos_2DError[Settings::KDvsM4l][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_2DError[Settings::KDvsM4l][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_2DError[Settings::KDvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_2DError[Settings::KDvsM4lHighMass][i_fs][i_cat][i_rs][i_proc]);
               
               histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_2DError[Settings::D1jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_2DError[Settings::D2jetvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_2DError[Settings::DWHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);
               histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][num_of_resonant_statuses - 1][i_proc]->Add(histos_2DError[Settings::DZHvsM4lZoomed][i_fs][i_cat][i_rs][i_proc]);


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
         histos_1D_ZX[Settings::M4lMainHighMass][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat]);
         
         //=============
         // MZ1
         //=============
         histos_1D_ZX[Settings::MZ1][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::MZ1][i_fs][i_cat]);
         histos_1D_ZX[Settings::MZ1_M4L118130][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat]);
         
         //=============
         // MZ2
         //=============
         histos_1D_ZX[Settings::MZ2][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::MZ2][i_fs][i_cat]);
         histos_1D_ZX[Settings::MZ2_M4L118130][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat]);
         
         //=============
         // KD
         //=============
         histos_1D_ZX[Settings::KD][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::KD][i_fs][i_cat]);
         histos_1D_ZX[Settings::KD_M4L118130][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::D1jet][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::D1jet][i_fs][i_cat]);
         histos_1D_ZX[Settings::D1jet_M4L118130][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::D2jet][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::D2jet][i_fs][i_cat]);
         histos_1D_ZX[Settings::D2jet_M4L118130][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::DWH][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::DWH][i_fs][i_cat]);
         histos_1D_ZX[Settings::DWH_M4L118130][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::DZH][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::DZH][i_fs][i_cat]);
         histos_1D_ZX[Settings::DZH_M4L118130][num_of_final_states - 1][i_cat]->Add(histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat]);
         
         //==========================
         // 2D plots with mass error
         //==========================
         vector_X[Settings::KDvsM4l][num_of_final_states - 1][i_cat].insert(vector_X[Settings::KDvsM4l][num_of_final_states - 1][i_cat].end(),vector_X[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4l][num_of_final_states - 1][i_cat].insert(vector_Y[Settings::KDvsM4l][num_of_final_states - 1][i_cat].end(),vector_Y[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4l][num_of_final_states - 1][i_cat].insert(vector_EX[Settings::KDvsM4l][num_of_final_states - 1][i_cat].end(),vector_EX[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4l][num_of_final_states - 1][i_cat].insert(vector_EY[Settings::KDvsM4l][num_of_final_states - 1][i_cat].end(),vector_EY[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4l][i_fs][i_cat].end());
         
         vector_X[Settings::KDvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_X[Settings::KDvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_Y[Settings::KDvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_Y[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EX[Settings::KDvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EX[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EY[Settings::KDvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EY[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::KDvsM4lHighMass][num_of_final_states - 1][i_cat].insert(vector_X[Settings::KDvsM4lHighMass][num_of_final_states - 1][i_cat].end(),vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4lHighMass][num_of_final_states - 1][i_cat].insert(vector_Y[Settings::KDvsM4lHighMass][num_of_final_states - 1][i_cat].end(),vector_Y[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4lHighMass][num_of_final_states - 1][i_cat].insert(vector_EX[Settings::KDvsM4lHighMass][num_of_final_states - 1][i_cat].end(),vector_EX[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4lHighMass][num_of_final_states - 1][i_cat].insert(vector_EY[Settings::KDvsM4lHighMass][num_of_final_states - 1][i_cat].end(),vector_EY[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         
         vector_X[Settings::D1jetvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_X[Settings::D1jetvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::D1jetvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_Y[Settings::D1jetvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_Y[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::D1jetvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EX[Settings::D1jetvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EX[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::D1jetvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EY[Settings::D1jetvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EY[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::D2jetvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_X[Settings::D2jetvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::D2jetvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_Y[Settings::D2jetvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_Y[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::D2jetvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EX[Settings::D2jetvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EX[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::D2jetvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EY[Settings::D2jetvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EY[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::DWHvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_X[Settings::DWHvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::DWHvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_Y[Settings::DWHvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_Y[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::DWHvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EX[Settings::DWHvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EX[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::DWHvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EY[Settings::DWHvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EY[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::DZHvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_X[Settings::DZHvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::DZHvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_Y[Settings::DZHvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_Y[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::DZHvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EX[Settings::DZHvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EX[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::DZHvsM4lZoomed][num_of_final_states - 1][i_cat].insert(vector_EY[Settings::DZHvsM4lZoomed][num_of_final_states - 1][i_cat].end(),vector_EY[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         
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
         histos_1D_ZX[Settings::M4lMainHighMass][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::M4lMainHighMass][i_fs][i_cat]);
         
         //=============
         // MZ1
         //=============
         histos_1D_ZX[Settings::MZ1][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::MZ1][i_fs][i_cat]);
         histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::MZ1_M4L118130][i_fs][i_cat]);
         
         //=============
         // MZ2
         //=============
         histos_1D_ZX[Settings::MZ2][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::MZ2][i_fs][i_cat]);
         histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::MZ2_M4L118130][i_fs][i_cat]);
         
         //=============
         // KD
         //=============
         histos_1D_ZX[Settings::KD][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::KD][i_fs][i_cat]);
         histos_1D_ZX[Settings::KD_M4L118130][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::KD_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::D1jet][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::D1jet][i_fs][i_cat]);
         histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::D1jet_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::D2jet][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::D2jet][i_fs][i_cat]);
         histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::D2jet_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::DWH][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::DWH][i_fs][i_cat]);
         histos_1D_ZX[Settings::DWH_M4L118130][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::DWH_M4L118130][i_fs][i_cat]);
         
         histos_1D_ZX[Settings::DZH][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::DZH][i_fs][i_cat]);
         histos_1D_ZX[Settings::DZH_M4L118130][i_fs][num_of_categories - 1]->Add(histos_1D_ZX[Settings::DZH_M4L118130][i_fs][i_cat]);
         
         //==========================
         // 2D plots with mass error
         //==========================
         vector_X[Settings::KDvsM4l][i_fs][num_of_categories - 1].insert(vector_X[Settings::KDvsM4l][i_fs][num_of_categories - 1].end(),vector_X[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4l][i_fs][num_of_categories - 1].insert(vector_Y[Settings::KDvsM4l][i_fs][num_of_categories - 1].end(),vector_Y[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4l][i_fs][num_of_categories - 1].insert(vector_EX[Settings::KDvsM4l][i_fs][num_of_categories - 1].end(),vector_EX[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4l][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4l][i_fs][num_of_categories - 1].insert(vector_EY[Settings::KDvsM4l][i_fs][num_of_categories - 1].end(),vector_EY[Settings::KDvsM4l][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4l][i_fs][i_cat].end());
         
         vector_X[Settings::KDvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_X[Settings::KDvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_Y[Settings::KDvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_Y[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EX[Settings::KDvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EX[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EY[Settings::KDvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EY[Settings::KDvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::KDvsM4lHighMass][i_fs][num_of_categories - 1].insert(vector_X[Settings::KDvsM4lHighMass][i_fs][num_of_categories - 1].end(),vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_X[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_Y[Settings::KDvsM4lHighMass][i_fs][num_of_categories - 1].insert(vector_Y[Settings::KDvsM4lHighMass][i_fs][num_of_categories - 1].end(),vector_Y[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_Y[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_EX[Settings::KDvsM4lHighMass][i_fs][num_of_categories - 1].insert(vector_EX[Settings::KDvsM4lHighMass][i_fs][num_of_categories - 1].end(),vector_EX[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_EX[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         vector_EY[Settings::KDvsM4lHighMass][i_fs][num_of_categories - 1].insert(vector_EY[Settings::KDvsM4lHighMass][i_fs][num_of_categories - 1].end(),vector_EY[Settings::KDvsM4lHighMass][i_fs][i_cat].begin(),vector_EY[Settings::KDvsM4lHighMass][i_fs][i_cat].end());
         
         vector_X[Settings::D1jetvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_X[Settings::D1jetvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::D1jetvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_Y[Settings::D1jetvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_Y[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::D1jetvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EX[Settings::D1jetvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EX[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::D1jetvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EY[Settings::D1jetvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EY[Settings::D1jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::D1jetvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::D2jetvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_X[Settings::D2jetvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::D2jetvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_Y[Settings::D2jetvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_Y[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::D2jetvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EX[Settings::D2jetvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EX[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::D2jetvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EY[Settings::D2jetvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EY[Settings::D2jetvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::D2jetvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::DWHvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_X[Settings::DWHvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::DWHvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_Y[Settings::DWHvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_Y[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::DWHvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EX[Settings::DWHvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EX[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::DWHvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EY[Settings::DWHvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EY[Settings::DWHvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::DWHvsM4lZoomed][i_fs][i_cat].end());
         
         vector_X[Settings::DZHvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_X[Settings::DZHvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_X[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_Y[Settings::DZHvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_Y[Settings::DZHvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_Y[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_Y[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_EX[Settings::DZHvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EX[Settings::DZHvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EX[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_EX[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         vector_EY[Settings::DZHvsM4lZoomed][i_fs][num_of_categories - 1].insert(vector_EY[Settings::DZHvsM4lZoomed][i_fs][num_of_categories - 1].end(),vector_EY[Settings::DZHvsM4lZoomed][i_fs][i_cat].begin(),vector_EY[Settings::DZHvsM4lZoomed][i_fs][i_cat].end());
         
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
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H120]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H120VBF]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H120]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H120VH]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H120]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H120other]);
            
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H124]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H124VBF]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H124]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H124VH]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H124]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H124other]);
            
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125VBF]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125VH]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H125other]);
            
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H126]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H126VBF]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H126]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H126VH]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H126]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H126other]);
            
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H130]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H130VBF]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H130]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H130VH]);
            histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H130]->Add(histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][Settings::H130other]);
      
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
         //=============
         // M4l
         //=============
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::M4lMain][Settings::fs4e][i_cat], histos_1D_ZX[Settings::M4lMain][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::M4lMain][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::M4lMainZoomed][Settings::fs4e][i_cat], histos_1D_ZX[Settings::M4lMainZoomed][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::M4lMainZoomed][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::M4lMainHighMass][Settings::fs4e][i_cat], histos_1D_ZX[Settings::M4lMainHighMass][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::M4lMainHighMass][Settings::fs2e2mu][i_cat]);
         
         //=============
         // MZ1
         //=============
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::MZ1][Settings::fs4e][i_cat], histos_1D_ZX[Settings::MZ1][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::MZ1][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::MZ1_M4L118130][Settings::fs4e][i_cat], histos_1D_ZX[Settings::MZ1_M4L118130][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::MZ1_M4L118130][Settings::fs2e2mu][i_cat]);
         //=============
         // MZ2
         //=============
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::MZ2][Settings::fs4e][i_cat], histos_1D_ZX[Settings::MZ2][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::MZ2][Settings::fs2e2mu][i_cat]);
      ZX->RenormalizeZX( i_cat, _expected_yield_SR, histos_1D_ZX[Settings::MZ2_M4L118130][Settings::fs4e][i_cat], histos_1D_ZX[Settings::MZ2_M4L118130][Settings::fs4mu][i_cat], histos_1D_ZX[Settings::MZ2_M4L118130][Settings::fs2e2mu][i_cat]);
         
         //=============
         // KD
         //=============
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
   //ZX->~M4lZX();
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
         histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat]->Write();

         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc]->Write();
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
//=============================================



//=============================================
void Histograms::DeleteYieldsHistos()
{
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         //=============
         // M4l
         //=============
         delete histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat];
         
         for ( int i_rs = 0; i_rs < num_of_resonant_statuses; i_rs++ )
         {
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               //=============
               // M4l
               //=============
               delete histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc];               
            }
         }
      }
   }

}
//=============================================



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
            for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
            {
               //=============
               // M4l
               //=============
               _histo_name = "M4l" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + "_" + _s_resonant_status.at(i_rs) + "_" + _s_process.at(i_proc) + "_" + _blinding;
               histos_1D[Settings::M4lMain][i_fs][i_cat][i_rs][i_proc] = (TH1F*)histo_file->Get(_histo_name.c_str());
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
         _histo_name = "M4l_ZX_shape_" + _s_final_state.at(i_fs) + "_" + _s_category.at(i_cat) + _blinding;
         histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat] = (TH1F*)histo_file->Get(_histo_name.c_str());
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
      stack->SetMinimum(0.1);
      stack->SetMaximum((data_max + data_max_error)*100);
   }
   
   else
   {
      stack->SetMinimum(1e-5);
      stack->SetMaximum((data_max + data_max_error)*1.1);
   }
   
   stack->GetXaxis()->SetTitle(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetXaxis()->GetTitle());
   stack->GetYaxis()->SetTitle(histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
   
   histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data]->Draw("SAME p E1 X0");
   
   TLegend *legend;
   if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass")
   {
      legend  = CreateLegend("right",histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX_shape[plot_index][fs][cat]);
   }
   
   else if ( plot_index == Settings::D1jet_M4L118130 || plot_index == Settings::D2jet_M4L118130 || plot_index == Settings::D1jet || plot_index == Settings::D2jet )
   {
      legend  = CreateLegendVBF("right",histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VBF],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][fs][cat]);
   }
   else if ( plot_index == Settings::DWH_M4L118130 || plot_index == Settings::DZH_M4L118130 || plot_index == Settings::DWH || plot_index == Settings::DZH  )
   {
      legend  = CreateLegendVH("right",histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125VH],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125other],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][fs][cat]);
   }
   else
   {
      legend = CreateLegend((plot_index == Settings::MZ1 || plot_index == Settings::MZ1_M4L118130 || plot_index == Settings::MZ2 || plot_index == Settings::MZ2_M4L118130)?"left":"right",histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][fs][cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][fs][cat]);
   }

   legend->Draw();
   
   // Draw lumi
   CMS_lumi *lumi = new CMS_lumi;
   lumi->set_lumi(c, 0, 0);
   
   // Draw X-axis log scale
   if ( plot_index == Settings::M4lMain )
   {
      stack->GetXaxis()->SetNdivisions(10);
      stack->GetXaxis()->SetLabelSize(0);
      DrawLogX(c, cat);
   }

   stringstream ss;
   ss << folder << "/" << variable_name << "_" << filename << "_" << _s_final_state.at(fs) << "_" << _s_category.at(cat);

   c->SaveAs((ss.str() + ".pdf").c_str());
   c->SaveAs((ss.str() + ".png").c_str());
   c->SaveAs((ss.str() + ".root").c_str());
   c->SaveAs((ss.str() + ".C").c_str());
   c->SaveAs((ss.str() + ".eps").c_str());

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
       
   for( int i_cat = num_of_categories - 1; i_cat >= 0; i_cat--)
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
      stack->GetYaxis()->SetTitle(histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
      
      histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data]->Draw("SAME p E1 X0");

      TLegend *legend;
      if(variable_name == "M4lMain" || variable_name == "M4lMainZoomed" || variable_name == "M4lMainHighMass")
      {
        legend  = CreateLegend("right",histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX_shape[plot_index][Settings::fs4l][i_cat]);
      }
      
      else
      {
         legend = CreateLegend("right",histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::Data],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::H125],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::qqZZ],histos_1D[plot_index][Settings::fs4l][i_cat][Settings::all_resonant][Settings::ggZZ], histos_1D_ZX[plot_index][Settings::fs4l][i_cat]);
      }
      legend->Draw();
      
      // Draw lumi
      CMS_lumi *lumi = new CMS_lumi;
      lumi->set_lumi(c, 0, 0);
      
      // Draw X-axis log scale
      if ( plot_index == Settings::M4lMain )
      {
         stack->GetXaxis()->SetNdivisions(10);
         stack->GetXaxis()->SetLabelSize(0);
         DrawLogX(c, i_cat);
      }
      
      stringstream ss;
      ss << folder << "/" << variable_name << "_" <<filename << "_" << _s_category.at(i_cat);
      cout << ss.str() << endl;
      c->SaveAs((ss.str() + ".pdf").c_str());
      c->SaveAs((ss.str() + ".png").c_str());
      c->SaveAs((ss.str() + ".root").c_str());
      c->SaveAs((ss.str() + ".C").c_str());
      c->SaveAs((ss.str() + ".eps").c_str());
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
      
      stack->GetXaxis()->SetTitle(histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->GetXaxis()->GetTitle());
      stack->GetYaxis()->SetTitle(histos_1D[plot_index][i_fs][Settings::inclusive][Settings::all_resonant][Settings::Data]->GetYaxis()->GetTitle());
      
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
      lumi->set_lumi(c, 0, 0);
      
      // Draw X-axis log scale
      if ( plot_index == Settings::M4lMain )
      {
         stack->GetXaxis()->SetNdivisions(10);
         stack->GetXaxis()->SetLabelSize(0);
         DrawLogX(c, i_fs);
      }
      
      stringstream ss;
      ss << folder << "/" << variable_name << "_" <<filename << "_" << _s_final_state.at(i_fs);
      cout << ss.str() << endl;
      c->SaveAs((ss.str() + ".pdf").c_str());
      c->SaveAs((ss.str() + ".png").c_str());
      c->SaveAs((ss.str() + ".root").c_str());
      c->SaveAs((ss.str() + ".C").c_str());
      c->SaveAs((ss.str() + ".eps").c_str());
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
   lumi->set_lumi(c, 0, 0);
   
   stringstream ss;
   ss << folder << "/" << variable_name << "_" << filename << "_" << _s_category.at(cat);
   
   c->SaveAs((ss.str() + ".pdf").c_str());
   c->SaveAs((ss.str() + ".png").c_str());
   c->SaveAs((ss.str() + ".root").c_str());
   c->SaveAs((ss.str() + ".C").c_str());
   c->SaveAs((ss.str() + ".eps").c_str());
   
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
   lumi->set_lumi(c, 0, 0);
   
   stringstream ss;
   ss << folder << "/" << variable_name << "_" << filename << "_" << _s_category.at(cat);
   
   c->SaveAs((ss.str() + ".pdf").c_str());
   c->SaveAs((ss.str() + ".png").c_str());
   c->SaveAs((ss.str() + ".root").c_str());
   c->SaveAs((ss.str() + ".C").c_str());
   c->SaveAs((ss.str() + ".eps").c_str());
   
}
//========================================================================================================

//========================================================================================================
void Histograms::PrintYields()
{
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
         {
            cout << "Yield in full mass range for " << _s_process.at(i_proc) << ", final state " << _s_final_state.at(i_fs) << ", category " << _s_category.at(i_cat) << ": " << histos_1D[Settings::M4lMain][i_fs][i_cat][Settings::all_resonant][i_proc]->Integral() << endl;
            
         }
      
      }
   }
   
   // Z+X
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
          cout << "Yield in full mass range for Z+X, final state " << _s_final_state.at(i_fs) << ", category " << _s_category.at(i_cat) << ": " << histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat]->Integral() << endl;
      }
   }

}
//========================================================================================================

//========================================================================================================
void Histograms::PrintYields(float M4l_down, float M4l_up)
{
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         for ( int i_proc = 0; i_proc < num_of_processes; i_proc++ )
         {
            cout << "Yield in mass range [" << M4l_down << "," << M4l_up << "] for " << _s_process.at(i_proc) << ", final state " << _s_final_state.at(i_fs) << ", category " << _s_category.at(i_cat) << ": " << histos_1D[Settings::M4lMain][i_fs][i_cat][Settings::all_resonant][i_proc]->Integral(histos_1D[Settings::M4lMain][i_fs][i_cat][Settings::all_resonant][i_proc]->FindBin(M4l_down), histos_1D[Settings::M4lMain][i_fs][i_cat][Settings::all_resonant][i_proc]->FindBin(M4l_up)) << endl;
            
         }
         
      }
   }
   
   // Z+X
   for ( int i_fs = 0; i_fs < num_of_final_states; i_fs++ )
   {
      for ( int i_cat = 0; i_cat < num_of_categories; i_cat++ )
      {
         cout << "Yield in mass range [" << M4l_down << "," << M4l_up << "] for Z+X, final state " << _s_final_state.at(i_fs) << ", category " << _s_category.at(i_cat) << ": " << histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat]->Integral(histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat]->FindBin(M4l_down), histos_1D_ZX_shape[Settings::M4lMain][i_fs][i_cat]->FindBin(M4l_up)) << endl;
      }
   }
}
//========================================================================================================


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
   else if (variable_name == "M4lMainHighMass")    return bool(Variables::M4lMainHighMass().var_log_x);
   
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
   else if (variable_name == "M4lMainHighMass")    return bool(Variables::M4lMainHighMass().var_log_y);
   
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



//========================================================================================
TLegend* Histograms::CreateLegend( string position, TH1F *data, TH1F *h125,TH1F *qqZZ,TH1F *ggZZ,TH1F *ZX )
{
   TLegend *leg;
   if(position == "right") leg = new TLegend( .73, .72, .97, .9 );
   else if(position == "left") leg = new TLegend(.14,.72,.38,.9);
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
//========================================================================================

//========================================================================================
TLegend* Histograms::CreateLegendVBF( string position, TH1F *data, TH1F *h125VBF, TH1F *h125other,TH1F *qqZZ,TH1F *ggZZ,TH1F *ZX )
{
   TLegend *leg;
   if(position == "right") leg = new TLegend( .70, .72, .95, .9 );
   else if(position == "left") leg = new TLegend(.14,.72,.38,.9);
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
//========================================================================================

//========================================================================================
TLegend* Histograms::CreateLegendVH( string position, TH1F *data, TH1F *h125VH, TH1F *h125other,TH1F *qqZZ,TH1F *ggZZ,TH1F *ZX )
{
   TLegend *leg;
   if(position == "right") leg = new TLegend( .70, .72, .95, .9 );
   else if(position == "left") leg = new TLegend(.14,.72,.38,.9);
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
//========================================================================================

//========================================================================================
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
//========================================================================================

//========================================================================================
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
   float y_latex = -0.6;
       
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

//==============================================
void Histograms::MakeCOLZGrey(bool shift)
{
   int col = 1;
   const Int_t NRGBs = 2;
   const Int_t NCont = 255;
   Double_t stops[NRGBs] = { 0.00, 1.00 };
   Double_t red[NRGBs]   = { 1., 0.5 };
   Double_t green[NRGBs] = { 1., 0.5 };
   Double_t blue[NRGBs]  = { 1., 0.5 };
   if(shift){
      for(int i=0; i<NRGBs; i++){
         red  [i] -= 0.10;
         green[i] -= 0.10;
         blue [i] -= 0.10;
      }
   }
   TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
   gStyle->SetNumberContours(NCont);
}
//==============================================
