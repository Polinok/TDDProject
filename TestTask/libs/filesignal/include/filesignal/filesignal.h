#ifndef FILESIGNAL_H
#define FILESIGNAL_H

//#include "complex/complex.h"
#include "C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\TestTask\\libs\\complex\\include\\complex\\complex.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

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


namespace Helpers {

void signalWriter(const std::vector<int16_t>& signal, WavHead& head, const std::string& filename);

template <typename T>
std::vector<Complex<T>> complexSignalReader(const std::string& filename)
{

    std::ifstream infile;
    infile.open(filename, std::ios::binary);
    if (infile.is_open())
        std::cout << "\n  File " << filename << " is opened\n" << std::endl;
    else
    {
        std::cout << "\n  Error: file " << filename << " isn't opened\n" << std::endl;
        exit(-1);
    }

    WavHead head;

    int weight = 0;
    infile.seekg (0, std::ios::end); // становимся в конец файла || std::ios::end или std::ios_base::end
    weight = infile.tellg(); // считываем текущую позицию
    infile.seekg(0, std::ios::beg); // возвращаемся в начало
    std::cout << "  File size = " << weight << " B" << std::endl << std::endl;//std::filesystem::size()
    int size = (weight-sizeof(head)) / (2 * sizeof(T)); // (количество элементов) = (общий вес) / (вес одного элемента типа int)
    std::cout << "  File contains " << size << " elements" << std::endl << std::endl;

    infile.read(reinterpret_cast<char*>(&head), sizeof(head));

    std::vector<Complex<T>> signal(size);
    infile.read((char*) signal.data(), size*sizeof(Complex<T>));
    infile.close();
    return signal;
}

}

#endif
