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
       
       
       float par0 = 141.9;
       float par1 = 21.3;
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
        
        
        float par0 = 130.4;
        float par1 = 15.6;
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
