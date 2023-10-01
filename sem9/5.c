#include <stdio.h>
#include <stdlib.h>


void nullChek(void* ptr){
    if (ptr == NULL){
        printf("Out of memory!");
        exit(0);
    }
}


void printArr(int arr[], size_t len){
    for (size_t i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int* scanArr(int* array, size_t* len) {
    int* arr = NULL;
    size_t size = 0;

    int a;
    int i = 0;
    do {
        size = size > 0 ? size * 2 : 1;
        arr = (int*) realloc(arr, (size) * sizeof(int));
        nullChek(arr);
        scanf("%d", &arr[i]);
        i++;
    } while (arr[i - 1] != 0);

    *len = i;
    return arr;
}


int main(){
    int len;
    int* arr = (int*) malloc(0 * sizeof(int));
    arr = scanArr(arr, &len);
    printArr(arr, len);
    return 0;
}