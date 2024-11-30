#ifndef DEMODULATOR_H
#define DEMODULATOR_H
//#include "complex/complex.h"
#include "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\TestTask\\libs\\complex\\include\\complex\\complex.h"
#include <string>
#include <vector>
#include <iostream>
// структура для хранения демодулированных данных
struct DemodSignal {
    std::vector<double> data;
    size_t size;
    DemodSignal(const std::vector<double>& d = {}) : data(d), size(d.size()) {} // конструктор
};
// Demodulator является классом-интерфейсом
template <typename T>
class Demodulator {
public:
    virtual void demod(const Complex<T>* inputData, size_t size) = 0; // метод для обработки данных
    virtual DemodSignal getDemodData() const = 0; // метод для получения демодулированных данных
    virtual std::vector<double>&& extractData() = 0; // метод для извлечения демодулированных данных
    virtual ~Demodulator() = default; // виртуальный деконструктор
};
#endif
