#include "MazeGraph.hpp"
#include <iostream>

using namespace std;

void MazeGraph::clear()
{
	if (adj) {
		delete[] adj;
		adj = 0;
	}
}

void MazeGraph::init()
{
	clear();
	if (n_n == 0) return;
	adj = new unsigned char[n_n*n_n];
	clean();
}

MazeGraph::MazeGraph(const Maze & m, bool do_capture)
	: adj(0)
{
	n_x = m.nx(); n_y = m.ny();
	n_n = n_x * n_y;
	init();
	if (do_capture) capture(m);
}

MazeGraph::~MazeGraph()
{ clear(); }

void MazeGraph::clean()
{
	if (!adj) return;
	memset(adj, 0, n_n*n_n);
}

void MazeGraph::capture(const Maze & m)
{
	for (unsigned int y = 0; y < m.ny() && y < n_y; ++y) {
		for (unsigned int x = 0; x < m.nx() && x < n_x; ++x) {
			connect(x, y, m.c(x,y));
		}
	}
}

void MazeGraph::connect(unsigned int x, unsigned int y, unsigned char walls)
{
	if ((walls & TOP   ) != TOP)    connect(x, y, x, y-1);
	if ((walls & BOTTOM) != BOTTOM) connect(x, y, x, y+1);
	if ((walls & RIGHT ) != RIGHT)  connect(x, y, x+1, y);
	if ((walls & LEFT  ) != LEFT)   connect(x, y, x-1, y);
}

bool MazeGraph::is_connected(unsigned int x, unsigned int y, unsigned char dir) const
{
	switch (dir) {
		case TOP:    return (y == 0)     ? false : is_connected(x, y, x, y-1);
		case BOTTOM: return (y == n_y-1) ? false : is_connected(x, y, x, y+1);
		case RIGHT:  return (x == n_x-1) ? false : is_connected(x, y, x+1, y);
		case LEFT:   return (x == 0)     ? false : is_connected(x, y, x-1, y);
	}
	return false;
}

void MazeGraph::print() const
{
	for (unsigned int y = 0; y < n_n; ++y) {
		for (unsigned int x = 0; x < n_n; ++x) {
			cout << " " << (int)adj[x+y*n_n];
		}
		cout << endl;
	}
}

