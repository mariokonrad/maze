#ifndef __MAZECREATOR__HPP__
#define __MAZECREATOR__HPP__

#include <vector>
#include "Position.hpp"
#include "State.hpp"

class MazeCreator // creates perfect mazes
{
	protected:
		typedef std::vector<unsigned char> PossibleDirections;
	protected:
		void get_possible_directions(const Position &, const State &, PossibleDirections &) const;
		void move(Maze &, State &, Position &, unsigned char) const;
	public:
		virtual void create(Maze & m) = 0;
};


#endif
