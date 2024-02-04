Dim count As Integer
Dim cancelFlag As Boolean
Sub Start()
    Range("A16").Select
    StartInput
End Sub
Sub StartInput()
    count = 0
    cancelFlag = False
    ScheduleInput
End Sub

Sub ScheduleInput()
    If Not cancelFlag Then
        count = count + 1
        SendKeys "1"
        SendKeys "{RIGHT}"
        Range("H8").Value = count * 30
        Application.OnTime Now + TimeValue("00:00:30"), "ScheduleInput"
    End If
End Sub

Sub StopInput()
    cancelFlag = True
End Sub
Sub Clr()
    Sheet1.Range("A16:AOO16").Clear
End Sub


'Start按钮绑定Start，Stop按钮绑定StopInput，Clear按钮绑定Clr
