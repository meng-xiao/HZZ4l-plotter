// C++
#include <iostream>
#include <fstream>
#include <string>

// ROOT
#include "TApplication.h"
#include <TROOT.h>
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"

// My own files
#include "Plotter.h"
#include "Variables.h"

using namespace std;

int main( int argc, char *argv[] )
{
   gROOT->ProcessLine(".L ./ext/setTDRStyle_cpp.so");
   gROOT->ProcessLine("setTDRStyle();");

   TString path = "ICHEP_2016/";
   TString file_name = "/ZZ4lAnalysis.root";
   TString file_name_FR = "/FakeRate_SS_2016B.root";
   
   TString Data        = path + "Data" + file_name;
   TString ggH125      = path + "ggH125" + file_name;
   TString VBFH125     = path + "VBFH125" + file_name;
   TString WpH125      = path + "WpH125" + file_name;
   TString WmH125      = path + "WmH125" + file_name;
   TString ZH125       = path + "ZH125" + file_name;
   TString ttH125      = path + "ttH125" + file_name;
   TString ZZTo4l      = path + "ZZTo4l" + file_name;
   TString ggZZ4e      = path + "ggTo4e" + file_name;
   TString ggZZ4mu     = path + "ggTo4mu" + file_name;
   TString ggZZ4tau    = path + "ggTo4tau" + file_name;
   TString ggZZ2e2mu   = path + "ggTo2e2mu" + file_name;
   TString ggZZ2e2tau  = path + "ggTo2e2tau" + file_name;
   TString ggZZ2mu2tau = path + "ggTo2mu2tau" + file_name;
   TString FakeRates   = path + "FakeRates" + file_name_FR;

   Plotter *plotter = new Plotter();

 
   plotter->SetBlinding(110, 150);
 
   plotter->MakeHistograms(Data);
   plotter->MakeHistograms(ggH125);
   plotter->MakeHistograms(VBFH125);
   plotter->MakeHistograms(ZH125);
   plotter->MakeHistograms(ttH125);
   plotter->MakeHistograms(ZZTo4l);
   plotter->MakeHistograms(ggZZ4e);
   plotter->MakeHistograms(ggZZ4mu);
   plotter->MakeHistograms(ggZZ4tau);
   plotter->MakeHistograms(ggZZ2e2mu);
   plotter->MakeHistograms(ggZZ2e2tau);
   plotter->MakeHistograms(ggZZ2mu2tau);

   plotter->MakeHistogramsZX(Data, FakeRates);
   plotter->MakeM4lZX();
   
   plotter->FillInclusive();

   plotter->Save();
   plotter->SaveYields();
   plotter->Delete();

  //===========================
  // Plotting of blinded plots
  //===========================
//   plotter->GetHistos( "Blinded" );
//   plotter->Plot1D_allCAT( "Blinded", "M4lMain", "Plots");
//   plotter->Plot1D_allFS( "Blinded", "M4lMain", "Plots");
//   plotter->Plot1D_allCAT( "Blinded", "M4lMainZoomed", "Plots");
//   plotter->Plot1D_allFS( "Blinded", "M4lMainZoomed", "Plots");
//   plotter->Plot1D_allCAT( "Blinded", "MZ1", "Plots");
//   plotter->Plot1D_allCAT( "Blinded", "MZ2", "Plots");
//   plotter->Plot1D_allFS( "Blinded", "MZ1", "Plots");
//   plotter->Plot1D_allFS( "Blinded", "MZ2", "Plots");
   
   //=============================
   // Plotting of unblinded plots
   //=============================
//   plotter->GetHistos( "Unblinded" );
//   plotter->Plot1D_allCAT( "Unblinded", "M4lMain" , "Plots");
//   plotter->Plot1D_allFS( "Unblinded", "M4lMain" , "Plots");
//   plotter->Plot1D_allCAT( "Unblinded", "M4lMainZoomed" , "Plots");
//   plotter->Plot1D_allFS( "Unblinded", "M4lMainZoomed" , "Plots");
//   plotter->Plot1D_allCAT( "Unblinded", "MZ1", "Plots");
//   plotter->Plot1D_allFS( "Unblinded", "MZ1", "Plots");
//   plotter->Plot1D_allCAT( "Unblinded", "MZ1_M4L118130", "Plots");
//   plotter->Plot1D_allFS( "Unblinded", "MZ1_M4L118130", "Plots");
//   plotter->Plot1D_allCAT( "Unblinded", "MZ2", "Plots");
//   plotter->Plot1D_allFS( "Unblinded", "MZ2", "Plots");
//   plotter->Plot1D_allCAT( "Unblinded", "MZ2_M4L118130", "Plots");
//   plotter->Plot1D_allFS( "Unblinded", "MZ2_M4L118130", "Plots");
//   
   
//   plotter->Plot1D_single( "Unblinded", "KD", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "MZ1", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "D1jet", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "D2jet", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "DWH", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "DZH", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "KD_M4L118130", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "D1jet_M4L118130", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "D2jet_M4L118130", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "DWH_M4L118130", "Plots", 4, 6);
//   plotter->Plot1D_single( "Unblinded", "DZH_M4L118130", "Plots", 4, 6);
}
