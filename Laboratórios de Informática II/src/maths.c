/**
 * @file maths.c
 *
 * \brief Funções relativas ao ficheiro math.c
 */

#include "maths.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
void init_DATA(STACK *s, DATA E, double *v){
    if((has_type(top(s), LONG))) {
        E.type = LONG;
        E.LONG = pop_LONG(s);
        *v = E.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        E.type = DOUBLE;
        E.DOUBLE = pop_DOUBLE(s);
        *v = E.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        E.type = CHAR;
        E.CHAR = pop_CHAR(s);
        *v = (long) E.CHAR;
    }
}*/

/**
 * \brief Função soma, soma os últimos dois valores da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void soma(STACK *s){
    // X argument
    DATA x;
    double f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    
    DATA y;
    double t = 0;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
        t = y.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
        t = y.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
        t = (long) y.CHAR;
    }

    double result = t + f;


    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, result);
    }
    else push_DOUBLE(s, result);
}

/**
 * \brief Função subtrai, subtrai os últimos dois valores da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void subtrai(STACK *s){
    DATA x;
    double f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    
    DATA y;
    double t = 0;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
        t = y.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
        t = y.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
        t = (long) y.CHAR;
    }

    double result = t - f;

    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, result);
    }
    else push_DOUBLE(s, result);
}

/**
 * \brief Função multiplica, multiplica os últimos dois valores da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void multiplica(STACK *s){
    DATA x;
    double f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    
    DATA y;
    double t = 0;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
        t = y.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
        t = y.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
        t = (long) y.CHAR;
    }

    double result = t * f;

    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, (long)result);
    }
    else push_DOUBLE(s, result);
}

/**
 * \brief Função dividir, divide os últimos dois valores da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void dividir(STACK *s){
    DATA x;
    double f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    
    DATA y;
    double t = 0;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
        t = y.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
        t = y.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
        t = (long) y.CHAR;
    }

    double result = t / f;

    if(has_type(x, LONG) && has_type(y, LONG)){
        push_LONG(s, result);
    }
    else push_DOUBLE(s, result);
}

/**
 * \brief Função decrementa, decrementa uma unidade ao valor do topo da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void decrementa(STACK *s){
    DATA x;
    double f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long)x.CHAR;
    }

    double result = f - 1;

    if(has_type(x, LONG)){
        push_LONG(s, result);
    }
    else if(has_type(x, CHAR)){
        push_CHAR(s, (char)result);
    }
    else push_DOUBLE(s, result);
}

/**
 * \brief Função incrementa, incrementa uma unidade ao valor do topo da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void incrementa(STACK *s){
    // X argument
    DATA x;
    double f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long)x.CHAR;
    }

    double result = f + 1 ;

    if(has_type(x, LONG)){
        push_LONG(s, result);
    }
    else if(has_type(x, CHAR)){
        push_CHAR(s, (char)result);
    }
    else push_DOUBLE(s, result);
}

/**
 * \brief Função modulo, divisão inteira dos últimos dois valores da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void modulo(STACK *s){
    // X argument
    DATA x;
    int f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    DATA y;
    int t = 0;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
        t = y.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
        t = y.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
        t = (long) y.CHAR;
    }

    double result = t % f;
    push_LONG(s, result);
}

/**
 * \brief Função expoente, exponenciação dos últimos dois valores da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void expoente(STACK *s){
    // X argument
    DATA x;
    double f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    DATA y;
    double t = 0;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
        t = y.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
        t = y.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
        t = (long) y.CHAR;
    }

    double exp = pow(t,f);

    if(has_type(x,LONG) && has_type(y,LONG)) {
        push_LONG(s, exp);
    }
    else push_DOUBLE(s, exp);
}

/**
 * \brief Função e, & lógico dos últimos dois valores da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void e(STACK *s){
    // X argument
    DATA x;
    int f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    DATA y;
    int t = 0;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
        t = y.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
        t = y.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
        t = (long) y.CHAR;
    }

    long result = t & f ;
    push_LONG(s, result);
}

/**
 * \brief Função e&, se A verdadeiro devolve B, caso contrário, devolve A.
 *
 * @param[in] *s Apontador para a stack
 */
void e_shortcut(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))) {
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else assert (0);

    DATA y;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))) {
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }
    else assert (0);

    if (has_type(y, LONG) && y.LONG > 0) push(s, x);
    else if (has_type(y, DOUBLE) && y.DOUBLE > 0) push(s, x);
    else push(s, y);
}


/**
 * \brief Função ou, | lógico dos últimos dois valores da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void ou(STACK *s){
    // X argument
    DATA x;
    int f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    DATA y;
    int t = 0;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
        t = y.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
        t = y.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
        t = (long) y.CHAR;
    }

    long result = t | f ;
    push_LONG(s, result);
}

/**
 * \brief Função e|, caso exista valor verdadeiro, devolve o primeiro. Caso contrário, devolve o último falso.
 *
 * @param[in] *s Apontador para a stack
 */
