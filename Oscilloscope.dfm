object Form1: TForm1
  Left = 110
  Top = 0
  Caption = 'Y(X) Oscillograph 2.1 Beta 2'
  ClientHeight = 514
  ClientWidth = 890
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 8
    Top = 8
    Width = 500
    Height = 500
  end
  object PaintBox1: TPaintBox
    Left = 8
    Top = 8
    Width = 500
    Height = 500
    Color = clWhite
    ParentColor = False
    OnPaint = PaintBox1Paint
  end
  object Button1: TButton
    Left = 512
    Top = 448
    Width = 289
    Height = 58
    Caption = 'Start'
    Enabled = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 807
    Top = 448
    Width = 75
    Height = 58
    Caption = 'Reset'
    Enabled = False
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 514
    Top = 313
    Width = 87
    Height = 129
    Caption = #1052#1072#1096#1090#1072#1073
    TabOrder = 2
    object Label1: TLabel
      Left = 31
      Top = 14
      Width = 25
      Height = 25
      Alignment = taCenter
      AutoSize = False
      Caption = '+'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
      OnClick = Label1Click
    end
    object Label2: TLabel
      Left = 13
      Top = 18
      Width = 17
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = 'X'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
    end
    object Label3: TLabel
      Left = 57
      Top = 18
      Width = 17
      Height = 17
      Alignment = taCenter
      AutoSize = False
      Caption = 'Y'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
    end
    object TrackBar2: TTrackBar
      Left = 47
      Top = 37
      Width = 34
      Height = 89
      Max = 9
      Orientation = trVertical
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBoth
      OnChange = TrackBar2Change
    end
    object TrackBar1: TTrackBar
      Left = 3
      Top = 37
      Width = 38
      Height = 89
      Max = 9
      Orientation = trVertical
      TabOrder = 1
      ThumbLength = 15
      TickMarks = tmBoth
      OnChange = TrackBar1Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 514
    Top = 8
    Width = 370
    Height = 150
    Caption = #1050#1072#1085#1072#1083' X '#1079#1085#1072#1095#1077#1085#1080#1081
    TabOrder = 3
    object Shape2: TShape
      Left = 10
      Top = 21
      Width = 350
      Height = 100
    end
    object PaintBox2: TPaintBox
      Left = 10
      Top = 21
      Width = 350
      Height = 100
      Color = clWhite
      ParentColor = False
      OnPaint = PaintBox2Paint
    end
    object Label4: TLabel
      Left = 233
      Top = 127
      Width = 97
      Height = 17
      AutoSize = False
      Caption = 't = 0 '#1089
      Layout = tlCenter
    end
    object Label6: TLabel
      Left = 16
      Top = 127
      Width = 105
      Height = 17
      AutoSize = False
      Caption = #1064#1082#1072#1083#1072' V = '#177' 1-10 '#1042': '
      Layout = tlCenter
    end
    object TrackBar3: TTrackBar
      Left = 127
      Top = 126
      Width = 100
      Height = 20
      Min = 1
      Position = 10
      TabOrder = 0
      ThumbLength = 10
      OnChange = TrackBar3Change
    end
  end
  object GroupBox3: TGroupBox
    Left = 514
    Top = 160
    Width = 370
    Height = 150
    Caption = #1050#1072#1085#1072#1083' Y '#1079#1085#1072#1095#1077#1085#1080#1081
    TabOrder = 4
    object Shape3: TShape
      Left = 10
      Top = 21
      Width = 350
      Height = 100
    end
    object PaintBox3: TPaintBox
      Left = 10
      Top = 21
      Width = 350
      Height = 100
      Color = clWhite
      ParentColor = False
      OnPaint = PaintBox3Paint
    end
    object Label5: TLabel
      Left = 233
      Top = 127
      Width = 97
      Height = 17
      AutoSize = False
      Caption = 't = 0 '#1089
      Layout = tlCenter
    end
    object Label7: TLabel
      Left = 16
      Top = 127
      Width = 105
      Height = 17
      AutoSize = False
      Caption = #1064#1082#1072#1083#1072' V = '#177' 1-10 '#1042': '
      Layout = tlCenter
    end
    object TrackBar4: TTrackBar
      Left = 127
      Top = 127
      Width = 100
      Height = 20
      Min = 1
      Position = 10
      TabOrder = 0
      ThumbLength = 10
      OnChange = TrackBar4Change
    end
  end
  object GroupBox4: TGroupBox
    Left = 607
    Top = 313
    Width = 170
    Height = 80
    Caption = #1064#1072#1075' '#1055#1088#1086#1088#1080#1089#1086#1074#1082#1080
    TabOrder = 5
    object Edit1: TEdit
      Left = 16
      Top = 24
      Width = 49
      Height = 17
      AutoSize = False
      TabOrder = 0
      Text = '1'
      OnExit = Edit1Exit
      OnKeyPress = Edit1KeyPress
    end
    object Button2: TButton
      Left = 71
      Top = 24
      Width = 82
      Height = 17
      Caption = #1051#1080#1085#1077#1081#1085#1099#1081
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button5: TButton
      Left = 16
      Top = 47
      Width = 137
      Height = 26
      Caption = 'Test'
      TabOrder = 2
      OnClick = Button5Click
    end
  end
  object CheckBox1: TCheckBox
    Left = 607
    Top = 422
    Width = 194
    Height = 20
    Caption = #1087#1088#1077#1080#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103' '#1103#1095#1077#1081#1082#1080
    TabOrder = 6
  end
  object Button6: TButton
    Left = 783
    Top = 316
    Width = 99
    Height = 77
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 7
    OnClick = Button6Click
  end
  object MainMenu1: TMainMenu
    Left = 848
    Top = 408
    object gsg1: TMenuItem
      Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072
      object N1: TMenuItem
        Caption = #1048#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072
        OnClick = N1Click
      end
      object N2: TMenuItem
        Caption = #1044#1077#1080#1085#1080#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = '-'
        Enabled = False
      end
      object N4: TMenuItem
        Caption = #1069#1082#1089#1087#1086#1088#1090' '#1076#1072#1085#1085#1099#1093
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = '-'
        Enabled = False
      end
      object N6: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        Default = True
        OnClick = N6Click
      end
    end
    object N15: TMenuItem
      Caption = #1043#1077#1085#1077#1088#1072#1090#1086#1088
      Enabled = False
      OnClick = N15Click
    end
    object N10: TMenuItem
      Caption = '?'
      object N11: TMenuItem
        Caption = #1055#1086#1084#1086#1097#1100
      end
      object N12: TMenuItem
        Caption = '-'
        Enabled = False
      end
      object N13: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      end
    end
  end
end
