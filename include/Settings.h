#ifndef Settings_h
#define Settings_h

using namespace std;

class Settings
{

public:
	
	Settings();
	~Settings();
   
   enum _blindings { fullyblind = 0, blindabove_110 = 1, blindbelow_150 = 2, blind_110_150 = 3, unblinded = 4 };
   enum _final_state { fs4mu = 0, fs4e = 1, fs2e2mu = 2, fs2mu2e = 3, fs4l = 4, MAX_NUM_OF_FINAL_STATES };
   enum _resonant_status { resonant = 0, nonresonant = 1, all_resonant = 2, MAX_NUM_OF_RESONANT_STATUSES };
   enum _category { untagged = 0, VBF_1j_tagged = 1, VBF_2j_tagged = 2, VH_lepton_tagged = 3, VH_hadron_tagged = 4, ttH_tagged = 5, inclusive = 6, MAX_NUM_OF_CATEGORIES };
   enum _1Dplot_name { M4lMain = 0, M4lMainZoomed = 1, M4lMainHighMass = 2, MZ1 = 3, MZ1_M4L118130 = 4, MZ2 = 5, MZ2_M4L118130 = 6, KD = 7, KD_M4L118130 = 8, D1jet = 9, D1jet_M4L118130 = 10, D2jet = 11, D2jet_M4L118130 = 12, DWH = 13, DWH_M4L118130 = 14, DZH = 15, DZH_M4L118130 = 16, MAX_NUM_OF_1DPLOT_NAMES};
   enum _2Dplot_name { MZ1vsMZ2 = 0, MZ1vsMZ2_M4L118130 = 1, MAX_NUM_OF_2DPLOT_NAMES};
   enum _2DErrorplot_name { KDvsM4l = 0,  KDvsM4lZoomed = 1, KDvsM4lHighMass = 2, D1jetvsM4lZoomed = 3, D2jetvsM4lZoomed = 4, DWHvsM4lZoomed = 5, DZHvsM4lZoomed = 6, MAX_NUM_OF_2DERRORPLOT_NAMES};
   
   enum _process {
   Data = 0,
   H120 = 1,
   H124 = 2,
   H125 = 3,
   H126 = 4,
   H130 = 5,
   H120VBF = 6,
   H124VBF = 7, 
   H125VBF = 8, 
   H126VBF = 9, 
   H130VBF = 10, 
   H120VH = 11,
   H124VH = 12,
   H125VH = 13,
   H126VH = 14,
   H130VH = 15,
   H120other = 16,
   H124other = 17,
   H125other = 18,
   H126other = 19,
   H130other = 20,
   qqZZ = 21,
   ggZZ = 22,
   DY = 23,
   ttbar = 24,
   MAX_NUM_OF_PROCESSES };
   
   
   static const int num_of_processes         = MAX_NUM_OF_PROCESSES;
   static const int num_of_final_states      = MAX_NUM_OF_FINAL_STATES;
   static const int num_of_res_statuses      = MAX_NUM_OF_RESONANT_STATUSES;
   static const int num_of_categories        = MAX_NUM_OF_CATEGORIES;
   static const int num_of_1Dplot_names      = MAX_NUM_OF_1DPLOT_NAMES;
   static const int num_of_2Dplot_names      = MAX_NUM_OF_2DPLOT_NAMES;
   static const int num_of_2DErrorplot_names = MAX_NUM_OF_2DERRORPLOT_NAMES;
   
   private:
   
};

#endif
