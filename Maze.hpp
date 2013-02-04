#ifndef __MAZE__HPP__
#define __MAZE__HPP__

#include "Position.hpp"
#include "Direction.hpp"

class Maze // 2D maze
{
	private:
		unsigned char * m;
		unsigned int n_x;
		unsigned int n_y;
	public:
		Maze(unsigned int, unsigned int, bool = true);
		virtual ~Maze();
		void init(bool = true);

		inline unsigned int id(unsigned int x, unsigned int y) const { return x+y*n_x; }
		inline unsigned int id(const Position & p) const { return id(p.first, p.second); }
		inline unsigned char & c(unsigned int x, unsigned int y) { return m[id(x,y)]; }
		inline unsigned char c(unsigned int x, unsigned int y) const { return m[id(x,y)]; }
		inline unsigned char & c(const Position & p) { return c(p.first, p.second); }
		inline unsigned char c(const Position & p) const { return c(p.first, p.second); }
		inline unsigned char & c(unsigned int id) { return c(id % n_x, id / n_x); }
		inline unsigned char c(unsigned int id) const { return c(id % n_x, id / n_x); }
		inline unsigned int nx() const { return n_x; }
		inline unsigned int ny() const { return n_y; }
		inline Position pos(unsigned int id) const { return Position(id % n_x, id / n_x); }
};

#endif
