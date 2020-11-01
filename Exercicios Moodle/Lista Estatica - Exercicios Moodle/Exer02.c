/* 2) Adicionar a TAD uma função uma função que implemente um algoritmo de ordenação. */
#include <stdio.h>
#define MAX 100

typedef struct aluno
{
    int RA;
    char Nome[30];
} elem;

typedef struct
{
    elem L[MAX];
    int quant;
} lista;

void CriaLista(lista *x);
void SelSort(lista *x);
void troca(lista *x, int p1, int p2);
int main(void)
{
    lista L1;
    int i;
    CriaLista(&L1);
    elem E0 = {32478, "Teste"};
    elem E1 = {1234, "Dotinha"};
    elem E2 = {4232, "Dotaemelhor"};
    elem E3 = {54366, "All"};
    elem E4 = {776, "bruninhaFofinha"};
    elem E5 = {32467, "rozicreydi"};
    elem E6 = {12544, "GGFASTEASY"};
    elem E7 = {5678, "OLOFMASTER"};
    elem E8 = {3995, "MIRACLE"};

    Inserir(&L1, &E0, 0);
    Inserir(&L1, &E1, 1);
    Inserir(&L1, &E2, 2);
    Inserir(&L1, &E3, 3);
    Inserir(&L1, &E4, 4);
    Inserir(&L1, &E5, 5);
    Inserir(&L1, &E6, 6);
    Inserir(&L1, &E7, 7);
    Inserir(&L1, &E8, 8);

    for (i = 0; i < 9; i++)
    {
        printf("RA: %d  Nome: %s\n", L1.L[i].RA, L1.L[i].Nome);
    }

    SelSort(&L1);
    printf("\n\nLista Ordenada pelo RA:\n\n");
    for (i = 0; i < 9; i++)
    {
        printf("RA: %d  Nome: %s\n", L1.L[i].RA, L1.L[i].Nome);
    }
}

int Inserir(lista *x, elem *e, int pos)
{
    if (x->quant == MAX)
    {
        return -1;
    }
    else if (pos > x->quant)
    {
        return -2;
    }
    else
    {
        if (x->quant == pos)
        {
            x->L[pos] = *e;
        }
        else
        {
            int i;
            for (i = x->quant; i > pos; i--)
            {
                x->L[i] = x->L[i - 1];
            }
            x->L[pos] = *e;
        }
        x->quant++;
    }
    return 1;
}

void SelSort(lista *x)
{
    int i, j, imin;
    for (i = 0; i < x->quant - 1; i++)
    {
        imin = i;
        for (j = i + 1; j < x->quant; j++)
        {
            if (x->L[j].RA < x->L[imin].RA)
            {
                imin = j;
            }
        }
        if (imin != i)
        {
            troca(x, i, imin);
            //troca2(&x->L[i], &x->L[imin]);
        }
    }
}

void CriaLista(lista *x)
{
    x->quant = 0;
}

void troca(lista *x, int p1, int p2)
{
    elem aux;
    aux = x->L[p1];
    x->L[p1] = x->L[p2];
    x->L[p2] = aux;
}
