cmake_minimum_required( VERSION 3.24 )

project( sdi33
    LANGUAGES CXX
    VERSION 3.3.0
    DESCRIPTION "SDI33 Testing App"
    HOMEPAGE_URL "https://github.com/KeyWorksRW/wxUiTesting" )

# ###################### Options #######################

# creates a compile_commands.json file in the build directory, suitable for clangd
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

option( BUILD_SHARED_LIBS "Build with wxWidgets shared libraries" OFF )

if( BUILD_SHARED_LIBS )
    message( NOTICE "Building with wxWidgets shared libraries" )
else()
    message( NOTICE "Building with wxWidgets static libraries" )
endif()

option( INTERNAL_DARK_MODE "Enable dark mode (used with wxWidgets 3.3 in _WIN32 builds)" OFF )
option( INTERNAL_DARK_HIGH_CONTRAST "Enable dark mode high contrast (used with wxWidgets 3.3 in _WIN32 builds)" OFF )

# ###################### Check for Multi-Config Generator #######################
get_property( isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG )

if( NOT isMultiConfig )
    message( "\nBecause you are using a single target generator, you MUST specify" )
    message( "    a \"--config [Debug|Release]\" option with the cmake --build command\n" )

    set( allowedBuildTypes Debug Release )
    set_property( CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${allowedBuildTypes}" )

    if( NOT CMAKE_BUILD_TYPE )
        set( CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE )
    elseif( NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes )
        message( FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}" )
    endif()
endif()

# ###################### General Settings #######################
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_CXX_EXTENSIONS OFF )

