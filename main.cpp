#include "printer/printer.h"
#include "complex_0110/complex_0110.h"
#include "C:\Users\ROG\Documents\TESTS\TDDProject\TestTask\libs\complex_0110\include\complex_0110\complex_0110.h"
#include <iostream>
#include <math.h>

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
    Complex_0110 T1;

    T1.view();

    Complex_0110 T2(6);

    T2.view();

    Complex_0110 T3(2, 6);

    T3.view();



	return 0;
}
