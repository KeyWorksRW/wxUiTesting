/////////////////////////////////////////////////////////////////////////////
// Purpose:   Main window
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"  // auto-generated: ../wxui_generated/mainframe_base.h and ../wxui_generated/mainframe_base.cpp

#include "commonctrls.h"   // CommonCtrls -- Common controls dialog
#include "dlgmultitest.h"  // DlgMultiTest -- Multiple Tests dialog
#include "other_ctrls.h"   // OtherCtrlsDlg
#include "ribbondlg.h"     // RibbonDlg
#include "wizard.h"        // Wizard

#include "../wxui_generated/python_dlg_base.h"
#include "choicebook_base.h"
#include "listbook_base.h"
#include "notebook_base.h"
#include "toolbook_base.h"
#include "treebook_base.h"

#include "import_test_base.h"

MainFrame::MainFrame(wxWindow* parent) : MainFrameBase(parent) {}

void MainFrame::OnMultiTestDialog(wxCommandEvent& WXUNUSED(event))
{
    DlgMultiTest dlg(this);
    dlg.ShowModal();
}

void MainFrame::OnCommonDialog(wxCommandEvent& WXUNUSED(event))
{
    CommonCtrls dlg(this);
    dlg.ShowModal();
}

void MainFrame::OnOtherCtrls(wxCommandEvent& WXUNUSED(event))
{
    OtherCtrlsDlg dlg(this);
    dlg.ShowModal();
}

void MainFrame::OnRibbonDialog(wxCommandEvent& WXUNUSED(event))
{
    RibbonDlg dlg(this);
    dlg.ShowModal();
}

void MainFrame::OnWizard(wxCommandEvent& WXUNUSED(event))
{
    Wizard wizard(this);
    wizard.Run();
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true forces the frame to close
    Close(true);
}

void MainFrame::OnChoicebook(wxCommandEvent& WXUNUSED(event))
{
    ChoiceBookBase dlg(this);
    dlg.ShowModal();
}

void MainFrame::OnNotebook(wxCommandEvent& WXUNUSED(event))
{
    NotebookBase dlg(this);
    dlg.ShowModal();
}

void MainFrame::OnListbook(wxCommandEvent& WXUNUSED(event))
{
    ListbookBase dlg(this);
    dlg.ShowModal();
}

void MainFrame::OnTreebook(wxCommandEvent& WXUNUSED(event))
{
    TreebookBase dlg(this);
    dlg.ShowModal();
}

void MainFrame::OnToolbook(wxCommandEvent& WXUNUSED(event))
{
    ToolbookBase dlg(this);
    dlg.ShowModal();
}

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

void MainFrame::OnPythonDlg(wxCommandEvent& WXUNUSED(event))
{
    PythonDlgBase dlg(this);
    dlg.ShowModal();
}
