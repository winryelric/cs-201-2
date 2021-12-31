# Title: Binary Search Trees
# Author: Zubeyir Bodur
# ID: 21702382
# Section: 2
# Assignment: 2
# Description: Makefile for the assignment
CXX = g++
CXXFLAGS= -std=c++11
DEPS = NodeQ.h BinarySearchTree.h BinaryTreeNode.h
OBJ = NodeQ.o BinarySearchTree.o BinaryTreeNode.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

hw2: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)
	rm -f *.o
