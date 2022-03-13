#include <stdio.h>

#define SIZE 28

int main (void)
{
	char str[SIZE] = "Hello1 app orange eweqwqwe \0";
	char str2[SIZE] = {' '};

	int mincount = 10, maxcount = 0;
	char* minword = str;
	char* maxword = str;
	int countsymbols = 0;

	for (int i = 0; i<SIZE; i++) {
		if (str[i] != ' ') {
			countsymbols++;
		}
		else if (str[i] == ' ')
        {
			if (mincount > countsymbols)
            {
				mincount = countsymbols;
				minword = &(str[i - countsymbols]);
			}
			if (maxcount < countsymbols)
            {
				maxcount = countsymbols;
				maxword = &(str[i - countsymbols]);
			}
			countsymbols = 0;
		}
	}

	int j = 0, k = 0;
	char* str3 = str;

	for (int i = 0; i < SIZE; i++)
    {
		if (str3 == minword)
        {
			j = i;
			while (*maxword != ' ')
            {
				str2[j] = *maxword;
				++maxword;
				++j;
			}
			k = 1;
			i += mincount;
			str3 += mincount;
			maxword -= maxcount;
		}
		else if (str3 == maxword)
        {
			j = i + maxcount - mincount;
			while (*minword != ' ')
            {
				str2[j] = *minword;
				++minword;
				++j;
			}
			i += maxcount;
			k = 0;
			str3 += maxcount;
		}
		if (k==1)
			str2[i + maxcount-mincount] = str[i];
		else
			str2[i] = str[i];
		++str3;
	}

	printf("%s", str2);

	return 0;
}
