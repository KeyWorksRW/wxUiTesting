/////////////////////////////////////////////////////////////////////////////
// Purpose:   Main application class
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020 KeyWorks Software (Ralph Walden)
// License:   Apache License see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/app.h>

class MainFrame;

class MainApp : public wxApp
{
public:
    MainApp() = default;

    MainFrame* GetMainFrame() { return m_mainframe; }

    // Set darkmode to 0 for light, 1 for dark.
    void SetDarkMode(long darkmode);

protected:
    bool OnInit() override;
    int OnRun() override;
    int OnExit() override;

private:
    MainFrame* m_mainframe;
};

wxDECLARE_APP(MainApp);
