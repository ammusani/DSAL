#include<stdlib.h>
#include<stdio.h>
#include<time.h>

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r); 
  
/* l is for left index and r is right index of the sub-array 
  of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
   if (l < r) 
   { 
      int m = l+(r-l)/2; //Same as (l+r)/2 but avoids overflow for large l & h 
      mergeSort(arr, l, m); 
      mergeSort(arr, m+1, r); 
      merge(arr, l, m, r); 
   } 
} 
  
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

int main() { 
    
    int arr_size = 100000; 
    int arr[arr_size];

    FILE *random;
    FILE *sorted;
    random = fopen("random.txt", "r");
    sorted = fopen("sorted.txt", "w+");

    for(int i = 0; i < arr_size; i++) {
	fscanf(random, "%d", &arr[i]);
    }

    const clock_t start = clock();
    mergeSort(arr, 0, arr_size - 1);
    const clock_t end = clock(); 
  
    for(int i = 0; i < arr_size; i++) {
	fprintf(sorted, "%d\n", arr[i]);
    }

    printf("%f\n", ((double)(end - start) * 1000) / CLOCKS_PER_SEC);
    return 0; 
}