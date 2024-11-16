###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

WX_GLOBAL_CONSTANTS = true unless defined? WX_GLOBAL_CONSTANTS

require 'wx/core'

class DlgIssue_956 < Wx::Dialog
  def initialize(parent, id = Wx::ID_ANY, title = 'colspan codegen issue',
                 pos = Wx::DEFAULT_POSITION, size = Wx::DEFAULT_SIZE,
                 style = Wx::DEFAULT_DIALOG_STYLE)

    super(parent, id, title, pos, size, style)

    dlg_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    panel_2 = Wx::Panel.new(self, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::BORDER_THEME|Wx::TAB_TRAVERSAL)
    dlg_sizer.add(panel_2, Wx::SizerFlags.new.expand.border(Wx::ALL))

    grid_bag_sizer = Wx::GridBagSizer.new

    @staticText_4 = Wx::StaticText.new(panel_2, Wx::ID_ANY, 'list test')
    grid_bag_sizer.add(@staticText_4, Wx::GBPosition.new(0, 0), Wx::GBSpan.new(1,
      1), Wx::ALL, 5)

    @choice = Wx::Choice.new(panel_2, Wx::ID_ANY)
    grid_bag_sizer.add(@choice, Wx::GBPosition.new(0, 1), Wx::GBSpan.new(1, 1),
      Wx::ALL|Wx::EXPAND, 5)

    @btn = Wx::Button.new(panel_2, Wx::ID_ANY, (''))
    @btn.set_label_markup('&Refresh')
    grid_bag_sizer.add(@btn, Wx::GBPosition.new(0, 2), Wx::GBSpan.new(1, 1),
      Wx::ALL, 5)

    @btn_2 = Wx::Button.new(panel_2, Wx::ID_ANY, (''))
    @btn_2.set_label_markup('&New')
    grid_bag_sizer.add(@btn_2, Wx::GBPosition.new(0, 3), Wx::GBSpan.new(1, 1),
      Wx::ALL, 5)

    @btn_3 = Wx::Button.new(panel_2, Wx::ID_ANY, (''))
    @btn_3.set_label_markup('&Edit')
    grid_bag_sizer.add(@btn_3, Wx::GBPosition.new(0, 4), Wx::GBSpan.new(1, 1),
      Wx::ALL, 5)

    @btn_4 = Wx::Button.new(panel_2, Wx::ID_ANY, (''))
    @btn_4.set_label_markup('&Delete')
    grid_bag_sizer.add(@btn_4, Wx::GBPosition.new(0, 5), Wx::GBSpan.new(1, 1),
      Wx::ALL, 5)

    @staticText_5 = Wx::StaticText.new(panel_2, Wx::ID_ANY, 'test type')
    grid_bag_sizer.add(@staticText_5, Wx::GBPosition.new(1, 0), Wx::GBSpan.new(1,
      1), Wx::ALL, 5)

    @choice_2 = Wx::Choice.new(panel_2, Wx::ID_ANY)
    grid_bag_sizer.add(@choice_2, Wx::GBPosition.new(1, 1), Wx::GBSpan.new(1, 5),
      Wx::ALL|Wx::EXPAND, 5)

    grid_bag_sizer.add_growable_col(1)
    grid_bag_sizer.add_growable_row(1)
    panel_2.set_sizer_and_fit(grid_bag_sizer)

    if Wx::PLATFORM != 'WXMAC'
      stdBtn_line = Wx::StaticLine.new(self, Wx::ID_ANY, Wx::DEFAULT_POSITION,
                                  Wx::Size.new(20, -1))
      dlg_sizer.add(stdBtn_line, Wx::SizerFlags.new.expand.border(Wx::ALL))
    end
    stdBtn = Wx::StdDialogButtonSizer.new
    stdBtn_ok = Wx::Button.new(self, Wx::ID_OK)
    stdBtn.add_button(stdBtn_ok)
    stdBtn_ok.set_default
    stdBtn_cancel = Wx::Button.new(self, Wx::ID_CANCEL)
    stdBtn.add_button(stdBtn_cancel)
    stdBtn.realize
    dlg_sizer.add(stdBtn, Wx::SizerFlags.new.expand.border(Wx::ALL))

    if pos != Wx::DEFAULT_POSITION
      set_position(from_dip(pos))
    end
    if size == Wx::DEFAULT_SIZE
      set_sizer_and_fit(dlg_sizer)
    else
      set_sizer(dlg_sizer)
      if size.x == Wx::DEFAULT_COORD || size.y == Wx::DEFAULT_COORD
        fit
      end
      set_size(from_dip(size))
      layout
    end
    centre(Wx::BOTH)
  end
end
# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************
