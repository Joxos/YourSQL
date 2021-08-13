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
    int osz = sizeof(opts) / sizeof(string); //�ʼǣ�sizeofֻ���������鶨���ͬ�ļ��ڷ�������
    string keyws[] = { "create", "delete", "add", "select" }; //����
    int ksz = sizeof(keyws) / sizeof(string);
    //���str�Ƿ�Ϊlst����Ԫ�أ�lst��СΪsz
    bool jdge(string str, string* lst, int sz) {
        /* �ʼǣ�
        * if (find(lst, lst + sz + 1, str) != lst + sz + 1) {
            cout << *lst << " " << *find(lst, lst + sz + 1, str) << endl;
            return true;
          }
          ����ף�opts��keyws���ڴ����������ģ����������Ϸ�������������opt + sz + 1���þ���keyws[0]
          ֻ��������forѭ����,mdzz......
        */
        for (int i = 0; i < sz; i++)
            if (str == *(lst + i))
                return true;
        return false;
    }
}

namespace analysis {
    string opts[] = { "<=", ">=", "==", "!=" };
    int osz = sizeof(opts) / sizeof(string); //�ʼǣ�sizeofֻ���������鶨���ͬ�ļ��ڷ�������
    string keyws[] = { "create", "delete", "add", "select" }; //����
    int ksz = sizeof(keyws) / sizeof(string);
    //���str�Ƿ�Ϊlst����Ԫ�أ�lst��СΪsz
    bool jdge(string str, string* lst, int sz) {
        /* �ʼǣ�
        * if (find(lst, lst + sz + 1, str) != lst + sz + 1) {
            cout << *lst << " " << *find(lst, lst + sz + 1, str) << endl;
            return true;
          }
          ����ף�opts��keyws���ڴ����������ģ����������Ϸ�������������opt + sz + 1���þ���keyws[0]
          ֻ��������forѭ����,mdzz......
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

