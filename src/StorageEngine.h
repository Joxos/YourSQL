#pragma once
#include <vector>
#include <string>

using namespace std;

struct Table {
    string name;
};

class Database {
private:
    vector<Table> tables;
public:
    string name;
    Database(string);
    bool createTable(string);
    Table getTable(string);
    bool dropTable(string);
};