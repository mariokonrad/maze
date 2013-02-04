#ifndef __CREATE_GROWINGTREE_RANDOM__HPP__
#define __CREATE_GROWINGTREE_RANDOM__HPP__

#include "Create_GrowingTree.hpp"

class Create_GrowingTree_Random : public Create_GrowingTree
{
	protected:
		virtual PositionVec::iterator choose(PositionVec &);
};

#endif
