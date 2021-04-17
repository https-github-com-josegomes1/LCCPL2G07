/** @file Ficheiro que contém as funcionalidades relativas ao parser */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "stack.h"
#include "parser.h"
#include "IO.h"
#include "math.h"
#include "lexer.h"
#include "logic.h"

void parse_plus(STACK *s) {sum(s);}
void parse_asterisk(STACK *s) {multiplication(s);}
void parse_slash(STACK *s) {division(s);}
void parse_left_parenthesis(STACK *s) {decrement(s);}
void parse_right_parenthesis(STACK *s) {increment(s);}
void parse_percentage(STACK *s) {module(s);}
void parse_tilde(STACK *s) {not_bitwise(s);}
void parse_equal(STACK *s) {Is_equal(s);}
void parse_less_than(STACK *s) {Is_lower(s);}
void parse_more_than(STACK *s) {Is_greater(s);}
void parse_pop(STACK *s) {pop(s);}

void parse_number(STACK *s, char *token) {
    if (Is_Double(token)) push_DOUBLE(s,convert_string_to_double(token)); // TOKEN -> DOUBLE
    else push_INT(s, convert_string_to_int(token));                       // TOKEN -> INT
}

void parse_operators(STACK *s, char *token) {
    char **operators = get_operators_token();
    parse_operators_function *func_ptr = get_operators_function();

    for (int i = 0; i < 34; i++) {
        if (strcmp(token, operators[i]) == 0) {
            func_ptr[i](s); return;
        }   
    }
}

int parse_operands(STACK *s, char *token) {
    int *operands = get_operands_state(token);
    parse_operands_function *func_ptr = get_operands_function();

    for(int i = 0; i < 3; i++) {
        if (operands[i]) {
            func_ptr[i](s, token); return 1;
        }
    }
    return 0;
}

void parse(STACK * s, char* line) {
    for (char* token = strtok(line, " \t\n"); token != NULL; token = strtok(NULL, " \t\n")) {
        if (!parse_operands(s, token)) parse_operators(s, token);
    }
}
