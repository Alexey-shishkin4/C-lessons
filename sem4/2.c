#include <stdio.h>
#include <assert.h>
#include <math.h>



int divisors(int n){
    int c = 2;
    if (n == 1){
        return 1;
    }
    for (int i = 2; i <= sqrt(n); i ++){
        if (n % i == 0)
            c += 2;
    }
    return c;
}

int main(){
    int n;
    scanf("%d", &n);
    assert(n>=1);
    printf("%d", divisors(n));
    return 0;
}