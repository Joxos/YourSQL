#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <iostream>
#include <regex>
#include "Functions.h"
using namespace std;
//笔记：头文件中只能放变量和函数的声明，不能写定义
//例外：类、const变量，inline函数

namespace analysis {
    enum INF_TYPE {
        NUL,
        COMMAND,
        VALUE,
        OPERATOR,
        INVAILD
    };

    const int MAX_TOKEN = 1000;

    struct TNode {
        TNode() {}
        TNode(string inff, INF_TYPE iftt) :inf(inff), ift(iftt) {}
        string inf;
        INF_TYPE ift;
    };

    struct TEdge {
        int v, next;
    };

    class TTree {
    public:
        TTree() :cur(0) {
            memset(p, -1, sizeof(p));
        }
        ~TTree() {}
        bool insert(int u, int v);
    private:
        TEdge eg[MAX_TOKEN];
        int p[MAX_TOKEN];
        int cur;
    };


    extern vector<TNode> tokens;
    INF_TYPE judgeType(string& tk);
    bool getTokens(string cmd);
    void printTokens();
    TTree* analysisToken();
}