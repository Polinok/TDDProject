#include "printer/printer.h"
#include "complex/complex.h"
#include "filesignal/filesignal.h"
#include "demodulator/demodulator.h"
#include "demodulatorAM/demodulatorAM.h"
#include "demodulatorFM/demodulatorFM.h"


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

    // AM

    // Чтение сигнала из файла filenameAM
    std::string filenameAM = "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\am_sound.dat";
    std::vector<Complex<int>> signalAM = Helpers::complexSignalReader<int>(filenameAM);

    int sizeAM = signalAM.size(); // размер комплексного вектора исходных данных

    Demodulator<int>* DMAM = new DemodulatorAM<int>();
    DMAM->demod(signalAM.data(), sizeAM);

    auto demodAM = DMAM->getDemodData(); // получение демодулированного сигнала

    double maxVal = *max_element(demodAM.data.begin(), demodAM.data.end()); // поиск максимума среди отсчетов демодулированного сигнала

    // Нормализуем данные и конвертируем в int16_t
    std::vector<int16_t> demodAM_int16(sizeAM);
    for (int i = 0; i < sizeAM; i++) {
        demodAM_int16[i] = static_cast<int16_t>((demodAM.data[i] / maxVal) * 32767);
    }

    // Запись демодулированного сигнала в файл
    std::string filenameDemodAM = "AMdemod.wav"; // имя выходного файла
    WavHead headAM={{'R','I','F','F'},0,{'W','A','V','E'},{'f','m','t',' '},16,
                    1,1,11025,11025 * sizeof(int16_t),sizeof(int16_t),16,{'d','a','t','a'},
                    0};
    Helpers::signalWriter(demodAM_int16, headAM, filenameDemodAM);


    // FM

    // Чтение сигнала из файла filenameFM
    std::string filenameFM = "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\file1EuropaPlus.bin";
    std::vector<Complex<int32_t>> signalFM = Helpers::complexSignalReader<int>(filenameFM);

    int sizeFM = signalFM.size(); // размер комплексного вектора исходных данных

    Demodulator<int>* DMFM = new DemodulatorFM<int>();
    DMFM->demod(signalFM.data(), sizeFM);

    auto demodFM = DMFM->getDemodData(); // получение демодулированного сигнала

    double maxValFM = *max_element(demodFM.data.begin(), demodFM.data.end()); // поиск максимума среди отсчетов демодулированного сигнала

    // Нормализуем данные и конвертируем в int16_t
    std::vector<int16_t> demodFM_int16(sizeFM);
    for (int i = 0; i < sizeFM; i++) {
        demodFM_int16[i] = static_cast<int16_t>((demodFM.data[i] / maxValFM) * 32767);
    }

    // Запись демодулированного сигнала в файл
    std::string filenameDemodFM = "FMdemod.wav"; // имя выходного файла
    WavHead headFM={{'R','I','F','F'},0,{'W','A','V','E'},{'f','m','t',' '},16,
                1,2,205000,205000 * sizeof(int16_t),sizeof(int16_t),16,{'d','a','t','a'},
                0};

    Helpers::signalWriter(demodFM_int16, headFM, filenameDemodFM);


/*
    // ДЛЯ ТЕСТА signalWriter И complexSignalReader

    std::cout << "\n\nIO TEST\n" << std::endl;

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

    std::cout << "size(signalW) = " << signal.size() << std::endl << std::endl;

    WavHead head={{'R','I','F','F'},0,{'W','A','V','E'},{'f','m','t',' '},16,
                1,1,11025,11025 * sizeof(int16_t),sizeof(int16_t),16,{'d','a','t','a'},
                0};
    std::string filename = "signaldemod.wav";
    Helpers::signalWriter(signal, head, filename);

    std::vector<Complex<int16_t>> signalnew = Helpers::complexSignalReader<int16_t>(filename);
    std::cout << "\nRead data:\n";
    for (size_t i = 0;  i < signalnew.size(); i++) {
        std::cout << signalnew[i] << std::endl;
    }
*/



    /*
    auto signalnew = Helpers::complexSignalReader<int16_t>(filename);
    std::cout << "\nRead data:\n";
        for (const auto& c : signalnew) {
            std::cout << c << '\n';
        }

    std::vector<Complex<uint8_t>> signalnew = Helpers::complexSignalReader<uint8_t>(filename);


    auto byte=reinterpret_cast<uint8_t*>(signalnew.data());

    auto data=reinterpret_cast<Complex<int16_t>*>(byte+44);


    for(size_t i=0;i!=10;i++){
        std::cout<<data[i];
    }*/
//    int sizenew = signalnew.size();
//    std::cout << "size(signalR) = " << signalnew.size() << std::endl;

//    for (int i = 0;  i < sizenew; i++) {
//        std::cout << signalnew[i] << std::endl;
//    }


	return 0;
}
