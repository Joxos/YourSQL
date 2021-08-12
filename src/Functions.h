#pragma once
#include <iostream>
#include <vector>
using namespace std;

string getuntil(char sign);
void trim(string& msg);
void validateFolder(const char*);
template <typename T>
void assert(bool, bool);

