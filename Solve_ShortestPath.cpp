#include "Solve_ShortestPath.hpp"
#include "MazeGraph.hpp"

bool Solve_ShortestPath::find_shortest_temp(unsigned int & id, NodeStates & s, Distances & d) const
{
	unsigned int max_dist = (unsigned int)-1;
	bool found = false;
	for (unsigned int i = 0; i < s.size(); ++i) {
		if ((d[i] < max_dist) && (s[i] == TEMP)) {
			id = i;
			max_dist = d[i];
			found = true;
		}
	}
	return found;
}

void Solve_ShortestPath::solve(const Maze & m, const Position & start,
	const Position & end, PositionVec & p)
{
	p.clear();

	// trivial case
	if (start == end) {
		p.push_back(start);
		return;
	}

	// init
	unsigned int n = m.nx() * m.ny();
	MazeGraph graph(m);
	Predecessors pred;
	NodeStates state(n, FREE);
	Distances dist(n, (unsigned int)-1);

	// set start node conditions
	state[m.id(start)] = TEMP;
	dist[m.id(start)] = 0;

	// search for the shortest path
	while (state[m.id(end)] != FINAL) {
		unsigned int id = 0;
		if (!find_shortest_temp(id, state, dist)) return; // there is no solution!
		state[id] = FINAL;
		Position c = m.pos(id);

		// check all neighbors:
		for (unsigned int j = 0; j < m.ny(); ++j) {
			for (unsigned int i = 0; i < m.ny(); ++i) {
				if (graph.is_connected(c, i, j)) {
					unsigned int other = m.id(i, j);
					unsigned int dsum = dist[id] + 1;
					if (dist[other] > dsum) {
						dist[other] = dsum;
						state[other] = TEMP;
						pred.insert(Predecessors::value_type(Position(i, j), c));
					}
				}
			}
		}
	}

	// construct path: go backwards through predecessors
	Position c = end;
	while (c != start) {
		p.insert(p.begin(), c);
		c = pred[c];
	}
	p.insert(p.begin(), c);
}

