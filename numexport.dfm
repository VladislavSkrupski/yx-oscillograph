object Form7: TForm7
  Left = 0
  Top = 0
  Caption = #1069#1082#1089#1087#1086#1088#1090
  ClientHeight = 87
  ClientWidth = 281
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 55
    Width = 129
    Height = 25
    Caption = #1054#1050
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 143
    Top = 55
    Width = 130
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 265
    Height = 41
    Caption = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1091#1077#1084#1099#1077' '#1079#1085#1072#1095#1077#1085#1080#1103
    TabOrder = 2
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 129
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1082#1072#1078#1076#1086#1077
      Layout = tlCenter
    end
    object Label2: TLabel
      Left = 199
      Top = 16
      Width = 47
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = #1079#1085#1072#1095#1077#1085#1080#1077
      Layout = tlCenter
    end
    object Edit1: TEdit
      Left = 151
      Top = 15
      Width = 42
      Height = 17
      AutoSize = False
      TabOrder = 0
      Text = '1'
      OnExit = Edit1Exit
      OnKeyPress = Edit1KeyPress
    end
  end
end
