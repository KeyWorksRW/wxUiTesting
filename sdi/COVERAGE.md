# Contents

The following tables indicate whether or not code is being generated sdi_test.wxui. A "???" indicates it is not currently used. "no" indcates that the language doesn't support it. "---" in the XRC column indicates that it could be generated, but there is no current testing for it.

The Ruby column will initially be used to verify if code generation for that control works in Ruby. Once the wxRuby code generation is far enought along, the sdi_test.wxui project will be updated to generate and test wxRuby code as well as it's current tests for C++ and wxPython.

XRC is listed, but there is currently no testing code for it. "---" in the XRC column means it could be generated. "no" indicates that XRC does not support the class.

# Categories

### Books

| Class         | C++ | Python | Ruby | XRC |
| ------------- | --- | ------ | ---- | --- |
| wxAuiNotebook | yes | yes    | ---  | --- |
| wxChoicebook  | yes | yes    | ---  | --- |
| wxListbook    | yes | yes    | ---  | --- |
| wxNotebook    | yes | yes    | ---  | --- |
| wxSimplebook  | ??? | ???    | ---  | --- |
| wxToolbook    | yes | yes    | ---  | --- |
| wxTreebook    | yes | yes    | ---  | --- |

### Forms

| Class                  | C++ | Python | Ruby | XRC |
| ---------------------- | --- | ------ | ---- | --- |
| wxDialog               | yes | yes    | yes  | yes |
| wxFrame                | yes | yes    | yes  | yes |
| wxMenu                 | yes | yes    | ---  | --- |
| wxMenuBar              | yes | yes    | ---  | --- |
| wxPanel                | yes | yes    | yes  | --- |
| wxPopupTransientWindow | yes | yes    | ---  | no  |
| wxRibbonBar            | yes | yes    | ---  | --- |
| wxToolBar              | yes | yes    | ---  | --- |
| wxWizard               | yes | yes    | ---  | --- |

### Pickers

| Class              | C++ | Python | Ruby | XRC |
| ------------------ | --- | ------ | ---- | --- |
| wxColourPickerCtrl | yes | yes    | ---  | --- |
| wxDatePickerCtrl   | yes | yes    | ---  | --- |
| wxDirPickerCtrl    | yes | yes    | ---  | --- |
| wxFilePickerCtrl   | yes | yes    | ---  | --- |
| wxFontPickerCtrl   | yes | yes    | ---  | --- |
| wxTimePickerCtrl   | yes | yes    | ---  | --- |

### Sizers

| Class                  | C++ | Python | Ruby | XRC |
| ---------------------- | --- | ------ | ---- | --- |
| wxBoxSizer             | yes | yes    | yes  | --- |
| wxCheckBoxSizer        | ??? | no     | ---  | --- |
| wxFlexGridSizer        | yes | yes    | ---  | --- |
| wxGridBagSizer         | yes | yes    | ---  | --- |
| wxGridSizer            | ??? | ???    | ---  | --- |
| wxRadioButtonSizer     | ??? | no     | ---  | --- |
| wxStaticBoxSizer       | yes | yes    | ---  | --- |
| wxStdDialogButtonSizer | yes | yes    | ---  | --- |
| wxWrapSizer            | yes | yes    | ---  | --- |

# Classes

