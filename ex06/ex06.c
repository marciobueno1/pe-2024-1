#include <stdio.h>
#include <math.h>

#define CAPAC_VETOR 10

void imprimirVetor(int v[], int qtd);

int main() {
  int qtd;
  int a[CAPAC_VETOR], b[CAPAC_VETOR], soma[CAPAC_VETOR];

  do {
    printf("Qual o tamanho dos vetores? (valor entre 1 e %d): ", CAPAC_VETOR);
    scanf("%d", &qtd);
  } while (qtd < 1 || qtd > CAPAC_VETOR);

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