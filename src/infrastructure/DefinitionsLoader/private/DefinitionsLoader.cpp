#include "DefinitionsLoader.h"
#include <iostream>
#include <string>
#include <regex>

std::vector<FileDefinition> DefinitionsLoader::getFileDefinitions()
{
    return this->fileDefinitions_;
}

DefinitionsLoader::DefinitionsLoader(std::string* fileDefinitionsDbPath)
{
    if (SQLITE_OK != sqlite3_open(fileDefinitionsDbPath->c_str(), &this->database_)) {
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

    sql = "SELECT * FROM file_section_definition_has_item";
    if (SQLITE_OK != sqlite3_exec(this->database_, sql.c_str(), DefinitionsLoader::loadSectionDefinitionRelation, (DefinitionsLoader*) this, &errorMsg)) {
        fprintf(stderr, "Error ejecutando sql: %s\n", errorMsg);
        return;
    }
    sqlite3_close(this->database_);

}

int DefinitionsLoader::loadFileDefinition(void* NotUsed, int colNum, char** colValues, char** colNames)
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
    std::string itemClass;
    int itemId;
    for (i = 0; i < colNum; i++){
        if (strcmp("file_section_definition_id", colNames[i]) == 0) {
            int fileSectionId = strtol(colValues[i], NULL, 0);
            fileSectionDefinition = definitionsLoader->fileSections_[fileSectionId];
        }

        if (strcmp("item_class", colNames[i]) == 0) {
            itemClass = colValues[i];
        }

        if (strcmp("item_id", colNames[i]) == 0) {
            itemId = strtol(colValues[i], NULL, 0);
        }
    }

    if (strcmp("Entry", itemClass.c_str()) == 0) {
        FileEntryDefinition* entry = definitionsLoader->fileEntries_[itemId];
        fileSectionDefinition->addEntry(entry);
    } else if (strcmp("Section", itemClass.c_str()) == 0)
    {
        FileSectionDefinition* section = definitionsLoader->fileSections_[itemId];
        fileSectionDefinition->addSection(section);
    }
    

    return 0;
}

void DefinitionsLoader::addFileSectionDefinition(FileSectionDefinition *fileSectionDefinition)
{
    this->fileSections_[fileSectionDefinition->id] = fileSectionDefinition;
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

void DefinitionsLoader::addFileEntryDefinition(FileEntryDefinition *fileEntryDefinition)
{
    this->fileEntries_[fileEntryDefinition->id] = fileEntryDefinition;
}