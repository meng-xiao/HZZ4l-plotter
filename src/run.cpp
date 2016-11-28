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

//	gROOT->ProcessLine(".L ./tdrstyle.C+");
//	gROOT->ProcessLine("setTDRStyle();");

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
   
   plotter->GetHistos( "Blinded_110_150_test.root" );
   plotter->Plot1D( "M4lV1b", 4, 1 );
   
   
   
//   cout << Variables::M4lV2().var_Y_label << endl;
   
}
