/** @file Ficheiro que contém as funcionalidades relativas à análise dos tokens */

#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "handle_operations.h"
#include "lexer.h"
#include "IO.h"
#include "array.h"
#include "variables.h"
#include "string.h"

void parse_variables(STACK *s, char *token) {
    if (*token == ':') copy_top_to_variable(s, token);
    else push_variables(s, token); 
}

void parse_number(STACK *s, char *token) {
    if (Is_Double(token)) push_DOUBLE(s,convert_string_to_double(token)); // TOKEN -> DOUBLE
    else push_INT(s, convert_string_to_int(token));                       // TOKEN -> INT
}

void parse_array(STACK *s, char *token) {
    int begin = s->pos;
    char *array_content = get_array_content(token);
    TOKENIZER *array = NULL;
    array = tokenize(array, array_content);
    parse_tokens(s, array);
    create_array(s, s->pos - begin);
}

void parse_block(STACK *s, char *token) {
    char *block = malloc(sizeof(char) * 10240);
    block = token;
    push_BLOCK(s, block);
}

int get_operands_state(char *token) {
    int state = 0, number_of_operands = 5;
    int (*operand_type[]) (char *token) = {
        Is_token_number,
        Is_token_array,
        Is_token_string,
        Is_token_variable,
        Is_token_block
    };
    for (; state < number_of_operands; state++) {
        if (operand_type[state](token)) break;
    }
    if (state == number_of_operands) state = -1;
    return state;
}

int parse_operands(STACK *s, char *token) {
    int state = get_operands_state(token);
    if (state == -1) return 0;
    void (*parse_operand[]) (STACK *s, char *token) = {
        parse_number,
        parse_array,
        create_string,
        parse_variables,
        parse_block
    };
    parse_operand[state](s, token);
    return 1;
}

int get_operation_state(STACK *s, char *token) {
    int state = 0;
    int (*operation_type[]) (STACK *s, char *token) = {
        Is_arithmetic_operation,
        Is_logic_operation,
        Is_string_operation,
        Is_array_operation,
        Is_stack_operation,
        Is_input_output_operation,
        Is_block_operation
    };
    for (; state < 7; state++) {
        if (operation_type[state](s, token)) break;
    }
    return state;
}

void parse_operations(STACK *s, char *token) {
    int state = get_operation_state(s, token);
    void (*handle_operation[]) (STACK *s, char *token) = {
        handle_arithmetic_operation,
        handle_logic_operation,
        handle_string_operation,
        handle_array_operation,
        handle_stack_operation,
        handle_input_output_operation,
        handle_block_operation
    };
    handle_operation[state](s, token);
}

void parse (STACK *s, char *token) {
    if (!parse_operands(s, token)) parse_operations(s, token);
}

void parse_tokens(STACK *s, TOKENIZER *tokenizer) {
    for (; tokenizer != NULL; tokenizer = tokenizer->next_token) {
        parse(s, tokenizer->token);
    }
}
