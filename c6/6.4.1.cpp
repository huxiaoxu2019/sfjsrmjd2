// https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch6/UVa572.cpp
// http://acm.hdu.edu.cn/showproblem.php?pid=1241
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
char ma[N][N];
int n, m, idx[N][N];
void dfs(int r, int c, int no) {
    idx[r][c] = no;
    for (int dr = -1; dr <= 1; ++dr)
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc ==0) continue;
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (idx[nr][nc] != 0 || ma[nr][nc] != '@') continue;
            dfs(nr, nc, no);
        }
}
int main() {
    while (scanf("%d%d", &m, &n) == 2 && m && n) {
        for (int i = 0; i < m; ++i) scanf("%s", ma[i]);
        memset(idx, 0, sizeof idx);
        int cnt = 0;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (idx[r][c] == 0 && ma[r][c] == '@') dfs(r, c, ++cnt);
        printf("%d\n", cnt);
    }
    return 0;
}
