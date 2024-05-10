#include <iostream>
#include <vector>
#include "ModReader.h"
#include "config.h"

int main() {
    std::cout << "Hello World\n";
    ModReader* modReader = new ModReader((char*) DEFINITIONS_DATABASE_FILEPATH);
    return 0;
}