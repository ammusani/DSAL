#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        int k;
        scanf("%d%d", &n, &k);
        queue<int> q;
        for(int i = 1; i <= n; i++) q.push(i);
        while(q.size() != 1) {
            for(int i = 0; i < k; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        printf("%d\n", q.front());
    }
}