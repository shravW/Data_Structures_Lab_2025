//Menu-driven program to search for an element in an array
#include <stdio.h>
#include <cstdlib>
#include "qn2_sorting_header.h"

//Searching for an element using Linear Search
void linear(int arr[], int size, int key){
    int check=0;
    for (int i=0; i<size; i++){
        if (arr[i]==key){
            printf("Element found at index %d\n",i);
            check=1;
        }
    }
    if (check==0){
        printf("Element not found\n");
    }
}

//Searching for an element using Binary Search
void binary(int arr[], int size,int key){
    int left=0;
    int right=size-1;
    int check=0;
    while(left<=right){
        int mid=left+((right-left)/2);
        if(arr[mid]==key){
            printf("Element found at index %d\n",mid);
            check=1;
            break;
        }
        else if(arr[mid]>key){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    if (check==0){
        printf("Element not found\n");
    }
}

int main(){
    int a=1;
    int size;
    printf("No of elements in the array : ");
    scanf("%d",&size);
    int arr[size];
    for (int i=0; i<size; i++){
        int inp2;
        printf("Element of index %d : ",i);
        scanf("%d",&inp2);
        arr[i]=inp2;
    }
    printf("\n");
    //Menu of the program
    while(a=1){
        printf("\nMenu-driven program to search for an element in an array\n");
        printf("1- Linear Search\n");
        printf("2- Binary Search\n");
        printf("3- Exit\n");
        int inp;
        printf("Which function do you want to do : ");
        scanf("%d",&inp);
        if (inp==3){
            break;
        }
        if (inp>3 || inp<1){
            printf("Input not valid\n");
            continue;
        }
        printf("\nElement to search for : ");
        int key;
        scanf("%d",&key);
        if (inp==1){
            linear(arr,size,key);
            continue;
        }
        else if (inp==2){
            //Sorting if Binary Search is used
            printf("Sorting initiated");
            bubble(arr,size);
            binary(arr,size,key);
            continue;
        }
    }
    return 0;
}
