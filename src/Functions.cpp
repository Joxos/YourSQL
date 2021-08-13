#include "Functions.h"
#include <direct.h>
#include <io.h>

void validateFolder(const char* runtime_path) {
    if (_access(runtime_path, 0) == -1)
        _mkdir(runtime_path);
}

void assert(bool should_be, bool res) {
    if (should_be == res)
        cout << "Good." << endl;
    else
        cout << "Bad!" << endl;
}

namespace analysis {
    string opts[] = { "<=", ">=", "==", "!=", "+", "-", "*", "/" };
    int priority[] = { 0, 0, 0, 0, 1, 1, 2, 2 };
    int osz = sizeof(opts) / sizeof(string); //笔记：sizeof只能在其数组定义的同文件内发挥作用
    string keyws[] = { "create", "delete", "add", "select" }; //待定
    int ksz = sizeof(keyws) / sizeof(string);
    //检查str是否为lst集中元素，lst大小为sz
    bool jdge(string str, string* lst, int sz) {
        /* 笔记：
        * if (find(lst, lst + sz + 1, str) != lst + sz + 1) {
            cout << *lst << " " << *find(lst, lst + sz + 1, str) << endl;
            return true;
          }
          离大谱，opts和keyws在内存里是连续的，不能用如上方法搜索，否则opt + sz + 1正好就是keyws[0]
          只能用垃圾for循环了,mdzz......
        */
        for (int i = 0; i < sz; i++)
            if (str == *(lst + i))
                return true;
        return false;
    }
}

namespace analysis {
    string opts[] = { "<=", ">=", "==", "!=" };
    int osz = sizeof(opts) / sizeof(string); //笔记：sizeof只能在其数组定义的同文件内发挥作用
    string keyws[] = { "create", "delete", "add", "select" }; //待定
    int ksz = sizeof(keyws) / sizeof(string);
    //检查str是否为lst集中元素，lst大小为sz
    bool jdge(string str, string* lst, int sz) {
        /* 笔记：
        * if (find(lst, lst + sz + 1, str) != lst + sz + 1) {
            cout << *lst << " " << *find(lst, lst + sz + 1, str) << endl;
            return true;
          }
          离大谱，opts和keyws在内存里是连续的，不能用如上方法搜索，否则opt + sz + 1正好就是keyws[0]
          只能用垃圾for循环了,mdzz......
        */
        for (int i = 0; i < sz; i++)
            if (str == *(lst + i))
                return true;
        return false;
    }
}

string getuntil(char sign) {
    char c;
    string msg = "";
    cin.get(c);
    while (c != sign) {
        msg = msg + c;
        cin.get(c);
    }
    return msg;
}

void trim(string& msg) {
    msg.erase(0, msg.find_first_not_of(' '));
    msg.erase(msg.find_last_not_of(' ') + 1);
}

vector<string> split(string msg) {
    string word;
    vector<string> words;
    for (auto c : msg) {
        if (c != ' ' && c != '\n') {
            word += c;
        }
        else if (word != "") {
            words.push_back(word);
            word = "";
        }
    }
    if (word != "")
        words.push_back(word);
    return words;
}

