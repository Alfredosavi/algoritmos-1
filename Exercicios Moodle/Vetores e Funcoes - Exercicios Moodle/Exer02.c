// 2) Implemente uma função que imprime uma string (array de caracteres) em ordem inversa.
// Exemplo: "pablo" -> "olbap".
#include <stdio.h>

void ImprimiString(char String[], int tam);
int ContaString(char String[]);
void InverteString(char String[], int tam);

int main(void)
{
    char String[51];
    int valor;

    printf("Informe uma string [50]: ");
    gets(String);

    printf("String Original: %s\n", String);
    printf("String Invertida: ");
    valor = ContaString(String);
    InverteString(String, valor);
}

void ImprimiString(char String[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%c", String[i]);
    }
}

int ContaString(char String[])
{
    int i = 0;
    do
    {
        i++;
    } while (String[i] != '\0');
    return (i);
}

void InverteString(char String[], int tam)
{
    int i;
    for (i = tam; i >= 0; i--)
    {
        printf("%c", String[i]);
    }
}
