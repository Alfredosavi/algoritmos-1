/* 2. Escreva uma versão recursiva do algoritmo de ordenação por inserção. */
#include <stdio.h>

void OrdeIn(int vet[], int tam, int i);

int main(void)
{
    int i;
    int input[] = {1, 5, 4, 6, 2, 6, 8, 9, 4, 123, 1, 66, 54, 23, 876, 35, 76, 34, 22, 77, 87};
    OrdeIn(input, 21, 1);
    for (i = 0; i < 21; i++)
    {
        printf("%d ", input[i]);
    }
}

void OrdeIn(int vet[], int tam, int i)
{
    int j, aux;
    if (i != tam)
    {
        j = i;
        while ((vet[j] < vet[j - 1]) && j != 0)
        {
            aux = vet[j];
            vet[j] = vet[j - 1];
            vet[j - 1] = aux;
            j--;
        }
        i++;
        OrdeIn(vet, tam, i);
    }
}
