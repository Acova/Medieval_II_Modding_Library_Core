#ifndef DEFINITIONSLOADER_H
#define DEFINITIONSLOADER_H

#include "FileDefinition.h"
#include "sqlite3.h"
#include <string>
#include <vector>

class DefinitionsLoader 
{
    private:
        sqlite3* database_;
        std::vector<FileDefinition> fileDefinitions_;

    public:
        DefinitionsLoader(std::string* fileDefinitionsDbPath);
        std::vector<FileDefinition> getFileDefinitions();
        static int loadDefinitions(void* NotUsed, int colNum, char** colNames, char** colValues);
        void setFileDefinitions(std::vector<FileDefinition>* fileDefinitions) {
            this->fileDefinitions_.assign(fileDefinitions->begin(), fileDefinitions->end());
        }
        void addFileDefinition(FileDefinition fileDefinition);
};
#endif