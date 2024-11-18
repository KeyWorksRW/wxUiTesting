set (sdi_test_dir ${CMAKE_CURRENT_LIST_DIR})

set (file_list

    cpp/cpptest.rc
    cpp/mainapp.cpp

    cpp/custom_ctrls/split_button.cpp  # Split Button Custom widget (button + menu)

)

# Manually maintained from wxui_code.cmake
set(sdi_wxui_file_list

    cpp/bitmaps_dlg.cpp
    cpp/bitmaps_dlg_manual.cpp
    cpp/booktest_dlg.cpp
    cpp/choicebook.cpp
    cpp/commonctrls.cpp
    cpp/data_dlg.cpp
    cpp/dlgissue_956.cpp
    cpp/dlgissue_960.cpp
    cpp/dlgmultitest.cpp
    cpp/formpaneltest_base.cpp
    cpp/form_toolbar_base.cpp
    cpp/images.cpp
    cpp/import_test.cpp
    cpp/listbook.cpp
    cpp/mainapp.cpp
    cpp/mainframe.cpp
    cpp/maintestdialog.cpp
    cpp/mypanel_base.cpp
    cpp/notebook.cpp
    cpp/other_ctrls.cpp
    cpp/popupwin.cpp
    cpp/propsheet_base.cpp
    cpp/python_dlg.cpp
    cpp/ribbondlg.cpp
    cpp/testformpanel.cpp
    cpp/toolbook.cpp
    cpp/tools_dlg.cpp
    cpp/treebook.cpp
    cpp/wizard.cpp

)

# Currently, these are not used in CMakeLists.txt, it's just a reference to which python files
# are being generated.

set (sdi_python_files

    python/bitmaps_dlg.py
    python/booktest_dlg.py
    python/dlgissue_956.py
    python/dlgissue_960.py
    python/images.py
    python/mainframe.py
    python/main_test_dlg.py
    python/popupwin.py
    python/propsheet.py
    python/python_dlg.py
    python/testformpanel.py
    python/tools_dlg.py
    python/wizard.py

)

set (sdi_ruby_files

    ruby/bitmaps_dlg.rb
    ruby/booktest_dlg.rb
    ruby/data_dlg.rb
    ruby/dlgissue_956.rb
    ruby/dlgissue_960.rb
    ruby/images.rb
    ruby/mainframe.rb
    ruby/main_test_dlg.rb
    ruby/propsheet.rb
    ruby/python_dlg.rb
    ruby/tools_dlg.rb
    ruby/wizard.rb

)

# These aren't actually used in CMAkeLists.txt, they are here just to provide a quick way to
# load them into an IDE that supports loading a file from the filenmae underneath the cursor.

set (sdi_other_files

    COVERAGE.md
    ../README.md

    run_cpp_build.cmd
    run_pytest.cmd
    run_ruby_test.cmd

    cpp/derived_classes/drv_menubar.h
    cpp/derived_classes/drv_statusbar.h
    cpp/derived_classes/drv_frame.h
    cpp/derived_classes/drv_panel.h
    cpp/derived_classes/drv_wizard.h
    cpp/derived_classes/drv_toolbar.h

)
