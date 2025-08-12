/////////////////////////////////////////////////////////////////////////////
// Purpose:
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/aui/framemanager.h>
#include <wx/bitmap.h>
#include <wx/bmpbndl.h>
#include <wx/cshelp.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>

#include <wx/xrc/xmlres.h>

#include <wx/mstream.h>
#include <wx/xml/xml.h>
#include <wx/xrc/xh_aui.h>
#include <wx/xrc/xh_auitoolb.h>
#include <wx/xrc/xh_ribbon.h>

#include "xrc_python_dlg.h"

#include "mainapp.h"
#include "mainframe.h"

#include "images.h"
#include "wxue_data.h"

void MainFrame::OnXrcPythonDlg(wxCommandEvent& WXUNUSED(event))
{
    XrcPythonDlg dlg(this);
    dlg.ShowModal();
}

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

// Convert a data array into a wxAnimation
#ifdef __cpp_inline_variables
inline void wxueAnimation(const unsigned char* data, size_t size_data, wxAnimation& animation)
#else
static void wxueAnimation(const unsigned char* data, size_t size_data, wxAnimation& animation)
#endif
{
    wxMemoryInputStream strm(data, size_data);
    animation.Load(strm);
};

namespace wxue_img
{
    extern const unsigned char clr_hourglass_gif[2017];  // ../art/clr_hourglass.gif
    extern const unsigned char hide_png[242];            // ../art/hide.png
    extern const unsigned char timer_png[1380];          // ../art/timer.png
}  // namespace wxue_img

XrcPythonDlg::XrcPythonDlg(wxWindow* parent)
{
    wxGetApp().GetMainFrame()->InitializeXmlResource();
    auto xrc_data = wxue_data::get_xrc_python_dlg();
    wxMemoryInputStream strm(xrc_data.c_str(), xrc_data.size());
    auto xml_doc = new wxXmlDocument(strm);
    wxASSERT_MSG(xml_doc->IsOk(), "Unable to initialize xrc_python_dlg");
    wxASSERT_MSG(wxXmlResource::Get()->LoadDocument(xml_doc), "Unable to load resource from xrc_python_dlg");

    wxXmlResource::Get()->LoadDialog(this, parent, "PythonDlg");

    // XRC wants an external file, but unless we set the directory, it won't find it. Instead, we
    // use the embedded version. XRC will still complain about the missing file in Debug builds, but
    // this will correctly set it.
    auto bmp = wxStaticCast(FindWindow(wxXmlResource::DoGetXRCID("bmp2")), wxStaticBitmap);
    if (bmp)
    {
        bmp->SetBitmap(wxBitmapBundle::FromBitmap(wxueImage(wxue_img::hide_png, sizeof(wxue_img::hide_png))));
    }

    bmp = wxStaticCast(FindWindow(wxXmlResource::DoGetXRCID("bmp3")), wxStaticBitmap);
    if (bmp)
    {
        bmp->SetBitmap(wxBitmapBundle::FromBitmap(wxueImage(wxue_img::timer_png, sizeof(wxue_img::timer_png))));
    }

    auto m_animation_ctrl = wxStaticCast(FindWindow(wxXmlResource::DoGetXRCID("m_animation_ctrl")), wxAnimationCtrl);
    if (m_animation_ctrl)
    {
        auto animate = m_animation_ctrl->CreateAnimation();
        wxueAnimation(wxue_img::clr_hourglass_gif, sizeof(wxue_img::clr_hourglass_gif), animate);
        m_animation_ctrl->SetAnimation(animate);

        auto m_toggleBtn = wxStaticCast(FindWindow(wxXmlResource::DoGetXRCID("m_toggleBtn")), wxToggleButton);
        if (m_toggleBtn)
        {
            m_toggleBtn->Bind(
                wxEVT_TOGGLEBUTTON,
                [this](wxCommandEvent&)
                {
                    auto m_toggleBtn = wxStaticCast(FindWindow(wxXmlResource::DoGetXRCID("m_toggleBtn")), wxToggleButton);
                    auto m_animation_ctrl =
                        wxStaticCast(FindWindow(wxXmlResource::DoGetXRCID("m_animation_ctrl")), wxAnimationCtrl);
                    auto m_checkPlayAnimation =
                        wxStaticCast(FindWindow(wxXmlResource::DoGetXRCID("m_checkPlayAnimation")), wxCheckBox);
                    if (m_toggleBtn->GetValue())
                    {
                        m_animation_ctrl->Play();
                        m_checkPlayAnimation->SetValue(true);
                    }
                    else
                    {
                        m_animation_ctrl->Stop();
                        m_checkPlayAnimation->SetValue(false);
                    }
                    Fit();
                });
        }

        auto m_checkPlayAnimation = wxStaticCast(FindWindow(wxXmlResource::DoGetXRCID("m_checkPlayAnimation")), wxCheckBox);
        if (m_checkPlayAnimation)
        {
            m_checkPlayAnimation->Bind(wxEVT_CHECKBOX,
                                       [this](wxCommandEvent&)
                                       {
                                           auto m_checkPlayAnimation = wxStaticCast(
                                               FindWindow(wxXmlResource::DoGetXRCID("m_checkPlayAnimation")), wxCheckBox);
                                           auto m_animation_ctrl = wxStaticCast(
                                               FindWindow(wxXmlResource::DoGetXRCID("m_animation_ctrl")), wxAnimationCtrl);

                                           if (m_checkPlayAnimation->GetValue())
                                           {
                                               m_animation_ctrl->Play();
                                           }
                                           else
                                           {
                                               m_animation_ctrl->Stop();
                                           }
                                       });
        }
    }

    Bind(wxEVT_BUTTON, &XrcPythonDlg::OnClose, this, wxID_CLOSE);
    Bind(wxEVT_UPDATE_UI, &XrcPythonDlg::OnUpdateClose, this, wxID_CLOSE);
}

void XrcPythonDlg::OnClose(wxCommandEvent& WXUNUSED(event))
{
    EndModal(wxID_CLOSE);
}

void XrcPythonDlg::OnUpdateClose(wxUpdateUIEvent& WXUNUSED(event))
{
    auto btn = wxStaticCast(FindWindow(wxID_CLOSE), wxButton);
    wxASSERT_MSG(btn, "Close button should have been set to SetCancelButton()!");
    btn->SetLabel("Close Me!");
}
