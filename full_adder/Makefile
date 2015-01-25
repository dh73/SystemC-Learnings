SYSTEMC=home/diego/EDA/SystemC/SystemC_Home
LDFLAGS=-L$(SYSTEMC)/lib-linux64 -lsystemc
CXXFLAGS=-Wno-deprecated -I$(SYSTEMC)/include -fpermissive
 
all:
	g++ $(CXXFLAGS) *.cpp $(LDFLAGS)
	./a.out
