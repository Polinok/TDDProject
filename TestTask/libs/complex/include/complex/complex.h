#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <math.h>

    template <typename T>
    class Complex {

    public:

        T Re;
        T Im;

        Complex() {  // конструктор 1
            Re = 0;
            Im = 0;
        };

        Complex(T in_Re) {  // конструктор 2
            Re = in_Re;
            Im = 0;
        };

        Complex(T in_Re, T in_Im) {  // конструктор 3
            Re = in_Re;
            Im = in_Im;
        };

        // double abs(); // модуль комплексного числа
        double abs()
        {
            return sqrt((double)Re * (double)Re + (double)Im * (double)Im);
        }

        // переопределение оператора "=="
        bool operator==(const Complex<T>& other) const {
               return Re == other.Re && Im == other.Im;
        }

        ~Complex() = default; // деструктор
/*
    private:

        double Re;
        double Im;
*/
        };

    // переопределение оператора вывода
    template <typename T>
    std::ostream& operator<<(std::ostream & os, Complex<T>  const& c)
    {
        os << c.Re << ((c.Im >= 0) ? (" + ") : (" - ")) << ((c.Im >= 0) ? (c.Im) : (-c.Im)) << "i \n";
        return os;
    }

    // комплексное сопряжение c1
    template <typename T>
    Complex<T> conj(Complex<T> & c1)
    {
       Complex<T> res;
       res.Re = c1.Re;
       res.Im = -c1.Im;
       return res;
    }

    // переопределение оператора "+"
    template <typename T>
    Complex<T> operator+(const Complex<T>& c1, const Complex<T>& c2){
                Complex<T> res;
                res.Re = c1.Re + c2.Re;
                res.Im = c1.Im + c2.Im;
                return res;
    }

    // переопределение оператора "-"
    template <typename T>
    Complex<T> operator-(const Complex<T>& c1, const Complex<T>& c2){
                Complex<T> res;
                res.Re = c1.Re - c2.Re;
                res.Im = c1.Im - c2.Im;
                return res;
    }

    // переопределение оператора "*"
    template <typename T>
    Complex<T> operator*(const Complex<T>& c1, const Complex<T>& c2){
                Complex<T> res;
                res.Re = (c1.Re * c2.Re) - (c1.Im * c2.Im);
                res.Im = (c1.Re * c2.Im) + (c1.Im * c2.Re);
                return res;
    }

    // переопределение оператора "/"
    template <typename T>
    Complex<T> operator/(const Complex<T>& c1, const Complex<T>& c2){
                Complex<T> res;
                res.Re = ((c1.Re * c2.Re) + (c1.Im * c2.Im)) / (c2.Re * c2.Re + c2.Im * c2.Im);
                res.Im = ((c1.Im * c2.Re) - (c1.Re * c2.Im)) / (c2.Re * c2.Re + c2.Im * c2.Im);
                return res;
    }



    /*
    template <typename T>
    std::ostream& operator<<(std::ostream & os, Complex<T>  const& c); // переопределение оператора вывода

    template <typename T>
    Complex<T> conj(Complex<T> & c1); // комплексное сопряжение c1

    template <typename T>
    Complex<T> operator+(const Complex<T>& c1, const Complex<T>& c2); // переопределение оператора "+"

    template <typename T>
    Complex<T> operator-(const Complex<T>& c1, const Complex<T>& c2); // переопределение оператора "-"

    template <typename T>
    Complex<T> operator*(const Complex<T>& c1, const Complex<T>& c2); // переопределение оператора "*"

    template <typename T>
    Complex<T> operator/(const Complex<T>& c1, const Complex<T>& c2); // переопределение оператора "/"
*/
    // Complex add(Complex & c1, Complex & c2); // сумма комплексных чисел c1 и c2

    // Complex dif(Complex & c1, Complex & c2); // разность комплексных чисел c1 и c2

#endif
