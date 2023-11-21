###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

WX_GLOBAL_CONSTANTS = true unless defined? WX_GLOBAL_CONSTANTS

require 'wx/core'
require 'wx/grid'
require 'wx/pg'

require_relative 'dlgissue_956'
require_relative 'dlgissue_960'
require_relative 'booktest_dlg'
require_relative 'wizard'
require_relative 'main_test_dlg'
require_relative 'tools_dlg'

require_relative 'images'
require 'base64'

class MainFrame < Wx::Frame
  def initialize(parent, id = Wx::ID_ANY, title = 'SDI Tests',
                 pos = Wx::DEFAULT_POSITION, size = Wx::Size.new(500, 300),
                 style = Wx::DEFAULT_FRAME_STYLE|Wx::TAB_TRAVERSAL)

    super(parent, id, title, pos, size, style)

    @splitter = Wx::SplitterWindow.new(self, Wx::ID_ANY,
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::SP_3D)
    @splitter.set_sash_gravity(0.0)
    @splitter.set_minimum_pane_size(150)
    @splitter.set_min_size(convert_dialog_to_pixels(Wx::Size.new(200, 200)))

    @propertyGridManager = Wx::PropertyGridManager.new(@splitter, Wx::ID_ANY,
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::PG::PG_AUTO_SORT|
      Wx::PG::PG_BOLD_MODIFIED|Wx::PG::PG_SPLITTER_AUTO_CENTER|
      Wx::PG::PG_DESCRIPTION|Wx::PG::PG_TOOLBAR|Wx::PG::PG_NO_INTERNAL_BORDER)
    @propertyGridManager.set_extra_style(Wx::PG::PG_EX_MODE_BUTTONS)

    @propertyGridPage = @propertyGridManager.add_page('Animal Page',
      wxue_get_bundle($wxPython_1_5x_png))

    @propertyGridItem_7 = @propertyGridPage.append(Wx::PG::PropertyCategory.new(
    'Pets', 'Pets'))

    @propertyGridItem_2 = @propertyGridPage.append(Wx::PG::StringProperty.new(
    'dog', 'Woof!'))

    @propertyGridItem = @propertyGridPage.append(Wx::PG::StringProperty.new(
    'cat', 'Meow!'))

    @propertyGridItem_5 = @propertyGridPage.append(Wx::PG::PropertyCategory.new(
    'Big Animals', 'Big Animals'))

    @propertyGridItem_8 = @propertyGridPage.append(Wx::PG::StringProperty.new(
    'horses', ''))

    @propertyGridPage_2 = @propertyGridManager.add_page('Number Page',
      wxue_get_bundle($english_png))

    @propertyGridItem_6 = @propertyGridPage_2.append(Wx::PG::PropertyCategory.new(
    'Numbers', 'Numbers'))

    @propertyGridItem_3 = @propertyGridPage_2.append(Wx::PG::IntProperty.new('1', ''
      ))

    @propertyGridItem_4 = @propertyGridPage_2.append(Wx::PG::IntProperty.new('2', ''
      ))

    @grid = Wx::GRID::Grid.new(@splitter, Wx::ID_ANY)
    @grid.create_grid(5, 5)
    @grid.enable_drag_grid_size(false)
    @grid.set_margins(0, 0)
    @grid.set_default_cell_alignment(Wx::ALIGN_LEFT, Wx::ALIGN_TOP)
    @grid.set_col_label_alignment(Wx::ALIGN_CENTER, Wx::ALIGN_CENTER)
    @grid.set_col_label_size(Wx::GRID::GRID_AUTOSIZE)
    @grid.set_row_label_alignment(Wx::ALIGN_CENTER, Wx::ALIGN_CENTER)
    @grid.set_row_label_size(Wx::GRID::GRID_AUTOSIZE)
    @splitter.split_horizontally(@propertyGridManager, @grid)

    menubar = Wx::MenuBar.new

    @menu = Wx::Menu.new
    menuQuit = Wx::MenuItem.new(@menu, Wx::ID_EXIT)
    menuQuit.set_bitmap(Wx::ArtProvider.get_bitmap_bundle(Wx::ART_QUIT,
      Wx::ART_MENU))
    @menu.append(menuQuit)
    menubar.append(@menu, Wx::get_stock_label(Wx::ID_FILE))

    menuDialogs = Wx::Menu.new
    menu_item_3 = Wx::MenuItem.new(menuDialogs, Wx::ID_ANY, 'MainTestDlg')
    menu_item_3.set_bitmap(wxue_get_bundle($debug_32_png))
    menuDialogs.append(menu_item_3)
    menu_item_4 = Wx::MenuItem.new(menuDialogs, Wx::ID_ANY, 'BookTestDlg')
    menu_item_4.set_bitmap(wxue_get_bundle($wxNotebook_png))
    menuDialogs.append(menu_item_4)
    menu_item_2 = Wx::MenuItem.new(menuDialogs, Wx::ID_ANY, 'PythonDlg')
    menu_item_2.set_bitmap(wxue_get_bundle($wxPython_png, $wxPython_1_5x_png, $wxPython_2x_png))
    menuDialogs.append(menu_item_2)
    menu_tools_dlg2 = Wx::MenuItem.new(menuDialogs, Wx::ID_ANY, 'Tools Dialog',
      'Dialog for testing different types of toolbars', Wx::ITEM_NORMAL)
    menu_tools_dlg2.set_bitmap(wxue_get_bundle($wxToolBar_png))
    menuDialogs.append(menu_tools_dlg2)
    menuItem3 = Wx::MenuItem.new(menuDialogs, Wx::ID_ANY, 'Wizard')
    menuItem3.set_bitmap(wxue_get_bundle($wxWizard_png))
    menuDialogs.append(menuItem3)
    menuDialogs.append_separator
    menuItem_2 = Wx::MenuItem.new(menuDialogs, Wx::ID_ANY, 'Common Controls...',
      'Common controls', Wx::ITEM_NORMAL)
    menuItem_2.set_bitmap(Wx::ArtProvider.get_bitmap_bundle(Wx::ART_TIP,
      Wx::ART_MENU))
    menuDialogs.append(menuItem_2)
    menuDialogs.append_separator

    submenu = Wx::Menu.new
    menu_item_5 = Wx::MenuItem.new(submenu, Wx::ID_ANY, 'DlgIssue_956')
    menu_item_5.set_bitmap(wxue_get_bundle($debug_32_png))
    submenu.append(menu_item_5)
    menu_item_6 = Wx::MenuItem.new(submenu, Wx::ID_ANY, 'DlgIssue_960')
    menu_item_6.set_bitmap(wxue_get_bundle($Ainsi_c3_a_se_passe_png))
    submenu.append(menu_item_6)
    submenu_item = menuDialogs.append_sub_menu(submenu, 'Issue Dialogs')
    submenu_item.set_bitmap(wxue_get_bundle($wxDialog_png))
    menubar.append(menuDialogs, '&Dialogs')

    set_menu_bar(menubar)

    @toolBar = create_tool_bar

    tool_dropdown = @toolBar.add_tool(Wx::ID_ANY, '', Wx::ArtProvider.get_bitmap_bundle(
      Wx::ART_EXECUTABLE_FILE, Wx::ART_MENU), (''), Wx::ITEM_DROPDOWN)
    tool_dropdown_menu = Wx::Menu.new
    menu_item = Wx::MenuItem.new(tool_dropdown_menu, Wx::ID_ANY, 'Wizard...')
    menu_item.set_bitmap(Wx::ArtProvider.get_bitmap_bundle(Wx::ART_FIND,
      Wx::ART_MENU))
    tool_dropdown_menu.append(menu_item)
    menu_tools_dlg = Wx::MenuItem.new(tool_dropdown_menu, Wx::ID_ANY,
      'Tools Dialog', 'Dialog for testing different types of toolbars',
      Wx::ITEM_NORMAL)
    tool_dropdown_menu.append(menu_tools_dlg)
    tool_dropdown.set_dropdown_menu(tool_dropdown_menu)
    tool_4 = @toolBar.add_tool(Wx::ID_ANY, 'MainTestDlg', wxue_get_bundle($debug_32_png))

    tool_5 = @toolBar.add_tool(Wx::ID_ANY, 'BookTestDlg', wxue_get_bundle($wxNotebook_png))

    @toolBar.add_separator
    tool_3 = @toolBar.add_tool(Wx::ID_ANY, 'PythonDlg', wxue_get_bundle($wxPython_1_5x_png))

    @toolBar.add_stretchable_space

    tool_2 = @toolBar.add_tool(Wx::ID_ANY, 'Common Controls...', Wx::ArtProvider.get_bitmap_bundle(
      Wx::ART_TIP, Wx::ART_TOOLBAR))

    @toolBar.realize

    @statusBar = create_status_bar(2)
    @statusBar.set_status_widths([100, -1])
    @statusBar.set_status_styles([Wx::SB_FLAT, Wx::SB_FLAT])

    centre(Wx::BOTH)

    # Event handlers
    evt_menu(menuQuit.get_id, :on_quit)
    evt_menu(menu_item_3.get_id, :OnMainTestDlg)
    evt_menu(menu_item_4.get_id, :OnBookTestDlg)
    evt_menu(menu_item_2.get_id, :OnPythonDlg)
    evt_menu(menu_tools_dlg2.get_id, :on_tools_dlg)
    evt_menu(menuItem3.get_id, :OnWizard)
    evt_menu(menuItem_2.get_id, :OnCommonDialog)
    evt_menu(menu_item_5.get_id, :OnDlgIssue_956)
    evt_menu(menu_item_6.get_id, :OnDlgIssue_960)
    evt_menu(menu_item.get_id, :OnWizard)
    evt_menu(menu_tools_dlg.get_id, :on_tools_dlg)
    evt_tool(tool_4.get_id, :OnMainTestDlg)
    evt_tool(tool_5.get_id, :OnBookTestDlg)
    evt_tool(tool_3.get_id, :OnPythonDlg)
    evt_tool(tool_2.get_id, :OnCommonDialog)
  end
