# Title: Sorting and Algorithm Efficiency
# Author: Zubeyir Bodur
# ID: 21702382
# Section: 2
# Assignment: 1
# Description: Makefile for the assignment
CXX = g++
CXXFLAGS= -std=c++11
DEPS = sorting.h
OBJ = sorting.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

hw1: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)
	rm -f *.o


