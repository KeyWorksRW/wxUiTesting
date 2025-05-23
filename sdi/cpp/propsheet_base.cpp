///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/bookctrl.h>
#include <wx/icon.h>
#include <wx/panel.h>
#include <wx/sizer.h>

#include "images.h"

#include "propsheet_base.h"

bool PropSheetBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString& name)
{
    SetSheetStyle(wxPROPSHEET_NOTEBOOK);
    SetSheetInnerBorder(20);
    if (!wxPropertySheetDialog::Create(parent, id, title, pos, size, style, name))
    {
        return false;
    }

    CreateButtons(wxOK|wxCANCEL);

    SetIcon(wxue_img::bundle_face_smile_svg(16, 16).GetIconFor(this));

    auto* page1 = new wxPanel(GetBookCtrl(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    GetBookCtrl()->AddPage(page1, "Page 1");

    auto* page_sizer_1 = new wxBoxSizer(wxVERTICAL);

    m_staticText1 = new wxStaticText(page1, wxID_ANY, "TODO: replace this control with something more useful...");
    m_staticText1->Wrap(200);
    page_sizer_1->Add(m_staticText1, wxSizerFlags().Border(wxALL));
    page1->SetSizerAndFit(page_sizer_1);

    auto* page2 = new wxPanel(GetBookCtrl(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    GetBookCtrl()->AddPage(page2, "Page 2");

    auto* page_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_staticText2 = new wxStaticText(page2, wxID_ANY, "TODO: replace this control with something more useful...");
    m_staticText2->Wrap(200);
    page_sizer_2->Add(m_staticText2, wxSizerFlags().Border(wxALL));
    page2->SetSizerAndFit(page_sizer_2);

    auto* page3 = new wxPanel(GetBookCtrl(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    GetBookCtrl()->AddPage(page3, "Page 3");

    auto* page_sizer_3 = new wxBoxSizer(wxVERTICAL);

    m_staticText3 = new wxStaticText(page3, wxID_ANY, "TODO: replace this control with something more useful...");
    m_staticText3->Wrap(200);
    page_sizer_3->Add(m_staticText3, wxSizerFlags().Border(wxALL));
    page3->SetSizerAndFit(page_sizer_3);

    LayoutDialog(wxBOTH);

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

#include "mainframe.h"  // MainFrame -- Main window

void MainFrame::OnPropSheetDlg(wxCommandEvent& WXUNUSED(event))
{
    PropSheetBase dlg(this);
    dlg.ShowModal();
}
