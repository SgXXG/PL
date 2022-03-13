#include <stdio.h>

#define SIZE 22
#define WORDCOUNT 5

int main (void)
{
    char sentence1[SIZE] = "Hello world a abcd Cc \0";
    char sentence2[SIZE] = { ' ' };
    char* word = sentence1;
    int symbolscount = 0, maxsymbols = 0;
    int k = 0;

    for (int i = 0; i < WORDCOUNT; i++)
    {
        for (int j = k; j < SIZE-2; j++)
        {
            while (sentence1[j] != ' ')
            {
                ++symbolscount;
                ++j;
            }
            if (maxsymbols < symbolscount)
            {
                maxsymbols = symbolscount;
                word = &(sentence1[j - symbolscount]);
            }
            symbolscount = 0;
        }
        while (*word != ' ')
        {
            sentence2[k] = *word;
            ++word;
            ++k;
        }
        sentence2[k] = ' ';
        ++k;
        maxsymbols = 0;
    }

    printf("%s", sentence2);

    return 0;
}
