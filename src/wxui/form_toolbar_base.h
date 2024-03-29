///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/combobox.h>
#include <wx/gdicmn.h>
#include <wx/toolbar.h>

class MyToolBarBase : public wxToolBar
{
public:
    MyToolBarBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = wxTB_HORIZONTAL, const wxString &name = wxPanelNameStr);

protected:

    // Class member variables

    wxComboBox* m_comboBox;
};

namespace wxue_img
{
    // Images declared in this class module:

    extern const unsigned char english_png[541];
    extern const unsigned char japanese_png[377];
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
