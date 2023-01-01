set (file_list_dir ${CMAKE_CURRENT_LIST_DIR})

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

set (python_files

    main.py

    mainframe.py
    mainframe_base.py
    python_dlg.py

)
