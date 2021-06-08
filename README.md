# keylogger
A windows keylogger which runs in the background at machine boot and maintains persistence

It creates a hidden directory 'C:\w32_service' and a 'log.txt' file

Uses the Windows API GetAsyncKeyState to get the keystrokes

Logs all the keystrokes in log.txt

NOTE: This is only for educational purpose. Please don't use it for malicious purposes.
