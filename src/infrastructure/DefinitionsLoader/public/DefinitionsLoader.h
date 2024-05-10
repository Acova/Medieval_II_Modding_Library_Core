#ifndef DEFINITIONSLOADER_H
#define DEFINITIONSLOADER_H

#include "FileDefinition.h"
#include "sqlite3.h"
#include <vector>

class DefinitionsLoader 
{
    private:
        sqlite3* database_;

    public:
        DefinitionsLoader(char* fileDefinitionsDbPath);
        static std::vector<FileDefinition>* getFileDefinitions();
};
#endif