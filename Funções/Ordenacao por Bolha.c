#include <stdio.h>

void BBSort(int vet[], int tam);
void ImprimiVet(int vet[], int tam);

int main(void)
{
    int vet[] = {1, 5, 2, 5, 1, 7, 5, 3, 8, 2, 5, 54, 2, 213, 45, 12, 6};
    BBSort(vet, 17);
    ImprimiVet(vet, 17);
}

void BBSort(int vet[], int tam)
{
    int i, j;
    int trocou = 1;
    int aux;
    for (i = 0; i < tam - 1 && trocou; i++)
    {
        trocou = 0;
        for (j = 0; j < (tam - 1 - i); j++)
        {
            if (vet[j] > vet[j + 1])
            {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                trocou = 1;
            }
        }
    }
}

void ImprimiVet(int vet[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}
