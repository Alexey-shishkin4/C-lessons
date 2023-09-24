#include <stdio.h>
#include <assert.h>


int length(unsigned long n) {
    unsigned long l = 0;
    do {
        l++;
        n /= 10;
    } while (n);
    return l;
}


int SumOfDigits(unsigned long n){
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}


int main(){
    unsigned long l;
    unsigned long r;
    scanf("%lu", &l);
    scanf("%lu", &r);

    assert(l < r);

    for (; l <= r; l++) {
        unsigned long x = l;
        if (length(x) == 6) {
            unsigned long first_sum = SumOfDigits(x % 1000);

            unsigned long second_sum = SumOfDigits(x / 1000);

            if (first_sum == second_sum){
                printf("%d \n", l);
            }
        }
        else if (length(x) > 6) {
            return 0;
        }
    }
    return 0;
}