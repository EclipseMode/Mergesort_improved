#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void merge(int*, int, int ,int);
void mergesort(int*, int, int);

#define N 1000

int main()
{
    int arr[N];
    struct timeval start_time;
    struct timeval end_time;
    struct timeval result;

    for(int i = 0 ; i < N ; i++) arr[i] = rand() % 1000;
//  for(int i = 0 ; i < N ; i++) printf("%d ", arr[i]);
//  printf("\n\n");

    gettimeofday(&start_time, NULL);
    mergesort(arr, 0, N - 1);
    gettimeofday(&end_time,NULL);

//  for(int i = 0 ; i < N ; i++) printf("%d ", arr[i]);
//  printf("\n\n");
    
    result.tv_usec = end_time.tv_usec - start_time.tv_usec;
    printf("Merge Sort : %ld us \n", result.tv_usec);
 
    return 0;
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)L[i] = arr[l + i];
    for (j = 0; j < n2; j++)R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) arr[k] = L[i++];
        else arr[k] = R[j++];
        k++;
    }
    while (i < n1)arr[k++] = L[i++];
    while (j < n2)arr[k++] = R[j++];
}
 
void mergesort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;

        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

