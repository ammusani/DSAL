#include<iostream>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int k = 1;
    while(k) {
        scanf("%d", &k);
        if(k == 0) break;
        int a[k];
        a[0] = 1;
        while(a[0]) {
            for(int i = 0; i < k; i++) {
                scanf("%d", &a[i]);
                if(i == 0 && a[i] == 0) break;
            }
            if(a[0] == 0) break;
            int j = 1;
            stack<int> s1;
            for(int i = 0; i < k; i++) {
                if(!s1.empty() && a[i] == s1.top()) s1.pop();
                else if(s1.empty() || j <= a[i]) {
                    for(; j < a[i]; j++) s1.push(j);
                    j++;
                }
                else {
                    j = 0;
                    break;
                }
            }
            if(j) printf("%s\n", "Yes");
            else printf("%s\n", "No");
        }
        puts("");
    }
}