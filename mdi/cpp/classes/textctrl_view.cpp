/////////////////////////////////////////////////////////////////////////////
// Purpose:     TextEditView definition
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "textctrl_view.h"

#include "mainapp.h"  // MainApp -- Main application class

wxIMPLEMENT_DYNAMIC_CLASS(TextEditView, wxView);

wxBEGIN_EVENT_TABLE(TextEditView, wxView) EVT_MENU(wxID_COPY, TextEditView::OnCopy)
    EVT_MENU(wxID_PASTE, TextEditView::OnPaste) EVT_MENU(wxID_SELECTALL, TextEditView::OnSelectAll) wxEND_EVENT_TABLE()

        bool TextEditView::OnCreate(wxDocument* doc, long flags)
{
    if (!wxView::OnCreate(doc, flags))
        return false;

    wxFrame* frame = wxGetApp().CreateChildFrame(this, false);
    wxASSERT(frame == GetFrame());
    m_text = new wxTextCtrl(frame, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    frame->Show();

    return true;
}

void TextEditView::OnDraw(wxDC* WXUNUSED(dc))
{
    // nothing to do here, wxTextCtrl draws itself
}

bool TextEditView::OnClose(bool deleteWindow)
{
    if (!wxView::OnClose(deleteWindow))
        return false;

    Activate(false);

    if (wxGetApp().GetMode() == MainApp::Mode_Single)
    {
        m_text->Clear();
    }
    else  // not single window mode
    {
        if (deleteWindow)
        {
            GetFrame()->Destroy();
            SetFrame(nullptr);
        }
    }
    return true;
}
