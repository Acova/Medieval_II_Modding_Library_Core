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
        std::vector<FileEntryDefinition*> entries;
        std::vector<FileSectionDefinition*> sections;
        FileSectionDefinition() {};
        FileSectionDefinition(
            int sectionDefinitionId,
            std::string sectionDefinitionName
        ) {
            id = sectionDefinitionId;
            name = sectionDefinitionName;
        };
        void addEntry(FileEntryDefinition* fileEntryDefinition) {
            this->entries.push_back(fileEntryDefinition);
        };
        void addSection(FileSectionDefinition* fileSectionDefinition) {
            this->sections.push_back(fileSectionDefinition);
        };
};

#endif