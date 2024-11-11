#include <gtest/gtest.h>
#include "filesignal/filesignal.h"

TEST(FileSignalTests, IOtest) {
/*
    std::vector<Complex<int>> signal(100);
    for (int i = 0;  i < 100; i++) {
        signal[i] = i;
    }

    WavHead head={{'R','I','F','F'},0,{'W','A','V','E'},{'f','m','t',' '},16,
                1,1,205000,205000 * sizeof(int16_t),sizeof(int16_t),16,{'d','a','t','a'},
                0};
    std::string filename = "signaldemod.wav";
    Helpers::complexSignalWriter(signal, head, filename);

    std::vector<Complex<int>> signalnew = Helpers::complexSignalReader<int>(filename);
    */

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
