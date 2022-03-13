#include <stdio.h>
const int n = 4;

struct person
{
    char firstName[20];
    char surname[30];
    char lastName[30];
    int num;
    int exp;
};

int main()
{
    struct person pers[n];
    for (int i = 0; i < n; i++)
    {
        printf(" Input your name: ");
        scanf("%s", pers[i].firstName);
        printf("Input your surname: ");
        scanf("%s", pers[i].surname);
        printf("Input your last name: ");
        scanf("%s", pers[i].lastName);
        printf("Input number of your department: ");
        scanf("%d", &pers[i].num);
        printf("Input your working experience: ");
        scanf("%d", &pers[i].exp);
    }

    struct person temp[n];
    int k = 0;
    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {
            if (pers[j-1].exp < pers[j].exp)
            {
                temp[k] = pers[j-1];
                pers[j-1] = pers[j];
                pers[j] = temp[k];
                k++;
            }
        }
    }

    printf("Employees of the enterprise in "
                    "descending order of their experience\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%s %s %s %d %d\n",
               pers[i].firstName, pers[i].surname, pers[i].lastName,
               pers[i].num, pers[i].exp);
    }

    return 0;
}
