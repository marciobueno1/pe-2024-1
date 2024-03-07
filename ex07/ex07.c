#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int v[], int qtd);

int main() {
  int qtd;

  do {
    printf("Qual o tamanho dos vetores? (valor maior que 0): ");
    scanf("%d", &qtd);
  } while (qtd < 1);

  int *a, *b, *soma;
  a = (int *) malloc(qtd * sizeof(int));
  b = (int *) malloc(qtd * sizeof(int));
  soma = (int *) malloc(qtd * sizeof(int));

  printf("Digitação dos valores do vetor A\n");
  for (int i = 0; i < qtd; ++i) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &a[i]);
  }

  printf("\nDigitação dos valores do vetor B\n");
  for (int i = 0; i < qtd; ++i) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &b[i]);
  }

  // cálculo do vetor soma
  for (int i = 0; i < qtd; ++i) {
    soma[i] = a[i] + b[i];
  }

  printf("\nImpressão dos vetores\n");
  printf("A = ");
  imprimirVetor(a, qtd);
  printf("B = ");
  imprimirVetor(b, qtd);
  printf("S = ");
  imprimirVetor(soma, qtd);

  free(a);
  free(b);
  free(soma);
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