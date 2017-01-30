#ifndef Histograms_h
#define Histograms_h

// C++
#include <iostream>
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
#include "TLatex.h"
#include "TStyle.h"
#include "TPaletteAxis.h"

// Include classes
#include "Settings.h"
#include "M4lZX.h"
#include "CMS_lumi.h"

using namespace std;

const int num_of_processes         = Settings::num_of_processes;
const int num_of_processes_yields  = Settings::num_of_processes_yields;
const int num_of_final_states      = Settings::num_of_final_states;
const int num_of_resonant_statuses = Settings::num_of_res_statuses;
const int num_of_categories        = Settings::num_of_categories;
const int num_of_1Dplot_names      = Settings::num_of_1Dplot_names;
const int num_of_2Dplot_names      = Settings::num_of_2Dplot_names;
const int num_of_2DErrorplot_names = Settings::num_of_2DErrorplot_names;


class Histograms
{
   
public:
   Histograms();
   Histograms( string );
   ~Histograms();
   void FillM4l( float, float, int, int, int, int );
   void FillM4lZX( float, float, int, int );
   
   void FillMZ1( float, float, float, int, int, int, int );
   void FillMZ1ZX( float, float, float, int, int );
   
   void FillMZ2( float, float, float, int, int, int, int );
   void FillMZ2ZX( float, float, float, int, int );
   
   void FillKD( float, float, float, int, int, int, int );
   void FillKDZX( float, float, float, int, int );
   
   void FillD1jet( float, float, float, int, int, int, int );
   void FillD1jetZX( float, float, float, int, int );
   
   void FillD2jet( float, float, float, int, int, int, int );
   void FillD2jetZX( float, float, float, int, int );
   
   void FillDWH( float, float, float, int, int, int, int );
   void FillDWHZX( float, float, float, int, int );
   
   void FillDZH( float, float, float, int, int, int, int );
   void FillDZHZX( float, float, float, int, int );
   
   void FillMZ1vsMZ2( float, float, float, float, int, int, int, int );
   
   void FillVectors( float, float, float, int, float, float, float, float, int, int) ;
   void FillDvsM4l( float, float, int, float, float, float, float, float, int, int, int, int );
   
   void FillYields( float, float, int, int, int, int );
   
   void SaveHistos( string );
   void SaveYieldHistos( string );
   void DeleteHistos();
   void DeleteYieldsHistos();
   void FillInclusive();
   void FillInclusiveYields();
   void SmoothHistograms();
   void RenormalizeZX(vector< vector <float> >);
   void GetHistos( TString );
   void GetYieldsHistos( TString );
   void Plot1D_single( TString, TString, TString, int, int );
   void Plot1D_allCAT( TString, TString, TString );
   void Plot1D_allFS( TString, TString, TString );
   void Plot2D_single( TString, TString, TString, int );
   void Plot2DError_single( TString, TString, TString, int );
   void PrintYields( );
   void PrintYields( float, float);
   void setColZGradient_OneColor(int , bool);
   void MakeZXShape(int, int);
   void MakeZXShapeYields(int, int);
   int SetPlotName( TString );
   bool GetVarLogX( TString );
   bool GetVarLogY( TString );
   TLegend* CreateLegend( string, TH1F*, TH1F*, TH1F*, TH1F*, TH1F* );
   TLegend* CreateLegendVBF( string, TH1F*, TH1F*, TH1F*, TH1F*, TH1F* ,TH1F* );
   TLegend* CreateLegendVH( string, TH1F*, TH1F*, TH1F*, TH1F*, TH1F* ,TH1F* );
   TLegend* Create2DLegend( string, TH2F*, TH2F*, TH2F*);
   TLegend* Create2DErrorLegend( string, TGraphErrors*, TGraphErrors*, TGraphErrors*);
   void DrawLogX( TCanvas *, int );
   void MakeCOLZGrey( bool );
   
private:
   
   float _y_max;

   vector<string> _s_category, _s_resonant_status, _s_final_state, _s_process;
   string _histo_name, _histo_labels, _blinding;
   
   //==========
   // 1D plots
   //==========
   TH1F *histos_1D[num_of_1Dplot_names][num_of_final_states][num_of_categories][num_of_resonant_statuses][num_of_processes_yields];
   
   // Z+X
   TH1F *histos_1D_ZX[num_of_1Dplot_names][num_of_final_states][num_of_categories];
   TH1F *histos_1D_ZX_shape[num_of_1Dplot_names][num_of_final_states][num_of_categories];
   
   //==========
   // 2D plots
   //==========
   TH2F *histos_2D[num_of_2Dplot_names][num_of_final_states][num_of_categories][num_of_resonant_statuses][num_of_processes];
   
   //==========================
   // 2D plots with mass error
   //==========================
   
   // Data
   TGraphErrors *histos_2DError_data[num_of_2DErrorplot_names][num_of_final_states][num_of_categories];
   
   vector<Float_t> vector_X[num_of_2DErrorplot_names][num_of_final_states][num_of_categories];
   vector<Float_t> vector_Y[num_of_2DErrorplot_names][num_of_final_states][num_of_categories];
   vector<Float_t> vector_EX[num_of_2DErrorplot_names][num_of_final_states][num_of_categories];
   vector<Float_t> vector_EY[num_of_2DErrorplot_names][num_of_final_states][num_of_categories];
   
   // MC
   TH2F *histos_2DError[num_of_2DErrorplot_names][num_of_final_states][num_of_categories][num_of_resonant_statuses][num_of_processes];
};
#endif