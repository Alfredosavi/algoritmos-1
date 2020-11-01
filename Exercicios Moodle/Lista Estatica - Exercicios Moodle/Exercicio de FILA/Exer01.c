/* Sua arquitetura computacional é capaz de armazenar uma fila dos processos que querem fazer 
uso da CPU do mesmo. Entretanto, para evitar que um só processo utilize a CPU por muito tempo, 
deixando os demais ociosos, a arquitetura foi programada para que cada processo só possa utilizar 
a CPU por, no máximo, 4 ms (milisegundos). Sendo assim, sempre que um processo necessitar de mais 
tempo de processamento, ele retorna ao final da fila.
Suponha que este sistema está, no momento, com 5 processos A,B,C,D e E (que entraram na fila 
nesta exata ordem) e que eles necessitam de A=20 ms, B=7ms, C=10ms, D=4ms, E=9ms como tempos de 
processamento. Implemente as funções necessárias para mostrar a exata ordem que estes processos 
serão executados e por quanto tempo. */
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct Processos
{
    char Processo;
    int tempo;
} elem;

typedef struct
{
    elem L[MAX];
    int quant;
    int inicio;
    int fim;
} FilaCircular;

void CriaFila(FilaCircular *f);
int InserirNaFilaCircular(FilaCircular *f, elem *e);
int RemoverDaFilaCircular(FilaCircular *f);

int main(void)
{
    int i;
    FilaCircular F1;
    CriaFila(&F1);
    elem E0 = {'A', 20};
    elem E1 = {'B', 7};
    elem E2 = {'C', 10};
    elem E3 = {'D', 4};
    elem E4 = {'E', 9};

    InserirNaFilaCircular(&F1, &E0);
    InserirNaFilaCircular(&F1, &E1);
    InserirNaFilaCircular(&F1, &E2);
    InserirNaFilaCircular(&F1, &E3);
    InserirNaFilaCircular(&F1, &E4);
    printf("Processos:\n");
    for (i = 0; i < F1.quant; i++)
    {
        printf("Processo: %c | Tempo: %d\n", F1.L[i].Processo, F1.L[i].tempo);
    }
    printf("\n\n");
    while (F1.quant != 0) // responsavel por processar todos os processos na Fila
    {
        for (i = 0; i < F1.quant; i++) // cada for � 4ms
        {
            F1.L[i].tempo = F1.L[i].tempo - 4;
            if (F1.L[i].tempo >= 0)
            {
                //RemoverDaFilaCircular(&F1);
                //InserirNaFilaCircular(&F1, (F1.L[i].Processo, F1.L[i].tempo));
            }
            else
            {
                RemoverDaFilaCircular(&F1);
            }
        }
        for (i = 0; i < F1.quant; i++)
        {
            printf("Processo: %c | Tempo: %d\n", F1.L[i].Processo, F1.L[i].tempo);
        }
        printf("\n");
    }

    printf("\n\n");
    printf("FILA FINAL:\n");
    for (i = 0; i < F1.quant; i++)
    {
        printf("Processo: %c | Tempo: %d\n", F1.L[i].Processo, F1.L[i].tempo);
    }
}

void CriaFila(FilaCircular *f)
{
    f->quant = 0;
    f->inicio = 0;
    f->fim = -1;
}

int InserirNaFilaCircular(FilaCircular *f, elem *e)
{
    int pos;
    if (f->fim == MAX - 1)
    {
        pos = 0;
    }
    else
    {
        pos = f->fim + 1;
    }

    if (pos == f->inicio && f->quant > 0)
    {
        return -1;
    }

    else
    {
        f->L[pos] = *e;
        f->fim = pos;
        f->quant++;
        return 1;
    }
}

int RemoverDaFilaCircular(FilaCircular *f)
{
    if (f->quant == 0)
    {
        return -1;
    }
    else
    {
        f->quant--;
        f->inicio = f->inicio + 1;
        if (f->inicio == MAX)
        {
            f->inicio = 0;
        }
    }
    return 1;
}
