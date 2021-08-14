#include "Analysis.h"

namespace analysis {
    vector<TNode> tokens;
    int tksz = -1;
    INF_TYPE judgeType(string& tk) {
        if (regex_match(tk, regex("\\d+")) || (tk[0] == '\"' && tk[tk.size() - 1] == '\"')) {
            //cout << "val" << endl;
            return VALUE;
        }
        if (tk[0] == '_' && tk[tk.size() - 1] == '_') {
            //cout << "var" << endl;
            return VARIABLE;
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
        tksz = tokens.size();
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

	int foreach(TTree* tree, int u, int& cur) { //u父亲节点，cur正在读入的token
		if (cur > tksz - 1) return 0;
		if (tokens[cur].ift == COMMAND) {
			tree->insert(u, cur);
			tokens.push_back(TNode("X", NUL));
			tree->insert(u, tokens.size() - 1);
			cur++;
			printTree(tree, tksz);
			return foreach(tree, tokens.size() - 1, cur);
		}
		else if (tokens[cur].ift == VALUE || tokens[cur].ift == VARIABLE) {
			if (cur <= tksz - 2) { //分层写防止溢出
				if (tokens[cur + 1].ift == OPERATOR) {
					tokens.push_back(TNode("X", NUL));
					tree->insert(u, tokens.size() - 1);
					tree->insert(tokens.size() - 1, cur);
					cur++;
					printTree(tree, tksz);
					return foreach(tree, u, cur);
				}
			}
			else {
				tree->insert(u, cur);
				cur++;
				printTree(tree, tksz);
				return foreach(tree, cur - 1, cur);
			}
		}
		else if (tokens[cur].ift == OPERATOR) {
			tree->insert(u, cur);
			tokens.push_back(TNode("X", NUL));
			tree->insert(u, tokens.size() - 1);
			cur++;
			printTree(tree, tksz);
			return foreach(tree, tokens.size() - 1, cur);
		}
		else {
			printTree(tree, tksz);
			return 1;
		}
	}

	TTree* analysisToken(string cmd) {
		getTokens(cmd);
		TTree* tree = new TTree();
		tokens.push_back(TNode("X", NUL));
		int currentRead = 0;
		foreach(tree, tokens.size() - 1, currentRead);
		return tree;
	}

    //按层序输出语义树，但每层都是反的，懒得再用stack搞，自行反过来看
    void printTree(TTree* tree, int u) {
        queue<pair<TEdge, int> > q;
        queue<int> fa;
        for (int i = tree->p[u]; i != -1; i = tree->eg[i].next) {
            q.push(make_pair(tree->eg[i], 0));
            fa.push(u);
        }
        int cr = 0;
        while (!q.empty()) {
            pair<TEdge, int> tg = q.front();
            q.pop();
            if (tg.second > cr) {
                cout << endl;
                cr++;
            }
            cout << tokens[fa.front()].inf << "->" << tokens[tg.first.v].inf << " ";
            fa.pop();
            int v = tg.first.v;
            for (int i = tree->p[v]; i != -1; i = tree->eg[i].next) {
                q.push(make_pair(tree->eg[i], tg.second + 1));
                fa.push(v);
            }
        }
        cout << endl << endl;
    }
}