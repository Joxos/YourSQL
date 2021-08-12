#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace analysis {
	extern int osz, ksz;
	extern string opts[];
	extern string keyws[];
	bool jdge(string str, string* lst, int sz);
}
string getuntil(char sign);
void trim(string& msg);
vector<string> split(string msg);