#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    int n;
    while(t--) {
        scanf("%d", &n);
        int a;
        int b;
        //int loc[n + 1];
        int part[n + 1];
        for(int i = 0; i < n/2; i++) {
            scanf("%d%d", &a, &b);
            //loc[a] = 1;
            //loc[b] = 0;
            part[a] = b;
            part[b] = a;
        }
        stack<int> q;
        //int flag = 1;
        for(int i = 1; i <= n; i++) {
            if(!q.empty() && part[i] == q.top()) q.pop();
            else q.push(i);
        }  
        if(q.empty()) printf("%s\n", "Yes");
        else printf("%s\n", "No");
    }
}