/////////////////////////////////////////////////////////////////////////////
// Purpose:   Main application class
// Author:    Ralph Walden
// Copyright: Copyright (c) 2025 KeyWorks Software (Ralph Walden)
// License:   wxWindows Library Licence see ../../wxWidgets32/licence.txt
/////////////////////////////////////////////////////////////////////////////

// This portion of the app is derived from the DocView sample in
// ../../wxWidgets32/samples/docview/docview.cpp

// wxWindows Library Licence applies only to this file and it's header, which essentially means that
// you are free to distribute binary copies of this code. If you distribute source code based on
// this code, then you need to use the wxWindows Library License for that code.

#if !wxUSE_DOC_VIEW_ARCHITECTURE
    #error You must set wxUSE_DOC_VIEW_ARCHITECTURE to 1 in setup.h!
#endif

#if !wxUSE_MDI_ARCHITECTURE
    #error You must set wxUSE_MDI_ARCHITECTURE to 1 in setup.h!
#endif

#if !wxUSE_AUI
    #error You must set wxUSE_AUI to 1 in setup.h!
#endif

#ifdef _MSC_VER
    // REVIEW: [Randalphwa - 04-29-2025] Do we really need these or are they leftover from before
    // CMake was used to build?
    #if defined(_WIN32)

        #pragma comment(lib, "kernel32.lib")
        #pragma comment(lib, "user32.lib")
        #pragma comment(lib, "gdi32.lib")
        #pragma comment(lib, "comctl32.lib")
        #pragma comment(lib, "comdlg32.lib")
        #pragma comment(lib, "shell32.lib")

        #pragma comment(lib, "rpcrt4.lib")
        #pragma comment(lib, "advapi32.lib")
    #endif
#endif

#include <wx/aui/tabmdi.h>
#include <wx/cmdline.h>
#include <wx/config.h>
#include <wx/docmdi.h>
#include <wx/docview.h>

#include "mainapp.h"

#include "aui_frame.h"     // AuiFrame definition
#include "mdi_frame.h"     // MdiFrame definition
#include "normal_frame.h"  // NormalFrame definition
#include "sdi_frame.h"     // SdiFrame definition

#include "drawing_document.h"  // DrawingDocument definition
#include "drawing_view.h"      // DrawingView definition

#include "image_document.h"  // ImageDocument -- Image Document class
#include "image_view.h"      // ImageCanvas -- Image Views and Canvas definition

#include "text_document.h"  // TextCtrlDocument -- Text Ctrl Document class
#include "textctrl_view.h"  // TextEditView definition

// #include "mainframe.h"  // MainFrame -- Main window

wxIMPLEMENT_APP(MainApp);

#if defined(_WIN32) && defined(_DEBUG)

// Because of the extensive use of share_ptrs and the number of classes that are created during initialization and never
// destroyed, both the original wxFormBuilder as well as this code base will have a lot of shared_ptrs that are completely
// dereferenced when the app exits, leading to a long and time-comsuming display of "leaked" memory when run under a
// Microsoft debugger. While it would be ideal if all those shared_ptrs were freed, it's a low priority to write a bunch of
// code to walk through all the maps and vectors in order to free the pointers.

// Uncomment the following to turn on a memory leak dump on exit.
// #define USE_CRT_MEMORY_DUMP

#endif  // _WIN32 && defined(_DEBUG)

// constants for the command line options names
namespace CmdLineOption
{

    const char* const MDI = "mdi";
    const char* const AUI = "aui";
    const char* const SDI = "sdi";
    const char* const SINGLE = "single";

}  // namespace CmdLineOption

void MainApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    wxApp::OnInitCmdLine(parser);

    parser.AddSwitch("", CmdLineOption::MDI, "run in MDI mode: multiple documents, single window");
    parser.AddSwitch("", CmdLineOption::AUI, "run in MDI mode using AUI: multiple documents, single window");
    parser.AddSwitch("", CmdLineOption::SDI, "run in SDI mode: multiple documents, multiple windows");
    parser.AddSwitch("", CmdLineOption::SINGLE, "run in single document mode");

    parser.AddParam("document-file", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_MULTIPLE | wxCMD_LINE_PARAM_OPTIONAL);
}

bool MainApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    int numModeOptions = 0;

    if (parser.Found(CmdLineOption::MDI))
    {
        m_mode = Mode_MDI;
        numModeOptions++;
    }

    if (parser.Found(CmdLineOption::AUI))
    {
        m_mode = Mode_AUI;
        numModeOptions++;
    }

    if (parser.Found(CmdLineOption::SDI))
    {
        m_mode = Mode_SDI;
        numModeOptions++;
    }

    if (parser.Found(CmdLineOption::SINGLE))
    {
        m_mode = Mode_Single;
        numModeOptions++;
    }

    if (numModeOptions > 1)
    {
        wxLogError("Only a single option choosing the mode can be given.");
        return false;
    }

    // save any files given on the command line: we'll open them in OnInit()
    // later, after creating the frame
    for (size_t i = 0; i != parser.GetParamCount(); ++i)
        m_filesFromCmdLine.push_back(parser.GetParam(i));

    return wxApp::OnCmdLineParsed(parser);
}

