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


int main() {
    int arr1[] = {0, 1, 8, 7, 4, 1, 8, 7, 6};
    int arr2[] = {8, 7};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    int* result = findSubArr(arr1, len1, arr2, len2);
    if (result != 0) {
        printf("index: %d\n", result - arr1);
    } else {
        printf("Not found\n");
    }

    return 0;
}
