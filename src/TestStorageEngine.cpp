#include <iostream>
#include "StorageEngine.h"
#include "Functions.h"
using namespace std;

int main(void) {
    cout << "Hello scratch." << endl;
    Database test_db;
    test_db.name = "test";
    assert(true, test_db.createTable("testTable1"));
    assert(true, test_db.createTable("testTable2"));
    assert(true, test_db.dropTable("testTable1"));
}