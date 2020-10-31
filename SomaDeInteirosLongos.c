#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Item
{
    int valor;
    struct Item *prox;
    struct Item *ant;
} Item;

typedef struct Lista
{
    Item *inicio;
    Item *fim;
    int tamanho;
} Lista;

Item *ponteiroParaPosicao(Lista *l, int pos);
Item *novoItem(int value);
void inserirInicio(Lista *l, Item *novo);
void inserirFim(Lista *l, Item *novo);
void inserirProximo(Lista *l, Item *atual, Item *novo);
void inserirNaPosicao(Lista *l, Item *novo, int pos);
Lista *tolist(const char *String);
Lista *add(Lista *A, Lista *B);
void PrintaLista(Lista *l);

int main(void)
{
    const char *x = "99999999999";
    const char *y = "11111111111";

    Lista *L1, *L2, *L3;
    L1 = tolist(x);
    L2 = tolist(y);
    printf("Lista L1: ");
    PrintaLista(L1);

    printf("\nLista L2: ");
    PrintaLista(L2);
    printf("\n\n");
    L3 = add(L1, L2);
    printf("Lista L3 (SOMA): ");
    PrintaLista(L3);
}

Item *ponteiroParaPosicao(Lista *l, int pos)
{
    Item *curr = NULL;
    int i;
    if (pos < (l->tamanho / 2))
    {
        curr = l->inicio;
        for (i = 0; i < (pos - 1); i++)
        {
            curr = curr->prox;
        }
    }
    else
    {
        curr = l->fim;
        for (i = l->tamanho; i > pos; i--)
        {
            curr = curr->ant;
        }
    }
    return (curr);
}

Item *novoItem(int value)
{
    Item *i = malloc(sizeof(Item));
    i->valor = value;
    i->prox = NULL;
    i->ant = NULL;
    return i;
}

void inserirInicio(Lista *l, Item *novo)
{
    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = l->inicio;
    }
    else
    {
        l->inicio->ant = novo;
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->tamanho++;
}

void inserirFim(Lista *l, Item *novo)
{
    if (l->fim == NULL)
    {
        inserirInicio(l, novo);
    }
    else
    {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
        l->fim->prox = NULL;
        l->tamanho++;
    }
}

void inserirProximo(Lista *l, Item *atual, Item *novo)
{
    assert(atual->prox != NULL);
    Item *aux;

    novo->prox = atual->prox;
    aux = atual->prox;
    novo->ant = atual;

    aux->ant = novo;
    atual->prox = novo;

    l->tamanho++;
}

void inserirNaPosicao(Lista *l, Item *novo, int pos)
{
    assert(pos >= 0 && pos <= l->tamanho);
    if (pos == 0)
    {
        inserirInicio(l, novo);
    }
    else if (pos == l->tamanho)
    {
        inserirFim(l, novo);
    }
    else
    {
        Item *curr = ponteiroParaPosicao(l, pos);
        inserirProximo(l, curr, novo);
    }
}

Lista *tolist(const char *String)
{
    Lista *L = malloc(sizeof(Lista));
    L->inicio = NULL;
    L->fim = NULL;
    L->tamanho = 0;

    int i, a;
    Item *aux;
    for (i = 0; String[i] != '\0'; i++)
    {
        a = (int)(String[i] - '0'); // mudando char para int
        aux = novoItem(a);
        inserirNaPosicao(L, aux, i);
    }
    return L;
}

Lista *add(Lista *A, Lista *B)
{
    Lista *L = malloc(sizeof(Lista));
    L->inicio = NULL;
    L->fim = NULL;
    L->tamanho = 0;
    Item *itemA = A->fim;
    Item *itemB = B->fim;
    Item *aux;
    int quantidade = 0;
    int soma;
    while (itemA != NULL || itemB != NULL)
    {
        if (itemA == NULL)
        {
            while (itemB != NULL)
            {
                soma = itemB->valor + quantidade;
                quantidade = 0;
                if (soma >= 10)
                {
                    soma = soma - 10;
                    quantidade = 1;
                }
                aux = novoItem(soma);
                inserirInicio(L, aux);
                itemB = itemB->ant;
            }
            if (quantidade != 0)
            {
                aux = novoItem(quantidade);
                inserirInicio(L, aux);
            }
            return L;
        }
        else if (itemB == NULL)
        {
            while (itemA != NULL)
            {
                soma = itemA->valor + quantidade;
                quantidade = 0;
                if (soma >= 10)
                {
                    soma = soma - 10;
                    quantidade = 1;
                }
                aux = novoItem(soma);
                inserirInicio(L, aux);
                itemA = itemA->ant;
            }
            if (quantidade != 0)
            {
                aux = novoItem(quantidade);
                inserirInicio(L, aux);
            }
            return L;
        }
        soma = itemA->valor + itemB->valor + quantidade;
        quantidade = 0;
        if (soma >= 10)
        {
            soma = soma - 10;
            quantidade = 1;
        }
        aux = novoItem(soma);
        inserirInicio(L, aux);
        itemA = itemA->ant;
        itemB = itemB->ant;
    }

    if (quantidade != 0)
    {
        aux = novoItem(quantidade);
        inserirInicio(L, aux);
    }
    return L;
}

void PrintaLista(Lista *l)
{
    Item *aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}