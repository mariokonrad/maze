#include "Create_GrowingTree_Random.hpp"

PositionVec::iterator Create_GrowingTree_Random::choose(PositionVec & pos)
{
	PositionVec::iterator it = pos.begin();
	if (pos.size() > 1) {
		it += rand() % (pos.size()-1);
	}
	return it;
}

