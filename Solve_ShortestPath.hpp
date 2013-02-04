#ifndef __SOLVE_SHORTESTPATH__HPP__
#define __SOLVE_SHORTESTPATH__HPP__

#include "MazeSolver.hpp"
#include "Position.hpp"
#include <vector>
#include <map>

class Solve_ShortestPath : public MazeSolver
{
	private:
		enum SOLVE_SHORTEST_PATH { FREE  = 0 ,TEMP  = 1 ,FINAL = 2 };
		typedef std::vector<SOLVE_SHORTEST_PATH> NodeStates;
		typedef std::vector<unsigned int> Distances;
		typedef std::map<Position,Position> Predecessors;
	private:
		bool find_shortest_temp(unsigned int &, NodeStates &, Distances &) const;
	public:
		virtual void solve(const Maze &, const Position &, const Position &, PositionVec &);
};

#endif
