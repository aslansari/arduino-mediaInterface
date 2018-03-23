Set Shell = CreateObject("WScript.Shell")
Shell.Run Chr(34) & "fullPathToBatchFile" & Chr(34), 0
Set Shell = Nothing