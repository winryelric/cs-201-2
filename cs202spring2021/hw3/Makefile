# Title: Heaps
# Author: Zubeyir Bodur
# ID: 21702382
# Section: 2
# Assignment: 3
# Description: Makefile for the assignment
CXX = g++
CXXFLAGS = -std=c++11
DEPS = myarray.h printer.h printrequest.h requestq.h simulator.h
OBJ = myarray.o printer.o printrequest.o requestq.o simulator.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

simulator: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)
	rm -f *.o
