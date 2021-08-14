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
    if (tr == nullptr) {
        cout << "INVAILD" << endl;
        return -1;
    }
    printTree(tr, tksz); //详见Analysis.cpp处注释
    //TTree DEMO INSTRUCTIONS README:
    /*
    * 
    * 现在暂时的语法：
    * 支持关键字create add delete select(ift标识为COMMAND)
    * 变量如右形式：_var_（左右加下划线）(ift标识为VARIABLE)
    * 支持的数据类型：string和int 字符串请加上双引号，数字直接写(ift标识为VALUE)
    * 操作符：加减乘除还有== >= <= !=(ift标识为OPERATOR)
    * 若输入了不符合以上规则的命令，ift标识为INVAILD，analysisToken将返回nullptr，无法生成语义树
    * 例子：create _a_
    * 语义树如下：
    *            X
    *         /     \
    *      create    X
    *                |
    *               _a_
    * 只是最基本的
    * 待我明天查一下标准SQL语法
    * 或者咱们其实可以自己定一套方法
    * 毕竟是自己写的
    * ·如何加关键字、操作符
    *   Functions.cpp中直接在keyws(关键字)、opts(操作符)中加即可，不用动别的
    *  
    */
    return 0;
}
