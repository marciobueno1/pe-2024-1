#include <stdio.h>
#include <math.h>

#define TAM_VETOR 10

int main() {
  int somatorio = 0, qtd;
  int numeros[TAM_VETOR];
  double media = 0.0, somatorioQuadrado = 0.0, desvioPadrao;

  do {
    printf("Você quer tirar a média de quantos números? (valor entre 1 e %d): ", TAM_VETOR);
    scanf("%d", &qtd);
  } while (qtd < 1 || qtd > TAM_VETOR);

  printf("\nRealizando a média de %d números\n", qtd);

  for (int i = 0; i < qtd; ++i) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &numeros[i]);
    somatorio += numeros[i];
  }
  
  media = (double) somatorio / (double) qtd;
  printf("A média dos números digitados é %lf\n", media);

  printf("\nNúmeros maiores que a média\n");

  for (int i = 0; i < qtd; ++i) {
    if (numeros[i] > media) {
      printf("%dº número é maior que a média: %d\n", i + 1, numeros[i]);
    }
  }

  // cálculo do desvio padrão
  for (int i = 0; i < qtd; ++i) {
    somatorioQuadrado += pow(numeros[i] - media, 2);
  }

  desvioPadrao = sqrt(somatorioQuadrado / qtd);
  printf("O desvio padrão é %lf\n\n", desvioPadrao);

  return 0;
}
