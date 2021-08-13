#include "StorageEngine.h"
#include "Functions.h"
#include <iostream>


void createDatabase(string name) {
    string path = "./data/" + name;
    validateFolder(path.c_str());
}

Database::Database(string database_name) {
    name = database_name;
}

bool Database::createTable(string table_name) {
    for (auto i = tables.begin(); i != tables.end(); ++i) {
        if (i->name == table_name) {
            return false;
        }
    }
    Table* new_table = new Table();
    new_table->name = table_name;
    // TODO: initalize the new table
    tables.push_back(*new_table);
    return true;
}

Table Database::getTable(string table_name) {
    for (auto table : tables) {
        if (table.name == table_name)
            return table;
    }
    throw "No table named " + table_name + ".";
}

bool Database::dropTable(string table_name) {
    for (auto i = tables.begin(); i != tables.end(); ++i) {
        if (i->name == table_name) {
            tables.erase(i);
            return true;
        }
    }
    return false;
}
