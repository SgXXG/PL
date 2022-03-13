#include <stdio.h>

#define BaseSize 47
#define Size 22
#define Size1 65

int main()
{
  char sentence1[Size] = "PRIVET MIR F ASDVF C \0";
  char Base[BaseSize] = "hello world all is ok yes no later night day \0";
  char sentence2[Size1] = { "" };

  int k = 0, m = 0, i = 0;

  while (i < Size1)
  {
      while (Base[m] != ' ')
      {
          sentence2[i] = Base[m];
          m++;
          i++;
      }
      m++;
      sentence2[i] = ' ';
      i++;

      while (Base[m] != ' ')
      {
          sentence2[i] = Base[m];
          m++;
          i++;
      }
      m++;
      sentence2[i] = ' ';
      i++;

      while (sentence1[k] != ' ')
      {
          sentence2[i] = sentence1[k];
          k++;
          i++;
      }
      k++;
      sentence2[i] = ' ';
      i++;
  }

  sentence2[i] = "\0";

  printf("\n%s", sentence2);
  return 0;
}
