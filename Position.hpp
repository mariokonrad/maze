#ifndef __POSITION__HPP__
#define __POSITION__HPP__

#include <vector>
#include <iostream>

typedef std::pair<unsigned int, unsigned int> Position;
typedef std::vector<Position> PositionVec;

inline std::ostream & operator << (std::ostream & os, const Position & p)
{ return os << "(" << p.first << "," << p.second << ")"; }

#endif
