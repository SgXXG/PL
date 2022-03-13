#include <stdio.h>

int check (FILE *F)
{
    if(F == NULL)
    {
        printf("\nERROR!!! Cannot open the file!\n");
        return -1;
    }
}

void read (FILE *F, FILE *F1)
{
    char str[22];
    char *estr;

    while (1)
    {
        estr = fgets (str, sizeof(str), F);

        if (estr == NULL)
        {
            if (feof (F) != 0)
            {
                printf ("\nReading is end\n");
                break;
            }
            else
            {
                printf ("\nReading mistake\n");
                break;
            }
        }
        fprintf (F1,"%s", str);
    }
}

int main() {
    FILE *f1 = fopen("D:\\!Studing\\Laba6.2\\F1.txt", "r");
    FILE *f2 = fopen("D:\\!Studing\\Laba6.2\\F2.txt", "r");
    FILE *f3 = fopen("D:\\!Studing\\Laba6.2\\F3.txt", "w+");

    check (f1);
    check (f2);
    check (f3);

    read (f1, f3);
    read (f2, f3);

    fclose(f1);
    fclose(f2);

    fseek (f3, SEEK_SET, 0);

    char str[16];
    fgets (str, 16, f3);
    fclose(f3);

    int Arr[16];
    for (int i = 0; i < 16; ++i)
    {
        Arr[i] = str[i];
    }

    int temp = 0;
    for (int i = 0; i < 16 - 1; i++)
    {
        for (int j = (16 - 1); j > i; j--)
        {
            if (Arr[j - 1] > Arr[j])
            {
                temp = Arr[j - 1];
                Arr[j - 1] = Arr[j];
                Arr[j] = temp;
            }
        }
    }

    FILE *resFile = fopen("D:\\!Studing\\Laba6.2\\F3.txt", "w+");

    for (int i = 0; i < 16; ++i)
    {
        str[i] = Arr[i];
    }

    for (int i = 1; i < 16; ++i)
    {
        fprintf(resFile, "%c", str[i]);
    }

    fclose (resFile);

    return 0;
}
