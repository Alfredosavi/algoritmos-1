/* 1. Modifique o código do método de ordenação por bolha para que ele se transforme no método de
ordenação por pedra, ou seja, o elemento desce ao invés de subir no vetor ordenado. */
#include <stdio.h>

void BBPedra(int vet[], int tam);

int main(void)
{
    int i;
    int input[] = {1, 5, 4, 6, 2, 6, 8, 9, 4, 123, 1, 66, 54, 23, 876, 35, 76, 34, 22, 77, 87};
    BBPedra(input, 21);
    for (i = 0; i < 21; i++)
    {
        printf("%d ", input[i]);
    }
}
void BBPedra(int vet[], int tam)
{
    int i, j, aux;
    for (i = tam - 1; i > 0; i--)
    {
        for (j = tam - 1; j > 0; j--)
        {
            if (vet[j] < vet[j - 1])
            {
                aux = vet[j];
                vet[j] = vet[j - 1];
                vet[j - 1] = aux;
            }
        }
    }
}
