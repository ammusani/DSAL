#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main() {
    int t;
    int n;
    int m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        queue<int> q;
        int k;
        int size = 0;
        int b[15] = {0};
        int a;
        size = n;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a);
            b[a]++;
            q.push(a);
            if(i == m) k = a;
        }
        //printf("scan hogaya\n");
        //printf("%d\n", k);
        a = 0;
        for(int i = 14; i > k; i--) {
            while(b[i] > 0) {
                if(m == 0) {
                    m = size - 1;
                    //printf("m = %d\n", m);
                    q.push(q.front());
                    q.pop();
                }
                else {
                    m--;
                    //printf("m = %d\n", m);
                    if(q.front() == i) {
                        q.pop();
                        a++;
                        b[i]--;
                        size--;
                    }
                    else {
                        q.push(q.front());
                        q.pop();
                    }
                }
            }
            //printf("i=%d\n", i);
        }
        //printf("yaha se nikal gaya\n");
       // printf("m = %d\n", m);
        for(; m >= 0;) {
            if(m != 0) {
                m--;
         //       printf("m2 = %d\n");
                if(q.front() == k) {
                    a++;
                   // printf("%d\n", 1);
                    //m--;
                    q.pop();
                }
                else {
                    //printf("%d\n", 2);
                    //m--;
                    q.pop();
                }
            }
            else {
                a++;
                break;
            }
        }
        printf("%d\n", a);
    }
    return 0;
}