///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/button.h>
#include <wx/sizer.h>

#include "../imports/crafter_base.hpp"
#include "../imports/form_base.h"
#include "../imports/import_crafter_base.h"
#include "../imports/import_form_base.h"

#include "import_test.h"

bool ImportTest::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    m_splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
    m_splitter->SetSashGravity(0.0);
    m_splitter->SetMinimumPaneSize(150);
    dlg_sizer->Add(m_splitter, wxSizerFlags().Border(wxALL));

    m_panel_import_fb = new ImportFormBuilder(m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);

    m_panel_formbuilder = new FormBuilderBase(m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_splitter->SplitVertically(m_panel_import_fb, m_panel_formbuilder);

    m_splitter_2 = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
    m_splitter_2->SetSashGravity(0.0);
    m_splitter_2->SetMinimumPaneSize(150);
    dlg_sizer->Add(m_splitter_2, wxSizerFlags().Border(wxALL));

    m_panel_import_crafter = new ImportCrafterBase(m_splitter_2, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxTAB_TRAVERSAL);

    m_panel_crafter = new CrafterBase(m_splitter_2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_splitter_2->SplitVertically(m_panel_import_crafter, m_panel_crafter);

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &ImportTest::OnInit, this);

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
// Purpose:   Import Test Dialog
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"  // MainFrame -- Main window

#include "imports/form_base.h"
#include "imports/import_form_base.h"

#include "imports/crafter_base.hpp"
#include "imports/import_crafter_base.h"

void MainFrame::OnImportTest(wxCommandEvent& WXUNUSED(event))
{
    ImportTest dlg;
    if (dlg.Create(this))
    {
        dlg.ShowModal();
    }
    else
    {
        wxMessageBox("Unable to create ImportTest dialog!");
    }
}

void ImportTest::OnInit(wxInitDialogEvent& event)
{
    m_panel_import_fb->m_infoCtrl1->ShowMessage("wxUiEditor version");
    m_panel_import_crafter->m_infoCtrl1->ShowMessage("wxUiEditor version");
    m_panel_formbuilder->m_infoCtrl1->ShowMessage("wxFormBuilder version");
    m_panel_crafter->GetInfoCtrl1()->ShowMessage("wxCrafter version");

    m_panel_import_fb->m_auinotebook1->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGED, &ImportTest::OnImportPageChanged, this);
    m_panel_import_crafter->m_auinotebook1->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGED, &ImportTest::OnImportCrafterPageChanged,
                                                 this);
    m_panel_formbuilder->m_auinotebook1->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGED, &ImportTest::OnFormPageChanged, this);
    m_panel_crafter->GetAuinotebook1()->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGED, &ImportTest::OnCrafterPageChanged, this);

    event.Skip();  // transfer all validator data to their windows and update UI
}

void ImportTest::OnImportPageChanged(wxAuiNotebookEvent& event)
{
    m_panel_formbuilder->m_auinotebook1->ChangeSelection(event.GetSelection());
    m_panel_import_crafter->m_auinotebook1->ChangeSelection(event.GetSelection());
    m_panel_crafter->GetAuinotebook1()->ChangeSelection(event.GetSelection());
}

void ImportTest::OnImportCrafterPageChanged(wxAuiNotebookEvent& event)
{
    m_panel_formbuilder->m_auinotebook1->ChangeSelection(event.GetSelection());
    m_panel_import_fb->m_auinotebook1->ChangeSelection(event.GetSelection());
    m_panel_crafter->GetAuinotebook1()->ChangeSelection(event.GetSelection());
}

void ImportTest::OnFormPageChanged(wxAuiNotebookEvent& event)
{
    m_panel_import_fb->m_auinotebook1->ChangeSelection(event.GetSelection());
    m_panel_import_crafter->m_auinotebook1->ChangeSelection(event.GetSelection());
    m_panel_crafter->GetAuinotebook1()->ChangeSelection(event.GetSelection());
}

void ImportTest::OnCrafterPageChanged(wxAuiNotebookEvent& event)
{
    m_panel_import_fb->m_auinotebook1->ChangeSelection(event.GetSelection());
    m_panel_import_crafter->m_auinotebook1->ChangeSelection(event.GetSelection());
    m_panel_formbuilder->m_auinotebook1->ChangeSelection(event.GetSelection());
}
