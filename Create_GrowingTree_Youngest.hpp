#ifndef __CREATE_GROWINGTREE_YOUNGEST__HPP__
#define __CREATE_GROWINGTREE_YOUNGEST__HPP__

#include "Create_GrowingTree.hpp"

class Create_GrowingTree_Youngest: public Create_GrowingTree
{
	protected:
		virtual PositionVec::iterator choose(PositionVec &);
};

#endif
