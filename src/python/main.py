import wx

import mainframe


class MyApp(wx.App):
    def OnInit(self):
        frame = mainframe.mainframe(None)
        self.SetTopWindow(frame)

        frame.Show(True)
        return True


app = MyApp()
app.MainLoop()
