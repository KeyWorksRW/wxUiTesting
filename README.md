# wxUiTesting

This app exists solely to test the UI and Code generation of [wxUiEditor](https://github.com/KeyWorksRW/wxUiEditor) (link is to the github repository for wxUiEditor). While the app does have several dialogs, they generally don't do anything -- they exist just to confirm that various **wxWidget** controls can be correctly generated with a variety of options.

CodeQL is run whenever the repository changes in order to check the security of the code that **wxUiEditor** generates.

## Cloning

Be aware the cloning may set the default branch to something other than `main` (occurs when special testing is being done for a longer period of time). You may not be able to build from any other branch other than `main`, so it is _strongly_ advised that you switch to the `main` branch before attempting to build.
