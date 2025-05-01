/////////////////////////////////////////////////////////////////////////////
// Purpose:     Text Ctrl Document class
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence see ../../../wxWidgets32/licence.txt
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/docview.h>

class wxTextCtrl;

class TextCtrlDocument : public wxDocument
{
public:
    TextCtrlDocument() : wxDocument() {}

    virtual bool OnCreate(const wxString& path, long flags) override;

    virtual wxTextCtrl* GetTextCtrl() const = 0;

    virtual bool IsModified() const override;
    virtual void Modify(bool mod) override;

protected:
    virtual bool DoSaveDocument(const wxString& filename) override;
    virtual bool DoOpenDocument(const wxString& filename) override;

    void OnTextChange(wxCommandEvent& event);

    wxDECLARE_NO_COPY_CLASS(TextCtrlDocument);
    wxDECLARE_ABSTRACT_CLASS(TextCtrlDocument);
};

class TextEditDocument : public TextCtrlDocument
{
public:
    TextEditDocument() : TextCtrlDocument() {}
    virtual wxTextCtrl* GetTextCtrl() const override;

    wxDECLARE_NO_COPY_CLASS(TextEditDocument);
    wxDECLARE_DYNAMIC_CLASS(TextEditDocument);
};
