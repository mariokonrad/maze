#ifndef __ASCIIMAZE__HPP__
#define __ASCIIMAZE__HPP__

#include "Maze.hpp"

class ASCIIMaze : public Maze
{
	private:
		char wall;
		char space;
		char center;
		char mark;
	public:
		ASCIIMaze(unsigned int, unsigned int, bool = true);
		void print(unsigned int = (unsigned int)-1, unsigned int = (unsigned int)-1) const;
};

#endif
