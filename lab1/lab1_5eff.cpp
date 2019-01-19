#include<stdio.h>
#include<time.h>
#include<iostream>
using namespace std;
int main() {
    clock_t begin;
    clock_t end;
    double timeSpent;
    /*int n;
    scanf("%d", &n);*/
    for(int i = 0; i <= 1000000000; i += 10000000) {
        begin = clock();
        long long int fib(int n);
        long long int k = fib(i);
        //printf("Fib number = %lld\n", k);
        end = clock();
        timeSpent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
        cout << i << "\t" << timeSpent << "\n";
    }
    //printf("%f", timeSpent);
    //printf("%lld", k);
    return 0;
}

long long int fib(int n) {
    long long int k = 0;
    long long int k0 = 0;
    long long int k1 = 1;
    if(n == 0) return 0;
    else if(n == 1) return 1;
    for(int i = 2; i <= n; i++) {
        k = k1 + k0;
        k0 = k1;
        k1 = k;
    }
    return k;
}