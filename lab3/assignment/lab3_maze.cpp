#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
class point {
    int x;
    int y;
    public:
        void initialize(int, int);
        int X();
        int Y();
};

void point :: initialize(int i, int j) {
    x = i;
    y = j;
}

int point :: X() {
    return x;
}

int point :: Y() {
    return y;
}

int main() {
    point start;
    point dest;
    point mat;
    int t;
    int m;
    int n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &m, &n);
        mat.initialize(m, n);
        int arr[m][n];
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
        scanf("%d%d", &m, &n);
        start.initialize(m, n);
        scanf("%d%d", &m, &n);
        dest.initialize(m, n);
        queue<point> q;
        q.push(start);
        point next;
        int flag = 0;
        while(!q.empty()) {
            m = q.front().X();
            n = q.front().Y();
            q.pop();
            if(m == dest.X() && n == dest.Y()) { 
                flag = 1;
                break;
            }
            if((m < mat.X() - 1) && (n < mat.Y()) && (arr[m + 1][n] == 1)) {
                next.initialize(m + 1, n);
                q.push(next);
            }
            if((m < mat.X()) && (n < mat.Y() - 1) && (arr[m][n + 1] == 1)) {
                next.initialize(m, n + 1);
                q.push(next);
            }
        }
        if(flag) printf("%s\n", "yes");
        else printf("%s\n", "no");
    }
}