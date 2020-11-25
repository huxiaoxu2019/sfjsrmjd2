// 《算法竞赛入门经典》 9.2.2 最长路径及其字典序
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int G[N][N], d[N];
int X[N][2]; // 矩形
int n, maxv, maxi;
// input sample
// 4
// 1 2
// 2 3
// 4 5
// 3 3
// output sample
// 1 2 3
int dp(int i) {
    int &ans = d[i];
    if (ans>0) return ans;
    ans = 1;
    for (int j=1;j<=n;++j) {
        if(G[i][j]) ans = max(ans, dp(j) + 1);
    }
    return ans;
}
void print_ans(int i) {
    cout<<i<<" ";
    for(int j=1;j<=n;++j) {
        if(G[i][j] && d[i]==d[j]+1) {
            print_ans(j);
            break;
        }
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i) {
        int a,b;
        cin>>X[i][0]>>X[i][1];
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(i==j) continue;
            // i -> j, i可以嵌套在j中
            if ((X[i][0] < X[j][0] && X[i][1] < X[j][1]) || (X[i][1] < X[j][0] && X[i][0] < X[j][1])) {
                G[i][j] = 1;
                cout<<"edge i->j:"<<i<<" "<<j<<endl;
            }
        }
    }
    for (int i=1;i<=n;++i) {
        if (maxv < dp(i)) {
            maxv = dp(i);
            maxi = i;
        }
    }
    print_ans(maxi);
    return 0;
}

