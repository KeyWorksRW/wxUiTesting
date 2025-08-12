/////////////////////////////////////////////////////////////////////////////
// Purpose:   Derived class for wxDialog 
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   LICENSE -- see ../../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/dialog.h>  // Base header for wxDialog

class drvDialog : public wxDialog
{
public:
    drvDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = wxDialogNameStr)
        : wxDialog(parent, id, title, pos, size, style, name)
    {
    }
};
