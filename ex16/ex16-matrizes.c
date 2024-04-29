#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 100
#define COLUNAS 100

void preencherMatrizAleatoria(int mat[][COLUNAS], int linhas, int colunas);
void preencherAlgunsValores(int mat[][COLUNAS], int linhas, int colunas);
void imprimirMatriz(int mat[][COLUNAS], int linhas, int colunas);
void zerarAbaixoDiagonalPrincipal(int mat[][COLUNAS], int ordem);
void zerarAbaixoDiagonalPrincipalEficiente(int mat[][COLUNAS], int ordem);
void zerarDiagonalSecundaria(int mat[][COLUNAS], int ordem);
void zerarAbaixoDiagonalSecundariaEficiente(int mat[][COLUNAS], int ordem);
void imprimirTotalPorColuna(int mat[][COLUNAS], int linhas, int colunas);

int main() {
  int mat[LINHAS][COLUNAS];
  int linhas, colunas;
  // srand(time(NULL));
  srand(7);
  printf("Valor de RAND_MAX: %d\n", RAND_MAX);
  do
  {
    printf("Digite o número de linhas da matriz (1-%d): ", LINHAS);
    scanf("%d", &linhas);
  } while (linhas < 1 || linhas > LINHAS);
  do {
    printf("Digite o número de colunas da matriz (1-%d): ", COLUNAS);
    scanf("%d", &colunas);
  } while (colunas < 1 || colunas > COLUNAS);

  preencherMatrizAleatoria(mat, linhas, colunas);
  // preencherAlgunsValores(mat, linhas, colunas);
  imprimirMatriz(mat, linhas, colunas);
  printf("\n");
  imprimirTotalPorColuna(mat, linhas, colunas);
  // zerarAbaixoDiagonalSecundariaEficiente(mat, linhas);
  // imprimirMatriz(mat, linhas, colunas);
  return 0;
}

void preencherMatrizAleatoria(int mat[][COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
      mat[i][j] = (rand() % (linhas * colunas)) + 1;
    }
  }
}

void preencherAlgunsValores(int mat[][COLUNAS], int linhas, int colunas) {
  int l, c;
  for (int i = 0; i < (colunas * linhas) / 2; ++i) {
    l = rand() % (linhas - 1);
    c = rand() % (colunas - 1);
    mat[l][c] = (rand() % (linhas * colunas)) + 1;
  }
}


void imprimirMatriz(int mat[][COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
      printf("%4d ", mat[i][j]);
    }
    printf("\n");
  }
}

void zerarAbaixoDiagonalPrincipal(int mat[][COLUNAS], int ordem) {
  for (int i = 0; i < ordem; ++i) {
    for (int j = 0; j < ordem; ++j) {
      if (i > j) {
        mat[i][j] = 0;
      }
    }
  }
}

void zerarAbaixoDiagonalPrincipalEficiente(int mat[][COLUNAS], int ordem) {
  for (int i = 1; i < ordem; ++i) {
    for (int j = 0; j < i; ++j) {
      mat[i][j] = 0;
    }
  }
}

void zerarDiagonalSecundaria(int mat[][COLUNAS], int ordem) {
  for (int i = 0; i < ordem; ++i) {
    for (int j = 0; j < ordem; ++j) {
      if (i + j == ordem - 1) {
        mat[i][j] = 0;
      }
    }
  }
}

void zerarAbaixoDiagonalSecundariaEficiente(int mat[][COLUNAS], int ordem) {
  for (int i = 1; i < ordem; ++i) {
    for (int j = ordem - i; j < ordem; ++j) {
      mat[i][j] = 0;
    }
  }
}

void imprimirTotalPorColuna(int mat[][COLUNAS], int linhas, int colunas) {
  int soma;
  for (int j = 0; j < colunas; ++j) {
    soma = 0;
    for (int i = 0; i < linhas; ++i) {
      soma += mat[i][j];
    }
    printf("%4d ", soma);
  }
  printf("\n");
}
