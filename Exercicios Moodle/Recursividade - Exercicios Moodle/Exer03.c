/* 3. Implemente uma função recursiva que calcula o valor máximo de um vetor de inteiros. */
#include <stdio.h>

int Exer03(int vet[], int maior, int tam, int pos);

int main(void)
{
    int Vet[10] = {1, 5, 7, 53467, 23, 645, 765, 234, 432, 7645};
    printf("Maior: %d\n", Exer03(Vet, Vet[0], 10, 0));
}

int Exer03(int vet[], int maior, int tam, int pos)
{
    if (pos == tam)
    {
        return maior;
    }
    if (vet[pos] > maior)
    {
        maior = vet[pos];
    }
    Exer03(vet, maior, tam, pos + 1);
}
