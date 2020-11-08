// BFS 最短路
// UVa 816
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
struct Node {
    int r, c, d;
    Node(int r = 0, int c = 0, int d = 0) : r(r), c(c), d(d) {}
};
ostream& operator << (ostream& out, const Node& p) {
    cout << "(" << p.r << "," << p.c << "," << p.d << ")";
    return out;
}
int dist[10][10][4];
Node p[10][10][4];
// 0 1 2 3 -> r(E) d(S) l(W) u(N)
int d[5] = {0, 1, 0, -1, 0};
unordered_map<char, int> ds{{'E',0}, {'S',1}, {'W',2}, {'N',3}};
unordered_map<char, int> ts{{'F',0}, {'L',1}, {'R',2}};
bool can[10][10][4][3];
queue<Node> q;
Node walk(Node u, int ti) {
    if (ti == 1) u.d = (u.d + 3) % 4;
    if (ti == 2) u.d = (u.d + 1) % 4;
    Node v(u.r + d[u.d], u.c + d[u.d + 1], u.d);
    return v;
};
void solve(Node& uu, Node& vv) {
    //cout << "solve:" << endl;
    q.push(uu);
    //cout << "uu:" << uu << " vv:" << vv << endl;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        //cout << "pop item:" << u << endl;
        for (int ti = 0; ti < 3; ++ti) {
            if (can[u.r][u.c][u.d][ti] == false) continue;
            //cout << "can" << endl;
            auto v = walk(u, ti);
            //cout << "ti:" << ti << " v:" << v << endl;
            if (dist[v.r][v.c][v.d] <= dist[u.r][u.c][u.d] + 1) continue;
            //cout << "dist yes" << endl;
            dist[v.r][v.c][v.d] = dist[u.r][u.c][u.d] + 1;
            p[v.r][v.c][v.d] = u;
            if (v.r == vv.r && v.c == vv.c) {
                vv.d = v.d;
                return;
            }
            q.push(v);
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
        if (dist[n.r][n.c][n.d] == 0) {
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
        if (name == "END") break;
        Node u, v;
        char cd;
        cin >> u.r >> u.c  >> cd >> v.r >> v.c;
        v.d = -1;
        u.d = ds[cd];
        //cout << "r:" << u.r << " c:" << u.c << " d:" << cd << " r:" << v.r << " c:" << v.c << endl;
        string line;
        getline(cin, line); // \n
        while (true) {
            getline(cin, line);
            //cout << "line:" << line << endl;
            stringstream sline(line);
            int r, c;
            sline >> r;
            if (r == 0) {
                int lr = u.r, lc = u.c;
                u.r += d[u.d], u.c += d[u.d + 1];
                p[u.r][u.c][u.d] = {lr, lc, u.d};
                dist[u.r][u.c][u.d] = 0;
                solve(u, v);
                // print 
                print_ans(v, name);
                break;
            }
            sline >> c;
            string limit;
            //cout << "r:" << r << " c:" << c << endl;
            while (sline >> limit) {
                if (limit == "*") {
                    break;
                }
                int dir = ds[limit[0]];
                //cout << " d:" << limit[0] << " dir:" << dir << endl;
                for (int i = 1; i < limit.size(); ++i) {
                    //cout << "ts:" << ts[limit[i]] << endl;
                    can[r][c][dir][ts[limit[i]]] = true;
                }
            }
        }

    }
    return 0;
}
