object Form5: TForm5
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1050#1086#1085#1092#1080#1075#1091#1088#1080#1088#1086#1074#1072#1085#1080#1077' '#1072#1085#1072#1083#1080#1079#1072#1090#1086#1088#1072
  ClientHeight = 143
  ClientWidth = 379
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
  object Button1: TButton
    Left = 119
    Top = 110
    Width = 122
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 247
    Top = 110
    Width = 122
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 110
    Width = 105
    Height = 23
    Caption = #1056#1077#1078#1080#1084' '#1089#1072#1084#1086#1087#1080#1089#1094#1072
    TabOrder = 2
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 161
    Height = 41
    Caption = #1043#1077#1085#1077#1088#1072#1090#1086#1088' '#1090#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
    TabOrder = 3
    object RadioButton1: TRadioButton
      Left = 16
      Top = 16
      Width = 41
      Height = 17
      Caption = '1-'#1099#1081
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 103
      Top = 16
      Width = 41
      Height = 17
      Caption = '2-'#1086#1081
      TabOrder = 1
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 55
    Width = 161
    Height = 49
    Caption = #1054#1073#1098#1105#1084' '#1076#1072#1085#1085#1099#1093
    TabOrder = 4
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 81
      Height = 22
      AutoSize = False
      Caption = #1063#1080#1089#1083#1086' '#1079#1085#1072#1095#1077#1085#1080#1081
      Layout = tlCenter
    end
    object Edit1: TEdit
      Left = 103
      Top = 17
      Width = 44
      Height = 21
      TabOrder = 0
      Text = '1000'
      OnExit = Edit1Exit
      OnKeyPress = Edit1KeyPress
    end
  end
  object GroupBox3: TGroupBox
    Left = 175
    Top = 8
    Width = 194
    Height = 96
    Caption = #1050#1072#1085#1072#1083#1099' '#1040#1062#1055
    TabOrder = 5
    object RadioButton3: TRadioButton
      Left = 16
      Top = 16
      Width = 81
      Height = 17
      Caption = '1-'#1099#1081' '#1080' 2-'#1086#1081
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 16
      Top = 39
      Width = 81
      Height = 17
      Caption = '1-'#1099#1081' '#1080' 3-'#1080#1081
      TabOrder = 1
      OnClick = RadioButton4Click
    end
    object RadioButton5: TRadioButton
      Left = 16
      Top = 62
      Width = 81
      Height = 17
      Caption = '1-'#1099#1081' '#1080' 4-'#1099#1081
      TabOrder = 2
      OnClick = RadioButton5Click
    end
    object RadioButton6: TRadioButton
      Left = 103
      Top = 16
      Width = 81
      Height = 17
      Caption = '2-'#1086#1081' '#1080' 3-'#1080#1081
      TabOrder = 3
      OnClick = RadioButton6Click
    end
    object RadioButton7: TRadioButton
      Left = 103
      Top = 39
      Width = 82
      Height = 17
      Caption = '2-'#1086#1081' '#1080' 4-'#1099#1081
      TabOrder = 4
      OnClick = RadioButton7Click
    end
    object RadioButton8: TRadioButton
      Left = 103
      Top = 62
      Width = 82
      Height = 17
      Caption = '3-'#1080#1081' '#1080' 4-'#1099#1081
      TabOrder = 5
      OnClick = RadioButton8Click
    end
  end
end
