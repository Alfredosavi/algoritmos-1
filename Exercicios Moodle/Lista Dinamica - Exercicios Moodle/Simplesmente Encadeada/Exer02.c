// 2) Adicionar a TAD uma função "Imprimir": que percorre toda a lista e imprime os conteúdos de todos
// os nós.
#include <stdio.h>

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
void ImprimiListaDinamica(ListaDin *x);

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
    strcpy(c->Nome, "numxei5");
    InserirPosicao(&Ala01, c, 4);

    ImprimiListaDinamica(&Ala01);
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

void ImprimiListaDinamica(ListaDin *x)
{
    comida *aux = x->inicio;
    while (aux->prox != NULL)
    {
        printf("Nome: %s | Preco: %.2f\n", aux->Nome, aux->preco);
        aux = aux->prox;
    }
}
