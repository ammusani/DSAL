//This program solves the malWart problem on hackerrank. Description in MalWart.pdf

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n) {
        int total = 0;
        int k;
        int t;
        multiset <int> :: iterator ptr;
        multiset <int> s;
        for(int i = 0; i < n; i++) {
            scanf("%d", &k);
            for(int i = 0; i < k; i++) {
                scanf("%d", &t);
                s.insert(t);
            }
            ptr = s.begin();
            int min = *ptr;
            s.erase(ptr);
            ptr = s.end();
            ptr--;
            int max = *ptr;
            s.erase(ptr);
            total += (max - min);
        }
        printf("%d\n", total);
        scanf("%d", &n);
    }
    return 0;
}
