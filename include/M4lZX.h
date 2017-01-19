#ifndef M4lZX_h
#define M4lZX_h

// ROOT
#include "TF1.h"
#include "TH1F.h"

#include "Settings.h"

using namespace std;

class M4lZX
{

public:
	
	M4lZX();
	~M4lZX();
   TH1F *GetM4lZX( int, int, int, int, int);
   void RenormalizeZX( int, TH1F* , TH1F*, TH1F* );
   void SetNormalization ( int );
   
   float GetNormZXFullSR4e()    { return _norm_ZX_full_SR_4e; };
   float GetNormZXFullSR4mu()   { return _norm_ZX_full_SR_4mu; };
   float GetNormZXFullSR2e2mu() { return _norm_ZX_full_SR_2e2mu; };

private:
   
   TF1 *f_4e_comb, *f_4mu_comb, *f_2e2mu_comb;
   TH1F *h_full_range_4mu, *h_full_range_4e, *h_full_range_2e2mu, *h_4mu, *h_4e, *h_2e2mu, *h_4l;
   
   
   int _n_entries;
   float _norm_4mu, _norm_4e, _norm_2e2mu, _norm_ZX_full_SR_4e, _norm_ZX_full_SR_4mu, _norm_ZX_full_SR_2e2mu;
   
};

#endif
