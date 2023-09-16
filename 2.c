#include <stdio.h>


int main(){
    unsigned long n;
    scanf("%lu", &n);
    unsigned long x = 0;
    unsigned long i;
    for (i = 0; i <= n - 1; i++) {
        unsigned long j;
        for (j = 0; j <= n - 1; j++) {
            printf("%3d ", x);
            x += 1;
        }
        printf("\n");
    }
}