#include <gtest/gtest.h>
#include "filesignal/filesignal.h"

TEST(FileSignalTests, IOtest) {
    std::vector<Complex<int16_t>> signalc(10);
    std::vector<int16_t> signal(20);
    int k = 0;
    for (int i = 0;  i < 10; i++) {
        signalc[i] = static_cast<int16_t>(i);
        std::cout << signalc[i] << std::endl;

        signal[k] = static_cast<int16_t>(signalc[i].Re);
        signal[k+1] = static_cast<int16_t>(signalc[i].Im);

        std::cout << signal[k] << " and " << signal[k+1] << std::endl << std::endl;
        k += 2;
    }

    std::cout << "size(signalW) = " << signal.size() << std::endl;

    WavHead head={{'R','I','F','F'},0,{'W','A','V','E'},{'f','m','t',' '},16,
                1,1,11025,11025 * sizeof(int16_t),sizeof(int16_t),16,{'d','a','t','a'},
                0};
    std::string filename = "signaldemod.wav";
    Helpers::signalWriter(signal, head, filename);

    std::vector<Complex<int16_t>> signalnew = Helpers::complexSignalReader<int16_t>(filename);

    ASSERT_EQ(signalnew, signalc);

/*
    Printing::Printer* testedObject = new Printing::Printer();
    Printing::Printer* testedObject1 = new Printing::Printer();
    Printing::Printer* testedObject2 = new Printing::Printer();

    delete  testedObject;
    ASSERT_EQ(Printing::Printer::getCountCreatedPrinters(), 2);
    delete  testedObject1;
    ASSERT_EQ(Printing::Printer::getCountCreatedPrinters(), 1);
    delete  testedObject2;
    ASSERT_EQ(Printing::Printer::getCountCreatedPrinters(), 0);
*/
}
