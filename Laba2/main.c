#include <stdio.h>;
#include <locale.h>;
#include <stdlib.h>
#include <time.h>

int main()
{
    int* a;
    int n;

    //setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    printf("Enter the size of the matrix:");
    scanf("%d", &n);

    a = (int*)malloc(n * n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(a + i * n + j) = rand() % 100;
        }
    }

    printf("Randommed array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", *(a + i * n + j));
        }
        printf("\n");
    }

    // верхняя и нижняя четверти матрицы
    int MinEl;
    MinEl = *a;
    // верхний треугольник
    for (int i = 0; i <= n/2+1; i++)
    {
        for (int j = i; j < n-i; j++)
        {
            if (*(a + i * n + j) <= MinEl)
            {
                MinEl = *(a + i * n + j);
            }
        }
    }
    // нижний треугольник
    for (int i = n/2+1; i < n; i++)
    {
        for (int j = n-i; j < i; j++)
        {
            if (*(a + i * n + j) < MinEl)
            {
                MinEl = *(a + i * n + j);
            }
        }
    }
    printf("Minimal element: %4d", MinEl);

    // левая четверть матрицы
    MinEl = 10000000;
    // верхняя часть
    for (int i = 0; i <= n/2+1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (*(a + i * n + j) < MinEl)
            {
                MinEl = *(a + i * n + j);
            }
        }
    }
    // нижняя часть
    for (int i = n/2+2; i < n; i++)
    {
        for (int j = 0; j < i-(n/2); j++)
        {
            if (*(a + i * n + j) < MinEl)
            {
                MinEl = *(a + i * n + j);
            }
        }
    }

    printf("\nMinimal element: %4d", MinEl);
}


