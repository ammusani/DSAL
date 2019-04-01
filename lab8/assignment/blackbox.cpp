//This program solves the black box problem possed in the pdf blackboxGet.pdf

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    scanf("%d\n", &k);
    int m;
    int n;
    while(k--) {
        scanf("%d", &m);
        scanf("%d", &n);
        int a[m];
        int u[n];
        vector<int> A;
        int j = 0;
        for(int i = 0; i < m; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) scanf("%d", &u[i]);
        for(int i = 1; i <= m; i++) {
            A.push_back(a[i - 1]);
            while(j < n && u[j] == i) {
                sort(A.begin(), A.end());
                printf("%d\n", A.at(j)); 
                j++;
            }
        }
        puts("");
    }
    return 0;
}