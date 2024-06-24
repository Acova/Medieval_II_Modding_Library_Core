#ifndef FileSectionDefinition_H
#define FileSectionDefinition_H

#include <string>
#include <vector>
#include "FileEntryDefinition.h"

class FileSectionDefinition {
    public:
        int id;
        std::string name;
        FileEntryDefinition* beginningEntry;
        FileEntryDefinition* endEntry;
        std::vector<FileEntryDefinition> contents;
        FileSectionDefinition() {};
        FileSectionDefinition(
            int sectionDefinitionId,
            std::string sectionDefinitionName
        ) {
            id = sectionDefinitionId;
            name = sectionDefinitionName;
        };
};

#endif