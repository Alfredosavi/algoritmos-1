// BUSCA BINARIA - RECURSIVA
#include <stdio.h>

int BBINR(int vet[], int x, int ini, int fim);

int main(void)
{
    int num[11] = {2, 5, 7, 10, 14, 14, 16, 17, 20, 24, 35};
    printf("%d\n", BBINR(num, 14, 0, 10));
}

int BBINR(int vet[], int x, int ini, int fim)
{
    if (ini > fim)
    {
        return -1;
    }
    else
    {
        int m = (ini + fim) / 2;
        if (vet[m] == x)
        {
            return m;
        }
        if (vet[m] < x)
        {
            return BBINR(vet, x, m + 1, fim);
        }
        else
        {
            return BBINR(vet, x, ini, m - 1);
        }
    }
}