void ou_shortcut(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))) {
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else assert (0);

    DATA y;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))) {
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }
    else assert (0);

    if (has_type(y, LONG) && y.LONG > 0) push(s, y);
    else if (has_type(y, DOUBLE) && y.DOUBLE > 0) push(s, y);
    else push(s, x);
}

/**
 * \brief Função xorr, operador binário.
 *
 * @param[in] *s Apontador para a stack
 */
void xorr(STACK *s){
    // X argument
    DATA x;
    int f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    DATA y;
    int t = 0;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
        t = y.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
        t = y.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
        t = (long) y.CHAR;
    }

    long result = t ^ f ;
    push_LONG(s, result);
}

/**
 * \brief Função nott, operador binário.
 *
 * @param[in] *s Apontador para a stack
 */
void nott(STACK *s){
    // X argument
    DATA x;
    int f = 0;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        f = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        f = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        f = (long) x.CHAR;
    }

    long result = ~f ;
    push_LONG(s, result);
}

/**
 * \brief Função dollar, copia um elemento especifico para o topo da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void dollar (STACK *s){
    long x= pop_LONG(s);
    DATA aux[10], rep;
    long i;
    for(i=0; i<=x; i++){
        aux[i]=pop(s);
        if(i==x)
            rep=aux[i];
    }
    for(i=x;i>=0;i--){
        push(s, aux[i]);
    }
    push(s, rep);
}

/**
 * \brief Função duplicar, duplica o último elemento da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void duplicar(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if ((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
    }

    if(has_type(x, LONG)){
        long result = x.LONG ;
        push_LONG(s, result);
        push_LONG(s, result);
    }
    else if(has_type(x, DOUBLE)){
        double result = x.DOUBLE ;
        push_DOUBLE(s, result);
        push_DOUBLE(s, result);
    }
    else if(has_type(x, CHAR)){
        char result = x.CHAR ;
        push_CHAR(s, result);
        push_CHAR(s, result);
    }
}

/**
 * \brief Função Pop, faz pop do topo da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void Pop(STACK *s){
    pop(s);
}

/**
 * \brief Função trocar, troca os últimos dois elementos da stack.
 *
 * @param[in] *s Apontador para a stack
 */
void trocar(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
    }

    DATA y;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else if ((has_type(top(s), DOUBLE))) {
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
    }

    push(s, x);
    push(s, y);
}

/**
 * \brief Função rodar, roda os últimos três elementos para a esquerda.
 *
 * @param[in] *s Apontador para a stack
 */
void rodar(STACK *s) {
    // X argument
    DATA x;
    if ((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    } 
    else if ((has_type(top(s), DOUBLE))) {
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
    }

    DATA y;
    if ((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else if ((has_type(top(s), DOUBLE))){
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
    }

    DATA z;
    if ((has_type(top(s), LONG))) {
        z.type = LONG;
        z.LONG = pop_LONG(s);
    } 
    else if ((has_type(top(s), DOUBLE))){
        z.type = DOUBLE;
        z.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        z.type = CHAR;
        z.CHAR = pop_CHAR(s);
    }

    push(s, y);
    push(s, x);
    push(s, z);
}

/**
 * \brief Função interrogacao, if then else.
 *
 * @param[in] *s Apontador para a stack
 */
void interrogacao(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else {
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }

    
    DATA y;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else {
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }

    DATA z;
    if((has_type(top(s), LONG))) {
        z.type = LONG;
        z.LONG = pop_LONG(s);
    }
    else {
        z.type = DOUBLE;
        z.DOUBLE = pop_DOUBLE(s);
    }


    if((has_type(z, DOUBLE) && z.DOUBLE > 0) ||(has_type(z, LONG) && z.LONG > 0)){
        if (has_type(y, LONG)){
            push_LONG(s, y.LONG);
        }
        else push_DOUBLE(s, y.DOUBLE);
    }
    else {
        if (has_type(x, LONG))
        {
            push_LONG(s, x.LONG);
        }
        else push_DOUBLE(s, x.DOUBLE);
    }
}

/**
 * \brief Função igual, compara dois valores e retorna uma valoração.
 *
 * @param[in] *s Apontador para a stack
 */
void igual(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
    }

    DATA y;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else if ((has_type(top(s), DOUBLE))) {
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        y.type = CHAR;
        y.CHAR = pop_CHAR(s);
    }

    if (has_type(x, LONG) && has_type(y, LONG) && x.LONG == y.LONG){
        push_LONG(s, 1);
    }
    else if (has_type(x, DOUBLE) && has_type(y, DOUBLE) && x.DOUBLE == y.DOUBLE){
        push_LONG(s, 1);
    }
    else if (has_type(x, LONG) && has_type(y, DOUBLE) && (double)x.LONG == y.DOUBLE){
        push_LONG(s, 1);
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG) && x.DOUBLE == (double)y.LONG){
        push_LONG(s, 1);
    }
    else if (has_type(x, CHAR) && has_type(y, CHAR) && x.CHAR == y.CHAR){
        push_LONG(s, 1);
    }
    else push_LONG(s, 0);
}

/**
 * \brief Função exclamacao, todo valor verdadeiro passa para falso (vice-versa).
 *
 * @param[in] *s Apontador para a stack
 */
void exclamacao(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
    }
    
    if ((has_type(x, LONG) && x.LONG > 0) || (has_type(x, DOUBLE) && x.DOUBLE > 0) || (has_type(x, CHAR) && x.CHAR > 0))
         push_LONG(s, 0);
    else push_LONG(s, 1);  
}

