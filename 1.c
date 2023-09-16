#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(){
    unsigned long n;
    scanf("%lu", &n);
    unsigned long x;
    for (x = 0; x <= n; x++) {
        if (x % 3 == 0 && x % 5 == 0) {
            printf("fizz buzz ");
        }
        else if (x % 3 == 0) {
            printf("fizz ");
        }
        else if (x % 5 == 0) {
            printf("buzz ");
        }
        else {
            printf("%d ", x);
        }
    }
}