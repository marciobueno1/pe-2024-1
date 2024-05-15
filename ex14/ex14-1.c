#include <stdio.h>
#include <string.h>

#define TAM_NOME 50

int tamanhoStr(char *str);

int main() {
  char nome[TAM_NOME];
  printf("Digite seu nome: ");
  fgets(nome, TAM_NOME, stdin); // essa função é mais segura que a função 'gets'
  nome[strlen(nome) - 1] = '\0'; // remover o \n do final da string
  printf("Nome digitado: -->%s<--\n", nome);

  printf("O tamanho da string digitada é: %d\n", tamanhoStr(nome));
  printf("O tamanho da string digitada é: %ld\n", strlen(nome));
  return 0;
}

int tamanhoStr(char *str) {
  int qtd = 0;
  while (str[qtd] != '\0') {
    ++qtd;
  }
  return qtd;
}