#ifndef FileDefinition_H
#define FileDefinition_H

#include "FileSectionDefinition.h"
#include "FileEntryDefinition.h"
#include <vector>
#include <string.h>

class FileDefinition {
    public:
        int id;
        std::string name;
        std::string filePath;
        std::vector<FileSectionDefinition*> sections;
        std::vector<FileEntryDefinition*> entries;
        FileDefinition() {};
        FileDefinition(int fileDefinitionId, std::string fileDefinitionName, std::string fileDefinitionPath) {
            id = fileDefinitionId;
            name = fileDefinitionName;
            filePath = fileDefinitionPath;
        };
        void addFileSection(FileSectionDefinition* fileSectionDefinition) {
            sections.push_back(fileSectionDefinition);
        };
        void addEntry(FileEntryDefinition* fileEntryDefinition) {
            entries.push_back(fileEntryDefinition);
        }
};

#endif