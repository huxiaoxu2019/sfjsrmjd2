// 2020/11/18
// 二叉树的编号
// UVa 679
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
/**
const int maxd = 20;
int s[1<<maxd];
int main() {
    int D, I;
    while(scanf("%d%d", &D, &I) == 2) {
        memset(s, 0, sizeof s);
        int k, n = (1 << D) - 1;
        for (int i = 0; i < I; ++i) {
            k = 1;
            while(true) {
                s[k] = !s[k];
                k = s[k] ? 2*k : 2*k+1;
                if (k > n) break;
            }
        }
        printf("%d\n", k / 2);
    }
    return 0;
}
*/
int main() {
    int I, D;
    while (scanf("%d%d", &D, &I) == 2) {
        int k = 1;
        for (int i = 0; i < D - 1; ++i) {
            if (I % 2 == 0) {
                // right
                k = 2 * k + 1;
                I = I / 2;
            } else {
                // left
                k = 2 * k;
                I = (I + 1) / 2;
            }
        }
        printf("%d\n", k);
    }
    return 0;
}
