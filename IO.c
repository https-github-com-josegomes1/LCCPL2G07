/** @file Ficheiro que contém as funcionalidades relativas ao input/output */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "stack.h"

double convert_string_to_double(char *string) {
    char *rest; // variável auxiliar para acompanhar a string na função "strtod"
    double DOUBLE = strtod(string, &rest); // STRING -> DOUBLE
    return DOUBLE;
}

int convert_string_to_int(char *string) {
    char *rest; // variável auxiliar para acompanhar a string na função "strtol"
    int INT = strtol(string, &rest, 10); // STRING -> INT
    return INT;
}

int Is_Double(char *token) {
    for (int i = 0; token[i]; i++) {
        if (token[i] == '.') return 1;
    }
    return 0;
}

int Is_array (STACK * s) {
    return s->stack[s->pos].type == ARRAY || s->stack[s->pos - 1].type == ARRAY;
}

int Is_String (STACK * s) {
    return s->stack[s->pos].type == STRING || s->stack[s->pos - 1].type == STRING;
}

void read_line(STACK * s) {
    char * input = malloc(sizeof(char) * 10240);
    assert(fgets(input, 10240, stdin) != NULL);
    input[strlen(input) - 1] = '\0';
    push_STRING(s, input);
}

void print_data(DATA data) {
    switch(data.type) {
        case INT: printf("%d", data.INT); break;
        case DOUBLE: printf("%g", data.DOUBLE); break;
        case CHAR: printf("%c", data.CHAR); break;
        case STRING: printf("%s", data.STRING); break;
        case ARRAY: break;
    }
}

void print_stack(STACK *s) {
    for (int i = 0; i <= s->pos; i++) {
        print_data(s->stack[i]);
    }
    putchar('\n');
}
