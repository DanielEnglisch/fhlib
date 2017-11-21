#include <iostream>
#include "../../include/DataStructs/rational.h"

using namespace std;

int main(){
    
    rational r1;
    rational r2{2};
    rational r3{12,24};
    rational r4{r3};
    rational r5 = r4; 

    cout << r1 << r2 << r3 << r4 << r5;

}