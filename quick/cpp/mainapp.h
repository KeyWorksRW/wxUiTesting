/////////////////////////////////////////////////////////////////////////////
// Purpose:   Main application class
// Author:    Ralph Walden
// Copyright: Copyright (c) 2023 KeyWorks Software (Ralph Walden)
// License:   Apache License see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/app.h>

class LanguageTest;

class MainApp : public wxApp
{
public:
    MainApp() {};

    LanguageTest* GetMainFrame() { return m_mainframe; }

protected:
    bool OnInit() override;
    int OnExit() override;

private:
    LanguageTest* m_mainframe;
};

wxDECLARE_APP(MainApp);
