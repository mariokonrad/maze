#include "Create_RecursiveBacktracker.hpp"
#include <stack>

using namespace std;

void Create_RecursiveBacktracker::create(Maze & m)
{
	// initialization
	m.init();
	State s(m);
	stack<Position> stack;
	PossibleDirections pd;
	pd.reserve(4);

	// start at random position
	Position c(rand() % m.nx(), rand() % m.ny());
	s.visit(c);
	stack.push(c);

	// carve through the maze
	while (!stack.empty()) {
		get_possible_directions(c, s, pd);
		if (pd.size() == 0) { // dead end?
			c = stack.top();
			stack.pop();
			continue;
		}
		move(m, s, c, pd[rand() % pd.size()]);
		stack.push(c);
	}

}

