#include "ModReader.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "sqlite3.h"

static int callback(void *data, int argc, char **argv, char **azColName) {
    fprintf(stderr, "%s: \n", (const char*)data);

    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

void IModReader::readFile(std::string filePath)
{
    std::cout << "Hola mundo 2\n";
    sqlite3 *dataBase;
    int rc = sqlite3_open("../src/infrastructure/ModRW/resources/miimlc.db", &dataBase);
    if (rc) {
        std::cout << "No se puede abrir la base de datos!" << std::endl;
        return;
    }

    char *sql = "SELECT * FROM file_definition";
    const char* data = "Callback function called!";
    char *errorMessage;
    rc = sqlite3_exec(dataBase, sql, callback, (void*)data, &errorMessage);
    sqlite3_close(dataBase);
    // std::ifstream file("../src/infrastructure/ModRW/resources/export_descr_buildings.txt");
    // std::string line;
    // if (file.is_open()) {
    //     while (std::getline(file, line)) {
    //         std::cout << line << std::endl;
    //     }
        
    // } else {
    //     std::cerr << "Unable to open file!" << std::endl;
    // }
}