# Contents

The following tables indicate whether or not code is being generated in a specific language. A "???" or "---" indicates it has not been verified. "no" indcates that the language doesn't support it. `partial` means that not all properties for the control are supported.

This does _not_ mean that the class is fully supported in every language -- this is just a guide to indicate whether or not it is at least partially implemented in the various languages.

# Categories

### Books

| Class         | C++ | Python | Ruby | XRC |
| ------------- | --- | ------ | ---- | --- |
| wxAuiNotebook | yes | yes    | yes  | --- |
| wxChoicebook  | yes | yes    | yes  | --- |
| wxListbook    | yes | yes    | yes  | --- |
| wxNotebook    | yes | yes    | yes  | --- |
| wxSimplebook  | yes | yes    | yes  | --- |
| wxToolbook    | yes | yes    | yes  | --- |
| wxTreebook    | yes | yes    | yes  | yes |

### Forms

| Class                  | C++ | Python | Ruby | XRC |
| ---------------------- | --- | ------ | ---- | --- |
| wxDialog               | yes | yes    | yes  | yes |
| wxFrame                | yes | yes    | yes  | yes |
| wxMenu                 | yes | yes    | yes  | --- |
| wxMenuBar              | yes | yes    | yes  | --- |
| wxPanel                | yes | yes    | yes  | --- |
| wxPopupTransientWindow | yes | yes    | yes  | no  |
| wxRibbonBar            | yes | yes    | yes  | --- |
| wxToolBar              | yes | yes    | yes  | --- |
| wxWizard               | yes | yes    | yes  | yes |

### Pickers

| Class              | C++ | Python | Ruby | XRC |
| ------------------ | --- | ------ | ---- | --- |
| wxColourPickerCtrl | yes | yes    | yes  | yes |
| wxDatePickerCtrl   | yes | yes    | yes  | yes |
| wxDirPickerCtrl    | yes | yes    | yes  | yes |
| wxFilePickerCtrl   | yes | yes    | yes  | yes |
| wxFontPickerCtrl   | yes | yes    | yes  | yes |
| wxTimePickerCtrl   | yes | yes    | yes  | yes |

### Sizers

| Class                    | C++ | Python | Ruby | XRC     |
| ------------------------ | --- | ------ | ---- | ------- |
| wxBoxSizer               | yes | yes    | yes  | yes     |
| wxCheckBoxSizer          | yes | no     | yes  | ---     |
| wxFlexGridSizer          | yes | yes    | yes  | yes     |
| wxGridBagSizer           | yes | yes    | yes  | yes     |
| wxGridSizer              | yes | yes    | yes  | yes     |
| wxStaticRadioBtnBoxSizer | yes | no     | yes  | ---     |
| wxStaticBoxSizer         | yes | yes    | yes  | yes     |
| wxStdDialogButtonSizer   | yes | yes    | yes  | partial |
| wxWrapSizer              | yes | yes    | yes  | yes     |

# Classes

