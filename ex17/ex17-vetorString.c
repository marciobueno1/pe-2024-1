#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define QTD_STRINGS 5
#define QTD_CARACTERES 10

void lerString(char *str, int maxTam);

int main() {
  char codigos[QTD_STRINGS][QTD_CARACTERES];
  for (int i = 0; i < QTD_STRINGS; i++) {
    printf("Informe o código %i: ", i+1);
    lerString(codigos[i], QTD_CARACTERES);
  }

  printf("\n\nIMPRESSÃO:\n");
  for (int i = 0; i < QTD_STRINGS; i++) {
    printf("Código %i: %s\n", i+1, codigos[i]);
  }

  return 0;
}

void lerString(char *str, int maxTam) {
    fgets(str, maxTam, stdin);
    int tam = strlen(str);
    if (str[tam - 1] == '\n') {
      str[tam - 1] = '\0';
    }
}
