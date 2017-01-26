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
   enum _process { Data = 0, H125 = 1, H125VBF = 2, H125VH = 3, H125other = 4, qqZZ = 5, ggZZ = 6, DY = 7, ttbar = 8, MAX_NUM_OF_PROCESSES };
   enum _process_yields {
   yData = 0,
   yH120 = 1,
   yH124 = 2,
   yH125 = 3,
   yH126 = 4,
   yH130 = 5,
   yH120VBF = 6,
   yH124VBF = 7,
   yH125VBF = 8,
   yH126VBF = 9,
   yH130VBF = 10,
   yH120VH = 11,
   yH124VH = 12,
   yH125VH = 13,
   yH126VH = 14,
   yH130VH = 15,
   yH120other = 16,
   yH124other = 17,
   yH125other = 18,
   yH126other = 19,
   yH130other = 20,
   yqqZZ = 21,
   yggZZ = 22,
   yDY = 23,
   yttbar = 24,
   MAX_NUM_OF_PROCESSES_YIELDS };
   
   
   static const int num_of_processes         = MAX_NUM_OF_PROCESSES;
   static const int num_of_processes_yields  = MAX_NUM_OF_PROCESSES_YIELDS;
   static const int num_of_final_states      = MAX_NUM_OF_FINAL_STATES;
   static const int num_of_res_statuses      = MAX_NUM_OF_RESONANT_STATUSES;
   static const int num_of_categories        = MAX_NUM_OF_CATEGORIES;
   static const int num_of_1Dplot_names      = MAX_NUM_OF_1DPLOT_NAMES;
   static const int num_of_2Dplot_names      = MAX_NUM_OF_2DPLOT_NAMES;
   static const int num_of_2DErrorplot_names = MAX_NUM_OF_2DERRORPLOT_NAMES;
   
   private:
   
};

#endif
