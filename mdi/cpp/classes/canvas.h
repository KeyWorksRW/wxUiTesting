/////////////////////////////////////////////////////////////////////////////
// Purpose:     Canvas definition
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/docview.h>
#include <wx/scrolwin.h>

class DoodleSegment;

// The window showing the drawing itself
class Canvas : public wxScrolledWindow
{
public:
    // view may be null if we're not associated with one yet, but parent must
    // be a valid pointer
    Canvas(wxView* view, wxWindow* parent = nullptr);
    virtual ~Canvas();

    virtual void OnDraw(wxDC& dc) override;

    // in a normal multiple document application a canvas is associated with
    // one view from the beginning until the end, but to support the single
    // document mode in which all documents reuse the same MyApp::GetCanvas()
    // we need to allow switching the canvas from one view to another one

    void SetView(wxView* view)
    {
        wxASSERT_MSG(!m_view, "shouldn't be already associated with a view");

        m_view = view;
    }

    void ResetView()
    {
        wxASSERT_MSG(m_view, "should be associated with a view");

        m_view = nullptr;
    }

protected:
    void OnMouseEvent(wxMouseEvent& event);

private:
    wxView* m_view;

    // the segment being currently drawn or nullptr if none
    DoodleSegment* m_currentSegment;

    // the last mouse press position
    wxPoint m_lastMousePos;
};
