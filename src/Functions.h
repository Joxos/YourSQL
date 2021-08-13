#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace analysis {
    extern int osz, ksz;
    extern string opts[];
    extern string keyws[];
    bool jdge(string str, string* lst, int sz);
}

string getuntil(char sign);
void trim(string& msg);
void validateFolder(const char*);
template <typename T>
void assert(bool, bool);

