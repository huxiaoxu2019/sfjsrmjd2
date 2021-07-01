// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=247&page=show_problem&problem=3661
// https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch9/UVa1220.cpp
// UVa 1220
#include<bits/stdc++.h>
using namespace std;
const int maxn = 200 + 5;
vector<int> sons[maxn];
int n, d[maxn][2], f[maxn][2];
map<string, int> dict;
int cnt;
int ID(const string& s) {
    if (!dict.count(s)) dict[s]=cnt++;
    return dict[s];
}
int dp(int u, int st) {
    if (st) {
        // select u
        int sum=0;
        int unique=1;
        for (int i=0;i<sons[u].size();++i) {
            int v = sons[u][i];
            sum+=dp(v,0);
            if (!f[v][0]) unique=0;;
        }
        d[u][1]=1+sum;
        f[u][1]=unique;
    } else {
        // not select u
        int sum=0;
        int unique=1;
        for (int i=0;i<sons[u].size();++i) {
            int v=sons[u][i];
            // v0 for not select v, v1 for select v
            int v0=dp(v,0), v1=dp(v,1);
            sum+=max(v0,v1);
            if (v0==v1||(v0>v1&&f[v][0]==0)||(v1>v0&&f[v][1]==0)) unique=0;
        }
        d[u][0]=sum;
        f[u][0]=unique;
    } 
    return d[u][st];
}

int main() {
    string s, s2;
    while (cin>>n>>s) {
        cnt = 0;
        dict.clear();
        for (int i=0;i<n;++i) sons[i].clear();
        ID(s);
        for (int i=0;i<n-1;++i) {
            cin>>s>>s2;
            sons[ID(s2)].push_back(ID(s));
        }
        printf("%d ", max(dp(0,0), dp(0,1)));
        bool unique=false;
        if (d[0][0]>d[0][1] && f[0][0]) unique=true;
        if (d[0][1]>d[0][0] && f[0][1]) unique=true;
        if (unique) printf("Yes\n"); else printf("No\n");
    }
    
    return 0;
}
