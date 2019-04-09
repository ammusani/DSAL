#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class setDisjoint {

    int *parent;
    int *p_size;
    
    public:
    setDisjoint(int n) {
        parent = (int *)malloc((n + 1) * sizeof(int));
        p_size = (int *)malloc((n + 1) * sizeof(int));
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            p_size[i] = 1;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;
        int px = find(parent[x]);
        parent[x] = px;
        return px;
    }

    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        if(p_size[x] == p_size[y]) {
            if(x > y) {
                parent[y] = x;
                p_size[x]++;
            }
            else {
                parent[x] = y;
                p_size[y]++;
            }
        }
        else if(p_size[x] > p_size[y]) {
            parent[y] = x;
        } 
        else {
            parent[x] = y;
        }
    }
};


int main() {
    int t;
    int n;
    int q;
    int k;
    int a;
    int b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        setDisjoint s(n);
        while(q--) {
            scanf("%d", &k);
            switch(k) {
                case 1: {
                    scanf("%d%d", &a, &b);
                    s.Union(a, b);
                    break;
                }
                case 2: {
                    scanf("%d", &a);
                    b = s.find(a);
                    printf("%d\n", b);
                    break;
                }
            }
        }
    }
    return 0;
}