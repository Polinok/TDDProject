#include "printer/printer.h"
#include "complex/complex.h"
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

struct WavHead{
 char RIFF[4];    //The RIFF in the first part
 long int size0;//Save the size of all files behind
 char WAVE[4];
 char FMT[4];
 long int size1;//Stored is the size saved by fmt, after including this, the first few data, a total of 16
 short int fmttag;
 short int channel;
 long int samplespersec;//The number of samples per second, using 11025
 long int bytepersec;
 short int blockalign;
 short int bitpersamples;
 char DATA[4];
 long int size2;//The remaining file size, that is, the size of the sound sample, because it is one second of content, then it is 11025.
};

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


    std::ifstream infile;
    infile.open("C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\am_sound.dat", std::ios::binary);
    if (infile.is_open())
        std::cout << "\n  File is opened\n" << std::endl;
    else
    {
        std::cout << "\n  Error: file isn't opened\n" << std::endl;
        return -1;
    }

    int weight = 0;
    infile.seekg (0, std::ios::end); // становимся в конец файла || std::ios::end или std::ios_base::end
    weight = infile.tellg(); // считываем текущую позицию
    infile.seekg(0, std::ios::beg); // возвращаемся в начало
    std::cout << "  File size = " << weight << " B" << std::endl << std::endl;
    int size = weight / sizeof(int); // (количество элементов) = (общий вес) / (вес одного элемента типа int)
    std::cout << "  File contains " << size << " elements" << std::endl << std::endl;

    std::vector<Complex<int>> signalAM(size/2);
    infile.read((char*) &signalAM[0], size/2*sizeof(int));
    std::cout << "  X = " << signalAM[409599] << std::endl;

    std::vector<double> demodAM(size/2);
    for (int i = 0; i < size/2; i++) {
        demodAM[i] = signalAM[i].abs();
    }

    double maxVal = *max_element(demodAM.begin(), demodAM.end());

    // Нормализуем данные и конвертируем в int16_t
    std::vector<int16_t> demodAM_int16(size/2);
    for (int i = 0; i < size/2; i++) {
        demodAM_int16[i] = static_cast<int16_t>((demodAM[i] / maxVal) * 32767);
    }

    std::cout << " |X| = " << demodAM[40999] << std::endl;
    infile.close();

    std::ofstream outfile("output.wav", std::ios::binary);
    WavHead head={{'R','I','F','F'},0,{'W','A','V','E'},{'f','m','t',' '},16,
                1,1,11025,11025 * sizeof(int16_t),sizeof(int16_t),16,{'d','a','t','a'},
                0};

    head.size2 = demodAM_int16.size() * sizeof(int16_t); // 3276800
    std::cout << head.size2<< std::endl;
    head.size0 = 36 + head.size2;
    outfile.write((char*) &head, sizeof(head)); // 44
    outfile.write((char*) (demodAM_int16.data()), head.size2);
    outfile.close();

	return 0;
}
