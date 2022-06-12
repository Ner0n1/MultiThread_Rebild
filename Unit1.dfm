object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 145
  ClientWidth = 511
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 243
    Height = 15
    Caption = 'Status:'
  end
  object Label2: TLabel
    Left = 8
    Top = 25
    Width = 76
    Height = 15
    Caption = #1056#1072#1079#1084#1077#1088' '#1073#1083#1086#1082#1072
  end
  object Label3: TLabel
    Left = 8
    Top = 75
    Width = 65
    Height = 15
    Caption = #1041#1091#1082#1074#1072' '#1076#1080#1089#1082#1072
  end
  object Label4: TLabel
    Left = 320
    Top = 57
    Width = 114
    Height = 15
    Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1085#1086' '#1073#1083#1086#1082#1086#1074':'
  end
  object Label5: TLabel
    Left = 456
    Top = 57
    Width = 3
    Height = 15
  end
  object Edit1: TEdit
    Left = 8
    Top = 48
    Width = 121
    Height = 23
    TabOrder = 0
    Text = '4'
  end
  object Button1: TButton
    Left = 176
    Top = 47
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 176
    Top = 95
    Width = 75
    Height = 25
    Caption = 'Stop'
    Enabled = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 8
    Top = 96
    Width = 121
    Height = 23
    TabOrder = 3
    Text = '\\\\.\\C:'
  end
end
