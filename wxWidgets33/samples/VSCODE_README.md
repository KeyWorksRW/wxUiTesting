If you are using VS Code, then you can build and debug most of the samples in your editor. Create your .vscode directory in the samples/ directory (the entire directory is in .gitignore). In your tasks.json file, add the following if you are building on Windows using MSVC:

```json
        {
            "label": "Build Debug MSVC",
            "type": "shell",
            "options": {
                "cwd": "${workspaceFolder}/build"
            },
            "command": "ninja -f build-Debug.ninja",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": {
                "base": "$msCompile",
                "fileLocation": [
                    "autoDetect",
                    "${workspaceFolder}"
                ]
            }
        },
```

For each target in CMakeLists.txt you want to build, add a task such as the following:

```json
        {
            "label": "Build artprov",
            "type": "shell",
            "options": {
                "cwd": "${workspaceFolder}/"
            },
            "command": "cmake.exe --build build --config Debug --target artprov",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": {
                "base": "$msCompile",
                "fileLocation": [
                    "autoDetect",
                    "${workspaceFolder}"
                ]
            }
        },
```

In your launch.json file, you can now add configurations for each target specified in the CMakeLists.txt file. For example

```json
      {
         "name": "artprov",
         "type": "cppvsdbg",
         "request": "launch",
         "cwd" : "${workspaceRoot}/../build/Debug",
         "program": "${workspaceRoot}/build/Debug/artprov.exe",
         "args": [
             ""
         ],
         "logging": {
            "moduleLoad": false
         },
         "stopAtEntry": false,
         "preLaunchTask": "Build artprov"
      },
```

Now all you need to do is select the target you want to run under the debugger from the Debug dropdown list and press F5.

This assumes, of course, that you have already built a shared version of wxWidgets. 
