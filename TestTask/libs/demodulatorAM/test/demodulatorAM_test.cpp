#include <gtest/gtest.h>
#include "demodulatorAM/demodulatorAM.h"

TEST(DemodulatorAMTests, answertest) {
    std::vector<Complex<int>> signalinput(5);
    std::vector<double> signalanswer = {0, 1, 2, 3, 4};
    for (int i = 0;  i < 5; i++) {
        signalinput[i] = Complex<int>(i);
    }

    Demodulator<int>* DMAM = new DemodulatorAM<int>();
    DMAM->demod(signalinput.data(), 5);

    auto signaloutput1 = DMAM->getDemodData(); // получение демодулированного сигнала
    for (int i = 0;  i < 5; i++) {
        std::cout << signaloutput1.data[i] << std::endl;
    }

    ASSERT_EQ(signaloutput1.data, signalanswer);

    std::vector<double> signaloutput2 = std::move(DMAM->extractData());
    for (int i = 0;  i < 5; i++) {
        std::cout << signaloutput2[i] << std::endl;
    }

    ASSERT_EQ(signaloutput2, signalanswer);

}
