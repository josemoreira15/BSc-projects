/**
 * @file parse.c
 *
 * \brief Função que diz respeito ao parser
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "parse.h"
#include "stack.h"
#include "maths.h"
/**
 * \brief Função find, verifica se o token pertence a um dos "dicionários".
 *
 * @param[in] *token Apontador para o token
 * @param[in] *dic Apontador para o dicionário
 * 
 * @return r 1 caso seja sucedido
 */
int find(char *token, char *dic){
    int i = 0, r = 0;
    int length = strlen(dic);

    for(i = 0; i < length; i++){
        if(dic[i] == *token){
            r = 1;
            break;
        }
    }

    return r;
}

/**
 * \brief Função find_Ascci, verifica se o token pertence a um intervalo da tabela Ascii.
 *
 * @param[in] *token Apontador para o token
 * @param[in] inf Base tabela Ascii
 * @param[in] sup Topo tabela Ascii
 * 
 * @return r 1 caso seja sucedido
 */
int find_Ascii(char *token, int inf, int sup){
    int r = 0;

    if((long) *token >= inf && (long) *token <= sup) r = 1;

    return r;
}

/**
 * \brief Função op_ascii1.
 *
 * @param[in] *s Apontador para a stack
 * @param[in] token Operador.
 * 
 */
void op_ascii1(STACK *s, char token){
    switch(token){
        case('!'): exclamacao(s);break;
        case('#'): expoente(s);break;
        case('$'): dollar(s);break;
        case('%'): modulo(s);break;
        case('&'): e(s);break;
        case('('): decrementa(s);break;
        case(')'): incrementa(s);break;
        case('*'): multiplica(s);break;
        case('+'): soma(s);break;
        case('-'): subtrai(s);break;
    }
}

/**
 * \brief Função op_ascii2.
 *
 * @param[in] *s Apontador para a stack
 * @param[in] token Operador
 * 
 */
void op_ascii2(STACK *s,char *token,double *dnum, char *vchar){
    switch(token[0]){
        case('/'): dividir(s);break;
        case(':'): doisL(s, token, dnum, vchar);break;
        case(';'): Pop(s);break;
        case('<'): menor(s);break;
        case('='): igual(s);break;
        case('>'): maior(s);break;
        case('?'): interrogacao(s);break;
        case('@'): rodar(s);break;
    }
}

/**
 * \brief Função op_ascii3.
 *
 * @param[in] *s Apontador para a stack
 * @param[in] token Operador
 * 
 */
void op_ascii3(STACK *s, char token){
    switch(token){
        case('\\'): trocar(s);break;
        case('^'): xorr(s);break;
        case('_'): duplicar(s);break;
    }
}

/**
 * \brief Função op_ascii3.
 *
 * @param[in] *s Apontador para a stack
 * @param[in] token Operador
 * 
 */
void op_ascii4(STACK *s, char token){
    switch(token){
        case('|'): ou(s);break;
        case('~'): nott(s);break;
    }
}

/**
 * \brief Função op_linhas, Função responsável apenas pelas operações em linhas.
 *
 * @param[in] *s Apontador para a stack
 * @param[in] token Operador relativo às linhas
 * 
 */
void op_linhas(STACK *s, char token){
    switch(token){
        case('l'): readLine(s);break;
        case('i'): toInt(s);break;
        case('c'): toChar(s);break;
        case('f'): toDouble(s);break;
    }
}

/**
 * \brief Função op_es, Função responsável apenas pelas operações shortcut.
 *
 * @param[in] *s Apontador para a stack
 * @param[in] token Operador "shortcut"
 * 
 */
void op_es(STACK *s, char *token){
    if(strcmp(token, "e&") == 0) e_shortcut(s);
    else if(strcmp(token, "e|") == 0) ou_shortcut(s);
    else if(strcmp(token, "e<") == 0) e_menor(s);
    else if(strcmp(token, "e>") == 0) e_maior(s);
}

/**
 * \brief Esta é a função que vai fazer o parse de uma linha
 *
 * @param[in] line A linha que foi lida e da qual se vai fazer o parse
 */
void parse(char *line) {
    char *delims = " \t\n";
    char *dic_linhas = "lifc";
    char *dic_es[] = {"e&", "e>", "e|", "e<"};

    double dnum[26]= {10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2};
    char vchar[26]={'l','l','l','l','l','l','l','l','l','l','l','l','l','\n','l','l','l','l',' ','l','l','l','l','l','l','l'};

    STACK *s = new_stack();

    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra1;
        char *sobra2;

        long val_l = strtol(token, &sobra1, 10);
        double val_d = strtod(token, &sobra2);

        if(strlen(sobra1) == 0) {
            push_LONG(s, val_l);
        }
        else if(strlen(sobra2) == 0) {
            push_DOUBLE(s, val_d);
        }
        else if (find_Ascii(token, 33, 45)) { 
            op_ascii1(s, *token);
        }
        else if (find_Ascii(token, 47, 64)) {
            op_ascii2(s, token,dnum, vchar);
        }
        else if (find_Ascii(token, 65, 90)) {
            letra(s, token,dnum, vchar);
        }
        else if (find_Ascii(token, 91, 96)) {
            op_ascii3(s, *token);
        }
        else if (find_Ascii(token, 123, 126)) {
            op_ascii4(s, *token);
        }
        else if (find(token, dic_linhas)) {
            op_linhas(s, *token);
        }
        else if (find(token, *dic_es)) {
            op_es(s, token);
        }
    }
    print_stack(s);
}
