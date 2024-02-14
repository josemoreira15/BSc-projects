/**
 * @file maths.h
 *
 * \brief Funções relativas ao ficheiro math.c
 */
#include "stack.h"

//void init_DATA(STACK *s, DATA E, double *v);

void soma(STACK *s);

void subtrai(STACK *s);

void multiplica(STACK *s);

void dividir(STACK *s);

void decrementa(STACK *s);

void incrementa(STACK *s);

void modulo(STACK *s);

void expoente(STACK *s);

void e(STACK *s); 

void e_shortcut(STACK *s); 

void ou(STACK *s);

void ou_shortcut(STACK *s);

void xorr(STACK *s);
  
void nott(STACK *s);

void dollar(STACK *s);

void duplicar(STACK *s);

void Pop(STACK *s);

void trocar(STACK *s);

void rodar(STACK *s);

void interrogacao(STACK *s);

void igual(STACK *s);

void exclamacao(STACK *s);

void maior (STACK *s);

void menor (STACK *s);

void e_menor (STACK *s);

void e_maior (STACK *s);

void toInt (STACK *s);

void toDouble (STACK *s);

void toChar (STACK *s); 

void readLine (STACK *s);

void doisL (STACK *s,char *token, double *dnum, char *vchar);

void letra (STACK *s,char *token, double *dnum, char *vchar);
