@echo off
del test.exe >nul
g++ -o test.exe .\stopwatch.cpp ..\..\lib\fhlib.a
echo Compiled! Press any key to run test.exe
pause >nul
test.exe
pause