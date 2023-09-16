#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(){
    unsigned long n;
    scanf("%lu", &n);
    unsigned long x = 0;
    unsigned long n1 = 0;
    for (unsigned long i = 0; i < n; i++) {
        n1 += 1;
        for (unsigned long j = 0; j < n1; j++) {
            if (x > (n * (n + 1) / 2 - 1)) {
                break;
            }
            printf("%3d ", x);
            x += 1;
        }
        printf("\n");
    }
    return 0;
}