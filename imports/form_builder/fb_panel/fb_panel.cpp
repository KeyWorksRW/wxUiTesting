///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "fb_panel.h"

///////////////////////////////////////////////////////////////////////////

fb_panel::fb_panel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	fb_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Text:"), wxDefaultPosition, wxDefaultSize, 0 );
	fb_staticText1->Wrap( -1 );
	bSizer2->Add( fb_staticText1, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );

	fb_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxT("Text \"ctrl\""), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( fb_textCtrl1, 0, wxALL, 5 );

	fb_staticText2 = new wxStaticText( this, wxID_ANY, wxT("More text:"), wxDefaultPosition, wxDefaultSize, 0 );
	fb_staticText2->Wrap( -1 );
	bSizer2->Add( fb_staticText2, 0, wxALL, 5 );

	fb_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxT("Another ctrl"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer2->Add( fb_textCtrl2, 0, wxALL, 5 );

	fb_checkBox = new wxCheckBox( this, wxID_ANY, wxT("2-state Checkbox"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( fb_checkBox, 0, wxALL, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	fb_btn = new wxButton( this, wxID_ANY, wxT("First btn"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( fb_btn, 0, wxALL, 5 );

	wxButton* btn2;
	btn2 = new wxButton( this, wxID_ANY, wxT("Popup"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btn2, 0, wxALL, 5 );

	fb_radioBtn = new wxRadioButton( this, wxID_ANY, wxT("First radio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( fb_radioBtn, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	fb_radioBtn2 = new wxRadioButton( this, wxID_ANY, wxT("Second radio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( fb_radioBtn2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	fb_checkBox2 = new wxCheckBox( this, wxID_ANY, wxT("Checked"), wxDefaultPosition, wxDefaultSize, wxCHK_3STATE|wxCHK_ALLOW_3RD_STATE_FOR_USER );
	fb_checkBox2->SetValue(true);
	bSizer3->Add( fb_checkBox2, 0, wxALL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
}

fb_panel::~fb_panel()
{
}
