@echo off
for %x in (*.cpp) call clang_check %x
for %x in (*.h) call clang_check %x

for %x in (custom_ctrls/*.cpp) call clang_check %x
for %x in (custom_ctrls/*.h) call clang_check %x

for %x in (ui/*.cpp) call clang_check %x
for %x in (ui/*.h) call clang_check %x
