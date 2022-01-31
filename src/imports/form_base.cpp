///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.0-4761b0c)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "form_base.h"

#include "../art/disabled.png.h"
#include "../art/french.png.h"
#include "../art/redo.png.h"
#include "../art/ribbon_button_hybrid.png.h"
#include "../art/toggle_button.png.h"
#include "../art/undo.png.h"

///////////////////////////////////////////////////////////////////////////

FormBuilderBase::FormBuilderBase()
{
}

FormBuilderBase::FormBuilderBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name )
{
	this->Create( parent, id, pos, size, style, name );
}

bool FormBuilderBase::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name )
{
	if ( !wxPanel::Create( parent, id, pos, size, style, name ) )
	{
		return false;
	}


	wxBoxSizer* parent_sizer;
	parent_sizer = new wxBoxSizer( wxVERTICAL );

	m_auinotebook1 = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_DEFAULT_STYLE );
	wxPanel* m_panel1;
	m_panel1 = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* parent_sizer1;
	parent_sizer1 = new wxGridBagSizer( 0, 0 );
	parent_sizer1->SetFlexibleDirection( wxBOTH );
	parent_sizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxString m_radioBox1Choices[] = { wxT("First"), wxT("Second"), wxT("Third") };
	int m_radioBox1NChoices = sizeof( m_radioBox1Choices ) / sizeof( wxString );
	m_radioBox1 = new wxRadioBox( m_panel1, wxID_ANY, wxT("wxRadioBox"), wxDefaultPosition, wxDefaultSize, m_radioBox1NChoices, m_radioBox1Choices, 1, wxRA_SPECIFY_COLS );
	m_radioBox1->SetSelection( 1 );
	parent_sizer1->Add( m_radioBox1, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_collapsiblePane1 = new wxCollapsiblePane( m_panel1, wxID_ANY, wxT("collapsible"), wxDefaultPosition, wxDefaultSize, wxCP_DEFAULT_STYLE );
	m_collapsiblePane1->Collapse( false );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( m_collapsiblePane1->GetPane(), wxID_ANY, wxT("これは日本語の文章です。"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALL, 5 );

	m_bitmap2 = new wxStaticBitmap( m_collapsiblePane1->GetPane(), wxID_ANY, wxArtProvider::GetBitmap( wxART_GO_UP, wxART_BUTTON ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_bitmap2, 0, wxALL, 5 );


	m_collapsiblePane1->GetPane()->SetSizer( bSizer2 );
	m_collapsiblePane1->GetPane()->Layout();
	bSizer2->Fit( m_collapsiblePane1->GetPane() );
	parent_sizer1->Add( m_collapsiblePane1, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );

	m_infoCtrl1 = new wxInfoBar( m_panel1 );
	m_infoCtrl1->SetShowHideEffects( wxSHOW_EFFECT_ROLL_TO_RIGHT, wxSHOW_EFFECT_ROLL_TO_LEFT );
	m_infoCtrl1->SetEffectDuration( 500 );
	parent_sizer1->Add( m_infoCtrl1, wxGBPosition( 0, 0 ), wxGBSpan( 1, 3 ), wxALL|wxEXPAND, 5 );

	m_textCtrlWithValidator = new wxTextCtrl( m_panel1, wxID_ANY, wxT("initial"), wxDefaultPosition, wxDefaultSize, wxTE_CAPITALIZE );
	m_textCtrlWithValidator->SetValidator( wxTextValidator( wxFILTER_ALPHANUMERIC, &m_text_validator ) );

	parent_sizer1->Add( m_textCtrlWithValidator, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	wxString m_choice1Choices[] = { wxT("First"), wxT("Second"), wxT("Third") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 1 );
	parent_sizer1->Add( m_choice1, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_bitmap21 = new wxStaticBitmap( m_panel1, wxID_ANY, french_png_to_wx_bitmap(), wxDefaultPosition, wxDefaultSize, 0 );
	parent_sizer1->Add( m_bitmap21, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_slider1 = new wxSlider( m_panel1, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_slider1->SetValidator( wxGenericValidator( &m_slider_validator ) );

	parent_sizer1->Add( m_slider1, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );


	m_panel1->SetSizer( parent_sizer1 );
	m_panel1->Layout();
	parent_sizer1->Fit( m_panel1 );
	m_auinotebook1->AddPage( m_panel1, wxT("Common"), true, wxNullBitmap );
	wxPanel* m_panel12;
	m_panel12 = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_propertyGridManager1 = new wxPropertyGridManager(m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPGMAN_DEFAULT_STYLE|wxPG_AUTO_SORT);
	m_propertyGridManager1->SetExtraStyle( wxPG_EX_HELP_AS_TOOLTIPS );

	m_propertyGridPage2 = m_propertyGridManager1->AddPage( wxT("Page"), wxNullBitmap );
	m_propertyGridItem1 = m_propertyGridPage2->Append( new wxStringProperty( wxT("String"), wxT("String") ) );
	m_propertyGridPage2->SetPropertyHelpString( m_propertyGridItem1, wxT("String property item") );
	m_propertyGridItem2 = m_propertyGridPage2->Append( new wxEditEnumProperty( wxT("Edit Enum"), wxT("Edit Enum") ) );
	m_propertyGridPage2->SetPropertyHelpString( m_propertyGridItem2, wxT("Edit Enumerations") );
	bSizer6->Add( m_propertyGridManager1, 0, wxALL, 5 );

	m_grid1 = new wxGrid( m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grid1->CreateGrid( 3, 3 );
	m_grid1->EnableEditing( true );
	m_grid1->EnableGridLines( true );
	m_grid1->SetGridLineColour( wxColour( 0, 128, 128 ) );
	m_grid1->EnableDragGridSize( false );
	m_grid1->SetMargins( 0, 0 );

	// Columns
	m_grid1->EnableDragColMove( false );
	m_grid1->EnableDragColSize( true );
	m_grid1->SetColLabelValue( 0, wxT("First") );
	m_grid1->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid1->EnableDragRowSize( true );
	m_grid1->SetRowLabelValue( 0, wxT("Row 1") );
	m_grid1->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grid1->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer6->Add( m_grid1, 0, wxALL, 5 );


	fgSizer1->Add( bSizer6, 1, wxEXPAND, 5 );

	m_ribbonBar1 = new wxRibbonBar( m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxRIBBON_BAR_DEFAULT_STYLE );
	m_ribbonBar1->SetArtProvider(new wxRibbonDefaultArtProvider);
	m_ribbonPage1 = new wxRibbonPage( m_ribbonBar1, wxID_ANY, wxT("MyRibbonPage") , wxNullBitmap , 0 );
	m_ribbonPanel1 = new wxRibbonPanel( m_ribbonPage1, wxID_ANY, wxT("Toolbar") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonToolBar1 = new wxRibbonToolBar( m_ribbonPanel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonToolBar1->AddTool( wxID_ANY, undo_png_to_wx_bitmap(), wxEmptyString);
	m_ribbonToolBar1->AddDropdownTool( wxID_ANY, redo_png_to_wx_bitmap(), wxEmptyString);
	m_ribbonToolBar1->AddToggleTool( wxID_ANY, toggle_button_png_to_wx_bitmap(), wxEmptyString);
	m_ribbonToolBar1->AddHybridTool( wxID_ANY, ribbon_button_hybrid_png_to_wx_bitmap(), wxEmptyString);
	m_ribbonPanel2 = new wxRibbonPanel( m_ribbonPage1, wxID_ANY, wxT("RibbonButton") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonButtonBar1 = new wxRibbonButtonBar( m_ribbonPanel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonButtonBar1->AddButton( wxID_ANY, wxT("Undo"), undo_png_to_wx_bitmap(), wxEmptyString);
	m_ribbonButtonBar1->AddDropdownButton( wxID_ANY, wxT("Drop"), redo_png_to_wx_bitmap(), wxEmptyString);
	m_ribbonButtonBar1->AddToggleButton( wxID_ANY, wxT("Toggle"), toggle_button_png_to_wx_bitmap(), wxEmptyString);
	m_ribbonButtonBar1->AddHybridButton( wxID_ANY, wxT("Hybrid"), ribbon_button_hybrid_png_to_wx_bitmap(), wxEmptyString);
	m_ribbonPanel3 = new wxRibbonPanel( m_ribbonPage1, wxID_ANY, wxT("Gallery") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonGallery1 = new wxRibbonGallery( m_ribbonPanel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	m_ribbonGallery1->Append( undo_png_to_wx_bitmap(), wxID_ANY);
	m_ribbonGallery1->Append( redo_png_to_wx_bitmap(), wxID_ANY);
	m_ribbonBar1->Realize();

	fgSizer1->Add( m_ribbonBar1, 0, wxALL, 5 );


	m_panel12->SetSizer( fgSizer1 );
	m_panel12->Layout();
	fgSizer1->Fit( m_panel12 );
	m_auinotebook1->AddPage( m_panel12, wxT("Data"), false, wxNullBitmap );
	m_panel3 = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_toggleBtn1 = new wxToggleButton( m_panel3, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_toggleBtn1, 0, wxALL, 5 );

	m_searchCtrl1 = new wxSearchCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_searchCtrl1->ShowSearchButton( true );
	#endif
	m_searchCtrl1->ShowCancelButton( false );
	bSizer4->Add( m_searchCtrl1, 0, wxALL, 5 );

	m_colourPicker1 = new wxColourPickerCtrl( m_panel3, wxID_ANY, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer4->Add( m_colourPicker1, 0, wxALL, 5 );


	bSizer3->Add( bSizer4, 0, wxALL, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_spinCtrl1 = new wxSpinCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 5 );
	bSizer5->Add( m_spinCtrl1, 0, wxALL, 5 );

	m_hyperlink1 = new wxHyperlinkCtrl( m_panel3, wxID_ANY, wxT("wxFB Website"), wxT("http://www.wxformbuilder.org"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	m_hyperlink1->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer5->Add( m_hyperlink1, 0, wxALL, 5 );


	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );

	m_animCtrl1 = new wxAnimationCtrl( m_panel3, wxID_ANY, wxNullAnimation, wxDefaultPosition, wxDefaultSize, wxAC_DEFAULT_STYLE );
	m_animCtrl1->LoadFile( wxT("clr_hourglass.gif") );

	m_animCtrl1->SetInactiveBitmap( disabled_png_to_wx_bitmap() );
	m_animCtrl1->Play();
	bSizer5->Add( m_animCtrl1, 0, wxALL, 5 );


	bSizer3->Add( bSizer5, 0, wxALL, 5 );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Static Box") ), wxHORIZONTAL );

	m_richText1 = new wxRichTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	sbSizer1->Add( m_richText1, 1, wxEXPAND | wxALL, 5 );


	bSizer3->Add( sbSizer1, 1, wxEXPAND, 5 );


	m_panel3->SetSizer( bSizer3 );
	m_panel3->Layout();
	bSizer3->Fit( m_panel3 );
	m_auinotebook1->AddPage( m_panel3, wxT("Additional"), false, wxNullBitmap );

	parent_sizer->Add( m_auinotebook1, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( parent_sizer );
	this->Layout();

	return true;
}

FormBuilderBase::~FormBuilderBase()
{
}
