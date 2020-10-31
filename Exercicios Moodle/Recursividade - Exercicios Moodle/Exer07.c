// 7. Implemente uma função recursiva que imprima o número de 0s e 1s dado um vetor de inteiros.
// Assuma que este vetor possui apenas 0s e 1s.
#include <stdio.h>

void Exer07(int vet[], int tam, int one);

int main(void)
{
    int Binario[] = {1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1};
    // 0 -> 9
    // 1 -> 11
    Exer07(Binario, 19, 0);
}

void Exer07(int vet[], int tam, int one)
{
    if (tam == -1)
    {
        printf("Numero 0 -> %d\n", (20 - one));
        printf("Numero 1 -> %d\n", one);
    }
    else
    {
        if (vet[tam] == 1)
        {
            one = one + 1;
        }
        Exer07(vet, tam - 1, one);
    }
}
