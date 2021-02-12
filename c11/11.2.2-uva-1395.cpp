// UVa 1395
// https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch11/UVa1395.cpp
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=446&page=show_problem&problem=4141
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int fa[N];
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
};

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {};
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

vector<Edge> e;
int n, m, u, v, w;

int solve() {
    sort(e.begin(), e.end());
    int ans = INT_MAX;
    for (int L = 0; L < m; ++L) {
        for (int i = 1; i <= n; ++i) fa[i] = i;
        int cnt = 0;
        for (int R = L; R < m; ++R) {
            int u = e[R].u, v = e[R].v, w = e[R].w;
            int pu = find(u), pv = find(v);
            if (pu == pv) continue;
            fa[pu] = pv;
            ++cnt;
            if (cnt == n - 1) {
                ans = min(ans, w - e[L].w);
                break;
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    while(scanf("%d%d", &n, &m) == 2 && n) {
        // n for nodes, m for edges
        e.clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            e.push_back({u, v, w});
        }
        printf("%d\n", solve());
    }
    return 0;
}
