/////////////////////////////////////////////////////////////////////////////
// Purpose:     DrawingView definition
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/docview.h>

class Canvas;
class DrawingDocument;

class DrawingView : public wxView
{
public:
    DrawingView() : wxView(), m_canvas(nullptr) {}

    bool OnCreate(wxDocument* doc, long flags) override;
    void OnDraw(wxDC* dc) override;
    void OnUpdate(wxView* sender, wxObject* hint = nullptr) override;
    bool OnClose(bool deleteWindow = true) override;

    DrawingDocument* GetDocument();

protected:
    void OnCut(wxCommandEvent& event);

private:
    Canvas* m_canvas;

    wxDECLARE_DYNAMIC_CLASS(DrawingView);
};
