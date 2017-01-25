#makefile

CXXFLAGS = -g -I. -m64 $(shell root-config --cflags) -I include
LDFLAGS = $(shell root-config --libs) -lm -lGenVector
CXX = g++

#LIBS = /afs/cern.ch/work/m/mkovac/CMS/RUN2/HZZ4l_Plotter/CMSSW_8_0_21/src/ext/
#EXTLIBS = -L$(LIBS) cConstants_cc.so FinalStates_cc.so bitops_cc.so

EXTLIBS = ./ext/cConstants_cc.so ./ext/FinalStates_cc.so ./ext/bitops_cc.so

VPATH = ./src/ ./include/

SRCPP = run.cpp\
		  Plotter.cpp\
		  Histograms.cpp\
		  Variables.cpp\
		  Tree.cpp\
		  Settings.cpp\
		  M4lZX.cpp\
		  FakeRates.cpp\
		  Category.cpp\
		  ZXVariables.cpp\
		  CMS_lumi.cpp
        
SRCPP_YIELDS = run_yields.cpp\
					Plotter.cpp\
					Histograms.cpp\
					Variables.cpp\
					Tree.cpp\
					Settings.cpp\
					M4lZX.cpp\
					FakeRates.cpp\
					Category.cpp\
					ZXVariables.cpp\
					CMS_lumi.cpp

INCLUDES = Plotter.h\
			  Histograms.h\
			  Variables.h\
			  Tree.h\
			  Settings.h\
			  M4lZX.h\
			  FakeRates.h\
			  Category.h\
			  ZXVariables.h\
			  CMS_lumi.h
        
OBJCPP = $(patsubst %.cpp,obj/%.o,$(SRCPP))
OBJCPP_YIELDS = $(patsubst %.cpp,obj/%.o,$(SRCPP_YIELDS))


all: run

yields: run_yields

obj/%.o: %.cpp $(INCLUDES)
	@echo ">> compiling $*"
	@mkdir -p obj/
	@$(CXX) -c $< ${CXXFLAGS} -o $@

run: $(OBJCPP)
	@echo ">> linking..."
	@$(CXX) $^ $(EXTLIBS) ${LDFLAGS} ${CXXFLAGS}  -o $@

run_yields: $(OBJCPP_YIELDS)
	@echo ">> linking..."
	@$(CXX) $^ $(EXTLIBS) ${LDFLAGS} ${CXXFLAGS}  -o $@
   
clean:
	@echo ">> cleaning objects and executable"
	@rm -f obj/*.o
	@rm -f run
	@rm -f run_yields

uninstall:
	@echo ">> Uninstalling plotter"
	@rm  -f obj/*.o
	@rm  -f ext/*.so ext/*.d ext/*.pcm
	@rm -f run