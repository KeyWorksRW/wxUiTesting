///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/artprov.h>
#include <wx/ribbon/buttonbar.h>
#include <wx/ribbon/page.h>
#include <wx/ribbon/panel.h>
#include <wx/sizer.h>

#include "images.h"

#include "tools_dlg.h"

#include <wx/bmpbndl.h>  // wxBitmapBundle class
#include <wx/mstream.h>  // memory stream classes
#include <wx/zstream.h>  // zlib stream classes

#include <memory>  // for std::make_unique

// Convert a data array into a wxImage
#ifdef __cpp_inline_variables
inline wxImage wxueImage(const unsigned char* data, size_t size_data)
#else
static wxImage wxueImage(const unsigned char* data, size_t size_data)
#endif
{
    wxMemoryInputStream strm(data, size_data);
    wxImage image;
    image.LoadFile(strm);
    return image;
};

// Convert compressed SVG string into a wxBitmapBundle
#ifdef __cpp_inline_variables
inline wxBitmapBundle wxueBundleSVG(const unsigned char* data,
    size_t size_data, size_t size_svg, wxSize def_size)
#else
static wxBitmapBundle wxueBundleSVG(const unsigned char* data,
    size_t size_data, size_t size_svg, wxSize def_size)
#endif
{
    auto str = std::make_unique<char[]>(size_svg);
    wxMemoryInputStream stream_in(data, size_data);
    wxZlibInputStream zlib_strm(stream_in);
    zlib_strm.Read(str.get(), size_svg);
    return wxBitmapBundle::FromSVG(str.get(), def_size);
};

namespace wxue_img
{
    extern const unsigned char left_svg[630];  // ../art/left.svg
    extern const unsigned char redo_png[945];  // ../art/redo.png
    extern const unsigned char undo_png[962];  // ../art/undo.png
}

