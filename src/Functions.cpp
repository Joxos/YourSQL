#include "Functions.h"

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
