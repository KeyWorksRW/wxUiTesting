///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/sizer.h>

#include "popupwin.h"

PopupWin::PopupWin(wxWindow* parent, int style) : wxPopupTransientWindow(parent, style)
{
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(this, wxID_ANY,
        "This is a wxPopupTransientWindow set to use a raised border around it. Note that the default is to not have a border at all.\n\nBTW, right-click anywhere in the dialog to get a popup menu for changing some of the control values.\n\nClick outside this window to dismiss it.");
    m_staticText->Wrap(250);
    parent_sizer->Add(m_staticText, wxSizerFlags().Border(wxALL));

    SetSizerAndFit(parent_sizer);
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
