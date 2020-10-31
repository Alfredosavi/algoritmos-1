/* 4. Voce pretende fazer uma viagem de carro em Duckland, um país muito organizado em
que todos os pedágios de uma mesma estrada estão organizados de maneira
equidistante, a partir da capital Donald. Seu destino final é Scrooge, porém são 4
estradas possíveis entre Donald e Scrooge. Por consequência, cada estrada terá uma
quilometragem total diferente, número de pedágios diferente e consumo de gasolina
diferente devido às condições do asfalto. Suas opções são:

Estrada     Quilometragem       Distância entre        Consumo
                total            cada pedâgio         (km/litro)
A               150                  20                   10
B               120                  15                   8,5
C               135                  20                   8,2
D               160                  30                   9,4

Implemente:
a) Um vetor de structs para armazenar os valores da tabela acima;
b) Uma função que recebe o vetor de structs criado em (a) e calcula o número de
pedágios daquela estrada e a quantidade de litros de combustível gasta;
c) Um vetor de structs que armazene os valores computados em (b);
d) Uma função que calcule o custo da viagem para cada estrada, recebendo como
parâmetros: uma struct (conforme criada em (c)), o preço de cada pedágio e o
preço do combustível. Ex.: se cada pedágio custa 10 duckdollars e o combustível é
vendido por 3 duckdollars, o custo da viagem em cada estrada seria:
A 115,00
B 122,35
C 109,39
D 101,06
Teste também com outros preços. A estrada D será sempre a mais vantajosa, mesmo
baixando/aumentando o preço do pedágio ou do combustível? */

#include <stdio.h>

struct Viagem
{
    char Estrada; //A B C D
    int Quilo;    // 150 120 135 160
    int Dist;     // 20 15 20 30
    float Consu;  // 10  8.5  8.2  9.4
};

struct Resultado
{
    char Estrada;
    int Pedagios;
    float Litros;
};
void FuncaoB(struct Viagem vA[], struct Resultado vB[], int i);
void CustoViagem(struct Resultado Vc[], float VC, float VP);
int main(void)
{
    int i;
    struct Viagem V[4];

    // recebendo dados
    V[0].Quilo = 150;
    V[1].Quilo = 120;
    V[2].Quilo = 135;
    V[3].Quilo = 160;

    V[0].Dist = 20;
    V[1].Dist = 15;
    V[2].Dist = 20;
    V[3].Dist = 30;

    V[0].Consu = 10;
    V[1].Consu = 8.5;
    V[2].Consu = 8.2;
    V[3].Consu = 9.4;

    V[0].Estrada = 'A';
    V[1].Estrada = 'B';
    V[2].Estrada = 'C';
    V[3].Estrada = 'D';

    //Declarando struct para o resultado
    struct Resultado Res[4];

    for (i = 0; i < 4; i++)
    {
        printf("Estrada -> %c\nQuilometros -> %d\nDistancia -> %d\nConsumo -> %.2f\n", V[i].Estrada, V[i].Quilo, V[i].Dist, V[i].Consu);
        printf("\n");
    }
    printf("\n\n\n");

    for (i = 0; i < 4; i++)
    {
        FuncaoB(V, Res, i);
        printf("Estrada = %c\nQuantidade de Pedagio = %d\nQuantidade de combustivel Gasto = %.2f\n", Res[i].Estrada, Res[i].Pedagios, Res[i].Litros);
        printf("\n");
    }
    CustoViagem(Res, 3, 10);
    return 0;
}

/* b) Uma função que recebe o vetor de structs criado em (a) e calcula o número de
pedágios daquela estrada e a quantidade de litros de combustível gasta */
void FuncaoB(struct Viagem vA[], struct Resultado vB[], int i)
{
    vB[i].Pedagios = vA[i].Quilo / vA[i].Dist;
    vB[i].Litros = vA[i].Quilo / vA[i].Consu;
    vB[i].Estrada = vA[i].Estrada;
}

// Funcao C
void CustoViagem(struct Resultado Vc[], float VC, float VP)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("Estrada %c %.2f\n", Vc[i].Estrada, (Vc[i].Pedagios * VP + Vc[i].Litros * VC));
    }
}
