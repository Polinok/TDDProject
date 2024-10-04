#include "complex/complex.h"
#include <iostream>
#include <math.h>

double Complex::abs()
{
    return sqrt(Re * Re + Im * Im);
}

void Complex::view()
{
   std::cout << "   Your complex number = " << Re << ((Im >= 0) ? (" + ") : (" - ")) << ((Im >= 0) ? (Im) : (-Im)) << "i" << std::endl;
}


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
