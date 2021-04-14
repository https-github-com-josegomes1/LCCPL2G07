/** @file Ficheiro que contém as funcionalidades relativas ao input/output do projeto */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "stack.h"

/**
 * \brief verifica se o ultimo ou penultimo elemento do topo da stack é um array
 */

int Is_array (STACK * s) {
    return s->stack[s->pos].type == ARRAY || s->stack[s->pos - 1].type == ARRAY;
}

/**
 * \brief verifica se o ultimo ou penultimo elemento do topo da stack é uma string
 */

int Is_String (STACK * s) {
    return s->stack[s->pos].type == STRING || s->stack[s->pos - 1].type == STRING;
}

/**
 * \brief faz leitura de uma linha e da push da string lida para a stack
 */

void read_line(STACK * s, char * line) {
    char * input = strdup(line);
    assert(fgets(input, 10240, stdin) != NULL);
    input[strlen(input) - 1] = '\0';
    push_STRING(s, input);
}

/**
 * \brief da printf da data consoante o tipo
 */

void print_data(DATA data) {
    switch(data.type) {
        case INT: printf("%d", data.INT); break;
        case DOUBLE: printf("%g", data.DOUBLE); break;
        case CHAR: printf("%c", data.CHAR); break;
        case STRING: printf("%s", data.STRING); break;
        case ARRAY: break;
    }
}

/**
 * \brief da printf de todos os elementos da stack
 */

void print_stack(STACK *s) {
    for (int i = 0; i <= s->pos; i++) {
        print_data(s->stack[i]);
    }
    putchar('\n');
}