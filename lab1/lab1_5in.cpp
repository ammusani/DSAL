#include<stdio.h>
#include<time.h>
int main() {
    clock_t begin;
    clock_t end;
    double timeSpent;
    /*int n;
    scanf("%d", &n);*/
    for(int i = 0; i <= 45; i++) {
        begin = clock();
        long long int fib(int n);
        long long int k;
        k = fib(i);
    //printf("Fib number = %lld\n", k);
        end = clock();
        timeSpent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
        printf("%d\t%f\n", i, timeSpent);
    //printf("%f", timeSpent);
    //printf("%lld", k);
    }
    return 0;
}
long long int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}