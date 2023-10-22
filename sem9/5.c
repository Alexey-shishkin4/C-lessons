#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void printArr(int arr[], size_t len){
    for (size_t i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void nullChek(void* ptr){
    if (ptr == NULL){
        printf("Out of memory!");
        exit(0);
    }
}


void scanArr(int *arr[], size_t* len, size_t* capacity) {
    *arr = malloc(1 * sizeof(int));
    *len = 0;
    *capacity = 1;
    nullChek(*arr);

    int input = -1;
    while (input != 0){
        scanf("%d", &input);
        if (input == 0)
            break;

        if (len == capacity){
            *capacity *= 2;
            *arr = realloc(*arr, *capacity * sizeof(int));
            nullChek(*arr);
        }
        (*arr)[*len] = input;
        (*len)++;
    }
}

int main() {
    int *arr;
    size_t size;
    size_t capacity;
    scanArr(&arr, &size, &capacity);
    printArr(arr, size);
}