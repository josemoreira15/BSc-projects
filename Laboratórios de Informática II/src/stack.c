/**
 * @file stack.c
 *
 * \brief Funções que dizem respeito ao stack
 */
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/**
 * \brief Esta função compara o tipo de uma struct com uma máscara.
 *
 * @return 0 caso seja true.
 */
int has_type(DATA elem, int mask){
	return (elem.type & mask) != 0;
}

/**
 * \brief Esta função cria uma nova stack.
 *
 * @return s nova stack
 */
STACK *new_stack(){
	STACK *s = (STACK *) calloc(1, sizeof(STACK));
	s->size = 100;
	s->stack = (DATA *) calloc(s->size, sizeof(DATA));
	return s;
}

/**
 * \brief Esta função adiciona um elemento ao topo da stack.
 *
 * @param[in] *s apontador para stack
 * @param[in] elem elemento a por na stack
 */
void push(STACK *s, DATA elem){
	if(s->size == s->n_elems){
		s->size += 100;
		s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
	}
	s->stack[s->n_elems] = elem;
	s->n_elems++;
}

/**
 * \brief Esta função retira o último elemento da stack.
 *
 * @param[in] *s apontador para stack
 * @returns top elemento do top da stack
 */
DATA pop(STACK *s){
	s->n_elems--;
	return s->stack[s->n_elems];
}

/**
 * \brief Esta função devolve o top da stack.
 *
 * @param[in] *s apontador para stack
 * @returns top elemento do topo da stack
 */
DATA top(STACK *s){
	return s->stack[s->n_elems -1];
}

/**
 * \brief Esta função verifica se a stack está vazia.
 *
 * @param[in] *s apontador para stack
 * @returns 0 caso esteja vazia
 */
__attribute__((unused)) int is_empty(STACK *s){
	return s->n_elems = 0;
}

/**
 * \brief Esta função dá print à stack.
 *
 * @param[in] *s apontador para stack
 */
void print_stack(STACK *s){
	for(int i = 0; i < s->n_elems; i++){
		DATA elem = s->stack[i];
		TYPE type = elem.type;
		switch(type){
			case LONG: printf("%ld", elem.LONG);
				break;
			case DOUBLE: printf("%g", elem.DOUBLE);
				break;
			case CHAR: printf("%c", elem.CHAR);
				break;
			case STRING: printf("%s", elem.STRING);
				break;
		}
	}
	  printf("\n");

}

/**
 * \brief Define de STACK_OPERATION.
 *
 * @param[in] _type
 * @param[in] _name
 *
 */
#define STACK_OPERATION(_type, _name)			\
	void push_##_name(STACK *s, _type val){ 	\
		DATA elem;								\
		elem.type = _name;						\
		elem._name = val;						\
		push(s, elem);							\
	}											\
	_type pop_##_name(STACK *s){				\
		DATA elem = pop(s); 					\
		assert(elem.type == _name);				\
		return elem._name;						\
	}

STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
// STACK_OPERATION(DATA, data)
