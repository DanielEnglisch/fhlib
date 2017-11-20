#include "rational.h"

rational::rational(const int n)
  : rational{n,1}
{

}

rational::rational(const int n, const int d)
  : num(n), den(d)
{
}

rational& rational::operator = (const int i){
  rational{i};
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
  return *this;
}

rational&  rational::operator /= (const rational &r){
  num *= r.den;
  den *= r.num;
  return *this;
}
rational&  rational::operator += (const rational &r){
  num = (num*r.den) + (r.num*den);
  den *= r.den;
  return *this;
}

rational&  rational::operator -= (const rational &r){
  num = (num*r.den) - (r.num*den);
  den *= r.den;
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


