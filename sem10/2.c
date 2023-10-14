#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void nullChek(void* ptr){
    if (ptr == NULL){
        printf("Out of memory!");
        exit(0);
    }
}


char* TrimStr(const char* str){
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    while (start < len && isspace(str[start]))
        start++;
    while (end > 0 && isspace(str[end]))
        end--;

    size_t newLen = end - start + 1;
    char* result = (char *) malloc(newLen + 1);
    nullChek(result);

    strncpy(result, str + start, newLen);
    result[newLen] = '\0';

    return result;
}


int main(){
    const char *str = "   ab a     ";

    char* trimmed = TrimStr(str);

    printf("Исходная строка: \"%s\"\n", str);
    printf("Обрезанная строка: \"%s\"\n", trimmed);
    free(trimmed);

    return 0;
}