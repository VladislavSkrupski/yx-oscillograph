object Form6: TForm6
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1043#1077#1085#1077#1088#1072#1090#1086#1088
  ClientHeight = 344
  ClientWidth = 536
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
    Left = 335
    Top = 250
    Width = 193
    Height = 40
    Caption = 'OK'
    Enabled = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 8
    Width = 520
    Height = 236
    Caption = #1043#1077#1085#1077#1088#1080#1088#1091#1077#1084#1099#1081' '#1089#1080#1075#1085#1072#1083
    TabOrder = 1
    object Shape1: TShape
      Left = 10
      Top = 26
      Width = 500
      Height = 200
    end
    object PaintBox1: TPaintBox
      Left = 10
      Top = 26
      Width = 500
      Height = 200
      OnPaint = PaintBox1Paint
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 250
    Width = 321
    Height = 40
    Caption = #1055#1080#1083#1072
    TabOrder = 2
    object Label10: TLabel
      Left = 10
      Top = 15
      Width = 17
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = 't ='
      Layout = tlCenter
    end
    object Label11: TLabel
      Left = 109
      Top = 15
      Width = 17
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = 'V ='
      Layout = tlCenter
    end
    object Label7: TLabel
      Left = 85
      Top = 15
      Width = 17
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = 'c'
      Layout = tlCenter
    end
    object Label8: TLabel
      Left = 188
      Top = 15
      Width = 12
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = #1084#1042
      Layout = tlCenter
    end
    object Bevel1: TBevel
      Left = 102
      Top = 15
      Width = 1
      Height = 17
      Shape = bsLeftLine
    end
    object Button4: TButton
      Left = 206
      Top = 14
      Width = 110
      Height = 20
      Caption = #1042#1074#1077#1089#1090#1080' '#1074' '#1084#1072#1089#1089#1080#1074
      TabOrder = 0
      OnClick = Button4Click
    end
    object Edit5: TEdit
      Left = 33
      Top = 15
      Width = 50
      Height = 17
      AutoSize = False
      TabOrder = 1
      Text = '30'
      OnExit = Edit5Exit
      OnKeyPress = Edit5KeyPress
    end
    object Edit6: TEdit
      Left = 132
      Top = 15
      Width = 50
      Height = 17
      AutoSize = False
      TabOrder = 2
      Text = '10000'
      OnExit = Edit6Exit
      OnKeyPress = Edit6KeyPress
    end
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 296
    Width = 520
    Height = 40
    Caption = #1059#1088#1086#1074#1077#1085#1100
    TabOrder = 3
    object Label1: TLabel
      Left = 10
      Top = 15
      Width = 17
      Height = 17
      AutoSize = False
      Caption = 't = '
      Layout = tlCenter
    end
    object Label2: TLabel
      Left = 85
      Top = 15
      Width = 17
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = #1089
      Layout = tlCenter
    end
    object Bevel2: TBevel
      Left = 102
      Top = 15
      Width = 1
      Height = 17
      Shape = bsLeftLine
    end
    object Label3: TLabel
      Left = 109
      Top = 15
      Width = 17
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = 'V ='
      Layout = tlCenter
    end
    object Label4: TLabel
      Left = 200
      Top = 15
      Width = 17
      Height = 17
      AutoSize = False
      Caption = #1084#1042
      Layout = tlCenter
    end
    object Label5: TLabel
      Left = 128
      Top = 15
      Width = 17
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = '+'
      Layout = tlCenter
      OnClick = Label5Click
    end
    object Button2: TButton
      Left = 376
      Top = 13
      Width = 141
      Height = 20
      Caption = #1042#1074#1077#1089#1090#1080' '#1074' '#1084#1072#1089#1089#1080#1074
      TabOrder = 0
      OnClick = Button2Click
    end
    object Edit1: TEdit
      Left = 33
      Top = 15
      Width = 50
      Height = 17
      TabOrder = 1
      Text = '30'
      OnExit = Edit1Exit
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 145
      Top = 15
      Width = 50
      Height = 17
      TabOrder = 2
      Text = '10000'
      OnExit = Edit2Exit
      OnKeyPress = Edit2KeyPress
    end
    object Button3: TButton
      Left = 220
      Top = 13
      Width = 150
      Height = 20
      Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1091#1088#1086#1074#1085#1103
      TabOrder = 3
      OnClick = Button3Click
    end
  end
end
