#ifndef Histograms_h
#define Histograms_h

// C++
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

// ROOT
#include "TH1F.h"
#include "TH2F.h"
#include "TGraphErrors.h"
#include "TMath.h"
#include "TString.h"
#include "TFile.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"
#include "TLine.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TPaletteAxis.h"
#include "TPaveText.h"
#include "TSystem.h"
#include "TIterator.h"
#include "TROOT.h"

// Include classes
#include "Settings.h"
#include "M4lZX.h"
#include "CMS_lumi.h"
#include "Variables.h"
#include "Cosmetics.h"


using namespace std;

const int num_of_production_modes    = Settings::num_of_production_modes;
const int num_of_processes           = Settings::num_of_processes;
const int num_of_processes_yields    = Settings::num_of_processes_yields;
const int num_of_processes_AC        = Settings::num_of_processes_AC;
const int num_of_final_states        = Settings::num_of_final_states;
const int num_of_categories          = Settings::num_of_categories;
const int num_of_categories_AC       = Settings::num_of_categories_AC;
const int num_of_1D_plot_names       = Settings::num_of_1D_plot_names;
const int num_of_2D_plot_names       = Settings::num_of_2D_plot_names;
const int num_of_2D_error_plot_names = Settings::num_of_2D_error_plot_names;
const int num_of_1D_ACplot_names     = Settings::num_of_1D_ACplot_names;
const int num_of_2D_ACplot_names     = Settings::num_of_2D_ACplot_names;
const int num_of_m4l_slices          = Settings::num_of_m4l_slices;


class Histograms
{
   
public:
   Histograms( double );
   Histograms( double, string );
   Histograms( double, int );
   ~Histograms();
   
   void FillM4l( float, float, int, int, int );
   void FillM4lZX( float, float, int, int );
   
   void FillMZ1( float, float, float, int, int, int );
   void FillMZ1ZX( float, float, float, int, int );
   
   void FillMZ2( float, float, float, int, int, int );
   void FillMZ2ZX( float, float, float, int, int );
   
   void FillKD( float, float, float, int, int, int );
   void FillKDZX( float, float, float, int, int );
   
   void FillD1jet( float, float, float, int, int, int );
   void FillD1jetZX( float, float, float, int, int );
   
   void FillD2jet( float, float, float, int, int, int );
   void FillD2jetZX( float, float, float, int, int );
   
   void FillDWH( float, float, float, int, int, int );
   void FillDWHZX( float, float, float, int, int );
   
   void FillDZH( float, float, float, int, int, int );
   void FillDZHZX( float, float, float, int, int );
   
   void FillMZ1vsMZ2( float, float, float, float, int, int, int );
   
   void FillVectors( float, float, float, int, float, float, float, float, int, int) ;
   void FillDvsM4l( float, float, int, float, float, float, float, float, int, int, int );
   
