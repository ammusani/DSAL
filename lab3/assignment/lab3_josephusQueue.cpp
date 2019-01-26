#include<iostream>
#include<bits/stdc++.h>
//#include<queue>
using namespace std;
class Queue {
    int arr[10000];
    int fptr = 0;
    int bptr = 0;
    int size = 0;
    public:
        void insert(int);
        void remove();
        int isEmpty();
        //void print();
        int atFront();
       // void initialize();
};

void Queue :: insert(int i) {
    arr[bptr%1000] = i;
    size++;
    bptr++;
}

void Queue :: remove() {
    fptr++;
    size--;
}

int Queue :: isEmpty() {
    return size;
}

int Queue :: atFront() {
    return arr[fptr%1000];
    printf("%d\n", fptr);
}



int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        int k;
        scanf("%d%d", &n, &k);
        Queue q;
        for(int i = 1; i <= n; i++) q.insert(i);
        while(q.isEmpty() != 1) {
            for(int i = 0; i < k; i++) {
                q.insert(q.atFront());
                q.remove();
            }
            q.remove();
        }
        printf("%d\n", q.atFront());
    }
}