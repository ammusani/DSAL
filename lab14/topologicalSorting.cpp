#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int isPath(int a, int b, vector<set<int>> t, int n);
    void topo(int i, int n, int visited[], vector<set<int>> vs, stack<int> &S);
    int t;
    int n;
    int m;
    int u;
    int v;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        if(m == 0) {
            for(int i = n; i >= 1; i--) printf("%d ", i);
            puts("");
            continue;
        }
        vector<set<int>> vs;
        set<int> a;
        int is[n + 1];
        int flag = 0;
        for(int i = 0; i <= n; i++) {
            vs.push_back(a);
            is[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            if(u == v) {
                flag = 1;
                break;
            }
            vs[u].insert(v);
            is[v]++;
        }
        if(flag) {
            printf("%d\n", 0);
            continue;
        }
        int flag1 = 0;
        int flag2 = 0;
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                flag1 = isPath(i, j, vs, n);
                flag2 = isPath(j, i, vs, n);
                flag = flag1 && flag2;
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) {
            printf("%d\n", 0);
            continue;
        }
        else {
            int visited[n + 1];
            stack<int> S;
            for(int i = 0; i <= n; i++) {
                visited[i] = 0;
                //if(!vs[i].empty()) sort(vs[i].begin(), vs[i].end());
            }
            for(int i = 1; i <= n; i++) {
                if(!is[i]) {
                    topo( i, n, visited, vs, S);
                }
            }
            while(!S.empty()) {
                printf("%d ", S.top());
                S.pop();   
            }
        }
        puts("");
    }
}

int isPath(int a, int b, vector<set<int>> t, int n) {
    int visited[n + 1];
    for(int i = 1; i <= n; i++) visited[i] = 0;
    queue<int> q;
    q.push(a);
    visited[a] = 1;
    int curr;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        for(auto i = t[curr].begin(); i != t[curr].end(); i++) {
            if(visited[*i] == 0) {
                visited[*i] = 1;
                q.push(*i);
            }
            if(*i == b) return 1;
        }
    }
    return 0;
}

void topo(int i, int n, int visited[], vector<set<int>> vs, stack<int> &S) {
    visited[i] = 1;
    for(auto j = vs[i].begin(); j != vs[i].end(); j++){
        if(!visited[*j]) topo(*j, n, visited, vs, S);
    }
    S.push(i);
}