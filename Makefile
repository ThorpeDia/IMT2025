CXX = g++
CXXFLAGS = -O2 -std=c++17 -stdlib=libc++ -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lQuantLib

SOURCES = main.cpp constantblackscholesprocess.cpp
HEADERS = constantblackscholesprocess.hpp mceuropeanengine.hpp mc_discr_arith_av_strike.hpp mcbarrierengine.hpp

all: montecarlo

montecarlo: $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o montecarlo $(SOURCES) $(LDFLAGS)

clean:
	rm -f montecarlo
