// 完全背包
// 起点固定（终点任意）的、边权之和最大的路径和
// 阶段 f[i] 代表容量为 i 时，能够获得的最大价值
#include<bits/stdc++.h>
using namespace std; 
const int N = 1e3 + 5;
int n, v[N], w[N], C, f[N];
int main() {
    cin>>n>>C;
    memset(f,0,sizeof f);
    for(int i=1;i<=n;++i) {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=C;++i) {
        for(int j=1;j<=n;++j) {
            if(j>=v) f[i][j] = max(f[i][j],f[i-1][j-v]+w);
        }
    }
    cout<<f[C]<<endl;
    return 0;
}
