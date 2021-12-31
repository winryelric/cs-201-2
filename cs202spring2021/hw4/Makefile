# Title: Heaps
# Author: Zubeyir Bodur
# ID: 21702382
# Section: 2
# Assignment: 3
# Description: Makefile for the assignment
CXX = g++
CXXFLAGS = -std=c++11
DEPS = Exception.h HashTable.h LinkedList.h WordNetwork.h
OBJ = HashTable.o LinkedList.o WordNetwork.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

hw4: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)
	rm -f *.o
