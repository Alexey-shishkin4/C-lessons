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


int main(){
    printf("%d \n", 150 / 60);
    unsigned long l;
    unsigned long r;
    scanf("%lu", &l);
    scanf("%lu", &r);

    assert(l < r);

    for (; l <= r; l++) {
        unsigned long x = l;
        if (length(x) == 6) {
            unsigned long first_sum = 0;
            for (int j = 0; j <= 2; j++) {
                first_sum += x % 10;
                x /= 10;
            }
            unsigned long second_sum = 0;
            for (int j = 0; j <= 2; j++) {
                second_sum += x % 10;
                x /= 10;
            }

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