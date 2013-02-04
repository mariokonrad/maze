#include "Create_GrowingTree.hpp"

void Create_GrowingTree::create(Maze & m)
{
	// initialize
	m.init();
	PositionVec pos;
	State s(m);
	PossibleDirections pd;
	pd.reserve(4);

	// start at random position
	Position c(rand() % m.nx(), rand() % m.ny());
	pos.push_back(c);
	s.visit(c);

	// carve through the maze
	while (pos.size() > 0) {
		PositionVec::iterator it = choose(pos);
		c = *it;
		get_possible_directions(c, s, pd);
		if (pd.size() == 0) { // dead end?
			pos.erase(it);
			continue;
		}
		move(m, s, c, pd[rand() % pd.size()]);
		pos.push_back(c);
	}
}

