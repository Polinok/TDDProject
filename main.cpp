#include "printer/printer.h"
#include "complex/complex.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>

#include <cstdlib>
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

    Complex<double> T3(2, -6);
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


    std::ifstream file;
    file.open("C:\\Users\\ROG\\Documents\\TESTS\\TDDProject\\am_sound.dat", std::ios::binary);
    if (file.is_open())
        std::cout << "\n  File is opened\n" << std::endl;
    else
    {
        std::cout << "\n  Error: file isn't opened\n" << std::endl;
        return -1;
    }

    int weight = 0;
    file.seekg (0, std::ios::end); // становимся в конец файла || std::ios::end или std::ios_base::end
    weight = file.tellg(); // считываем текущую позицию
    file.seekg(0, std::ios::beg); // возвращаемся в начало
    std::cout << "  File size = " << weight << " B" << std::endl;
    size_t size = weight / sizeof(int); // (количество элементов) = (общий вес) / (вес одного элемента типа int)
    std::cout << "  File contains " << size << " elements" << std::endl;

    std::vector<int> data3(size);
    file.read((char*) &data3[0], weight);
    std::cout << data3[1000] << std::endl;
    file.close();

	return 0;
}
