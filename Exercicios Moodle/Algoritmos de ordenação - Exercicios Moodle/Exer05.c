/* 5. Alfredo está frequentando as aulas de Algoritmos, e não contente com os métodos apresentados,
resolveu criar o Alfredinho Sort: para cada elemento do vetor, sorteia-se uma posição aleatória e 
executa-se a troca entre estas posições. Este processo deve ser repetido até que o vetor esteja 
ordenado. Implemente o Alfredinho Sort e tente analisar quão eficiente ele é. */
#include <stdio.h>
#define INTERACOES 1000

void AlfredinhoSort(int vet[], int tam);
void printVet(int vet[], int tam);

int main(void)
{
    // Numeros aleatorios entre 1-50 em diferentes tamanhos de vetores com o mesmo numero de interações
    int vet1[5] = {34, 49, 5, 37, 42};
    int vet2[10] = {48, 15, 18, 22, 27, 35, 7, 6, 38, 16};
    int vet3[15] = {48, 15, 22, 9, 12, 11, 13, 17, 13, 2, 38, 29, 16, 2, 39};
    int vet4[20] = {42, 18, 31, 35, 23, 17, 25, 38, 20, 5, 18, 28, 9, 35, 21, 28, 26, 25, 43, 23};
    int vet5[25] = {19, 6, 5, 44, 21, 25, 7, 29, 7, 44, 41, 22, 39, 11, 20, 26, 39, 41, 13, 10, 45, 48, 12, 16};

    printf("Vetor[1]: ");
    printVet(vet1, 5);
    AlfredinhoSort(vet1, 5);
    printf("Order[1]: ");
    printVet(vet1, 5);

    printf("\n");

    printf("Vetor[2]: ");
    printVet(vet2, 10);
    AlfredinhoSort(vet2, 10);
    printf("Order[2]: ");
    printVet(vet2, 10);

    printf("\n");

    printf("Vetor[3]: ");
    printVet(vet3, 15);
    AlfredinhoSort(vet3, 15);
    printf("Order[3]: ");
    printVet(vet3, 15);

    printf("\n");

    printf("Vetor[4]: ");
    printVet(vet4, 20);
    AlfredinhoSort(vet4, 20);
    printf("Order[4]: ");
    printVet(vet4, 20);

    printf("\n");

    printf("Vetor[5]: ");
    printVet(vet5, 25);
    AlfredinhoSort(vet5, 25);
    printf("Order[5]: ");
    printVet(vet5, 25);

    return 0;
}

void AlfredinhoSort(int vet[], int tam)
{
    int aux, luck1, luck2, cont = 0;
    srand(time(NULL));

    do
    {
        luck1 = rand() % (tam - 0) + 0;
        luck2 = rand() % (tam - 0) + 0;

        if (vet[luck1] > vet[luck2] && luck1 < luck2)
        {
            aux = vet[luck1];
            vet[luck1] = vet[luck2];
            vet[luck2] = aux;
        }

        cont++;
    } while (cont < INTERACOES);
}

void printVet(int vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%2d ", vet[i]);
    }
    printf("\n");
}
