object Form2: TForm2
  Left = 329
  Top = 307
  BorderStyle = bsNone
  Caption = #1048#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072
  ClientHeight = 213
  ClientWidth = 296
  Color = clBtnFace
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel2: TBevel
    Left = 16
    Top = 132
    Width = 260
    Height = 20
  end
  object Bevel1: TBevel
    Left = 8
    Top = 115
    Width = 280
    Height = 90
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 16
    Top = 132
    Width = 260
    Height = 20
    Alignment = taCenter
    AutoSize = False
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = False
    Layout = tlCenter
  end
  object Button1: TButton
    Left = 16
    Top = 164
    Width = 130
    Height = 30
    Caption = #1048#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 146
    Top = 164
    Width = 130
    Height = 30
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 280
    Height = 101
    Caption = #1050#1072#1085#1072#1083#1099' '#1040#1062#1055
    TabOrder = 2
    object RadioButton1: TRadioButton
      Left = 40
      Top = 24
      Width = 81
      Height = 17
      Caption = '1-'#1099#1081' '#1080' 2-'#1086#1081
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 40
      Top = 47
      Width = 81
      Height = 17
      Caption = '1-'#1099#1081' '#1080' 3-'#1080#1081
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 40
      Top = 70
      Width = 81
      Height = 17
      Caption = '1-'#1099#1081' '#1080' 4-'#1099#1081
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 151
      Top = 24
      Width = 81
      Height = 17
      Caption = '2-'#1086#1081' '#1080' 3-'#1080#1081
      TabOrder = 3
      OnClick = RadioButton4Click
    end
    object RadioButton5: TRadioButton
      Left = 151
      Top = 47
      Width = 81
      Height = 17
      Caption = '2-'#1086#1081' '#1080' 4-'#1099#1081
      TabOrder = 4
      OnClick = RadioButton5Click
    end
    object RadioButton6: TRadioButton
      Left = 151
      Top = 70
      Width = 81
      Height = 17
      Caption = '3-'#1080#1081' '#1080' 4-'#1099#1081
      TabOrder = 5
      OnClick = RadioButton6Click
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 248
    Top = 48
  end
end
