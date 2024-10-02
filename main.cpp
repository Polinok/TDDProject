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

	return 0;
}
