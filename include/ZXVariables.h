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
       float norm_combined         = 18.4 * 1.1;
       float norm_inclusive        = 18.4 * 1.1;
       float N = norm_combined/norm_inclusive * 1.1;
       float norm_untagged         = 15.4 * N;
       float norm_VBF_1j_tagged    = 0.9 * N;
       float norm_VBF_2j_tagged    = 1.3 * N;
       float norm_VH_lepton_tagged = 0.17 * N;
       float norm_VH_hadron_tagged = 0.28 * N;
       float norm_ttH_tagged       = 0.36 * N;
       
       
       float par0 = 141.9;
       float par1 = 21.3;
   };
    
    struct ZX4mu
    {
        float norm_combined         = 30.8 * 1.1;
        float norm_inclusive        = 30.8 * 1.1;
        float N = norm_combined/norm_inclusive * 1.1;
        float norm_untagged         = 24.9 * N;
        float norm_VBF_1j_tagged    = 1.7 * N;
        float norm_VBF_2j_tagged    = 2.1 * N;
        float norm_VH_lepton_tagged = 0.36 * N;
        float norm_VH_hadron_tagged = 0.9 * N;
        float norm_ttH_tagged       = 0.8 * N;
        
        
        float par0 = 130.4;
        float par1 = 15.6;
     };
   
    struct ZX2e2mu
    {
        float norm_combined         = (26.7 + 22.9) * 1.1;
        float norm_inclusive        = (26.7 + 22.9) * 1.1;
        float N = norm_combined/norm_inclusive * 1.1;
        float norm_untagged         = (21.6 + 19.1) * N;
        float norm_VBF_1j_tagged    = (1.6 + 1) * N;
        float norm_VBF_2j_tagged    = (1.4 + 1.7) * N;
        float norm_VH_lepton_tagged = (0.4 + 0.2) * N;
        float norm_VH_hadron_tagged = (0.8 + 0.4) * N;
        float norm_ttH_tagged       = (0.8 + 0.4) * N;
        
        
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
