#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    int n;
    int m;
    int q;
    int a;
    int b;
    int i;
    int path1;
    int path2;
    int isPath(int, int, vector<vector<int>>, int);
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &q);
        vector<vector<int>> v;
        vector<int> aa;
        for(i = 0; i < n; i++) v.push_back(aa);
        for(i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
        }
        for(i = 0; i < q; i++) {
            scanf("%d%d", &a, &b);
            path1 = isPath(a, b, v, n);
            path2 = isPath(b, a, v, n);
            path1 = path1 && path2;
            printf("%d\n", path1);
        }
    }
    return 0;
}

int isPath(int a, int b, vector<vector<int>> t, int n) {
    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;
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