| Class                  | C++ | Python  | Ruby | XRC     |
| ---------------------- | --- | ------- | ---- | ------- |
| wxActivityIndicator    | yes | yes     | yes  | yes     |
| wxAnimationCtrl        | yes | ???     | yes  | ---     |
| wxAuiToolBar           | yes | yes     | yes  | yes     |
| wxBannerWindow         | yes | yes     | yes  | yes     |
| wxBitmapComboBox       | ??? | ???     | ???  | ---     |
| wxButton               | yes | yes     | yes  | partial |
| wxCalendarCtrl         | yes | yes     | yes  | yes     |
| wxCheckBox             | yes | yes     | yes  | yes     |
| wxCheckListBox         | yes | yes     | yes  | yes     |
| wxChoice               | yes | yes     | yes  | yes     |
| wxCollapsiblePane      | yes | yes     | yes  | yes     |
| wxComboBox             | yes | yes     | yes  | yes     |
| wxCommandLinkButton    | yes | yes     | yes  | yes     |
| wxDataViewCtrl         | yes | yes     | no   | no      |
| wxDataViewListCtrl     | yes | yes     | no   | no      |
| wxDataViewTreeCtrl     | yes | yes     | no   | no      |
| wxEditableListBox      | yes | yes     | yes  | yes     |
| wxFileCtrl             | yes | yes     | yes  | yes     |
| wxGauge                | yes | yes     | yes  | ---     |
| wxGenericDirCtrl       | yes | partial | yes  | partial |
| wxGrid                 | yes | yes     | yes  | no      |
| wxHtmlWindow           | yes | yes     | yes  | yes     |
| wxHyperlinkCtrl        | yes | yes     | yes  | yes     |
| wxInfoBar              | yes | ???     | ???  | yes     |
| wxListBox              | yes | yes     | yes  | yes     |
| wxListView             | yes | yes     | yes  | partial |
| wxMenu                 | yes | yes     | yes  | ---     |
| wxMenuBar              | yes | yes     | yes  | ---     |
| wxMenuItem             | yes | yes     | yes  | ---     |
| wxPanel                | yes | yes     | yes  | ---     |
| wxPropertyGrid         | yes | yes     | yes  | no      |
| wxPropertyGridManager  | yes | yes     | yes  | no      |
| wxPropertySheetDialog  | no  | no      | no   | no      |
| wxRadioBox             | yes | yes     | yes  | yes     |
| wxRadioButton          | yes | yes     | yes  | yes     |
| wxRearrangeCtrl        | yes | yes     | yes  | no      |
| wxRibbonBar            | yes | yes     | yes  | ---     |
| wxRibbonButtonBar      | yes | yes     | yes  | ---     |
| wxRibbonGallery        | yes | yes     | yes  | ---     |
| wxRibbonPage           | yes | yes     | yes  | ---     |
| wxRibbonPanel          | yes | yes     | yes  | ---     |
| wxRibbonToolBar        | yes | yes     | yes  | ---     |
| wxRichTextCtrl         | yes | yes     | yes  | yes     |
| wxScrollBar            | yes | yes     | yes  | yes     |
| wxScrolled\<wxPanel\>  | yes | yes     | yes  | ---     |
| wxScrolled\<wxWindow\> | yes | yes     | yes  | ---     |
| wxSearchCtrl           | yes | yes     | yes  | yes     |
| wxSimpleHtmlListBox    | yes | yes     | yes  | yes     |
| wxSlider               | yes | yes     | yes  | yes     |
| wxSpinButton           | yes | yes     | yes  | yes     |
| wxSpinCtrl             | yes | yes     | yes  | yes     |
| wxSpinCtrlDouble       | yes | yes     | yes  | yes     |
| wxSplitterWindow       | yes | yes     | yes  | yes     |
| wxStaticBitmap         | yes | yes     | yes  | yes     |
| wxStaticBox            | yes | ???     | ---  | ---     |
| wxStaticLine           | yes | yes     | yes  | yes     |
| wxStaticText           | yes | yes     | yes  | yes     |
| wxStatusBar            | yes | yes     | yes  | yes     |
| wxStyledTextCtrl       | yes | partial | yes  | partial |
| wxTextCtrl             | yes | yes     | yes  | yes     |
| wxToggleButton         | yes | yes     | yes  | partial |
| wxToolBar              | yes | yes     | yes  | yes     |
| wxTreeCtrl             | yes | yes     | yes  | yes     |
| wxTreeListCtrl         | yes | yes     | no   | no      |
| wxWebView              | yes | yes     | no   | no      |
| wxWizardPageSimple     | yes | yes     | yes  | yes     |

# Objects

| Class                | C++ | Python | Ruby | XRC |
| -------------------- | --- | ------ | ---- | --- |
| AuiTool              | yes | yes    | yes  | yes |
| AuiToolLabel         | yes | yes    | yes  | yes |
| AuiToolSpacer        | yes | yes    | yes  | yes |
| AuiToolStretchSpacer | yes | yes    | yes  | yes |
| BookPage             | yes | yes    | yes  | yes |
| Check3State          | yes | ???    | ---  | --- |
| CustomControl        | yes | no     | ---  | --- |
| DataViewColumn       | yes | yes    | no   | no  |
| DataViewListColumn   | yes | ???    | ---  | --- |
| NewCloseButton       | yes | yes    | yes  | yes |
| PageCtrl             | yes | ???    | ---  | no  |
| PropertyGridItem     | yes | yes    | ---  | no  |
| PropertyGridPage     | yes | yes    | ---  | no  |
| RibbonButton         | yes | yes    | yes  | --- |
| RibbonGalleryItem    | yes | yes    | yes  | --- |
| RibbonTool           | yes | yes    | yes  | --- |
| Separator            | yes | ???    | ---  | --- |
| Spacer               | yes | ???    | ---  | --- |
| SubMenu              | yes | ???    | ---  | --- |
| ToolDropDown         | yes | ???    | ---  | --- |
| ToolGenerator        | yes | ???    | ---  | --- |
| ToolSeparator        | yes | ???    | ---  | --- |
| ToolStretchable      | yes | ???    | ---  | --- |
| TreeListCtrlColumn   | yes | ???    | ---  | no  |
| wxContextMenuEvent   | yes | no     | ---  | no  |

# Special Notes:

Neither wxPython or XRC support setting the initial folder in wxGenericDirCtrl, though it works fine in wxRuby3

# Python unsupported

- CheckBoxSizer
- RadioBoxSizer
- wxTreeListCtrl

# Ruby unsupported

- wxBannerWindow
- wxInfoBar
- wxRearrangeCtrl
- wxSpinCtrlDouble
- wxWebView
- wxWrapSizer
- wxCommandLinkButton

- wxDataViewListCtrl
- wxDataViewCtrl
- DataViewColumn
- DataViewListColumn
- wxTreeListCtrl
