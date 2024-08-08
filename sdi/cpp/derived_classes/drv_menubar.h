/////////////////////////////////////////////////////////////////////////////
// Purpose:   Derived class for wxMenuBar 
// Author:    Ralph Walden
// Copyright: Copyright (c) 2024 KeyWorks Software (Ralph Walden)
// License:   LICENSE -- see ../../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/menu.h>  // wxMenuBar

class drv_menubar : public wxMenuBar
{
public:
    drv_menubar(long style = 0)
        : wxMenuBar(style)
    {
    }
};