if( MSVC )
    # /O1 often results in faster code than /O2 due to CPU caching
    string( REPLACE "/O2" "/O1" cl_optimize ${CMAKE_CXX_FLAGS_RELEASE} )
    set( CMAKE_CXX_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C++ Release flags" FORCE )

    # Using /Z7 instead of /Zi to avoid blocking while parallel compilers write to the pdb file.
    # This can considerably speed up build times at the cost of larger object files.
    string( REPLACE "/Zi" "/Z7" z_seven ${CMAKE_CXX_FLAGS_DEBUG} )
    set( CMAKE_CXX_FLAGS_DEBUG ${z_seven} CACHE STRING "C++ Debug flags" FORCE )

    # Use static runtime for Release builds to run with Wine without needing to install the dlls
    if( NOT BUILD_SHARED_LIBS )
        set( CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" )
    endif()
elseif( UNIX )
    # Use the package PkgConfig to detect GTK+ headers/library files
    find_package( PkgConfig REQUIRED )

    pkg_check_modules( GTK3 REQUIRED gtk+-3.0 )
    include_directories( ${GTK3_INCLUDE_DIRS} )
    link_directories( ${GTK3_LIBRARY_DIRS} )
    add_definitions( ${GTK3_CFLAGS_OTHER} )

    pkg_check_modules( X11 REQUIRED x11 )
    include_directories( ${X11_INCLUDE_DIRS} )
    link_directories( ${X11_LIBRARY_DIRS} )
    add_definitions( ${X11_CFLAGS_OTHER} )

    # This should work for gcc and clang (including xcode which is based on clang)
    # -O2 can result in faster code than -O3 due to CPU caching.
    string( REPLACE "-O3" "-O2" cl_optimize "${CMAKE_CXX_FLAGS_RELEASE}" )
    set( CMAKE_CXX_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C++ Release flags" FORCE )
endif()

add_compile_definitions( $<$<CONFIG:Release>:NDEBUG> )

set( stageDir ${CMAKE_CURRENT_BINARY_DIR} )

include( GNUInstallDirs )

if( NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${stageDir}/${CMAKE_INSTALL_BINDIR} )
endif()

if( NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${stageDir}/${CMAKE_INSTALL_LIBDIR} )
endif()

if( NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${stageDir}/${CMAKE_INSTALL_LIBDIR} )
endif()

# ###################### Set wxWidgets location macros #######################
if( WIN32 )
    set( wxWidgets_REQUIRED_COMPONENTS base core lunasvg html xml aui richtext ribbon propgrid webview stc xrc )
else()
    set( wxWidgets_REQUIRED_COMPONENTS base core lunasvg html xml aui richtext ribbon propgrid stc xrc )
endif()

include( FetchContent )

# Set wxWidgets build options BEFORE FetchContent_MakeAvailable
set( wxBUILD_SHARED OFF CACHE BOOL "Build static wx libraries" )
set( wxUSE_UNICODE_UTF8 1 CACHE BOOL "Use UTF-8 internally in wxWidgets" )
set( wxUSE_UTF8_LOCALE_ONLY 1 CACHE BOOL "Use UTF-8 locale only in wxWidgets" )
set( wxUSE_GUI ON CACHE BOOL "This is a GUI application" FORCE )
set( wxUSE_LUNASVG ON CACHE BOOL "Use LunaSVG for rendering SVG images" FORCE )
set( wxUSE_NANOSVG OFF CACHE BOOL "Use NanoSVG for rendering SVG images" FORCE )
set( wxBUILD_INSTALL OFF CACHE BOOL "Don't build wxWidgets install" )

set( wxUSE_WEBVIEW_IE OFF CACHE BOOL "Use wxWebView IE backend for web viewing" )

if( WIN32 )
    set( wxUSE_WEBVIEW ON CACHE BOOL "Use wxWidgets' web viewing classes" )
    set( wxUSE_WEBVIEW_WEBKIT OFF CACHE BOOL "Use wxWebView WebKit for web viewing" )
elseif( APPLE )
    set( wxUSE_WEBVIEW OFF CACHE BOOL "Don't use wxWidgets' web viewing classes" )
else()
    set( wxUSE_WEBVIEW OFF CACHE BOOL "Don't use wxWidgets' web viewing classes" )
endif()

# Prevent FetchContent from updating wxWidgets after initial download
set( FETCHCONTENT_UPDATES_DISCONNECTED wxWidgets ON CACHE BOOL "Prevent FetchContent from updating wxWidgets after initial download" )

message( STATUS "Fetching wxWidgets (this may take awhile) ..." )

FetchContent_Declare(
    wxWidgets
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../wxFetch"
)

message( NOTICE "Configuring wxWidgets..." )

FetchContent_MakeAvailable( wxWidgets )

message( NOTICE "wxWidgets has been fetched and configured." )
message( STATUS "wxWidgets sources: " ${wxWidgets_SOURCE_DIR} )

# ###################### Libraries and Executables #######################

# Setting CMAKE_MODULE_PATH causes ninja to fail rebuilding until CMake re-generates. Specifying the full path and extension
# means ninja sees this as a normal dependency that didn't change any time one of the files it specifies changes.
include( wxui_code.cmake ) # This will set ${wxue_generated_code} with a list of generated files
include( file_list.cmake ) # This will set ${file_list} with a list of files

add_executable( ${PROJECT_NAME} WIN32
    ${file_list}
    ${sdi_generated_code}
)

if( BUILD_SHARED_LIBS )
    target_compile_definitions( ${PROJECT_NAME} PRIVATE WXUSINGDLL )
endif()

if( INTERNAL_DARK_MODE )
    target_compile_definitions( ${PROJECT_NAME} PRIVATE DARK_MODE=1 )

    if( INTERNAL_DARK_HIGH_CONTRAST )
        message( NOTICE "Building with Dark mode and High Contrast" )
        target_compile_definitions( ${PROJECT_NAME} PRIVATE DARK_HIGH_CONTRAST=1 )
    else()
        message( NOTICE "Building with Dark mode, but not High Contrast" )
    endif()
endif()

if( UNIX )
    set( SYSTEM_LIBS
        ${GTK3_LIBRARIES}
        ${X11_LIBRARIES}
        pthread
        dl
        png
        GL
        GLX
    )
elseif( WIN32 )
    set( SYSTEM_LIBS comctl32 Imm32 Shlwapi Version UxTheme )
endif()

if( MSVC )
    # /GL -- combined with the Linker flag /LTCG to perform whole program optimization in Release build
    # /FC -- Full path to source code file in diagnostics
    target_compile_options( sdi33 PRIVATE "$<$<CONFIG:Release>:/GL>" "/FC" "/W4" "/Zc:__cplusplus" "/utf-8" )
    target_link_options( sdi33 PRIVATE "$<$<CONFIG:Release>:/LTCG>" )

    # Assume the manifest is in the resource file
    target_link_options( sdi33 PRIVATE "/manifest:no" )
    target_link_directories( ${PROJECT_NAME} PRIVATE ${WX_LIB_DIR} )
elseif( UNIX )
    target_compile_definitions( ${PROJECT_NAME} PRIVATE __WXGTK__ )
    target_link_directories( ${PROJECT_NAME} PRIVATE ${WX_LIB_DIR} ${GTK3_LIBRARY_DIRS} )
endif()

target_precompile_headers( ${PROJECT_NAME} PRIVATE "cpp/pch.h" )

target_include_directories( ${PROJECT_NAME} PRIVATE
    ${wxWidgets_SOURCE_DIR}/include
)

if( WIN32 )
    target_include_directories( ${PROJECT_NAME} PRIVATE
        ${wxWidgets_BUILD_DIR}/lib/vc_x64_lib/mswu
    )
elseif( APPLE )
    target_include_directories( ${PROJECT_NAME} PRIVATE
        ${wxWidgets_SOURCE_DIR}/include
        ${wxWidgets_BUILD_DIR}/lib/osx_cocoa-unicode-static
    )
elseif( UNIX )
    target_include_directories( ${PROJECT_NAME} PRIVATE
        ${wxWidgets_SOURCE_DIR}/include
        ${wxWidgets_BUILD_DIR}/lib/gtk3_unixu-3.3/include
    )
else()
    message( FATAL_ERROR "Unsupported platform: Only WIN32, APPLE, or UNIX are supported." )
endif()

target_include_directories( ${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/cpp/
)

foreach( component ${wxWidgets_REQUIRED_COMPONENTS} )
    list( APPEND wxWidgets_LIBRARIES wx${component} )
endforeach()

target_link_libraries( ${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES} ${SYSTEM_LIBS})
