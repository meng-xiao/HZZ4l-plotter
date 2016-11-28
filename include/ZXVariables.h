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
       float norm_combined         = 9.8;
       float norm_inclusive        = 9.743;
       float N = norm_combined/norm_inclusive;
       float norm_untagged         = 8.250 * N;
       float norm_VBF_1j_tagged    = 0.687 * N;
       float norm_VBF_2j_tagged    = 0.429 * N;
       float norm_VH_lepton_tagged = 0.066 * N;
       float norm_VH_hadron_tagged = 0.118 * N;
       float norm_ttH_tagged       = 0.193 * N;
       
       
       float par0 = 4.404e-05;
       float par1 = 151.2;
       float par2 = 36.6;
       float par3 = 7.06;
       float par4 = -0.00497;
       float par5 = 0.01446;
       float par6 = 157.3;
       float par7 = 26.00;
   };
    
    struct ZX4mu
    {
        float norm_combined         = 10.2;
        float norm_inclusive        = 10.950;
        float N = norm_combined/norm_inclusive;
        float norm_untagged         = 8.848 * N;
        float norm_VBF_1j_tagged    = 0.771 * N;
        float norm_VBF_2j_tagged    = 0.092 * N;
        float norm_VH_lepton_tagged = 0.208 * N;
        float norm_VH_hadron_tagged = 0.272 * N;
        float norm_ttH_tagged       = 0.193 * N;
        
        
        float par0 = 0.04276;
        float par1 = 134.6;
        float par2 = 24.4;
    };
   
    struct ZX2e2mu
    {
        float norm_combined         = 20.4;
        float norm_inclusive        = 10.476 + 11.731;
        float N = norm_combined/norm_inclusive;
        float norm_untagged         = (8.597 + 9.843) * N;
        float norm_VBF_1j_tagged    = (0.620 + 0.911) * N;
        float norm_VBF_2j_tagged    = (0.506 + 0.490) * N;
        float norm_VH_lepton_tagged = (0.180 + 0.117) * N;
        float norm_VH_hadron_tagged = (0.255 + 0.167) * N;
        float norm_ttH_tagged       = (0.319 + 0.203) * N;
        
        
        float par0 = 0.04130;
        float par1 = 144.5;
        float par2 = 25.3;
    };
private:

};

#endif
