/////////////////////////////////////////////////////////////////////////////
// Purpose:   Derived class for wxPanel 
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   LICENSE -- see ../../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/panel.h>  // Base class for wxPanel

class drvPanel : public wxPanel
{
public:
    drvPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
        : wxPanel(parent, id, pos, size, style, name)
    {
    }
};
