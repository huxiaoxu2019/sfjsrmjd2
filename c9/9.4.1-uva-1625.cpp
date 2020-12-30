// https://www.cnblogs.com/violet-acmer/p/11010582.html
// https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch9/UVa1625.cpp
// https://onlinejudge.org/external/16/1625.pdf
// UVa 1625
// Tip: 在for里面，每次需要初始化变量 memset!!!
//      memset 耗时，TLE
#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int d[maxn][maxn], c[maxn][maxn];
char p[maxn], q[maxn];
int n, m;
int sp[26], ep[26], sq[26], eq[26];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s%s", p+1, q+1);
        n = strlen(p+1);
        m = strlen(q+1);
        for(int i = 1; i <= n; i++) p[i] -= 'A';
        for(int i = 1; i <= m; i++) q[i] -= 'A';

        for(int i = 0; i < 26; i++) {sp[i] = sq[i] = 0x3f3f3f3f; ep[i] = eq[i] = 0; }
        for (int i=1;i<=n;++i) {
            sp[p[i]] = min(sp[p[i]], i);
            ep[p[i]] = i;
        }
        for (int i=1;i<=m;++i) {
            sq[q[i]] = min(sq[q[i]], i);
            eq[q[i]] = i;
        }
        for (int i=0;i<=n;++i) {
            for (int j=0;j<=m;++j) {
                if (i) {
                    c[i][j] = c[i-1][j];
                    if (sp[p[i]] == i && sq[p[i]] > j) c[i][j]++;
                    if (ep[p[i]] == i && eq[p[i]] <= j) c[i][j]--;
                } else if (j) {
                    c[i][j] = c[i][j-1];
                    if (sq[q[j]] == j && sp[q[j]] > i) c[i][j]++;
                    if (eq[q[j]] == j && ep[q[j]] <= i) c[i][j]--;
                }
            }
        }
        for (int i=0;i<=n;++i) {
            for (int j=0;j<=m;++j) {
                if (!i && !j) continue;
                d[i][j]=0x3f3f3f3f;
                if (i) d[i][j] = min(d[i][j], d[i-1][j] + c[i-1][j]);
                if (j) d[i][j] = min(d[i][j], d[i][j-1] + c[i][j-1]);
                //cout<<"i:"<<i<<" j:"<<j<<" d:"<<d[i][j]<<endl;
            }
        }
        
        printf("%d\n", d[n][m]);
    }
    return 0;
}
