#ifndef __MAZESOLVER__HPP__
#define __MAZESOLVER__HPP__

#include "Maze.hpp"
#include "Position.hpp"

class MazeSolver // solves perfect mazes without loops
{
	public:
		virtual void solve(const Maze & m, const Position & start,
			const Position & end, PositionVec & p) = 0;
};

#endif
