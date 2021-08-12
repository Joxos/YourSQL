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
    bool newTable(string table_name);
    bool delTable(string table_name);
};
