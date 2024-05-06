#ifndef FileDefinition_H
#define FileDefinition_H

class FileDefinition {
    public:
        int id;
        char* name;
        char* filePath;
        FileDefinition() {};
        FileDefinition(int fileDefinitionId, char* fileDefinitionName, char* fileDefinitionPath) {
            id = fileDefinitionId;
            name = fileDefinitionName;
            filePath = fileDefinitionPath;
        };
};

#endif