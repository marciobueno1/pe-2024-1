#include <stdio.h>
#include <math.h>

#define TAM_VETOR 10

int main() {
  int qtd;
  int a[TAM_VETOR], b[TAM_VETOR], soma[TAM_VETOR];

  do {
    printf("Qual o tamanho dos vetores? (valor entre 1 e %d): ", TAM_VETOR);
    scanf("%d", &qtd);
  } while (qtd < 1 || qtd > TAM_VETOR);

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

  printf("\nImpressão do vetor soma\n");
  for (int i = 0; i < qtd; ++i) {
    printf("soma[%d] = %d\n", i + 1, soma[i]);
  }

  return 0;
}
