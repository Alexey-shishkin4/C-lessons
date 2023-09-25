#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void nullChek(void* ptr){
    if (ptr == NULL){
        printf("Out of memory!");
        exit(0);
    }
}

int* Concat(int arr1[], int len, int arr2[], int len2, int* resultLen){
    int* arr = (int*) malloc((len + len2) * sizeof(int));
    nullChek(arr);

    for (size_t i = 0; i < len; i++){
        arr[i] = arr1[i];
    }
    for (size_t i = 0; i < len2; i++){
        arr[len + i] = arr2[i];
    }
    *resultLen = len + len2;
    return arr;
}


int main() {
    int arr1[5] = {1, 2, 3, 5, 4};
    int arr2[4] = {0, 2, 3, 4};
    int* arr = (int*) malloc((9) * sizeof(int));
    nullChek(arr);

    int newLen;
    arr = Concat(arr1, 5, arr2, 4, &newLen);
    printf("%d \n", newLen);
    for (size_t i = 0; i < newLen; i++)
        printf("%d ", arr[i]);
    
    free(arr);
    return 0;
}
