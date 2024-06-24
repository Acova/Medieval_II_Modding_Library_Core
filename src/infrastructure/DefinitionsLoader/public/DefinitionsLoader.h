#ifndef DEFINITIONSLOADER_H
#define DEFINITIONSLOADER_H

#include "FileDefinition.h"
#include "FileEntryDefinition.h"
#include "sqlite3.h"
#include <string>
#include <vector>
#include <map>

class DefinitionsLoader 
{
    private:
        sqlite3* database_;
        std::vector<FileDefinition> fileDefinitions_;
        std::map<int, FileEntryDefinition*> fileEntries_;
        std::map<int, FileSectionDefinition*> fileSections_;

    public:
        DefinitionsLoader(std::string* fileDefinitionsDbPath);
        std::vector<FileDefinition> getFileDefinitions();
        std::map<int, FileEntryDefinition> getFileEntryDefinitions();
        std::map<int, FileSectionDefinition> getFileSectionDefinitions();
        static int loadEntryDefinition(void *NotUsed, int colNum, char **colValues, char **colNames);
        static int loadSectionDefinition(void *NotUsed, int colNum, char **colValues, char **colNames);
        static int loadSectionDefinitionRelation(void *NotUsed, int colNum, char** colValues, char** colNames);
        static int loadFileDefinition(void *NotUsed, int colNum, char **colValues, char **colNames);
        void setFileDefinitions(std::vector<FileDefinition>* fileDefinitions) {
            this->fileDefinitions_.assign(fileDefinitions->begin(), fileDefinitions->end());
        }
        void addFileDefinition(FileDefinition fileDefinition);
        void addFileSectionDefinition(FileSectionDefinition* fileSectionDefinition);
        void addFileEntryDefinition(FileEntryDefinition* fileEntryDefinition); 
};
#endif