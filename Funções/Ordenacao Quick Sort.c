// ORDENACAO POR QUICK SORT
#include <stdio.h>

int Separa(int v[], int p, int dir);
void QuickSort(int v[], int p, int r);

int main(void)
{
    int i;
    int vet[] = {5, 7, 2, 5, 8, 1, 5, 76, 3, 654, 2, 76, 1, 43};
    QuickSort(vet, 0, 14);
    for (i = 0; i < 14; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int Separa(int v[], int p, int dir)
{
    int c = v[p], i = p + 1, j = dir, aux;
    while (i <= j)
    {
        if (v[i] <= c)
        {
            i++;
        }
        else if (c < v[j])
        {
            j--;
        }
        else
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    v[p] = v[j];
    v[j] = c;
    return j;
}

void QuickSort(int v[], int p, int r) // r (direita)
{
    if (p < r)
    {
        int j = Separa(v, p, r);
        QuickSort(v, p, j - 1);
        QuickSort(v, j + 1, r);
    }
}
