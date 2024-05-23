#include <stdio.h>

#define TAM_NOME 3
#define QTD_ESTADOS 2

struct VeiculosEstado {
  char nome[TAM_NOME];
  int qtdVeiculos;
  int qtdAcidentes;
};

void lerInfoEstados(struct VeiculosEstado estados[], int tam);
void lerString(char *str, int maxTam);
void maiorMenorNumeroAcidentes(
    struct VeiculosEstado estados[],
    int tam,
    int *indiceMaiorQtdAcid,
    int *indiceMenorQtdAcid);
void imprimirRegistro(struct VeiculosEstado estado);

int main() {
  int indiceMaiorQtdAcid, indiceMenorQtdAcid;
  struct VeiculosEstado estados[QTD_ESTADOS];
  lerInfoEstados(estados, QTD_ESTADOS);
  maiorMenorNumeroAcidentes(estados, QTD_ESTADOS, &indiceMaiorQtdAcid, &indiceMenorQtdAcid);
  printf("Estado com a maior quantidade de acidentes\n");
  imprimirRegistro(estados[indiceMaiorQtdAcid]);
  printf("\n\nEstado com a menor quantidade de acidentes\n");
  imprimirRegistro(estados[indiceMenorQtdAcid]);
  return 0;
}

void lerInfoEstados(struct VeiculosEstado estados[], int tam) {
  for (int i = 0; i < tam; ++i) {
    printf("Digite o nome do estado %d: ", i + 1);
    lerString(estados[i].nome, TAM_NOME);
    printf("Digite a quantidade de veículos do estado %s: ", estados[i].nome);
    scanf("%d", &estados[i].qtdVeiculos);
    printf("Digite a quantidade de acidentes do estado %s: ", estados[i].nome);
    scanf("%d", &estados[i].qtdAcidentes);
    while (getchar() != '\n');
  }
}

void maiorMenorNumeroAcidentes(
  struct VeiculosEstado estados[],
  int tam,
  int *indiceMaiorQtdAcid,
  int *indiceMenorQtdAcid)
{
  *indiceMaiorQtdAcid = 0;
  *indiceMenorQtdAcid = 0;
  for (int i = 1; i < tam; ++i) {
    if (estados[i].qtdAcidentes > estados[*indiceMaiorQtdAcid].qtdAcidentes) {
      *indiceMaiorQtdAcid = i;
    } else if (estados[i].qtdAcidentes < estados[*indiceMenorQtdAcid].qtdAcidentes) {
      *indiceMenorQtdAcid = i;
    }
  }
}

void imprimirRegistro(struct VeiculosEstado estado) {
  printf("-------------------------------------\n");
  printf("Estado: %s\n", estado.nome);
  printf("Qtd veiculos: %d\n", estado.qtdVeiculos);
  printf("Qtd acidentes: %d\n", estado.qtdAcidentes);
  printf("-------------------------------------\n");
}

void lerString(char *str, int maxTam) {
    fgets(str, maxTam, stdin);
    int tam = strlen(str);
    if (str[tam - 1] == '\n') {
      str[tam - 1] = '\0';
    }
}
