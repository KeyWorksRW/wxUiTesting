/////////////////////////////////////////////////////////////////////////////
// Purpose:     Image Document class
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence see ../../../wxWidgets32/licence.txt
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/docview.h>

// This is a normal document containing an image. It can be created from an image file on disk as
// usual.
class ImageDocument : public wxDocument
{
public:
    ImageDocument() : wxDocument() { }

    virtual bool OnOpenDocument(const wxString& file) override;

    wxImage GetImage() const { return m_image; }

protected:
    virtual bool DoOpenDocument(const wxString& file) override;

private:
    wxImage m_image;

    wxDECLARE_NO_COPY_CLASS(ImageDocument);
    wxDECLARE_DYNAMIC_CLASS(ImageDocument);
};

// This is a child document of ImageDocument: this document doesn't correspond to any file on disk,
// it's part of ImageDocument and can't be instantiated independently of it.
class ImageDetailsDocument : public wxDocument
{
public:
    ImageDetailsDocument(ImageDocument *parent);

    // accessors for ImageDetailsView
    wxSize GetSize() const { return m_size; }
    unsigned long GetNumColours() const { return m_numColours; }
    wxBitmapType GetType() const { return m_type; }
    bool HasAlpha() const { return m_hasAlpha; }

private:
    // some information about the image we choose to show to the user
    wxSize m_size;
    unsigned long m_numColours;
    wxBitmapType m_type;
    bool m_hasAlpha;

    wxDECLARE_NO_COPY_CLASS(ImageDetailsDocument);
};
