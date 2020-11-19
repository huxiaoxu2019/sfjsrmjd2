// 2020/11/19
// 树的层次遍历
// UVa 122
#include<cstdio>
#include<queue>

using namespace std;

const int root = 1;
const int N = 300;
int left[N], right[N], value[N];
bool have_value[N];
int idx;
char s[N];
void newtree() {left[root] = right[root] = 0; have_value[root] = false; idx = root;}
int newnode() {int u = ++idx; left[u] = right[u] = 0; have_value[u] = false; return u;}
void bfs() {
    queue<int> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty()) {
        auto cidx = q.front(); q.pop();
        if (have_value[cidx] == false) break;
        ans.push_back(value[cidx]);
        if (left[cidx] != 0) q.push(left[cidx]);
        if (right[cidx] != 0) q.push(right[cidx]);
    }
    if (ans.empty()) {
        printf("-1\n");
    } else {
        for (auto &x : ans) printf("%d ", x);
    }
}
bool addnode(int v, char* s) {
    int l = strlen(s);
    int cidx = root;
    for (int i = 0; i < l; ++i) {
        if (s[i] == 'L') {
            if (left[cidx] == 0) left[cidx] = newnode();
            cidx = left[cidx];
        } else if (s[i] == 'R') {
            if (right[cidx] == 0) right[cidx] = newnode();
            cidx = right[cidx];
        }
    }
    if (have_value[cidx] == true) return false;
    have_value[cidx] = true;
    value[cidx] = v;
    return true;
}

bool read_line() {
    newtree();
    //memset(left, 0, sizeof left); memset(right, 0, sizeof right);
    memset(have_value, false, sizeof have_value);
    while (true) {
        if (scanf("%s", s) != 1) return false;
        //printf("%s\n", s);
        if (strcmp(s, "()") == 0) break;
        // (7,LLL)
        int v;
        sscanf(&s[1], "%d", &v);
        // LLL)
        addnode(v, strchr(s, ',') + 1);
    }
    return true;
}
int main() {
    while(read_line()) {
        bfs();
    }
    return 0;
}
