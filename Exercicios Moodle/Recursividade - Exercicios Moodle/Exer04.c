//4. Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um número natural
// N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.
#include <stdio.h>

int Exer04(int num, int k, int cont);
int Exer04v2(char string[], char k, int cont, int i); //versão string

int main(void)
{
    int Number = 1435564;
    int n = 4;
    printf("%d ocorre %d vezes em %d.\n", n, Exer04(Number, n, 0), Number);

    // VERSÃO STRING

    char String[] = "anala";
    char K = 'a';
    printf("%c ocorre %d vezes em %s.\n", K, Exer04v2(String, K, 0, 0), String);

    return 0;
}
int Exer04(int num, int k, int cont)
{
    if (num == 0)
    {
        return cont;
    }
    else
    {
        if ((num % 10) == k)
        {
            cont++;
        }
        num = num / 10;
        return Exer04(num, k, cont);
    }
}

int Exer04v2(char string[], char k, int cont, int i)
{
    if (string[i] == '\0')
    {
        return cont;
    }
    else
    {
        if (string[i] == k)
        {
            cont++;
        }
    }
    return Exer04v2(string, k, cont, i + 1);
}
