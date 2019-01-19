#include<stdio.h>
#include<math.h>
#include<time.h>
int main() {
    clock_t begin;
    clock_t end;
    double timeSpent;
    
    /*int n;
    scanf("%d", &n);*/
    int isPrime(int n);
   for(int i = 0; i <= 100000; i++) { 
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

int isPrime(int n) {
    int flag = 1;
    if(n == 2) return 1;
    if(n % 2 == 0) flag = 0;
    else {
        for(int i = 3; i <= sqrt(n) + 1; i += 2) {
            if(n % i == 0) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}