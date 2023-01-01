cmake_minimum_required(VERSION 3.20)

project(wxUiTesting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    # /O1 often results in faster code than /O2 due to CPU caching
    string(REPLACE "/O2" "/O1" cl_optimize "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C++ Release flags" FORCE)

    # Using /Z7 instead of /Zi to avoid blocking while parallel compilers write to the pdb file.
    # This can considerably speed up build times at the cost of larger object files.
    string(REPLACE "/Zi" "/Z7" z_seven "${CMAKE_CXX_FLAGS_DEBUG}")
    set(CMAKE_CXX_FLAGS_DEBUG ${z_seven} CACHE STRING "C++ Debug flags" FORCE)

    # Use static runtime for Release builds to run with Wine without needing to install the dlls
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    # This should work for gcc and clang (including xcode which is based on clang)
    # -O2 can result in faster code than -O3 due to CPU caching.
    string(REPLACE "-O3" "-O2" cl_optimize "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C++ Release flags" FORCE)
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

option(INTERNAL_WIDGETS_SOURCES "Build with internal forked wxWidgets sources" )

if (INTERNAL_WIDGETS_SOURCES)
    message(NOTICE "Building internal version")

    # Add preprocessor definition that can be used to conditionalize code based on whether the
    # internal wxWidgets libraries are being used.
    add_compile_definitions(INTERNAL_WIDGETS)
endif()

set (widget_dir ${CMAKE_CURRENT_LIST_DIR}/wxSnapshot)
set (widget_cmake_dir ${CMAKE_CURRENT_LIST_DIR}/wxSnapshot)
add_subdirectory(${widget_cmake_dir})

add_compile_definitions($<$<CONFIG:Release>:NDEBUG>)

include(src/wxui_generated/wxui_generated.cmake)  # This will set ${wxue_generated_code} with a list of generated files
include(src/file_list.cmake)     # This will set ${file_list} with a list of files
list(TRANSFORM file_list PREPEND "${file_list_dir}/")

add_executable(wxUiTesting WIN32
    ${file_list}
    ${wxui_generated}
)

# This is just used by a github action to confirm that all the source code can be compiled
add_library(check_build STATIC EXCLUDE_FROM_ALL
    ${file_list}
    ${wxui_generated}
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
    set(setup_dir ${widget_cmake_dir}/win)
endif()

target_include_directories(wxUiTesting PRIVATE
    ${widget_dir}/include
    ${setup_dir}
    src/
    src/ui
    src/wxui_generated
)

target_include_directories(check_build PRIVATE
    ${widget_dir}/include
    ${setup_dir}
    src/
    src/ui
    src/wxui_generated
)
