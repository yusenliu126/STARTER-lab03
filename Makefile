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

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: clean
