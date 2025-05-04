//Header file
#include <stdio.h>
#include <cstdlib>

//To print an array of length n
void printarray(int arr[], int size){
    printf("\nThe sorted array is\n[ ");
    for (int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

//Sorting an array using BubbleSort method
void bubble(int arr[],int size){
    for (int i=0; i<size; i++){
        for (int j=size-i-1; j<size-1; j++){
            if (arr[j]>arr[j+1]){
            int tmp;
            tmp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=tmp;
            }
        }
    }
    printarray(arr,size);
}

//Sorting an array using InsertSort method
void insert(int arr[],int size){
    for (int i=1; i<size; i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    printarray(arr,size);
}

//Sorting an array using SelectionSort method
void select(int arr[],int size){
    for (int i=0; i<size; i++){
        int min;
        int j;
        min=i;
        for (j=i+1; j<size; j++){
            if (arr[min]>arr[j]){
            min=j;
            }
        }
        int tmp=arr[i];
        arr[i]=arr[min];
        arr[min]=tmp;
    }
    printarray(arr,size);
}