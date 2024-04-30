#include <iostream>
#include <string>
#include "ModReader.h"

int main() {
    std::cout << "Hello World\n";
    std::string filePath = "Hola mundo 2";
    IModReader::readFile(filePath);
    return 0;
}