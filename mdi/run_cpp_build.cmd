@echo off

@REM This batch file assumes that you have built a debug version of wxUiEditor.exe and that it
@REM is in the ..\..\build\stage\bin\debug directory.

echo Generating C++ files...
..\..\wxUiEditor\build\bin\Debug\wxUiEditor.exe --gen_cpp mdi.wxui
type mdi.log
cmake.exe --build build --config Debug
..\wxWidgets32\build\Debug\mdi_test.exe --mdi
