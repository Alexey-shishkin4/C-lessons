#include <stdio.h>
#include <stdlib.h>


void nullChek(void* ptr){
    if (ptr == NULL){
        printf("Out of memory!");
        exit(0);
    }
}

int* findSubArray(int arr1[], int len, int arr2[], int len2, int* result) {
    int start_subarr;
    size_t c = 0;
    for (size_t i = 0; i < len; i++) {
        if (c == len2){
            *result = start_subarr - len2 + 1;
            return  &(arr1[start_subarr - len2 + 1]);
        }
        if (arr1[i] == arr2[c]){
            start_subarr = i;
            c++;
        }
        else
            c = 0;
    }
    return 0;
}

void RemoveEl(int* arr, int* len, size_t index){
    for (size_t i = 0; i < *len - index - 1; i++){
        arr[index + i] = arr[index + 1 + i];
    }
    *len -= 1;
}

void removeSubArr(int* arr1[], int len, int arr2[], int len2, int* resLen){
    int res;
    findSubArray(arr1, len, arr2, len2, &res);
    do{
        for (size_t i = 0; i < len2; i++){
            RemoveEl(arr1, &len, res);
        }
    } while (findSubArray(arr1, len, arr2, len2, &res) != 0);
    *resLen = len;

}


int main() {
    int arr[9] = { 0, 1, 8, 7, 4, 1, 8, 7, 6};
    int arr2[2] = {8, 7};

    size_t len = 9;
    int* arr1 = (int*) malloc(len * sizeof(int));
    nullChek(arr1);
    for (size_t i = 0; i < len; i++){
        arr1[i] = arr[i];
    }

    int res;
    removeSubArr(arr1, 9, arr2, 2, &res);
    arr1 = realloc(arr1, res * sizeof(int));
    nullChek(arr1);
    for (size_t i = 0; i < res; i++){
        printf("%d ", arr1[i]);
    }
    free(arr1);
    return 0;
}
