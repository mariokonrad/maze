#include "wxMaze.hpp"

using namespace std;

wxMaze::wxMaze(unsigned int nx, unsigned int ny, bool full)
	: Maze(nx, ny, full)
{}

void wxMaze::draw(wxDC & dc, int w, int h, unsigned int m_x, unsigned int m_y) const
{
	dc.SetPen(*wxBLACK_PEN);
	dc.DrawRectangle(0, 0, w, h);

/* {{{ DISABLED: copy from ASCIIMaze
	for (unsigned int j = 0; j < ny(); ++j) {
		for (unsigned int i = 0; i < nx(); ++i) {
			cout << wall;
			if (j == 0) {
				cout << ((c(i, j) & TOP) ? wall : space);
			} else {
				cout << (((c(i, j) & TOP) && (c(i, j-1) & BOTTOM)) ? wall : space);
			}
		}
		cout << wall << endl;
		for (unsigned int i = 0; i < nx(); ++i) {
			if (i == 0) {
				cout << ((c(i, j) & LEFT) ? wall : space);
			} else {
				cout << (((c(i, j) & LEFT) && (c(i-1, j) & RIGHT)) ? wall : space);
			}
			if (m_x == (unsigned int)-1 || m_y == (unsigned int)-1) {
				cout << center;
			} else {
				cout << ((i == m_x && j == m_y) ? mark : center);
			}
		}
		cout << ((c(nx()-1, j) & RIGHT) ? wall : space);
		cout << endl;
	}
	for (unsigned int i = 0; i < nx(); ++i) {
		cout << wall;
		cout << ((c(i, ny()-1) & BOTTOM) ? wall : space);
	}
	cout << wall << endl;
}}} */
}

