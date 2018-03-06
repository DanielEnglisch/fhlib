#ifndef STOPWATCH_H
#define 	 STOPWATCH_H

#include <time.h>

class Stopwatch{
    private:
        static size_t currentTime;
    public:
        static void reset(){
            currentTime = clock();
        };
        static double getTime(){
            return (((double)(clock() - currentTime)) / CLOCKS_PER_SEC);
        };
};

#endif