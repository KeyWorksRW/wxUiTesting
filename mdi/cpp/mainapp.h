/////////////////////////////////////////////////////////////////////////////
// Purpose:   Main application class
// Author:    Ralph Walden
// Copyright: Copyright (c) 2025 KeyWorks Software (Ralph Walden)
// License:   wxWindows Library Licence see ../../wxWidgets32/licence.txt
/////////////////////////////////////////////////////////////////////////////

#pragma once

// This portion of the app is derived from the DocView sample in
// ../../wxWidgets32/samples/docview/docview.cpp

// wxWindows Library Licence applies only to this file and it's source, which essentially means that
// you are free to distribute binary copies of this code. If you distribute source code based on
// this code, then you need to use the wxWindows Library License for that code.

#include <memory>

#include <wx/app.h>

#include <vector>

class MainFrame;
class wxFrame;
class wxView;
class Canvas;  // Canvas -- The window showing the drawing itself
class wxDocTemplate;

class MainApp : public wxApp
{
public:
    enum Mode
    {
        Mode_MDI,    // MDI mode: multiple documents, single top level window
        Mode_AUI,    // MDI AUI mode
        Mode_SDI,    // SDI mode: multiple documents, multiple top level windows
        Mode_Single  // single document mode (and hence single top level window)
    };

    MainApp() {};

    MainFrame* GetMainFrame() { return m_mainframe; }

    void OnInitCmdLine(wxCmdLineParser& parser) override;
    bool OnCmdLineParsed(wxCmdLineParser& parser) override;

    Mode GetMode() const { return m_mode; }

    wxFrame* CreateChildFrame(wxView* view, bool isCanvas);
    Canvas* GetMainWindowCanvas() const
    {
        wxASSERT(m_canvas);
        return m_canvas;
    }
    wxMenu* GetMainWindowEditMenu() const
    {
        wxASSERT(m_menuEdit);
        return m_menuEdit;
    }

    void OnAbout(wxCommandEvent& WXUNUSED(event));

protected:
    bool OnInit() override;
    int OnRun() override;
    int OnExit() override;

private:
    MainFrame* m_mainframe;

    Mode m_mode;
    Canvas* m_canvas;
    wxMenu* m_menuEdit;

    // REVIEW: [Randalphwa - 05-01-2025] Good idea, but causes a crash when the app exits.
    
    // std::unique_ptr<wxDocTemplate> m_drawingDocTemplate;  // Drawing document template
    // std::unique_ptr<wxDocTemplate> m_textDocTemplate;     // Text document template
    // std::unique_ptr<wxDocTemplate> m_imageDocTemplate;    // Image document template

    std::vector<wxString> m_filesFromCmdLine;
};

wxDECLARE_APP(MainApp);
