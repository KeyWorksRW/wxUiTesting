cmake_minimum_required(VERSION 3.20)

project(samples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

####################### Options #######################

# creates a compile_commands.json file in the build directory, suitable for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_SHARED_LIBS "Build with wxWidgets shared libraries" ON)

if (BUILD_SHARED_LIBS)
    message(NOTICE "Building with wxWidgets shared libraries")
else()
    message(NOTICE "Building with wxWidgets static libraries")
endif()

set(BUILD_ROOT ${CMAKE_CURRENT_LIST_DIR}/../../wxWidgets33 CACHE PATH "${CMAKE_CURRENT_LIST_DIR}/../../wxWidgets33" FORCE)
set(WIDGETS_LIB ${CMAKE_CURRENT_LIST_DIR}/../../wxWidgets33)

message(NOTICE "wxWidgets lib: ${WIDGETS_LIB}")
message(NOTICE "BUILD_ROOT: ${BUILD_ROOT}")
message(NOTICE "Building into ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} using ${WIDGETS_LIB}")

####################### Check for Multi-Config Generator #######################

get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if (NOT isMultiConfig)
    message("\nBecause you are using a single target generator, you MUST specify")
    message("    a \"--config [Debug|Release]\" option with the cmake --build command\n")

    set(allowedBuildTypes Debug Release)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${allowedBuildTypes}")

    if (NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
    elseif (NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
        message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
    endif()
endif()

get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if (NOT isMultiConfig)
    message("\nBecause you are using a single target generator, you MUST specify")
    message("    a \"--config [Debug|Release]\" option with the cmake --build command\n")

    set(allowedBuildTypes Debug Release)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${allowedBuildTypes}")

    if (NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
    elseif (NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
        message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
    endif()
endif()

include_directories(
    ${BUILD_ROOT}/include
    ${setup_dir}
    ${CMAKE_CURRENT_LIST_DIR}/
)

link_directories(
    $<$<CONFIG:Debug>:${BUILD_ROOT}/build/Debug>
    $<$<CONFIG:Release>:${BUILD_ROOT}/build/Release>
)

if (MSVC)
    # /O1 often results in faster code than /O2 due to CPU caching
    string(REPLACE "/O2" "/O1" cl_optimize ${CMAKE_CXX_FLAGS_RELEASE})
    set(CMAKE_CXX_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C++ Release flags" FORCE)

    # Using /Z7 instead of /Zi to avoid blocking while parallel compilers write to the pdb file.
    # This can considerably speed up build times at the cost of larger object files.
    string(REPLACE "/Zi" "/Z7" z_seven ${CMAKE_CXX_FLAGS_DEBUG})
    set(CMAKE_CXX_FLAGS_DEBUG ${z_seven} CACHE STRING "C++ Debug flags" FORCE)
else()
    # Use the package PkgConfig to detect GTK+ headers/library files
    find_package(PkgConfig REQUIRED)

    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    include_directories(${GTK3_INCLUDE_DIRS})
    link_directories(${GTK3_LIBRARY_DIRS})
    add_definitions(${GTK3_CFLAGS_OTHER})

    pkg_check_modules(X11 REQUIRED x11)
    include_directories(${X11_INCLUDE_DIRS})
    link_directories(${X11_LIBRARY_DIRS})
    add_definitions(${X11_CFLAGS_OTHER})

    # This should work for gcc and clang (including xcode which is based on clang)
    # -O2 can result in faster code than -O3 due to CPU caching.
    string(REPLACE "-O3" "-O2" cl_optimize "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C++ Release flags" FORCE)
endif()

####################### Set wxWidgets location macros #######################

if (WIN32)
    set(setup_dir ${BUILD_ROOT}/win)
else()
    set(setup_dir ${BUILD_ROOT}/unix)
endif()

set(compiler_defs
    WXUSINGDLL
    wxUSE_UNICODE_UTF8=1
    wxUSE_UTF8_LOCALE_ONLY=1
)

####################### Libraries and Executables #######################

add_executable(animate WIN32 ${CMAKE_CURRENT_LIST_DIR}/animate/anitest.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(archive WIN32 ${CMAKE_CURRENT_LIST_DIR}/archive/archive.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)

add_executable(artprov WIN32
    ${CMAKE_CURRENT_LIST_DIR}/artprov/arttest.cpp
    ${CMAKE_CURRENT_LIST_DIR}/artprov/artbrows.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sample.rc
)

add_executable(aui WIN32 ${CMAKE_CURRENT_LIST_DIR}/aui/auidemo.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(calendar WIN32 ${CMAKE_CURRENT_LIST_DIR}/calendar/calendar.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(caret WIN32 ${CMAKE_CURRENT_LIST_DIR}/caret/caret.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(clipboard WIN32 ${CMAKE_CURRENT_LIST_DIR}/clipboard/clipboard.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(collpane WIN32 ${CMAKE_CURRENT_LIST_DIR}/collpane/collpane.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(combo WIN32 ${CMAKE_CURRENT_LIST_DIR}/combo/combo.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(console WIN32 ${CMAKE_CURRENT_LIST_DIR}/console/console.cpp)

add_executable(dataview WIN32
    ${CMAKE_CURRENT_LIST_DIR}/dataview/dataview.cpp
    ${CMAKE_CURRENT_LIST_DIR}/dataview/mymodels.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sample.rc
)

add_executable(debugrpt WIN32 ${CMAKE_CURRENT_LIST_DIR}/debugrpt/debugrpt.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(dialogs WIN32 ${CMAKE_CURRENT_LIST_DIR}/dialogs/dialogs.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(display WIN32 ${CMAKE_CURRENT_LIST_DIR}/display/display.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)

add_executable(dnd WIN32
    ${CMAKE_CURRENT_LIST_DIR}/dnd/dnd.cpp
    ${CMAKE_CURRENT_LIST_DIR}/dnd/dnd.rc
)

add_executable(docview WIN32
    ${CMAKE_CURRENT_LIST_DIR}/docview/doc.cpp
    ${CMAKE_CURRENT_LIST_DIR}/docview/docview.cpp
    ${CMAKE_CURRENT_LIST_DIR}/docview/view.cpp
    ${CMAKE_CURRENT_LIST_DIR}/docview/docview.rc
)

add_executable(dragimag WIN32
    ${CMAKE_CURRENT_LIST_DIR}/dragimag/dragimag.cpp
    ${CMAKE_CURRENT_LIST_DIR}/dragimag/dragimag.rc
)

add_executable(drawing WIN32 ${CMAKE_CURRENT_LIST_DIR}/drawing/drawing.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(erase WIN32 ${CMAKE_CURRENT_LIST_DIR}/erase/erase.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(griddemo WIN32 ${CMAKE_CURRENT_LIST_DIR}/grid/griddemo.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(menu WIN32 ${CMAKE_CURRENT_LIST_DIR}/menu/menu.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)

add_executable(event WIN32
    ${CMAKE_CURRENT_LIST_DIR}/event/event.cpp
    ${CMAKE_CURRENT_LIST_DIR}/event/chessboard.cpp
    ${CMAKE_CURRENT_LIST_DIR}/event/gestures.cpp
)

add_executable(notebook WIN32 ${CMAKE_CURRENT_LIST_DIR}/notebook/notebook.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)

add_executable(propgrid WIN32
    ${CMAKE_CURRENT_LIST_DIR}/propgrid/propgrid.cpp
    ${CMAKE_CURRENT_LIST_DIR}/propgrid/propgrid_minimal.cpp
    ${CMAKE_CURRENT_LIST_DIR}/propgrid/sampleprops.cpp
)

add_executable(richtext WIN32 ${CMAKE_CURRENT_LIST_DIR}/richtext/richtext.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)
add_executable(splitter WIN32 ${CMAKE_CURRENT_LIST_DIR}/splitter/splitter.cpp ${CMAKE_CURRENT_LIST_DIR}/sample.rc)

add_executable(svgtest WIN32
    ${CMAKE_CURRENT_LIST_DIR}/svg/svgtest.cpp
    ${CMAKE_CURRENT_LIST_DIR}/svg/svgtest.rc
)

add_executable(widgets WIN32
    ${CMAKE_CURRENT_LIST_DIR}/widgets/activityindicator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/bmpcombobox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/button.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/checkbox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/choice.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/clrpicker.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/combobox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/datepick.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/dirctrl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/dirpicker.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/editlbox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/filectrl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/filepicker.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/fontpicker.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/gauge.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/headerctrl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/hyperlnk.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/itemcontainer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/listbox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/native.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/notebook.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/odcombobox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/radiobox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/searchctrl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/slider.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/spinbtn.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/statbmp.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/static.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/textctrl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/timepick.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/toggle.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgets/widgets.cpp
)

add_executable(xrcdemo WIN32
    ${CMAKE_CURRENT_LIST_DIR}/xrc/custclas.cpp
    ${CMAKE_CURRENT_LIST_DIR}/xrc/derivdlg.cpp
    ${CMAKE_CURRENT_LIST_DIR}/xrc/myframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/xrc/objrefdlg.cpp
    ${CMAKE_CURRENT_LIST_DIR}/xrc/xrcdemo.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sample.rc
)

target_compile_definitions(animate PRIVATE ${compiler_defs})
target_compile_definitions(archive PRIVATE ${compiler_defs})
target_compile_definitions(artprov PRIVATE ${compiler_defs})
target_compile_definitions(aui PRIVATE ${compiler_defs})
target_compile_definitions(calendar PRIVATE ${compiler_defs})
target_compile_definitions(caret PRIVATE ${compiler_defs})
target_compile_definitions(clipboard PRIVATE ${compiler_defs})
target_compile_definitions(collpane PRIVATE ${compiler_defs})
target_compile_definitions(combo PRIVATE ${compiler_defs})
target_compile_definitions(console PRIVATE ${compiler_defs})
target_compile_definitions(dataview PRIVATE ${compiler_defs})
target_compile_definitions(debugrpt PRIVATE ${compiler_defs})
target_compile_definitions(dialogs PRIVATE ${compiler_defs})
target_compile_definitions(display PRIVATE ${compiler_defs})
target_compile_definitions(dnd PRIVATE ${compiler_defs})
target_compile_definitions(docview PRIVATE ${compiler_defs})
target_compile_definitions(dragimag PRIVATE ${compiler_defs})
target_compile_definitions(drawing PRIVATE ${compiler_defs})
target_compile_definitions(event PRIVATE ${compiler_defs})
target_compile_definitions(erase PRIVATE ${compiler_defs})
target_compile_definitions(griddemo PRIVATE ${compiler_defs})
target_compile_definitions(menu PRIVATE ${compiler_defs})
target_compile_definitions(notebook PRIVATE ${compiler_defs})
target_compile_definitions(propgrid PRIVATE ${compiler_defs})
target_compile_definitions(richtext PRIVATE ${compiler_defs})
target_compile_definitions(splitter PRIVATE ${compiler_defs})
target_compile_definitions(svgtest PRIVATE ${compiler_defs})
target_compile_definitions(widgets PRIVATE ${compiler_defs})
target_compile_definitions(xrcdemo PRIVATE ${compiler_defs})

target_precompile_headers(animate PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(archive PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(artprov PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(aui PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(calendar PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(caret PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(clipboard PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(collpane PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(combo PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(console PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(dataview PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(debugrpt PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(dialogs PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(display PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(dnd PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(docview PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(dragimag PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(drawing PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(event PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(erase PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(griddemo PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(menu PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(notebook PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(propgrid PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(richtext PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(splitter PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(svgtest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(widgets PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)
target_precompile_headers(xrcdemo PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include/wx/wxprec.h)

target_include_directories(animate PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/animate)
target_include_directories(archive PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/archive)
target_include_directories(artprov PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/artprov)
target_include_directories(aui PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/aui)
target_include_directories(calendar PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/calendar)
target_include_directories(caret PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/caret)
target_include_directories(clipboard PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/clipboard)
target_include_directories(collpane PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/collpane)
target_include_directories(combo PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/combo)
target_include_directories(console PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/console)
target_include_directories(dataview PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/dataview)
target_include_directories(debugrpt PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/debugrpt)
target_include_directories(dialogs PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/dialogs)
target_include_directories(display PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/display)
target_include_directories(dnd PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/dnd)
target_include_directories(docview PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/docview)
target_include_directories(dragimag PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/display)
target_include_directories(drawing PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/drawing)
target_include_directories(erase PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/erase)
target_include_directories(event PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/event)
target_include_directories(griddemo PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/griddemo)
target_include_directories(menu PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/menu)
target_include_directories(notebook PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/notebook)
target_include_directories(propgrid PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/propgrid)
target_include_directories(richtext PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/richtext)
target_include_directories(splitter PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/splitter)
target_include_directories(svgtest PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/svgtest)
target_include_directories(widgets PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/widgets)
target_include_directories(xrcdemo PRIVATE ${setup_dir} ${CMAKE_CURRENT_LIST_DIR}/xrcdemo)

if (UNIX)
    set(SYSTEM_LIBS
        ${GTK3_LIBRARIES}
        ${X11_LIBRARIES}
        pthread
        dl
        png
        GL
        GLX
    )
endif()

if (WIN32)
    target_link_libraries(animate PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(archive PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(artprov PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(aui PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(calendar PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(caret PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(clipboard PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(collpane PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(combo PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(console PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(dataview PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(debugrpt PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(dialogs PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(display PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(dnd PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(docview PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(dragimag PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(drawing PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(erase PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(event PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(griddemo PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(menu PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(notebook PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(propgrid PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(richtext PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(splitter PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(svgtest PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(widgets PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
    target_link_libraries(xrcdemo PRIVATE wxWidgets33 wxCLib kernel32 user32 gdi32 comctl32 comdlg32 shell32 rpcrt4 advapi32)
else()
    target_link_libraries(animate PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(archive PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(artprov PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(aui PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(calendar PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(caret PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(clipboard PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(collpane PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(combo PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(console PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(dataview PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(debugrpt PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(dialogs PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(display PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(dnd PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(docview PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(dragimag PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(drawing PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(erase PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(event PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(griddemo PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(menu PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(notebook PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(propgrid PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(richtext PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(splitter PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(svgtest PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(widgets PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
    target_link_libraries(xrcdemo PRIVATE wxWidgets33 ${SYSTEM_LIBS} wxCLib)
endif()

target_compile_options(archive PRIVATE "/DwxUSE_GUI=0")
target_compile_options(console PRIVATE "/DwxUSE_GUI=0")
