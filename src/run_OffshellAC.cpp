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
#include "Offshell_AC.h"
#include "Variables.h"

using namespace std;

int main( int argc, char *argv[] )
{
   gROOT->ProcessLine(".L ./ext/setTDRStyle_cpp.so");
   gROOT->ProcessLine("setTDRStyle();");

   TString path = "Moriond_2017/";
   TString file_name = "/ZZ4lAnalysis.root";
   TString file_name_FR = "/FakeRate_SS_Moriond368.root";
   
   //Data
   TString Data        = path + "Data" + file_name;
   TString FakeRates   = path + "FakeRates" + file_name_FR;
   
   // SM POWHEG Signal
   TString ggH125      = path + "ggH125" + file_name;
   TString VBFH125     = path + "VBFH125" + file_name;
   TString WpH125      = path + "WplusH125" + file_name;
   TString WmH125      = path + "WminusH125" + file_name;
   TString ZH125       = path + "ZH125" + file_name;
   TString ttH125      = path + "ttH125" + file_name;
   
   // SM MCFM Signal
   TString ggTo4e_0PM     = path + "ggTo4e_0PMH125_MCFM701" + file_name;
   TString ggTo4mu_0PM    = path + "ggTo4mu_0PMH125_MCFM701" + file_name;
   TString ggTo2e2mu_0PM  = path + "ggTo2e2mu_0PMH125_MCFM701" + file_name;
   
   
   // BSM Signal
   TString ggTo4e_0MH     = path + "ggTo4e_0MHH125_MCFM701" + file_name;
   TString ggTo4mu_0MH    = path + "ggTo4mu_0MHH125_MCFM701" + file_name;
   TString ggTo2e2mu_0MH  = path + "ggTo2e2mu_0MHH125_MCFM701" + file_name;
   
   TString ggTo4e_0PH     = path + "ggTo4e_0PHH125_MCFM701" + file_name;
   TString ggTo4mu_0PH    = path + "ggTo4mu_0PHH125_MCFM701" + file_name;
   TString ggTo2e2mu_0PH  = path + "ggTo2e2mu_0PHH125_MCFM701" + file_name;
   
   TString ggTo4e_0PL1     = path + "ggTo4e_0PL1H125_MCFM701" + file_name;
   TString ggTo4mu_0PL1    = path + "ggTo4mu_0PL1H125_MCFM701" + file_name;
   TString ggTo2e2mu_0PL1  = path + "ggTo2e2mu_0PL1H125_MCFM701" + file_name;
   
   
   // Backgrounds
   TString ZZTo4l      = path + "ZZTo4l" + file_name;
   TString ggZZ4e      = path + "ggTo4e" + file_name;
   TString ggZZ4mu     = path + "ggTo4mu" + file_name;
   TString ggZZ4tau    = path + "ggTo4tau" + file_name;
   TString ggZZ2e2mu   = path + "ggTo2e2mu" + file_name;
   TString ggZZ2e2tau  = path + "ggTo2e2tau" + file_name;
   TString ggZZ2mu2tau = path + "ggTo2mu2tau" + file_name;
   
   // SM - bkg interference MCFM Signal
   
   // BSM - bkg interference MCFM Signal
   
   // SM - BSM interference MCFM Signal
   
   Offshell_AC *offshell_AC = new Offshell_AC( 35.867);
   
//===============
// Produce plots 
//===============
   // DATA
   offshell_AC->MakeHistograms(Data);
   
   // POWHEG SM SIGNAL
   offshell_AC->MakeHistograms(ggH125);
   offshell_AC->MakeHistograms(VBFH125);
   offshell_AC->MakeHistograms(WpH125);
   offshell_AC->MakeHistograms(WmH125);
   offshell_AC->MakeHistograms(ZH125);
   offshell_AC->MakeHistograms(ttH125);
   
   // MCFM SM SIGNAL
   offshell_AC->MakeHistograms(ggTo4e_0MH);
   offshell_AC->MakeHistograms(ggTo4mu_0MH);
   offshell_AC->MakeHistograms(ggTo2e2mu_0MH);
   
   // SM Background
   offshell_AC->MakeHistograms(ZZTo4l);
   offshell_AC->MakeHistograms(ggZZ4e);
   offshell_AC->MakeHistograms(ggZZ4mu);
   offshell_AC->MakeHistograms(ggZZ2e2mu);
   offshell_AC->MakeHistogramsZX(Data, FakeRates);
   
   // DZeroMinus BSM signal
   offshell_AC->MakeHistograms(ggTo4e_0PM);
   offshell_AC->MakeHistograms(ggTo4mu_0PM);
   offshell_AC->MakeHistograms(ggTo2e2mu_0PM);
   
   // DZerohPlus BSM signal
   offshell_AC->MakeHistograms(ggTo4e_0PH);
   offshell_AC->MakeHistograms(ggTo4mu_0PH);
   offshell_AC->MakeHistograms(ggTo2e2mu_0PH);

   // DL1 BSM signal
   offshell_AC->MakeHistograms(ggTo4e_0PL1);
   offshell_AC->MakeHistograms(ggTo4mu_0PL1);
   offshell_AC->MakeHistograms(ggTo2e2mu_0PL1);
   
   offshell_AC->FillInclusive();

   offshell_AC->Save();

   offshell_AC->GetHistos("Offshell_AC");
   
   offshell_AC->Plot1D_AC_SMvsBSM("DZeroMinus", "Plots" );
   offshell_AC->Plot1D_AC_SMvsBSM("DZerohPlus", "Plots" );
   offshell_AC->Plot1D_AC_SMvsBSM("DL1", "Plots" );

   offshell_AC->Plot1D_AC_SMvsBSM_bkg("DZeroMinus", "Plots" );
   offshell_AC->Plot1D_AC_SMvsBSM_bkg("DZerohPlus", "Plots" );
   offshell_AC->Plot1D_AC_SMvsBSM_bkg("DL1", "Plots" );

   offshell_AC->Plot2D_AC_SMvsBSM("DZeroMinusvsM4l", "Plots");
   offshell_AC->Plot2D_AC_SMvsBSM("DZerohPlusvsM4l", "Plots");
   offshell_AC->Plot2D_AC_SMvsBSM("DL1vsM4l", "Plots");
   
   delete offshell_AC;
}
