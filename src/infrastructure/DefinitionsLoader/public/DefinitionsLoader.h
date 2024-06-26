#ifndef DEFINITIONSLOADER_H
#define DEFINITIONSLOADER_H

#include "FileDefinition.h"
#include "FileEntryDefinition.h"
#include "FileSectionDefinition.h"
#include "sqlite3.h"
#include <string>
#include <map>

class DefinitionsLoader 
{
    private:
        sqlite3* database_;
        std::map<int, FileDefinition*> fileDefinitions_;
        std::map<int, FileEntryDefinition*> fileEntries_;
        std::map<int, FileSectionDefinition*> fileSections_;

    public:
        DefinitionsLoader(std::string fileDefinitionsDbPath);
        std::map<int, FileDefinition*> getFileDefinitions() {
            return this->fileDefinitions_;
        };
        std::map<int, FileEntryDefinition*> getFileEntryDefinitions() {
            return this->fileEntries_;
        };
        std::map<int, FileSectionDefinition*> getFileSectionDefinitions(){
            return this->fileSections_;
        };
        static int loadEntryDefinition(void *NotUsed, int colNum, char **colValues, char **colNames);
        static int loadSectionDefinition(void *NotUsed, int colNum, char **colValues, char **colNames);
        static int loadSectionDefinitionRelation(void *NotUsed, int colNum, char **colValues, char **colNames);
        static int loadFileDefinition(void *NotUsed, int colNum, char **colValues, char **colNames);
        static int loadFileDefinitionRelation(void *NotUsed, int colNum, char **colValues, char **colNames);
        void addFileDefinition(FileDefinition* fileDefinition) {
            this->fileDefinitions_[fileDefinition->id] = fileDefinition;
        };
        void addFileSectionDefinition(FileSectionDefinition* fileSectionDefinition){
            this->fileSections_[fileSectionDefinition->id] = fileSectionDefinition;
        };
        void addFileEntryDefinition(FileEntryDefinition* fileEntryDefinition){
            this->fileEntries_[fileEntryDefinition->id] = fileEntryDefinition;
        }; 
};
#endif