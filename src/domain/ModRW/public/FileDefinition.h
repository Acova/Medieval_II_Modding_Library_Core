#ifndef FileDefinition_H
#define FileDefinition_H

class FileDefinition {
    public:
        int id;
        char* name;
        FileDefinition() {};
        FileDefinition(int fileDefinitionId, char* fileDefinitionName);
};

#endif