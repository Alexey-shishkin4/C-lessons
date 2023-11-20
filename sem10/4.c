#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <setjmp.h>

void bufJump(int errorCode, jmp_buf *buf) {
    if (buf != NULL)
        longjmp(*buf, errorCode);
    else
        exit(errorCode);
}

int isValidSymbol(char c, int base) {
    if (base <= 10) {
        return (c >= '0' && c < '0' + base);
    } else {
        return ((c >= '0' && c <= '9') || (c >= 'A' && c < 'A' + base - 10));
    }
}

int charToDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

int s2i(const char* str, unsigned int base, jmp_buf *buf) {
    if (base > 16) {
        printf("Base > 16\n");
        bufJump(1, buf);
    }

    int sign = (str[0] == '-') ? -1 : 1;
    if (str[0] == '-')
        str++;

    long long dst = 0;
    for (const char* i = str; *i != 0; i++) {
        if (!isValidSymbol(*i, base))
            bufJump(2, buf);

        dst *= base;
        dst += charToDigit(*i);
        if (INT_MAX < dst || dst < INT_MIN)
            bufJump(3, buf);
    }
    
    dst *= sign;
    return (int)dst;
}

int main() {
    jmp_buf buf;
    setjmp(buf);

    printf("%d\n", s2i("ABCD", 16, &buf));
    printf("%d\n", s2i("66", 7, &buf));

    int errorCode = setjmp(buf);
    if (errorCode == 0)
        s2i("23456AAAAAAAAAAAA876543", 11, &buf);
    else if (errorCode == 3) {
        printf("Overflow error\n");
    }

    errorCode = setjmp(buf);
    if (errorCode == 0)
        s2i("zxc", 10, &buf);
    else if (errorCode == 2) {
        printf("Invalid symbol error\n");
    }

    return 0;
}
