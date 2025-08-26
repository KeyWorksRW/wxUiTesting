///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.0-4761b0c)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/collpane.h>
#include <wx/infobar.h>
#include <wx/textctrl.h>
#include <wx/valtext.h>
#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/valgen.h>
#include <wx/gbsizer.h>
#include <wx/panel.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/advprops.h>
#include <wx/grid.h>
#include <wx/ribbon/toolbar.h>
#include <wx/ribbon/panel.h>
#include <wx/ribbon/buttonbar.h>
#include <wx/ribbon/gallery.h>
#include <wx/ribbon/page.h>
#include <wx/ribbon/control.h>
#include <wx/ribbon/art.h>
#include <wx/ribbon/bar.h>
#include <wx/tglbtn.h>
#include <wx/srchctrl.h>
#include <wx/clrpicker.h>
#include <wx/spinctrl.h>
#include <wx/hyperlink.h>
#include <wx/animate.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/statbox.h>
#include <wx/aui/auibook.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FormBuilderBase
///////////////////////////////////////////////////////////////////////////////
class FormBuilderBase : public wxPanel
{
	private:

	protected:
		wxRadioBox* m_radioBox1;
		wxCollapsiblePane* m_collapsiblePane1;
		wxStaticText* m_staticText2;
		wxStaticBitmap* m_bitmap2;
		wxTextCtrl* m_textCtrlWithValidator;
		wxStaticBitmap* m_bitmap21;
		wxSlider* m_slider1;
		wxPropertyGridManager* m_propertyGridManager1;
		wxPropertyGridPage* m_propertyGridPage2;
		wxPGProperty* m_propertyGridItem1;
		wxPGProperty* m_propertyGridItem2;
		wxGrid* m_grid1;
		wxRibbonBar* m_ribbonBar1;
		wxRibbonPage* m_ribbonPage1;
		wxRibbonPanel* m_ribbonPanel1;
		wxRibbonToolBar* m_ribbonToolBar1;
		wxRibbonPanel* m_ribbonPanel2;
		wxRibbonButtonBar* m_ribbonButtonBar1;
		wxRibbonPanel* m_ribbonPanel3;
		wxRibbonGallery* m_ribbonGallery1;
		wxPanel* m_panel3;
		wxToggleButton* m_toggleBtn1;
		wxSearchCtrl* m_searchCtrl1;
		wxColourPickerCtrl* m_colourPicker1;
		wxSpinCtrl* m_spinCtrl1;
		wxHyperlinkCtrl* m_hyperlink1;
		wxAnimationCtrl* m_animCtrl1;
		wxRichTextCtrl* m_richText1;

	public:
		wxAuiNotebook* m_auinotebook1;
		wxInfoBar* m_infoCtrl1;
		wxChoice* m_choice1;
		wxString m_text_validator;
		int m_slider_validator;

		FormBuilderBase();
		FormBuilderBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		bool Create( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~FormBuilderBase();

};

