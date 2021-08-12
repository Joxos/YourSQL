#include "StorageEngine.h"
#include "Functions.h"
#include <iostream>


void createDatabase(string name) {
    string path = "./data/" + name;
    validateFolder(path.c_str());
}

bool Database::newTable(string table_name) {
    for (auto i = tables.begin(); i != tables.end(); ++i) {
        if ((*i).name == table_name) {
            return false;
        }
    }
    Table* new_table = new Table();
    new_table->name = table_name;
    // TODO: initalize the new table
    tables.push_back(*new_table);
    return true;
}

bool Database::delTable(string table_name) {
    for (auto i = tables.begin(); i != tables.end(); ++i) {
        if (i->name == table_name) {
            tables.erase(i);
            return true;
        }
    }
    return false;
}
