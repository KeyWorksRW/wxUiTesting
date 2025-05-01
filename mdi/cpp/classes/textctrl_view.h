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

#include <wx/docview.h>
#include <wx/textctrl.h>

// The view using a standard wxTextCtrl to show its contents
class TextEditView : public wxView
{
public:
    TextEditView() : wxView(), m_text(nullptr) {}

    virtual bool OnCreate(wxDocument* doc, long flags) override;
    virtual void OnDraw(wxDC* dc) override;
    virtual bool OnClose(bool deleteWindow = true) override;

    wxTextCtrl* GetText() const { return m_text; }

protected:
    void OnCopy(wxCommandEvent& WXUNUSED(event)) { m_text->Copy(); }
    void OnPaste(wxCommandEvent& WXUNUSED(event)) { m_text->Paste(); }
    void OnSelectAll(wxCommandEvent& WXUNUSED(event)) { m_text->SelectAll(); }

private:
    wxTextCtrl* m_text;

    wxDECLARE_EVENT_TABLE();
    wxDECLARE_DYNAMIC_CLASS(TextEditView);
};
