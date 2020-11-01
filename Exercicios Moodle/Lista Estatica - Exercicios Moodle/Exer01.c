/* 1) Implementar a TAD lista estatica conforme foi visto em aula, e criar uma "main" capaz de 
testar suas funções (criar, inserir, remover, etc). */
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

void CriaLista(lista *x);
int Inserir(lista *x, elem *e, int pos);
int Remove(lista *x, int pos);
elem *Busca(lista *x, int RA);
elem *BuscaNome(lista *x, char n[]);
int main(void)
{
    lista L1;
    int i;
    int opcao;
    char repetir;

    elem E0s = {32478, "OiaaaAPEDRA"};
    elem E1 = {1234, "Dotinha"};
    elem E2 = {4232, "Dotaemelhor"};
    elem E3 = {54366, "alana"};
    elem E4 = {75876, "bruninhaFofinha"};
    elem E5 = {32467, "rozicreydi"};
    elem E6 = {12544, "GGFASTEASY"};
    elem E7 = {5678, "PABLOOREI"};
    elem E8 = {3995, "thelifesnake"};

    do
    {
        printf("************************************************\n");
        printf("1. Criar Lista\n");
        printf("2. Inserir\n");
        printf("3. Remover\n");
        printf("4. Sair\n");
        printf("************************************************\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            CriaLista(&L1);
        }
        else if (opcao == 2)
        {
            //int Inserir(lista *x, elem *e, int pos);
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
        }
        else if (opcao == 3)
        {
            int posicao;
            printf("Qual Posicao deseja remover? ");
            scanf("%d", &posicao);

            //int Remove(lista *x, int pos)
            Remove(&L1, posicao);
            for (i = 0; i < L1.quant; i++)
            {
                printf("RA: %d  Nome: %s\n", L1.L[i].RA, L1.L[i].Nome);
            }
        }
        else if (opcao == 4)
        {
            repetir = 'S';
        }
        else
        {
            printf("Opcao Invalida !!!\n");
        }
    } while (repetir != 'S');
}

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

int Remove(lista *x, int pos)
{
    int i;
    if (pos > x->quant)
    {
        return -1;
    }
    else
    {
        for (i = pos; i < x->quant; i++)
        {
            x->L[i] = x->L[i + 1];
        }
        x->quant--;
    }
    return -1;
}

elem *Busca(lista *x, int RA)
{
    int i;
    for (i = 0; i <= x->quant; i++)
    {
        if (RA == x->L[i].RA)
            ;
        {
            return &(x->L[i]);
        }
        return NULL;
    }
}

elem *BuscaNome(lista *x, char n[])
{
    int i;
    for (i = 0; i <= x->quant; i++)
    {
        if (strcmp(n, x->L[i].Nome) == 0)
        {
            return &(x->L[i]);
        }
    }
    return NULL;
}
