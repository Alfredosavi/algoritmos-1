/* 4) Adicionar a TAD uma função "InserirOrdenado", que ao invés de inserir o novo elemento 
baseado no parametro de posição, capaz de automaticamente encontrar a posição correta
para o novo elemento de forma a manter a lista ordenada por RAs. */
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

int InserirOrdenadoPorRa(lista *x, elem *e)
{
    if (x->quant == MAX)
    {
        return -1;
    }
    else
    {
        if (x->quant == 0)
        {
            x->L[0] = *e;
            x->quant++;
            return 1;
        }
        int i;
        int valida;
        for (i = x->quant; i >= 0; i--)
        {
            valida = 0;
            if (e->RA > x->L[i - 1].RA)
            {
                x->L[i] = *e;
                x->quant++;
                valida = 1;
                return 1;
            }
            else
            {
                x->L[i] = x->L[i - 1];
            }
        }
        if (valida == 0)
        {
            x->L[i] = *e;
            x->quant++;
            return 1;
        }
    }
    return -1;
}

int main(void)
{
    lista L1;
    int i;

    CriaLista(&L1);
    elem E0 = {50, "Teste"};
    elem E1 = {20, "bruninhaFofinha"};
    elem E2 = {90, "Dotaemelhor"};
    elem E3 = {100, "ingreis"};
    elem E4 = {105, "SEESSIGOU"};
    elem E5 = {0, "meupctravou"};
    elem E6 = {2, "GGMIDEASY"};
    elem E7 = {300, "OLOFMASTER"};
    elem E8 = {200, "MIRACLE"};
    elem E9 = {1, "DEUCERTO?"};

    printf("", InserirOrdenadoPorRa(&L1, &E0));
    printf("", InserirOrdenadoPorRa(&L1, &E1));
    printf("", InserirOrdenadoPorRa(&L1, &E2));
    printf("", InserirOrdenadoPorRa(&L1, &E3));
    printf("", InserirOrdenadoPorRa(&L1, &E4));
    printf("", InserirOrdenadoPorRa(&L1, &E5));
    printf("", InserirOrdenadoPorRa(&L1, &E6));
    printf("", InserirOrdenadoPorRa(&L1, &E7));
    printf("", InserirOrdenadoPorRa(&L1, &E8));
    printf("", InserirOrdenadoPorRa(&L1, &E9));

    printf("Quant = %d\n", L1.quant);
    for (i = 0; i < L1.quant; i++)
    {
        printf("RA: %d  Nome: %s\n", L1.L[i].RA, L1.L[i].Nome);
    }
}
