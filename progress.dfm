object Form5: TForm5
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'Form5'
  ClientHeight = 79
  ClientWidth = 241
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 10
    Top = 10
    Width = 220
    Height = 57
  end
  object CGauge1: TCGauge
    Left = 20
    Top = 20
    Width = 200
    Height = 20
  end
  object Label1: TLabel
    Left = 20
    Top = 46
    Width = 200
    Height = 15
    Alignment = taCenter
    AutoSize = False
    Layout = tlCenter
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 192
    Top = 40
  end
  object Timer2: TTimer
    Enabled = False
    OnTimer = Timer2Timer
    Left = 152
    Top = 40
  end
end
