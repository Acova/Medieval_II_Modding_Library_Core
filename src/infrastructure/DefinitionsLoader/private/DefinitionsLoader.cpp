#include "DefinitionsLoader.h"
#include <iostream>
#include <string.h>

DefinitionsLoader::DefinitionsLoader(std::string* fileDefinitionsDbPath)
{
    if (SQLITE_OK != sqlite3_open(fileDefinitionsDbPath->c_str(), &this->database_)) {
        fprintf(stderr, "Error abriendo la base de datos");
        return;
    }

    char* sql = "SELECT * FROM file_definition;";
    char* errorMsg;
    if (SQLITE_OK != sqlite3_exec(this->database_, sql, DefinitionsLoader::loadDefinitions, (FileDefinition*) this, &errorMsg)) {
        fprintf(stderr, "Error ejecutando sql: %s\n", errorMsg);
        return;
    }

    sqlite3_close(this->database_);

}

int DefinitionsLoader::loadDefinitions(void* NotUsed, int colNum, char** colValues, char** colNames)
{
    int i;
    DefinitionsLoader* obj = (DefinitionsLoader*) NotUsed;
    FileDefinition* newFileDefinition = new FileDefinition();
    for(i = 0; i < colNum; i++) {
        printf("%s = %s\n", colNames[i], colValues[i] ? colValues[i] : "NULL");
        if (strcmp("id", colNames[i]) == 0) {
            newFileDefinition->id = strtol(colValues[i], NULL, 0);
        }
        if (strcmp("name", colNames[i]) == 0) {
            newFileDefinition->name = colValues[i];
        }
        if (strcmp("file_path", colNames[i]) == 0) {
            newFileDefinition->filePath = colValues[i];
        }
    }
    obj->addFileDefinition(*newFileDefinition);

    std::vector<FileDefinition> fileDefinitions = obj->getFileDefinitions();
    return 0;
}

void DefinitionsLoader::addFileDefinition(FileDefinition fileDefinition) {
    this->fileDefinitions_.push_back(fileDefinition);
}

std::vector<FileDefinition> DefinitionsLoader::getFileDefinitions()
{
    return this->fileDefinitions_;
}