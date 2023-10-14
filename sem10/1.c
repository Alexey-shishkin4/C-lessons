#include <stdio.h>
#include <string.h>
#include <ctype.h>


int PalindromChek(const char* str){
    int len = strlen(str);
    int j = len - 1;
    int i = 0;

    while (i < j){

        while (i < len && isspace(str[i]))
            i++;
        while (j >= 0 && isspace(str[j]))
            j++;

        if (i >= j){
            break;
        }

        if (str[i] != str[j])
            return 0;

        i++;
        j--;
    }
    return 1;
}


int main(){
    const char* str = "ab ba";

    if (PalindromChek(str)){
        printf("palindrome\n");
    }else{
        printf("not palindrome\n");
    }

    const char* str1 = "ab a";

    if (PalindromChek(str1)){
        printf("palindrome\n");
    }else{
        printf("not palindrome\n");
    }

    return 0;
}