@echo off

@REM This batch file assumes that you have built a debug version of wxUiEditor.exe and that it
@REM is in the ..\..\build\stage\bin\debug directory.

echo Generating C++ files...
..\..\wxUiEditor\build\stage\bin\debug\wxUiEditor.exe --gen_cpp sdi_31.wxui
type sdi_31.log
cmake.exe --build build --config Debug --target sdi_31
build\Debug\sdi_31.exe
