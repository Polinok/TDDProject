#include "complex/complex.h"
#include <iostream>
#include <math.h>

double Complex::abs()
{
    return sqrt(Re * Re + Im * Im);
}

std::ostream& operator<<(std::ostream & os, Complex  const& c)
{
    os << c.Re << ((c.Im >= 0) ? (" + ") : (" - ")) << ((c.Im >= 0) ? (c.Im) : (-c.Im)) << "i" << std::endl;
    return os;
}

Complex conj(Complex & c1)
{
   Complex res;
   res.Re = c1.Re;
   res.Im = -c1.Im;
   return res;
}

Complex operator+(const Complex& c1, const Complex& c2){
            Complex res;
            res.Re = c1.Re + c2.Re;
            res.Im = c1.Im + c2.Im;
            return res;
}

Complex operator-(const Complex& c1, const Complex& c2){
            Complex res;
            res.Re = c1.Re - c2.Re;
            res.Im = c1.Im - c2.Im;
            return res;
}

Complex operator*(const Complex& c1, const Complex& c2){
            Complex res;
            res.Re = (c1.Re * c2.Re) - (c1.Im * c2.Im);
            res.Im = (c1.Re * c2.Im) + (c1.Im * c2.Re);
            return res;
}

Complex operator/(const Complex& c1, const Complex& c2){
            Complex res;
            res.Re = ((c1.Re * c2.Re) + (c1.Im * c2.Im)) / (c2.Re * c2.Re + c2.Im * c2.Im);
            res.Im = ((c1.Im * c2.Re) - (c1.Re * c2.Im)) / (c2.Re * c2.Re + c2.Im * c2.Im);
            return res;
}

/*
Complex add(Complex & c1, Complex & c2)
{
   Complex res;
   res.Re = c1.Re + c2.Re;
   res.Im = c1.Im + c2.Im;
   return res;
}

Complex dif(Complex & c1, Complex & c2)
{
   Complex res;
   res.Re = c1.Re - c2.Re;
   res.Im = c1.Im - c2.Im;
   return res;
}
*/
