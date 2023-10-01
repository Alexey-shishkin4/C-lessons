#include <stdio.h>
#include <stdlib.h>


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


int main() {
    int arr1[9] = { 0, 1, 8, 7, 4, 1, 8, 7, 6};
    int arr2[4] = {8, 7, 4, 1};

    int res;
    int* a = findSubArray(arr1, 9, arr2, 4, &res);
    printf("%d \n", a);
    printf("%d", res);
    return 0;
}