# Unimplemented Event handler functions
# Copy any listed and paste them below the comment block, or to your inherited class.

=begin
  def OnBookTestDlg(event)
    event.skip
  end

  def OnDlgIssue_956(event)
    event.skip
  end

  def OnDlgIssue_960(event)
    event.skip
  end

  def OnMainTestDlg(event)
    event.skip
  end

  def OnWizard(event)
    event.skip
  end

=end
end

$wxToolBar_png = Base64.decode64(
  'iVBORw0KGgoAAAANSUhEUgAAABYAAAAWCAYAAADEtGw7AAAACXBIWXMAAAsTAAALEwEAmpwY' +
  'AAAB3ElEQVQ4y+2UMWgTURjHf69pcnI2BYPeIukiGoQGBIcMthDCG8RBp7aDkw4VS6AdnJ0l' +
  'lHSQDgWXCiGgi2ATLJih5yAHtqU26ZacOlgK0iKXco1HeQ5pGo9r3TIU+t/ee9/7f///933v' +
  'wTmOIHK5nOoJcbVa7QlxX69K0Q8gZYpo1GBp6QMASimEEAB4nue7MDIyTCgUIZN5ECCzLAsh' +
  'BKVSif7p6cdsb8/gODdJp+8Ch8AecAnb/sH6+jeazebx5aEh0LSLvL7zPUB866vG/r7TUdwA' +
  'LhCNfmJ1dQZoAXXgGuPjc6cYVYTGFjh8+8S3Ozj4C03baxMLcQXwgOs0Gj+pVD4Dt4H32PZV' +
  'isUiuq6jlEJK2ek5AKGxBX++QqZbY6VagODgoEk+b1OrmYAJwMAALC9/AWBjA6SsohSMTpk8' +
  'f1kI+BidMvk4l+yUogX0MTu7g+O8IZ0OGq/XIZV62tbaFsufxMP/T4UQl1lc9NjaKpBIBAN2' +
  'dyEcvs/k5DNc10UdTX3+UfI4Jh6Pk81m2THudYktq4GuvyKZ/H1i5s3NG8zPv8B1XZ/if2EY' +
  'ho+00wWlaRCJnGzJNNcIh/2HExPD1GrddSwWQ0pJpfKOlZW1s/qky+Xy+R9/RvEX3wKaS6uF' +
  'TSQAAAAASUVORK5CYII=')

