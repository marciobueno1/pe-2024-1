#include <stdio.h>

int main() {
  int qtd, num;
  double media = 0.0;

  // do {
  //   printf("Você quer tirar a média de quantos números? (valor maior que 0): ");
  //   scanf("%d", &qtd);
  // } while (qtd < 1);

  printf("Você quer tirar a média de quantos números? (valor maior que 0): ");
  scanf("%d", &qtd);
  while (qtd < 1) {
    printf("Valor ínválido.\nVocê quer tirar a média de quantos números? (valor maior que 0): ");
    scanf("%d", &qtd);
  }

  printf("Realizando a média de %d números\n", qtd);

  for (int i = 1; i <= qtd; ++i) {
    printf("Digite o %dº número inteiro: ", i);
    scanf("%d", &num);
    media += num;
  }
  
  media /= qtd;
  printf("A média dos números digitados é %lf\n", media);
 
  return 0;
}
