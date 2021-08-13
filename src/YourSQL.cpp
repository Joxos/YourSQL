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
#include "Analysis.h"

using namespace std;
using namespace analysis;

int main() {
    /*
    cout << "Hello there. This is your SQL." << endl;
    string input;
    vector<string> words = { "" };
    while (words[0] != "exit" && words[0] != "quit") {
        cout << "yourSQL >";
        input = getuntil(';');
        words = split(input);
        for (auto node : words) {
            cout << node << endl;
        }
    }
    cout << "Bye." << endl;
    */
    /* lex analysis test
    * string st;
    getline(cin, st);
    if (!getTokens(st)) {
        cout << "INVAILD!" << endl;
        return 0;
    }
    printTokens();
    */
    string a;
    getline(cin, a);
    TTree* tr = analysisToken(a);
    printTree(tr, tksz);
    return 0;
}

