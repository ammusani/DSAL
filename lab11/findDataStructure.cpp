#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int k;
    int x;
    while(n) {
        int flag1 = 1;
        int flag2 = 1;
        int flag3 = 1;
        stack<int> s;
        queue<int> q;
        priority_queue<int> p;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &k, &x);
            switch(k) {
                case 1: {
                    if(flag1) s.push(x);
                    if(flag2) q.push(x);
                    if(flag3) p.push(x);
                    break;
                }
                case 2: {
                    if(flag1) {
                        if(s.top() != x) flag1 = 0;
                        s.pop();
                    }
                    if(flag2) {
                        if(q.front() != x) flag2 = 0;
                        q.pop();
                    }
                    if(flag3) {
                        if(p.top() != x) flag3 = 0;
                        p.pop();
                    }
                    break;
                }
            }
        }
        int sum = flag1 + flag2 + flag3;
        if(sum == 1) {
            if(flag1) printf("%s", "stack\n");
            else if(flag2) printf("%s", "queue\n");
            else if(flag3) printf("%s", "priority queue\n");
        }
        else if(sum == 0) {
            printf("%s", "impossible\n");
        }
        else {
            printf("%s", "not sure\n");
        }
        scanf("%d", &n);
    }
}