// 01 背包
// f[i][j] 前 i 个物品放入容量为 j 的背包中的最大价值
// f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int C,n,f[N][N];
int v,w;
int main() {
    cin>>n>>C;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;++i) {
        cin>>v>>w;
        for(int j=1;j<=C;++j) {
            f[i][j]=f[i-1][j];
            if(j>=v) f[i][j] = max(f[i][j],f[i-1][j-v]+w);
        }
    }
    cout<<f[n][C]<<endl;
    return 0;
}
