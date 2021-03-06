////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/splitter.h>

class CrafterBase;
class FormBuilderBase;
class ImportCrafterBase;
class ImportFormBuilder;

#include <wx/aui/auibook.h>

class ImportTest : public wxDialog
{
public:
    ImportTest() {}
    ImportTest(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "wxFormBuilder comparison",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "wxFormBuilder comparison",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    void OnImportPageChanged(wxAuiNotebookEvent& event);
    void OnImportCrafterPageChanged(wxAuiNotebookEvent& event);
    void OnFormPageChanged(wxAuiNotebookEvent& event);
    void OnCrafterPageChanged(wxAuiNotebookEvent& event);

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);

    // Class member variables

    CrafterBase* m_panel_crafter;
    FormBuilderBase* m_panel_formbuilder;
    ImportCrafterBase* m_panel_import_crafter;
    ImportFormBuilder* m_panel_import_fb;
    wxSplitterWindow* m_splitter;
    wxSplitterWindow* m_splitter_2;
};
