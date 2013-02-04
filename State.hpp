#ifndef __STATE__HPP__
#define __STATE__HPP__

#include "Maze.hpp"

class State
{
	private:
		enum VISITOR_STATE { NOT_VISITED = 0, VISITED = 1 };
	private:
		unsigned int n_x;
		unsigned int n_y;
		unsigned char * s;
	public:
		State(unsigned int, unsigned int);
		State(const Maze &);
		~State();
		void init();

		inline unsigned char & c(unsigned int x, unsigned int y) { return s[y*n_x+x]; }
		inline unsigned char c(unsigned int x, unsigned int y) const { return s[y*n_x+x]; }
		inline unsigned char & c(const Position & p) { return c(p.first, p.second); }
		inline unsigned char c(const Position & p) const { return c(p.first, p.second); }
		inline unsigned int nx() const { return n_x; }
		inline unsigned int ny() const { return n_y; }

		inline void visit(unsigned int x, unsigned int y) { c(x,y) = VISITED; }
		inline void visit(const Position & p) { c(p) = VISITED; }
		inline bool is_visited(unsigned int x, unsigned int y) const { return c(x,y) == VISITED; }
		inline bool is_visited(const Position & p) const { return c(p) == VISITED; }
		inline bool not_visited(unsigned int x, unsigned int y) const { return c(x,y) == NOT_VISITED; }
		inline bool not_visited(const Position & p) const { return c(p) == NOT_VISITED; }
};

#endif
