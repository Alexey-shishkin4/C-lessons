#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int IsPrime(unsigned long long n) {
    for (unsigned long long i = 2;i <= n / 2 ;i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    unsigned long long n;
    scanf("%llu", &n);
    if (n < 2) {
        printf("Error!");
        return 0;
    }

    if (IsPrime(n) == 1) {
        printf("Prime");
    }
    else {
        printf("Compositive");
    }
    return 0;
}