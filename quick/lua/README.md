wxLua does not provide binaries, apparently assuming that anyone programming in Lua will have a complete C++ toolchain and the knowledge needed to build it.

The most recent Windows binaries I could find are from https://github.com/decuant/wxLua542Win10 -- this uses Lua 5.4, wxWidgets 3.1.4 and wxLua 3.1.0. Note that while the binaries include lua54.dll they do _not_ include lua.exe, so if you want to use that you will need to find the correct version separately. In reality, the _only_ thing you need is wxLua.exe -- that has wxWidgets and lua built-in, so just running wxLua.exe instead of lua.exe works fine without needing anything additional.

