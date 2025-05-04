//Menu-driven program to check if a number is Palindrome, Armstrong or Perfect.
#include <cstdio>
#include <cstdlib>
#include <cmath>

//Checking if given number is palindrome or not
void is_palindrome(int *number){
    //Usage of Dynamic memory allocation(DMA)
    int *original = (int *)malloc(sizeof(int));
    *original = *number;
    int *reversed = (int *)malloc(sizeof(int));
    *reversed = 0;
    int *temp = (int *)malloc(sizeof(int));
    *temp = *number;
    while(*temp > 0){
        *reversed = (*reversed * 10) + (*temp % 10);
        *temp /= 10;
    }
    if(*original == *reversed){
        printf("%d is a palindrome\n", *number);
    }
    else{
        printf("%d is not a palindrome\n", *number);
    }
    free(original);
    free(reversed);
    free(temp);
    }

//Checking if given number is armstrong or not
void is_armstrong(int *number){
    int *original = (int *)malloc(sizeof(int));
    *original = *number;
    int *temp = (int *)malloc(sizeof(int));
    *temp = *number;
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    int *digits = (int *)malloc(sizeof(int));
    *digits = 0;
    while(*temp > 0){
        *temp /= 10;
        (*digits)++;
    }
    *temp = *number;
    while(*temp > 0){
        *sum += pow(((*temp) % 10), *digits);
        *temp /= 10;
    }
    if(*sum == *original){
        printf("%d is an armstrong number\n", *number);
    }
    else{
        printf("%d is not an armstrong number\n", *number);
    }
    free(original);
    free(temp);
    free(sum);
    free(digits);
}

//Checking if given number is perfect or not
void is_perfectNumber(int *number){
    int *temp = (int *)malloc(sizeof(int));
    *temp = *number;
    int *original = (int *)malloc(sizeof(int));
    *original = *number;
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    int *count = (int *)malloc(sizeof(int));
    *count = 1;
    while(*count > 0){
        if(*temp % *count == 0 && *count != 1){
            *sum += *temp / *count;
        }
        if(*count == 1){
            *sum += 1;
        }
        if(*sum == *temp){
            break;
        }
        (*count)++;
    }
    if(*sum == *original){
        printf("%d is a perfect number\n", *number);
    }
    else {
        printf("%d is not a perfect number\n", *number);
    }
    free(temp);
    free(original);
    free(sum);
    free(count);
}

int main(){
    int *choice = (int *)malloc(sizeof(int));
    int *number = (int *)malloc(sizeof(int));
    if(number == NULL || choice == NULL){
        printf("Dynamic memory allocation failed");
        return 1;
    }
    //Menu of the program
    do{printf("\nMenu:\n");
    printf("1. Palindrome\n");
    printf("2. Armstrong Number\n");
    printf("3. Perfect Number\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
    printf("Enter the number: ");
    scanf("%d", number);
    switch(*choice){
        case 1:
            is_palindrome(number);
            break;
        case 2:
            is_armstrong(number);
            break;
        case 3:
            is_perfectNumber(number);
            break;
        case 4:
            printf("Exiting the menu\n");
            break;
        default:
            printf("The choice entered is incorrect\n");
    }
    }while(*choice!=4);
    free(choice);
    free(number);
    return 0;
}

