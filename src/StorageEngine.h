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
    bool createTable(string table_name);
    bool dropTable(string table_name);
};
