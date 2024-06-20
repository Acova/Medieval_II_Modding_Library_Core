#include <iostream>
#include <string>
#include <vector>
#include "ModReader.h"
#include "config.h"

int main() {
    std::string filePath = DEFINITIONS_DATABASE_FILEPATH;
    ModReader* modReader = new ModReader(&filePath);
    return 0;
}