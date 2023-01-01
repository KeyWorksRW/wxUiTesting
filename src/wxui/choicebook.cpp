///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>

#include "choicebook.h"

#include "../art/english.xpm"
#include "../art/french.xpm"
#include "../art/japanese.xpm"

bool ChoiceBook::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_choicebook = new wxChoicebook(this, wxID_ANY);
    m_choicebook->SetMinSize(wxSize(400, 400));
    parent_sizer->Add(m_choicebook, wxSizerFlags().Border(wxALL));

    auto* btn = new wxButton(m_choicebook, wxID_ANY, "First");
    m_choicebook->GetControlSizer()->Add(btn, wxSizerFlags().Expand().Border(wxALL));

    auto* btn_2 = new wxButton(m_choicebook, wxID_ANY, "Last");
    m_choicebook->GetControlSizer()->Add(btn_2, wxSizerFlags().Expand().Border(wxALL));

    auto* page = new wxPanel(m_choicebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_choicebook->AddPage(page, "English");
    page->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page, wxID_ANY, "This is a sentence in English.");
    parent_sizer_2->Add(m_staticText, wxSizerFlags().Border(wxALL));

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText_2 = new wxStaticText(page, wxID_ANY,
        "The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.");
    m_staticText_2->Wrap(380);
    box_sizer->Add(m_staticText_2, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer_2->Add(box_sizer, wxSizerFlags().Border(wxALL));
    page->SetSizerAndFit(parent_sizer_2);

    auto* page_2 = new wxPanel(m_choicebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_choicebook->AddPage(page_2, wxString::FromUTF8("Français"));
    page_2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer__2 = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page_2, wxID_ANY, wxString::FromUTF8("Ceci est une phrase en français."));
    parent_sizer__2->Add(m_staticText, wxSizerFlags().Border(wxALL));

    auto* box_sizer_3 = new wxBoxSizer(wxVERTICAL);

    m_staticText__3 = new wxStaticText(page_2, wxID_ANY,
        "The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.");
    m_staticText__3->Wrap(390);
    box_sizer_3->Add(m_staticText__3, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer__2->Add(box_sizer_3, wxSizerFlags().Border(wxALL));
    page_2->SetSizerAndFit(parent_sizer__2);

    auto* page_3 = new wxPanel(m_choicebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_choicebook->AddPage(page_3, wxString::FromUTF8("日本語"));
    page_3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_3 = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page_3, wxID_ANY, wxString::FromUTF8("これは日本語の文章です。"));
    parent_sizer_3->Add(m_staticText, wxSizerFlags().Border(wxALL));

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_staticText__2 = new wxStaticText(page_3, wxID_ANY,
        "The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.");
    m_staticText__2->Wrap(390);
    box_sizer_2->Add(m_staticText__2, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer_3->Add(box_sizer_2, wxSizerFlags().Border(wxALL));
    page_3->SetSizerAndFit(parent_sizer_3);

    auto* stdBtn = CreateStdDialogButtonSizer(wxCLOSE|wxNO_DEFAULT);
    stdBtn->GetCancelButton()->SetDefault();
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    btn->Bind(wxEVT_BUTTON,
        [this](wxCommandEvent&)
        {
            m_choicebook->SetSelection(0);
        } );
    btn_2->Bind(wxEVT_BUTTON,
        [this](wxCommandEvent&)
        {
            m_choicebook->SetSelection(2);
        } );

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

/////////////////// Non-generated Copyright/License Info ////////////////////
// Purpose:   Multiple Tests dialog
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"  // MainFrame -- Main window

void MainFrame::OnChoicebook(wxCommandEvent& WXUNUSED(event))
{
    ChoiceBook dlg(this);
    dlg.ShowModal();
}
