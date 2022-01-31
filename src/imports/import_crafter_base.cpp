////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/artprov.h>
#include <wx/gbsizer.h>
#include <wx/ribbon/buttonbar.h>
#include <wx/ribbon/gallery.h>
#include <wx/ribbon/page.h>
#include <wx/ribbon/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>

#include "import_crafter_base.h"

#if !(__cplusplus >= 201703L || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L))
    #error "A C++17 or later compatible compiler is required."
#endif

#include <wx/mstream.h>  // Memory stream classes

// Convert a data array into a wxImage
inline wxImage GetImageFromArray(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

#include <wx/animate.h>

// Convert a data array into a wxAnimation
inline wxAnimation GetAnimFromHdr(const unsigned char* data, size_t size_data)
{
    wxMemoryInputStream strm(data, size_data);
    wxAnimation animation;
    animation.Load(strm);
    return animation;
};

bool ImportCrafterBase::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxPanel::Create(parent, id, pos, size, style, name))
        return false;

    if (!wxImage::FindHandler(wxBITMAP_TYPE_GIF))
        wxImage::AddHandler(new wxGIFHandler);
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_auinotebook1 = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TOP|wxAUI_NB_TAB_SPLIT|wxAUI_NB_TAB_MOVE|wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_CLOSE_ON_ACTIVE_TAB|wxAUI_NB_MIDDLE_CLICK_CLOSE);
    parent_sizer->Add(m_auinotebook1, wxSizerFlags(1).Expand().Border(wxALL));

    auto m_panel1 = new wxPanel(m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_auinotebook1->AddPage(m_panel1, _("Common"));

    auto parent_sizer1 = new wxGridBagSizer();

    m_infoCtrl1 = new wxInfoBar(m_panel1);
    m_infoCtrl1->SetShowHideEffects(wxSHOW_EFFECT_NONE, wxSHOW_EFFECT_NONE);
    parent_sizer1->Add(m_infoCtrl1, wxGBPosition(0, 0), wxGBSpan(1, 3), wxALL|wxEXPAND, 5);

    wxString radioBox1_choices[] = {
        _("First"),
        _("Second"),
        _("Third"),
    };
    m_radioBox1 = new wxRadioBox(m_panel1, wxID_ANY, _("wxRadioBox"),
        wxDefaultPosition, wxDefaultSize, 3, radioBox1_choices, 1);
    m_radioBox1->SetSelection(1);
    parent_sizer1->Add(m_radioBox1, wxGBPosition(1, 0), wxGBSpan(1, 1), wxALL, 5);

    m_collPane4 = new wxCollapsiblePane(m_panel1, wxID_ANY, _("collapsible"));
    m_collPane4->Collapse();
    parent_sizer1->Add(m_collPane4, wxGBPosition(1, 1), wxGBSpan(1, 1), wxALL, 5);

    auto boxSizer8 = new wxBoxSizer(wxVERTICAL);

    m_staticText10 = new wxStaticText(m_collPane4->GetPane(), wxID_ANY, _(wxString::FromUTF8("これは日本語の文章です。")));
    boxSizer8->Add(m_staticText10, wxSizerFlags().Border(wxALL));

    auto m_bitmap2 = new wxStaticBitmap(m_collPane4->GetPane(), wxID_ANY, wxBitmap(wxArtProvider::GetBitmap(wxART_GO_UP, wxART_BUTTON)));
    boxSizer8->Add(m_bitmap2, wxSizerFlags().Border(wxALL));

    m_collPane4->GetPane()->SetSizerAndFit(boxSizer8);

    m_textCtrlWithValidator = new wxTextCtrl(m_panel1, wxID_ANY, _("initial"));
    parent_sizer1->Add(m_textCtrlWithValidator, wxGBPosition(1, 2), wxGBSpan(1, 1), wxALL, 5);

    m_choice1 = new wxChoice(m_panel1, wxID_ANY);
    m_choice1->Append(_("First"));
    m_choice1->Append(_("Second"));
    m_choice1->Append(_("Third"));
    m_choice1->SetSelection(1);
    parent_sizer1->Add(m_choice1, wxGBPosition(2, 0), wxGBSpan(1, 1), wxALL, 5);

    auto m_bitmap21 = new wxStaticBitmap(m_panel1, wxID_ANY, wxBitmap(GetImageFromArray(wxue_img::french_png, sizeof(wxue_img::french_png))));
    parent_sizer1->Add(m_bitmap21, wxGBPosition(2, 1), wxGBSpan(1, 1), wxALL, 5);

    m_slider1 = new wxSlider(m_panel1, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS);
    m_slider1->SetValue(50);
    parent_sizer1->Add(m_slider1, wxGBPosition(2, 2), wxGBSpan(1, 1), wxALL, 5);

    m_panel1->SetSizerAndFit(parent_sizer1);

    auto m_panel12 = new wxPanel(m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_auinotebook1->AddPage(m_panel12, _("Data"));

    auto fgSizer1 = new wxFlexGridSizer(1, 0, 0);

    auto bSizer6 = new wxBoxSizer(wxHORIZONTAL);
    fgSizer1->Add(bSizer6, wxSizerFlags(1).Expand().Border(wxALL));

    m_propertyGridManager1 = new wxPropertyGridManager(m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxPG_AUTO_SORT);
    m_propertyGridManager1->SetExtraStyle(wxPG_EX_MODE_BUTTONS);
    bSizer6->Add(m_propertyGridManager1, wxSizerFlags().Border(wxALL));

    m_propertyGridPage = m_propertyGridManager1->AddPage(wxEmptyString, wxNullBitmap);

    m_propertyGridItem1 = m_propertyGridPage->Append(new wxStringProperty(_("String"), _("String property item")));

    m_propertyGridItem2 = m_propertyGridPage->Append(new wxStringProperty(_("Edit Enum"), wxEmptyString));

    m_grid1 = new wxGrid(m_panel12, wxID_ANY);
    {
        m_grid1->CreateGrid(3, 3);
        m_grid1->EnableDragGridSize(false);
        m_grid1->SetMargins(0, 0);

        m_grid1->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
        m_grid1->SetColLabelSize(-1);
        m_grid1->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

        m_grid1->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
    }
    bSizer6->Add(m_grid1, wxSizerFlags().Border(wxALL));

    m_ribbonBar1 = new wxRibbonBar(m_panel12, wxID_ANY);
    m_ribbonBar1->SetArtProvider(new wxRibbonDefaultArtProvider);
    fgSizer1->Add(m_ribbonBar1, wxSizerFlags().Border(wxALL));

    auto m_ribbonPage1 = new wxRibbonPage(m_ribbonBar1, wxID_ANY, _("MyRibbonPage"));

    auto m_ribbonPanel1 = new wxRibbonPanel(m_ribbonPage1, wxID_ANY, _("Toolbar"));

    auto m_ribbonToolBar1 = new wxRibbonToolBar(m_ribbonPanel1, wxID_ANY);
    {
        m_ribbonToolBar1->AddTool(wxID_ANY, GetImageFromArray(wxue_img::undo_png, sizeof(wxue_img::undo_png)), _("Help String"), wxRIBBON_BUTTON_NORMAL);
        m_ribbonToolBar1->AddTool(wxID_ANY, GetImageFromArray(wxue_img::redo_png, sizeof(wxue_img::redo_png)), _("Help String"), wxRIBBON_BUTTON_DROPDOWN);
        m_ribbonToolBar1->AddTool(wxID_ANY, GetImageFromArray(wxue_img::toggle_button_png, sizeof(wxue_img::toggle_button_png)), _("Help String"), wxRIBBON_BUTTON_TOGGLE);
        m_ribbonToolBar1->AddTool(wxID_ANY, GetImageFromArray(wxue_img::ribbon_button_hybrid_png, sizeof(wxue_img::ribbon_button_hybrid_png)), _("Help String"), wxRIBBON_BUTTON_HYBRID);
    }
    m_ribbonToolBar1->Realize();

    auto m_ribbonPanel2 = new wxRibbonPanel(m_ribbonPage1, wxID_ANY, _("RibbonButton"));

    auto m_ribbonButtonBar1 = new wxRibbonButtonBar(m_ribbonPanel2, wxID_ANY);

    m_ribbonButtonBar1->AddButton(wxID_ANY, _("Undo"), GetImageFromArray(wxue_img::undo_png, sizeof(wxue_img::undo_png)), _("Help String"), wxRIBBON_BUTTON_NORMAL);

    m_ribbonButtonBar1->AddButton(wxID_ANY, _("Drop"), GetImageFromArray(wxue_img::redo_png, sizeof(wxue_img::redo_png)), _("Help String"), wxRIBBON_BUTTON_DROPDOWN);

    m_ribbonButtonBar1->AddButton(wxID_ANY, _("Toggle"), GetImageFromArray(wxue_img::toggle_button_png, sizeof(wxue_img::toggle_button_png)), _("Help String"), wxRIBBON_BUTTON_TOGGLE);

    m_ribbonButtonBar1->AddButton(wxID_ANY, _("Hybrid"), GetImageFromArray(wxue_img::ribbon_button_hybrid_png, sizeof(wxue_img::ribbon_button_hybrid_png)), _("Help String"), wxRIBBON_BUTTON_HYBRID);

    auto m_ribbonPanel3 = new wxRibbonPanel(m_ribbonPage1, wxID_ANY, _("Gallery"));

    auto m_ribbonGallery62 = new wxRibbonGallery(m_ribbonPanel3, wxID_ANY);

    m_ribbonGallery62->Append(GetImageFromArray(wxue_img::undo_png, sizeof(wxue_img::undo_png)), wxID_ANY);

    m_ribbonGallery62->Append(GetImageFromArray(wxue_img::redo_png, sizeof(wxue_img::redo_png)), wxID_ANY);
    m_ribbonBar1->Realize();

    m_panel12->SetSizerAndFit(fgSizer1);

    auto m_panel3 = new wxPanel(m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    m_auinotebook1->AddPage(m_panel3, _("Additional"));

    auto bSizer3 = new wxBoxSizer(wxVERTICAL);

    auto bSizer4 = new wxBoxSizer(wxHORIZONTAL);
    bSizer3->Add(bSizer4, wxSizerFlags().Border(wxALL));

    m_toggleBtn1 = new wxToggleButton(m_panel3, wxID_ANY, _("MyButton"));
    bSizer4->Add(m_toggleBtn1, wxSizerFlags().Border(wxALL));

    m_searchCtrl1 = new wxSearchCtrl(m_panel3, wxID_ANY);
    m_searchCtrl1->ShowSearchButton(true);
    bSizer4->Add(m_searchCtrl1, wxSizerFlags().Border(wxALL));

    m_colourPicker1 = new wxColourPickerCtrl(m_panel3, wxID_ANY, wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    bSizer4->Add(m_colourPicker1, wxSizerFlags().Border(wxALL));

    auto bSizer5 = new wxBoxSizer(wxHORIZONTAL);
    bSizer3->Add(bSizer5, wxSizerFlags().Border(wxALL));

    m_spinCtrl1 = new wxSpinCtrl(m_panel3, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 5);
    bSizer5->Add(m_spinCtrl1, wxSizerFlags().Border(wxALL));

    m_hyperlink1 = new wxHyperlinkCtrl(m_panel3, wxID_ANY, _("wxFB Website"), _("http://www.wxformbuilder.org"), wxDefaultPosition, wxDefaultSize,
        wxHL_DEFAULT_STYLE);
    {
        wxFontInfo font_info(9);
        font_info.FaceName(_("Arial"));
        m_hyperlink1->SetFont(wxFont(font_info));
    }
    bSizer5->Add(m_hyperlink1, wxSizerFlags().Border(wxALL));

    bSizer5->AddStretchSpacer(1);

    m_animCtrl1 = new wxAnimationCtrl(m_panel3, wxID_ANY, GetAnimFromHdr(wxue_img::clr_hourglass_gif, sizeof(wxue_img::clr_hourglass_gif)));
    m_animCtrl1->Play();
    bSizer5->Add(m_animCtrl1, wxSizerFlags().Border(wxALL));

    auto sbSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, m_panel3, _("Static Box"));
    bSizer3->Add(sbSizer1, wxSizerFlags(1).Expand().Border(wxALL));

    m_richText1 = new wxRichTextCtrl(sbSizer1->GetStaticBox(), wxID_ANY, _("wxRichTextCtrl!"), wxDefaultPosition, wxDefaultSize, wxRE_MULTILINE|wxWANTS_CHARS|wxBORDER_NONE|wxHSCROLL|wxVSCROLL);
    m_richText1->SetMinSize(ConvertPixelsToDialog(wxSize(200, 100)));
    sbSizer1->Add(m_richText1, wxSizerFlags(1).Expand().Border(wxALL));

    m_panel3->SetSizerAndFit(bSizer3);

    SetSizerAndFit(parent_sizer);
    SetSize(wxSize(500, 300));

    return true;
}

namespace wxue_img
{

    inline const unsigned char clr_hourglass_gif[2017] {
    71,73,70,56,57,97,32,0,32,0,242,0,0,255,255,255,204,204,204,0,255,255,0,153,153,0,0,0,0,0,0,0,0,0,0,0,0,33,255,11,78,69,84,83,67,65,
    80,69,50,46,48,3,1,0,0,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,102,88,186,220,254,48,202,73,171,189,56,231,193,187,231,132,86,
    112,66,41,124,67,40,18,108,235,170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,134,7,32,4,140,72,209,2,121,108,10,53,204,164,178,
    17,157,62,164,214,6,47,171,157,61,99,1,224,145,251,171,89,203,193,41,218,172,92,123,213,97,241,91,137,242,124,41,36,19,234,46,121,249,
    89,92,129,130,131,132,133,18,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,103,88,186,220,254,48,202,73,171,189,56,231,193,187,231,
    132,86,112,66,41,124,67,40,18,108,235,170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,134,7,32,204,140,66,12,50,176,76,102,154,
    76,209,163,41,133,32,171,16,30,214,81,219,46,112,198,232,246,215,173,146,131,230,64,110,39,142,169,129,101,247,26,45,69,121,156,20,146,
    9,133,151,188,254,44,94,130,131,132,133,134,18,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,106,88,186,220,254,48,202,73,171,189,
    56,231,193,187,231,132,86,112,66,41,124,67,40,18,108,235,170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,134,7,228,5,132,24,194,
    113,169,68,102,154,76,209,3,234,148,54,165,17,30,246,81,219,50,112,202,163,183,240,235,98,203,97,173,180,28,60,7,114,59,241,250,93,156,
    85,41,40,207,93,66,50,161,246,16,47,130,44,99,133,134,135,136,137,18,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,105,88,186,220,
    254,48,202,73,171,189,56,231,193,187,231,132,86,112,66,41,124,67,40,18,108,235,170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,
    134,7,172,137,22,132,64,114,169,60,50,152,75,103,3,42,117,68,171,13,30,150,97,220,226,146,205,234,175,123,28,131,181,229,64,110,23,142,
    169,117,231,246,237,205,22,94,80,30,123,133,100,66,233,39,47,129,44,91,132,133,134,135,136,12,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,
    0,32,0,0,3,105,88,186,220,254,48,202,73,171,189,56,231,193,187,231,132,86,112,66,41,124,67,40,18,108,235,170,98,32,207,52,172,201,0,
    64,203,118,134,235,187,30,230,183,11,8,49,4,163,50,121,204,48,151,162,199,179,25,101,70,35,188,235,163,166,101,224,146,198,110,129,56,
    163,86,136,224,108,148,204,93,7,114,202,242,245,151,86,139,80,30,179,132,100,66,233,33,47,129,44,98,132,133,134,135,136,18,9,0,33,249,
    4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,104,88,186,220,254,48,202,73,171,189,56,231,193,187,231,132,86,112,66,41,124,67,40,18,108,235,
    170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,230,183,11,8,49,4,227,44,121,204,48,149,77,205,51,186,50,138,36,188,43,164,166,
    109,224,146,214,110,129,184,236,18,193,217,43,153,171,14,228,148,229,118,238,153,22,161,60,84,9,201,132,202,67,94,128,44,98,131,132,
    133,134,135,24,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,105,88,186,220,254,48,202,73,171,189,56,231,193,187,231,132,86,112,66,
    41,124,67,40,18,108,235,170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,230,183,11,8,49,4,99,80,212,72,58,141,76,199,243,24,117,
    70,33,188,171,163,166,93,224,146,80,45,113,70,181,16,193,89,230,152,171,14,228,148,228,40,15,240,76,139,80,158,242,132,100,66,233,35,
    47,129,44,93,132,133,134,135,136,18,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,105,88,186,220,254,48,202,73,171,189,56,231,193,
    187,231,132,86,112,66,41,124,67,40,18,108,235,170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,230,183,11,8,49,132,162,81,212,72,
    58,151,204,166,17,26,149,30,171,188,170,163,166,93,224,146,212,40,113,118,181,16,193,89,230,152,171,14,228,166,100,177,17,240,116,70,
    81,158,242,132,100,66,233,35,47,129,44,93,132,133,134,135,136,18,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,108,88,186,220,254,
    48,202,73,171,189,56,231,193,187,231,132,86,112,66,41,124,67,40,18,108,235,170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,230,
    183,11,8,49,132,162,81,212,72,38,121,76,135,115,25,149,82,171,13,40,150,81,219,42,112,207,163,47,144,235,70,137,79,109,140,12,52,175,
    1,211,153,184,194,131,27,239,115,10,202,147,151,144,76,40,125,16,47,132,44,94,135,136,137,138,139,12,9,0,33,249,4,9,10,0,5,0,44,0,0,
    0,0,32,0,32,0,0,3,106,88,186,220,254,48,202,73,171,189,56,231,193,187,231,132,86,112,66,41,124,67,40,18,108,235,170,98,32,207,52,172,
    201,0,64,203,118,134,235,187,30,230,183,11,8,49,132,162,81,212,72,214,152,142,164,20,250,152,82,29,188,107,227,169,45,224,156,71,95,
    32,199,101,18,157,89,243,24,88,190,141,165,198,116,204,8,128,91,69,40,79,152,66,50,161,246,18,47,130,44,93,133,134,135,136,137,12,9,
    0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,108,88,186,220,254,48,202,73,171,189,56,231,193,187,231,132,86,112,66,41,124,67,40,18,
    108,235,170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,230,183,11,8,49,132,162,81,212,72,214,152,14,231,18,26,157,82,27,188,43,
    118,118,140,5,0,206,238,240,11,204,66,137,82,235,141,156,86,251,190,201,184,217,75,0,27,239,98,10,202,147,151,144,76,40,125,16,47,132,
    44,90,135,136,137,138,139,18,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,107,88,186,220,254,48,202,73,171,189,56,231,193,187,231,
    132,86,112,66,41,124,67,40,18,108,235,170,98,32,207,52,172,201,0,64,203,118,134,235,187,30,230,183,11,8,49,132,162,81,212,72,214,152,
    14,231,18,26,157,82,27,188,43,118,118,140,5,128,86,40,145,75,37,74,195,190,47,32,41,237,86,112,108,99,150,201,91,203,217,80,148,199,
    61,33,153,80,124,17,47,131,44,90,134,135,136,137,138,18,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,103,88,186,220,254,48,202,73,
    171,189,56,235,55,200,158,67,247,69,131,32,142,77,16,148,39,90,168,0,192,122,40,12,168,97,187,5,177,138,135,180,221,205,247,211,97,120,
    68,31,97,249,65,38,131,151,228,144,8,181,216,122,129,165,86,99,163,126,128,89,0,193,187,153,137,179,202,209,12,61,102,170,77,109,182,
    43,23,175,126,193,118,53,208,229,216,243,27,110,127,130,131,132,133,134,19,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,115,88,186,
    220,254,48,202,73,171,189,56,235,205,187,255,217,48,104,3,33,137,68,160,6,208,26,160,167,144,174,102,227,190,114,156,2,124,80,43,42,
    30,111,144,139,16,119,61,31,48,32,28,22,33,71,102,210,23,4,184,142,167,210,109,123,131,25,181,169,176,111,214,45,101,9,226,176,130,188,
    242,66,193,212,95,129,253,50,127,209,113,7,219,253,64,161,209,16,127,104,118,129,114,22,128,32,137,138,139,140,141,142,143,144,145,146,
    13,9,0,33,249,4,9,10,0,5,0,44,0,0,0,0,32,0,32,0,0,3,109,88,186,220,254,48,202,73,171,189,56,235,66,200,150,196,224,125,79,40,146,142,
    57,4,35,202,13,112,32,183,95,40,172,242,76,218,120,206,214,131,155,143,245,219,192,86,0,0,129,216,113,205,148,76,87,225,73,128,250,104,
    152,142,22,48,44,162,2,220,33,86,3,238,178,154,155,178,24,54,182,128,195,179,35,73,150,140,195,156,111,149,116,202,10,14,246,10,60,128,
    10,126,131,132,127,134,137,138,139,140,36,9,0,33,254,50,82,101,100,117,99,101,100,32,53,54,37,32,64,32,119,119,119,46,114,97,115,112,
    98,101,114,114,121,104,105,108,108,46,99,111,109,47,103,105,102,119,105,122,97,114,100,46,104,116,109,108,0,59
    };

    inline const unsigned char french_png[252] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,19,0,0,0,15,8,2,0,0,0,137,38,99,123,0,0,0,3,115,66,73,84,8,8,8,219,225,79,224,0,
    0,0,9,112,72,89,115,0,0,10,240,0,0,10,240,1,66,172,52,152,0,0,0,159,73,68,65,84,40,207,99,252,252,249,235,239,63,255,254,253,251,207,
    0,3,108,108,204,44,204,140,12,72,224,255,159,223,255,127,255,128,115,25,153,152,25,89,88,89,222,190,251,113,231,254,231,175,223,126,
    51,252,103,96,96,100,96,96,96,208,213,18,18,21,102,135,155,196,200,192,240,247,237,243,95,215,142,48,48,48,48,252,255,207,192,200,200,
    204,205,199,170,168,207,114,255,225,151,101,171,238,62,127,249,13,110,100,126,166,22,63,191,8,178,157,63,239,94,252,60,175,28,206,101,
    17,87,16,136,168,102,98,32,23,140,234,28,213,9,77,149,15,30,190,37,156,110,223,60,193,76,183,140,100,231,21,0,198,75,81,253,220,87,197,
    4,0,0,0,0,73,69,78,68,174,66,96,130
    };

    inline const unsigned char redo_png[945] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,6,0,0,0,224,119,61,248,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,
    0,154,156,24,0,0,3,99,73,68,65,84,72,199,237,149,77,104,29,85,20,199,127,231,220,59,243,222,228,131,180,133,8,45,85,108,77,65,168,144,
    38,187,34,180,10,133,110,252,64,161,32,4,4,23,74,69,16,169,139,108,68,138,82,234,66,65,44,72,69,44,110,42,136,238,196,101,17,65,209,
    69,177,80,132,208,214,36,181,49,145,166,173,137,53,239,189,204,155,185,247,184,152,215,215,164,77,172,214,149,224,133,203,12,195,153,
    255,239,158,207,11,255,245,37,119,50,248,228,212,101,147,86,132,104,32,213,15,34,130,56,65,122,28,7,246,14,202,93,1,222,253,252,146,
    249,166,117,4,59,162,194,138,45,221,103,236,129,231,31,219,42,127,27,240,230,137,139,22,151,74,84,111,21,94,241,126,3,76,245,205,245,
    121,94,121,230,94,185,35,224,208,251,147,102,11,237,74,172,3,80,1,81,233,10,155,5,156,250,155,33,235,108,221,224,57,252,220,54,89,23,
    48,246,246,25,75,175,38,136,130,58,233,66,244,22,47,54,111,106,145,38,142,153,249,20,204,186,0,12,154,3,109,62,124,121,184,171,235,87,
    2,102,46,64,190,216,192,84,112,78,240,137,146,36,66,45,85,234,53,71,86,83,188,19,182,248,132,151,198,134,120,231,227,115,76,205,121,
    48,16,51,48,72,92,125,237,16,13,31,157,182,75,95,252,92,85,135,19,196,105,21,34,21,232,132,7,132,212,11,251,70,61,31,189,62,74,179,149,
    243,198,241,9,126,154,245,168,0,17,136,198,181,190,200,87,71,70,100,149,7,205,185,6,154,58,212,11,226,21,113,66,226,35,7,246,102,60,
    181,103,144,109,91,234,56,173,108,211,36,193,204,200,234,41,175,189,240,32,79,190,250,3,83,115,74,79,170,244,166,74,127,95,194,154,33,
    114,117,69,189,34,94,241,222,120,239,197,65,246,239,222,74,136,145,197,235,77,66,168,236,74,13,228,121,14,64,81,22,104,170,44,155,208,
    106,4,174,44,22,12,108,204,214,1,212,28,154,40,154,40,143,238,140,60,50,122,15,167,39,46,51,126,114,158,249,70,218,181,219,125,127,224,
    216,193,33,90,121,155,67,31,92,228,252,213,20,95,143,196,66,170,106,243,178,158,7,30,77,43,192,232,14,37,111,231,28,63,245,27,215,232,
    199,247,221,168,81,32,93,102,241,250,18,227,39,127,229,244,108,29,151,69,196,71,196,5,80,193,165,235,2,28,174,166,85,46,92,160,40,10,
    114,81,146,222,164,74,182,128,153,209,10,37,227,159,205,115,118,177,31,223,27,137,237,72,104,7,68,171,238,171,37,173,181,1,62,115,104,
    234,112,117,199,212,66,155,162,93,176,119,200,152,60,239,145,78,134,205,140,201,176,137,88,72,87,60,250,128,56,33,136,128,4,206,190,
    53,114,123,31,92,56,246,144,12,31,157,182,246,239,109,92,230,248,238,74,198,211,87,151,216,191,179,159,193,190,5,102,27,238,230,73,204,
    48,131,111,127,17,166,150,250,9,90,9,3,244,108,201,86,245,193,42,15,6,182,167,44,156,139,184,154,163,172,215,56,114,166,201,216,246,
    63,216,181,185,206,46,239,110,155,89,51,205,156,25,171,194,39,174,58,244,143,135,119,200,95,206,162,135,79,76,219,114,195,227,51,223,
    201,137,35,141,13,122,92,168,102,133,25,177,52,98,25,105,20,9,203,69,66,104,5,202,102,73,182,49,242,253,193,7,228,142,211,116,207,167,
    179,22,66,138,203,60,46,115,184,78,3,162,130,69,195,138,72,200,35,33,15,148,141,130,178,89,146,214,75,190,121,246,62,249,71,23,206,190,
    83,75,166,181,42,233,154,40,210,1,196,60,82,46,151,148,205,146,216,142,124,253,196,6,185,235,27,13,224,241,137,104,34,178,34,199,70,
    92,14,124,57,146,8,255,175,127,187,254,4,36,215,71,244,23,26,212,231,0,0,0,0,73,69,78,68,174,66,96,130
    };

    inline const unsigned char ribbon_button_hybrid_png[192] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,
    0,154,156,24,0,0,0,114,73,68,65,84,56,203,237,147,81,10,128,32,16,68,199,232,70,227,153,244,76,219,153,244,76,246,17,6,21,153,27,236,
    135,224,252,14,251,22,222,42,48,99,29,71,134,98,1,94,1,32,37,177,1,3,128,247,241,81,214,133,191,58,50,20,139,12,236,24,0,92,204,221,
    131,69,216,236,23,171,119,108,6,190,168,96,222,20,163,210,15,206,12,77,135,154,27,188,170,184,67,52,208,79,199,21,166,133,30,94,71,251,
    121,51,103,118,153,23,204,66,178,140,4,249,0,0,0,0,73,69,78,68,174,66,96,130
    };

    inline const unsigned char toggle_button_png[277] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,22,0,0,0,22,8,6,0,0,0,196,180,108,59,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,
    0,154,156,24,0,0,0,199,73,68,65,84,56,203,99,96,24,5,163,0,29,48,158,191,249,230,191,97,212,90,170,26,122,126,89,48,3,35,131,241,204,
    255,167,119,164,81,213,96,83,143,89,12,76,12,12,12,12,127,254,99,199,166,162,140,12,166,162,140,40,124,116,121,116,61,172,76,16,195,
    89,24,24,24,24,56,153,49,109,53,16,102,100,184,240,246,63,6,219,82,12,193,198,166,23,198,199,105,48,186,56,140,125,243,195,127,6,117,
    1,70,134,155,31,254,99,53,152,139,5,201,96,24,7,29,32,139,195,216,184,104,24,32,24,20,184,92,204,201,204,192,240,230,251,127,6,17,78,
    70,172,46,102,65,54,152,3,139,139,191,252,254,207,192,195,202,8,103,195,0,76,45,76,158,3,135,111,89,24,24,24,24,216,152,176,75,254,250,
    251,159,36,62,93,50,200,40,24,5,152,0,0,191,144,85,198,46,125,47,182,0,0,0,0,73,69,78,68,174,66,96,130
    };

    inline const unsigned char undo_png[962] {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,6,0,0,0,224,119,61,248,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,
    0,154,156,24,0,0,3,116,73,68,65,84,72,199,237,149,79,104,93,69,20,198,127,103,102,222,125,247,190,247,130,182,74,132,68,107,19,83,52,
    221,212,134,46,4,197,90,186,212,165,32,216,133,80,80,193,162,20,41,84,81,161,59,21,161,148,110,44,136,10,98,65,200,66,80,151,74,105,
    65,138,110,74,138,66,149,182,233,159,24,105,83,147,180,73,243,222,189,119,102,142,139,155,164,9,73,141,214,149,224,129,97,206,101,230,
    124,223,253,206,156,57,3,255,117,147,181,54,12,31,159,80,157,11,104,80,84,21,5,80,192,8,154,25,158,223,121,159,220,17,193,71,223,140,
    169,153,163,2,213,165,51,203,191,1,223,16,246,62,187,65,254,54,193,161,47,46,107,152,245,243,0,183,128,86,128,207,251,49,130,105,57,
    222,217,189,81,214,36,56,240,233,168,198,105,95,1,206,15,20,66,244,136,216,91,68,81,137,11,100,177,154,101,93,194,193,87,30,146,219,
    18,188,120,120,68,27,215,19,144,37,224,34,60,208,93,80,148,129,223,39,179,101,127,31,151,128,199,80,249,197,189,37,71,247,109,93,196,
    117,203,216,102,83,110,204,149,21,129,8,8,244,247,120,246,236,122,152,67,159,159,101,38,143,248,160,180,243,72,39,15,228,69,164,44,21,
    95,70,66,80,36,42,245,169,100,89,70,22,9,118,188,117,74,39,175,116,192,8,24,136,10,3,189,158,215,95,24,36,75,19,206,142,119,56,54,226,
    41,124,165,77,21,136,138,198,121,21,33,86,149,118,185,205,150,119,71,117,228,205,62,89,161,224,194,149,156,155,69,100,174,136,244,247,
    68,222,126,105,136,44,77,80,85,62,120,117,128,162,44,1,8,17,70,199,59,124,121,98,130,225,227,109,74,111,208,96,80,31,137,94,153,27,191,
    185,82,193,165,73,199,245,171,179,152,154,65,156,193,36,134,210,151,228,121,181,238,67,32,4,93,60,185,173,143,172,99,219,230,123,120,
    114,203,24,175,125,56,137,247,6,245,130,248,184,122,138,196,9,182,110,49,53,131,169,25,126,189,102,216,115,248,23,14,190,188,145,172,
    158,176,239,227,81,78,94,176,139,129,221,205,130,247,119,117,243,212,80,55,59,30,157,230,216,207,134,88,10,82,46,47,76,179,224,216,68,
    48,117,139,77,45,54,115,216,204,241,227,111,41,123,63,185,200,244,141,89,72,44,174,149,226,186,82,92,43,229,15,186,56,242,221,36,121,
    145,51,180,41,93,140,177,169,91,93,65,189,214,198,214,45,182,110,42,162,196,98,18,195,233,233,132,253,195,87,9,49,224,90,14,145,170,
    134,53,42,185,228,148,101,137,177,138,107,56,98,17,8,230,54,10,78,191,183,77,108,106,177,169,195,101,14,215,176,184,134,195,53,28,103,
    242,187,57,23,215,83,107,213,170,209,85,163,214,114,108,31,80,202,162,228,252,84,192,53,220,124,172,93,93,1,64,87,95,139,124,178,168,
    210,84,183,216,204,210,223,154,225,241,251,21,145,234,210,45,88,111,51,48,244,96,23,99,215,102,57,57,145,225,26,14,49,66,210,211,96,
    228,141,190,213,47,218,79,7,54,201,224,254,51,106,83,135,205,44,46,115,108,88,47,60,179,57,93,209,175,74,31,248,225,226,12,71,207,55,
    241,205,6,206,6,196,8,119,245,37,127,221,139,30,59,114,78,219,83,166,146,156,89,210,90,73,179,86,98,156,193,56,169,84,168,50,23,44,133,
    105,18,242,64,232,4,124,219,147,54,61,223,239,238,147,53,187,233,19,159,93,210,162,83,229,223,53,107,139,135,47,53,131,24,129,168,68,
    175,132,34,16,218,129,208,246,88,91,112,226,185,94,249,71,15,206,246,175,166,213,38,6,219,112,184,212,97,234,21,129,70,37,150,145,208,
    9,196,60,240,237,206,150,220,241,139,6,240,244,169,82,197,25,196,73,85,166,84,29,244,235,65,35,252,111,255,214,254,4,190,176,184,85,
    156,35,97,16,0,0,0,0,73,69,78,68,174,66,96,130
    };

}
