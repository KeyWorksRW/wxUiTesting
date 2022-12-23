import wx

import mainframe_base
import python_dlg

class mainframe(mainframe_base.MainFrameBase):
    def __init__(self, parent):
        super().__init__(parent)

    # Event handler functions
    def OnChoicebook(self, event):
        event.Skip()

    def OnCommonDialog(self, event):
        event.Skip()

    def OnImportTest(self, event):
        event.Skip()

    def OnListbook(self, event):
        event.Skip()

    def OnMultiTestDialog(self, event):
        event.Skip()

    def OnNotebook(self, event):
        event.Skip()

    def OnOtherCtrls(self, event):
        event.Skip()

    def OnQuit(self, event):
        self.Close()

    def OnRibbonDialog(self, event):
        event.Skip()

    def OnToolbook(self, event):
        event.Skip()

    def OnTreebook(self, event):
        event.Skip()

    def OnWizard(self, event):
        event.Skip()

    def OnPythonDlg(self, event):
        dlg = python_dlg.PythonDlg(self)
        dlg.ShowModal()
        dlg.Destroy()
