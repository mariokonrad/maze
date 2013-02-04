#ifndef __CREATE_GROWINGTREE__HPP__
#define __CREATE_GROWINGTREE__HPP__

#include "MazeCreator.hpp"

class Create_GrowingTree : public MazeCreator
{
	protected:
		virtual PositionVec::iterator choose(PositionVec &) = 0;
	public:
		virtual void create(Maze &);
};

#endif
