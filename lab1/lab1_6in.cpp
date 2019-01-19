#include<stdio.h>
#include<time.h>
int main(){

    clock_t begin, end;
    double time_spent ;

    /*int n;
    int a;
    scanf("%d", &a);
    scanf("%d", &n);*/
    //long long int power(int a, int n);
    for(long long int i = 0; i <= 1000000000; i += 10000000) {
        begin = clock();
        int k = 1;
        for(long long int j = 0; j < i; j++) {
            k *= 2;
        }
        //printf("%d to power %d = %lld\n", a, n, k);

        end = clock();
        time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
        printf("%d\t", i);
        printf("%d\t%f\n", i, time_spent);
    }
    //printf("%f\n", time_spent);
    return 0;
}
