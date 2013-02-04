#include "Solve_RecursiveBacktracker.hpp"

bool Solve_RecursiveBacktracker::search(const Maze & m, const MazeGraph & g,
	const Position & cur, const Position & end, State & s, PositionVec & p)
{
	// is the end nigh?
	if (cur == end) {
		p.insert(p.begin(), cur);
		return true;
	}

	s.visit(cur);

	// search all connected but no visited neighors of the current node
	for (unsigned int j = 0; j < m.ny(); ++j) {
		for (unsigned int i = 0; i < m.nx(); ++i) {
			if (g.is_connected(cur, i, j)) {
				Position act(i, j);
				if (s.not_visited(act)) {
					if (search(m, g, act, end, s, p)) {
						// the end was found
						p.insert(p.begin(), cur);
						return true;
					}
				}
			}
		}
	}
	// dead end
	return false;
}

void Solve_RecursiveBacktracker::solve(const Maze & m, const Position & start,
	const Position & end, PositionVec & p)
{
	p.clear();
	if (start == end) {
		p.push_back(start);
		return;
	}
	State s(m);
	search(m, MazeGraph(m), start, end, s, p);
}

