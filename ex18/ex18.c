#include <stdio.h>

void trocaPassagemValor(int a, int b);
void trocaPassagemReferencia(int *a, int *b);
void trocaVetor(int v[2]);

int main() {
  int num1 = 10, num2 = 20;
  printf("main antes de trocaPassagemValor: valor de num1 = %d - valor de num2 = %d\n", num1, num2);
  trocaPassagemValor(num1, num2);
  printf("main apos trocaPassagemValor: valor de num1 = %d - valor de num2 = %d\n", num1, num2);

  printf("\n\nmain antes de trocaPassagemReferencia: valor de num1 = %d - valor de num2 = %d\n", num1, num2);
  trocaPassagemReferencia(&num1, &num2);
  printf("main apos trocaPassagemReferencia: valor de num1 = %d - valor de num2 = %d\n", num1, num2);

  int vet[2];
  vet[0] = 10;
  vet[1] = 20;
  printf("\n\nmain antes de trocaVetor: valor de vet[0] = %d - valor de vet[1] = %d\n", vet[0], vet[1]);
  trocaVetor(vet);
  printf("main apos de trocaVetor: valor de vet[0] = %d - valor de vet[1] = %d\n", vet[0], vet[1]);
  return 0;
}

void trocaPassagemValor(int a, int b) {
  printf("inicio trocaPassagemValor: valor de a = %d - valor de b = %d\n", a, b);
  int aux = a;
  a = b;
  b = aux;
  printf("final trocaPassagemValor: valor de a = %d - valor de b = %d\n", a, b);
}

void trocaPassagemReferencia(int *a, int *b) {
  printf("inicio trocaPassagemValor: valor de a = %d - valor de b = %d\n", *a, *b);
  int aux = *a;
  *a = *b;
  *b = aux;
  printf("final trocaPassagemValor: valor de a = %d - valor de b = %d\n", *a, *b);
}

void trocaVetor(int v[2]) {
  printf("inicio trocaVetor: valor de v[0] = %d - valor de v[1] = %d\n", v[0], v[1]);
  int aux = v[0];
  v[0] = v[1];
  v[1] = aux;
  printf("final trocaVetor: valor de v[0] = %d - valor de v[1] = %d\n", v[0], v[1]);
  v = NULL;
}