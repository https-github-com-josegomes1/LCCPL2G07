/** @file Ficheiro que contém as funcionalidades relativas à análise dos tipos dos tokens */

#include <stdlib.h>

#include "stack.h"
#include "variables.h"

int Is_arithmetic_operation(STACK *s, char *token) {
    switch(*token) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '#':
            return has_type(s->stack[s->pos], NUMBER) && has_type(s->stack[s->pos - 1], NUMBER);
        case '&':
        case '|':
        case '^':
        case '%':
            return has_type(s->stack[s->pos], INTEGER) && has_type(s->stack[s->pos - 1], INTEGER);
        case '~':
            return has_type(s->stack[s->pos], INTEGER);
        case '(':
        case ')':
            return has_type(s->stack[s->pos], NUMBER);
    }
    return 0;
}

int Is_logic_operation (STACK *s, char *token) {
    switch(*token) {
        case '?':
            return 1;
        case '!':
            return has_type(top(s), NUMBER);
        case '<':
        case '>':
        case 'e':
        case '=':
            return (has_type(s->stack[s->pos], NUMBER) && has_type(s->stack[s->pos - 1], NUMBER)) ||
                   (has_type(s->stack[s->pos], STRING) && has_type(s->stack[s->pos - 1], STRING));
    }
    return 0;
}

int Is_array_operation(STACK *s, char *token) {
    switch(*token) {
        case ',': return has_type(top(s), NUMBER) || has_type(top(s), ARRAY);
        case '~':
        case '(':
        case ')':
            return has_type(top(s), ARRAY);
        case '*':
            return has_type(s->stack[s->pos - 1], ARRAY) && has_type(top(s), NUMBER);
        case '+':
            return (has_type(s->stack[s->pos], ARRAY) && has_type(s->stack[s->pos - 1], ARRAY)) ||
                   (has_type(s->stack[s->pos], ARRAY) && has_type(s->stack[s->pos - 1], NUMBER)) ||
                   (has_type(s->stack[s->pos], NUMBER) && has_type(s->stack[s->pos - 1], ARRAY));
        case '=':
        case '<':
        case '>':
            return has_type(s->stack[s->pos], NUMBER) || has_type(s->stack[s->pos - 1], ARRAY);
    }
    return 0;
}

int Is_string_operation(STACK *s, char *token) {
    switch(*token) {
        case 'S':
        case 'N':
        case '(':
        case ')':
        case ',':
            return has_type(top(s), STRING);
        case '*':
        case '=':
        case '<':
        case '>':
            return has_type(s->stack[s->pos - 1], STRING) && has_type(top(s), NUMBER);
        case '#':
        case '/':
        case '+':
            return (has_type(s->stack[s->pos - 1], STRING) && has_type(top(s), STRING)) ||
                   (has_type(s->stack[s->pos - 1], STRING) && has_type(top(s), CHAR)) ||
                   (has_type(s->stack[s->pos - 1], CHAR) && has_type(top(s), STRING));
    }
    return 0;
}

int Is_stack_operation(STACK *s, char *token) {
    switch(*token) {
        case '$':
            return !has_type(top(s), BLOCK);
        case 'i':
        case 'f':
        case 'c':
        case 's':
        case '_':
        case ';':
        case '\\':
        case '@':
            return 1;
    }
    return 0;
}

int Is_input_output_operation(STACK *s, char *token) {
    switch(*token) {
        case 'l':
        case 't':
        case 'p':
            return s != NULL;
    }
    return 0;
}

int Is_block_operation(STACK *s, char *token) {
    switch(*token) {
        case '~':
        case '%':
        case '*':
        case ',':
        case '$':
        case 'w':
            return has_type(top(s), BLOCK);
    }
    return 0;
}

int Is_token_number(char *token) {
    if (*token == '-') return Is_token_number(++token);
    return *token >= '0' && *token <= '9';
}

int Is_token_array(char *token) {
    return *token == '[';
}

int Is_token_string(char * token) {
    return *token == '"';
}

int Is_token_variable(char * token) {
    if (*token == ':') return 1;
    else return *token >= 'A' && *token <= 'Z' && token[1] != '/';
}

int Is_token_block(char * token) {
    return *token == '{';
}
