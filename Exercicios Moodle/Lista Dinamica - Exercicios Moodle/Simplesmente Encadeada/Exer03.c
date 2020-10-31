// 3) Adicionar a TAD uma função de busca.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct comida
{
    float preco;
    char Nome[30];
    struct comida *prox;
} comida;

typedef struct
{
    int quant;
    comida *inicio;
} ListaDin;

void CriaListaLD(ListaDin *L);
void InserirPrimeiro(ListaDin *L, comida *C);
void InserirPosicao(ListaDin *L, comida *C, int pos);
void ImprimiListaDin(ListaDin *Lista);
comida *BuscaNome1(ListaDin *l, char n[]);
comida *BuscaPreco1(ListaDin *l, float p);

int main(void)
{
    comida *c;

    //L2
    ListaDin Ala02;
    CriaListaLD(&Ala02);
    c = malloc(sizeof(comida));
    c->preco = 2;
    strcpy(c->Nome, "seila1");
    InserirPrimeiro(&Ala02, c);

    c = malloc(sizeof(comida));
    c->preco = 6;
    strcpy(c->Nome, "seila2");
    InserirPosicao(&Ala02, c, 1);

    c = malloc(sizeof(comida));
    c->preco = 10;
    strcpy(c->Nome, "seila3");
    InserirPosicao(&Ala02, c, 2);

    c = malloc(sizeof(comida));
    c->preco = 12;
    strcpy(c->Nome, "seila4");
    InserirPosicao(&Ala02, c, 3);

    printf("Lista L2:\n");
    ImprimiListaDin(&Ala02);

    printf("\n\nEDICAO\n");

    comida *aux;
    aux = BuscaNome1(&Ala02, "seila2");
    if (aux == NULL)
    {
        printf("Nao Encontrado\n");
    }
    else
    {
        printf("Nome: %s -- Preco: %.2f\n", aux->Nome, aux->preco);
    }

    aux = BuscaPreco1(&Ala02, 10);
    if (aux == NULL)
    {
        printf("Nao Encontrado\n");
    }
    else
    {
        printf("Nome: %s -- Preco: %.2f\n", aux->Nome, aux->preco);
    }
}

void CriaListaLD(ListaDin *L)
{
    L->quant = 0;
    L->inicio = NULL;
}

void InserirPrimeiro(ListaDin *L, comida *C)
{
    L->quant++;
    C->prox = L->inicio;
    L->inicio = C;
}

void InserirPosicao(ListaDin *L, comida *C, int pos)
{
    int cont = 0;
    comida *aux;
    aux = L->inicio;
    if (pos == 0)
    {
        L->quant++;
        C->prox = L->inicio;
        L->inicio = C;
    }
    while (cont < (pos - 1))
    {
        aux = aux->prox;
        cont++;
    }
    C->prox = aux->prox;
    aux->prox = C;
    L->quant++;
}

void ImprimiListaDin(ListaDin *Lista)
{
    comida *aux = Lista->inicio;
    do
    {
        printf("Nome: %s -- Preco: %.2f\n", aux->Nome, aux->preco);
        aux = aux->prox;

    } while (aux != NULL);
}

comida *BuscaNome1(ListaDin *l, char n[])
{
    int i;
    comida *aux = l->inicio;
    for (i = 0; i < l->quant; i++)
    {
        if (strcmp(n, aux->Nome) == 0)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

comida *BuscaPreco1(ListaDin *l, float p)
{
    int i;
    comida *aux = l->inicio;
    for (i = 0; i < l->quant; i++)
    {
        if (aux->preco == p)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
