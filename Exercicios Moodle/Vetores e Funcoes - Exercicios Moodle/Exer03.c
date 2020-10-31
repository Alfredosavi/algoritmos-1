// 3) Implementa uma função que recebe um vetor de inteiros e imprime a quantidade de números de
// pares e a quantidade de números ímpares.
#include <stdio.h>

void GeraVetorAleatorio(int vetor[], int tam, int LimI, int LimS);
void ImprimiVetor(int vetor[], int tam);
void SeparaPI(int vet[], int tam);

int main(void)
{
    int tamanho;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int Vetor[tamanho];

    GeraVetorAleatorio(Vetor, tamanho, 1, 100);
    ImprimiVetor(Vetor, tamanho);
    printf("\n\n");
    SeparaPI(Vetor, tamanho);
}

void GeraVetorAleatorio(int vetor[], int tam, int LimI, int LimS)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < tam; i++)
    {
        vetor[i] = rand() % (LimS - LimI) + LimI;
    }
}

void ImprimiVetor(int vetor[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d\t", vetor[i]);
    }
}

void SeparaPI(int vet[], int tam)
{
    int par = 0;
    int impar = 0;
    int i;

    for (i = 0; i < tam; i++)
    {
        if (vet[i] % 2 == 0)
        {
            par = par + 1;
        }
        else
        {
            impar = impar + 1;
        }
    }
    printf("Numero PAR: %d\n", par);
    printf("Numero IMPAR: %d\n", impar);
}
