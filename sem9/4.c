#include <stdio.h>
#include <stdlib.h>


void nullChek(void* ptr){
    if (ptr == NULL){
        printf("Out of memory!");
        exit(0);
    }
}

int bcl(int n ,int k){
    if (k > n / 2)
        k = n - k;
    if (k == 1)
        return n;
    if (k == 0)
        return 1;
    int r = 1;
    for (int i = 1; i <= k; i++) {
        r *= n - k + i;
        r /= i;
    }
    return r;
}


void PrintPascal(int** arr, int n){
    size_t leng = 1;
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < leng; j++){
            printf("%d ", arr[i][j]);
        }
        leng += 1;
        printf("\n");
    }
}


int** CreateMassive(int n){
    int** arr = (int**) malloc(n * sizeof(int*));
    nullChek(arr);
    int m = 1;
    for (size_t i = 0; i < n; i++){
        arr[i] = (int*) malloc(m * sizeof(int));
        nullChek(arr[i]);
        m++;
    }
    return arr;
}



void coeff(int** arr, int n){
    int leng = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < leng; j++){
            arr[i][j] = bcl(i, j);
        }
        leng += 1;
    }
}


int main() {
    //printf("%d", factorial(3));
    int n;
    scanf("%d", &n);
    int** arr;
    arr = CreateMassive(n);

    coeff(arr, n);
    PrintPascal(arr, n);

    return 0;
}