CXX = g++
CPPFLAGS = -I/opt/local/include -I$(HOME)/usr/include
CXXFLAGS = -O3 -fopenmp -ffast-math -std=c++11 -DHAVE_CONFIG_H
LDFLAGS = -L$(HOME)/usr/lib -lcopter  -lm -lgsl -lgslcblas

ZBiasEFT: ZBiasEFT.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) vec3.cpp kernels.cpp ZBiasEFT.cpp $(LDFLAGS) -o ZBiasEFT

clean:
	@rm -f ZBiasEFT
