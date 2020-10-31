#include <stdio.h>

int FIBO(int n);

int main(void)
{
    // Dado o numero (posição) ele retorna o valor respectivo da serie
    int N = 9;
    printf("%d ", FIBO(N));
}

int FIBO(int n)
{
    if (n == 1 || n == 2) // ou n<=2
    {
        return 1;
    }
    return FIBO(n - 1) + FIBO(n - 2);
}
