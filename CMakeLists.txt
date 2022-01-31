cmake_minimum_required(VERSION 3.20)

project(wxUiTesting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    # /O1 often results in faster code than /O2 due to CPU caching
    string(REPLACE "/O2" "/O1" cl_optimize ${CMAKE_CXX_FLAGS_RELEASE})
    set(CMAKE_CXX_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C++ Release flags" FORCE)

    # Using /Z7 instead of /Zi to avoid blocking while parallel compilers write to the pdb file.
    # This can considerably speed up build times at the cost of larger object files.
    string(REPLACE "/Zi" "/Z7" z_seven ${CMAKE_CXX_FLAGS_DEBUG})
    set(CMAKE_CXX_FLAGS_DEBUG ${z_seven} CACHE STRING "C++ Debug flags" FORCE)
endif()

get_property(isMultiConfig GLOBAL
  PROPERTY GENERATOR_IS_MULTI_CONFIG
)

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

# This will build wxCLib.lib and wxWidgets.lib
add_subdirectory(wxSnapshot)

add_compile_definitions($<$<CONFIG:Release>:NDEBUG>)

include(src/ui/wxui_code.cmake)  # This will set ${wxue_generated_code} with list of generated files

add_executable(wxUiTesting WIN32
    src/wxUiTesting.rc
    src/mainapp.cpp

    src/import_test.cpp   # Import Test Dialog

    src/imports/form_base.cpp
    src/imports/import_form_base.cpp

    src/custom_ctrls/split_button.cpp  # Split Button Custom widget (button + menu)

    src/ui/mainframe.cpp       # Main window
    src/ui/mainframe_base.cpp  # wxUiEditor generated file

    src/ui/commonctrls.cpp
    src/ui/dlgmultitest.cpp
    src/ui/other_ctrls.cpp
    src/ui/popupwin.cpp
    src/ui/ribbondlg.cpp
    src/ui/wizard.cpp

    ${wxue_generated_code}

)

# This is just used by a github action to confirm that all the source code can be compiled
add_library(check_build STATIC EXCLUDE_FROM_ALL
    ${file_list}
    ${wxue_generated_code}
)

if (WIN32)
    target_link_libraries(wxUiTesting PRIVATE wxWidgets wxCLib comctl32 Imm32 Shlwapi Version UxTheme)
else()
    target_link_libraries(wxUiTesting PRIVATE wxWidgets wxCLib)
endif()

if (MSVC)
    # /GL -- combined with the Linker flag /LTCG to perform whole program optimization in Release build
    # /FC -- Full path to source code file in diagnostics
    target_compile_options(wxUiTesting PRIVATE "$<$<CONFIG:Release>:/GL>" "/FC" "/W4" "/Zc:__cplusplus" "/utf-8")
    target_link_options(wxUiTesting PRIVATE "$<$<CONFIG:Release>:/LTCG>")

    target_link_options(wxUiTesting PRIVATE "$<$<CONFIG:Debug>:/natvis:${CMAKE_CURRENT_LIST_DIR}/src/wxtesting.natvis>")

    # Assume the manifest is in the resource file
    target_link_options(wxUiTesting PRIVATE "/manifest:no")
endif()

target_precompile_headers(wxUiTesting PRIVATE "src/pch.h")
target_precompile_headers(check_build PRIVATE "src/pch.h")

if (WIN32)
    set(setup_dir wxSnapshot/win)
endif()

target_include_directories(wxUiTesting PRIVATE
    wxSnapshot/include
    ${setup_dir}
    src/
    src/ui
)

target_include_directories(check_build PRIVATE
    wxSnapshot/include
    ${setup_dir}
    src/
    src/ui
)
