#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

class  numb {
    queue<string> q1;
    public:
        void insert(string);
        void remove();
        int isEmpty();
        void print();
        string atFront();
        void initialize();

};

void numb :: insert(string i) {
    q1.push(i);
}

void numb :: remove() {
    q1.pop();
} 

int numb :: isEmpty() {
    return q1.empty();
}

void numb :: print() {
    string p = q1.front();
    q1.pop();
    cout << p << endl;
    q1.push(p + "0");
    q1.push(p + "1");
}

string numb :: atFront() {
    return q1.front();
}

void numb :: initialize() {
    q1.push("0");
    q1.push("1");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        numb series;
        series.initialize();
        while(n--) {
            series.print();
        }
        puts(" ");
    }
    return 0;
}
