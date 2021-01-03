// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=944
// https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch9/UVa10003.cpp
// UVa 10003
// Tips: 区间DP，length 代表区间的长度（即点的个数），所以习惯写法
// for (int len = 1;len <= maxLen; ++len) {
//     for (int i = minLeft; i + len - 1 <= maxRight; ++i) {
//         int j = i + len - 1;
//     }
// }
#include<bits/stdc++.h>
using namespace std;
int f[105][105];
int a[105];
int L,n;
int main() {
    while (scanf("%d%d", &L, &n) == 2 && L) {
        a[0] = 0;
        a[n+1] = L;
        for (int i=1;i<=n;++i) scanf("%d", &a[i]);
        memset(f,0x3f,sizeof f);
        for (int l=1;l<=n+2;++l) {
            for (int i=0;i+l-1<=n+1;++i) {
                int j=i+l-1;
                if (l<=2) {
                    f[i][j] = 0;
                    continue;
                }
                for (int k=i+1;k<=j-1;++k) {
                    // f[i][j] = min{f[i][k] + f[k][j] + a[j] - a[i], f[i][j]}
                    f[i][j] = min(f[i][k] + f[k][j] + a[j] - a[i], f[i][j]);
                }
            }
        }
        printf("The minimum cutting is %d.\n", f[0][n+1]);
    }
    return 0;
}
