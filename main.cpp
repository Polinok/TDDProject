#include "printer/printer.h"
#include "complex/complex.h"
#include "filesignal/filesignal.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>



using namespace std;
int main()
{

    /*
    Printing::Printer printer;

    printer.print("Hello Word!");
    std::cerr << "Printerov sozdano: " << Printing::Printer::getCountCreatedPrinters() << std::endl;

    Printing::Printer* ptrToprinter = nullptr;

    ptrToprinter = new Printing::Printer();

    std::cerr << "Printerov sozdano: " << Printing::Printer::getCountCreatedPrinters() << std::endl;

    delete ptrToprinter;

    std::cerr << "Printerov sozdano: " << Printing::Printer::getCountCreatedPrinters() << std::endl;
*/
    Complex<double> T1;
    std::cout << "  T1 = " << T1;
    std::cout << "  |T1| = " << T1.abs() << std::endl << std::endl;

    Complex<double> T2(6);
    std::cout << "  T2 = " << T2;
    std::cout << "  |T2| = " << T2.abs() << std::endl<< std::endl;

    Complex<double> T3(253146, -199327);
    std::cout << "  T3 = " << T3;
    std::cout << "  |T3| = " << T3.abs() << std::endl<< std::endl;

    Complex<double> T4 = conj(T3);
    std::cout << "  T4 = T3* = " << T4;

    Complex<double> T5(-3, 7);
    std::cout << "  T5 = " << T5;

    Complex<double> T6;
    T6 = T3 + T5;
    std::cout << "  T6 = T3 + T5 = " << T6;

    Complex<double> T7;
    T7 = T3 - T5;
    std::cout << "  T7 = T3 - T5 = " << T7;

    Complex<double> T8;
    T8 = T3 * T5;
    std::cout << "  T8 = T3 * T5 = " << T8;

    Complex<double> T9;
    T9 = Complex<double>(2,-4) / Complex<double>(-1,2);
    std::cout << "  T9 = Complex(2,-4) / Complex(-1,2) = " << T9;



    // AM

    // Чтение сигнала из файла
    std::string filenameAM = "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\am_sound.dat";
    std::vector<Complex<int>> signalAM = Helpers::complexSignalReader<int>(filenameAM);

    int sizeAM = signalAM.size();
    std::cout << "  X = " << signalAM[409599] << std::endl;

    std::vector<double> demodAM(sizeAM);
    for (int i = 0; i < sizeAM; i++) {
        demodAM[i] = signalAM[i].abs();
    }

    double maxVal = *max_element(demodAM.begin(), demodAM.end());

    // Нормализуем данные и конвертируем в int16_t
    std::vector<int16_t> demodAM_int16(sizeAM);
    for (int i = 0; i < sizeAM; i++) {
        demodAM_int16[i] = static_cast<int16_t>((demodAM[i] / maxVal) * 32767);
    }

    std::cout << " |X| = " << demodAM[40999] << std::endl;


    // Запись демодулированного сигнала в файл
    std::string filenameDemodAM = "AMdemod.wav"; // Имя выходного файла
    WavHead headAM={{'R','I','F','F'},0,{'W','A','V','E'},{'f','m','t',' '},16,
                    1,1,11025,11025 * sizeof(int16_t),sizeof(int16_t),16,{'d','a','t','a'},
                    0};
    Helpers::signalWriter(demodAM_int16, headAM, filenameDemodAM);



    // FM

    // Чтение сигнала из файла
    std::string filenameFM = "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\file1EuropaPlus.bin";
    std::vector<Complex<int>> signalFM = Helpers::complexSignalReader<int>(filenameFM);

    int sizeFM = signalFM.size();

    std::cout << "  X = " << signalFM[409599] << std::endl;
    std::cout << "  XRE = " << signalFM[409599].Re << std::endl;
    std::cout << "  XIM = " << signalFM[409599].Im << std::endl;

    std::vector<double> demodFM(sizeFM);
    demodFM[0] = ((double)signalFM[0].Im * (double)signalFM[0].Re - (double)signalFM[0].Re * (double)signalFM[0].Im) / ((double)signalFM[0].Re * (double)signalFM[0].Re + (double)signalFM[0].Im * (double)signalFM[0].Im);
    for (int i = 1; i < sizeFM; i++) {
        demodFM[i] = (((double)signalFM[i].Im - (double)signalFM[i-1].Im) * (double)signalFM[i].Re - ((double)signalFM[i].Re - (double)signalFM[i-1].Re) * (double)signalFM[i].Im) / ((double)signalFM[i].Re * (double)signalFM[i].Re + (double)signalFM[i].Im * (double)signalFM[i].Im);
    }
    std::cout << "  Xdemod = " << demodFM[409599] << std::endl;

    double maxValFM = *max_element(demodFM.begin(), demodFM.end());

    // Нормализуем данные и конвертируем в int16_t
    std::vector<int16_t> demodFM_int16(sizeFM);
    for (int i = 0; i < sizeFM; i++) {
        demodFM_int16[i] = static_cast<int16_t>((demodFM[i] / maxValFM) * 32767);
    }


    // Запись демодулированного сигнала в файл
    std::string filenameDemodFM = "FMdemod.wav"; // Имя выходного файла
    WavHead headFM={{'R','I','F','F'},0,{'W','A','V','E'},{'f','m','t',' '},16,
                1,2,205000,205000 * sizeof(int16_t),sizeof(int16_t),16,{'d','a','t','a'},
                0};
    Helpers::signalWriter(demodFM_int16, headFM, filenameDemodFM);




    // ДЛЯ ТЕСТА signalWriter И complexSignalReader
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

    WavHead head={{'R','I','F','F'},0,{'W','A','V','E'},{'f','m','t',' '},16,
                1,1,11025,11025 * sizeof(int16_t),sizeof(int16_t),16,{'d','a','t','a'},
                0};
    std::string filename = "signaldemod.wav";
    Helpers::signalWriter(signal, head, filename);

    std::vector<Complex<int16_t>> signalnew = Helpers::complexSignalReader<int16_t>(filename);
    int sizenew = signalnew.size();
    std::cout << signalnew.size() << std::endl;

    for (int i = 0;  i < sizenew; i++) {
        std::cout << signalnew[i] << std::endl;
    }


	return 0;
}
