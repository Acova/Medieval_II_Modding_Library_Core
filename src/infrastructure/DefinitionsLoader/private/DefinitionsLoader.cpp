#include "DefinitionsLoader.h"
#include <iostream>
#include <string>
#include <regex>

DefinitionsLoader::DefinitionsLoader(std::string fileDefinitionsDbPath)
{
    if (SQLITE_OK != sqlite3_open(fileDefinitionsDbPath.c_str(), &this->database_)) {
        fprintf(stderr, "Error abriendo la base de datos");
        return;
    }

    std::string sql = "SELECT * FROM file_entry_definition;";
    char* errorMsg;
    if (SQLITE_OK != sqlite3_exec(this->database_, sql.c_str(), DefinitionsLoader::loadEntryDefinition, (DefinitionsLoader*) this, &errorMsg)) {
        fprintf(stderr, "Error ejecutando sql: %s\n", errorMsg);
        return;
    }

    sql = "SELECT * FROM file_section_definition";
    if (SQLITE_OK != sqlite3_exec(this->database_, sql.c_str(), DefinitionsLoader::loadSectionDefinition, (DefinitionsLoader*) this, &errorMsg)) {
        fprintf(stderr, "Error ejecutando sql: %s\n", errorMsg);
        return;
    }

    sql = "SELECT * FROM file_section_definition_has_file_entry_definition";
    if (SQLITE_OK != sqlite3_exec(this->database_, sql.c_str(), DefinitionsLoader::loadSectionDefinitionRelation, (DefinitionsLoader*) this, &errorMsg)) {
        fprintf(stderr, "Error ejecutando sql: %s\n", errorMsg);
        return;
    }

    sql = "SELECT * FROM file_definition";
    if (SQLITE_OK != sqlite3_exec(this->database_, sql.c_str(), DefinitionsLoader::loadFileDefinition, (DefinitionsLoader*) this, &errorMsg)) {
        fprintf(stderr, "Error ejecutando sql: %s\n", errorMsg);
        return;
    }

    sql = "SELECT * FROM file_definition_has_file_section_definition";
    if (SQLITE_OK != sqlite3_exec(this->database_, sql.c_str(), DefinitionsLoader::loadFileDefinitionRelation, (DefinitionsLoader*) this, &errorMsg)) {
        fprintf(stderr, "Error ejecutando sql: %s\n", errorMsg);
        return;
    }

    sqlite3_close(this->database_);

}

int DefinitionsLoader::loadEntryDefinition(void *NotUsed, int colNum, char **colValues, char **colNames)
{
    int i;
    DefinitionsLoader* definitionsLoader = (DefinitionsLoader*) NotUsed;
    FileEntryDefinition* newFileEntryDefinition = new FileEntryDefinition();
    for (i = 0; i < colNum; i++) {
        char* colName = colNames[i];
        if (strcmp("id", colNames[i]) == 0) {
            newFileEntryDefinition->id = strtol(colValues[i], NULL, 0);
        }

        if (strcmp("name", colNames[i]) == 0) {
            newFileEntryDefinition->name = colValues[i];
        }
        
        if (strcmp("regex", colNames[i]) == 0) {
            std::string value = colValues[i];
            newFileEntryDefinition->regularExpression = std::regex(colValues[i]);
        }

        if (strcmp("match_group", colNames[i]) == 0) {
            newFileEntryDefinition->matchGroup = strtol(colValues[i], NULL, 0);
        }
    }

    definitionsLoader->addFileEntryDefinition(newFileEntryDefinition);
    return 0;
}

int DefinitionsLoader::loadSectionDefinition(void* NotUsed, int colNum, char** colValues, char** colNames)
{
    int i;
    DefinitionsLoader* definitionsLoader = (DefinitionsLoader*) NotUsed;
    FileSectionDefinition* newFileSectionDefinition = new FileSectionDefinition();
    for (i = 0; i < colNum; i++) {
        if (strcmp("id", colNames[i]) == 0) {
            newFileSectionDefinition->id = strtol(colValues[i], NULL, 0);
        }

        if (strcmp("name", colNames[i]) == 0) {
            newFileSectionDefinition->name = colValues[i];
        }

        if (strcmp("beginning_entry", colNames[i]) == 0) {
            int entryId = strtol(colValues[i], NULL, 0);
            newFileSectionDefinition->beginningEntry = definitionsLoader->fileEntries_[entryId];
        }

        if (strcmp("end_entry", colNames[i]) == 0) {
            int entryId = strtol(colValues[i], NULL, 0);
            newFileSectionDefinition->endEntry = definitionsLoader->fileEntries_[entryId];
        }
    }

    definitionsLoader->addFileSectionDefinition(newFileSectionDefinition);
    return 0;
}

int DefinitionsLoader::loadSectionDefinitionRelation(void *NotUsed, int colNum, char **colValues, char **colNames)
{
    int i;
    DefinitionsLoader* definitionsLoader = (DefinitionsLoader*) NotUsed;
    FileSectionDefinition* fileSectionDefinition;
    int fileEntryDefinitionId;
    for (i = 0; i < colNum; i++){
        if (strcmp("file_section_definition_id", colNames[i]) == 0) {
            int fileSectionId = strtol(colValues[i], NULL, 0);
            fileSectionDefinition = definitionsLoader->fileSections_[fileSectionId];
        }

        if (strcmp("file_entry_definition_id", colNames[i]) == 0) {
            fileEntryDefinitionId = strtol(colValues[i], NULL, 0);
        }
    }

    FileEntryDefinition* entry = definitionsLoader->fileEntries_[fileEntryDefinitionId];
    fileSectionDefinition->addEntry(entry);
    
    return 0;
}

int DefinitionsLoader::loadFileDefinition(void* NotUsed, int colNum, char** colValues, char** colNames)
{
    int i;
    DefinitionsLoader* definitionsLoader = (DefinitionsLoader*) NotUsed;
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
    definitionsLoader->addFileDefinition(newFileDefinition);
    return 0;
}

int DefinitionsLoader::loadFileDefinitionRelation(void *NotUsed, int colNum, char **colValues, char **colNames)
{
    int i;
    DefinitionsLoader* definitionsLoader = (DefinitionsLoader*) NotUsed;
    FileDefinition* fileDefinition;
    int fileSectionDefinitionId;
    for (i = 0; i < colNum; i++){
        if (strcmp("file_definition_id", colNames[i]) == 0) {
            int fileDefinitionId = strtol(colValues[i], NULL, 0);
            fileDefinition = definitionsLoader->fileDefinitions_[fileDefinitionId];
        }

        if (strcmp("file_section_definition_id", colNames[i]) == 0) {
            char* value = colValues[i];
            fileSectionDefinitionId = strtol(colValues[i], NULL, 0);
        }
    }

    FileSectionDefinition* section = definitionsLoader->fileSections_[fileSectionDefinitionId];
    fileDefinition->addFileSection(section);
    
    return 0;
}
