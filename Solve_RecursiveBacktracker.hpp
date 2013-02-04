#ifndef __SOLVE_RECURSIVEBACKTRACKER__HPP__
#define __SOLVE_RECURSIVEBACKTRACKER__HPP__

#include "MazeSolver.hpp"
#include "MazeGraph.hpp"
#include "State.hpp"

class Solve_RecursiveBacktracker : public MazeSolver
{
	private:
		bool search(const Maze &, const MazeGraph &,
			const Position &, const Position &, State &, PositionVec &);
	public:
		virtual void solve(const Maze &, const Position &,
			const Position &, PositionVec &);
};

#endif
