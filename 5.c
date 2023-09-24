#include <stdio.h>
#include <assert.h>


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

    assert(n > 2);

    for (unsigned long long i = 2; i <= n; i++) {
        if (IsPrime(i) == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}