@echo off
gcc -c Stopwatch\Stopwatch.c -o Stopwatch.o
ar rvs fhlib.a Stopwatch.o
del Stopwatch.o
move fhlib.a ..\lib\fhlib.a
pause