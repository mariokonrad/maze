// labyrinth.cpp

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/dcbuffer.h>
#include "wxMaze.hpp"

enum {
	 ID_QUIT   = wxID_EXIT
	,ID_ABOUT  = wxID_ABOUT
	,ID_CREATE = 10000
	,ID_SOLVE  = 10001
};

// {{{

class Canvas : public wxPanel
{
	private:
		wxMaze m;
	public:
		Canvas(wxWindow * parent
			, wxWindowID = -1
			, const wxPoint & = wxDefaultPosition
			, const wxSize & = wxDefaultSize);
		virtual void OnPaint(wxPaintEvent &);
		void on_erase_background(wxEraseEvent &);
		void on_size(wxSizeEvent &);

	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(Canvas, wxPanel)
	EVT_PAINT(Canvas::OnPaint)
	EVT_ERASE_BACKGROUND(Canvas::on_erase_background)
	EVT_SIZE(Canvas::on_size)
END_EVENT_TABLE()

Canvas::Canvas(wxWindow * parent
	, wxWindowID id
	, const wxPoint & pos
	, const wxSize & size)
	: wxPanel(parent, id, pos, size)
{
	SetBackgroundColour(*wxWHITE);
	SetFocusIgnoringChildren();
}

void Canvas::OnPaint(wxPaintEvent & event)
{
	wxAutoBufferedPaintDC dc(this);
	dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();
	PrepareDC(dc);

	int w, h;
	GetSize(&w, &h);

	m.draw(dc, w, h);
}

void Canvas::on_erase_background(wxEraseEvent &)
{} // ignore to avoid flashing

void Canvas::on_size(wxSizeEvent &)
{
	// TODO
	Refresh();
}

// }}}

// {{{

class Frame : public wxFrame
{
	private:
		Canvas * canvas;
		wxButton * btn_create;
		wxButton * btn_solve;
		wxSpinCtrl * sp_width;
		wxSpinCtrl * sp_height;
	public:
		Frame(const wxString &, const wxPoint &, const wxSize &);
		void on_quit(wxCommandEvent &);
		void on_about(wxCommandEvent &);

	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(Frame, wxFrame)
	EVT_MENU(ID_QUIT,  Frame::on_quit)
	EVT_MENU(ID_ABOUT, Frame::on_about)
END_EVENT_TABLE()

Frame::Frame(const wxString & title, const wxPoint & pos, const wxSize & size)
	: wxFrame(NULL, -1, title, pos, size)
	, canvas(0)
{
	// menu
	wxMenu * menu_file = new wxMenu;
	menu_file->Append(ID_QUIT, wxT("&Quit"));
	wxMenu * menu_help= new wxMenu;
	menu_help->Append(ID_ABOUT, wxT("&About"));
	wxMenuBar * menubar = new wxMenuBar;
	menubar->Append(menu_file, wxT("&File"));
	menubar->Append(menu_help, wxT("&Help"));
	SetMenuBar(menubar);

	// canvas
	canvas = new Canvas(this);
	wxSizer * s_cnv = new wxBoxSizer(wxVERTICAL);
	s_cnv->Add(canvas, 1, wxGROW | wxALL, 0);
	s_cnv->SetMinSize(256, 256);

	// controls
	sp_width = new wxSpinCtrl(this, -1);
	sp_height = new wxSpinCtrl(this, -1);
	btn_create = new wxButton(this, ID_CREATE, wxT("Create"));
	btn_solve  = new wxButton(this, ID_SOLVE, wxT("Solve"));
	wxSizer * s_ctrl = new wxBoxSizer(wxHORIZONTAL);
	s_ctrl->Add(new wxStaticText(this, -1, wxT("Width:")), 0, 0, 2);
	s_ctrl->Add(sp_width, 0, 0, 2);
	s_ctrl->Add(new wxStaticText(this, -1, wxT("Height:")), 0, 0, 2);
	s_ctrl->Add(sp_height, 0, 0, 2);
	s_ctrl->Add(btn_create, 0, 0, 2);
	s_ctrl->Add(btn_solve, 0, 0, 2);

	sp_width->SetRange(8, 64);
	sp_height->SetRange(8, 64);

	// layout
	wxSizer * s_top = new wxBoxSizer(wxVERTICAL);
	s_top->Add(s_cnv, 1, wxGROW | wxALL, 2);
	s_top->Add(s_ctrl, 0, wxGROW | wxLEFT | wxRIGHT, 2);
	SetAutoLayout(true);
	SetSizer(s_top);
	s_top->Fit(this);
	s_top->SetSizeHints(this);
}

void Frame::on_quit(wxCommandEvent &)
{
	Close(true);
}

void Frame::on_about(wxCommandEvent &)
{
	wxMessageBox(
		wxString::Format(wxT("Labyrinth\n\nBuild: %s %s\n\n"), wxT(__DATE__), wxT(__TIME__)),
		wxT("About"), wxOK | wxICON_INFORMATION, this);
}

// }}}

// {{{

class App : public wxApp
{
	public:
		virtual bool OnInit();
};

IMPLEMENT_APP(App)

bool App::OnInit()
{
	wxFrame * frame = new Frame(wxT("Labyrinth"), wxDefaultPosition, wxSize(600, 600));
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}

// }}}

