#makefile

CXXFLAGS = -g -I. -m64 $(shell root-config --cflags) -I include
LDFLAGS = $(shell root-config --libs) -lm -lGenVector
CXX = g++

EXTLIBS = ./ext/cConstants_cc.so ./ext/FinalStates_cc.so ./ext/bitops_cc.so ./ext/Discriminants_cc.so

VPATH = ./src/ ./include/

SRCPP_PLOTTER = run_plotter.cpp\
                Plotter.cpp\
                Histograms.cpp\
                Variables.cpp\
                Tree.cpp\
                Settings.cpp\
                M4lZX.cpp\
                FakeRates.cpp\
                Category.cpp\
                ZXVariables.cpp\
                CMS_lumi.cpp\
                Cosmetics.cpp
        
SRCPP_YIELDS = run_yields.cpp\
               Yields.cpp\
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
           Yields.h\
           Histograms.h\
           Variables.h\
           Tree.h\
           Settings.h\
           M4lZX.h\
           FakeRates.h\
           Category.h\
           ZXVariables.h\
           CMS_lumi.h\
           Cosmetics.h
    
    
OBJCPP_PLOTTER = $(patsubst %.cpp,obj/%.o,$(SRCPP_PLOTTER))
OBJCPP_YIELDS = $(patsubst %.cpp,obj/%.o,$(SRCPP_YIELDS))


all: run
plotter: run_plotter
yields: run_yields


obj/%.o: %.cpp $(INCLUDES)
	@echo ">> compiling $*"
	@mkdir -p obj/
	@$(CXX) -c $< ${CXXFLAGS} -o $@
   

run_plotter: $(OBJCPP_PLOTTER)
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