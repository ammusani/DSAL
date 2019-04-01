#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int k;
    scanf("%d", &n);
    scanf("%d", &k);
    //printf("%d %d\n", n, k);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        //printf("%d %d\n", i, arr[i]);
    }
    int arr2[n - 1];    
    for(int i = 1; i < n; i++) {
        arr2[i - 1] = arr[i - 1] + arr[i];
        //printf("%d %d %d %d\n", i, arr2[i - 1], arr[i - 1], arr[i]);
    }
    sort(arr2, arr2 + (n - 1));
    //for(int i = 0; i < n - 1; i++) printf("%d ", arr2[i]);
    int min = arr[0] + arr[n - 1];
    int max = arr[0] + arr[n - 1];
    if(k > n) {
        min = -1;
        max = -1;
    }
    else {
        for(int i = 0; i < k - 1; i++) {
            min += arr2[i];
            max += arr2[n - 2 - i];
            //printf("%d ", arr2[n - 2 - i]);
        }
    }
    printf("%d\n%d\n", min, max);
}