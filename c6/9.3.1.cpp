// Uva 116 单向TSP
// GitHub https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch9/UVa116.cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M = 15, N = 105;
int m,n,grid[M][N],Next[M][N],first_row;
LL d[M][N],minv;
void solve() {
    memset(d, 0x3f, sizeof d);
    minv=LONG_MAX;
    for(int r=1;r<=m;++r) {
        d[r][n]=grid[r][n];
    }
    for(int c=n;c>=2;--c) {
        for(int r=1;r<=m;++r) {
            int rows[3] = {r-1,r,r+1};
            if(r==1) rows[0]=m;
            if(r==m) rows[2]=1;
            for(int ri=0;ri<3;++ri) {
                int cv=d[r][c]+grid[rows[ri]][c-1];
                if(d[rows[ri]][c-1]>cv) {
                    d[rows[ri]][c-1]=cv;
                    Next[rows[ri]][c-1]=r;
                    if(c==2) {
                        if(minv>d[rows[ri]][c-1] || (minv==d[rows[ri]][c-1] && first_row>rows[ri])) {
                            minv=d[rows[ri]][c-1];
                            first_row=rows[ri];
                        }
                    }
                }
            }
        }
    }
}
void print_ans() {
    printf("%d", first_row);
    int row = first_row;
    for(int c=1;c<=n-1;++c) {
        row=Next[row][c];
        printf(" %d", row);
    }
    printf("\n%lld\n", minv);
}
int main() {
    while(scanf("%d%d",&m,&n)==2 && m) {
        for(int r=1;r<=m;++r) {
            for(int c=1;c<=n;++c) {
                scanf("%d",&grid[r][c]);
            }
        }
        solve();
        print_ans();
    }
}
