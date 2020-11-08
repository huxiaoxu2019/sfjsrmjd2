// 拓扑排序 DFS
// UVa 10305
#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int topo[N], vis[N], G[N][N], t, n, m;
bool dfs(int u) {
    vis[u] = -1; // 正在访问
    for (int v = 0; v < n; ++v) {
        if (G[u][v]) {
            if (vis[v] == -1) return false;
            if (!vis[v] && !dfs(v)) return false;
        }
    }
    vis[u] = 1;
    topo[--t] = u;
    return true;
}
bool toplogic() {
    cin >> n >> m;
    t = n;
    memset(vis, 0, sizeof vis);
    memset(G, 0, sizeof G);
    for (int i = 0, cu, cv; i < m; ++i) {
       cin >> cu >> cv;
       G[cu][cv] = 1;
    }
    for (int u = 0; u < n; ++u) {
        if (!vis[u]) {
            if (!dfs(u)) return false;
        }
    }
    return true;
}
int main() {
    if (toplogic()) {
        // print
        for (int i = 0; i < n; ++i) {
            cout << topo[i] << " ";
        }
    } else {
        cout << "No solution" << endl;
    }
    return 0;
}
