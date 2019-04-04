#include<iostream>
#include<time.h>
#include<bits/stdc++.h>

using namespace std;

int main() { 
    int arr_size = 1000000; 
    int arr[arr_size];

    FILE *random;
    FILE *sorted;
    random = fopen("random.txt", "r");
    sorted = fopen("sorted.txt", "w+");

    for(int i = 0; i < arr_size; i++) {
	fscanf(random, "%d", &arr[i]);
    }

    const clock_t start = clock();
    sort(arr, arr + arr_size);
    const clock_t end = clock(); 
  
    for(int i = 0; i < arr_size; i++) {
	    fprintf(sorted, "%d\n", arr[i]);
    }

    printf("%f\n", ((double)(end - start) * 1000) / CLOCKS_PER_SEC);
    return 0;  
}