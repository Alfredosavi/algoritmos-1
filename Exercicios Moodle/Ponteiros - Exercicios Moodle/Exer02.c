/* 2. Implemente uma função que recebe um vetor com 10 diferentes números e retorna o maior e o menor 
dentre estes números. Imprima esses valores fora do escopo da função (na main). */
#include <stdio.h>

void Exer02(int vet[], int tam, int *pg, int *pp);

int main(void)
{
    int pp, pg;
    int vet[10] = {534, 7, 23, 55, 6865, 5, 235, 867, 8, 545};
    Exer02(vet, 10, &pg, &pp);
    printf("Maior -> %d\nMenor -> %d\n", pg, pp);
}

void Exer02(int vet[], int tam, int *pg, int *pp)
{
    int i;
    *pg = vet[0], *pp = vet[0];
    for (i = 0; i < tam; i++)
    {
        if (vet[i] > *pg)
        {
            *pg = vet[i];
        }
        if (vet[i] < *pp)
        {
            *pp = vet[i];
        }
    }
}
