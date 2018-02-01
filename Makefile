CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -I.
# -g          Enable extra debugging information for GDB
# -std=c++11  Enable C++11
# -Wall       Enable all warning flags
# -I.         Search for header files in the current directory
BIN=P0

all: $(BIN)

# $@ is the name of the target
# $< is the name of the first dependency
# $^ is the list of all dependencies

$(BIN): main.o procInput.o incrDiv.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $<

procInput.o: procInput.cpp procInput.h
	$(CXX) $(CXXFLAGS) -c $<

incrDiv.o: incrDiv.cpp incrDiv.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o *.gch $(BIN)
