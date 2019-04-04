#include<stdlib.h>
#include<stdio.h>
#include<time.h>


void merge(int *a, int *tmp_array, int l_pos, int r_pos, int right_end ) {

    int i, left_end, num_elements, tmp_pos;
    left_end = r_pos - 1;
    tmp_pos = l_pos;
    num_elements = right_end - l_pos + 1;

    /* main loop */

    while( ( l_pos <= left_end ) && ( r_pos <= right_end ) )

        if( a[l_pos] <= a[r_pos] )
            tmp_array[tmp_pos++] = a[l_pos++];
        else
            tmp_array[tmp_pos++] = a[r_pos++];

    while( l_pos <= left_end )  /* copy rest of first half */
        tmp_array[tmp_pos++] = a[l_pos++];

    while( r_pos <= right_end ) /* copy rest of second half */
        tmp_array[tmp_pos++] = a[r_pos++];

    /* copy tmp_array back */
    for(i=1; i <= num_elements; i++, right_end-- )
        a[right_end] = tmp_array[right_end];

}

void m_sort( int *a, int *tmp_array, int left, int right ) {

    int center;
    if( left < right ) {
        if(right - left > 8) {
            center = (left + right) / 2;
            m_sort( a, tmp_array, left, center);
            m_sort( a, tmp_array, center+1, right);
            if(a[center] > a[center + 1]) merge( a, tmp_array, left, center+1, right);
        }
        else {
            int i;
            int j;
            int temp;
            for(i = left; i < right; i++) {
                for(j = i + 1; j <= right; j++) {
                    if(a[i] > a[j]) {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                }
            }
        }
    }
}


void mergeSort(int a[], unsigned int n) {

    int *tmp_array;
    tmp_array = (int *) malloc( (n+1) * sizeof (int) );
    m_sort(a, tmp_array, 0, n);
    free( tmp_array );
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
    mergeSort(arr, arr_size - 1);
    const clock_t end = clock(); 
  
    for(int i = 0; i < arr_size; i++) {
	    fprintf(sorted, "%d\n", arr[i]);
    }

    printf("%f\n", ((double)(end - start) * 1000) / CLOCKS_PER_SEC);
    return 0; 
}