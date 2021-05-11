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

long convert_string_to_int(char *string) {
    char *rest; // variável auxiliar para acompanhar a string na função "strtol"
    long INT = strtol(string, &rest, 10); // STRING -> INT
    return INT;
}

int Is_Double(char *token) {
    for (int i = 0; token[i] != '\0'; i++) {
        if (token[i] == '.') return 1;
    }
    return 0;
}

void read_line(STACK * s) {
    char * input = malloc(sizeof(char) * 10240);
    assert(fgets(input, 10240, stdin) != NULL);
    input[strlen(input) - 1] = '\0';
    push_STRING(s, input);
}

void read_all_input(STACK *s) {
    char *input = malloc(sizeof(char) * 10240);
    char c;
    int i = 0;
    while((c = getchar()) != EOF) {
        input[i] = c;
        i++;
    }
    input[i+1] = '\0';
    push_STRING(s, input);
}

void print_array(STACK *s, DATA a) {
    for (int i = 0; i < a.array.size; i++) {
        switch(a.array.elems[i].type) {
            case ARRAY: print_array(s, a.array.elems[i]); break;
            case INT: printf("%ld", a.array.elems[i].INT); break;
            case DOUBLE: printf("%g", a.array.elems[i].DOUBLE); break;
            case CHAR: printf("%c", a.array.elems[i].CHAR); break;
            case STRING: printf("%s", a.array.elems[i].STRING); break;
            default: break;
        }
    }
}

void print_data(STACK *s, DATA data) {
    switch(data.type) {
        case INT: printf("%ld", data.INT); break;
        case DOUBLE: printf("%g", data.DOUBLE); break;
        case CHAR: printf("%c", data.CHAR); break;
        case STRING: printf("%s", data.STRING); break;
        case BLOCK: printf("%s", data.BLOCK); break;
        case ARRAY: print_array(s, data); break;
    }
}

void print_stack(STACK *s) {
    for (int i = 0; i <= s->pos; i++) {
        print_data(s, s->stack[i]);
    }
    putchar('\n');
}
