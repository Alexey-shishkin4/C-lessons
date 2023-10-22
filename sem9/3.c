#include <stdio.h>

int* findSubArr(int* arr1, int len1, int* arr2, int len2) {
    for (int i = 0; i <= len1 - len2; i++) {
        int found = 1;
        for (int j = 0; j < len2; j++) {
            if (arr1[i + j] != arr2[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            return &arr1[i];
        }
    }
    return 0;
}


void removeSubArr(int* arr1, int* len1, int* arr2, int len2) {
    int* found;
    while ((found = findSubArr(arr1, *len1, arr2, len2)) != NULL) {
        for (int *p = found; p < arr1 + *len1 - len2; p++) {
            *p = *(p + len2);
        }
        *len1 -= len2;
    }
}


int main() {
    int arr1[] = {0, 1, 2, 3, 1, 2, 4};
    int arr2[] = {1, 2};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    removeSubArr(arr1, &len1, arr2, len2);

    printf("arr1: ");
    for (int i = 0; i < len1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}