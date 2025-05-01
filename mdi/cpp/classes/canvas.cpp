/////////////////////////////////////////////////////////////////////////////
// Purpose:     Canvas implementation
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include <wx/dcclient.h>
#include <wx/event.h>

#include "canvas.h"
#include "drawing_document.h"

Canvas::Canvas(wxView* view, wxWindow* parent) : wxScrolledWindow(parent ? parent : view->GetFrame())
{
    m_view = view;
    m_currentSegment = nullptr;
    m_lastMousePos = wxDefaultPosition;

    SetCursor(wxCursor(wxCURSOR_PENCIL));

    // this is completely arbitrary and is done just for illustration purposes
    SetVirtualSize(1000, 1000);
    SetScrollRate(20, 20);

    SetBackgroundColour(*wxWHITE);

    // Bind(wxMouseEvent, &Canvas, &Canvas::OnMouseEvent, wxEVT_LEFT_DOWN, wxEVT_RIGHT_DCLICK);
}

Canvas::~Canvas()
{
    delete m_currentSegment;
}

// Define the repainting behaviour
void Canvas::OnDraw(wxDC& dc)
{
    if (m_view)
        m_view->OnDraw(&dc);
}

// This implements a tiny doodling program. Drag the mouse using the left
// button.
void Canvas::OnMouseEvent(wxMouseEvent& event)
{
    if (!m_view)
        return;

    wxClientDC dc(this);
    PrepareDC(dc);

    dc.SetPen(*wxBLACK_PEN);

    const wxPoint pt(event.GetLogicalPosition(dc));

    // is this the end of the current segment?
    if (m_currentSegment && event.LeftUp())
    {
        if (!m_currentSegment->IsEmpty())
        {
            // We've got a valid segment on mouse left up, so store it.
            DrawingDocument* const doc = wxStaticCast(m_view->GetDocument(), DrawingDocument);

            doc->GetCommandProcessor()->Submit(new DrawingAddSegmentCommand(doc, *m_currentSegment));

            doc->Modify(true);
        }

        wxDELETE(m_currentSegment);
    }

    // is this the start of a new segment?
    if (m_lastMousePos != wxDefaultPosition && event.Dragging())
    {
        if (!m_currentSegment)
            m_currentSegment = new DoodleSegment;

        m_currentSegment->AddLine(m_lastMousePos, pt);

        dc.DrawLine(m_lastMousePos, pt);
    }

    m_lastMousePos = pt;
}
