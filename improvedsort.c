#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define RUN 32
#define N 1000

void insert(int*, int, int);
void merge(int*, int, int, int);
void improvedsort(int*, int);

int main()
{
    int arr[N];
    struct timeval start_time;
    struct timeval end_time;
    struct timeval result;

    for(int i = 0 ; i < N ; i++) arr[i] = rand()%1000;
//  for(int i = 0 ; i < N ; i++) printf("%d ",arr[i]);
//  printf("\n\n");

    gettimeofday(&start_time,NULL);
    improvedsort(arr, N);
    gettimeofday(&end_time,NULL);

//  for(int i = 0 ; i < N ; i++) printf("%d ",arr[i]);
//  printf("\n\n");

    result.tv_usec = end_time.tv_usec - start_time.tv_usec;
    printf("Improved Sort : %ld us \n", result.tv_usec);
    return 0;
}

 
void insert(int arr[], int left, int right){
    for (int i = left + 1; i <= right; i++){
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
 
void merge(int arr[], int l, int m, int r){
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < len1 && j < len2){
        if (left[i] <= right[j])arr[k] = left[i++];
        else arr[k] = right[j++];
        k++;
    }
    while (i < len1)arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];
}
 
void improvedsort(int arr[], int n)
{
    for (int i = 0; i < n; i+=RUN) insert(arr, i, ((i+31) > (n-1) ? (n-1) : (i+31)));
    for (int size = RUN; size < n; size = 2*size){
        for (int left = 0; left < n; left += 2*size){
            int mid = left + size - 1;
            int right = ((left + 2*size - 1) > (n-1) ? (n-1) : (left + 2*size - 1));
            merge(arr, left, mid, right);
        }
    }
}
 
