@echo off
del test.exe
gcc -o test.exe .\test.c ..\lib\fhlib.a
test.exe
pause