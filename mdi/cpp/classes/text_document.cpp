/////////////////////////////////////////////////////////////////////////////
// Purpose:     Text Ctrl Document class
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence see ../../../wxWidgets32/licence.txt
/////////////////////////////////////////////////////////////////////////////

#include "text_document.h"

#include "textctrl_view.h"  // TextEditView definition

wxIMPLEMENT_CLASS(TextCtrlDocument, wxDocument);

bool TextCtrlDocument::OnCreate(const wxString& path, long flags)
{
    if (!wxDocument::OnCreate(path, flags))
        return false;

    // Bind to changes in the text control to update the document state when it's modified
    GetTextCtrl()->Bind(wxEVT_TEXT, &TextCtrlDocument::OnTextChange, this);

    return true;
}

// Since text windows have their own method for saving to/loading from files, we override
// DoSave/OpenDocument instead of Save/LoadObject
bool TextCtrlDocument::DoSaveDocument(const wxString& filename)
{
    return GetTextCtrl()->SaveFile(filename);
}

bool TextCtrlDocument::DoOpenDocument(const wxString& filename)
{
    if (!GetTextCtrl()->LoadFile(filename))
        return false;

    // we're not modified by the user yet
    Modify(false);

    return true;
}

bool TextCtrlDocument::IsModified() const
{
    wxTextCtrl* wnd = GetTextCtrl();
    return wxDocument::IsModified() || (wnd && wnd->IsModified());
}

void TextCtrlDocument::Modify(bool modified)
{
    wxDocument::Modify(modified);

    wxTextCtrl* wnd = GetTextCtrl();
    if (wnd && !modified)
    {
        wnd->DiscardEdits();
    }
}

void TextCtrlDocument::OnTextChange(wxCommandEvent& event)
{
    Modify(true);

    event.Skip();
}

// ----------------------------------------------------------------------------
// TextEditDocument implementation
// ----------------------------------------------------------------------------

wxIMPLEMENT_DYNAMIC_CLASS(TextEditDocument, wxDocument);

wxTextCtrl* TextEditDocument::GetTextCtrl() const
{
    wxView* view = GetFirstView();
    return view ? wxStaticCast(view, TextEditView)->GetText() : nullptr;
}
