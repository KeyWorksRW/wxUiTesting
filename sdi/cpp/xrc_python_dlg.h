/////////////////////////////////////////////////////////////////////////////
// Purpose:
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/animate.h>
#include <wx/aui/auibar.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/colour.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/notebook.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/tglbtn.h>

namespace wxue_img
{
    // ../art/clr_hourglass.gif
    extern const unsigned char clr_hourglass_gif[2017];
    // ../art/hide.png
    extern const unsigned char hide_png[242];
    // ../art/timer.png
    extern const unsigned char timer_png[1380];
}  // namespace wxue_img

class XrcPythonDlg : public wxDialog
{
public:
    XrcPythonDlg(wxWindow* parent);

protected:
    // Event handlers

    void OnClose(wxCommandEvent& event);
    void OnUpdateClose(wxUpdateUIEvent& event);
};
