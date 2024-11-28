#include <gtest/gtest.h>
#include "demodulatorAM/demodulatorAM.h"

TEST(DemodulatorAMTests, answertest) {
    std::vector<Complex<int>> signalinput(5);
    std::vector<double> signalanswer = {0, 1, 2, 3, 4};
    for (int i = 0;  i < 5; i++) {
        signalinput[i] = static_cast<int>(i);
    }

    Demodulator<int>* DMAM = new DemodulatorAM<int>();
    DMAM->demod(signalinput.data(), 5);

    auto signaloutput = DMAM->getDemodData(); // получение демодулированного сигнала

    ASSERT_EQ(signaloutput.data, signalanswer);
}
