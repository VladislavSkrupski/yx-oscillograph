object Form3: TForm3
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1050#1086#1085#1092#1080#1075#1091#1088#1080#1088#1086#1074#1072#1085#1080#1077' '#1082#1086#1084#1087#1083#1077#1082#1089#1072
  ClientHeight = 128
  ClientWidth = 331
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
    Left = 8
    Top = 95
    Width = 153
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 167
    Top = 95
    Width = 154
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 313
    Height = 81
    Caption = #1042#1085#1091#1090#1088#1077#1085#1085#1080#1077' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1099' '#1090#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
    TabOrder = 2
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 85
      Height = 20
      Alignment = taCenter
      AutoSize = False
      Caption = '1-'#1099#1081' '#1075#1077#1085#1077#1088#1072#1090#1086#1088
      Layout = tlCenter
    end
    object Label2: TLabel
      Left = 16
      Top = 50
      Width = 85
      Height = 20
      Alignment = taCenter
      AutoSize = False
      Caption = '2-'#1086#1081' '#1075#1077#1085#1077#1088#1072#1090#1086#1088
      Layout = tlCenter
    end
    object Label3: TLabel
      Left = 207
      Top = 24
      Width = 98
      Height = 20
      AutoSize = False
      Caption = #1085#1089' = 10 '#1084#1082#1089
      Layout = tlCenter
    end
    object Label4: TLabel
      Left = 207
      Top = 50
      Width = 98
      Height = 20
      AutoSize = False
      Caption = #1085#1089' = 10 '#1084#1082#1089
      Layout = tlCenter
    end
    object Edit1: TEdit
      Left = 107
      Top = 24
      Width = 94
      Height = 21
      TabOrder = 0
      Text = '10000'
      OnChange = Edit1Change
      OnExit = Edit1Exit
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 107
      Top = 50
      Width = 94
      Height = 21
      TabOrder = 1
      Text = '10000'
      OnChange = Edit2Change
      OnExit = Edit2Exit
      OnKeyPress = Edit2KeyPress
    end
  end
end
