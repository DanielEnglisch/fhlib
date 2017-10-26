@echo off
del test.exe >nul
gcc -o test.exe .\test.c ..\lib\fhlib.a
echo Compiled! Press any key to run test.exe
pause >nul
test.exe
pause