#include "State.hpp"

State::State(unsigned int nx, unsigned int ny)
	: n_x(nx), n_y(ny), s(0)
{
	s = new unsigned char[n_x*n_y];
	init();
}

State::State(const Maze & m)
	: s(0)
{
	n_x = m.nx(); n_y = m.ny();
	s = new unsigned char[n_x*n_y];
	init();
}

State::~State()
{
	if (s) {
		delete[] s;
		s = 0;
	}
}

void State::init()
{
	if (!s) return;
	unsigned int n = n_x * n_y;
	for (unsigned int i = 0; i < n; ++i) {
		s[i] = NOT_VISITED;
	}
}

