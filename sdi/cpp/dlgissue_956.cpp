///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/gbsizer.h>
#include <wx/panel.h>
#include <wx/sizer.h>

#include "dlgissue_956.h"

bool DlgIssue_956::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
    {
        return false;
    }

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* panel_2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_THEME|wxTAB_TRAVERSAL);
    dlg_sizer->Add(panel_2, wxSizerFlags().Expand().Border(wxALL));

    auto* grid_bag_sizer = new wxGridBagSizer();

    m_staticText_4 = new wxStaticText(panel_2, wxID_ANY, "list test");
    grid_bag_sizer->Add(m_staticText_4, wxGBPosition(0, 0), wxGBSpan(1, 1), wxALL, 5);

    m_choice = new wxChoice(panel_2, wxID_ANY);
    grid_bag_sizer->Add(m_choice, wxGBPosition(0, 1), wxGBSpan(1, 1), wxALL|wxEXPAND, 5);

    m_btn = new wxButton(panel_2, wxID_ANY, wxEmptyString);
    m_btn->SetLabelMarkup("&Refresh");
    grid_bag_sizer->Add(m_btn, wxGBPosition(0, 2), wxGBSpan(1, 1), wxALL, 5);

    m_btn_2 = new wxButton(panel_2, wxID_ANY, wxEmptyString);
    m_btn_2->SetLabelMarkup("&New");
    grid_bag_sizer->Add(m_btn_2, wxGBPosition(0, 3), wxGBSpan(1, 1), wxALL, 5);

    m_btn_3 = new wxButton(panel_2, wxID_ANY, wxEmptyString);
    m_btn_3->SetLabelMarkup("&Edit");
    grid_bag_sizer->Add(m_btn_3, wxGBPosition(0, 4), wxGBSpan(1, 1), wxALL, 5);

    m_btn_4 = new wxButton(panel_2, wxID_ANY, wxEmptyString);
    m_btn_4->SetLabelMarkup("&Delete");
    grid_bag_sizer->Add(m_btn_4, wxGBPosition(0, 5), wxGBSpan(1, 1), wxALL, 5);

    m_staticText_5 = new wxStaticText(panel_2, wxID_ANY, "test type");
    grid_bag_sizer->Add(m_staticText_5, wxGBPosition(1, 0), wxGBSpan(1, 1), wxALL, 5);

    m_choice_2 = new wxChoice(panel_2, wxID_ANY);
    grid_bag_sizer->Add(m_choice_2, wxGBPosition(1, 1), wxGBSpan(1, 5), wxALL|wxEXPAND, 5);
    {
        grid_bag_sizer->AddGrowableCol(1);
        grid_bag_sizer->AddGrowableRow(1);
    }
    panel_2->SetSizerAndFit(grid_bag_sizer);

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    if (pos != wxDefaultPosition)
    {
        SetPosition(FromDIP(pos));
    }
    if (size == wxDefaultSize)
    {
        SetSizerAndFit(dlg_sizer);
    }
    else
    {
        SetSizer(dlg_sizer);
        if (size.x == wxDefaultCoord || size.y == wxDefaultCoord)
        {
            Fit();
        }
        SetSize(FromDIP(size));
        Layout();
    }
    Centre(wxBOTH);

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
