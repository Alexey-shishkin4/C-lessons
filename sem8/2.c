#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void scanArr(int arr[], size_t len){
    for (size_t i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], size_t len){
    for (size_t i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void revertArr(int arr[], size_t len){
    for (size_t i = 0; i < len / 2; i++){
        int temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}

int maxInArr(int arr[], size_t len){
    int max = arr[0];
    for (size_t i = 1; i < len; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int findInArr(int arr[], size_t len, int x){
    for (int i = 0; i < len; i++){
        if (arr[i] == x)
            return i;
    }
    return -1;
}


void extractDigits(int arr[], size_t size, int n) {
    assert(size >= 10);
    size_t i = 0;
    while (n != 0){
        arr[i] = n % 10;
        n /= 10;
        i++;
    }
    revertArr(arr, i);
}


int compareArrays(int arr1[], size_t len1, int arr2[], size_t len2) {
    for (size_t i = 0; i < len1 && i < len2; i++) {
        if (arr1[i] == arr2[i])
            continue;
        if (arr1[i] < arr2[i])
            return -1;
        if (arr1[i] > arr2[i])
            return 1;
    }
    if (len1 == len2)
        return 0;
    else if (len1 < len2)
        return -1;
    return 1;
}


void nullChek(void* ptr){
    if (ptr == NULL){
        printf("Out of memory!");
        exit(0);
    }
}


int* myRealloc(int* arr, size_t len, size_t newlen){
    assert(len <= newlen);

    int *new_arr = malloc(newlen * sizeof(int));
    nullChek(new_arr);

    for(size_t i = 0; i < len; i++)
        new_arr[i] = arr[i];
    free(arr);

    return new_arr;
}


int main() {
    int* arr = (int*) malloc(1 * sizeof(int));
    nullChek(arr);
    int input, len = -1;
    int length = 1;
    do {
        len++;
        scanf("%d", &input);
        arr[len] = input;
        arr = myRealloc(arr, length, length * 2);
        length *= 2;
    } while (input != 0);

    int* arr1 = (int*) malloc(len * sizeof(int));
    nullChek(arr1);
    for (size_t j = 0; j < len; j++){
        arr1[j] = arr[j];
    }
    free(arr);

    // тестирование функций
    printArr(arr1, len);

    revertArr(arr1, len);
    printArr(arr1, len);

    printf("%d \n", maxInArr(arr1, len));

    printf("%d \n", findInArr(arr1, len, 9));

    extractDigits(arr1, len, 123);
    printArr(arr1, len);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d", compareArrays(arr1, len, arr2, 10));

    free(arr1);

    return 0;
}