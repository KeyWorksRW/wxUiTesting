/////////////////////////////////////////////////////////////////////////////
// Purpose:   Import Test Dialog
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "imports/form_base.h"
#include "imports/import_form_base.h"

#include "ui/import_test_base.h"

void ImportTest::OnInit(wxInitDialogEvent& event)
{
    m_panel_import->m_infoCtrl1->ShowMessage("wxUiEditor version");
    m_panel_formbuilder->m_infoCtrl1->ShowMessage("wxFormBuilder version");

    m_panel_import->m_auinotebook1->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGED, &ImportTest::OnImportPageChanged, this);
    m_panel_formbuilder->m_auinotebook1->Bind(wxEVT_AUINOTEBOOK_PAGE_CHANGED, &ImportTest::OnFormPageChanged, this);

    event.Skip();  // transfer all validator data to their windows and update UI
}

void ImportTest::OnImportPageChanged(wxAuiNotebookEvent& event)
{
    m_panel_formbuilder->m_auinotebook1->ChangeSelection(event.GetSelection());
}

void ImportTest::OnFormPageChanged(wxAuiNotebookEvent& event)
{
    m_panel_import->m_auinotebook1->ChangeSelection(event.GetSelection());
}
