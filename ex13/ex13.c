#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10

void imprimirMatriz(int matriz[][COLUNAS], int linhas, int colunas);
void preencherMatriz(int matriz[][COLUNAS], int linhas, int colunas);
void preencherMatrizAleatoria(int matriz[][COLUNAS], int linhas, int colunas);
void multiplicarMatrizes(
  int a[][COLUNAS], int linhas1, int colunas1,
  int b[][COLUNAS], int linhas2, int colunas2,
  int c[][COLUNAS]);

int main()
{
  int linhas1, colunas1, linhas2, colunas2;
  int a[LINHAS][COLUNAS], b[LINHAS][COLUNAS], c[LINHAS][COLUNAS];

  srand(time(NULL));

  do
  {
    printf("Qual a quantidade de linhas da primeira matriz? (valor entre 1 e %d): ", LINHAS);
    scanf("%d", &linhas1);
  } while (linhas1 < 1 || linhas1 > LINHAS);

  do {
    printf("Qual a quantidade de colunas da primeira matriz? (valor entre 1 e %d): ", COLUNAS);
    scanf("%d", &colunas1);
  } while (colunas1 < 1 || colunas1 > COLUNAS);

  preencherMatrizAleatoria(a, linhas1, colunas1);

  do
  {
    printf("Qual a quantidade de linhas da segunda matriz? (valor entre 1 e %d): ", LINHAS);
    scanf("%d", &linhas2);
  } while (linhas2 < 1 || linhas2 > LINHAS);

  do {
    printf("Qual a quantidade de colunas da segunda matriz? (valor entre 1 e %d): ", COLUNAS);
    scanf("%d", &colunas2);
  } while (colunas2 < 1 || colunas2 > COLUNAS);

  preencherMatrizAleatoria(b, linhas2, colunas2);

  printf("\nMATRIZ A\n");
  imprimirMatriz(a, linhas1, colunas1);
  printf("\nMATRIZ B\n");
  imprimirMatriz(b, linhas2, colunas2);

  multiplicarMatrizes(
      a, linhas1, colunas1,
      b, linhas2, colunas2,
      c);

  printf("\nMATRIZ C\n");
  imprimirMatriz(c, linhas1, colunas2);

  return 0;
}

void imprimirMatriz(int matriz[][COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
      printf("%4d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void preencherMatriz(int matriz[][COLUNAS], int linhas, int colunas) {
  printf("Digite os valores para preencher a matriz\n");
  for (int i = 0; i < linhas; ++i)
  {
    for (int j = 0; j < colunas; ++j) {
      printf("matriz[%d][%d] = ", i + 1, j + 1);
      scanf("%d", &matriz[i][j]);
    }
  }
}

void preencherMatrizAleatoria(int matriz[][COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
      matriz[i][j] = rand() % (2 * linhas * colunas) + 1;
    }
  }
}

void multiplicarMatrizes(
  int a[][COLUNAS], int linhas1, int colunas1,
  int b[][COLUNAS], int linhas2, int colunas2,
  int c[][COLUNAS])
{
  if (colunas1 != linhas2) {
    printf("ERRO: Não é possível multiplicar essas matrizes!\n");
    return;
  }

  for (int i = 0; i < linhas1; ++i) {
    for (int j = 0; j < colunas2; ++j) {
      c[i][j] = 0;
      for (int k = 0; k < colunas1; ++k) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}
