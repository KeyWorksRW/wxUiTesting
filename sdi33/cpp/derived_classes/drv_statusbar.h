/////////////////////////////////////////////////////////////////////////////
// Purpose:   Derived class for wxStatusBar 
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   LICENSE -- see ../../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/statusbr.h>  // wxStatusBar

class drvStatusBar : public wxStatusBar
{
public:
    drvStatusBar(wxWindow* parent, wxWindowID id = wxID_ANY, long style = wxSTB_DEFAULT_STYLE,
                 const wxString& name = wxStatusBarNameStr)
        : wxStatusBar(parent, id, style, name)
    {
    }
};


