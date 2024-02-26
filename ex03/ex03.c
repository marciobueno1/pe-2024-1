#include <stdio.h>

int main() {
  int qtd;
  int numeros[10];
  double media = 0.0;

  do {
    printf("Você quer tirar a média de quantos números? (valor entre 1 e 10): ");
    scanf("%d", &qtd);
  } while (qtd < 1 || qtd > 10);

  printf("\nRealizando a média de %d números\n", qtd);

  for (int i = 0; i < qtd; ++i) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &numeros[i]);
    media += numeros[i];
  }
  
  media /= qtd;
  printf("A média dos números digitados é %lf\n", media);

  printf("\nNúmeros maiores que a média\n");

  for (int i = 0; i < qtd; ++i) {
    if (numeros[i] > media) {
      printf("%dº número é maior que a média: %d\n", i + 1, numeros[i]);
    }
  }


  return 0;
}
