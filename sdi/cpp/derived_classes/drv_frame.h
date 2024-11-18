/////////////////////////////////////////////////////////////////////////////
// Purpose:   Derived class for wxFrame
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   LICENSE -- see ../../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/frame.h>  // Base class for wxFrame

class drvFrame : public wxFrame
{
public:
    drvFrame()
    {
    }

    bool Create(int ignore, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "SDI Tests",
                const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300),
                long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL, const wxString& name = wxFrameNameStr)
    {
        wxUnusedVar(ignore);
        if (!wxFrame::Create(parent, id, title, wxWindow::FromDIP(pos), wxWindow::FromDIP(size), style, name))
            return false;
        else
            return true;
    }
};
