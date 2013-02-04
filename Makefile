# Makefile

CFLAGS+=-Wall -pedantic -ansi -O2 -Wextra
CXXFLAGS+=-Wall -pedantic -ansi -O2 -Wextra

#CXXFLAGS=-Wall -pedantic -ansi -ggdb

all: console labyrinth

console: \
	Maze.o \
	ASCIIMaze.o \
	State.o \
	MazeCreator.o \
	Create_RecursiveBacktracker.o \
	Create_GrowingTree.o \
	Create_GrowingTree_Random.o \
	Create_GrowingTree_Oldest.o \
	Create_GrowingTree_Youngest.o \
	MazeGraph.o \
	Solve_RecursiveBacktracker.o \
	Solve_ShortestPath.o \
	console.o
	$(CXX) -o $@ $^ -lstdc++

labyrinth : \
	wxMaze.o \
	Maze.o \
	labyrinth.o
	$(CXX) -o $@ $^ `wx-config --libs`

labyrinth.o : labyrinth.cpp
	$(CXX) -o $@ -c $^ `wx-config --cxxflags`

wxMaze.o : wxMaze.cpp
	$(CXX) -o $@ -c $^ `wx-config --cxxflags`

console.o: console.cpp

clean:
	rm -f *.o *.bak *.exe *.stackdump console labyrinth

