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
   bool yields = 1;
   
   // Signal
   TString ggH120      = path + "ggH120" + file_name;
   TString ggH124      = path + "ggH124" + file_name;
   TString ggH125      = path + "ggH125" + file_name;
   TString ggH126      = path + "ggH126" + file_name;
   TString ggH130      = path + "ggH130" + file_name;
               
   TString VBFH120     = path + "VBFH120" + file_name;
   TString VBFH124     = path + "VBFH124" + file_name;
   TString VBFH125     = path + "VBFH125" + file_name;
   TString VBFH126     = path + "VBFH126" + file_name;
   TString VBFH130     = path + "VBFH130" + file_name;
   
   TString WpH120      = path + "WplusH120" + file_name;
   TString WpH124      = path + "WplusH124" + file_name;
   TString WpH125      = path + "WplusH125" + file_name;
   TString WpH126      = path + "WplusH126" + file_name;
   TString WpH130      = path + "WplusH130" + file_name;
    
   TString WmH120      = path + "WminusH120" + file_name;
   TString WmH124      = path + "WminusH124" + file_name;
   TString WmH125      = path + "WminusH125" + file_name;
   TString WmH126      = path + "WminusH126" + file_name;
   TString WmH130      = path + "WminusH130" + file_name;
      
   TString ZH120       = path + "ZH120" + file_name;
   TString ZH124       = path + "ZH124" + file_name;
   TString ZH125       = path + "ZH125" + file_name;
   TString ZH126       = path + "ZH126" + file_name;
   TString ZH130       = path + "ZH130" + file_name;
   
   TString ttH120      = path + "ttH120" + file_name;
   TString ttH124      = path + "ttH124" + file_name;
   TString ttH125      = path + "ttH125" + file_name;
   TString ttH126      = path + "ttH126" + file_name;
   TString ttH130      = path + "ttH130" + file_name;
   
   
   // Backgrounds
   TString ZZTo4l      = path + "ZZTo4l" + file_name;
   TString ggZZ4e      = path + "ggTo4e" + file_name;
   TString ggZZ4mu     = path + "ggTo4mu" + file_name;
   TString ggZZ4tau    = path + "ggTo4tau" + file_name;
   TString ggZZ2e2mu   = path + "ggTo2e2mu" + file_name;
   TString ggZZ2e2tau  = path + "ggTo2e2tau" + file_name;
   TString ggZZ2mu2tau = path + "ggTo2mu2tau" + file_name;
   
   Plotter *plotter = new Plotter(yields);

   plotter->MakeYieldsHistograms(ggH120);
   plotter->MakeYieldsHistograms(ggH124);
   plotter->MakeYieldsHistograms(ggH125);
   plotter->MakeYieldsHistograms(ggH126);
   plotter->MakeYieldsHistograms(ggH130);
   
   plotter->MakeYieldsHistograms(VBFH120);
   plotter->MakeYieldsHistograms(VBFH124);
   plotter->MakeYieldsHistograms(VBFH125);
   plotter->MakeYieldsHistograms(VBFH126);
   plotter->MakeYieldsHistograms(VBFH130);
   
   plotter->MakeYieldsHistograms(ZH120);
   plotter->MakeYieldsHistograms(ZH124);
   plotter->MakeYieldsHistograms(ZH125);
   plotter->MakeYieldsHistograms(ZH126);
   plotter->MakeYieldsHistograms(ZH130);
   
   plotter->MakeYieldsHistograms(ttH120);
   plotter->MakeYieldsHistograms(ttH124);
   plotter->MakeYieldsHistograms(ttH125);
   plotter->MakeYieldsHistograms(ttH126);
   plotter->MakeYieldsHistograms(ttH130);
      
   plotter->MakeYieldsHistograms(ZZTo4l);
   plotter->MakeYieldsHistograms(ggZZ4e);
   plotter->MakeYieldsHistograms(ggZZ4mu);
   plotter->MakeYieldsHistograms(ggZZ4tau);
   plotter->MakeYieldsHistograms(ggZZ2e2mu);
   plotter->MakeYieldsHistograms(ggZZ2e2tau);
   plotter->MakeYieldsHistograms(ggZZ2mu2tau);

   plotter->MakeYieldsM4lZX();
   
   plotter->FillInclusiveYields();

   plotter->SaveYields();
   plotter->DeleteYields();
   
   plotter->GetHistos("Yields");
}
