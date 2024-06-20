#include "DefinitionsLoader.h"
#include <iostream>
#include <string.h>

DefinitionsLoader::DefinitionsLoader(std::string* fileDefinitionsDbPath)
{
    if (SQLITE_OK != sqlite3_open(fileDefinitionsDbPath->c_str(), &this->database_)) {
        fprintf(stderr, "Error abriendo la base de datos");
        return;
    }

    std::string sql = "SELECT * FROM file_definition;";
    char* errorMsg;
    if (SQLITE_OK != sqlite3_exec(this->database_, sql.c_str(), DefinitionsLoader::loadDefinitions, (DefinitionsLoader*) this, &errorMsg)) {
        fprintf(stderr, "Error ejecutando sql: %s\n", errorMsg);
        return;
    }

    for(FileDefinition fileDefinition : this->fileDefinitions_) {
        std::string newSql = "SELECT "
            "fsd.id, fsd.name, fsd.beginning_entry, fsd.end_entry " 
        "FROM "
        "   file_section_definition fsd "
        "INNER JOIN file_definition_has_file_section_definition fdhfsd ON "
        "    fdhfsd.file_definition_id = fsd.id "
        "WHERE fsd.id = ";
        newSql = newSql + std::to_string(fileDefinition.id);
        if (SQLITE_OK != sqlite3_exec(this->database_, newSql.c_str(), DefinitionsLoader::loadSectionDefinitions, (void*) &fileDefinition, &errorMsg)) {
            fprintf(stderr, "Error ejecutando sql: %s\n", errorMsg);
            return;
        }
    }

    sqlite3_close(this->database_);

}

int DefinitionsLoader::loadSectionDefinitions(void* NotUsed, int colNum, char** colValues, char** colNames)
{
    int i;
    FileDefinition* fileDefinition = (FileDefinition*) NotUsed;
    FileSectionDefinition* newFileSectionDefinition = new FileSectionDefinition();
    for (i = 0; i < colNum; i++) {
        printf("%s = %s\n", colNames[i], colValues[i]);
        if (strcmp("id", colNames[i]) == 0) {
            newFileSectionDefinition->id = strtol(colValues[i], NULL, 0);
        }
        if (strcmp("name", colNames[i]) == 0) {
            newFileSectionDefinition->name = colValues[i];
        }
    }
    fileDefinition->AddFileSectionDefinition(*newFileSectionDefinition);
    return 0;
}

int DefinitionsLoader::loadDefinitions(void* NotUsed, int colNum, char** colValues, char** colNames)
{
    int i;
    DefinitionsLoader* obj = (DefinitionsLoader*) NotUsed;
    FileDefinition* newFileDefinition = new FileDefinition();
    for(i = 0; i < colNum; i++) {
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