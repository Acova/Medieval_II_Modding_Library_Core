#ifndef FileDefinition_H
#define FileDefinition_H

#include "FileSectionDefinition.h"
#include <vector>
#include <string.h>

class FileDefinition {
    public:
        int id;
        std::string name;
        std::string filePath;
        std::vector<FileSectionDefinition> fileSectionDefinitions;
        FileDefinition() {};
        FileDefinition(int fileDefinitionId, std::string fileDefinitionName, std::string fileDefinitionPath) {
            id = fileDefinitionId;
            name = fileDefinitionName;
            filePath = fileDefinitionPath;
        };
        void AddFileSectionDefinition(FileSectionDefinition fileSectionDefinition) {
            fileSectionDefinitions.push_back(fileSectionDefinition);
        };
};

#endif