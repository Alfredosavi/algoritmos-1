#include <stdio.h>

void SSort(int vet[], int tam);

int main(void)
{
    int k;
    int vet[] = {5, 7, 2, 5, 8, 1, 5, 76, 3, 654, 2, 76, 1, 43};
    SSort(vet, 14);
    for (k = 0; k < 14; k++)
    {
        printf("%d ", vet[k]);
    }
    printf("\n");
}

void SSort(int vet[], int tam)
{
    int i, j, m, aux;
    for (i = 0; i < tam - 1; i++)
    {
        m = i;
        for (j = i + 1; j < tam; j++)
        {
            if (vet[j] < vet[m])
            {
                m = j;
            }
        }
        if (i != m)
        {
            aux = vet[m];
            vet[m] = vet[i];
            vet[i] = aux;
        }
    }
}
