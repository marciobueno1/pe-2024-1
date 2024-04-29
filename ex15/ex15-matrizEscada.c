#include <stdio.h>

#define LINHAS 500
#define COLUNAS 500

void lerMatriz(int mat[][COLUNAS], int linhas, int colunas);
int matrizEscada(int mat[][COLUNAS], int linhas, int colunas);

int main() {
  int n, m;
  int matriz[LINHAS][COLUNAS];
  scanf("%d", &n);
  scanf("%d", &m);
  lerMatriz(matriz, n, m);
  if (matrizEscada(matriz, n, m)) {
    printf("S\n");
  } else {
    printf("N\n");
  }
  return 0;
}

void lerMatriz(int mat[][COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
      scanf("%d", &mat[i][j]);
    }
  }
}

int matrizEscada(int mat[][COLUNAS], int linhas, int colunas) {
  int i, j, ehEscada = 1, primNaoNulo = -1;
  for (i = 0; i < linhas; ++i) {
    for (j = 0; j < colunas; ++j) {
      if (mat[i][j] != 0) {
        if (j <= primNaoNulo) {
          ehEscada = 0;
        } else {
          primNaoNulo = j;
        }
        break;
      }
    }
    if (!ehEscada) {
      break;
    }
    if (j == colunas) {
      primNaoNulo = j;
    }
  }

  return ehEscada;
}