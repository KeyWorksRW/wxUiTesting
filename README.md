# wxUiTesting

This app exists solely to test the UI and Code generation of [wxUiEditor](https://github.com/KeyWorksRW/wxUiEditor) (link is to the github repository for wxUiEditor). While the app does have several dialogs, they generally don't do anything -- they exist just to confirm that various **wxWidget** controls can be correctly generated with a variety of options.

CodeQL is run whenever the repository changes in order to check the security of the code that **wxUiEditor** generates.

Note that normally **wxSnapshot** would be a submodule since it is essentially a copy of a public repository (https://github.com/KeyWorksRW/wxSnapshot). However, in order to experiment with changes in the **wxWidgets** code (such as early copies of the next dev release of wxWidgets) it is added directly here.
