/////////////////////////////////////////////////////////////////////////////
// Purpose:   Derived class for wxWizard 
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   LICENSE -- see ../../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/wizard.h>  // Base header for wxWizard

class drvWizard : public wxWizard
{
public:
    drvWizard(wxWindow* parent, wxWindowID id, const wxString& title, const wxBitmap& bitmap, const wxPoint& pos = wxDefaultPosition,
              long style = wxDEFAULT_DIALOG_STYLE)
        : wxWizard(parent, id, title, bitmap, pos, style)
    {
    }
};
