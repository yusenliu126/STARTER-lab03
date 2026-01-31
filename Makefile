CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g
OBJECTS = intbst.o testbst.o
EXECUTABLE = bst

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

intbst.o: intbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -c intbst.cpp

testbst.o: testbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -c testbst.cpp

test_intbst: test_intbst.o intbst.o
	$(CXX) test_intbst.o intbst.o -o test_intbst

test_intbst.o: test_intbst.cpp intbst.h
	$(CXX) $(CXXFLAGS) -c test_intbst.cpp

.PHONY: test_intbst

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

all: bst test_intbst

.PHONY: all
