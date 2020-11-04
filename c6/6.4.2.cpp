#include<bits/stdc++.h>
using namespace std;
const int F = 0, L = 1, R = 2; // R:1, L:3
struct Node {
    int r, c, d;
    Node(int r = 0, int c = 0, int d = 0) : r(r), c(c), d(d) {}
};
int dist[10][10][4];
Node p[10][10][4];
// 0 1 2 3 -> r d l u
int d[5] = {0, 1, 0, -1, 0};
unordered_map<char, int> ds{'E':0, 'S':1, 'W':2, 'N':3};
unordered_map<char, int> ts{'F':0, 'L':1, 'R':2};
bool can[10][10][4][3];
void solve(Node u, Node v) {

}
int main() {
    while(true) {
        memset(can, false, sizeof can);
        memset(d, 0, sizeof d);
        memset(p, 0, sizeof p);
        string name;
        cin >> name;
        Node u, v;
        char cd;
        cin >> u.r >> u.c  >> cd >> v.r >> v.c;
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
                d[u.r][u.c][u.d] = 1;
                solve(u, v);
                // print 
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
                    can[r][c][dir][limit[i]] = true;
                }
            }
        }

    }
    return 0;
}
