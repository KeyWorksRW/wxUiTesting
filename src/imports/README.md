# Import comparisons

First off, _always_ set the compiler_standard to C++ 17 or you will end up with duplicate embedded images.

The purpose of the files here is to compare code generation from other designers with the Imported code generation the **wxUiEditor** creates. For the most part, the UI should look identical. However there are some exceptions:

- The text control will contain the word "initial" in the wxUiEditor version, and blank in the wxFormBuilder version. This is because wxFormBuilder does not initialize the text control's validator variable, thereby losing it's initial value.
- The spin control has an initial position of 50 in the wxUiEditor version, but not the wxFormBuilder version. This is also because the validator variable is not initialized, so the initial value is tossed.
- On the Additional tab, the animation control is playing in the wxUiEditor version, and disabled in the wxFormBuilder version. This is because wxFormBuilder won't accept the path to the animation control.


# wxFormBuilder import comparison

The purpose of the files in this directory is to create a variety of different controls in **wxFormBuiler** and generate the code to implement those controls, all in a `wxPanel` containing a wxAuiNotebook so that we can add as many pages as we want to test our various controls. **wxUiEditor** is used to import the wxFormBuilder project and generate it's own version of the code. Finally, a dialog is created that contains a split window with the wxUiEditor-generated panel on the left and the wxFormBuilder-generated panel on the right. In this way, the two versions can be compared side-by-side to ensure they look the same.

The point of this is not just to verify that importing works, but also that while the generated code is very different, then appearance of the UI should look the same (unless wxUiEditor is correctly handling a bug in the way wxFormBuilder is generating the code).

## wxFormBuilder project notes

Be aware that **wxFormBuilder** always stores the expand/collapse state of every node. To minimize **git** creating a difference based purely on the expansion state, as well as forcing everyone who opens the file to be stuck with the same expansion state, save the project with every node fully expanded. Yes, it's hard to work with, but it limits git history to actual design changes.

## Bitmaps

Do not use bitmaps that are already included in the main `wxUiTesting.wxui` project -- you'll end up with duplicates, and that will cause the linker to complain.

## Public variables

Normally, variables would be `protected:` or `private:`. However, we need for the parent dialog to be able to access the controls in both panels. Normally, those panels would be part of the dialog class, but in this case they are separate classes, so we need to access their controls directly.

## Images

You will get a constant complaint in **wxFormBuilder** about not being able to find the file specified for the animation control. It doesn't matter that the file exists, and it doesn't work to use the property's file finder button, or even to type in the path. The file's path is relative to the project file, but **wxFormBuilder** doesn't actually look there when it is processing the image (unlike static bitmaps where it _does_ know to look in it's embedded_files_path). Note that it works fine when imported into **wxUiEditor**.

## Ribbon Panels

Be _very_ careful when modifying the ribbon panel in the Data page. Save early and save often as **wxFormBuilder** can crash when working with this control.

## wxFormBuilder Validators

**wxFormBuilder** always sets the the validator type to **wxDefaultValidator** -- and if you leave it that way, it won't generate any code. It also lets you specify **wxTextValidator** for controls that can only use a **wxGenericValidator**. The code wxFormBuilder generates in this case cannot be compiled.

**wxFormBuilder** does not initialize validators. So, for example, if you set the `value` property of a text control which also has a validator, then the text control will be blank because the validator didn't get initialized. Our import code does initialize the value, so they _will_ look different. This will be true of all validators that have initial values set -- it will work when imported and generated, and will be broken in the wxFormbuild-generated version.

# wxCrafter project notes

While wxCrafter has an import wxFormBuilder function, it doesn't work very well, so a lot of controls will be missing. You'll have to add them by hand to get the same control layout as wxFormBuilder.

wxCrafter doesn't allow you to change the access of class members. We need to directly access m_auinotebook1 and m_infoCtrl1. We call the function that wxCrafter creates for it's generated code, but for our imported code we have to change the access of these two variables to `public:`.

**wxCrafter** doesn't generate any code to set the animation file for a wxAnimationCtrl. It does set the property, so it works in the imported version, but not the wxCrafter generated version.
