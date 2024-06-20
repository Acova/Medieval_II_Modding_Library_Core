#ifndef FileSectionDefinition_H
#define FileSectionDefinition_H

#include "FileDefinition.h"
#include <string>

class FileSectionDefinition {
    public:
        int id;
        std::string name;
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