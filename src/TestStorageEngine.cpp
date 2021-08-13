#include <iostream>
#include "StorageEngine.h"
#include "Functions.h"
using namespace std;

int main(void) {
    cout << "Hello scratch." << endl;
    Database* test_db = new Database("test");
    assert(true, test_db->createTable("testTable"));
    assert(false, test_db->createTable("testTable"));
    try {
        test_db->getTable("testTable");
        test_db->getTable("foo");
    }
    catch (string msg) {
        cerr << msg << endl;
    }
    assert(true, test_db->dropTable("testTable"));
    assert(false, test_db->dropTable("foo"));
}