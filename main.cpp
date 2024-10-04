#include "printer/printer.h"
#include "complex/complex.h"
//#include "..\TDDProject\TestTask\libs\complex\include\complex\complex.h"
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
    Complex T1;
    T1.view();
    std::cout << "  |complex number| = " << T1.abs() << std::endl << std::endl;

    Complex T2(6);
    T2.view();
    std::cout << "  |complex number| = " << T2.abs() << std::endl<< std::endl;

    Complex T3(2, -6);
    T3.view();
    std::cout << "  |complex number| = " << T3.abs() << std::endl<< std::endl;

    Complex T4 = add(T2, T3);
    T4.view();

    Complex T5 = dif(T3, T2);
    T5.view();

    Complex T6 = conj(T3);
    T6.view();

    Complex T7(-3, 7);

    Complex T8;
    T8 = T3 + T7;
    T8.view();

    Complex T9;
    T9 = T3 - T7;
    T9.view();

    Complex T10;
    T10 = T3 * T7;
    T10.view();

    Complex T11;
    T11 = Complex(2,-4) / Complex(-1,2);
    T11.view();

	return 0;
}
