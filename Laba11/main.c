#include <stdio.h>
#include <string.h>

typedef enum CharType{ctUnknown, ctDigit, ctLetter, ctHyphen } CharType;

CharType GetCharType(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return ctLetter;
    else if(c >= '0' && (c <= '9'))
        return ctDigit;
    else if(c == '_')
        return ctHyphen;
    else return ctUnknown;
}

int main() {
    char str[100];
    int transitions[3][4] = {
        {0, 0, 0, 0},
        {0, 0, 2, 2},
        {0, 2, 2, 2}
    };
    int isFinalState[3] = {0, 0, 1};
    int k, result = 0, i = 0, num = 1;
    printf_s("Enter identifiers: ");
    gets(str);
    putchar('\n');

    char temp[100];

    while(i < strlen(str)){
        k = 1;

        int start = i;
        while((str[i] != ' ') && (i < strlen(str))){
            k = transitions[k][GetCharType(str[i])];
            result = isFinalState[k];
            i++;
        }

        memcpy(temp, str+start, i-start);
        temp[i-start] = '\0';

        if(result)
            printf_s("Identifier \'%s\' is valid!\n", temp);
        else
            printf_s("Identifier \'%s\' is not valid!\n", temp);

        num++;
    }

    getchar();

    return 0;
}