   void FillACHistos( int, int, int, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
   void FillACZXHistos( int, int, int, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
   
   void FillYields( float, float, int, int, int );
   
   void SaveHistos( TString );
   void SaveYieldHistos( TString );
   void SaveACHistos( TString );
   void DeleteHistos();
   void DeleteYieldsHistos();
   void DeleteACHistos();
   void FillInclusive();
   void FillInclusiveYields();
   void FillInclusiveAC();
   void SmoothHistograms();
   void RenormalizeZX( vector<vector<float>> );
   void GetHistos( TString );
   void GetYieldsHistos( TString );
   void GetACHistos( TString );
   void Plot1D_single( TString, TString, TString, int, int );
   void Plot1D_all_cat( TString, TString, TString );
   void Plot1D_allFS( TString, TString, TString );
   void Plot2D_single( TString, TString, TString, int );
   void Plot2DError_single( TString, TString, TString, int );
   void Plot2DErrorAllCat( TString , TString , TString );
   void Plot1D_AC_SMvsBSM( TString, TString );
   void Plot1D_AC_SMvsBSM_bkg( TString, TString );
   void Plot2D_AC_SMvsBSM( TString, TString );
   void FillYieldGraphs( float, float );
   void PrepareYamlFiles( TString , float , float, vector<vector<float>> );
   void PrintYields( vector<vector<float>> );
   void PrintYields( float, float, vector<vector<float>> );
   void PrintLatexTables( float, float, vector<vector<float>> );
   void setColZGradient_OneColor( int , bool );
   void MakeZXShape( vector<vector<float>>, int );
   void DrawLogX( TCanvas *, int, int );
   void MakeCOLZGrey( bool );
   void ConditionalizeInM4L();
   void SavePlots( TCanvas *, TString );
   void Rebin( THStack * );
   void ChangeYaxisTitle( THStack * );
   int SetProcess( int, int );
   int SetPlotName( TString );
   float SetMassPoint( int );
   bool GetVarLogX( TString );
   bool GetVarLogY( TString );
   
   TLegend *CreateLegend( string, TH1F*, TH1F*, TH1F*, TH1F*, TH1F* );
   TLegend *CreateLegendVBF( string, TH1F*, TH1F*, TH1F*, TH1F*, TH1F* ,TH1F* );
   TLegend *CreateLegendVH( string, TH1F*, TH1F*, TH1F*, TH1F*, TH1F* ,TH1F* );
   TLegend *CreateLegendttH( string, TH1F*, TH1F*, TH1F*, TH1F*, TH1F* ,TH1F* );
   TLegend *Create2DLegend( string, TH2F*, TH2F*, TH2F* );
   TLegend *Create2DErrorLegend( string, TGraphErrors*, TGraphErrors*, TGraphErrors* );
   TLegend *Create2DLegendAllCat( string, TGraphErrors*, TGraphErrors*, TGraphErrors*, TGraphErrors*, TGraphErrors*, TGraphErrors*, TGraphErrors*, TGraphErrors*, TGraphErrors*, TGraphErrors* );
   
   TPaveText *CreateCutText( string, TString);
   TPaveText *CreateCatText( string, TString);
   
   TLine *CreateDashedLine( int );
   

private:
      
   float _lumi, _y_max;
   bool VBF_tagged_, VH_tagged_, ttH_tagged_;

   vector<double> mass_points;

   vector<TString> _s_category, _s_category_label, _s_final_state, _s_process, _s_production_mode, _s_m4l_slice;
   string _histo_name, _histo_labels, _blinding;
   
   TString _graph_name, _fit_funct_name, _fs_label, _out_file_name;
   
//==========
// 1D plots
//==========
   TH1F *histos_1D[num_of_1D_plot_names][num_of_final_states][num_of_categories][num_of_processes_yields];
   TH1F *histos_1D_AC[num_of_1D_ACplot_names][num_of_m4l_slices][num_of_final_states][num_of_categories_AC][num_of_processes_AC];
   
   // Z+X
   TH1F *histos_1D_ZX[num_of_1D_plot_names][num_of_final_states][num_of_categories];
   TH1F *histos_1D_ZX_shape[num_of_1D_plot_names][num_of_final_states][num_of_categories];
   TH1F *histos_1D_ZX_AC[num_of_1D_ACplot_names][num_of_m4l_slices][num_of_final_states][num_of_categories_AC][num_of_processes_AC];
   
//==========
// 2D plots
//==========
   TH2F *histos_2D[num_of_2D_plot_names][num_of_final_states][num_of_categories][num_of_processes];
   TH2F *histos_2D_AC[num_of_2D_ACplot_names][num_of_final_states][num_of_categories_AC][num_of_processes_AC];
   
//==========================
// 2D plots with mass error
//==========================
   
   // Data
   TGraphErrors *histos_2DError_data[num_of_2D_error_plot_names][num_of_final_states][num_of_categories];
   
   vector<Float_t> vector_X[num_of_2D_error_plot_names][num_of_final_states][num_of_categories];
   vector<Float_t> vector_Y[num_of_2D_error_plot_names][num_of_final_states][num_of_categories];
   vector<Float_t> vector_EX[num_of_2D_error_plot_names][num_of_final_states][num_of_categories];
   vector<Float_t> vector_EY[num_of_2D_error_plot_names][num_of_final_states][num_of_categories];
   
   // MC
   TH2F *histos_2DError[num_of_2D_error_plot_names][num_of_final_states][num_of_categories][num_of_processes];
   
//==========================
// Graphs for yields vs mH
//==========================
   TGraphErrors *yields_graph[num_of_final_states][num_of_categories][num_of_production_modes];
};
#endif
