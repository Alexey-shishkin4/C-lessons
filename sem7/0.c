#include <stdio.h>


void ReverseDioganal(int arr[4][4], size_t len){
    int temp;
    for (size_t i = 0; i < len; i++){
        for (size_t j = i; j < len; j++){
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

int main() {
    int arr[4][4];
    for (size_t i = 0; i < 4; i++){
        for (size_t j = 0; j < 4; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    ReverseDioganal(arr, 4);

    printf("\n");
    for (size_t i = 0; i < 4; i++){
        for (size_t j = 0; j < 4; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
