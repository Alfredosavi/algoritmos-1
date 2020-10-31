/* 1. Faça uma função recursiva que receba um número inteiro positivo N e imprima todos os números 
naturais de 0 até N em ordem crescente. */
#include <stdio.h>

void Exer01(int valor);

int main(void)
{
    int valor;

    printf("Insira um numero positivo: ");
    scanf("%d", &valor);
    Exer01(valor);
}

void Exer01(int valor)
{
    if (valor != -1)
    {
        Exer01(valor - 1);
        printf("%d ", valor);
    }
}
