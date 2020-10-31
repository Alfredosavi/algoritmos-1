/* 1) Implementar a TAD lista dinamica conforme foi visto em aula, e criar uma "main"
capaz de testar suas funções (definir, inserir, remover, etc). */
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
void InserirOrdenadoPreco(ListaDin *L, comida *C);
void EditarPrecoPorNome(ListaDin *L, char n[], float p);
void ImprimiListaDin(ListaDin *Lista);
comida *removePorPosicao(ListaDin *l, int pos);
comida *RemoverPorNome(ListaDin *l, char n[]);

int main(void)
{
    comida *c;

    //L1
    ListaDin Ala01;
    CriaListaLD(&Ala01);
    c = malloc(sizeof(comida));
    c->preco = 1.345;
    strcpy(c->Nome, "numxei1");
    InserirPrimeiro(&Ala01, c);

    c = malloc(sizeof(comida));
    c->preco = 3.46;
    strcpy(c->Nome, "numxei2");
    InserirPosicao(&Ala01, c, 1);

    c = malloc(sizeof(comida));
    c->preco = 4.99;
    strcpy(c->Nome, "numxei3");
    InserirPosicao(&Ala01, c, 2);

    c = malloc(sizeof(comida));
    c->preco = 9.99;
    strcpy(c->Nome, "numxei4");
    InserirPosicao(&Ala01, c, 3);

    c = malloc(sizeof(comida));
    c->preco = 3.45;
    strcpy(c->Nome, "InserirOrdenado");
    InserirOrdenadoPreco(&Ala01, c);

    //L2
    ListaDin Ala02;
    CriaListaLD(&Ala02);
    c = malloc(sizeof(comida));
    c->preco = 2;
    strcpy(c->Nome, "seila");
    InserirPrimeiro(&Ala02, c);

    c = malloc(sizeof(comida));
    c->preco = 6;
    strcpy(c->Nome, "seila");
    InserirPosicao(&Ala02, c, 1);

    c = malloc(sizeof(comida));
    c->preco = 10;
    strcpy(c->Nome, "seila");
    InserirPosicao(&Ala02, c, 2);

    c = malloc(sizeof(comida));
    c->preco = 12;
    strcpy(c->Nome, "seila");
    InserirPosicao(&Ala02, c, 3);

    printf("Lista L1:\n");
    ImprimiListaDin(&Ala01);
    printf("\n\n");
    printf("Lista L2:\n");
    ImprimiListaDin(&Ala02);

    printf("\n\nEDICAO\n");
    EditarPrecoPorNome(&Ala01, "numxei1", 6.99);
    removePorPosicao(&Ala01, 3);
    RemoverPorNome(&Ala01, "numxei2");

    printf("Lista L1:\n");
    ImprimiListaDin(&Ala01);
    printf("\n\n");
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

void InserirOrdenadoPreco(ListaDin *L, comida *C)
{
    comida *aux;
    if (C->preco < L->inicio->preco)
    {
        InserirPrimeiro(L, C);
    }
    else
    {
        aux = L->inicio;
        while (aux->prox->preco < C->preco)
        {
            aux = aux->prox;
        }
        C->prox = aux->prox;
        aux->prox = C;
        L->quant++;
    }
}

void EditarPrecoPorNome(ListaDin *L, char n[], float p)
{
    comida *aux;
    aux = L->inicio;
    while ((strcmp(n, aux->Nome) != 0) && aux != NULL)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        aux->preco = p;
    }
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

comida *removePorPosicao(ListaDin *l, int pos)
{
    comida *aux, *tmp;
    int cont = 0;
    aux = l->inicio;
    if (pos == 0)
    {
        tmp = aux->prox;
        l->inicio = tmp;
        l->quant--;
        return aux;
    }
    else
    {
        while (cont < (pos - 1))
        {
            aux = aux->prox;
            cont++;
        }
        tmp = aux->prox;
        aux->prox = tmp->prox;
        l->quant--;
        tmp->prox = NULL;
    }
    return tmp;
}

comida *RemoverPorNome(ListaDin *l, char n[])
{
    comida *aux = l->inicio, *tmp;
    if (strcmp(n, aux->Nome) == 0)
    {
        tmp = aux->prox;
        l->inicio = tmp;
        l->quant--;
        tmp->prox = NULL;
        return aux;
    }
    while (strcmp(n, aux->prox->Nome) != 0 && aux != NULL)
    {
        aux = aux->prox;
    }
    tmp = aux->prox;
    aux->prox = tmp->prox;
    l->quant--;
    tmp->prox = NULL;
    return tmp;
}
