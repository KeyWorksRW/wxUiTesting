/////////////////////////////////////////////////////////////////////////////
// Purpose:   wxPython testing dialog
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "../wxui_generated/python_dlg_base.h"

void PythonDlgBase::OnInit(wxInitDialogEvent& event)
{
    event.Skip();  // transfer all validator data to their windows and update UI
}

void PythonDlgBase::OnText(wxCommandEvent& WXUNUSED(event))
{
    // TODO: Implement OnText
}
