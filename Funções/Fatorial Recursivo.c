#include <stdio.h>

int FAT(int x);

int main(void)
{
    int a;
    printf("Insira o fatorial: ");
    scanf("%d", &a);
    printf("Fatorial de %d = %d\n", a, FAT(a));
    return 0;
}

int FAT(int x)
{
    if (x == 0)
    {
        return 1;
    }
    return x * FAT(x - 1);
}
