#include <stdio.h>


void EvilScanf(int* p0, int* p1, int* p2){
    int n0, n1, n2;
    scanf("%d", &n0);
    scanf("%d", &n1);
    scanf("%d", &n2);
    int oldp0 = *p0;
    int oldp1 = *p1;
    int oldp2 = *p2;
    *p0 = n0;
    if (n0 > 0){
        *p1 = n1;
        *p2 = n2;
    }
    else{
        *p1 = oldp0;
        *p2 = n0 * n1 * n2 * oldp1 * oldp2;
    }
}


int main() {
    int a = 10, b = 5, c = 9;
    EvilScanf(&a, &b, &c);
    printf("%d %d %d", a, b, c);
    return 0;
}
