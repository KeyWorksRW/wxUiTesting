set (file_list

    ${CMAKE_CURRENT_LIST_DIR}/wxUiTesting.rc
    ${CMAKE_CURRENT_LIST_DIR}/mainapp.cpp

    ${CMAKE_CURRENT_LIST_DIR}/import_test.cpp   # Import Test Dialog

    ${CMAKE_CURRENT_LIST_DIR}/imports/form_base.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imports/import_form_base.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imports/crafter_base.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imports/crafter_bitmaps.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imports/import_crafter_base.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imports/import_crafter_base.cpp

    ${CMAKE_CURRENT_LIST_DIR}/custom_ctrls/split_button.cpp  # Split Button Custom widget (button + menu)

    ${CMAKE_CURRENT_LIST_DIR}/ui/commonctrls.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/dlgmultitest.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/mainframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/other_ctrls.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/popupwin.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/ribbondlg.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/wizard.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ui/python_dlg.cpp

)
