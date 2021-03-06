////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/bannerwindow.h>
#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/colour.h>
#include <wx/commandlinkbutton.h>
#include <wx/dialog.h>
#include <wx/editlbox.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/listbase.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/rearrangectrl.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/tglbtn.h>

class DlgMultiTestBase : public wxDialog
{
public:
    DlgMultiTestBase() {}
    DlgMultiTestBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Widgets Testing",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Widgets Testing",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, const wxString &name = wxDialogNameStr);

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }

    // Class member variables

    wxBannerWindow* m_banner;
    wxBannerWindow* m_banner_left;
    wxBannerWindow* m_banner_right;
    wxBannerWindow* m_banner_top;
    wxButton* m_btn;
    wxButton* m_btn_2;
    wxButton* m_btn_4;
    wxButton* m_btn_bitmaps;
    wxCheckListBox* m_checkList;
    wxCommandLinkButton* m_btn_5;
    wxEditableListBox* m_edit_listbox;
    wxListView* m_listview;
    wxNotebook* m_notebook;
    wxRearrangeCtrl* m_rearrange;
    wxStaticText* m_staticText;
    wxStaticText* m_staticText_2;
    wxStaticText* m_staticText_3;
    wxStaticText* m_staticText_5;
    wxToggleButton* m_toggleBtn;
};

namespace wxue_img
{
    // Images declared in this class module:

    extern const unsigned char focus_png[517];
    extern const unsigned char no_hour_png[347];
    extern const unsigned char normal_png[508];
}
