#include <iostream>
#include <string>
#include <vector>
#include "ModReader.h"
#include "config.h"

int main() {
    std::string filePath = DEFINITIONS_DATABASE_FILEPATH;
    ModReader* modReader = new ModReader("/opt/projects/medieval-ii-modding-library-core/src/infrastructure/DefinitionsLoader/resources/miimlc.db");
    return 0;
}