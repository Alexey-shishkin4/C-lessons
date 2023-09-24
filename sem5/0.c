#include <stdio.h>
#include <assert.h>
#include <math.h>



void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int x = 5, y = 7;
    swap(&x, &y);
    printf("%d, %d", x, y);
}

