#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class bag {
    int arr[1000] = {0};
    int min;
    int len;
public:
    void initialize();
    void add(int);
    void rem(int);
    void printMin();
    int check(int);
};

void bag :: initialize() {
    len = 0;
    min = 0;
}

void bag :: add(int n) {
    if(len == 0) min = n;
    else if(min > n) min = n;
    arr[len] = n;
    len++;
}

void bag :: rem(int n) {
    int k = check(n);
    int j = arr[k];
    if(k != -1 && len) {
        for(int i = k; i < len - 1; i++) arr[i] = arr[i + 1];
        len--;
    }
    if(min == j) {
        min = arr[0];
        for(int i = 1; i < len; i++) if(min > arr[i]) min = arr[i];
    }
}

void bag :: printMin() {
    printf("%d\n", min);
}

int bag :: check(int n) {
    for(int i = 0; i < len; i++) {
        if(arr[i] == n) return i;
    }
    return -1;
}
int main() {
    bag p;
    p.initialize();
    int k = 1;
    while(k) {
        scanf("%d", &k);
        if(k == 0) break;
        switch(k) {
            case 1: {
                int n;
                scanf("%d", &n);
                p.add(n);
                break;
            }
            case 2: {
                int n;
                scanf("%d", &n);
                p.rem(n);
                break;
            }
            case 3: {
                p.printMin();
                break;
            }
            default: continue;
        }
    }
    return 0;
}
