////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>

#include "treebook_base.h"

#include "../art/english.xpm"
#include "../art/french.xpm"
#include "../art/japanese.xpm"

#include <wx/mstream.h>  // memory stream classes

// Convert a data array into a wxImage
inline wxImage wxueImage(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

bool TreebookBase::Create(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    m_treebook = new wxTreebook(this, wxID_ANY);
    {
        wxBookCtrlBase::Images bundle_list;
        bundle_list.push_back(wxBitmapBundle::FromBitmap(wxImage(english_xpm)));
        bundle_list.push_back(wxBitmapBundle::FromBitmap(wxImage(french_xpm)));
        bundle_list.push_back(wxBitmapBundle::FromBitmap(wxImage(japanese_xpm)));
        m_treebook->SetImages(bundle_list);
    }
    m_treebook->SetMinSize(wxSize(400, 400));
    box_sizer->Add(m_treebook, wxSizerFlags().Border(wxALL));

    auto* page = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddPage(page, "English", false, 0);
    page->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page, wxID_ANY, "This is a sentence in English.");
    parent_sizer->Add(m_staticText, wxSizerFlags().Border(wxALL));

    page->SetSizerAndFit(parent_sizer);

    auto* page_4 = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddSubPage(page_4, "British", false, 1);
    page_4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* page_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText_2 = new wxStaticText(page_4, wxID_ANY, "Theatre");
    page_sizer->Add(m_staticText_2, wxSizerFlags().Border(wxALL));

    page_4->SetSizerAndFit(page_sizer);

    auto* page_5 = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddSubPage(page_5, "United States", false, 2);
    page_5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* page_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_staticText_3 = new wxStaticText(page_5, wxID_ANY, "Theater");
    page_sizer_2->Add(m_staticText_3, wxSizerFlags().Border(wxALL));

    page_5->SetSizerAndFit(page_sizer_2);

    auto* page_2 = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddPage(page_2, wxString::FromUTF8("Français"), false, 3);
    page_2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_2 = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page_2, wxID_ANY, wxString::FromUTF8("Ceci est une phrase en français."));
    parent_sizer_2->Add(m_staticText, wxSizerFlags().Border(wxALL));

    page_2->SetSizerAndFit(parent_sizer_2);

    auto* page_3 = new wxPanel(m_treebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_treebook->AddPage(page_3, wxString::FromUTF8("日本語"), false, 4);
    page_3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

    auto* parent_sizer_3 = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(page_3, wxID_ANY, wxString::FromUTF8("これは日本語の文章です。"));
    parent_sizer_3->Add(m_staticText, wxSizerFlags().Border(wxALL));

    page_3->SetSizerAndFit(parent_sizer_3);

    auto* stdBtn = CreateStdDialogButtonSizer(wxCLOSE|wxNO_DEFAULT);
    stdBtn->GetCancelButton()->SetDefault();
    box_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(box_sizer);
    Centre(wxBOTH);

    return true;
}

namespace wxue_img
{

    const unsigned char er_png[302] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,9,112,72,89,115,0,0,11,
    19,0,0,11,19,1,0,154,156,24,0,0,0,224,73,68,65,84,56,203,221,210,177,74,131,65,16,4,224,47,26,68,33,69,138,32,216,11,
    166,248,81,132,148,105,124,17,75,123,75,9,136,248,2,41,82,88,40,216,219,8,150,105,140,54,177,240,17,44,4,11,81,180,177,
    139,32,177,89,225,56,238,7,91,93,56,150,155,185,27,118,103,151,63,31,139,5,108,29,21,190,240,81,243,175,66,27,239,41,
    184,138,27,204,147,115,129,149,224,59,129,157,39,252,118,42,48,197,125,168,55,176,131,103,156,101,2,15,88,67,47,222,129,
    126,144,85,86,234,30,102,104,37,2,131,244,65,51,242,86,228,81,38,208,198,18,186,120,12,236,169,36,176,28,166,93,23,12,
    187,196,107,221,20,126,4,94,98,34,167,209,119,41,58,37,112,33,242,24,159,56,200,248,97,152,214,250,205,78,236,135,73,
    99,28,226,42,238,199,217,20,118,235,22,233,14,183,216,192,38,222,112,132,147,224,231,81,229,36,90,254,47,241,13,232,231,
    48,28,126,54,168,173,0,0,0,0,73,69,78,68,174,66,96,130
    };

    const unsigned char re_png[305] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,0,31,243,255,97,0,0,0,9,112,72,89,115,0,0,11,
    19,0,0,11,19,1,0,154,156,24,0,0,0,227,73,68,65,84,56,203,221,210,33,75,195,81,20,5,240,223,116,168,32,200,194,112,172,
    235,146,6,193,184,44,88,76,102,147,205,34,171,54,139,31,65,176,24,5,63,130,32,26,108,99,12,44,43,166,205,160,162,77,16,
    68,248,91,174,240,248,239,109,125,158,114,223,59,239,190,243,222,61,28,102,30,243,25,110,3,53,124,36,220,42,182,176,130,
    183,156,80,29,5,46,163,22,113,161,138,115,252,36,124,31,107,147,4,158,208,196,54,42,56,195,59,118,99,223,194,3,6,33,62,
    38,112,146,112,139,248,196,81,233,177,86,244,238,40,171,96,148,172,215,177,140,67,236,103,198,222,196,77,117,138,193,
    75,81,123,24,150,206,238,208,205,253,32,197,75,212,91,92,77,106,154,155,34,240,140,71,28,135,31,127,216,11,99,219,57,
    19,15,74,34,237,48,114,128,83,92,224,43,70,168,164,65,42,240,141,123,188,38,2,67,92,163,17,185,88,136,92,116,34,27,255,
    1,191,112,157,46,178,241,156,153,71,0,0,0,0,73,69,78,68,174,66,96,130
    };

}
