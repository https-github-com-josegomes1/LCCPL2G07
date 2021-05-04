/** @file Ficheiro que contém as funcionalidades relativas às operações do programa */ 

#include <string.h>
#include <stdio.h>

#include "handle_operations.h"
#include "stack.h"
#include "math.h"
#include "logic.h"
#include "stackManipulation.h"
#include "IO.h"
#include "array.h"
#include "string.h"
#include "block.h"

void handle_arithmetic_operation (STACK *s, char *token) {
    char *possible_tokens = "+-*/#%|&^~()";
    void (*operators[]) (STACK *s) = {
        sum,
        subtraction,
        multiplication,
        division,
        power,
        module,
        or_bitwise,
        and_bitwise,
        xor_bitwise,
        not_bitwise,
        decrement,
        increment
    };
    for (int i = 0; possible_tokens[i] != '\0'; i++) {
        if (possible_tokens[i] == *token) {
            operators[i](s); return;
        }
    }
}

void handle_logic_operation (STACK *s, char *token) {
    if (*token == 'e') logic_shortcut(s, token);
    char *possible_tokens = "=<>!?";
    void (*operators[]) (STACK *s) = {
        Is_equal,
        Is_lower,
        Is_greater,
        negate,
        if_then_else
    };
    for (int i = 0; possible_tokens[i] != '\0'; i++) {
        if (possible_tokens[i] == *token) {
            operators[i](s); return;
        }
    }
}

void handle_string_operation (STACK *s, char *token) {
    char *possible_tokens = "+*,=<>()#/SN";
    void (*operators[]) (STACK *s) = {
        concatenate_string,
        multiply_string,
        string_length,
        string_element_by_index,
        get_string_elements_by_first,
        get_string_elements_by_last,
        remove_string_first_element,
        remove_string_last_element,
        search_substring,
        separate_string_by_substring,
        separate_string_by_whitespace,
        separate_string_by_newline
    };
    for (int i = 0; possible_tokens[i] != '\0'; i++) {
        if (possible_tokens[i] == *token) {
            operators[i](s); return;
        }
    }
}

void handle_array_operation (STACK *s, char *token) {
    char *possible_tokens = "~+*,=<>()";
    void (*operators[]) (STACK *s) = {
        array_to_stack,
        concatenate_array,
        multiply_array,
        range_array,
        array_element_by_index,
        get_array_elements_by_first,
        get_array_elements_by_last,
        remove_array_first_element,
        remove_array_last_element
    };
    for (int i = 0; possible_tokens[i] != '\0'; i++) {
        if (possible_tokens[i] == *token) {
            operators[i](s); return;
        }
    }
}

void handle_stack_operation (STACK *s, char *token) {
    if (*token == ';') pop(s);

    char *possible_tokens = "_\\@$ifcs";
    void (*operators[]) (STACK *s) = {
        duplicate_top,
        swap_top,
        rotate_top,
        copy_nth_element,
        convert_stack_to_int,
        convert_stack_to_float,
        convert_stack_to_char,
        convert_stack_to_string
    };
    for (int i = 0; possible_tokens[i] != '\0'; i++) {
        if (possible_tokens[i] == *token) {
            operators[i](s); return;
        }
    }  
}

void handle_input_output_operation (STACK *s, char *token) {
    switch(*token) {
        case 'l': read_line(s); break;
        case 't': read_all_input(s); break;
        case 'p': print_data(s, top(s)); putchar('\n'); break;
    }
}

void handle_block_operation(STACK *s, char *token) {
    char *possible_tokens = "~%*,$w";
    void (*operators[]) (STACK *s) = {
        execute_block,
        apply_block_to,
        fold_array,
        filter_by_block,
        sort_by_block,
        execute_while_true
    };
    for (int i = 0; possible_tokens[i] != '\0'; i++) {
        if (possible_tokens[i] == *token) {
            operators[i](s); return;
        }
    }  
}