bool ToolBarsDialog::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
    {
        return false;
    }
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    m_tool_bar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL);
    m_tool_svg = m_tool_bar->AddTool(wxID_ANY, wxEmptyString,
        wxueBundleSVG(wxue_img::left_svg, 630, 1927, wxSize(24, 24)));

    m_tool_bar->AddTool(wxID_ANY, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_CUT, wxART_TOOLBAR));

    m_tool_bar->AddTool(wxID_ANY, wxEmptyString,
        wxueImage(wxue_img::undo_png, sizeof(wxue_img::undo_png)));

    m_tool_bar->AddTool(wxID_ANY, wxEmptyString,
        wxueImage(wxue_img::redo_png, sizeof(wxue_img::redo_png)));

    m_tool_bar->AddTool(wxID_ANY, wxEmptyString, wxue_img::bundle_wxPython_png());

    m_tool_bar->AddTool(wxID_ANY, wxEmptyString, wxue_img::bundle_fontPicker_png());

    m_tool_bar->Realize();
    box_sizer->Add(m_tool_bar, wxSizerFlags().Border(wxALL));

    m_aui_tool_bar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxAUI_TB_PLAIN_BACKGROUND);
    m_aui_tool_svg = m_aui_tool_bar->AddTool(wxID_ANY, wxEmptyString,
        wxueBundleSVG(wxue_img::left_svg, 630, 1927, wxSize(24, 24)));
    m_aui_tool_bar->AddTool(wxID_ANY, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_CUT, wxART_TOOLBAR));
    m_aui_tool_bar->AddTool(wxID_ANY, wxEmptyString,
        wxueImage(wxue_img::redo_png, sizeof(wxue_img::redo_png)));
    m_aui_tool_bar->AddTool(wxID_ANY, wxEmptyString, wxue_img::bundle_wxPython_png());
    m_aui_tool_bar->AddTool(wxID_ANY, wxEmptyString, wxue_img::bundle_fontPicker_png());
    m_aui_tool_bar->Realize();
    box_sizer->Add(m_aui_tool_bar, wxSizerFlags().Border(wxALL));

    m_rbnBar = new wxRibbonBar(this, wxID_ANY);

    m_rbnBar->SetArtProvider(new wxRibbonDefaultArtProvider);
    box_sizer->Add(m_rbnBar, wxSizerFlags().Border(wxALL));

    auto* rbnPage = new wxRibbonPage(m_rbnBar, wxID_ANY, "Page 1");

    auto* rbnPanel = new wxRibbonPanel(rbnPage, wxID_ANY, "Tool Panel");

    auto* rbnToolBar = new wxRibbonToolBar(rbnPanel, wxID_ANY);
    {
        rbnToolBar->AddTool(rbn_tool_svg,
            wxueBundleSVG(wxue_img::left_svg, 630, 1927, FromDIP(wxSize(24, 24))).GetBitmap(wxDefaultSize), wxEmptyString,
            wxRIBBON_BUTTON_NORMAL);
        rbnToolBar->AddTool(rbn_tool_art, wxArtProvider::GetBitmap(wxART_CUT, wxART_TOOLBAR), wxEmptyString,
            wxRIBBON_BUTTON_NORMAL);
        rbnToolBar->AddTool(rbn_tool1,
            wxueImage(wxue_img::undo_png, sizeof(wxue_img::undo_png)).Rescale(
            FromDIP(24), FromDIP(24), wxIMAGE_QUALITY_BILINEAR), wxEmptyString, wxRIBBON_BUTTON_NORMAL);
        rbnToolBar->AddTool(rbn_tool2,
            wxueImage(wxue_img::redo_png, sizeof(wxue_img::redo_png)).Rescale(
            FromDIP(24), FromDIP(24), wxIMAGE_QUALITY_BILINEAR), wxEmptyString, wxRIBBON_BUTTON_NORMAL);
        rbnToolBar->AddTool(rbn_tool3, wxue_img::bundle_wxPython_png().GetBitmap(wxDefaultSize), wxEmptyString,
            wxRIBBON_BUTTON_NORMAL);
        rbnToolBar->AddTool(rbn_tool_list, wxue_img::bundle_fontPicker_png().GetBitmap(wxDefaultSize), wxEmptyString,
            wxRIBBON_BUTTON_NORMAL);
    }
    rbnToolBar->Realize();

    auto* rbn_panel2 = new wxRibbonPanel(rbnPage, wxID_ANY, "Button Panel");

    auto* rbn_btn_bar = new wxRibbonButtonBar(rbn_panel2, wxID_ANY);
    {
        rbn_btn_bar->AddButton(wxID_ANY, "rbn_btn_svg",
            wxueBundleSVG(wxue_img::left_svg, 630, 1927, FromDIP(wxSize(24, 24))).GetBitmap(wxDefaultSize), wxEmptyString,
            wxRIBBON_BUTTON_NORMAL);
        rbn_btn_bar->AddButton(wxID_ANY, "rbn_btn_art", wxArtProvider::GetBitmap(wxART_CUT, wxART_TOOLBAR), wxEmptyString,
            wxRIBBON_BUTTON_NORMAL);
        rbn_btn_bar->AddButton(wxID_ANY, "rbn_btn1",
            wxueImage(wxue_img::undo_png, sizeof(wxue_img::undo_png)).Rescale(
            FromDIP(24), FromDIP(24), wxIMAGE_QUALITY_BILINEAR), wxEmptyString, wxRIBBON_BUTTON_NORMAL);
    }
    rbn_btn_bar->Realize();

    SetMinSize(FromDIP(wxSize(400, -1)));
    if (pos != wxDefaultPosition)
    {
        SetPosition(FromDIP(pos));
    }
    if (size == wxDefaultSize)
    {
        SetSizerAndFit(box_sizer);
    }
    else
    {
        SetSizer(box_sizer);
        if (size.x == wxDefaultCoord || size.y == wxDefaultCoord)
        {
            Fit();
        }
        SetSize(FromDIP(size));
        Layout();
    }
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &ToolBarsDialog::OnInit, this);
    Bind(wxEVT_TOOL, &ToolBarsDialog::OnTool, this, m_tool_svg->GetId());

    return true;
}

