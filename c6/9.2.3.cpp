// 《算法竞赛入门经典》 9.2.3 固定终点的最长路和最短路
// n个硬币，每种无限多，使得面值之和恰好为S的硬币数量的最小值与最大值
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int minv[N], maxv[N];
int S, n;
int coins[N];
int max_coins[N], min_coins[N];
// input sample
// S n
// 1 2 3 5
// output sample
// 2 10
// 4 4 具体方案（硬币no）
// 1 1 1 1 1 1 1 1 1 1
void print_ans() {
    int s=S;
    while(s) {
        cout<<min_coins[s]<<" ";
        s-=coins[min_coins[s]];
    }
    cout<<endl;
    s=S;
    while(s) {
        cout<<max_coins[s]<<" ";
        s-=coins[max_coins[s]];
    }
}
int main() {
    cin>>S>>n;
    for(int i=1;i<=n;++i) {
        cin>>coins[i];
    }
    memset(minv, 0x3f, sizeof minv); memset(maxv, 0xc0, sizeof maxv);
    minv[0] = maxv[0] = 0;
    for(int i=1;i<=S;++i) {
        for(int j=1;j<=n;++j) {
            if (i>=coins[j]) {
                if(minv[i] > minv[i-coins[j]]+1) {
                    minv[i]=minv[i-coins[j]]+1;
                    min_coins[i]=j;
                }
                if(maxv[i]<maxv[i-coins[j]]+1) {
                    maxv[i]=maxv[i-coins[j]]+1;
                    max_coins[i]=j;
                }
            }
        }
    }
    cout<<minv[S]<<" "<<maxv[S]<<endl;
    print_ans();
    return 0;
}
