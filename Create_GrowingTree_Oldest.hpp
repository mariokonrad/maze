#ifndef __CREATE_GROWINGTREE_OLDEST__HPP__
#define __CREATE_GROWINGTREE_OLDEST__HPP__

#include "Create_GrowingTree.hpp"

class Create_GrowingTree_Oldest: public Create_GrowingTree
{
	protected:
		virtual PositionVec::iterator choose(PositionVec &);
};

#endif
