#include <stdio.h>

int POW(int a, int b);

int main(void)
{
    int a;
    int b;
    printf("Insira uma base (A): ");
    scanf("%d", &a);
    printf("Insira uma expoente (B): ");
    scanf("%d", &b);
    printf("Resultado = %d\n", POW(a, b));

    return 0;
}

int POW(int a, int b)
{
    int R = 1;
    while (b >= 1)
    {
        R = R * a;
        b--;
    }
    return R;
}
