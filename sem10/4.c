#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <setjmp.h>


long Convert(const char* str, int base, jmp_buf* jmp_env) {
    if (str == NULL || base < 2 || base > 16) {
        if (jmp_env == NULL) {
            exit(1);
        } else {
            longjmp(*jmp_env, 1);
        }
    }

    char* endptr;
    long result = strtol(str, &endptr, base);

    if (*endptr != '\0' && !isspace(*endptr)) {
        if (jmp_env == NULL) {
            exit(1);
        } else {
            longjmp(*jmp_env, 1);
        }
    }

    return result;
}

int main() {
    char* input = "1A";
    int base = 16;
    jmp_buf jmp_env;

    long result = Convert(input, base, &jmp_env);
    printf("%ld\n", result);
    
    return 0;
}
