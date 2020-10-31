// 1) Implemente uma função que imprima o número de 0s e 1s dado um vetor de inteiros. Assuma que
// este vetor possui apenas 0s e 1s.
#include <stdio.h>

void GeraVetor(int vetor[], int tam);
void ImprimiVetor(int Vetor[], int tam);

int main(void)
{
    int tamanho;
    printf("Informe o tamanho do seu vetor: ");
    scanf("%d", &tamanho);
    int Vetor[tamanho];
    GeraVetor(Vetor, tamanho);
    ImprimiVetor(Vetor, tamanho);
}

//Funcao que gera vetor
void GeraVetor(int vetor[], int tam)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 2;
        // rand() rand() % (LimS - LimI) + LimI
    }
}

void ImprimiVetor(int Vetor[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d\t", Vetor[i]);
    }
}
