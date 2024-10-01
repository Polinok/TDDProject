#include "complex_0110/complex_0110.h"
#include <iostream>
#include <math.h>

double Complex_0110::abs()
{
    return sqrt(Re * Re + Im * Im);
}

void Complex_0110::view(){
   std::cout << "Your complex number = " << Re << "+" << Im << "i" << std::endl;
}

/*
Complex_0110  add(Complex_0110 & c1, Complex_0110 & c2){
   Complex_0110 res;
   res.Re = c1.Re + c2.Re;
   res.Im = c1.Im + c2.Im;
   return res;
}
 */
