// console.cpp

// see: http://www.astrolog.org/labyrnth/algrithm.htm

#include <iostream>
#include <algorithm>
#include <time.h>
#include "Position.hpp"
#include "Maze.hpp"
#include "ASCIIMaze.hpp"
#include "State.hpp"
#include "MazeCreator.hpp"
#include "Create_RecursiveBacktracker.hpp"
#include "Create_GrowingTree.hpp"
#include "Create_GrowingTree_Random.hpp"
#include "Create_GrowingTree_Oldest.hpp"
#include "Create_GrowingTree_Youngest.hpp"
#include "MazeGraph.hpp"
#include "MazeSolver.hpp"
#include "Solve_RecursiveBacktracker.hpp"
#include "Solve_ShortestPath.hpp"

using namespace std;

struct SolutionPrint {
	void operator()(const PositionVec::value_type & s)
	{ cout << " " << s; }
};

int main(int, char **)
{
	srand(time(0));

	ASCIIMaze m(16, 16);
	Position start(0, 0);
	Position end(15, 15);

	Create_RecursiveBacktracker().create(m);
//	Create_GrowingTree_Random().create(m);
//	Create_GrowingTree_Oldest().create(m);
//	Create_GrowingTree_Youngest().create(m);
	m.print();

	PositionVec solution;
	Solve_RecursiveBacktracker().solve(m, start, end, solution);
//	Solve_ShortestPath().solve(m, start, end, solution);

	cout << endl;
	cout << "solution:";
	if (solution.empty()) {
		cout << " NONE";
	} else {
		for_each(solution.begin(), solution.end(), SolutionPrint());
	}
	cout << endl << endl;

	return 0;
}

