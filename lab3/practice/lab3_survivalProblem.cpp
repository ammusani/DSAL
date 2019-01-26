#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

class  cirArr {
    queue<int> q1;
    int len;
    public:
        void insert(int);
        void remove();
        int isEmpty();
        void print();
        int atFront();
        void initialize(int);
        void rotate(int);
};

void cirArr :: insert(int i) {
    q1.push(i);
}

void cirArr :: remove() {
    q1.pop();
} 

int cirArr :: isEmpty() {
    return q1.empty();
}

void cirArr :: print() {
    while(len > 1) {
        if(q1.empty()) break;
        q1.push(q1.front());
        q1.pop();
        q1.pop();
        len--;
    }
    printf("%d\n", q1.front());
}

int cirArr :: atFront() {
    return q1.front();
}

void cirArr :: initialize(int n) {
    for(int i = 1; i <= n; i++) q1.push(i);
    len = n;
    /*for(int i = 0; i < len; i++) {
        printf("%d ", q1.front());
        q1.push(q1.front());
        q1.pop();
    }
    puts(" ");*/
}

void cirArr :: rotate(int m) {
    for(int i = 1; i < m; i++) {
        q1.push(q1.front());
        q1.pop();
    }
    /*for(int i = 0; i < len; i++) {
        printf("%d ", q1.front());
        q1.push(q1.front());
        q1.pop();
    }
    puts(" ");*/
}

int main() {
    int k;
    scanf("%d", &k);
    while(k--) {
        int n;
        int m;
        scanf("%d%d", &n, &m);
        cirArr a1;
        a1.initialize(n);
        a1.rotate(m);
        a1.print();
    }
    return 0;
}
