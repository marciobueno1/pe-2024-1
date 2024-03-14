#include <stdio.h>
#include <stdlib.h>

#define CAPAC_VETOR 500000
#define MAX_NUM_RAND 1000

void preencherAleatorio(int v[], int qtd);
void imprimirVetor(int v[], int qtd);
void insertionSort(int v[], int qtd);

int main() {
  char opcao;
  int qtd, num, pos;
  int v[CAPAC_VETOR];

  do {
    printf("Qual o tamanho do vetor? (valor entre 1 e %d): ", CAPAC_VETOR);
    scanf("%d", &qtd);
  } while (qtd < 1 || qtd > CAPAC_VETOR);

  printf("Digitação dos valores do vetor V\n");
  preencherAleatorio(v, qtd);

  printf("\nImpressão do vetor original\n");
  printf("V = ");
  imprimirVetor(v, qtd);

  insertionSort(v, qtd);

  printf("\nImpressão do vetor ordenado\n");
  printf("V = ");
  imprimirVetor(v, qtd);

  return 0;
}

void imprimirVetor(int v[], int qtd) {
  printf("[");
  if (qtd > 0) {
    printf("%d", v[0]);
    for (int i = 1; i < qtd; ++i) {
      printf(", %d", v[i]);
    }
  }
  printf("]\n");
}

void insertionSort(int v[], int qtd) {
  int atual, j;
  for (int i = 1; i < qtd; ++i) {
    atual = v[i];
    j = i - 1;
    while (j >= 0 && atual < v[j]) {
      v[j + 1] = v[j];
      j = j - 1;
    }
    v[j + 1] = atual;
  }
}

// https://en.cppreference.com/w/c/numeric/random/rand
void preencherAleatorio(int v[], int qtd) {
  for (int i = 0; i < qtd; ++i) {
    // v[i] = 1 + rand()/((RAND_MAX + 1u)/MAX_NUM_RAND);
    v[i] = 1 + rand() % MAX_NUM_RAND;
  }
}