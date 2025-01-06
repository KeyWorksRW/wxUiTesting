###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

WX_GLOBAL_CONSTANTS = true unless defined? WX_GLOBAL_CONSTANTS

require 'wx/core'
require 'wx/aui'

require_relative 'images'
require 'zlib'
require 'base64'
require 'stringio'

class PythonDlg < Wx::Dialog
  def initialize(parent, id = Wx::ID_ANY, title = 'Hello Python Dialog!',
                 pos = Wx::DEFAULT_POSITION, size = Wx::DEFAULT_SIZE,
                 style = Wx::DEFAULT_DIALOG_STYLE)

    super(parent, id, title, pos, size, style)

    bSizer1 = Wx::BoxSizer.new(Wx::VERTICAL)

    box_sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    @auiToolBar = Wx::AUI::AuiToolBar.new(self, Wx::ID_ANY,
      Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::AUI::AUI_TB_PLAIN_BACKGROUND|
      Wx::AUI::AUI_TB_DEFAULT_STYLE)
    @auiToolBar.add_label(Wx::ID_ANY, 'Label')
    tool_2 = @auiToolBar.add_tool(Wx::ID_ANY, 'Searching', wxue_get_bundle($fontPicker_png,
      $fontPicker_1_25x_png, $fontPicker_1_5x_png), Wx::NULL_BITMAP,
      Wx::ITEM_NORMAL, 'This tool should be initially disabled.',
      'This tool should be initially disabled.', nil)
    tool_2.set_state(Wx::AUI::AUI_BUTTON_STATE_NORMAL|
      Wx::AUI::AUI_BUTTON_STATE_DISABLED)
    @auiToolBar.add_spacer(@auiToolBar.from_dip(10))

    @spinCtrl = Wx::SpinCtrl.new(@auiToolBar)
    @auiToolBar.add_control(@spinCtrl)
    @auiToolBar.realize
    box_sizer.add(@auiToolBar, Wx::SizerFlags.new.border(Wx::ALL))

    @staticText = Wx::StaticText.new(self, Wx::ID_ANY,
      'wxPython est génial n\'est-ce pas?', from_dip(Wx::Point.new(100, 250)),
      from_dip(Wx::Size.new(300, 80)), Wx::ALIGN_CENTER_HORIZONTAL, name=
    'my_text')
    @staticText.set_window_variant(Wx::WINDOW_VARIANT_LARGE)
    @staticText.set_foreground_colour(Wx::Colour.new('#008000'))
    box_sizer.add(@staticText, Wx::SizerFlags.new.center.border(Wx::ALL))

    box_sizer2 = Wx::BoxSizer.new(Wx::HORIZONTAL)

    _svg_string_ = Zlib::Inflate.inflate(Base64.decode64($face_smile_svg))
    bmp = Wx::StaticBitmap.new(self, Wx::ID_ANY, Wx::BitmapBundle.from_svg(_svg_string_,
      Wx::Size.new(32, 32)))
    box_sizer2.add(bmp, Wx::SizerFlags.new.border(Wx::ALL))

    bmp2 = Wx::StaticBitmap.new(self, Wx::ID_ANY, wxue_get_bundle($hide_png))
    box_sizer2.add(bmp2, Wx::SizerFlags.new.border(Wx::ALL))

    bmp3 = Wx::StaticBitmap.new(self, Wx::ID_ANY, wxue_get_bundle($timer_png))
    box_sizer2.add(bmp3, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer.add(box_sizer2, Wx::SizerFlags.new.border(Wx::ALL))

    @checkPlayAnimation = Wx::CheckBox.new(self, Wx::ID_ANY, 'Play Animation')
    static_box_2 = Wx::StaticBoxSizer.new(Wx::StaticBox.new(self, Wx::ID_ANY, @checkPlayAnimation
      ), Wx::VERTICAL)

    @toggleBtn = Wx::ToggleButton.new(static_box_2.get_static_box, Wx::ID_ANY,
      'Play Animation', Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::BU_EXACTFIT)
    static_box_2.add(@toggleBtn, Wx::SizerFlags.new.border(Wx::ALL))

    @animation_ctrl = Wx::AnimationCtrl.new(static_box_2.get_static_box,
      Wx::ID_ANY, get_animation($clr_hourglass_gif), Wx::DEFAULT_POSITION,
      Wx::DEFAULT_SIZE, Wx::AC_DEFAULT_STYLE)
    @animation_ctrl.set_inactive_bitmap(wxue_get_bundle($disabled_png))
    static_box_2.add(@animation_ctrl, Wx::SizerFlags.new.border(Wx::ALL))

    box_sizer.add(static_box_2, Wx::SizerFlags.new.border(Wx::ALL))

    bSizer1.add(box_sizer, Wx::SizerFlags.new.expand.border(Wx::ALL))

    if Wx::PLATFORM != 'WXMAC'
      @stdBtn_line = Wx::StaticLine.new(self, Wx::ID_ANY, Wx::DEFAULT_POSITION,
                                      Wx::Size.new(20, -1))
      bSizer1.add(@stdBtn_line, Wx::SizerFlags.new.expand.border(Wx::ALL))
    end
    @stdBtn = Wx::StdDialogButtonSizer.new
    @stdBtn_ok = Wx::Button.new(self, Wx::ID_OK)
    @stdBtn.add_button(@stdBtn_ok)
    @stdBtn_ok.set_default
    @stdBtn_close = Wx::Button.new(self, Wx::ID_CLOSE)
    @stdBtn.add_button(@stdBtn_close)
    @stdBtn.add_button(Wx::ContextHelpButton.new(self, Wx::ID_CONTEXT_HELP))
    @stdBtn.realize
    bSizer1.add(@stdBtn, Wx::SizerFlags.new.expand.border(Wx::ALL))

    if pos != Wx::DEFAULT_POSITION
      set_position(from_dip(pos))
    end
    if size == Wx::DEFAULT_SIZE
      set_sizer_and_fit(bSizer1)
    else
      set_sizer(bSizer1)
      if size.x == Wx::DEFAULT_COORD || size.y == Wx::DEFAULT_COORD
        fit
      end
      set_size(from_dip(size))
      layout
    end
    centre(Wx::BOTH)

    # Event handlers
    evt_update_ui(@stdBtn_close.get_id, :on_update_close)
    evt_button(@stdBtn_close.get_id, :on_close)
    evt_checkbox(@checkPlayAnimation.get_id, :OnEvent)
    evt_init_dialog(:OnInit)
    evt_togglebutton(@toggleBtn.get_id, :OnEvent)
  end

  # Loads image from a string and returns a Wx::Animation object.
  def get_animation(image_name)
    animation = Wx::Animation.new
    animation.load(StringIO.new(image_name))
    return animation
  end

# ../art/timer.png
$timer_png = Base64.decode64(
  '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')

# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************

  def OnEvent(event)
    event.skip
  end

  def OnInit(event)
    event.skip
  end

  def on_close(event)
    end_modal(Wx::ID_CLOSE)
  end

  def on_update_close(event)
    @stdBtn_close.set_label('Close Me!')
  end

end