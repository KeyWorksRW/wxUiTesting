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
    drvFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style,
             const wxString& name)
        : wxFrame(parent, id, title, pos, size, style, name)
    {
    }
};
