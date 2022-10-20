Imports System.Windows.Forms
Imports AutomationServerTypeLibForDotNet64Bit

Public Class VBAutomationClient
    Inherits Form
    Public Sub New()
        Dim MyIDispatch As Object
        Dim MyRef As New CMyMathClass()
        MyIDispatch = MyRef

        Dim iNum1 = 175
        Dim iNum2 = 125
        Dim iSum = MyIDispatch.SumOfTwoIntegers(iNum1, iNum2)
        Dim str As String = String.Format("Sum of {0} & {1} is {2}", iNum1, iNum2, iSum)
        MsgBox(str)

        Dim iSub = MyIDispatch.SubtractionOfTwoIntegers(iNum1, iNum2)
        str = String.Format("Subtraction of {0} & {1} is {2}", iNum1, iNum2, iSub)
        MsgBox(str)

        End

    End Sub

    <STAThread()>
    Shared Sub Main()
        Application.EnableVisualStyles()
        Application.Run(New VBAutomationClient())
    End Sub

End Class

' Cmd to compile
' vbc.exe /t:winexe /r:Microsoft.VisualBasic.dll /r:AutomationServerTypeLibForDotNet64Bit.dll VBAutomationClient64Bit.vb
' add switch /platform:x86 for 32-bit