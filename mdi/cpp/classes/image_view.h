/////////////////////////////////////////////////////////////////////////////
// Purpose:     Image Views and Canvas definition
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

class ImageDocument;
class ImageDetailsDocument;

class ImageCanvas : public wxScrolledWindow
{
public:
    ImageCanvas(wxView*);

    virtual void OnDraw(wxDC& dc) override;
private:
    wxView *m_view;
};

class ImageView : public wxView
{
public:
    ImageView() : wxView() {}

    virtual bool OnCreate(wxDocument*, long flags) override;
    virtual void OnDraw(wxDC*) override;
    virtual bool OnClose(bool deleteWindow = true) override;
    virtual void OnUpdate(wxView *sender, wxObject *hint = nullptr) override;

    ImageDocument* GetDocument();

private:
    ImageCanvas* m_canvas;

    wxDECLARE_DYNAMIC_CLASS(ImageView);
};

class ImageDetailsView : public wxView
{
public:
    ImageDetailsView(ImageDetailsDocument *doc);

    virtual void OnDraw(wxDC *dc) override;
    virtual bool OnClose(bool deleteWindow) override;

private:
    wxFrame *m_frame;

    wxDECLARE_NO_COPY_CLASS(ImageDetailsView);
};
