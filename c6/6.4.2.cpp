#include<bits/stdc++.h>
using namespace std;
struct Node {
    int r, c, d;
    Node(int r = 0, int c = 0, int d = 0) : r(r), c(c), d(d) {}
};
int dist[10][10][4];
Node p[10][10][4];
// 0 1 2 3 -> r(E) d(S) l(W) u(N)
int d[5] = {0, 1, 0, -1, 0};
unordered_map<char, int> ds{'E':0, 'S':1, 'W':2, 'N':3};
unordered_map<char, int> ts{'F':0, 'L':1, 'R':2};
bool can[10][10][4][3];
queue<Node> q;
Node walk(Node u, int ti) {
    if (ti == 1) u.d = (u.d + 3) % 4;
    if (ti == 2) u.d = (u.d + 1) % 4;
    Node v(u.r + d[u.d], u.c + d[u.d + 1], u.d);
}
void solve(Node& u, Node& v) {
    q.push(u);
    while (!q.empty()) {
        auto n = q.front();
        q.pop();
        for (int ti = 0; ti < 3; ++ti) {
            if (can[u.r][u.c][u.d][ti] == false) continue;
            auto n = walk(u, ti);
            if (dist[n.r][n.c][n.d] <= dist[u.r][u.c][u.d] + 1) continue;
            dist[n.r][n.c][n.d] = dist[u.r][u.c][u.d] + 1;
            p[n.r][n.c][n.d] = u;
            if (n.r == v.r && n.c == v.c) {
                v.d = n.d;
                return;
            }
            q.push(n);
        }
    }
}
void print_ans(Node& v, string& name) {
    cout << name << endl;
    if (v.d == -1) {
        cout << "  No Solution Possible" << endl;
        return;
    }
    vector<Node> ans;
    Node n = v;
    while(true) {
        ans.push_back(n);
        auto nn = p[n.r][n.c][n.d];
        if (d[n.r][n.c][n.d] == 0) {
            ans.push_back(nn);
            break;
        }
        n = nn;
    }
    cout << " ";
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << "(" << ans[i].r << "," << ans[i].c << ") ";
    }
}
int main() {
    while(true) {
        memset(can, false, sizeof can);
        memset(dist, 0x3f, sizeof dist);
        string name;
        cin >> name;
        Node u, v;
        char cd;
        cin >> u.r >> u.c  >> cd >> v.r >> v.c;
        v.d = -1;
        int u.d = ds[cd];
        string line;
        while (true) {
            cin >> line;
            streamstring sline(line);
            int r, c;
            sline >> r;
            if (r == 0) {
                int lr = u.r, lc = u.c;
                u.r += d[u.d], u.c += d[u.d + 1];
                p[u.r][u.c][u.d] = {lr, lc, u.d};
                d[u.r][u.c][u.d] = 0;
                solve(u, v);
                // print 
                print_ans(v, name);
                break;
            }
            sline >> c;
            string limit;
            while (sline >> limit) {
                if (limit == "*") {
                    break;
                }
                int dir = ds[limit[0]];
                for (int i = 1; i < limit.size(); ++i) {
                    can[r][c][dir][ts[limit[i]]] = true;
                }
            }
        }

    }
    return 0;
}
