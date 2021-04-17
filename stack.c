/** @file Ficheiro que contém as funcionalidades relativas a stack */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

STACK* create_stack () {
    STACK *s = malloc(sizeof(STACK));
    s->pos = -1; // -1 -> posição inicial: representa que a stack que está vazia
    s->size = 32; // Definimos um tamanho inicial para a stack e aumentamos conforme seja preciso
    s->stack = malloc(sizeof(DATA) * s->size);
    s->variables = malloc(sizeof(DATA) * 26); // 26 -> Variáveis de A até Z
    return s;
}

void push(STACK *s, DATA elem) {
    if (s->pos == s->size - 1) { // Se a stack estiver cheia, aumentamos ela
        s->size += 32;           // assim enquanto houver espaço na nossa memória física, há espaço na stack
        s->stack = realloc(s->stack, sizeof(DATA) * s->size);
    }
    s->stack[++s->pos] = elem;
}

DATA pop(STACK *s) {
    return s->stack[s->pos--];
}

DATA top (STACK *s) {
    return s->stack[s->pos];
}

void push_unary_operation(STACK *s, double val) {                           // val tipo -> push tipo
    if (s->stack[s->pos + 1].type == DOUBLE) {push_DOUBLE(s, val); return;} // DOUBLE   -> DOUBLE
    if (s->stack[s->pos + 1].type == INT) {push_INT(s, val); return;}       // DOUBLE   -> INT
    push_CHAR(s, val);                                                      // DOUBLE   -> CHAR
}

void push_binary_operation(STACK *s, double val) {
    if (s->stack[s->pos + 1].type == DOUBLE || s->stack[s->pos + 2].type == DOUBLE) { // val tipo -> push tipo
        push_DOUBLE(s, val); return;}                                                 // DOUBLE   -> DOUBLE
    push_INT(s, val);                                                                 // DOUBLE   -> INT
}

double pop_operand(STACK *s) { // O double consegue armazenar os três tipos, sem trocar o valor do elemento
    DATA elem = pop(s);                          // pop tipo -> retorna 
    if (elem.type == INT) return elem.INT;       // INT      -> DOUBLE
    if (elem.type == DOUBLE) return elem.DOUBLE; // DOUBLE   -> DOUBLE
    return elem.CHAR;                            // CHAR     -> DOUBLE
}

/**
 * \brief macro para push's e pop's dos tipos de dados
 * a macro define funções push e pop do tipo
 *        INT, DOUBLE, CHAR, STRING
 */

#define STACK_OPERATION(_type, _name)             \
    void push_##_name(STACK *s, _type val) {      \
        DATA elem;                                \
        elem.type = _name;                        \
        elem._name = val;                         \
        push(s, elem);                            \
    }                                             \
    _type pop_##_name(STACK *s) {                 \
        DATA elem = pop(s);                       \
        return elem._name;                        \
    }

STACK_OPERATION(int, INT)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
