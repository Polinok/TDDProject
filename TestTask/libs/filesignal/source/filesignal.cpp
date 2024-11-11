#include "filesignal/filesignal.h"

void Helpers::signalWriter(const std::vector<int16_t>& signal, WavHead& head, const std::string& filename)
{
    std::ofstream outfile(filename, std::ios::binary);
    if (!outfile) {
            std::cerr << "\n  Error: file " << filename << " isn't opened\n " << std::endl;
            return;
        }
    head.size2 = signal.size() * sizeof(int16_t); // 3276800
    std::cout << head.size2<< std::endl;
    head.size0 = 36 + head.size2;
    outfile.write((char*) &head, sizeof(head)); // 44
    outfile.write((char*) (signal.data()), head.size2);
    outfile.close();
    std::cout << " The data has been written to the file: " << filename << std::endl;

}
