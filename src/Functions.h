#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace analysis {
	extern int osz, ksz;
	extern string opts[];
	extern string keyws[];
	extern int priorty[];
	bool jdge(string str, string* lst, int sz);
}
string getuntil(char sign);
void trim(string& msg);
void validateFolder(const char*);
void assert(bool, bool);

