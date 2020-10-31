
#include <stdio.h>

void Insercao(int vet[], int tam);

int main(void)
{
    int i;
    int vet[] = {5, 7, 2, 5, 8, 1, 5, 76, 3, 654, 2, 76, 1, 43};
    Insercao(vet, 14);
    for (i = 0; i < 14; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void Insercao(int vet[], int tam)
{
    int aux;
    int i, j;
    for (i = 2; i < tam; i++)
    {
        j = i;
        while (vet[j] < vet[j - 1] && j != 0)
        {
            aux = vet[j - 1];
            vet[j - 1] = vet[j];
            vet[j] = aux;
            j--;
        }
    }
}