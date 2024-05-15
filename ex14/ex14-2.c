#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_FRASE 100
#define QTD_VOGAIS 5

int isVowel(char c);
void replaceVowelWithAsterisk(char *frase);

int main() {
  char frase[TAM_FRASE];
  printf("Digite sua frase: ");
  fgets(frase, TAM_FRASE, stdin); // essa função é mais segura que a função 'gets'
  frase[strlen(frase) - 1] = '\0'; // remover o \n do final da string
  replaceVowelWithAsterisk(frase);
  printf("%s\n", frase);
}

int isVowel(char c) {
  char vogais[QTD_VOGAIS] = {
    'a', 'e', 'i', 'o', 'u'
    // 'á', 'â', 'ã', 'à'
    // ...
  };
  c = tolower(c);
  for (int i = 0; i < QTD_VOGAIS; ++i) {
    if (c == vogais[i]) {
      return 1;
    }
  }

  return 0;

  // return (c == 'a' ||
  //         c == 'e' ||
  //         c == 'i' ||
  //         c == 'o' ||
  //         c == 'u'
  // );
}

void replaceVowelWithAsterisk(char *frase) {
  int tam = strlen(frase);
  for (int i = 0; i < tam; ++i) {
    if (isVowel(frase[i])) {
      frase[i] = '*';
    }
  }
}
