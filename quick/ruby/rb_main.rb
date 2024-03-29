###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

# rubocop:disable all

WX_GLOBAL_CONSTANTS = true unless defined? WX_GLOBAL_CONSTANTS

require 'wx/core'

require_relative 'test_dlg'
require_relative 'wizard'

class MainFrame < Wx::Frame
  def initialize(parent, id = Wx::ID_ANY, title = 'Tests',
                 pos = Wx::DEFAULT_POSITION, size = Wx::DEFAULT_SIZE,
                 style = Wx::DEFAULT_FRAME_STYLE)

    super(parent, id, title, pos, size, style)

    set_min_size(convert_dialog_to_pixels(Wx::Size.new(300, -1)))

    @menubar = Wx::MenuBar.new

    @menu_file = Wx::Menu.new
    menu_item = Wx::MenuItem.new(@menu_file, Wx::ID_EXIT)
    @menu_file.append(menu_item)
    @menubar.append(@menu_file, '&File')

    menu_dialogs = Wx::Menu.new
    menu_item_test_dlg = Wx::MenuItem.new(menu_dialogs, Wx::ID_ANY,
      'Test Dialog...')
    menu_dialogs.append(menu_item_test_dlg)
    menu_item_test_wizard = Wx::MenuItem.new(menu_dialogs, Wx::ID_ANY,
      'Wizard...')
    menu_dialogs.append(menu_item_test_wizard)
    @menubar.append(menu_dialogs, 'Tests')

    set_menu_bar(@menubar)

    box_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    panel = Wx::Panel.new(self, Wx::ID_ANY, Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::TAB_TRAVERSAL)
    box_sizer.add(panel, Wx::SizerFlags.new(1).expand)

    panel_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    @text_ctrl = Wx::TextCtrl.new(panel, Wx::ID_ANY, '',
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::TE_MULTILINE)
    @text_ctrl.set_min_size(convert_dialog_to_pixels(Wx::Size.new(200, 100)))
    panel_sizer.add(@text_ctrl, Wx::SizerFlags.new(1).expand.border(Wx::ALL))
    panel.set_sizer_and_fit(panel_sizer)
    set_sizer_and_fit(box_sizer)

    centre(Wx::BOTH)

    # Event handlers
    evt_menu(menu_item.get_id, :on_quit)
    evt_menu(menu_item_test_dlg.get_id, :on_test_dlg)
    evt_menu(menu_item_test_wizard.get_id, :on_wizard)
  end
# Unimplemented Event handler functions
# Copy any listed and paste them below the comment block, or to your inherited class.

=begin
  def on_quit(event)
    event.skip
  end

  def on_test_dlg(event)
    event.skip
  end

  def on_wizard(event)
    event.skip
  end

=end
end

# rubocop:enable all

# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************

def on_quit
  close(true)
end

def on_test_dlg
  test_dlg = TestDialog.new(self)
  test_dlg.show_modal
  test_dlg.destroy
end

def on_wizard
  my_wizard = Wizard.new(self)
  my_wizard.run_wizard(my_wizard.get_page_area_sizer.get_item(0).get_window)
  my_wizard.destroy
end

class App < Wx::App
  def on_init
    frame = MainFrame.new(nil, Wx::ID_ANY, 'Ruby implementation')
    frame.show
    set_top_window(frame)
    true
  end
end

App.run
