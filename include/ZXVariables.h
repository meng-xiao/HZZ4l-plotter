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
       float norm_combined         = 20.3;
       float norm_inclusive        = 20.3;
       float N = norm_combined/norm_inclusive ;
       float norm_untagged         = 17.1 * N;
       float norm_VBF_1j_tagged    = 1.4  * N;
       float norm_VBF_2j_tagged    = 0.97 * N;
       float norm_VH_lepton_tagged = 0.18 * N;
       float norm_VH_hadron_tagged = 0.31 * N;
       float norm_ttH_tagged       = 0.38 * N;
       
       
       float par0 = 141.9;
       float par1 = 21.3;
   };
    
    struct ZX4mu
    {
        float norm_combined         = 33.5;
        float norm_inclusive        = 33.5;
        float N = norm_combined/norm_inclusive;
        float norm_untagged         = 27  * N;
        float norm_VBF_1j_tagged    = 2.3 * N;
        float norm_VBF_2j_tagged    = 1.98 * N;
        float norm_VH_lepton_tagged = 0.37 * N;
        float norm_VH_hadron_tagged = 0.96 * N;
        float norm_ttH_tagged       = 0.9 * N;
        
        
        float par0 = 130.4;
        float par1 = 15.6;
     };
   
    struct ZX2e2mu
    {
        float norm_combined         = (29.1 + 25.5);
        float norm_inclusive        = (29.1 + 25.5);
        float N = norm_combined/norm_inclusive;
        float norm_untagged         = (23.5 + 21.4) * N;
        float norm_VBF_1j_tagged    = (1.6 + 1.8) * N;
        float norm_VBF_2j_tagged    = (1.8 + 1.14) * N;
        float norm_VH_lepton_tagged = (0.5 + 0.25) * N;
        float norm_VH_hadron_tagged = (0.87 + 0.43) * N;
        float norm_ttH_tagged       = (0.83 + 0.47) * N;
        
        
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