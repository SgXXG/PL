#include <stdio.h>
#include <string.h>

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
                fprintf(F1, "\n");
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

int check (FILE *F)
{
    if(F == NULL)
    {
        printf("\nERROR!!! Cannot open the file!\n");
        return -1;
    }
}

int main() {
    FILE *f1 = fopen("D:\\!Studing\\Laba6\\File1.txt", "r+");
    FILE *f2 = fopen("D:\\!Studing\\Laba6\\File2.txt", "r+");
    FILE *f3 = fopen("D:\\!Studing\\Laba6\\File3.txt", "r+");
    FILE *resFile = fopen("D:\\!Studing\\Laba6\\ResFile.txt", "w+");

    check (f1);
    check (f2);
    check (f3);
    check (resFile);

    read (f1, resFile);
    read (f2, resFile);
    read (f3, resFile);

    fseek (resFile, SEEK_SET, 0);

    char strings[14][22], str[22];
    int count = 0, i, j;

    while ( (feof (resFile) == 0) && (count < 14))
    {
        fgets (str, 22, resFile);
        strcpy (strings[count++], str);
    }

    for(i = 1; i < count; i++)
    {
        for(j = 0; j < count - i; j++)
        {
            if(strcmp(strings[j], strings[j+1]) > 0)
            {
                strcpy (str, strings[j]);
                strcpy (strings[j], strings[j+1]);
                strcpy (strings[j+1], str);
            }
        }
    }

    fclose(resFile);
    FILE *resultFile = fopen("D:\\!Studing\\Laba6\\ResFile.txt", "r+");
    i = 0;
    while (i < count)
    {
        fprintf (resultFile, strings[i++]);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(resultFile);

    return 0;
}
