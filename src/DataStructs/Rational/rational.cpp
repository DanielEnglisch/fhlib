/*CPP**********************************************************************
* FILENAME :        rational.h
*
* DESCRIPTION :
*       rational struct
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

#include "rational.h"

rational::rational(const int n)
  : rational{n,1}
{
}

rational::rational(const int n, const int d)
  : num(n), den(d)
{
   simplify();
}

rational& rational::operator = (const int i){
  rational{i};
  simplify();
  return *this;
}

std::ostream& rational::print(std::ostream &s)const{
  return s << num << " / " << den << std::endl;
}

std::ostream& operator << (std::ostream &s, const rational &r){
 r.print(s);
 return s;
}

rational& rational::operator *= (const rational &r){
  num *= r.num;
  den *= r.den;
  simplify();
  return *this;
}

rational&  rational::operator /= (const rational &r){
  num *= r.den;
  den *= r.num;
  simplify();
  return *this;
}
rational&  rational::operator += (const rational &r){
  num = (num*r.den) + (r.num*den);
  den *= r.den;
  simplify();
  return *this;
}

rational&  rational::operator -= (const rational &r){
  num = (num*r.den) - (r.num*den);
  den *= r.den;
  simplify();
  return *this;
}


rational operator * (const rational &l,const rational &r){
  auto res {l};
  return res *= r;
}

rational  operator / (const rational &l,const rational &r){
  auto res {l};
  return res /= r;
}

rational operator + (const rational &l,const rational &r){
  auto res {l};
  return res += r;
}
rational operator - (const rational &l,const rational &r){
  auto res {l};
  return res -= r;
}

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void rational::simplify(){
  int g = gcd(num, den);
  if(g != 0){
     num /= g;
     den /= g;
  }
}


