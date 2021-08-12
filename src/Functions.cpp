#include "Functions.h"
#include <direct.h>
#include <io.h>

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
