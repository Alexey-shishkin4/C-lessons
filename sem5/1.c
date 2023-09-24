#include <stdio.h>
#include <assert.h>
#include <math.h>


void bad_swap(int a, int b){
    int c = a;
    a = b;
    b = c;
}

int main() {
    int x = 5, y = 7;
    printf("before \"bad_swap\": \n x = %d, y = %d \n", x, y);
    bad_swap(x, y);
    printf("after \"bad_swap\": \n x = %d, y = %d\n", x, y);
    printf("y before: %d\n", y);
    int* pointer;
    pointer = &y;
    *pointer = 10;
    printf("y after: %d ", y);
    return 0;
}

