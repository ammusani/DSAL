#include<iostream>
#include<time.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

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
    selectionSort(arr, arr_size);
    const clock_t end = clock(); 
  
    for(int i = 0; i < arr_size; i++) {
	    fprintf(sorted, "%d\n", arr[i]);
    }

    printf("%f\n", ((double)(end - start) * 1000) / CLOCKS_PER_SEC);
    return 0;  
}