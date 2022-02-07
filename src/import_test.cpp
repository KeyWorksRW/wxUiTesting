/////////////////////////////////////////////////////////////////////////////
// Purpose:   Import Test Dialog
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "imports/form_base.h"
#include "imports/import_form_base.h"

#include "imports/crafter_base.hpp"
#include "imports/import_crafter_base.h"

#include "import_test_base.h"

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
