/////////////////////////////////////////////////////////////////////////////
// Purpose:     DrawingView implementation
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "drawing_view.h"  // DrawingView definition

#include "canvas.h"            // Canvas definition
#include "drawing_document.h"  // DrawingDocument definition
#include "mainapp.h"           // MainApp -- Main application class

wxIMPLEMENT_DYNAMIC_CLASS(DrawingView, wxView);

// What to do when a view is created. Creates actual
// windows for displaying the view.
bool DrawingView::OnCreate(wxDocument* doc, long flags)
{
    if (!wxView::OnCreate(doc, flags))
        return false;

    MainApp& app = wxGetApp();
    if (app.GetMode() != MainApp::Mode_Single)
    {
        // create a new window and canvas inside it
        wxFrame* frame = app.CreateChildFrame(this, true);
        wxASSERT(frame == GetFrame());
        m_canvas = new Canvas(this);
        frame->Show();
    }
    else  // single document mode
    {
        // reuse the existing window and canvas
        m_canvas = app.GetMainWindowCanvas();
        m_canvas->SetView(this);

        // Initialize the edit menu Undo and Redo items
        doc->GetCommandProcessor()->SetEditMenu(app.GetMainWindowEditMenu());
        doc->GetCommandProcessor()->Initialize();
    }

    Bind(wxEVT_MENU, &DrawingView::OnCut, this, wxID_CUT);

    return true;
}

// Sneakily gets used for default print/preview as well as drawing on the
// screen.
void DrawingView::OnDraw(wxDC* dc)
{
    dc->SetPen(*wxBLACK_PEN);

    // simply draw all lines of all segments
    const DoodleSegments& segments = GetDocument()->GetSegments();
    for (DoodleSegments::const_iterator i = segments.begin(); i != segments.end(); ++i)
    {
        const DoodleLines& lines = i->GetLines();
        for (DoodleLines::const_iterator j = lines.begin(); j != lines.end(); ++j)
        {
            const DoodleLine& line = *j;

            dc->DrawLine(line.x1, line.y1, line.x2, line.y2);
        }
    }
}

DrawingDocument* DrawingView::GetDocument()
{
    return wxStaticCast(wxView::GetDocument(), DrawingDocument);
}

void DrawingView::OnUpdate(wxView* sender, wxObject* hint)
{
    wxView::OnUpdate(sender, hint);
    if (m_canvas)
        m_canvas->Refresh();
}

// Clean up windows used for displaying the view.
bool DrawingView::OnClose(bool deleteWindow)
{
    if (!wxView::OnClose(deleteWindow))
        return false;

    Activate(false);

    // Clear the canvas in single-window mode in which it stays alive
    if (wxGetApp().GetMode() == MainApp::Mode_Single)
    {
        m_canvas->ClearBackground();
        m_canvas->ResetView();
        m_canvas = nullptr;

        if (GetFrame())
            wxStaticCast(GetFrame(), wxFrame)->SetTitle(wxTheApp->GetAppDisplayName());
    }
    else  // not single window mode
    {
        if (deleteWindow)
        {
            GetFrame()->Destroy();
            SetFrame(nullptr);
        }
    }
    return true;
}

void DrawingView::OnCut(wxCommandEvent& WXUNUSED(event))
{
    DrawingDocument* const doc = GetDocument();

    doc->GetCommandProcessor()->Submit(new DrawingRemoveSegmentCommand(doc));
}
