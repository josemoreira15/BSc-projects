/**
 * @file stack.h
 *
 * \brief Ficheiro que diz respeito à stack
 */
#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

/** Tipo enum TYPE */
typedef enum {
	/** Long */
	LONG = 1,
	/** Double */
	DOUBLE = 2,
	/** Char */
	CHAR = 4,
	/** String */
	STRING = 8
} TYPE;

/** Define do Integer */
#define INTEGER(LONG , CHAR)

/** Struct definida de DATA */
typedef struct data {
	/** Type */
	TYPE type;
	/** Long */
	long LONG;
	/** Double */
	double DOUBLE;
	/** Char */
	char CHAR;
	/** String */
	char *STRING;
} DATA;

/** Struct definida da STACK */
typedef struct stack{
	/** Stack */
	DATA *stack;
	/** Int */
	int size;
	/** Int */
	int n_elems;
} STACK;

int has_type(DATA elem, int mask);

STACK *new_stack();

void push(STACK *s, DATA elem);

DATA pop(STACK *s);

DATA top(STACK *s);

__attribute__((unused)) int is_empty(STACK *s);
void print_stack(STACK *s);

/** Define do STACK_OPERATION_PROTO */
#define STACK_OPERATION_PROTO(_type, _name)		\
	void push_##_name(STACK *s, _type val);		\
	_type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif
