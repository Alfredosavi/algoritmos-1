// 5. Implemente uma função recursiva que recebe uma string e substitui as letras minúsculas por
// maiúsculas e vice-versa.
#include <stdio.h>

void Exer(char string[], int tam);

int main(void)
{
    char string[] = "BrUniNHaCArolINa";
    Exer(string, 15);
    return (0);
}

void Exer(char string[], int tam)
{
    if (tam == -1)
    {
        printf("%s\n", string);
    }
    else
    {
        if (string[tam] >= 65 && string[tam] <= 90)
        {
            string[tam] = string[tam] + 32;
        }
        else
        {
            string[tam] = string[tam] - 32;
        }
        Exer(string, tam - 1);
    }
}
