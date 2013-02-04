#include "Maze.hpp"

Maze::Maze(unsigned int nx, unsigned int ny, bool full)
	: n_x(nx), n_y(ny)
{
	m = new unsigned char[n_x*n_y];
	init(full);
}

Maze::~Maze()
{
	if (m) {
		delete[] m;
		m = 0;
	}
}

void Maze::init(bool full)
{
	if (!m) return;
	if (full) {
		memset(m, TOP | RIGHT | BOTTOM | LEFT, n_x*n_y);
	} else {
		memset(m, NONE, n_x*n_y);
	}
}

