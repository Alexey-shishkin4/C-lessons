#include <stdio.h>
#include <assert.h>



int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    assert(a>=1 && b>=1);
    printf("%d", gcd(a, b));
    return 0;
}