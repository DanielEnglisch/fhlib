@echo off
gcc -c Stopwatch\Stopwatch.c -o Stopwatch.o
gcc -c ArrayUtils\ArrayUtils.c -o ArrayUtils.o
ar cr fhlib.a Stopwatch.o ArrayUtils.o
del Stopwatch.o ArrayUtils.o
pause