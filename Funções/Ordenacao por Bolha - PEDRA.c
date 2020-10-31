#include <stdio.h>

void BBPedra(int vet[], int tam);

int main(void)
{
    int i;
    int Ala[] = {1, 5, 4, 6, 2, 6, 8, 9, 4, 123, 1, 66, 54, 23, 876, 35, 76, 34, 22, 77, 87};
    BBPedra(Ala, 21);
    for (i = 0; i < 21; i++)
    {
        printf("%d ", Ala[i]);
    }
    printf("\n");
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
