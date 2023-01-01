/////////////////////////////////////////////////////////////////////////////
// Purpose:   Main window
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"  // auto-generated: ../wxui_generated/mainframe_base.h and ../wxui_generated/mainframe_base.cpp

MainFrame::MainFrame(wxWindow* parent) : MainFrameBase(parent) {}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true forces the frame to close
    Close(true);
}
