#include<stdio.h>
#include<time.h>
#include<math.h>


int main(){

    clock_t begin, end;
    double time_spent ;

    /*int n;
    int a;
    scanf("%d", &a);
    scanf("%d", &n);*/
    long long int power(int a, int n);
    for(int i = 0; i <= 1000000000; i += 10000000) {
        begin = clock();

        long long int k = power(2, i);
        //printf("%d to power %d = %lld\n", a, n, k);

        end = clock();
        time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
        printf("%d\t%f\n", i, time_spent);
    }
    return 0;
}
long long int power(int a, int n) {
    if(n == 0) return 1;
    if(n == 1) return a;
    return power(a, ceil(n/2)) * power(a, floor(n/2));
}