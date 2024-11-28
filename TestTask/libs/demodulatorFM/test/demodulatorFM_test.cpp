#include <gtest/gtest.h>
#include "demodulatorFM/demodulatorFM.h"

TEST(DemodulatorFMTests, answertest) {
    std::vector<Complex<int>> signalinput(5);
    std::vector<double> signalanswer = {0, -0.8, -0.1, 1, 0.3};
    signalinput[0] = {1, 3};
    signalinput[1] = {3, 1};
    signalinput[2] = {10, 0};
    signalinput[3] = {3, 1};
    signalinput[4] = {0, 10};

    Demodulator<int>* DMFM = new DemodulatorFM<int>();
    DMFM->demod(signalinput.data(), 5);

    auto signaloutput = DMFM->getDemodData(); // получение демодулированного сигнала

    ASSERT_EQ(signaloutput.data, signalanswer);
}

