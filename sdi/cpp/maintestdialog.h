///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/activityindicator.h>
#include <wx/animate.h>
#include <wx/bannerwindow.h>
#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/checklst.h>
#include <wx/choice.h>
#include <wx/clrpicker.h>
#include <wx/collpane.h>
#include <wx/colour.h>
#include <wx/combobox.h>
#include <wx/commandlinkbutton.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/dialog.h>
#include <wx/editlbox.h>
#include <wx/event.h>
#include <wx/filectrl.h>
#include <wx/filepicker.h>
#include <wx/font.h>
#include <wx/fontpicker.h>
#include <wx/gdicmn.h>
#include <wx/html/htmlwin.h>
#include <wx/htmllbox.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/listbase.h>
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/radiobut.h>
#include <wx/rearrangectrl.h>
#include <wx/ribbon/art.h>
#include <wx/ribbon/bar.h>
#include <wx/ribbon/control.h>
#include <wx/ribbon/toolbar.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/stc/stc.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
#include <wx/timectrl.h>

namespace wxue_img
{
    // ../art/clr_hourglass.gif
    extern const unsigned char clr_hourglass_gif[2017];
}

class MainTestDialog : public wxDialog
{
public:
    wxHtmlWindow* m_htmlWin;

    static const int DLG_MAINTEST = wxID_HIGHEST + 100;
    static const int ID_RICHTEXT = 100;

    enum
    {
        TXT_CTRL = wxID_HIGHEST + 1
    };

    MainTestDialog() {}
    MainTestDialog(wxWindow *parent, wxWindowID id = DLG_MAINTEST, const wxString& title = "Main Testing Dialog",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }
    bool Create(wxWindow *parent, wxWindowID id = DLG_MAINTEST, const wxString& title = "Main Testing Dialog",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

    void OnEventName(const std::string& event_name)
    {
        m_events_list->Select(m_events_list->Append(wxString().FromUTF8(event_name)));
    }

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnClearList(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDisableBitmapsBtn(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInit(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnPageChanged(wxBookCtrlEvent& event) { event.Skip(); }
    virtual void OnPopupBtn(wxCommandEvent& event) { event.Skip(); }

    // Validator variables

    int m_valRadio { 1 };

    // Class member variables

    wxActivityIndicator* indicator;
    wxAnimationCtrl* m_animation_ctrl;
    wxBannerWindow* m_banner;
    wxBannerWindow* m_banner_left;
    wxBannerWindow* m_banner_right;
    wxBannerWindow* m_banner_top;
    wxButton* m_btn;
    wxButton* m_btn_2;
    wxButton* m_btn_3;
    wxButton* m_btn_4;
    wxButton* m_btn_6;
    wxButton* m_btn_7;
    wxButton* m_btn_bitmaps;
    wxCheckBox* m_checkBox;
    wxCheckBox* m_checkBox_sizer;
    wxCheckBox* m_checkPlayAnimation;
    wxCheckListBox* m_checkList2;
    wxCheckListBox* m_checkList;
    wxCheckListBox* m_checkList_2;
    wxChoice* m_choice2;
    wxChoice* m_choice;
    wxCollapsiblePane* collapsible_pane;
    wxColourPickerCtrl* m_colourPicker;
    wxComboBox* m_comboBox2;
    wxComboBox* m_comboBox;
    wxCommandLinkButton* m_btn_5;
    wxDatePickerCtrl* m_datePicker;
    wxDirPickerCtrl* m_dirPicker;
    wxEditableListBox* m_edit_listbox;
    wxFileCtrl* fileCtrl;
    wxFilePickerCtrl* m_filePicker;
    wxFontPickerCtrl* m_fontPicker;
    wxListBox* m_events_list;
    wxListBox* m_listBox2;
    wxListBox* m_listbox;
    wxListView* m_listview;
    wxNotebook* m_notebook;
    wxRadioButton* m_radioBtn2;
    wxRadioButton* m_radioBtn;
    wxRadioButton* m_radioBtn_2;
    wxRadioButton* m_radioBtn_3;
    wxRadioButton* m_radioBtn_4;
    wxRadioButton* m_radioBtn_5;
    wxRadioButton* m_radioBtn_6;
    wxRadioButton* m_radioBtn_7;
    wxRadioButton* m_radioBtn__sizer;
    wxRearrangeCtrl* m_rearrange;
    wxRibbonBar* m_rbnBar;
    wxRichTextCtrl* m_richText;
    wxSimpleHtmlListBox* html_listbox;
    wxStaticText* m_staticText10;
    wxStaticText* m_staticText3;
    wxStaticText* m_staticText4;
    wxStaticText* m_staticText5;
    wxStaticText* m_staticText6;
    wxStaticText* m_staticText7;
    wxStaticText* m_staticText8;
    wxStaticText* m_staticText9;
    wxStaticText* m_staticText;
    wxStaticText* m_staticText_2;
    wxStaticText* m_staticText_3;
    wxStaticText* m_staticText_4;
    wxStaticText* m_static_text;
    wxStaticText* staticText_5;
    wxStaticText* static_text2;
    wxStaticText* static_text3;
    wxStaticText* static_text;
    wxStyledTextCtrl* m_scintilla;
    wxTextCtrl* m_text_ctrl;
    wxTimePickerCtrl* m_timePicker;
    wxToggleButton* m_toggleBtn;
    wxToggleButton* m_toggleBtn_2;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
