#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void nullChek(void* ptr){
    if (ptr == NULL){
        printf("Out of memory");
        exit(0);
    }
}


char** split(const char* str, int* lenlist){
    int len = strlen(str);

    int wordcount = 0;
    int wordnow = 0;

    for (int i = 0; i < len; i++){
        if (isspace(str[i])){
            wordnow = 0;
        }else if (!wordnow) {
            wordnow = 1;
            wordcount++;
        }
    }
    char** words = (char **) malloc(wordcount * sizeof(char * ));
    nullChek(words);

    int wordIndex = 0;
    wordnow = 0;
    int wordStart = 0;

    for (int i = 0; i < len; i++){
        if (isspace(str[i])) {
            if (wordnow) {
                int wordLen = i - wordStart;
                words[wordIndex] = (char *)malloc(wordLen + 1);
                strncpy(words[wordIndex], str + wordStart, wordLen);
                words[wordIndex][wordLen] = '\0';
                wordIndex++;
                wordnow = 0;
            }
        } else if (!wordnow) {
            wordStart = i;
            wordnow = 1;
        }
    }

    // Последнее слово
    if (wordnow) {
        int wordLen = len - wordStart;
        words[wordIndex] = (char *)malloc(wordLen + 1);
        strncpy(words[wordIndex], str + wordStart, wordLen);
        words[wordIndex][wordLen] = '\0';
    }


    *lenlist = wordcount;
    return words;
}


void freeWordArray(char** words, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);
}


int main(){
    const char *str = "This is a test";

    int wordCount;
    char **words = split(str, &wordCount);

    printf("%s\n", str);
    for (int i = 0; i < wordCount; i++) {
        printf("\"%s\" ", words[i]);
    }

    freeWordArray(words, wordCount);
    return 0;
}