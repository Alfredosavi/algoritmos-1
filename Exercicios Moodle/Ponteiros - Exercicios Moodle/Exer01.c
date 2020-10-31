/* 1. Implemente uma função que receba 2 números floats e retorne a multiplicação e a divisão entre eles.
Trate possíveis erros. Imprima esses valores fora do escopo da função (na main). */
#include <stdio.h>

void Exer01(float num1, float num2, float *pd, float *pm);

int main(void)
{
    float N1 = 3.14151692, N2 = 24.65;
    float pd, pm;
    Exer01(N1, N2, &pd, &pm);
    printf("Divisao -> %.4f\nMultiplicacao -> %.4f\n", pd, pm);
}

void Exer01(float num1, float num2, float *pd, float *pm)
{
    *pm = num1 * num2;
    if (num2 != 0)
    {
        *pd = num1 / num2;
    }
}
