/* 5) Crie uma função que recebe duas variaveis L1 e L2 do tipo lista estática e
imprime todos elementos de L1 que tambem estão em L2. */
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

void Exer05(lista *L1, lista *L2);
int main(void)
{
    lista L1;
    lista L2;
    int i;
    CriaLista(&L1);
    CriaLista(&L2);

    //Lista L1
    elem E0 = {32478, "Alana"};
    elem E1 = {1234, "Genice"};
    elem E2 = {4232, "obi-wan"};
    elem E3 = {54366, "Bruna"};
    elem E4 = {75876, "doguinhos"};
    elem E5 = {32467, "kenobi"};
    elem E6 = {12544, "MIRACLE"};
    elem E7 = {5678, "ninja"};
    elem E8 = {3995, "DOTAEMELHOR"};

    elem E9 = {32478, "Genice"};
    elem E10 = {1234, "Bruna"};
    elem E11 = {4232, "TESTING"};
    elem E12 = {54366, "Alana"};
    elem E13 = {75876, "jedi"};
    elem E14 = {32467, "XABLAU"};
    elem E15 = {12544, "EASY"};
    elem E16 = {5678, "MIRACLE"};
    elem E17 = {3995, "SEESSIGOU"};

    Inserir(&L1, &E0, 0);
    Inserir(&L1, &E1, 1);
    Inserir(&L1, &E2, 2);
    Inserir(&L1, &E3, 3);
    Inserir(&L1, &E4, 4);
    Inserir(&L1, &E5, 5);
    Inserir(&L1, &E6, 6);
    Inserir(&L1, &E7, 7);
    Inserir(&L1, &E8, 8);

    Inserir(&L2, &E9, 0);
    Inserir(&L2, &E10, 1);
    Inserir(&L2, &E11, 2);
    Inserir(&L2, &E12, 3);
    Inserir(&L2, &E13, 4);
    Inserir(&L2, &E14, 5);
    Inserir(&L2, &E15, 6);
    Inserir(&L2, &E16, 7);
    Inserir(&L2, &E17, 8);

    for (i = 0; i < 9; i++)
    {
        printf("RA: %d  Nome: %s\n", L1.L[i].RA, L1.L[i].Nome);
    }
    printf("\n\n");
    for (i = 0; i < 9; i++)
    {
        printf("RA: %d  Nome: %s\n", L2.L[i].RA, L2.L[i].Nome);
    }

    printf("\n\n");
    Exer05(&L1, &L2);
}

// Funcao que recebe duas listas e imprimi somente se existe nas duas.
void Exer05(lista *L1, lista *L2)
{
    int i, j;
    for (i = 0; i <= L1->quant; i++)
    {
        for (j = 0; j <= L2->quant; j++)
        {
            if (strcmp(L1->L[i].Nome, L2->L[j].Nome) == 0)
            {
                printf("%s\n", L1->L[i].Nome);
            }
        }
    }
}
