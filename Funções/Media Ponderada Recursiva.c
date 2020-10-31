#include <stdio.h>

float P4(float vet[], int peso[], int tam, int i, float soma, int somapeso);

int main(void)
{
    float vet[] = {5.876, 7.425, 2.345};
    float vetA[] = {5.876, 7.425, 2.345};
    int peso[] = {2, 5, 3};
    printf("Media Recursiva Ponderada -> %.2f\n", P4(vet, peso, 3, 0, 0, 0));
    float soma = 0;
    int i;
    for (i = 0; i < 3; i++)
    {
        soma = soma + (vetA[i] * peso[i]);
    }
    printf("Media no FOR -> %.2f\n", soma / 10);
}

float P4(float vet[], int peso[], int tam, int i, float soma, int somapeso)
{
    if (i != tam)
    {
        soma = soma + (vet[i] * peso[i]);
        somapeso = somapeso + peso[i];
        return P4(vet, peso, tam, i + 1, soma, somapeso);
    }
    else
    {
        return soma / somapeso;
    }
}
