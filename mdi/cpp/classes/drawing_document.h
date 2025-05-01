/////////////////////////////////////////////////////////////////////////////
// Purpose:     Drawing Document classes
// Author:      Julian Smart
// Modified by: Vadim Zeitlin: merge with the MDI version and general cleanup
// Created:     04/01/98
// Copyright:   (c) 1998 Julian Smart
//              (c) 2008 Vadim Zeitlin
// Licence:     wxWindows licence see ../../../wxWidgets32/licence.txt
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/docview.h>
#include <wx/image.h>
#include <wx/vector.h>

#include <istream>
#include <ostream>

// Represents a line from one point to the other
struct DoodleLine
{
    DoodleLine() { /* leave fields uninitialized */ }

    DoodleLine(const wxPoint& pt1, const wxPoint& pt2) : x1(pt1.x), y1(pt1.y), x2(pt2.x), y2(pt2.y) {}

    wxInt32 x1;
    wxInt32 y1;
    wxInt32 x2;
    wxInt32 y2;
};

typedef wxVector<DoodleLine> DoodleLines;

// Contains a list of lines: represents a mouse-down doodle
class DoodleSegment
{
public:
    std::ostream& SaveObject(std::ostream& stream);
    std::istream& LoadObject(std::istream& stream);

    bool IsEmpty() const { return m_lines.empty(); }
    void AddLine(const wxPoint& pt1, const wxPoint& pt2) { m_lines.push_back(DoodleLine(pt1, pt2)); }
    const DoodleLines& GetLines() const { return m_lines; }

private:
    DoodleLines m_lines;
};

typedef wxVector<DoodleSegment> DoodleSegments;

class DrawingDocument : public wxDocument
{
public:
    DrawingDocument() : wxDocument() {}

    std::ostream& SaveObject(std::ostream& stream) override;
    std::istream& LoadObject(std::istream& stream) override;

    void AddDoodleSegment(const DoodleSegment& segment);

    // remove the last segment, if any, and copy it in the provided pointer if
    // not null and return true or return false and do nothing if there are no
    // segments
    bool PopLastSegment(DoodleSegment* segment);

    const DoodleSegments& GetSegments() const { return m_doodleSegments; }

protected:
    void DoUpdate();

private:
    DoodleSegments m_doodleSegments;

    wxDECLARE_DYNAMIC_CLASS(DrawingDocument);
};

// ----------------------------------------------------------------------------
// Some operations (which can be done and undone by the view) on the document:
// ----------------------------------------------------------------------------

// Base class for all operations on DrawingDocument
class DrawingCommand : public wxCommand
{
public:
    DrawingCommand(DrawingDocument* doc, const wxString& name, const DoodleSegment& segment = DoodleSegment()) :
        wxCommand(true, name), m_doc(doc), m_segment(segment)
    {
    }

protected:
    bool DoAdd()
    {
        m_doc->AddDoodleSegment(m_segment);
        return true;
    }
    bool DoRemove() { return m_doc->PopLastSegment(&m_segment); }

private:
    DrawingDocument* const m_doc;
    DoodleSegment m_segment;
};

class DrawingAddSegmentCommand : public DrawingCommand
{
public:
    DrawingAddSegmentCommand(DrawingDocument* doc, const DoodleSegment& segment) :
        DrawingCommand(doc, "Add new segment", segment)
    {
    }

    virtual bool Do() override { return DoAdd(); }
    virtual bool Undo() override { return DoRemove(); }
};

class DrawingRemoveSegmentCommand : public DrawingCommand
{
public:
    DrawingRemoveSegmentCommand(DrawingDocument* doc) : DrawingCommand(doc, "Remove last segment") {}

    virtual bool Do() override { return DoRemove(); }
    virtual bool Undo() override { return DoAdd(); }
};
