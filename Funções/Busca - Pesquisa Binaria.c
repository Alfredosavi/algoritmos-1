// Busca / Pesquisa Binaria
#include <stdio.h>

int BBIN(int vet[], int x, int ini, int fim);

int main(void)
{
    int vet[] = {1, 2, 5, 7, 10, 14, 15, 17, 20, 25, 52, 432, 534};
    printf("Posicao - %d\n", BBIN(vet, 534, 0, 13));
}

int BBIN(int vet[], int x, int ini, int fim)
{
    int m;
    while (ini <= fim)
    {
        m = (ini + fim) / 2;
        if (vet[m] == x)
        {
            return m;
        }
        else
        {
            if (vet[m] < x)
            {
                ini = m + 1;
            }
            else
            {
                fim = m - 1;
            }
        }
    }
    return -1;
}
