/////////////////////////////////////////////////////////////////////////////
// Purpose:
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/aui/framemanager.h>
#include <wx/bitmap.h>
#include <wx/bmpbndl.h>
#include <wx/cshelp.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>

#include <wx/xrc/xmlres.h>

#include <wx/xrc/xh_aui.h>
#include <wx/xrc/xh_auitoolb.h>
#include <wx/xrc/xh_ribbon.h>

#include "xrc_python_dlg.h"

#include "mainframe.h"

void MainFrame::OnXrcPythonDlg(wxCommandEvent& WXUNUSED(event))
{
    XrcPythonDlg dlg(this);
    dlg.ShowModal();
}

static bool g_xrc_initialized = false;

XrcPythonDlg::XrcPythonDlg(wxWindow* parent)
{
    if (!g_xrc_initialized)
    {
        wxXmlResource::Get()->InitAllHandlers();
        wxXmlResource::Get()->AddHandler(new wxRibbonXmlHandler);
        wxXmlResource::Get()->AddHandler(new wxAuiXmlHandler);
        wxXmlResource::Get()->AddHandler(new wxAuiToolBarXmlHandler);

        wxASSERT_MSG(wxXmlResource::Get()->LoadAllFiles("../../../sdi/xrc"), "No XRC files!");
    }

    wxXmlResource::Get()->LoadDialog(this, parent, "PythonDlg");

    Bind(wxEVT_BUTTON, &XrcPythonDlg::OnClose, this, wxID_CLOSE);
}

void XrcPythonDlg::OnClose(wxCommandEvent& WXUNUSED(event))
{
    EndModal(wxID_CLOSE);
}
