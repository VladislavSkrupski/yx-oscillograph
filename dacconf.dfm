object Form4: TForm4
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1050#1086#1085#1092#1080#1075#1091#1088#1080#1088#1086#1074#1072#1085#1080#1077' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1072
  ClientHeight = 144
  ClientWidth = 344
  Color = clBtnFace
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 161
    Height = 97
    Caption = #1056#1077#1078#1080#1084#1099' '#1075#1077#1085#1077#1088#1072#1094#1080#1080
    TabOrder = 0
    object Bevel1: TBevel
      Left = 22
      Top = 70
      Width = 10
      Height = 10
      Shape = bsLeftLine
    end
    object Bevel2: TBevel
      Left = 22
      Top = 70
      Width = 10
      Height = 10
      Shape = bsBottomLine
    end
    object RadioButton1: TRadioButton
      Left = 16
      Top = 24
      Width = 137
      Height = 17
      Caption = #1054#1076#1085#1086#1082#1088#1072#1090#1085#1099#1081' '#1087#1088#1086#1093#1086#1076
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 47
      Width = 137
      Height = 17
      Caption = #1062#1080#1082#1083#1080#1095#1085#1072#1103' '#1075#1077#1085#1077#1088#1072#1094#1080#1103
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object CheckBox1: TCheckBox
      Left = 40
      Top = 70
      Width = 105
      Height = 17
      Caption = #1056#1077#1078#1080#1084' '#1089#1072#1084#1086#1087#1080#1089#1094#1072
      Enabled = False
      TabOrder = 2
    end
  end
  object Button1: TButton
    Left = 8
    Top = 111
    Width = 161
    Height = 26
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 175
    Top = 111
    Width = 161
    Height = 26
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 2
    OnClick = Button2Click
  end
  object GroupBox2: TGroupBox
    Left = 175
    Top = 8
    Width = 161
    Height = 41
    Caption = #1043#1077#1085#1077#1088#1072#1090#1086#1088' '#1090#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
    TabOrder = 3
    object RadioButton3: TRadioButton
      Left = 14
      Top = 16
      Width = 41
      Height = 17
      Caption = '1-'#1099#1081
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton4: TRadioButton
      Left = 96
      Top = 16
      Width = 41
      Height = 17
      Caption = '2-'#1086#1081
      TabOrder = 1
    end
  end
  object GroupBox3: TGroupBox
    Left = 175
    Top = 55
    Width = 161
    Height = 50
    Caption = #1054#1073#1098#1105#1084' '#1076#1072#1085#1085#1099#1093
    TabOrder = 4
    object Label1: TLabel
      Left = 13
      Top = 19
      Width = 85
      Height = 14
      AutoSize = False
      Caption = #1063#1080#1089#1083#1086' '#1079#1085#1072#1095#1077#1085#1080#1081
      Layout = tlCenter
    end
    object Edit1: TEdit
      Left = 104
      Top = 16
      Width = 41
      Height = 21
      TabOrder = 0
      Text = '500'
      OnExit = Edit1Exit
      OnKeyPress = Edit1KeyPress
    end
  end
end