/**
 * \brief Função maior, compara dois valores e dá push à valoração.
 *
 * @param[in] *s Apontador para a stack
 */
void maior(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        x.type = LONG;
        x.CHAR = pop_CHAR(s);
    }

    DATA y;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else if ((has_type(top(s), DOUBLE))) {
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        y.type = LONG;
        y.CHAR = pop_CHAR(s);
    }

    if (has_type(x, LONG) && has_type(y, LONG)){
        int r = y.LONG > x.LONG;
        if (r) push_LONG(s, r);
        else push_LONG(s, 0);
    }
    else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        int r = y.DOUBLE > x.DOUBLE;
        if (r) push_LONG(s, r);
        else push_LONG(s, 0);
    }
    else if (has_type(x, LONG) && has_type(y, DOUBLE)){
        int r = y.DOUBLE > x.LONG;
        if (r) push_LONG(s, r);
        else push_LONG(s, 0);
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        int r = y.LONG > x.DOUBLE;
        if (r) push_LONG(s, r);
        else push_LONG(s, 0);
    }
}

/**
 * \brief Função menor, compara dois valores e dá push à valoração.
 *
 * @param[in] *s Apontador para a stack
 */
void menor(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        x.type = LONG;
        x.CHAR = pop_CHAR(s);
    }

    DATA y;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else if ((has_type(top(s), DOUBLE))) {
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        y.type = LONG;
        y.CHAR = pop_CHAR(s);
    }

    if (has_type(x, LONG) && has_type(y, LONG)){
        int r = y.LONG < x.LONG;
        if (r) push_LONG(s, r);
        else push_LONG(s, 0);
    }
    else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        int r = y.DOUBLE < x.DOUBLE;
        if (r) push_LONG(s, r);
        else push_LONG(s, 0);
    }
    else if (has_type(x, LONG) && has_type(y, DOUBLE)){
        int r = y.DOUBLE < x.LONG;
        if (r) push_LONG(s, r);
        else push_LONG(s, 0);
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        int r = y.LONG < x.DOUBLE;
        if (r) push_LONG(s, r);
        else push_LONG(s, 0);
    }
}

/**
 * \brief Função doisL, altera o valor da letra para o introduzido.
 *
 * @param[in] *s Apontador para a stack
 * @param[in] *token Apontador para o token
 * @param[in] *dnum Apontador para array de doubles
 * @param[in] *vchar Apontador para array de char
 */
void doisL(STACK *s,char *token, double *dnum, char *vchar){
    char y = token[1];
    int i = (long) y - 65;
    
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
        vchar[i] = 'l';
        dnum[i] = x.LONG;
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
        vchar[i]  = 'd';
        dnum[i] = x.DOUBLE;
    }
    else if((has_type(top(s), CHAR))){
        x.type = CHAR;
        x.CHAR = pop_CHAR(s);
        vchar[i] = x.CHAR;
    }
    else if((has_type(top(s), STRING))){
        x.type = STRING;
        x.STRING = pop_STRING(s);
        vchar[i] = x.STRING[0];
    }
    push(s, x);
}
/**
 * \brief Função letra, dá push da letra em questão
 *
 * @param[in] *s Apontador para a stack
 * @param[in] *token Apontador para o token
 * @param[in] *dnum Apontador para array de doubles
 * @param[in] *vchar Apontador para array de char
 */
void letra(STACK *s,char *token, double *dnum, char *vchar){
    int i = (long) *token - 65;

    if (vchar[i] == 'd'){
        push_DOUBLE(s,dnum[i]);
    }
    else if(vchar[i] == 'l'){
        push_LONG(s,dnum[i]);
    }
    else push_CHAR(s, vchar[i]);
}

