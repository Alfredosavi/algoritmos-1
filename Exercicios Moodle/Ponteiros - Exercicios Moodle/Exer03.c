/* 3. Implemente uma função que recebe uma string como parametro e retorna a quantidade de vogais e 
a quantidade de consoantes nesta string. Imprima esses valores fora do escopo da função (na main). */
#include <stdio.h>

void Exer03(char str[], int *vog, int *conso);

int main(void)
{
    int vog = 0, conso = 0;
    char Str[] = "MelhorMidLaneDoMundoDoMundoNaoDaBahia";
    Exer03(Str, &vog, &conso);
    printf("Consoantes -> %d\nVogais -> %d\n", conso, vog);
}

void Exer03(char str[], int *vog, int *conso)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            *vog = *vog + 1;
        }
        else
        {
            *conso = *conso + 1;
        }
    }
}
