/////////////////////////////////////////////////////////////////////////////
// Purpose:   Derived class for wxToolBar
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   LICENSE -- see ../../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/toolbar.h>  // Base class for wxToolBar

class drvToolBar : public wxToolBar
{
public:
    drvToolBar(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
               long style = wxTB_FLAT | wxTB_DOCKABLE | wxTB_HORIZONTAL, const wxString& name = wxToolBarNameStr)
        : wxToolBar(parent, id, pos, size, style, name)
    {
    }
};
