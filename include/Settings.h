#ifndef Settings_h
#define Settings_h

using namespace std;

class Settings
{

public:
	
	Settings();
	~Settings();
   
   enum _blindings { fullyblind = 0, blindabove_110 = 1, blindbelow_150 = 2, blind_110_150 = 3, unblinded = 4 };
   enum _final_state { fs4e = 0, fs4mu = 1, fs2e2mu = 2, fs2mu2e = 3, fs4l = 4, MAX_NUM_OF_FINAL_STATES };
   
   enum _category
   {
      untagged = 0,
      VBF_1j_tagged = 1,
      VBF_2j_tagged = 2,
      VH_lepton_tagged = 3,
      VH_hadron_tagged = 4,
      ttH_tagged = 5,
      VH_MET_tagged = 6,
      inclusive = 7,
      MAX_NUM_OF_CATEGORIES
   };
   
   enum _category_AC
   {
      ac_untagged = 0,
      ac_VBF_tagged = 1,
      ac_VH_tagged = 2,
      MAX_NUM_OF_CATEGORIES_AC
   };
   
   enum _1D_plot_name
   {
      M4lMain = 0,
      M4lMainZoomed = 1,
      M4lMainHighMass = 2,
      MZ1 = 3,
      MZ1_M4L118130 = 4,
      MZ2 = 5,
      MZ2_M4L118130 = 6,
      KD = 7,
      KD_M4L118130 = 8,
      D1jet = 9,
      D1jet_M4L118130 = 10,
      D2jet = 11,
      D2jet_M4L118130 = 12,
      DWH = 13,
      DWH_M4L118130 = 14,
      DZH = 15,
      DZH_M4L118130 = 16,
      M4lYields = 17,
      MAX_NUM_OF_1D_PLOT_NAMES
   };
   
   enum _2D_plot_name
   {
      MZ1vsMZ2 = 0,
      MZ1vsMZ2_M4L118130 = 1,
      MAX_NUM_OF_2D_PLOT_NAMES
   };
   
   enum _2D_error_plot_name 
   {
      KDvsM4l = 0,
      KDvsM4lZoomed = 1,
      KDvsM4lHighMass = 2,
      D1jetvsM4lZoomed = 3,
      D2jetvsM4lZoomed = 4,
      DWHvsM4lZoomed = 5,
      DZHvsM4lZoomed = 6,
      MAX_NUM_OF_2D_ERROR_PLOT_NAMES
   };
   
   enum _1D_ACplot_name
   {
      DZeroMinus = 0,
      DZerohPlus = 1,
      DL1        = 2,
      MAX_NUM_OF_1D_ACPLOT_NAMES
   };
   
   enum _2D_ACplot_name
   {
      DZeroMinusvsM4l = 0,
      DZerohPlusvsM4l = 1,
      DL1vsM4l        = 2,
      MAX_NUM_OF_2D_ACPLOT_NAMES
   };

   enum _m4l_slices
   {
      _70To220 = 0,
      _220To370 = 1,
      _370To520 = 2,
      _520To670 = 3,
      _670To820 = 4,
      _820To970 = 5,
      OnShell = 6,
      OffShell = 7,
      MAX_NUM_OF_M4L_SLICES
   };
   
   enum _production_modes { ggH = 0, VBF = 1, WH = 2, ZH = 3, ttH = 4, MAX_NUM_OF_PRODUCTION_MODES };
   
   enum _process
   { 
      Data = 0,
      H125 = 1,
      H125ggH = 2,
      H125VBF = 3,
      H125VH = 4,
      H125ttH = 5,
      qqZZ = 6,
      ggZZ = 7,
      DY = 8,
      ttbar = 9,
      MAX_NUM_OF_PROCESSES
   };
   
   enum _process_AC
   {
      acData = 0,
      acH125 = 1,
      acH125ggH = 2,
      acH125VBF = 3,
      acH125VH = 4,
      acH125ttH = 5,
      acqqZZ = 6,
      acggZZ = 7,
      acH125_0MH = 8,
      acH125_0PH = 9,
      acH125_0PL1 = 10,
      acH125_0MHf05 = 11,
      acH125_0PHf05 = 12,
      acH125_0PL1f05 = 13,
      MAX_NUM_OF_PROCESSES_AC
   };
   
   enum _process_yields
   {
      yData = 0,
      yH120 = 1,
      yH124 = 2,
      yH125 = 3,
      yH126 = 4,
      yH130 = 5,
      yH120ggH = 6,
      yH124ggH = 7,
      yH125ggH = 8,
      yH126ggH = 9,
      yH130ggH = 10,
      yH120VBF = 11,
      yH124VBF = 12,
      yH125VBF = 13,
      yH126VBF = 14,
      yH130VBF = 15,
      yH120WH = 16,
      yH124WH = 17,
      yH125WH = 18,
      yH126WH = 19,
      yH130WH = 20,
      yH120ZH = 21,
      yH124ZH = 22,
      yH125ZH = 23,
      yH126ZH = 24,
      yH130ZH = 25,
      yH120ttH = 26,
      yH124ttH = 27,
      yH125ttH = 28,
      yH126ttH = 29,
      yH130ttH = 30,
      yqqZZ = 31,
      yggZZ = 32,
      yDY = 33,
      yttbar = 34,
      MAX_NUM_OF_PROCESSES_YIELDS
   };
   
   static const int num_of_production_modes    = MAX_NUM_OF_PRODUCTION_MODES;
   static const int num_of_processes           = MAX_NUM_OF_PROCESSES;
   static const int num_of_processes_yields    = MAX_NUM_OF_PROCESSES_YIELDS;
   static const int num_of_processes_AC        = MAX_NUM_OF_PROCESSES_AC;
   static const int num_of_final_states        = MAX_NUM_OF_FINAL_STATES;
   static const int num_of_categories          = MAX_NUM_OF_CATEGORIES;
   static const int num_of_categories_AC       = MAX_NUM_OF_CATEGORIES_AC;
   static const int num_of_1D_plot_names       = MAX_NUM_OF_1D_PLOT_NAMES;
   static const int num_of_2D_plot_names       = MAX_NUM_OF_2D_PLOT_NAMES;
   static const int num_of_2D_error_plot_names = MAX_NUM_OF_2D_ERROR_PLOT_NAMES;
   static const int num_of_1D_ACplot_names     = MAX_NUM_OF_1D_ACPLOT_NAMES;
   static const int num_of_2D_ACplot_names     = MAX_NUM_OF_2D_ACPLOT_NAMES;
   static const int num_of_m4l_slices          = MAX_NUM_OF_M4L_SLICES;
   
   private:
      
};
#endif
