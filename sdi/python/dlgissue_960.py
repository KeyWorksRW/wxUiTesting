###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

"""DlgIssue_960 class generated by wxUiEditor."""

import wx
ISSUE_DLG_960 = wx.ID_HIGHEST + 1

import images

class DlgIssue_960(wx.Dialog):
    def __init__(self, parent, id=ISSUE_DLG_960, title=
"C’est une bonne journée pour tester", pos=wx.DefaultPosition,
                size=wx.DefaultSize, style=wx.DEFAULT_DIALOG_STYLE,
                name=wx.DialogNameStr):
        wx.Dialog.__init__(self)

        if not self.Create(parent, id, title, pos, size, style, name):
            return

        dlg_sizer = wx.BoxSizer(wx.VERTICAL)

        self.staticText = wx.StaticText(self, wx.ID_ANY,
            "The following are bitmaps that have filenames which are invalid as C++ or Python variables. This is used to test resolution of issue #960.")
        self.staticText.Wrap(300)
        dlg_sizer.Add(self.staticText, wx.SizerFlags().Border(wx.ALL))

        box_sizer = wx.BoxSizer(wx.HORIZONTAL)

        bmp = wx.StaticBitmap(self, wx.ID_ANY, wx.BitmapBundle.FromBitmap(
            images.img_1_bottom_png.Bitmap))
        box_sizer.Add(bmp, wx.SizerFlags().Border(wx.ALL))

        bmp_2 = wx.StaticBitmap(self, wx.ID_ANY, wx.BitmapBundle.FromBitmap(
            images.bottom_1__png.Bitmap))
        box_sizer.Add(bmp_2, wx.SizerFlags().Border(wx.ALL))

        dlg_sizer.Add(box_sizer, wx.SizerFlags().Border(wx.ALL))

        bmp_3 = wx.StaticBitmap(self, wx.ID_ANY, wx.BitmapBundle.FromBitmap(
            images.Ainsi_c3a7a_se_passe_png.Bitmap))
        dlg_sizer.Add(bmp_3, wx.SizerFlags().Border(wx.ALL))

        if "wxMac" not in wx.PlatformInfo:
            stdBtn_line = \
                wx.StaticLine(self, wx.ID_ANY, wx.DefaultPosition, wx.Size(20, -1))
            dlg_sizer.Add(stdBtn_line, wx.SizerFlags().Expand().Border(wx.ALL))

        stdBtn = wx.StdDialogButtonSizer()
        stdBtn_ok = wx.Button(self, wx.ID_OK)
        stdBtn.SetAffirmativeButton(stdBtn_ok)
        stdBtn_cancel = wx.Button(self, wx.ID_CANCEL)
        stdBtn.SetCancelButton(stdBtn_cancel)
        stdBtn_ok.SetDefault()
        stdBtn.Realize()
        dlg_sizer.Add(stdBtn, wx.SizerFlags().Expand().Border(wx.ALL))

        if pos != wx.DefaultPosition:
            self.SetPosition(self.FromDIP(pos))
        if size == wx.DefaultSize:
            self.SetSizerAndFit(dlg_sizer)
        else:
            self.SetSizer(dlg_sizer)
            if size.x == wx.DefaultCoord or size.y == wx.DefaultCoord:
                self.Fit()
            self.SetSize(self.FromDIP(size))
            self.Layout()
        self.Centre(wx.BOTH)
# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************
