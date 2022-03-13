#include <stdio.h>

#define SIZE 22

int main(void)
{
	char sentence[SIZE] = "hello world v hate c \0";

    sentence[0] = sentence[0] + 'A' - 'a';
    for (int j = 1; j < SIZE-2; j++)
    {
        if (sentence[j-1] == ' ')
        {
            sentence[j] = sentence[j] + 'A' - 'a';
        }
    }

	printf("%s", sentence);
	return 0;
}
