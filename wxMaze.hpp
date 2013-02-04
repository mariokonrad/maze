#ifndef __WXMAZE__HPP__
#define __WXMAZE__HPP__

#include "Maze.hpp"
#include <wx/wx.h>

class wxMaze : public Maze
{
	public:
		wxMaze(unsigned int, unsigned int, bool = true);
		void draw(wxDC &, int, int, unsigned int = (unsigned int)-1, unsigned int = (unsigned int)-1) const;
};

#endif
