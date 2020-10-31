/* 2 Faça uma função recursiva que receba um número inteiro positivo N e imprima todos os números 
naturais de 0 até N em ordem decrescente. */
#include <stdio.h>

void Exer02(int valor);

int main(void)
{
    int valor;

    printf("Insira um numero positivo: ");
    scanf("%d", &valor);
    Exer02(valor);
}
void Exer02(int valor)
{
    if (valor != -1)
    {
        printf("%d ", valor);
        Exer02(valor - 1);
    }
}
