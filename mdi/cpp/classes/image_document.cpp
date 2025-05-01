/////////////////////////////////////////////////////////////////////////////
// Purpose:     Image Document class
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence see ../../../wxWidgets32/licence.txt
/////////////////////////////////////////////////////////////////////////////

#include "image_document.h"

#include "image_view.h"  // ImageCanvas -- Image Views and Canvas definition

wxIMPLEMENT_DYNAMIC_CLASS(ImageDocument, wxDocument);

bool ImageDocument::DoOpenDocument(const wxString& file)
{
    return m_image.LoadFile(file);
}

bool ImageDocument::OnOpenDocument(const wxString& filename)
{
    if (!wxDocument::OnOpenDocument(filename))
        return false;

    // we don't have a wxDocTemplate for the image details document as it's
    // never created by wxWidgets automatically, instead just do it manually
    ImageDetailsDocument* const docDetails = new ImageDetailsDocument(this);
    docDetails->SetFilename(filename);

    new ImageDetailsView(docDetails);

    return true;
}

ImageDetailsDocument::ImageDetailsDocument(ImageDocument* parent) : wxDocument(parent)
{
    const wxImage image = parent->GetImage();

    m_size.x = image.GetWidth();
    m_size.y = image.GetHeight();
    m_numColours = image.CountColours();
    m_type = image.GetType();
    m_hasAlpha = image.HasAlpha();
}
