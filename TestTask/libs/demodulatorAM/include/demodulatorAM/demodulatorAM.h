#ifndef DEMODULATORAM_H
#define DEMODULATORAM_H

//#include "complex/complex.h"
#include "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\TestTask\\libs\\complex\\include\\complex\\complex.h"
#include "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\TestTask\\libs\\demodulator\\include\\demodulator\\demodulator.h"

#include <string>
#include <vector>
#include <iostream>


// DemodulatorAM является классом-наследником класса Demodulator
template <typename T>
class DemodulatorAM : public Demodulator<T>  {

public:

    std::vector<double> demodAM; // демодулированный сигнал

    // переопределяем виртуальную функцию demod базового класса Demodulator с помощью override
    void demod(const Complex<T>* signalAM, size_t size) override {
        demodAM.resize(size);

        for (size_t i = 0; i < size; i++) {
            demodAM[i] = signalAM[i].abs();
        }

    }

    DemodSignal getDemodData() const override {
        return DemodSignal(demodAM);
    }

};


#endif
