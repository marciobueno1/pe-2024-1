#include <stdio.h>
#include <math.h>

#define CAPAC_VETOR 10

void imprimirVetor(int v[], int qtd);
int pesquisar(int v[], int qtd, int valor);

int main() {
  char opcao;
  int qtd, num, pos;
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

  do {
    printf("Digite o valor que deseja pesquisar: ");
    scanf("%d", &num);
    pos = pesquisar(a, qtd, num);
    if (pos != -1) {
      printf("O valor %d está na posição %d\n", num, pos + 1);
    } else {
      printf("O valor %d não está presente no vetor!\n", num);
    }
    printf("Deseja pesquisar mais algum valor (s/n): ");
    // fflush(stdin); // não funciona no LINUX
    scanf("%c", &opcao); // desprezar o ENTER da digitação anterior
    scanf("%c", &opcao);
  } while (opcao == 's');
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

int pesquisar(int v[], int qtd, int valor) {
  for (int i = 0; i < qtd; ++i) {
    if (v[i] == valor) {
      return i;
    }
  }
  return -1;
}