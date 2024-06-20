#ifndef MODREADER_H
#define MODREADER_H

#include "FileDefinition.h"
#include "DefinitionsLoader.h"
#include <string>
#include <vector>

class ModReader
{
    private:
        DefinitionsLoader* definitionsLoader_;
        std::vector<FileDefinition>* fileDefinitions_;

    public:
        ModReader(std::string* fileDefinitionsDbPath);
        void readFile();
};
#endif