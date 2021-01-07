// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=4501&mosmsg=Submission+received+with+ID+25928455
// https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch9/UVa1626.cpp
// UVa 1626
#include<bits/stdc++.h>
using namespace std;

int f[105][105];
char S[105];
int n;

void readline(char* S) {
    fgets(S,105,stdin);
}

bool match(char a, char b) {
  return (a == '(' && b == ')') || (a == '[' && b == ']');
}

void solve() {
    memset(f,-1,sizeof f);

    for(int i = 0; i < n; i++) {
        f[i+1][i] = 0;
        f[i][i] = 1;
    }
    for (int i=n-2;i>=0;--i) {
        for (int j=i;j<=n-1;++j) {
            if (i==j) {
                f[i][j] = 1;
            } else if (i+1 == j) {
                if (match(S[i],S[j])) f[i][j]=0;
                else f[i][j]=2;
            } else {
                f[i][j]=n;
                if (match(S[i],S[j])) f[i][j] = min(f[i][j],f[i+1][j-1]);
                for (int k=i;k<j;++k) {
                    // i..k, k+1..j
                    f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]);
                }
            }
        }

    }
}

void print(int i, int j) {
    if (i>j) return;
    if (i==j) {
        if (S[i]=='(' || S[i] == ')') printf("()");
        else printf("[]");
        return;
    }

    // i...j
    int ans = f[i][j];
    if (match(S[i],S[j]) && ans == f[i+1][j-1]) {
        printf("%c", S[i]);print(i+1,j-1);printf("%c", S[j]);
        return;
    }
    for (int k=i;k<j;++k) {
        if(ans==f[i][k]+f[k+1][j]) {
            print(i,k);print(k+1,j);
            return;
        }
    }
}

int main() {
    int T;
    readline(S);
    sscanf(S, "%d", &T);
    readline(S);
    while (T--) {
        readline(S);
        n=strlen(S) - 1;
        solve();
        print(0,n-1);
        printf("\n");
        if (T) printf("\n");
        readline(S);
    }
    return 0;
}
