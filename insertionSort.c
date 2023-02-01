#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insertion_sort(int arr[], int n) {
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

void main(){
    int arr[6] = {20,10,90,80,40,30};
    for (int i = 0; i < 6; i++)
    {
        printf("%d--",arr[i]);
    }
    printf("\n");
    insertion_sort(arr,6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d--",arr[i]);
    }
    printf("\n");
}