bool MainApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

#if defined(wxUSE_ON_FATAL_EXCEPTION)
    ::wxHandleFatalExceptions(true);
#endif

    SetAppDisplayName(txtAppname);
    SetVendorName("KeyWorks");
    wxDocManager* docManager = new wxDocManager;

    // BUGBUG: [Randalphwa - 05-01-2025] Technically, this is a memory leak since it is never freed, and with MSVC debugger,
    // terminating the app will show a memory leak.

    // Create a template relating drawing documents to their views
    new wxDocTemplate(docManager, "Drawing", "*.drw", "", "drw", "Drawing Doc", "Drawing View", CLASSINFO(DrawingDocument),
                      CLASSINFO(DrawingView));

    if (m_mode == Mode_Single)
    {
        // If we've only got one window, we only get to edit one document at a
        // time. Therefore no text editing, just doodling.
        docManager->SetMaxDocsOpen(1);
    }
    else  // multiple documents mode: allow documents of different types
    {
        // Create a template relating text documents to their views
        new wxDocTemplate(docManager, "Text", "*.txt;*.text", "", "txt;text", "Text Doc", "Text View",
                          CLASSINFO(TextEditDocument), CLASSINFO(TextEditView));
        // Create a template relating image documents to their views
        new wxDocTemplate(docManager, "Image", "*.png;*.jpg", "", "png;jpg", "Image Doc", "Image View",
                          CLASSINFO(ImageDocument), CLASSINFO(ImageView));
    }

    wxFrame* frame = nullptr;

    switch (m_mode)
    {
        case Mode_MDI:
            frame = new MdiFrame(docManager);
            break;

        case Mode_Single:
            frame = new NormalFrame(nullptr);
            break;

        case Mode_SDI:
            frame = new SdiFrame(docManager);
            break;

        case Mode_AUI:
            frame = new AuiFrame(nullptr);
            break;
    }

    // docManager->FileHistoryUseMenu(menuFile);
    // docManager->FileHistoryLoad(*wxConfig::Get());

    if (m_mode == Mode_Single)
    {
    }

    frame->Centre();
    frame->Show();

    // Bind(wxEVT_MENU, &MainApp::OnAbout, this, wxID_ABOUT);

    return true;
}

int MainApp::OnRun()
{
    // m_mainframe = new MainFrame(nullptr);
    // m_mainframe->SetTitle("C++ MDI Tests");
    // m_mainframe->Show(true);

    ::wxInitAllImageHandlers();

    return wxApp::OnRun();
}

int MainApp::OnExit()
{
    return wxApp::OnExit();
}

wxFrame* MainApp::CreateChildFrame(wxView* view, bool /* isCanvas */)
{
    // create a child frame of appropriate class for the current mode
    wxFrame* subframe = nullptr;
    wxDocument* doc = view->GetDocument();
    switch (GetMode())
    {
        case Mode_MDI:
            subframe = new wxDocMDIChildFrame(doc, view, wxStaticCast(GetTopWindow(), wxDocMDIParentFrame), wxID_ANY,
                                              "Child Frame", wxDefaultPosition, wxSize(300, 300));
            break;

        case Mode_AUI:
            subframe = new wxDocChildFrameAny<wxAuiMDIChildFrame, wxAuiMDIParentFrame>(
                doc, view, wxStaticCast(GetTopWindow(), wxAuiMDIParentFrame), wxID_ANY, "Child Frame", wxDefaultPosition,
                wxSize(300, 300));
            break;

        case Mode_SDI:
            subframe = new wxDocChildFrame(doc, view, wxStaticCast(GetTopWindow(), wxDocParentFrame), wxID_ANY,
                                           "Child Frame", wxDefaultPosition, wxSize(300, 300));

            subframe->Centre();
            break;

        case Mode_Single:
            subframe = new wxFrame(wxStaticCast(GetTopWindow(), wxDocParentFrame), wxID_ANY, "Child Frame",
                                   wxDefaultPosition, wxSize(300, 300));
            subframe->Centre();
            break;
    }
    return subframe;
}

void MainApp::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxString modeName;
    switch (m_mode)
    {
        case Mode_MDI:
            modeName = "MDI";
            break;

        case Mode_AUI:
            modeName = "AUI";
            break;

        case Mode_SDI:
            modeName = "SDI";
            break;

        case Mode_Single:
            modeName = "single document";
            break;

        default:
            wxFAIL_MSG("unknown mode ");
    }

    auto docsCount = wxDocManager::GetDocumentManager()->GetDocumentsVector().size();

    wxLogMessage("This is the wxUiTesting MDI app\n"
                 "running in %s mode.\n"
                 "All frames generated by wxUiEditor.\n"
                 "%d open documents.\n"
                 "\n"
                 "Authors: Julian Smart, Vadim Zeitlin, wxUiEditor\n"
                 "\n"
                 "Usage: mdi_test [--{mdi,aui,sdi,single}]",
                 modeName, static_cast<int>(docsCount));
}
