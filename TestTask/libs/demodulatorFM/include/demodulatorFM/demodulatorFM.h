#ifndef DEMODULATORFM_H
#define DEMODULATORFM_H
//#include "complex/complex.h"
#include "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\TestTask\\libs\\complex\\include\\complex\\complex.h"
#include "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\TestTask\\libs\\demodulator\\include\\demodulator\\demodulator.h"
#include <string>
#include <vector>
#include <iostream>
// DemodulatorFM является классом-наследником класса Demodulator
template <typename T>
class DemodulatorFM : public Demodulator<T>  {
public:

    std::vector<double> demodFM; // демодулированный сигнал

    // переопределяем виртуальную функцию demod базового класса Demodulator с помощью override
    void demod(const Complex<T>* signalFM, size_t size) override {
        demodFM.resize(size);
        demodFM[0] = ((double)signalFM[0].Im * (double)signalFM[0].Re - (double)signalFM[0].Re * (double)signalFM[0].Im) / ((double)signalFM[0].Re * (double)signalFM[0].Re + (double)signalFM[0].Im * (double)signalFM[0].Im);
        for (int i = 1; i < size; i++) {
            demodFM[i] = (((double)signalFM[i].Im - (double)signalFM[i-1].Im) * (double)signalFM[i].Re - ((double)signalFM[i].Re - (double)signalFM[i-1].Re) * (double)signalFM[i].Im) / ((double)signalFM[i].Re * (double)signalFM[i].Re + (double)signalFM[i].Im * (double)signalFM[i].Im);
        }
    }

    DemodSignal getDemodData() const override {
        return DemodSignal(demodFM);
    }

    // возвращаем rvalue-ссылку на внутренний вектор с помщью std::move
    std::vector<double>&& extractData() override {
        return std::move(demodFM);
    }
};
#endif
