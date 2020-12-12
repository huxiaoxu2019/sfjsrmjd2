// UVa 11400
// https://github.com/aoapc-book/aoapc-bac2nd/blob/master/ch9/uva11400.cpp
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
struct Lamp {
    int v,k,c,l;
    bool operator < (const Lamp& a) const{
        return v<a.v;
    }
}lamp[maxn];
int n,s[maxn],d[maxn];
int main() {
    while(cin>>n && n) {
        for (int i=1;i<=n;++i) {
            cin>>lamp[i].v>>lamp[i].k>>lamp[i].c>>lamp[i].l;
        }
        sort(lamp+1,lamp+n+1);
        s[0]=0;
        for(int i=1;i<=n;++i) s[i]=s[i-1]+lamp[i].l;
        d[0]=0;
        for(int i=1;i<=n;++i) {
            d[i]=lamp[i].k+lamp[i].c*s[i];
            for(int j=1;j<=i;++j) {
                d[i]=min(d[i], d[j] + (s[i]-s[j]) * lamp[i].c + lamp[i].k);
            }
        }
        cout<<d[n]<<endl;
    }
    return 0;
}
