#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int ArrayA[7][7];
    for (int i = 0; i <= 6; ++i)
    {
        for (int j = 0; j <= 6; j++)
        {
            ArrayA[i][j] = rand() % 100;
        }
    }

    printf("Random array\n");
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            printf("%d\t", ArrayA[i][j]);
        }
        printf("\n");
    }

    int MaxEl = 0;
    int ArrayB [7];

    for (int i = 0; i < 7; i++)
    {
        MaxEl = ArrayA[i][0];
        for (int j = 0; j < 7; j++)
        {
            if (ArrayA[i][j] > MaxEl)
            {
                MaxEl = ArrayA[i][j];
            }
        }
        ArrayB[i] = MaxEl;
    }

    printf("\nArray of max elements\n");

    for (int i = 0; i < 7; i++)
    {
        printf("%d\t", ArrayB[i]);
    }

    printf("\n\n");
    for (int i = 0; i <= 6; i++)
    {
        ArrayA[i][i] = ArrayB[i];
    }

    printf("Updated array\n");
    for (int i = 0; i <= 6; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            printf("%d\t", ArrayA[i][j]);
        }
        printf("\n");
    }

    return 0;
}