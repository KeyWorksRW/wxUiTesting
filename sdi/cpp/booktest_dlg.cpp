///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/colour.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>

#include "images.h"

#include "booktest_dlg.h"

// Convert a data array into a wxImage
wxImage wxueImage(const unsigned char* data, size_t size_data);

namespace wxue_img
{
    extern const unsigned char english_png[541];
    extern const unsigned char er_png[302];
    extern const unsigned char french_png[252];
    extern const unsigned char japanese_png[377];
    extern const unsigned char re_png[305];
}

bool BookTestDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);
    dlg_sizer->SetMinSize(400, 400);

    m_notebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxAUI_NB_TOP|wxAUI_NB_TAB_SPLIT|wxAUI_NB_TAB_MOVE|wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_CLOSE_ON_ACTIVE_TAB|wxAUI_NB_MIDDLE_CLICK_CLOSE
    );
    dlg_sizer->Add(m_notebook, wxSizerFlags(1).Expand().Border(wxALL));

    auto* page_2 = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(page_2, "ChoiceBook");

    auto* page_sizer_1 = new wxBoxSizer(wxVERTICAL);

    m_choicebook = new wxChoicebook(page_2, wxID_ANY);
    m_choicebook->SetMinSize(wxSize(400, 400));
    page_sizer_1->Add(m_choicebook, wxSizerFlags().Border(wxALL));

    auto* btn = new wxButton(m_choicebook, wxID_ANY, "First");
    m_choicebook->GetControlSizer()->Add(btn, wxSizerFlags().Expand().Border(wxALL));

    auto* btn_2 = new wxButton(m_choicebook, wxID_ANY, "Last");
    m_choicebook->GetControlSizer()->Add(btn_2, wxSizerFlags().Expand().Border(wxALL));

    auto* page_20 = new wxPanel(m_choicebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_choicebook->AddPage(page_20, "English");
    page_20->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_13 = new wxBoxSizer(wxVERTICAL);

    m_staticText_16 = new wxStaticText(page_20, wxID_ANY, "This is a sentence in English.");
    parent_sizer_13->Add(m_staticText_16, wxSizerFlags().Border(wxALL));

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText_2 = new wxStaticText(page_20, wxID_ANY,
        "The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.");
    m_staticText_2->Wrap(380);
    box_sizer->Add(m_staticText_2, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer_13->Add(box_sizer, wxSizerFlags().Border(wxALL));
    page_20->SetSizerAndFit(parent_sizer_13);

    auto* page_21 = new wxPanel(m_choicebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_choicebook->AddPage(page_21, wxString::FromUTF8("Français"));
    page_21->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer__2 = new wxBoxSizer(wxVERTICAL);

    m_staticText_17 = new wxStaticText(page_21, wxID_ANY, wxString::FromUTF8("Ceci est une phrase en français."));
    parent_sizer__2->Add(m_staticText_17, wxSizerFlags().Border(wxALL));

    auto* box_sizer_3 = new wxBoxSizer(wxVERTICAL);

    m_staticText__3 = new wxStaticText(page_21, wxID_ANY,
        "The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.");
    m_staticText__3->Wrap(390);
    box_sizer_3->Add(m_staticText__3, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer__2->Add(box_sizer_3, wxSizerFlags().Border(wxALL));
    page_21->SetSizerAndFit(parent_sizer__2);

    auto* page_22 = new wxPanel(m_choicebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_choicebook->AddPage(page_22, wxString::FromUTF8("日本語"));
    page_22->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_14 = new wxBoxSizer(wxVERTICAL);

    m_staticText_18 = new wxStaticText(page_22, wxID_ANY, wxString::FromUTF8("これは日本語の文章です。"));
    parent_sizer_14->Add(m_staticText_18, wxSizerFlags().Border(wxALL));

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_staticText__2 = new wxStaticText(page_22, wxID_ANY,
        "The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.");
    m_staticText__2->Wrap(390);
    box_sizer_2->Add(m_staticText__2, wxSizerFlags().Expand().Border(wxALL));

    parent_sizer_14->Add(box_sizer_2, wxSizerFlags().Border(wxALL));
    page_22->SetSizerAndFit(parent_sizer_14);
    page_2->SetSizerAndFit(page_sizer_1);

    auto* page_3 = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(page_3, "ListBook");

    auto* page_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_listbook = new wxListbook(page_3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_LEFT);
    {
        wxWithImages::Images bundle_list;
        bundle_list.push_back(wxue_img::bundle_english_png());
        bundle_list.push_back(wxue_img::bundle_french_png());
        bundle_list.push_back(wxue_img::bundle_japanese_png());
        m_listbook->SetImages(bundle_list);
    }
    m_listbook->SetMinSize(wxSize(400, 400));
    page_sizer_2->Add(m_listbook, wxSizerFlags().Border(wxALL));

    auto* page_6 = new wxPanel(m_listbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_listbook->AddPage(page_6, "English", false, 0);
    page_6->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText_6 = new wxStaticText(page_6, wxID_ANY, "This is a sentence in English.");
    parent_sizer->Add(m_staticText_6, wxSizerFlags().Border(wxALL));
    page_6->SetSizerAndFit(parent_sizer);

    auto* page_7 = new wxPanel(m_listbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_listbook->AddPage(page_7, wxString::FromUTF8("Français"), false, 1);
    page_7->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_staticText_3 = new wxStaticText(page_7, wxID_ANY, wxString::FromUTF8("Ceci est une phrase en français."));
    parent_sizer_2->Add(m_staticText_3, wxSizerFlags().Border(wxALL));
    page_7->SetSizerAndFit(parent_sizer_2);

    auto* page_8 = new wxPanel(m_listbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_listbook->AddPage(page_8, wxString::FromUTF8("日本語"), false, 2);
    page_8->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_3 = new wxBoxSizer(wxVERTICAL);

    m_staticText_7 = new wxStaticText(page_8, wxID_ANY, wxString::FromUTF8("これは日本語の文章です。"));
    parent_sizer_3->Add(m_staticText_7, wxSizerFlags().Border(wxALL));
    page_8->SetSizerAndFit(parent_sizer_3);

    page_3->SetSizerAndFit(page_sizer_2);

    auto* page_4 = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(page_4, "NoteBook");

    auto* page_sizer_3 = new wxBoxSizer(wxVERTICAL);

    m_notebook_2 = new wxNotebook(page_4, wxID_ANY);
    {
        wxWithImages::Images bundle_list;
        bundle_list.push_back(wxue_img::bundle_english_png());
        bundle_list.push_back(wxue_img::bundle_french_png());
        bundle_list.push_back(wxue_img::bundle_japanese_png());
        m_notebook_2->SetImages(bundle_list);
    }
    m_notebook_2->SetMinSize(wxSize(400, 400));
    page_sizer_3->Add(m_notebook_2, wxSizerFlags().Expand().Border(wxALL));

    auto* page_9 = new wxPanel(m_notebook_2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook_2->AddPage(page_9, "English", false, 0);
    page_9->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_4 = new wxBoxSizer(wxVERTICAL);

    m_staticText_4 = new wxStaticText(page_9, wxID_ANY, "This is a sentence in English.");
    parent_sizer_4->Add(m_staticText_4, wxSizerFlags().Border(wxALL));
    page_9->SetSizerAndFit(parent_sizer_4);

    auto* page_10 = new wxPanel(m_notebook_2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook_2->AddPage(page_10, wxString::FromUTF8("Français"), false, 1);
    page_10->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_5 = new wxBoxSizer(wxVERTICAL);

    m_staticText_8 = new wxStaticText(page_10, wxID_ANY, wxString::FromUTF8("Ceci est une phrase en français."));
    parent_sizer_5->Add(m_staticText_8, wxSizerFlags().Border(wxALL));
    page_10->SetSizerAndFit(parent_sizer_5);

    auto* page_11 = new wxPanel(m_notebook_2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook_2->AddPage(page_11, wxString::FromUTF8("日本語"), false, 2);
    page_11->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_6 = new wxBoxSizer(wxVERTICAL);

    m_staticText_9 = new wxStaticText(page_11, wxID_ANY, wxString::FromUTF8("これは日本語の文章です。"));
    parent_sizer_6->Add(m_staticText_9, wxSizerFlags().Border(wxALL));
    page_11->SetSizerAndFit(parent_sizer_6);

    page_4->SetSizerAndFit(page_sizer_3);

    auto* page_5 = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(page_5, "ToolBook");

    auto* page_sizer_4 = new wxBoxSizer(wxVERTICAL);

    m_toolbook = new wxToolbook(page_5, wxID_ANY);
    {
        wxWithImages::Images bundle_list;
        bundle_list.push_back(wxue_img::bundle_english_png());
        bundle_list.push_back(wxue_img::bundle_french_png());
        bundle_list.push_back(wxue_img::bundle_japanese_png());
        m_toolbook->SetImages(bundle_list);
    }
    m_toolbook->SetMinSize(wxSize(400, 400));
    page_sizer_4->Add(m_toolbook, wxSizerFlags().Border(wxALL));

    auto* page_12 = new wxPanel(m_toolbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_toolbook->AddPage(page_12, "English", false, 0);
    page_12->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_7 = new wxBoxSizer(wxVERTICAL);

    m_staticText_5 = new wxStaticText(page_12, wxID_ANY, "This is a sentence in English.");
    parent_sizer_7->Add(m_staticText_5, wxSizerFlags().Border(wxALL));
    page_12->SetSizerAndFit(parent_sizer_7);

    auto* page_13 = new wxPanel(m_toolbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_toolbook->AddPage(page_13, wxString::FromUTF8("Français"), false, 1);
    page_13->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_8 = new wxBoxSizer(wxVERTICAL);

    m_staticText_10 = new wxStaticText(page_13, wxID_ANY, wxString::FromUTF8("Ceci est une phrase en français."));
    parent_sizer_8->Add(m_staticText_10, wxSizerFlags().Border(wxALL));
    page_13->SetSizerAndFit(parent_sizer_8);

    auto* page_14 = new wxPanel(m_toolbook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_toolbook->AddPage(page_14, wxString::FromUTF8("日本語"), false, 2);
    page_14->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_9 = new wxBoxSizer(wxVERTICAL);

    m_staticText_11 = new wxStaticText(page_14, wxID_ANY, wxString::FromUTF8("これは日本語の文章です。"));
    parent_sizer_9->Add(m_staticText_11, wxSizerFlags().Border(wxALL));
    page_14->SetSizerAndFit(parent_sizer_9);

    page_5->SetSizerAndFit(page_sizer_4);

    auto* page = new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_notebook->AddPage(page, "TreeBook");

    auto* page_sizer_5 = new wxBoxSizer(wxVERTICAL);

    m_treebook = new wxTreebook(page, wxID_ANY);
    {
        wxWithImages::Images bundle_list;
        bundle_list.push_back(wxue_img::bundle_english_png());
        bundle_list.push_back(wxue_img::bundle_french_png());
        bundle_list.push_back(wxue_img::bundle_japanese_png());
        m_treebook->SetImages(bundle_list);
    }
    m_treebook->SetMinSize(wxSize(400, 400));
    page_sizer_5->Add(m_treebook, wxSizerFlags().Border(wxALL));

    auto* page_15 = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddPage(page_15, "English", false, 0);
    page_15->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_10 = new wxBoxSizer(wxVERTICAL);

    m_staticText_12 = new wxStaticText(page_15, wxID_ANY, "This is a sentence in English.");
    parent_sizer_10->Add(m_staticText_12, wxSizerFlags().Border(wxALL));
    page_15->SetSizerAndFit(parent_sizer_10);

    auto* page_16 = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddSubPage(page_16, "British", false, 1);
    page_16->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* page_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText_13 = new wxStaticText(page_16, wxID_ANY, "Theatre");
    page_sizer->Add(m_staticText_13, wxSizerFlags().Border(wxALL));
    page_16->SetSizerAndFit(page_sizer);

    auto* page_17 = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddSubPage(page_17, "United States", false, 2);
    page_17->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* page_sizer_6 = new wxBoxSizer(wxVERTICAL);

    m_staticText_14 = new wxStaticText(page_17, wxID_ANY, "Theater");
    page_sizer_6->Add(m_staticText_14, wxSizerFlags().Border(wxALL));
    page_17->SetSizerAndFit(page_sizer_6);

    auto* page_18 = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddPage(page_18, wxString::FromUTF8("Français"), false, 3);
    page_18->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_11 = new wxBoxSizer(wxVERTICAL);

    m_staticText_15 = new wxStaticText(page_18, wxID_ANY, wxString::FromUTF8("Ceci est une phrase en français."));
    parent_sizer_11->Add(m_staticText_15, wxSizerFlags().Border(wxALL));
    page_18->SetSizerAndFit(parent_sizer_11);

    auto* page_19 = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddPage(page_19, wxString::FromUTF8("日本語"), false, 4);
    page_19->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_12 = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page_19, wxID_ANY, wxString::FromUTF8("これは日本語の文章です。"));
    parent_sizer_12->Add(m_staticText, wxSizerFlags().Border(wxALL));
    page_19->SetSizerAndFit(parent_sizer_12);

    page->SetSizerAndFit(page_sizer_5);

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    btn->Bind(wxEVT_BUTTON,
        [this](wxCommandEvent&)
        {
            m_choicebook->SetSelection(0);
        });
    btn_2->Bind(wxEVT_BUTTON,
        [this](wxCommandEvent&)
        {
            m_choicebook->SetSelection(2);
        });

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
// Purpose:   Common controls dialog
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"  // auto-generated: ../wxui_generated/mainframe_base.h and ../wxui_generated/mainframe_base.cpp

void MainFrame::OnBookTestDlg(wxCommandEvent& WXUNUSED(event))
{
    BookTestDlg dlg(this);
    dlg.ShowModal();
}
