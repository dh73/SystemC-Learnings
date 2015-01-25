SYSTEMC=$SYSTEMC_HOME
LDFLAGS=-L$(SYSTEMC)/lib-linux64 -lsystemc
CXXFLAGS=-Wno-deprecated -I$(SYSTEMC)/include -fpermissive
 
all:
	g++ $(CXXFLAGS) *.cpp $(LDFLAGS)
	./a.out
