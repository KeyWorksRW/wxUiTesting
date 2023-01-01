set (file_list_dir wxui_generated)

set (file_list

    wxUiTesting.rc
    mainapp.cpp

    import_test.cpp   # Import Test Dialog

    imports/form_base.cpp
    imports/import_form_base.cpp
    imports/crafter_base.cpp
    imports/crafter_bitmaps.cpp
    imports/import_crafter_base.cpp
    imports/import_crafter_base.cpp

    custom_ctrls/split_button.cpp  # Split Button Custom widget (button + menu)

    ui/commonctrls.cpp
    ui/dlgmultitest.cpp
    ui/mainframe.cpp
    ui/other_ctrls.cpp
    ui/popupwin.cpp
    ui/ribbondlg.cpp
    ui/wizard.cpp

)

# Manually maintained from wxui_generated/wxui_generated.cmake
set(wxui_file_list

    wxui/choicebook_base.cpp
    wxui/commonctrls_base.cpp
    wxui/dlgmultitest_base.cpp
    wxui/form_toolbar_base.cpp
    wxui/import_test_base.cpp
    wxui/listbook_base.cpp
    wxui/mainframe_base.cpp
    wxui/my_images.cpp
    wxui/notebook_base.cpp
    wxui/other_ctrls_base.cpp
    wxui/popupwin_base.cpp
    wxui/python_dlg.cpp
    wxui/ribbondlg_base.cpp
    wxui/toolbook_base.cpp
    wxui/treebook_base.cpp
    wxui/wizard_base.cpp

)

set (python_files

    main.py

    mainframe.py
    mainframe_base.py
    python_dlg.py

)
