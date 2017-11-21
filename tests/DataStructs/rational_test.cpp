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
    //     0/1   2/1   1/2   1/2    1/2

    r1 += r2*2; // Implicit convertion from int to rational(int)
    cout << r1; // 4/1

    r2 = r2-r3;
    cout << r2; // 3/2

}