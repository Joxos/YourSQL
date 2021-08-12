#pragma once
#include <iostream>
#include <vector>
using namespace std;

string getuntil(char sign);
void trim(string& msg);
void validateFolder(const char*);
template <typename T>
bool ifexsist(vector<T>, T);
void assert(bool, bool);

template<typename T>
inline bool ifexsist(vector<T> items, T to_check) {
    for (auto i = items.begin(); i != items.end(); ++i) {
        if ((*i) == to_check) {
            return true;
        }
    }
    return false;
}
