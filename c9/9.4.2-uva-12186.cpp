// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3338&mosmsg=Submission+received+with+ID+26526401
// https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch9/uva12186.cpp
// UVa 12186
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int N, T;
vector<int> sons[maxn];
int dp(int u) {
    if (sons[u].empty()) return 1;
    int k = sons[u].size();
    vector<int> d;
    for (int i=0;i<k;++i) d.push_back(dp(sons[u][i]));
    sort(d.begin(), d.end());
    int c = (k*T - 1) / 100 + 1;
    int ans = 0;
    for (int i=0;i<c;++i) ans += d[i];
    return ans;
}
int main() {
    while (scanf("%d%d", &N, &T) == 2 && N) {
        for (int i=0;i<=N;i++) sons[i].clear();
        for (int i=1,x=0;i<=N;++i) {
            scanf("%d", &x);
            sons[x].push_back(i);
        }
        printf("%d\n", dp(0));
    }
    return 0;
}
