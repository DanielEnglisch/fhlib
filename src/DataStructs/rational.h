#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class rational final{
  private:
    int num {0};
    int den {1};
  public: 
    rational() = default;                                   // r1
    rational(const int n);                                  // r1{4}
    rational(const int n, const int d);                     // r1{1,4}
    rational(const rational &) = default;                   // r1{r2}

    rational& operator = (const rational &r) = default;     // r1 = r2
    rational& operator = (const int r);                     // r1 = 3
    std::ostream& print(std::ostream &s = std::cout)const;  // r1.print(std::cout) OR std::cout << r1.print()

    rational& operator *= (const rational &r);              // r1 *= r2
    rational& operator /= (const rational &r);              // r1 /= r2
    rational& operator += (const rational &r);              // r1 += r2
    rational& operator -= (const rational &r);              // r1 -= r2

};

std::ostream& operator << (std::ostream &s, const rational &r);   // std:cout << r1

rational operator * (const rational &l,const rational &r);        // r1 = r2 * r3
rational operator / (const rational &l,const rational &r);        // r1 = r2 / r3
rational operator + (const rational &l,const rational &r);        // r1 = r2 + r3
rational operator - (const rational &l,const rational &r);        // r1 = r2 - r3


#endif