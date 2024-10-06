#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

    class Complex {

    public:

        double Re;
        double Im;

        Complex() {  // конструктор 1
            Re = 0;
            Im = 0;
        };

        Complex(double in_Re) {  // конструктор 2
            Re = in_Re;
            Im = 0;
        };

        Complex(double in_Re, double in_Im) {  // конструктор 3
            Re = in_Re;
            Im = in_Im;
        };

        double abs(); // модуль комплексного числа

        ~Complex() = default; // деструктор
/*
    private:

        double Re;
        double Im;
*/
        };

    std::ostream& operator<<(std::ostream & os, Complex  const& c); // переопределение оператора вывода

    Complex conj(Complex & c1); // комплексное сопряжение c1

    Complex operator+(const Complex& c1, const Complex& c2); // переопределение оператора "+"

    Complex operator-(const Complex& c1, const Complex& c2); // переопределение оператора "-"

    Complex operator*(const Complex& c1, const Complex& c2); // переопределение оператора "*"

    Complex operator/(const Complex& c1, const Complex& c2); // переопределение оператора "/"

    // Complex add(Complex & c1, Complex & c2); // сумма комплексных чисел c1 и c2

    // Complex dif(Complex & c1, Complex & c2); // разность комплексных чисел c1 и c2

#endif