$wxWizard_png = Base64.decode64(
  'iVBORw0KGgoAAAANSUhEUgAAABYAAAAWCAYAAADEtGw7AAAACXBIWXMAAAsTAAALEwEAmpwY' +
  'AAADyUlEQVQ4y9WVTWhcVRTHf+8jM+8lqXmTqJ0nVoy6meAmARW6DIISLaLd1EaKCIJQi9Wm' +
  'iG03UkEEN0oHRFo/aRei1YXUBmXsxpQWO5FojaBt2qSkTa2Z5mMyk5l3z3Hx3kwdtHXlwguH' +
  'x3v3vt8595x7/hf+b8M68cvvevTUFbq6A1ZqigCoggIqqGqLAagk30nWiCKqtNmKLXUevi/E' +
  'PfrDPH6nDyh+W9MfAJuyJ5kaK3Lirq0kyGsh6T+FCVKv8/l3M7hqu5RXhXJtFSsBNkZwcA/Z' +
  'gZCF8rM32HPrq0SGurFwjShBu02n5zQnt4w+RHVgK956j8zFIi9kvqTEYb659cN/yaxSqwkz' +
  'S+B6Dgzc2cG963yMxNNXR/vJ8hrV9X14ZOCz58lk9rGhv+uGWNexWFyp88XSMq4FtKcsejod' +
  '5n78iuDgHqo5qA724QVvAgXIeVSn8gSv5xnvfQKvd4COu3MtUC/tsaanG9IWrgMuqogKK5Ua' +
  'lck8ARAwRZWw9cfJ+JnLhFRDmC1X/gYGqBvBiOAqSiO7nQ8eZOKe89zxydtkOUz1kZF44shF' +
  'DkwGHAn6+PTxZ0gDGQvSnt8CLy8txAU0gq0iRBInVyQ5qwcOcby6A6/wM2NbixzOT5IrVenv' +
  'y7Ft50583yedTl831yKCLapESdUUi3Taoz4xzf3PvUphX0hf7xDD9LJxcorjhSP0hiEjIyNE' +
  'UXRdqIpgowoSR+u2uWSza/F9n3K5HK8c3sjC3DgAxWKR4liBTCbD9hdfYmFhscUisZpdaasK' +
  'IgIIKdeh3fdItTmgEX2T45S8HI4FF6bPAVAYi+FhGLJ79y5cW1vMGBODG1DbdqisRsz+UWPm' +
  'So0LV+qUvr/Emq5bKF1dpB4Zps6eacILhQJBEPDOu/s5MxexWLXjVCSnzDbGQCw9TF+ucejb' +
  'EvuPzrN/dJ73vy5x+nwFVWnmsAEvFotxpoaH+enkKKfPlZvdZyKDraJIUry0C7d1O6y7Obbb' +
  'e2w6PAv5Cxjg1MRvDA4OEoYh2WyWoaEhLv9aSJQP1BhcFcEYpbxSoecmmw0PdDaly7btRrPS' +
  '5l7TkrUBfPTBe7z8yg7y+TwAT295KgYncmo3JNCxIeVCylVSrkXKtXAsBTHUVissLZep1aPY' +
  'otj27n2D8fFxNm/eRC2KMFGElQTlLi6tcPZSGrGspEEE1diZqDRVUaSKSEOVkwUKjz65nWPF' +
  'WVDFsS1WVg1Xl018g7z18THaO3zESHLAFRVBNHkagzQcQuxcBCTeelwDjS8eUXZte+y/u/P+' +
  'BD1fHlfoCgy7AAAAAElFTkSuQmCC')