| Class                  | C++ | Python | Ruby | XRC |
| ---------------------- | --- | ------ | ---- | --- |
| wxActivityIndicator    | ??? | ???    | ---  | --- |
| wxAnimationCtrl        | ??? | ???    | ---  | --- |
| wxAuiToolBar           | ??? | ???    | ---  | --- |
| wxBannerWindow         | yes | yes    | ---  | --- |
| wxBitmapComboBox       | ??? | ???    | ---  | --- |
| wxButton               | ??? | ???    | ---  | --- |
| wxCalendarCtrl         | yes | yes    | ---  | --- |
| wxCheckBox             | yes | yes    | ---  | --- |
| wxCheckListBox         | yes | yes    | ---  | --- |
| wxChoice               | yes | yes    | ---  | --- |
| wxCollapsiblePane      | ??? | ???    | ---  | --- |
| wxComboBox             | yes | yes    | ---  | --- |
| wxCommandLinkButton    | yes | yes    | ---  | --- |
| wxDataViewCtrl         | yes | yes    | no   | --- |
| wxDataViewListCtrl     | yes | yes    | ---  | --- |
| wxDataViewTreeCtrl     | yes | yes    | ---  | --- |
| wxEditableListBox      | yes | yes    | ---  | --- |
| wxFileCtrl             | ??? | ???    | ---  | --- |
| wxGauge                | ??? | ???    | ---  | --- |
| wxGenericDirCtrl       | ??? | ???    | ---  | --- |
| wxGrid                 | yes | yes    | ---  | --- |
| wxHtmlWindow           | yes | yes    | ---  | --- |
| wxHyperlinkCtrl        | yes | yes    | ---  | --- |
| wxInfoBar              | ??? | ???    | ---  | --- |
| wxListBox              | yes | yes    | ---  | --- |
| wxListView             | yes | yes    | ---  | --- |
| wxMenu                 | yes | yes    | yes  | --- |
| wxMenuBar              | yes | yes    | yes  | --- |
| wxMenuItem             | yes | yes    | ---  | --- |
| wxPanel                | ??? | ???    | yes  | --- |
| wxPropertyGrid         | ??? | ???    | ---  | no  |
| wxPropertyGridManager  | yes | yes    | ---  | no  |
| wxRadioBox             | yes | yes    | ---  | --- |
| wxRadioButton          | yes | yes    | ---  | --- |
| wxRearrangeCtrl        | yes | yes    | ---  | no  |
| wxRibbonBar            | yes | yes    | ---  | --- |
| wxRibbonButtonBar      | yes | yes    | ---  | --- |
| wxRibbonGallery        | yes | yes    | ---  | --- |
| wxRibbonPage           | yes | yes    | ---  | --- |
| wxRibbonPanel          | yes | yes    | ---  | --- |
| wxRibbonToolBar        | yes | yes    | ---  | --- |
| wxRichTextCtrl         | yes | yes    | ---  | --- |
| wxScrollBar            | yes | yes    | ---  | --- |
| wxScrolled\<wxPanel\>  | ??? | ???    | ---  | --- |
| wxScrolled\<wxWindow\> | ??? | ???    | ---  | --- |
| wxSearchCtrl           | yes | yes    | ---  | --- |
| wxSimpleHtmlListBox    | ??? | ???    | ---  | --- |
| wxSlider               | ??? | ???    | ---  | --- |
| wxSpinButton           | yes | yes    | ---  | --- |
| wxSpinCtrl             | yes | yes    | ---  | --- |
| wxSpinCtrlDouble       | yes | yes    | ---  | --- |
| wxSplitterWindow       | ??? | ???    | ---  | --- |
| wxStaticBitmap         | ??? | ???    | ---  | --- |
| wxStaticBox            | ??? | ???    | ---  | --- |
| wxStaticLine           | ??? | ???    | ---  | --- |
| wxStaticText           | yes | yes    | yes  | --- |
| wxStatusBar            | yes | yes    | ---  | --- |
| wxStyledTextCtrl       | yes | yes    | ---  | --- |
| wxTextCtrl             | yes | yes    | yes  | --- |
| wxToggleButton         | yes | yes    | ---  | --- |
| wxToolBar              | yes | yes    | yes  | --- |
| wxTreeCtrl             | ??? | ???    | ---  | --- |
| wxTreeListCtrl         | ??? | ???    | ---  | no  |
| wxWebView              | ??? | ???    | ---  | no  |
| wxWizardPageSimple     | yes | yes    | ---  | --- |

# Objects

| Class                | C++ | Python | Ruby | XRC |
| -------------------- | --- | ------ | ---- | --- |
| AuiTool              | ??? | ???    | ---  | --- |
| AuiToolLabel         | ??? | ???    | ---  | --- |
| AuiToolSpacer        | ??? | ???    | ---  | --- |
| AuiToolStretchSpacer | ??? | ???    | ---  | --- |
| BookPage             | yes | yes    | ---  | --- |
| Check3State          | ??? | ???    | ---  | --- |
| CustomControl        | ??? | no     | ---  | --- |
| DataViewColumn       | ??? | ???    | ---  | --- |
| DataViewListColumn   | ??? | ???    | ---  | --- |
| NewCloseButton       | ??? | ???    | ---  | --- |
| PageCtrl             | ??? | ???    | ---  | no  |
| PropertyGridItem     | yes | yes    | ---  | no  |
| PropertyGridPage     | yes | yes    | ---  | no  |
| RibbonButton         | yes | yes    | ---  | --- |
| RibbonGalleryItem    | yes | yes    | ---  | --- |
| RibbonTool           | yes | yes    | ---  | --- |
| Separator            | ??? | ???    | ---  | --- |
| Spacer               | ??? | ???    | ---  | --- |
| SubMenu              | ??? | ???    | ---  | --- |
| ToolDropDown         | ??? | ???    | ---  | --- |
| ToolGenerator        | ??? | ???    | ---  | --- |
| ToolSeparator        | ??? | ???    | ---  | --- |
| ToolStretchable      | ??? | ???    | ---  | --- |
| TreeListCtrlColumn   | ??? | ???    | ---  | no  |
| wxContextMenuEvent   | ??? | no     | ---  | no  |
