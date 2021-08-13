#include "Analysis.h"

namespace analysis {
    vector<TNode> tokens;
    INF_TYPE judgeType(string& tk) {
        if (regex_match(tk, regex("\\d+")) || (tk[0] == '\"' && tk[tk.size() - 1] == '\"')) {
            //cout << "val" << endl;
            return VALUE;
        }
        if (jdge(tk, opts, osz)) {
            //cout << "ope" << endl;
            return OPERATOR;
        }
        if (jdge(tk, keyws, ksz)) {
            //cout << "keyws" << endl;
            return COMMAND;
        }
        //cout << "invaild" << endl;
        return INVAILD;
    }

    bool getTokens(string cmd) {
        istringstream ss(cmd);
        while (ss.rdbuf()->in_avail() > 0) {
            string temp;
            ss >> temp;
            if (temp == "") break;
            tokens.push_back(TNode(temp, judgeType(temp)));
            if (tokens[tokens.size() - 1].ift == INVAILD) return false;
        }
        return true;
    }

    void printTokens() {
        for (int i = 0; i < tokens.size(); i++) {
            cout << tokens[i].ift << tokens[i].inf << endl;
        }
    }

    bool TTree::insert(int u, int v) {
        if (cur >= MAX_TOKEN)
            return false;
        eg[cur].v = v;
        eg[cur].next = p[u];
        p[u] = cur++;
        return true;
    }

    TTree* analysisToken() {

    }
}