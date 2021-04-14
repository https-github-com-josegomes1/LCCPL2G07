/** @file Ficheiro que contém as funcionalidades relativas a stack do projeto */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/**
 * \brief Inicializa os valores da stack
 */

void create_stack (STACK *s) {
    s->pos = -1;
    s->size = 32;
    s->stack = malloc(sizeof(DATA) * s->size);
    s->variables = malloc(sizeof(DATA) * 26);
}

/**
 * \brief adiciona um elemento ao topo da stack
 */

void push(STACK *s, DATA elem) {
    if (s->pos == s->size - 1) {
        s->size += 32;
        s->stack = realloc(s->stack, sizeof(DATA) * s->size);
    }
    s->stack[++s->pos] = elem;
}

/**
 * \brief retira um elemento do topo da stack
 */

DATA pop(STACK *s) {
    return s->stack[s->pos--];
}

/**
 * \brief devolve o elemento que está no topo da stack
 */

DATA top (STACK *s) {
    return s->stack[s->pos];
}

/**
 * \brief troca os dois elementos do top da stack
 */

void swap_data (STACK *s) {
    DATA data1 = pop(s);
    DATA data2 = pop(s);
    push(s, data1);
    push(s, data2);
}

/**
 * \brief roda os três elementos do topo da stack
 */

void rotate_top(STACK *s) {
    DATA data1 = pop(s);
    DATA data2 = pop(s);
    DATA data3 = pop(s);
    push(s, data2);
    push(s, data1);
    push(s, data3);
}

/**
 * \brief  Copia n-ésimo elemento para o topo da stack
 * 0 é o topo da stack neste caso
 */

void copy_nth_element(STACK *s) {
    int n = pop_INT(s);
    push(s, s->stack[s->pos - n]);
}

/**
 * \brief converte o topo da stack em char
 */

void convert_to_char(STACK * s) {
    DATA elem = pop(s);
    switch(elem.type) {
        case INT: push_CHAR(s, elem.INT); break;
        case DOUBLE: push_CHAR(s, elem.DOUBLE); break;
        case STRING: push_CHAR(s, *elem.STRING); break;
        case CHAR:
        case ARRAY:
            break;
    }
}

/**
 * \brief converte o topo da stack em int
 */

void convert_to_int(STACK * s) {
    DATA elem = pop(s);
    switch(elem.type) {
        case CHAR: push_INT(s, elem.CHAR); return;
        case DOUBLE: push_INT(s, elem.DOUBLE); return;
        case STRING:
        case ARRAY:
        case INT:
            break;
    }
    char * sobra;
    int INT = strtol(elem.STRING, &sobra, 10);
    push_INT(s, INT);
}

/**
 * \brief converte o topo da stack em float
 */

void convert_to_float(STACK * s) {
    char * sobra;
    DATA elem = pop(s);
    double elem_DOUBLE = elem.DOUBLE;
    switch(elem.type) {
        case CHAR: push_DOUBLE(s, elem.CHAR); return;
        case INT: push_DOUBLE(s, elem.INT); return;
        case STRING: elem_DOUBLE = strtod(elem.STRING, &sobra); break;
        case DOUBLE: break;
        case ARRAY: return;
    }
    push_DOUBLE(s, elem_DOUBLE);
}

/**
 * \brief converte o topo da stack em string
 */

void convert_to_string(STACK * s) {
    DATA data = pop(s);
    char * string = malloc(sizeof(char) * 20);
    switch(data.type) {
        case CHAR: string[0] = data.CHAR; break;
        case INT: snprintf(string, 20, "%d", data.INT); break;
        case DOUBLE: snprintf(string, 20, "%g", data.DOUBLE); break;
        case STRING:
        case ARRAY:
            break;
    }
    push_STRING(s, string);
}

/**
 * \brief define os valores por omissão das variáveis
 */

void default_variables(STACK *s) {
    s->variables[0].INT = 10; s->variables[0].type = INT;              // A
    s->variables[1].INT = 11; s->variables[1].type = INT;              // B
    s->variables[2].INT = 12; s->variables[2].type = INT;              // C
    s->variables[3].INT = 13; s->variables[3].type = INT;              // D
    s->variables[4].INT = 14; s->variables[4].type = INT;              // E
    s->variables[5].INT = 15; s->variables[5].type = INT;              // F
    s->variables[13].STRING = "\n"; s->variables[13].type = STRING;    // N
    s->variables[18].STRING = " "; s->variables[18].type = STRING;     // S
    s->variables[23].INT = 0; s->variables[23].type = INT;             // X
    s->variables[24].INT = 1; s->variables[24].type = INT;             // Y
    s->variables[25].INT = 2; s->variables[25].type = INT;             // Z
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
