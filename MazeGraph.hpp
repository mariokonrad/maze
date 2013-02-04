#ifndef __MAZE_GRAPH__HPP__
#define __MAZE_GRAPH__HPP__

#include "Maze.hpp"

class MazeGraph
{
	private:
		unsigned int n_x;
		unsigned int n_y;
		unsigned int n_n;
		unsigned char * adj;
	private:
		void clear();
		void init();
	public:
		MazeGraph(const Maze &, bool = true);
		~MazeGraph();
		void clean();
		void capture(const Maze &);

		inline void connect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
		{ adj[(x1+y1*n_x)+(x2+y2*n_x)*n_n] = 1; }

		inline bool is_connected(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) const
		{ return adj[(x1+y1*n_x)+(x2+y2*n_x)*n_n] == 1; }

		inline bool is_connected(const Position & p, unsigned int x2, unsigned int y2) const
		{ return is_connected(p.first, p.second, x2, y2); }

		void connect(unsigned int, unsigned int, unsigned char);
		bool is_connected(unsigned int, unsigned int, unsigned char) const;

		inline unsigned int nx() const { return n_x; }
		inline unsigned int ny() const { return n_y; }
		inline unsigned int nn() const { return n_n; }

		void print() const;
};

#endif
