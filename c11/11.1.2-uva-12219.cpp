// UVa 12219
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=244&page=show_problem&problem=3371
// https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch11/UVa12219.cpp
#include<cstdio>
#include<string>
#include<map>

using namespace std;

const int maxn=60010;
int T, kase, cnt;
char exp[maxn * 5], *p;
int done[maxn];

struct Node{
    string s;
    int hash, left, right;
    bool operator < (const Node& node) const {
        if (hash != node.hash) return hash < node.hash;
        if (left != node.left) return left < node.left;
        return right < node.right;
    }
} node[maxn];

map<Node, int> dict;

// in-order dfs
int parse() {
    int id=cnt++; // from 0
    Node& u = node[id];
    u.left = u.right = -1;
    u.s = ""; u.hash = 0;
    while(isalpha(*p)) {
        u.hash = u.hash * 27 + *p - 'a' + 1;
        u.s.push_back(*p);
        ++p;
    }
    if (*p == '(') {
        ++p;u.left = parse();++p;u.right = parse();++p;
    }
    if (dict.count(u) != 0) {
        --cnt;
        return dict[u];
    }
    return dict[u] = id;
}

void print(int u) {
    if (done[u] == kase) {
        printf("%d", u + 1);
    } else {
        done[u] = kase;
        printf("%s", node[u].s.c_str());
        if (node[u].left != -1) {
            putchar('(');
            print(node[u].left);
            putchar(',');
            print(node[u].right);
            putchar(')');
        }
    }
}

int main() {
    scanf("%d", &T);
    for (kase = 1; kase <= T; ++kase) {
        dict.clear();
        cnt = 0;
        scanf("%s", exp);
        p = exp;
        print(parse());
        putchar('\n');
    }
    return 0;
}