/**
 * \brief Função e_menor, compara dois valores e dá push ao menor.
 *
 * @param[in] *s Apontador para a stack
 */
void e_menor(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        x.type = LONG;
        x.CHAR = pop_CHAR(s);
    }

    DATA y;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else if ((has_type(top(s), DOUBLE))) {
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        y.type = LONG;
        y.CHAR = pop_CHAR(s);
    }

    if (has_type(x, LONG) && has_type(y, LONG)){
        int r = y.LONG < x.LONG;
        if (r) push_LONG(s, y.LONG);
        else push_LONG(s, x.LONG);
    }
    else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        int r = y.DOUBLE < x.DOUBLE;
        if (r) push_DOUBLE(s, y.DOUBLE);
        else push_DOUBLE(s, x.DOUBLE);
    }
    else if (has_type(x, LONG) && has_type(y, DOUBLE)){
        int r = y.DOUBLE < x.LONG;
        if (r) push_DOUBLE(s, y.DOUBLE);
        else push_LONG(s, x.LONG);
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        int r = y.LONG < x.DOUBLE;
        if (r) push_LONG(s, y.LONG);
        else push_DOUBLE(s, x.DOUBLE);
    }
}
/**
 * \brief Função e_maior, compara dois valores e dá push ao maior.
 *
 * @param[in] *s Apontador para a stack
 */
void e_maior(STACK *s){
    // X argument
    DATA x;
    if((has_type(top(s), LONG))) {
        x.type = LONG;
        x.LONG = pop_LONG(s);
    }
    else if((has_type(top(s), DOUBLE))){
        x.type = DOUBLE;
        x.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        x.type = LONG;
        x.CHAR = pop_CHAR(s);
    }

    DATA y;
    if((has_type(top(s), LONG))) {
        y.type = LONG;
        y.LONG = pop_LONG(s);
    }
    else if ((has_type(top(s), DOUBLE))) {
        y.type = DOUBLE;
        y.DOUBLE = pop_DOUBLE(s);
    }
    else if((has_type(top(s), CHAR))){
        y.type = LONG;
        y.CHAR = pop_CHAR(s);
    }

    if (has_type(x, LONG) && has_type(y, LONG)){
        int r = y.LONG > x.LONG;
        if (r) push_LONG(s, y.LONG);
        else push_LONG(s, x.LONG);
    }
    else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)){
        int r = y.DOUBLE > x.DOUBLE;
        if (r) push_DOUBLE(s, y.DOUBLE);
        else push_DOUBLE(s, x.DOUBLE);
    }
    else if (has_type(x, LONG) && has_type(y, DOUBLE)){
        int r = y.DOUBLE > x.LONG;
        if (r) push_DOUBLE(s, y.DOUBLE);
        else push_LONG(s, x.LONG);
    }
    else if (has_type(x, DOUBLE) && has_type(y, LONG)){
        int r = y.LONG > x.DOUBLE;
        if (r) push_LONG(s, y.LONG);
        else push_DOUBLE(s, x.DOUBLE);
    }
}

/**
 * \brief Função toInt, coverter o tipo para Int.
 *
 * @param[in] *s Apontador para a stack
 */
void toInt (STACK *s){
    DATA X = pop(s);
    if (has_type(X,DOUBLE)){
        long a = X.DOUBLE;
        push_LONG(s,a);
    }
    else if (has_type(X,CHAR)){
        long a = X.CHAR;
        push_LONG(s,a);
    }
    else if (has_type(X,STRING)){
        char *a = X.STRING;
        long x = atol(a);
        push_LONG(s,x);
    }
    else push(s,X);
}

/**
 * \brief Função toDouble, coverter o tipo para Float.
 *
 * @param[in] *s Apontador para a stack
 */
void toDouble (STACK *s){
    DATA X = pop(s);
    if (has_type(X,LONG)){
        double a = X.LONG;
        push_DOUBLE(s,a);
    }
    else if (has_type(X,CHAR)){
        double a = (long)X.CHAR;
        push_DOUBLE(s,a);
    }
    else if (has_type(X,STRING)){
        char *a = X.STRING;
        double x = atof(a);
        push_DOUBLE(s,x);
    }
    else push_DOUBLE(s,X.DOUBLE);
}

/**
 * \brief Função toChar, coverter o tipo para Char.
 *
 * @param[in] *s Apontador para a stack
 */
void toChar (STACK *s){
    DATA X = pop(s);

        char a = X.LONG;
        X.type = CHAR;
        X.CHAR = a;
        push(s,X);
    }
/**
 * \brief Função readLine, lê a linha.
 *
 * @param[in] *s Apontador para a stack
 */
void readLine (STACK *s){
    DATA x;
    assert(scanf("%lf",&x.DOUBLE) == 1);
    x.type = DOUBLE;
    push(s, x);
}
