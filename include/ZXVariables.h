#ifndef ZXVariables_h
#define ZXVariables_h

// C++
#include <iostream>

using namespace std;

class ZXVariables
{
   
public:
   ZXVariables ();
   ~ZXVariables();
   
   struct ZX4e
   {
       float OS_norm_inclusive        = 21.1;
       float OS_norm_untagged         = 0.;
       float OS_norm_VBF_1j_tagged    = 0.;
       float OS_norm_VBF_2j_tagged    = 0.;
       float OS_norm_VH_lepton_tagged = 0.;
       float OS_norm_VH_hadron_tagged = 0.;
       float OS_norm_ttH_tagged       = 0.;
       float OS_norm_VH_MET_tagged    = 0.;
       
       float par0 = 141.9;
       float par1 = 21.3;
   };
    
    struct ZX4mu
    {
        float OS_norm_inclusive        = 34.4;
        float OS_norm_untagged         = 0.;
        float OS_norm_VBF_1j_tagged    = 0.;
        float OS_norm_VBF_2j_tagged    = 0.;
        float OS_norm_VH_lepton_tagged = 0.;
        float OS_norm_VH_hadron_tagged = 0.;
        float OS_norm_ttH_tagged       = 0.;
        float OS_norm_VH_MET_tagged    = 0.;
       
        float par0 = 130.4;
        float par1 = 15.6;
     };
   
    struct ZX2e2mu
    {
        float OS_norm_inclusive        = 59.9;
        float OS_norm_untagged         = 0.;
        float OS_norm_VBF_1j_tagged    = 0.;
        float OS_norm_VBF_2j_tagged    = 0.;
        float OS_norm_VH_lepton_tagged = 0.;
        float OS_norm_VH_hadron_tagged = 0.;
        float OS_norm_ttH_tagged       = 0.;
        float OS_norm_VH_MET_tagged    = 0.;
        
        float par0 = 0.45;
        float par1 = 131.1;
        float par2 = 18.1;
        float par3 = 0.55;
        float par4 = 133.8;
        float par5 = 18.9;        
    };
private:

};

#endif