/*CPP**********************************************************************
* FILENAME :        Stopwatch.cpp
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
*CPP*/

#include "Stopwatch.h"

  size_t Stopwatch::currentTime = clock();

  void Stopwatch::reset(){
    currentTime = clock();
  }

  double Stopwatch::getTime(){
    return (((double)(clock() - currentTime)) / CLOCKS_PER_SEC);
  }

