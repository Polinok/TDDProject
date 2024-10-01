#ifndef COMPLEX_0110_H
#define COMPLEX_0110_H

#include <iostream>

    class Complex_0110 {
    public:

        double Re;
        double Im;

        Complex_0110() {  // конструктор 1
            Re = 0;
            Im = 0;
        };

        Complex_0110(double in_Re) {  // конструктор 2
            Re = in_Re;
            Im = 0;
        };

        Complex_0110(double in_Re, double in_Im) {  // конструктор 3
            Re = in_Re;
            Im = in_Im;
        };

        void view(); // вывод комплексного числа в виде "Re+Imi"

        double abs(); // модуль комплексного числа



        ~Complex_0110() = default; // деструктор
/*
    private:

        double Re;
        double Im;
*/
        };

    //Complex_0110 add(Complex_0110 c1, Complex_0110 c2);

#endif
