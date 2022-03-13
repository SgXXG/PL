#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 20

typedef struct tagBTH
{
    char day[3], month[3], year[5];
} BTH;
/* Структура для хранения информации про одного человека */
typedef struct tagITEM
{
    char Surname[20], Name[20], Lastname[20], Division[20];
    BTH birthday;
} ITEM;

/* Массив максимум на 20 человек */
ITEM Men[MAX];

/* Количество занятых элементов в массиве */
int Number;

/* Функция для вывода всех элементов */
void Print( void )
{
    int i;

    printf(" N  Surname              Name                 Lastname             Division              Birthday\n");
    for (i = 0; i < Number; i++)
        printf("%2i. %-20s %-20s %-20s %-20s %3s %3s %5s\n",
               i + 1, Men[i].Surname, Men[i].Name, Men[i].Lastname, Men[i].Division, Men[i].birthday.day, Men[i].birthday.month, Men[i].birthday.year);
}
/* End of 'Print' function */

/* Функция для добавления элемента */
void Add(void)
{
    if (Number == 19)
    {
        fprintf(stderr, "Can't add element\n");
        return;
    }

    printf("Enter surname > ");
    scanf("%s", Men[Number].Surname);
    printf("Enter name > ");
    scanf("%s", Men[Number].Name);
    printf("Enter lastname > ");
    scanf("%s", Men[Number].Lastname);
    printf("Enter division > ");
    scanf("%s", Men[Number].Division);
    printf("Enter day of birthday > ");
    scanf("%s", Men[Number].birthday.day);
    printf("Enter month of birthday > ");
    scanf("%s", Men[Number].birthday.month);
    printf("Enter year of birthday > ");
    scanf("%s", Men[Number].birthday.year);

    Number++;
}
/* End of 'Add' function */

/* Функция для изменения элемента */
void Edit(void)
{
    int i;

    printf("Enter the number of the editting element > ");
    scanf("%i", &i);
    if (i < 1 || i > Number)
    {
        fprintf(stderr, "Element %i is not available\n", i);
        return;
    }

    i--;

    printf("Select the field, which you would like to edit: ");
    char str[7];
    scanf("%s", str);
    if (strcmp(str, "Surname") == 0)
    {
        printf("Enter surname > ");
        scanf("%s", Men[i].Surname);
    }
    else
    {
        if ((strcmp(str, "Name") == 0))
        {
            printf("Enter name > ");
            scanf("%s", Men[i].Name);
        }
        else
        {
            if (strcmp(str, "Lastname") == 0)
            {
                printf("Enter Lastname > ");
                scanf("%s", Men[i].Lastname);
            }
            else
            {
                if (strcmp(str, "Division") == 0)
                {
                    printf("Enter Division > ");
                    scanf("%s", Men[i].Division);
                }
                else
                {
                    if (strcmp(str, "Day") == 0)
                    {
                        printf("Enter day of birthday > ");
                        scanf("%s", Men[i].birthday.day);
                    }
                    else
                    {
                        if (strcmp(str, "Month") == 0)
                        {
                            printf("Enter month of birthday > ");
                            scanf("%s", Men[i].birthday.month);
                        }
                        else
                        {
                            if (strcmp(str, "Year") == 0)
                            {
                                printf("Enter year of birthday > ");
                                scanf("%s", Men[i].birthday.year);
                            }
                            else
                                printf("Incorrect field entered\n");
                        }
                    }
                }
            }
        }
    }
}
/* End of 'Edit' function */

/* Функция для удаления элемента */
void Del( void )
{
    int i;

    Print();
    printf("Enter the number of the deletting element > ");
    scanf("%i", &i);
    if (i < 1 || i > Number)
    {
        fprintf(stderr, "Element %i is not available\n", i);
        return;
    }

    for (i--; i < Number - 1; i++)
        Men[i] = Men[i + 1];

    Number--;
}
/* End of 'Del' function */

/* Функция для сохранения массива в файле */
void Save(void)
{
    FILE* F;
    int i;

    if ((F = fopen("File.txt", "w")) == NULL)
    {
        fprintf(stderr, "Can't open file for writing 'File.txt'\n");
        return;
    }

    fprintf(F, " N  Surname              Name                 Lastname             Division             Birthday\n");
    for (i = 0; i < Number; i++)
        fprintf(F, "%2i. %-20s %-20s %-20s %-20s %-3s %-3s %-5s\n",
                i + 1, Men[i].Surname, Men[i].Name, Men[i].Lastname, Men[i].Division, Men[i].birthday.day, Men[i].birthday.month, Men[i].birthday.year);
    fclose(F);
}
/* End of 'Save' function */

/* Функция для чтения массива из файла */
void Load(void)
{
    FILE* F;
    int i;

    if ((F = fopen("File.txt", "r")) == NULL)
    {
        fprintf(stderr, "Can't open file for reading '1.txt'\n");
        return;
    }

    char FileName[256];
    int k = 0;
    while ((fgets(FileName, 255, F) != NULL))
    {
        k++;
    }
    k--;
    Number = k;
    fseek(F, SEEK_SET, 0);

    char str[256];
    fgets(str, 256, F);
    char suta[4];

    for (i = 0; i < Number; ++i)
        fscanf(F, "%s %s %s %s %s %s %s %s", suta, Men[i].Surname, Men[i].Name, Men[i].Lastname, Men[i].Division, Men[i].birthday.day, Men[i].birthday.month, Men[i].birthday.year);
    fclose(F);
}
/* End of 'Load' function */

/* Функция для упорядочивания массива по фамилии */
void SortBySurname( void )
{
    int i, j;
    BTH tempBth;
    ITEM Temp;

    for (j = Number - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (strcmp(Men[i].Surname, Men[i + 1].Surname) > 0)
            {
                Temp = Men[i];
                Men[i] = Men[i + 1];
                Men[i + 1] = Temp;
            }
        }
    }
}
/* End of 'SortBySurname' function */

/* Функция для упорядочивания массива по названию отдела */
void SortByDivision(void)
{
    int i, j;
    ITEM Temp;

    for (j = Number - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if (strcmp(Men[i].Division, Men[i + 1].Division) > 0)
            {
                Temp = Men[i];
                Men[i] = Men[i + 1];
                Men[i + 1] = Temp;
            }
}
/* End of 'SortByDivision' function */

/* Вывод меню и чтение номера выбранного пункта */
int Menu( void )
{
    int c = 0;

    while ((c < '0' || c > '8') && c != 27)
    {
        printf("0 : exit\n"
               "1 : add\n"
               "2 : save\n"
               "3 : load\n"
               "4 : print\n"
               "5 : sort by surname\n"
               "6 : sort by division\n"
               "7 : delete\n"
               "8 : edit\n"
               ">");
        c = getch();
        printf("%c\n", c);
    }
    return c;
} /* End of 'Menu' function */

/* Основная функция */
void main( void )
{
    int Selection;

    Number = 0;
    while ((Selection = Menu()) != '0' && Selection != 27)
        switch (Selection)
        {
            case '1':
                Add();
                break;
            case '2':
                Save();
                break;
            case '3':
                Load();
                break;
            case '4':
                Print();
                break;
            case '5':
                SortBySurname();
                break;
            case '6':
                SortByDivision();
                break;
            case '7':
                Del();
                break;
            case '8':
                Edit();
                break;
        }
} /* End of 'main' function */