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
    int isPrime(long long int n);
    for(int i = 0;  i <= 100000; i++) {
        begin = clock();    
        int sol = isPrime(i);
        /*if(sol) printf("Is Prime\n");
        else printf("Not Prime\n");*/
        end = clock();
        timeSpent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
        printf("%d\t%f\n", i, timeSpent);
    } 
    //printf("%lld", k);
    return 0;
}

int isPrime(long long int n) {
    int flag = 1;
    if(n == 2) return 1;
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}