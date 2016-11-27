// Include classes
#include "M4lZX.h"

using namespace std;

// Constructor
//============
M4lZX::M4lZX()
{
   _n_entries = 1000000;
   
   // Z+X normalization from combination of SS and OS method
   _norm_ZX_full_SR_4e    = 9.8;
   _norm_ZX_full_SR_4mu   = 10.2; // To be defined for the 2016 dataset
   _norm_ZX_full_SR_2e2mu = 20.4; // To be defined for the 2016 dataset
   
   f_4e_comb    = new TF1("f_4e_comb", "landau(0)*(1 + exp( pol1(3))) + [5]*(TMath::Landau(x, [6], [7]))", 70, 1000);
   f_4mu_comb   = new TF1("f_4mu_comb","landau(0)", 70, 1000);
   f_2e2mu_comb = new TF1("f_2e2mu_comb","landau(0)", 70, 1000);

   f_4e_comb->SetParameters(4.404e-05, 151.2, 36.6, 7.06, -0.00497, 0.01446, 157.3, 26.00);
   f_4mu_comb->SetParameters(0.04276, 134.6, 24.4);
   f_2e2mu_comb->SetParameters(0.04130, 144.5, 25.3);

   h_full_range_4mu   = new TH1F("h_full_range_4mu"  , ";;", 1000, 0, 1000);
   h_full_range_4e    = new TH1F("h_full_range_4e"   , ";;", 1000, 0, 1000);
   h_full_range_2e2mu = new TH1F("h_full_range_2e2mu", ";;", 1000, 0, 1000);
   
}
//=====================


//================
M4lZX::~M4lZX() {}
//================


//===================================================================================
TH1F *M4lZX::GetM4lZX(int n_bins, int x_min, int x_max, int final_state, double lumi)
{

   h_full_range_4mu  ->FillRandom("f_4mu_comb"  , _n_entries);
   h_full_range_4e   ->FillRandom("f_4e_comb"   , _n_entries);
   h_full_range_2e2mu->FillRandom("f_2e2mu_comb", _n_entries);
  
   _norm_4mu = _norm_ZX_full_SR_4mu * h_full_range_4mu->Integral(h_full_range_4mu->FindBin(x_min), h_full_range_4mu->FindBin(x_max)-1) / h_full_range_4mu->Integral();
   _norm_4e = _norm_ZX_full_SR_4e * h_full_range_4e->Integral(h_full_range_4e->FindBin(x_min), h_full_range_4e->FindBin(x_max)-1) / h_full_range_4e->Integral();
   _norm_2e2mu = _norm_ZX_full_SR_2e2mu * h_full_range_2e2mu->Integral(h_full_range_2e2mu->FindBin(x_min), h_full_range_2e2mu->FindBin(x_max)-1) / h_full_range_2e2mu->Integral();
   
   delete h_full_range_4e;
   delete h_full_range_4mu;
   delete h_full_range_2e2mu;

   cout << "[INFO] In function GetM4lZX, x_min = " << x_min << ", x_max = " << x_max << ", " << endl;
   cout << "yield in 4mu      = " << _norm_4mu << endl;
   cout << "yield in 4e       = " << _norm_4e << endl;
   cout << "yield in 2e2mu    = " << _norm_2e2mu << endl;
   cout << "total yield in 4l = " << _norm_4mu + _norm_4e + _norm_2e2mu << endl;

   h_4mu   = new TH1F("h_4mu"  , ";;", n_bins, x_min, x_max);
   h_4e    = new TH1F("h_4e"   , ";;", n_bins, x_min, x_max);
   h_2e2mu = new TH1F("h_2e2mu", ";;", n_bins, x_min, x_max);
   h_4l     = new TH1F("h_4l"   , ";;", n_bins, x_min, x_max);
 
   h_4mu  ->FillRandom("f_4mu_comb"  , _n_entries);
   h_4e   ->FillRandom("f_4e_comb"   , _n_entries);
   h_2e2mu->FillRandom("f_2e2mu_comb", _n_entries);
  
   h_4mu  ->Scale(_norm_4mu   / h_4mu->Integral());
   h_4e   ->Scale(_norm_4e    / h_4e->Integral());
   h_2e2mu->Scale(_norm_2e2mu / h_2e2mu->Integral());
  
   h_4l->Add(h_4mu);
   h_4l->Add(h_4e);
   h_4l->Add(h_2e2mu);
	
   if ( final_state == Settings::fs4mu ) return h_4mu;
   else if (final_state == Settings::fs4e) return h_4e;
   else if (final_state == Settings::fs2e2mu) return h_2e2mu;
   else if (final_state == Settings::num_of_final_states - 1) return h_4l;
   else
   {
      cout << "[ERROR] Computing Z+X histogram: wrong final state" << endl;
      abort();
   }

}
//===================================================================================



//==========================================================================
void M4lZX::RenormalizeZX( vector<float> expected_yield_SR, TH1F* M4lV1_ZX )
{
   // TBD
}
//==========================================================================
