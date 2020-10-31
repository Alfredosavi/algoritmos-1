#include <stdio.h>

int POWR(int a, int b);

int main(void)
{
    int a;
    int b;
    printf("Insira uma base (A): ");
    scanf("%d", &a);
    printf("Insira uma expoente (B): ");
    scanf("%d", &b);
    printf("Resultado = %d\n", POWR(a, b));
    return 0;
}

int POWR(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * POWR(a, b - 1);
    }
}
