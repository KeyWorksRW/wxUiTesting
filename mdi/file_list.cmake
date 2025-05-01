set (sdi_test_dir ${CMAKE_CURRENT_LIST_DIR})

# wxui_code.cmake

set (file_list

    cpp/mdi_test.rc
    cpp/mainapp.cpp

    cpp/classes/canvas.cpp
    cpp/classes/drawing_document.cpp
    cpp/classes/drawing_view.cpp
    cpp/classes/image_document.cpp
    cpp/classes/image_view.cpp
    cpp/classes/text_document.cpp
    cpp/classes/textctrl_view.cpp

)

# Currently, these are not used in CMakeLists.txt, it's just a reference to which python files
# are being generated.

set (mdi_perl_files


)

set (mdi_python_files


)

set (mdi_ruby_files


)

# These aren't actually used in CMAkeLists.txt, they are here just to provide a quick way to
# load them into an IDE that supports loading a file from the filenmae underneath the cursor.

set (sdi_other_files

    ../README.md

    run_cpp_build.cmd
    run_pytest.cmd
    run_ruby_test.cmd

)
