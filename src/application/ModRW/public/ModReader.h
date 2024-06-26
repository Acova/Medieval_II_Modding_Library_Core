#ifndef MODREADER_H
#define MODREADER_H

#include "DefinitionsLoader.h"
#include "FileDefinition.h"
#include "IFileParser.h"

#include <map>
#include <string>
#include <vector>

class ModReader
{
    private:
        DefinitionsLoader* definitionsLoader_;
        std::vector<FileDefinition*> fileDefinitions_;
        std::map<std::string, IFileParser*> fileParsers;

    public:
        ModReader(std::string fileDefinitionsDbPath);
        void readFile();
};
#endif