namespace wxue_img
{
    // ../art/left.svg
    const unsigned char left_svg[630] {
        120,218,133,149,75,115,155,48,16,199,251,81,52,234,165,157,177,21,173,36,36,112,140,15,61,181,135,94,123,200,141,
        132,231,4,27,15,80,39,238,167,239,10,145,152,135,177,229,199,0,187,250,233,191,218,93,177,109,78,25,57,37,117,83,
        84,135,144,2,3,74,138,56,164,248,20,52,215,148,188,21,113,155,135,84,10,74,242,164,200,242,214,93,159,138,228,237,
        71,245,30,82,78,56,145,2,191,116,183,141,147,180,233,102,219,11,208,192,233,195,110,155,145,226,240,218,188,68,
        199,100,147,213,213,223,227,190,138,147,144,150,209,57,169,233,197,84,70,207,73,25,210,95,251,40,75,156,2,92,31,
        44,52,235,239,164,47,37,37,109,29,29,154,180,170,247,33,221,71,109,93,188,127,3,198,13,40,225,235,21,199,15,222,
        5,198,211,176,90,99,40,248,212,51,221,101,32,180,47,2,249,29,121,199,168,205,73,211,158,75,84,17,23,205,17,149,
        108,138,67,89,28,146,199,180,40,203,205,87,142,35,77,31,155,182,174,94,147,117,23,255,6,24,46,47,112,125,148,242,
        155,136,149,240,153,150,56,20,249,67,132,97,66,227,48,228,39,145,76,6,221,32,138,249,214,246,233,39,249,200,44,
        200,19,217,163,147,176,171,113,88,241,9,200,48,77,2,198,157,117,14,178,102,253,49,185,71,129,67,35,234,68,48,100,
        233,80,57,1,166,186,223,4,146,91,39,229,254,254,57,45,51,21,160,89,191,4,152,57,97,100,87,168,232,105,1,35,184,
        147,10,68,0,186,205,48,23,59,248,184,109,139,24,197,84,143,241,174,237,238,192,46,151,33,56,199,57,73,126,5,241,
        105,181,115,58,8,95,173,113,111,173,171,100,176,68,81,204,115,20,84,22,220,225,0,230,117,137,195,153,234,57,128,
        17,222,225,40,22,44,112,48,47,210,113,48,111,230,22,231,163,190,128,51,127,9,38,152,232,104,4,36,102,111,25,198,
        187,250,179,249,213,204,88,152,246,231,52,159,65,47,45,96,94,95,60,87,144,182,201,144,40,221,194,184,51,172,3,94,
        109,178,139,159,135,69,122,183,203,6,164,105,151,77,73,183,219,108,200,26,182,217,152,178,216,103,3,29,179,62,155,
        10,185,213,104,3,206,172,209,166,156,91,157,54,228,76,59,109,198,89,108,181,33,101,156,249,25,99,146,115,119,236,
        219,227,25,240,64,159,191,27,226,170,109,236,11,229,238,1,158,166,22,219,221,172,171,99,244,82,180,231,13,140,207,
        115,206,184,80,190,86,151,19,29,119,88,120,125,25,160,62,87,63,182,150,4,55,194,72,131,242,21,40,79,25,229,250,
        171,119,22,102,228,52,14,67,122,96,230,113,212,73,108,195,120,200,250,31,190,106,119,95,254,3,80,50,172,151
    };
    // ../art/redo.png
    const unsigned char redo_png[945] {
        137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,6,0,0,0,224,119,61,248,0,0,0,9,112,72,89,115,
        0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,3,99,73,68,65,84,72,199,237,149,77,104,29,85,20,199,127,231,220,59,243,222,
        228,131,180,133,8,45,85,108,77,65,168,144,38,187,34,180,10,133,110,252,64,161,32,4,4,23,74,69,16,169,139,108,68,
        138,82,234,66,65,44,72,69,44,110,42,136,238,196,101,17,65,209,69,177,80,132,208,214,36,181,49,145,166,173,137,53,
        239,189,204,155,185,247,184,152,215,215,164,77,172,214,149,224,133,203,12,195,153,255,239,158,207,11,255,245,37,
        119,50,248,228,212,101,147,86,132,104,32,213,15,34,130,56,65,122,28,7,246,14,202,93,1,222,253,252,146,249,166,117,
        4,59,162,194,138,45,221,103,236,129,231,31,219,42,127,27,240,230,137,139,22,151,74,84,111,21,94,241,126,3,76,245,
        205,245,121,94,121,230,94,185,35,224,208,251,147,102,11,237,74,172,3,80,1,81,233,10,155,5,156,250,155,33,235,108,
        221,224,57,252,220,54,89,23,48,246,246,25,75,175,38,136,130,58,233,66,244,22,47,54,111,106,145,38,142,153,249,20,
        204,186,0,12,154,3,109,62,124,121,184,171,235,87,2,102,46,64,190,216,192,84,112,78,240,137,146,36,66,45,85,234,
        53,71,86,83,188,19,182,248,132,151,198,134,120,231,227,115,76,205,121,48,16,51,48,72,92,125,237,16,13,31,157,182,
        75,95,252,92,85,135,19,196,105,21,34,21,232,132,7,132,212,11,251,70,61,31,189,62,74,179,149,243,198,241,9,126,154,
        245,168,0,17,136,198,181,190,200,87,71,70,100,149,7,205,185,6,154,58,212,11,226,21,113,66,226,35,7,246,102,60,181,
        103,144,109,91,234,56,173,108,211,36,193,204,200,234,41,175,189,240,32,79,190,250,3,83,115,74,79,170,244,166,74,
        127,95,194,154,33,114,117,69,189,34,94,241,222,120,239,197,65,246,239,222,74,136,145,197,235,77,66,168,236,74,13,
        228,121,14,64,81,22,104,170,44,155,208,106,4,174,44,22,12,108,204,214,1,212,28,154,40,154,40,143,238,140,60,50,
        122,15,167,39,46,51,126,114,158,249,70,218,181,219,125,127,224,216,193,33,90,121,155,67,31,92,228,252,213,20,95,
        143,196,66,170,106,243,178,158,7,30,77,43,192,232,14,37,111,231,28,63,245,27,215,232,199,247,221,168,81,32,93,102,
        241,250,18,227,39,127,229,244,108,29,151,69,196,71,196,5,80,193,165,235,2,28,174,166,85,46,92,160,40,10,114,81,
        146,222,164,74,182,128,153,209,10,37,227,159,205,115,118,177,31,223,27,137,237,72,104,7,68,171,238,171,37,173,181,
        1,62,115,104,234,112,117,199,212,66,155,162,93,176,119,200,152,60,239,145,78,134,205,140,201,176,137,88,72,87,60,
        250,128,56,33,136,128,4,206,190,53,114,123,31,92,56,246,144,12,31,157,182,246,239,109,92,230,248,238,74,198,211,
        87,151,216,191,179,159,193,190,5,102,27,238,230,73,204,48,131,111,127,17,166,150,250,9,90,9,3,244,108,201,86,245,
        193,42,15,6,182,167,44,156,139,184,154,163,172,215,56,114,166,201,216,246,63,216,181,185,206,46,239,110,155,89,
        51,205,156,25,171,194,39,174,58,244,143,135,119,200,95,206,162,135,79,76,219,114,195,227,51,223,201,137,35,141,
        13,122,92,168,102,133,25,177,52,98,25,105,20,9,203,69,66,104,5,202,102,73,182,49,242,253,193,7,228,142,211,116,
        207,167,179,22,66,138,203,60,46,115,184,78,3,162,130,69,195,138,72,200,35,33,15,148,141,130,178,89,146,214,75,190,
        121,246,62,249,71,23,206,190,83,75,166,181,42,233,154,40,210,1,196,60,82,46,151,148,205,146,216,142,124,253,196,
        6,185,235,27,13,224,241,137,104,34,178,34,199,70,92,14,124,57,146,8,255,175,127,187,254,4,36,215,71,244,23,26,212,
        231,0,0,0,0,73,69,78,68,174,66,96,130
    };
    // ../art/undo.png
    const unsigned char undo_png[962] {
        137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,6,0,0,0,224,119,61,248,0,0,0,9,112,72,89,115,
        0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,3,116,73,68,65,84,72,199,237,149,79,104,93,69,20,198,127,103,102,222,125,
        247,190,247,130,182,74,132,68,107,19,83,52,221,212,134,46,4,197,90,186,212,165,32,216,133,80,80,193,162,20,41,84,
        81,161,59,21,161,148,110,44,136,10,98,65,200,66,80,151,74,105,65,138,110,74,138,66,149,182,233,159,24,105,83,147,
        180,73,243,222,189,119,102,142,139,155,164,9,73,141,214,149,224,129,97,206,101,230,124,223,253,206,156,57,3,255,
        117,147,181,54,12,31,159,80,157,11,104,80,84,21,5,80,192,8,154,25,158,223,121,159,220,17,193,71,223,140,169,153,
        163,2,213,165,51,203,191,1,223,16,246,62,187,65,254,54,193,161,47,46,107,152,245,243,0,183,128,86,128,207,251,49,
        130,105,57,222,217,189,81,214,36,56,240,233,168,198,105,95,1,206,15,20,66,244,136,216,91,68,81,137,11,100,177,154,
        101,93,194,193,87,30,146,219,18,188,120,120,68,27,215,19,144,37,224,34,60,208,93,80,148,129,223,39,179,101,127,
        31,151,128,199,80,249,197,189,37,71,247,109,93,196,117,203,216,102,83,110,204,149,21,129,8,8,244,247,120,246,236,
        122,152,67,159,159,101,38,143,248,160,180,243,72,39,15,228,69,164,44,21,95,70,66,80,36,42,245,169,100,89,70,22,
        9,118,188,117,74,39,175,116,192,8,24,136,10,3,189,158,215,95,24,36,75,19,206,142,119,56,54,226,41,124,165,77,21,
        136,138,198,121,21,33,86,149,118,185,205,150,119,71,117,228,205,62,89,161,224,194,149,156,155,69,100,174,136,244,
        247,68,222,126,105,136,44,77,80,85,62,120,117,128,162,44,1,8,17,70,199,59,124,121,98,130,225,227,109,74,111,208,
        96,80,31,137,94,153,27,191,185,82,193,165,73,199,245,171,179,152,154,65,156,193,36,134,210,151,228,121,181,238,
        67,32,4,93,60,185,173,143,172,99,219,230,123,120,114,203,24,175,125,56,137,247,6,245,130,248,184,122,138,196,9,
        182,110,49,53,131,169,25,126,189,102,216,115,248,23,14,190,188,145,172,158,176,239,227,81,78,94,176,139,129,221,
        205,130,247,119,117,243,212,80,55,59,30,157,230,216,207,134,88,10,82,46,47,76,179,224,216,68,48,117,139,77,45,54,
        115,216,204,241,227,111,41,123,63,185,200,244,141,89,72,44,174,149,226,186,82,92,43,229,15,186,56,242,221,36,121,
        145,51,180,41,93,140,177,169,91,93,65,189,214,198,214,45,182,110,42,162,196,98,18,195,233,233,132,253,195,87,9,
        49,224,90,14,145,170,134,53,42,185,228,148,101,137,177,138,107,56,98,17,8,230,54,10,78,191,183,77,108,106,177,169,
        195,101,14,215,176,184,134,195,53,28,103,242,187,57,23,215,83,107,213,170,209,85,163,214,114,108,31,80,202,162,
        228,252,84,192,53,220,124,172,93,93,1,64,87,95,139,124,178,168,210,84,183,216,204,210,223,154,225,241,251,21,145,
        234,210,45,88,111,51,48,244,96,23,99,215,102,57,57,145,225,26,14,49,66,210,211,96,228,141,190,213,47,218,79,7,54,
        201,224,254,51,106,83,135,205,44,46,115,108,88,47,60,179,57,93,209,175,74,31,248,225,226,12,71,207,55,241,205,6,
        206,6,196,8,119,245,37,127,221,139,30,59,114,78,219,83,166,146,156,89,210,90,73,179,86,98,156,193,56,169,84,168,
        50,23,44,133,105,18,242,64,232,4,124,219,147,54,61,223,239,238,147,53,187,233,19,159,93,210,162,83,229,223,53,107,
        139,135,47,53,131,24,129,168,68,175,132,34,16,218,129,208,246,88,91,112,226,185,94,249,71,15,206,246,175,166,213,
        38,6,219,112,184,212,97,234,21,129,70,37,150,145,208,9,196,60,240,237,206,150,220,241,139,6,240,244,169,82,197,
        25,196,73,85,166,84,29,244,235,65,35,252,111,255,214,254,4,190,176,184,85,156,35,97,16,0,0,0,0,73,69,78,68,174,
        66,96,130
    };

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
// Purpose:   Multiple Tests dialog
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"  // MainFrame -- Main window

void MainFrame::OnToolsDlg(wxCommandEvent& WXUNUSED(event))
{
    ToolBarsDialog dlg(this);
    dlg.ShowModal();
}
