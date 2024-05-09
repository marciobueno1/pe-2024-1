#include <stdio.h>

#define QTD_STRINGS 5
#define QTD_CARACTERES 10

int main() {
  char codigos[QTD_STRINGS][QTD_CARACTERES];
  for (int i = 0; i < QTD_STRINGS; i++) {
    printf("Informe o código %i: ", i+1);
    fgets_s(codigos[i], QTD_CARACTERES, stdin);
    int tam = strlen(codigos[i]);
    if (codigos[i][tam - 1] == '\n') {
      codigos[i][tam - 1] = '\0';
    }
  }
  
}