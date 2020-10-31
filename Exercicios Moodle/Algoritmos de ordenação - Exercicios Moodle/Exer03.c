/*3. Escreva uma versão recursiva do algoritmo de ordenação por seleção.*/
#include <stdio.h>

void OrdSelec(int vet[], int tam, int i);

int main()
{
    int i;
    int bruninha[] = {12, 5, 7, 2, 10, 8, 15, 3, 11, 4};

    OrdSelec(bruninha, 10, 0);

    for (i = 0; i < 10; i++)
    {
        printf("%d ", bruninha[i]);
    }
}

void OrdSelec(int vet[], int tam, int i)
{
    if (i != tam)
    {
        int menor;
        int aux;
        int j = i;

        menor = j;
        while (j < tam)
        {
            if (vet[j] < vet[menor] && j != tam)
            {
                menor = j;
            }
            j++;
        }
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
        OrdSelec(vet, tam, i + 1);
    }
}
