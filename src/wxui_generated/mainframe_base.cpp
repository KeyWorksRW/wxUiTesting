////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/menu.h>

#include "mainframe_base.h"

MainFrameBase::MainFrameBase(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style) :
    wxFrame(parent, id, title, pos, size, style)
{
    auto menubar = new wxMenuBar();

    auto menuDialogs = new wxMenu();

    auto menuItem_2 = new wxMenuItem(menuDialogs, wxID_ANY, "Common Controls...",
        "Common controls", wxITEM_NORMAL);
    menuItem_2->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_LIST_VIEW, wxART_MENU));
    menuDialogs->Append(menuItem_2);

    auto menuItem = new wxMenuItem(menuDialogs, wxID_ANY, "DlgMulitTest...",
        "Launch DlgMultiTest Dialog", wxITEM_NORMAL);
    menuItem->SetBitmap(wxArtProvider::GetBitmapBundle(wxART_REPORT_VIEW, wxART_MENU));
    menuDialogs->Append(menuItem);

    auto menu_item = new wxMenuItem(menuDialogs, wxID_ANY, "Import Tests");
    menuDialogs->Append(menu_item);

    auto menuItem1 = new wxMenuItem(menuDialogs, wxID_ANY, "Other Controls Dialog...");
    menuDialogs->Append(menuItem1);

    auto menuItem2 = new wxMenuItem(menuDialogs, wxID_ANY, "Ribbon Dialog");
    menuDialogs->Append(menuItem2);

    auto menuItem3 = new wxMenuItem(menuDialogs, wxID_ANY, "Wizard");
    menuDialogs->Append(menuItem3);

    auto submenu = new wxMenu();

    auto menu_choicebook = new wxMenuItem(submenu, wxID_ANY, "Choicebook");
    submenu->Append(menu_choicebook);

    auto menu_listbook = new wxMenuItem(submenu, wxID_ANY, "Listbook");
    submenu->Append(menu_listbook);

    auto menu_notebook = new wxMenuItem(submenu, wxID_ANY, "Notebook");
    submenu->Append(menu_notebook);

    auto menu_toolbook = new wxMenuItem(submenu, wxID_ANY, "Toolbook");
    submenu->Append(menu_toolbook);

    auto menu_treebook = new wxMenuItem(submenu, wxID_ANY, "Treebook");
    submenu->Append(menu_treebook);
    menuDialogs->AppendSubMenu(submenu, "Book Controls");

    menuDialogs->AppendSeparator();

    auto menuItem4 = new wxMenuItem(menuDialogs, wxID_EXIT, "Exit");
    menuDialogs->Append(menuItem4);
    menubar->Append(menuDialogs, "&Dialogs");

    SetMenuBar(menubar);

    m_toolBar = CreateToolBar();
    auto tool_2 = m_toolBar->AddTool(wxID_ANY, "Common Controls...", wxArtProvider::GetBitmapBundle(wxART_LIST_VIEW, wxART_TOOLBAR));

    auto tool = m_toolBar->AddTool(wxID_ANY, "DlgMulitTest...", wxArtProvider::GetBitmapBundle(wxART_REPORT_VIEW, wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, 
            "Launch DlgMultiTest Dialog", "Launch DlgMultiTest Dialog");

    auto tool_3 = m_toolBar->AddTool(wxID_ANY, "ImportTest", wxArtProvider::GetBitmapBundle(wxART_FULL_SCREEN, wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, 
            "Import Test", "Import Test");

    m_toolBar->Realize();

    m_statusBar = CreateStatusBar();

    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_MENU, &MainFrameBase::OnCommonDialog, this, menuItem_2->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnMultiTestDialog, this, menuItem->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnImportTest, this, menu_item->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnOtherCtrls, this, menuItem1->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnRibbonDialog, this, menuItem2->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnWizard, this, menuItem3->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnChoicebook, this, menu_choicebook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnListbook, this, menu_listbook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnNotebook, this, menu_notebook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnToolbook, this, menu_toolbook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnTreebook, this, menu_treebook->GetId());
    Bind(wxEVT_MENU, &MainFrameBase::OnQuit, this, wxID_EXIT);
    Bind(wxEVT_TOOL, &MainFrameBase::OnCommonDialog, this, tool_2->GetId());
    Bind(wxEVT_TOOL, &MainFrameBase::OnMultiTestDialog, this, tool->GetId());
    Bind(wxEVT_TOOL, &MainFrameBase::OnImportTest, this, tool_3->GetId());
}
