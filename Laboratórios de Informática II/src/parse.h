/**
 * @file parse.h
 *
 * \brief Função que diz respeito ao parser
 */
#include "stack.h"

int find(char *token, char *dic);

int find_Ascii(char *token, int inf, int sup);

void parse (char *);

void op_ascii1(STACK *s, char token);

void op_ascii2(STACK *s,char *token,double *dnum, char *vchar);

void op_ascii3(STACK *s, char token);

void op_ascii4(STACK *s, char token);

void op_linhas(STACK *s, char token);

void op_es(STACK *s, char *token);
