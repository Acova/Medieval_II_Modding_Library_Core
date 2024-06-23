#ifndef FileEntryDefinition_H
#define FileEntryDefinition_H

#include <string>
#include <regex>

class FileEntryDefinition {
    public:
        int id;
        std::string name;
        std::regex regularExpression;
        int matchGroup;
        FileEntryDefinition() {};
        FileEntryDefinition(int fileEntryId, std::string fileEntryName, std::regex fileEntryRegex, int fileEntryMatchGroup) {
            id = fileEntryId;
            name = fileEntryName;
            regularExpression = fileEntryRegex;
            matchGroup = fileEntryMatchGroup;
        }
};

#endif