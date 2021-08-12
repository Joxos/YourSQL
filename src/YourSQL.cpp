/*
SQL 面向数据库执行查询
SQL 可从数据库取回数据
SQL 可在数据库中插入新的记录
SQL 可更新数据库中的数据
SQL 可从数据库删除记录
SQL 可创建新数据库
SQL 可在数据库中创建新表
SQL 可在数据库中创建存储过程
SQL 可在数据库中创建视图
SQL 可以设置表、存储过程和视图的权限
*/

#include <iostream>
#include <vector>
#include "Functions.h"
#include "StorageEngine.h"

using namespace std;

int main() {
    cout << "Hello there. This is your SQL." << endl;
    string input;
    vector<string> words = { "" };
    while (words[0] != "exit" && words[0] != "quit") {
        cout << "yourSQL >";
        input = getuntil(';');
    }
    cout << "Bye." << endl;
    return 0;
}

