#include "stdio.h"

int main() {
  int num1;
  printf("num1 = %d\n", num1);
  num1 = 10;
  printf("num1 = %d\n", num1);
  printf("num1 = %f\n", num1);
  printf("Olá Turma!\n");

  float d = 0.0, inc = 0.1;
  for (int i = 0; i < 100; ++i)
  {
    printf("%f\n", d);
    d += inc;
  }
    return 0;
}
