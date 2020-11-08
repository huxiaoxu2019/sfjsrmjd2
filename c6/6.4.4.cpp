// 欧拉回路 AC
// UVa 10129 https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1070
// GitHub https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch6/UVa10129.cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int pa[256]; // 并查集
int findp(int x) {return pa[x] == x ? x : pa[x] = findp(pa[x]);}
int deg[256], used[256];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char word[N];
        cin >> n;
        memset(used, 0, sizeof used);
        memset(deg, 0, sizeof deg);
        int cc = 26; // 连通块个数
        for (char c = 'a'; c <= 'z'; ++c) pa[c] = c;

        for (int i = 0; i < n; ++i) {
            scanf("%s", word);
            char u = word[0], v = word[strlen(word) - 1];
            int pu = findp(u), pv = findp(v);
            deg[u]++;
            deg[v]--;
            used[u] = used[v] = 1;
            if (pu != pv) {
                pa[pv] = pu;
                --cc;
            }
        }

        vector<int> d;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (!used[c]) --cc;
            else if (deg[c] != 0) {
                d.push_back(deg[c]);
            }
        }

        if (cc == 1 && (d.empty() || (d.size() == 2 && (d[0] == 1 || d[0] == -1)))) {
            cout << "Ordering is possible." << endl;
        } else {
            cout << "The door cannot be opened." << endl;
        }
    }
    return 0;
}
