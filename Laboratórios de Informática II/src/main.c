/**
 * @file main.c
 *
 * \brief Ficheiro principal do projeto (main)
 */
#include <stdio.h>
#include "parse.h"

/**
 * Esta é a função principal do programa.
 *
 * @returns O valor 0
 */
int main() {
  char buf[BUFSIZ];
  parse(fgets(buf, BUFSIZ, stdin));
  return 0;
}
