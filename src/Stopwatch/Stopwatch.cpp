#include "Stopwatch.h"

  size_t Stopwatch::currentTime = clock();

  void Stopwatch::reset(){
    currentTime = clock();
  }

  double Stopwatch::getTime(){
    return (((double)(clock() - currentTime)) / CLOCKS_PER_SEC);
  }

