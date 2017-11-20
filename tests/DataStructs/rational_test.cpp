#include <iostream>
#include "../../include/DataStructs/rational.h"

using namespace std;

int main(){
    // Constructor tests
    rational r1;        // 0/1
    rational r2{2};     // 2/1
    rational r3{4,10};  // 4/10
    rational r4{r3};    // 4/10
    rational r5 = r4;   // 4/10

    cout << r1 << r2 << r3 << r4 << r5;
    
    // Calculations
    r4 *= r2;
    r1 -= 10;
    cout << r1 ;
    r3 += {6,10};
    cout << r3 ;
    cout << r3 - r4 ;

    cout << r4;
    cout << r4 + r2;
    cout << r4 * r2;
    cout << r4 - r2;
    cout << r4 / r2;

}