$wxDialog_png = Base64.decode64(
  'iVBORw0KGgoAAAANSUhEUgAAABYAAAAWCAYAAADEtGw7AAAACXBIWXMAAAsTAAALEwEAmpwY' +
  'AAACLklEQVQ4y7WVQWsTURDHf7vZLompaVPQg+jFa8DiqQe/gMceetNCEQX9Bl5ERBD8AF4q' +
  'Kt562EPqKQfpPSJKMBEEb8FcckmTGmmzb8bDvt1skm6bUjqwzHs7782b+c9/3oMLEicevNrt' +
  'qACoggIqqOrEB6Bi/2PXiCKqLLiKKyOeb95yAFyAFzu/tLAA4fdtir5D2HhLMZ/D/HiPND9w' +
  'uejDz4+UFn2WSnmWSwXKpQLlpSIr5UX8zcc4955QLJV4+u6bAngA6nrsf9kGiHRlK5lT2aJv' +
  'x/2/o4x8I+n/M4yMMzY92/mt11f8TLCcaQ/HinJ0FNLu7PP60W3HA8jn4M7VzrkL1nVvcjg4' +
  'IIEijieo1thYv5voWCqra6c6bTXqXPIdvBxjx9iKp50G1Vry709nvmxEBSNCwgpLnnNLDhAj' +
  '44jVnhJHmNYAvW57LsehCJKOWFTPhGfWmtBIEqSbxjjeEOugWku+aafTayKQSTo0giJqZlqN' +
  'OpXVNVqN+gwc6epnrRHb7mMoUhjHG06jVgYvEE0VzxgzYV6+cmNmS1zAk2wgmNCkWTFLt8+N' +
  'yXuhuRewdX/jRJsYQW2Q7jTd5pG8by8ah6TToszHHeEdt7HXbdPcC8iyfa0FWfdQIl5WVHHa' +
  'Z7VNOO4PhrSH11CViNIa9b2TopHYOkTJxq+MnauScx2GhwN6B2byqn7w8pOKRE+NiiBqtTFI' +
  'fKDlvIokzRDRS6MXTZTdNw8dLlL+A4iuUQ4KRZVvAAAAAElFTkSuQmCC')

# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************

def OnBookTestDlg
  dlg = BookTestDlg.new(self)
  dlg.show_modal
  dlg.destroy
end

def OnCommonDialog(event)
  event.skip
end

def OnDlgIssue_956
  dlg = DlgIssue_956.new(self)
  dlg.show_modal
  dlg.destroy
end

def OnDlgIssue_960
  dlg = DlgIssue_960.new(self)
  dlg.show_modal
  dlg.destroy
end

def OnMainTestDlg
  dlg = MainTestDialog.new(self)
  dlg.show_modal
  dlg.destroy
end

def OnPythonDlg(event)
  event.skip
end

def on_quit(event)
  close(true)
end

def OnWizard
  my_wizard = Wizard.new(self)
  my_wizard.run_wizard(my_wizard.get_page_area_sizer.get_item(0).get_window)
  my_wizard.destroy
end

def on_tools_dlg(event)
  dlg = ToolBarsDialog.new(self)
  dlg.show_modal
  dlg.destroy
end

class App < Wx::App
  def on_init
    frame = MainFrame.new(nil)
    frame.set_title('Ruby SDI Tests')
    frame.show
    set_top_window(frame)
    true
  end
end

App.run