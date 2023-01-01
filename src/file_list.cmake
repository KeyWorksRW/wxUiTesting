set (file_list_dir src)

set (file_list

    wxUiTesting.rc
    mainapp.cpp

    imports/form_base.cpp
    imports/import_form_base.cpp
    imports/crafter_base.cpp
    imports/crafter_bitmaps.cpp
    imports/import_crafter_base.cpp
    imports/import_crafter_base.cpp

    custom_ctrls/split_button.cpp  # Split Button Custom widget (button + menu)

    ui/mainframe.cpp

)

# Manually maintained from wxui/wxui_generated.cmake
set(wxui_file_list

    wxui/choicebook.cpp
    wxui/commonctrls.cpp
    wxui/dlgmultitest.cpp
    wxui/form_toolbar_base.cpp
    wxui/import_test.cpp
    wxui/listbook.cpp
    wxui/mainframe_base.cpp
    wxui/my_images.cpp
    wxui/notebook.cpp
    wxui/other_ctrls.cpp
    wxui/popupwin.cpp
    wxui/python_dlg.cpp
    wxui/ribbondlg.cpp
    wxui/toolbook.cpp
    wxui/treebook.cpp
    wxui/wizard.cpp

)

set (python_files

    main.py

    mainframe.py
    mainframe_base.py
    python_dlg.py

)
