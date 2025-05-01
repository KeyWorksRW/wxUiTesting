/////////////////////////////////////////////////////////////////////////////
// Purpose:     View classes
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/docview.h>

class DoodleSegment;
class DrawingDocument;
class ImageDocument;
class ImageDetailsDocument;

// ----------------------------------------------------------------------------
// Text view classes
// ----------------------------------------------------------------------------

// The view using a standard wxTextCtrl to show its contents
class TextEditView : public wxView
{
public:
    TextEditView() : wxView(), m_text(nullptr) {}

    virtual bool OnCreate(wxDocument *doc, long flags) override;
    virtual void OnDraw(wxDC *dc) override;
    virtual bool OnClose(bool deleteWindow = true) override;

    wxTextCtrl *GetText() const { return m_text; }

private:
    void OnCopy(wxCommandEvent& WXUNUSED(event)) { m_text->Copy(); }
    void OnPaste(wxCommandEvent& WXUNUSED(event)) { m_text->Paste(); }
    void OnSelectAll(wxCommandEvent& WXUNUSED(event)) { m_text->SelectAll(); }

    wxTextCtrl *m_text;

    wxDECLARE_EVENT_TABLE();
    wxDECLARE_DYNAMIC_CLASS(TextEditView);
};

// ----------------------------------------------------------------------------
// ImageCanvas
// ----------------------------------------------------------------------------

class ImageCanvas : public wxScrolledWindow
{
public:
    ImageCanvas(wxView*);

    virtual void OnDraw(wxDC& dc) override;
private:
    wxView *m_view;
};

// ----------------------------------------------------------------------------
// ImageView
// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------
// ImageDetailsView
// ----------------------------------------------------------------------------

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
