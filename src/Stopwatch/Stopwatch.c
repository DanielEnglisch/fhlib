#include "Stopwatch.h"
#include <time.h>

clock_t currentTime = 0;

void startStopwatch(){
	currentTime = clock();
}

double getTime(){
	return (((double)(clock() - currentTime)) / CLOCKS_PER_SEC);
}