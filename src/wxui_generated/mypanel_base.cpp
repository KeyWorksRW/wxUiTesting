////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////

#include <wx/sizer.h>

#include "mypanel_base.h"

MyPanelBase::MyPanelBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) :
    wxPanel(parent, id, pos, size, style)
{
    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
    m_splitter->SetSashGravity(0.0);
    parent_sizer->Add(m_splitter, wxSizerFlags(1).Expand().Border(wxALL));

    auto panel = new wxPanel(m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);

    auto parent_sizer2 = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(panel, wxID_ANY, wxString::FromUTF8("Left Panel"));
    parent_sizer2->Add(m_staticText, wxSizerFlags().Border(wxALL));

    panel->SetSizerAndFit(parent_sizer2);

    auto m_panel2 = new wxPanel(m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);

    auto parent_sizer3 = new wxBoxSizer(wxVERTICAL);

    m_staticText2 = new wxStaticText(m_panel2, wxID_ANY, wxString::FromUTF8("Right Panel"));
    parent_sizer3->Add(m_staticText2, wxSizerFlags().Border(wxALL));

    m_panel2->SetSizerAndFit(parent_sizer3);
    m_splitter->SplitVertically(panel, m_panel2);

    SetSizerAndFit(parent_sizer);
}
