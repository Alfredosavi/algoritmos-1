/* 6) Crie uma função que remove elementos duplicados de uma lista, ou seja, se existirem 2 
ou mais elementos com o mesmo RA na lista, apenas um deles deve permanecer após a execução 
desta função. */
#include <stdio.h>
#include <string.h>
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

void CriaLista(lista *x)
{
    x->quant = 0;
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

void Exer06(lista *x);
int Remove(lista *x, int pos);

int main(void)
{
    lista L1;
    int i;

    elem E0 = {1, "Teste"};
    elem E1 = {2, "Dotinha"};
    elem E2 = {3, "Dotaemelhor"};
    elem E3 = {4, "All"};
    elem E4 = {5, "SEESSIGOU"};
    elem E5 = {1, "WIN"};
    elem E6 = {2, "GGMIDEASY"};
    elem E7 = {8, "OLOFMASTER"};
    elem E8 = {3, "MIRACLE"};

    CriaLista(&L1);

    Inserir(&L1, &E0, 0);
    Inserir(&L1, &E1, 1);
    Inserir(&L1, &E2, 2);
    Inserir(&L1, &E3, 3);
    Inserir(&L1, &E4, 4);
    Inserir(&L1, &E5, 5);
    Inserir(&L1, &E6, 6);
    Inserir(&L1, &E7, 7);
    Inserir(&L1, &E8, 8);

    for (i = 0; i < L1.quant; i++)
    {
        printf("RA: %d  Nome: %s\n", L1.L[i].RA, L1.L[i].Nome);
    }
    printf("\n\n");
    Exer06(&L1);
    printf("Quant = %d\n", L1.quant);
    for (i = 0; i < L1.quant; i++)
    {
        printf("RA: %d  Nome: %s\n", L1.L[i].RA, L1.L[i].Nome);
    }
}

void Exer06(lista *x)
{
    int pos;
    int i, j, k;
    int cont;
    for (i = 0; i < x->quant; i++)
    {
        cont = 0;
        for (j = 0; j < x->quant; j++)
        {
            if (x->L[i].RA == x->L[j].RA)
            {
                cont++;
                pos = j;
            }
        }
        if (cont > 1)
        {
            for (k = pos; k < x->quant; k++)
            {
                x->L[k] = x->L[k + 1];
            }
            x->quant--;
        }
    }
}
