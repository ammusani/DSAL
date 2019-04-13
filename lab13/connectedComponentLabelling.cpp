#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class setDisjoint {
    int *parent;
    int *p_size;

    public:
    setDisjoint(int mn) {
        parent = (int *)malloc((mn + 1) * sizeof(int));
        p_size = (int *)malloc((mn + 1) * sizeof(int));
        for(int i = 1; i <= mn; i++) {
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

    int Parent(int x) {
        //printf("%d %d\n", x, parent[x]);
        return parent[x];
    }
};

int main() {
    int t;
    int m;
    int n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &m, &n);
        int arr[m * n + 1];
        setDisjoint SDJ(m * n);
        for(int i = 1; i <= m * n; i++) {
            scanf("%d", &arr[i]);
        }
        for(int i = 1; i <= m * n; i++) {
            if(arr[i]) {
                if(i > n) {
                        if(arr[i - n]) SDJ.Union(i, i - n);
                }
                if(i % n != 1) {
                    if(arr[i - 1]) SDJ.Union(i, i - 1);
                }
            }
        }
        set<int> s;
        for(int i = 1; i <= m * n; i++) {
            if(arr[i]) {
                SDJ.find(i);
                s.insert(SDJ.Parent(i));
            }
        }
        //for(auto i = s.begin(); i != s.end(); i++) printf("%d ", (*i));
        //puts(" ");
        int k = s.size();
        printf("%d\n", k);
    }
    return 0;
}