#include "MazeCreator.hpp"

void MazeCreator::get_possible_directions(const Position & c, const State & s, PossibleDirections & pd) const
{
	pd.clear();
	if (c.first > 0 && s.not_visited(c.first-1, c.second))
		pd.push_back(LEFT);
	if (c.first < s.nx()-1 && s.not_visited(c.first+1, c.second))
		pd.push_back(RIGHT);
	if (c.second > 0 && s.not_visited(c.first, c.second-1))
		pd.push_back(TOP);
	if (c.second < s.ny()-1 && s.not_visited(c.first, c.second+1))
		pd.push_back(BOTTOM);
}

void MazeCreator::move(Maze & m, State & s, Position & c, unsigned char dir) const
{
	m.c(c) &= ~dir;
	switch (dir) {
		case TOP:
			m.c(c.first, c.second-1) &= ~BOTTOM;
			--c.second;
			break;
		case BOTTOM:
			m.c(c.first, c.second+1) &= ~TOP;
			++c.second;
			break;
		case RIGHT:
			m.c(c.first+1, c.second) &= ~LEFT;
			++c.first;
			break;
		case LEFT:
			m.c(c.first-1, c.second) &= ~RIGHT;
			--c.first;
			break;
	}
	s.visit(c);
}

