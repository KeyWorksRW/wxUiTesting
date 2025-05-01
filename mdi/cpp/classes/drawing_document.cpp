/////////////////////////////////////////////////////////////////////////////
// Purpose:     Drawing Document classes
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence see ../../../wxWidgets32/licence.txt
/////////////////////////////////////////////////////////////////////////////

#include "drawing_document.h"

wxIMPLEMENT_DYNAMIC_CLASS(DrawingDocument, wxDocument);

std::ostream& DrawingDocument::SaveObject(std::ostream& ostream)
{
    std::ostream& stream = ostream;

    wxDocument::SaveObject(ostream);

    const wxInt32 count = m_doodleSegments.size();
    stream << count << '\n';

    for (int n = 0; n < count; n++)
    {
        m_doodleSegments[n].SaveObject(ostream);
        stream << '\n';
    }

    return ostream;
}

std::istream& DrawingDocument::LoadObject(std::istream& istream)
{
    std::istream& stream = istream;

    wxDocument::LoadObject(istream);

    wxInt32 count = 0;
    stream >> count;
    if (count < 0)
    {
        wxLogWarning("Drawing document corrupted: invalid segments count.");
        istream.clear(std::ios::badbit);
        return istream;
    }

    for (int n = 0; n < count; n++)
    {
        DoodleSegment segment;
        segment.LoadObject(istream);
        m_doodleSegments.push_back(segment);
    }

    return istream;
}

void DrawingDocument::DoUpdate()
{
    Modify(true);
    UpdateAllViews();
}

void DrawingDocument::AddDoodleSegment(const DoodleSegment& segment)
{
    m_doodleSegments.push_back(segment);

    DoUpdate();
}

bool DrawingDocument::PopLastSegment(DoodleSegment* segment)
{
    if (m_doodleSegments.empty())
        return false;

    if (segment)
        *segment = m_doodleSegments.back();

    m_doodleSegments.pop_back();

    DoUpdate();

    return true;
}

std::ostream& DoodleSegment::SaveObject(std::ostream& ostream)
{
    std::ostream& stream = ostream;

    const wxInt32 count = m_lines.size();
    stream << count << '\n';

    for ( int n = 0; n < count; n++ )
    {
        const DoodleLine& line = m_lines[n];
        stream
            << line.x1 << ' '
            << line.y1 << ' '
            << line.x2 << ' '
            << line.y2 << '\n';
    }

    return ostream;
}

std::istream& DoodleSegment::LoadObject(std::istream& istream)
{
    std::istream& stream = istream;

    wxInt32 count = 0;
    stream >> count;

    for ( int n = 0; n < count; n++ )
    {
        DoodleLine line;
        stream
            >> line.x1
            >> line.y1
            >> line.x2
            >> line.y2;
        m_lines.push_back(line);
    }

    return istream;
}
