#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int f[maxn];
bool p[maxn][maxn];
int n, T;
char s[maxn];
void getp() {
    memset(p,false,sizeof p);
    for (int i=1;i<=n;++i) {
        for (int l=0;l<=n;++l) {
            int left=i-l, right=i+l;
            if (left < 1 || right > n) break;
            if (left==right) {
                p[left][right]=true;
            } else {
                p[left][right] = p[left+1][right-1] && (s[left] == s[right]);
            }
            if (p[left][right]==false) break;
        }
    }
    for (int i=1;i<=n;++i) {
        for (int l=0;l<=n;++l) {
            int left=i-l, right=i+l+1;
            if (left < 1 || right > n) break;
            if (left+1==right) {
                p[left][right]=s[left]==s[right];
            } else {
                p[left][right] = p[left+1][right-1] && (s[left] == s[right]);
            }
            if (p[left][right]==false) break;
        }
    }
}
 int main() {
     scanf("%d", &T);
     while (T--) {
        scanf("%s", s+1);
        n=strlen(s+1);
        getp();
        memset(f, 0x3f, sizeof f);
        f[0]=0;
        for (int i=1;i<=n; ++i) {
            for (int j=0;j<i;++j) {
                // ...j...i, j+1~i
                if (p[j+1][i]) f[i] = min(f[i], f[j] + 1);
                //printf("i:%d,j:%d,p[j+1][i]:%d\n", i, j, p[j+1][i]);
            }
        }
        printf("%d\n", f[n]);
     }
     return 0;
 }

