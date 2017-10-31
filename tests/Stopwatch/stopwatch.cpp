#include "../../include/fhlib.h"
#include <stdio.h>

int main(){
	printf("oida\n");
	Stopwatch::reset();
	
	for(double i = 0; i < 10000; i++){
			printf("oida\n");
	}
	
	printf("%f", Stopwatch::getTime());
  
  
  return 0;
}