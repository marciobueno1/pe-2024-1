#include <stdio.h>
#include <math.h>

#define CAPAC_VETOR 10

void imprimirVetor(int v[], int qtd);
void inverterVetorCopia(int v[], int inv[], int qtd);
void inverterVetor(int v[], int qtd);

int main() {
  int qtd;
  int a[CAPAC_VETOR], invertido[CAPAC_VETOR];

  do {
    printf("Qual o tamanho dos vetores? (valor entre 1 e %d): ", CAPAC_VETOR);
    scanf("%d", &qtd);
  } while (qtd < 1 || qtd > CAPAC_VETOR);

  printf("Digitação dos valores do vetor A\n");
  for (int i = 0; i < qtd; ++i) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &a[i]);
  }

  printf("\nImpressão dos vetores\n");
  printf("A = ");
  imprimirVetor(a, qtd);

  inverterVetorCopia(a, invertido, qtd);

  printf("INVERTIDO CÓPIA = ");
  imprimirVetor(invertido, qtd);

  inverterVetor(a, qtd);

  printf("INVERTIDO = ");
  imprimirVetor(a, qtd);

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

void inverterVetorCopia(int v[], int inv[], int qtd) {
    for (int i = 0; i < qtd; ++i) {
      inv[qtd - 1 - i] = v[i];
    }
}

void inverterVetor(int v[], int qtd) {
  int aux;
  for (int i = 0; i < qtd / 2; ++i) {
    aux = v[i];
    v[i] = v[qtd - 1 - i];
    v[qtd - 1 - i] = aux;
    imprimirVetor(v, qtd);
  }
}
