set(PACKAGE_VERSION "")

# Set the path to the include directory
set(wxWidgets_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

# Set the path/names of the libraries to link to
set(wxWidgets_LIB_DIRS
    "$<$<CONFIG:Debug>:C:/rwCode/wxUiTesting/wxWidgets32/build/Debug>"
    "$<$<CONFIG:Release>:C:/rwCode/wxUiTesting/wxWidgets32/build/Release>"
)

# Set the names of the libraries to link to
if(BUILD_SHARED_LIBS)
    set(wxWidgets_LIBRARIES wxWidgets32)
else()
    set(wxWidgets_LIBRARIES "wxWidgets32" "wxCLib")
endif()
