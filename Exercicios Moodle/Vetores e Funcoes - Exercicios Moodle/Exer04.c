/* 4) Implementa uma função que recebe 3 parametros: uma palavra e dois caracteres; e retorna a 
quantidade de caracteres no alfabeto entre os 2 caracteres que foram passados como parametros.
Ex: fun("azbgxbcyhdu", 'b', 'd') retorna 4. */
#include <stdio.h>

int Exer04(char s[], char a, char b);

int main(void)
{
    char string[] = "skldgnklndfweopjdf";
    char x = 'a';
    char y = 'e';
    printf("String: %s\n", string);
    printf("A string tem %d letras entre o (%c) e (%c)\n", Exer04(string, x, y), x, y);
}

int Exer04(char s[], char a, char b)
{
    int cont = 0;
    int qtde = 0;
    char maior = b;
    char menor = a;

    if (a > b)
    {
        maior = a;
        menor = b;
    }

    do
    {
        if (s[cont] <= maior && s[cont] >= menor)
        {
            qtde++;
        }
        cont++;
    } while (s[cont] != '\0');
    return (qtde);
}
