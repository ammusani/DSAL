#include<iostream>
#include<time.h>

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

int main() 
{ 
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
    insertionSort(arr, arr_size);
    const clock_t end = clock(); 
  
    for(int i = 0; i < arr_size; i++) {
	    fprintf(sorted, "%d\n", arr[i]);
    }

    printf("%f\n", ((double)(end - start) * 1000) / CLOCKS_PER_SEC);
    return 0;  
}