#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        void mergeSort(int*, int);
        mergeSort(a, n);
        for(int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        puts(" ");
    }
    return 0;
}

void mergeSort(int *a, int n) {
    //int i = 1;
    int k;
    int l;
    void merge(int*, int, int, int);
    for(int i = 1; i < n; i *= 2) {
        for(int j = 0; j < n - 1; j += 2*i) {
            if(n > j + 2 * i) l = j + 2 * i - 1;
            else l = n - 1;
            k = i + j - 1;
            merge(a, j, k, l);
        }
    }
}

void merge(int *a, int i, int j, int k) {
    int l1 = j - i + 1;
    int l2 = k - j;
    int a1[l1];
    int a2[l2];
    for(int q = 0; q < l1; q++) {
        a1[q] = a[i + q]; 
    }
    for(int q = 0; q < l2; q++) {
        a2[q] = a[j + 1 + q];
    }
    int q = 0;
    int r = 0;
    int tt;
    for(tt = i; tt <= k && q < l1 && r < l2; tt++) {
        if(a1[q] > a2[r]) {
            a[tt] = a2[r];
            r++;
        }
        else {
            a[tt] = a1[q];
            q++;
        }
    }
    while(q < l1) {
        a[tt] = a1[q];
        q++;
        tt++;
    }
    while(r < l2) {
        a[tt] = a2[r];
        r++;
        tt++;
    }
}
