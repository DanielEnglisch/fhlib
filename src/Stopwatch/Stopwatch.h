/*H**********************************************************************
* FILENAME :        Stopwatch.h
*
* DESCRIPTION :
*       Stopwatch functionality
*
* NOTES :
*
*
*
* AUTHOR :    Daniel Englisch        START DATE :    26.11.17
*
* CHANGES :
*
*H*/

#if !defined STOPWATCH_H
#define 	 STOPWATCH_H
#include <time.h>

class Stopwatch{
  
  private:
    static size_t currentTime;
  public:
    static void reset();
    static double getTime();

};

#endif