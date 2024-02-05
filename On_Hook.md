Dim count As Integer
Dim cancelFlag As Boolean
Sub Start()
    Clr
    Range("A16").Select
    StartInput
End Sub
Sub StartInput()
    count = 0
    cancelFlag = False
    ScheduleInput_Right
End Sub

Sub ScheduleInput_Right()
    If Not cancelFlag Then
        count = count + 1
        SendKeys count, False
        SendKeys "{RIGHT}", False
        Range("H8").Value = count
        Application.OnTime Now + TimeValue("00:00:01"), "ScheduleInput_Down"
        ELSE Range("A18").Value = "Interrupt Successful"
    End If
End Sub

Sub ScheduleInput_Down()
    If Not cancelFlag Then
        count = count + 1
        SendKeys count, False
        SendKeys "{DOWN}", False
        Range("H8").Value = count
        Application.OnTime Now + TimeValue("00:00:01"), "ScheduleInput_Left"
        ELSE Range("A18").Value = "Interrupt Successful"
    End If
End Sub

Sub ScheduleInput_Left()
    If Not cancelFlag Then
        count = count + 1
        SendKeys count, False
        SendKeys "{LEFT}", False
        Range("H8").Value = count
        Application.OnTime Now + TimeValue("00:00:01"), "ScheduleInput_Up"
        ELSE Range("A18").Value = "Interrupt Successful"
    End If
End Sub

Sub ScheduleInput_Up()
    If Not cancelFlag Then
        count = count + 1
        SendKeys count, False
        SendKeys "{UP}", False
        Range("H8").Value = count
        Application.OnTime Now + TimeValue("00:00:01"), "ScheduleInput_Right"
        ELSE Range("A18").Value = "Interrupt Successful"
    End If
End Sub

Sub StopInput()
    cancelFlag = True
End Sub

Sub Clr()
    Sheet1.Range("A16:B18").Clear
    Sheet1.Range("H8").Value = 0
End Sub
