#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class rational final{
    private:
        int num {0};
        int den {1};
        int gcd(int a, int b){
            while (b != 0){
                int r = a % b;
                a = b;
                b = r;
            }
            return a;
        };
    public: 
        rational() = default;
        rational(const int n);
        : rational {n, 1}
        { };
        rational(const int n, const int d)
        : num {n}
        , den {d}
        {
            simplify();
        }
        rational(const rational &) = default;

        rational& operator = (const rational &r) = default;
        rational& operator = (const int r){
            rational {i};
            simplify();
            return this;
        };
        std::ostream& print(std::ostream &s = std::cout)const{
            return s << "[ " << num << " / " << den;
        };

        void simplify(){
            int g = gcd(num, den);
            if(g != 0){
                num /= g;
                den /= g;
            }
        };

        rational& operator *= (const rational &r){
            num *= r.num;
            den *= r.den;
            simplify();
            return *this;
        };
        rational& operator /= (const rational &r){
            num *= r.den;
            den *= r.num;
            simplify();
            return *this;
        };
        rational& operator += (const rational &r){
            num = (num * r.den) + (r.num * den);
            den *= r.den;
            simplify();
            return *this;
        };
        rational& operator -= (const rational &r){
            num = (num * r.den) - (r.num * den);
            den *= r.den;
            simplify();
            return *this;
        };
};

std::ostream& operator << (std::ostream &s, const rational &r){
    r.print(s);
    return s;
}

rational operator * (const rational &l,const rational &r){
    auto res {l};
    return res *= r;
}
rational operator / (const rational &l,const rational &r){
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

#endif