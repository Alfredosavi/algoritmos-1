// Desenvolva uma estrutura modular baseada em menu com opcoes para criar e
// para ler um arquivo do tipo texto.

#include <stdio.h>
#include <string.h>

void GravarTxt(void);
void LerTxt(void);

int main(void)
{
  int opcao;
  do
  {
    printf("****** MENU PRINCIPAL ******\n");
    printf("1. Criar um Arquivo Texto\n");
    printf("2. Ler um Arquivo Texto\n");
    printf("3. Sair do Programa\n");
    printf("Opcao Desejada: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      GravarTxt();
      break;
    case 2:
      LerTxt();
      break;
    case 0:
      exit(0);
    }
  } while (opcao == 1 || opcao == 2 || opcao == 0);
}

void GravarTxt(void)
{
  FILE *fp;
  fp = fopen("saida.txt", "w");

  char str[80];

  printf("Digite a mensagem, (FIM) para encerrar:\n");
  fflush(stdin);
  do
  {
    gets(str);
    if (strcmp(str, "FIM") == 0)
    {
      break;
    }
    strcat(str, "\n"); // add o fim de linha
    fputs(str, fp);    // gravar uma linha no arquivo texto
  } while (strcmp(str, "FIM") != 0);

  fclose(fp);
}

void LerTxt(void)
{
  FILE *fp;
  fp = fopen("saida.txt", "r");

  char str[80];

  printf("Texto lido......\n");
  fgets(str, 80, fp);
  while (!feof(fp))
  {
    printf("%s", str);
    fgets(str, 80, fp);
  }
  fclose(fp);
}
