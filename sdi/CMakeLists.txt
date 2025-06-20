cmake_minimum_required(VERSION 3.20)

project(sdi_test LANGUAGES CXX)
project(sdi_test
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "SDI Test"
    HOMEPAGE_URL "https://github.com/KeyWorksRW/wxUiEditor")

####################### Options #######################

# creates a compile_commands.json file in the build directory, suitable for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_SHARED_LIBS "Build with wxWidgets shared libraries" ON)

if (BUILD_SHARED_LIBS)
    message(NOTICE "Building with wxWidgets shared libraries")
else()
    message(NOTICE "Building with wxWidgets static libraries")
endif()

# This option is designed to make it possible to check changes to a wxWidgets fork, and/or to
# build with the current wxWidgets sources (assuming the wxWidgets fork is in sync).
# Realistically, this is only going to be usable by the maintainers of this project.

option(BUILD_33 "Builds wxWidgets using wxWidgets33")

if (BUILD_33)
    set(BUILD_ROOT ${CMAKE_CURRENT_LIST_DIR}/../wxWidgets33 CACHE PATH "${CMAKE_CURRENT_LIST_DIR}/../wxWidgets33" FORCE)
    set(WIDGETS_LIB wxWidgets33)
else()
    set(BUILD_ROOT ${CMAKE_CURRENT_LIST_DIR}/../wxWidgets32 CACHE PATH "${CMAKE_CURRENT_LIST_DIR}/../wxWidgets32" FORCE)
    set(WIDGETS_LIB wxWidgets32)
endif()

if (NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_ROOT}/build)
endif()

message(NOTICE "wxWidgets lib: ${WIDGETS_LIB}")
message(NOTICE "BUILD_ROOT: ${BUILD_ROOT}")
message(NOTICE "Building into ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} using ${WIDGETS_LIB}")

option(INTERNAL_DARK_MODE "Enable dark mode (used with wxWidgets 3.3 in _WIN32 builds)" OFF)
option(INTERNAL_DARK_HIGH_CONTRAST "Enable dark mode high contrast (used with wxWidgets 3.3 in _WIN32 builds)" OFF)

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

####################### General Settings #######################

set(CMAKE_CXX_STANDARD 14)
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

    # Use static runtime for Release builds to run with Wine without needing to install the dlls
    if (NOT BUILD_SHARED_LIBS)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()
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

add_compile_definitions($<$<CONFIG:Release>:NDEBUG>)

####################### Set wxWidgets location macros #######################

if (WIN32)
    set(setup_dir ${BUILD_ROOT}/win)
else()
    set(setup_dir ${BUILD_ROOT}/unix)
endif()

####################### Libraries and Executables #######################

# Setting CMAKE_MODULE_PATH causes ninja to fail rebuilding until CMake re-generates. Specifying the full path and extension
# means ninja sees this as a normal dependency that didn't change any time one of the files it specifies changes.

include( wxui_code.cmake )  # This will set ${wxue_generated_code} with a list of generated files
include( file_list.cmake )  # This will set ${file_list} with a list of files

add_executable(sdi_test WIN32
    ${file_list}
    ${sdi_generated_code}
)

# This is just used by a github action to confirm that all the source code can be compiled
add_library(check_build STATIC EXCLUDE_FROM_ALL
    ${file_list}
    ${sdi_generated_code}
)

if (BUILD_SHARED_LIBS)
    target_compile_definitions(sdi_test PRIVATE WXUSINGDLL)
    target_compile_definitions(check_build PRIVATE WXUSINGDLL)
endif()

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
elseif (WIN32)
    set(SYSTEM_LIBS comctl32 Imm32 Shlwapi Version UxTheme)
endif()

target_link_libraries(sdi_test PRIVATE ${WIDGETS_LIB}  ${SYSTEM_LIBS} wxCLib)

if (MSVC)
    # /GL -- combined with the Linker flag /LTCG to perform whole program optimization in Release build
    # /FC -- Full path to source code file in diagnostics
    target_compile_options(sdi_test PRIVATE "$<$<CONFIG:Release>:/GL>" "/FC" "/W4" "/Zc:__cplusplus" "/utf-8")
    target_link_options(sdi_test PRIVATE "$<$<CONFIG:Release>:/LTCG>")

    # Assume the manifest is in the resource file
    target_link_options(sdi_test PRIVATE "/manifest:no")
elseif(UNIX)
    target_compile_options(sdi_test PRIVATE "-fPIC")
endif()

target_precompile_headers(sdi_test PRIVATE "cpp/pch.h")
target_precompile_headers(check_build PRIVATE "cpp/pch.h")

target_include_directories(sdi_test PRIVATE
    ${BUILD_ROOT}/include
    ${setup_dir}
    ${CMAKE_CURRENT_LIST_DIR}/cpp/
)

target_include_directories(check_build PRIVATE
    ${BUILD_ROOT}/include
    ${setup_dir}
    ${CMAKE_CURRENT_LIST_DIR}/cpp/
)

target_link_directories(sdi_test PRIVATE
    $<$<CONFIG:Debug>:${BUILD_ROOT}//build/Debug>
    $<$<CONFIG:Release>:${BUILD_ROOT}//build/Release>
)
