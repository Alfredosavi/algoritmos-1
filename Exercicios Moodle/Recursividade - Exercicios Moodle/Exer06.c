// 6. Implemente uma função recursiva que recebe um número decimal e retorna sua versão em binrio.
#include <stdio.h>

int Exer06(int num);

int main(void)
{
    int Number = 10;
    printf("%d", Exer06(Number));
    return 0;
}

int Exer06(int num)
{
    if (num < 2)
    {
        return num;
    }
    return (10 * Exer06(num / 2)) + num % 2;
}
