/** @file Ficheiro que contém as funcionalidades relativas ao parser do projeto */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "stack.h"
#include "array.h"
#include "IO.h"
#include "math.h"

/**
 * \brief Esta função divide a linha em tokens e interpreta os mesmos 
 */

void parse(STACK * s, char* line) {

    char *rest;
    int pos_array = 0, int1, int2;
    double double1, double2;

    for (char* token = strtok(line, " \t\n"); token != NULL; token = strtok(NULL, " \t\n")) {

        int1 = strtol(token, &rest, 10);

        if (strlen(rest) == 0) { // Ler int
            push_INT(s, int1); continue;
        }

        double1 = strtod(token, &rest);

        if (strlen(rest) == 0) { // Ler double
            push_DOUBLE(s, double1); continue;
        }

        // Arrays

        if (*token == '[') {
            pos_array = s->pos; continue;
        }

        if (*token == ']') {
            create_array(s, s->pos - pos_array); continue;
        }

        // Variables

        if (*token >= 'A' && *token <= 'Z' && token[1] == '\0') {
            push(s, s->variables[*token - 65]); continue;
        }

        if (*token == ':') {
            token++;
            s->variables[*token - 65] = top(s); continue;
        }

        // Math

        if (!Is_array(s) && !Is_String(s)) {

            // Operações aritméticas

            switch(*token) {
                case '+': 
                    double1 = pop_operand(s); 
                    double2 = pop_operand(s); 
                    push_binary_operation(s, double2 + double1); continue;

                case '-':
                    double1 = pop_operand(s); 
                    double2 = pop_operand(s); 
                    push_binary_operation(s, double2 - double1); continue;

                case '*': 
                    double1 = pop_operand(s); 
                    double2 = pop_operand(s); 
                    push_binary_operation(s, double2 * double1); continue;

                case '/': 
                    double1 = pop_operand(s); 
                    double2 = pop_operand(s); 
                    push_binary_operation(s, double2 / double1); continue;

                case '#': 
                    double1 = pop_operand(s); 
                    double2 = pop_operand(s); 
                    push_binary_operation(s, pow(double2, double1)); continue;

                case '%': 
                    int1 = pop_operand(s); 
                    int2 = pop_operand(s); 
                    push_binary_operation(s, int2 % int1); continue;

                case '|': 
                    int1 = pop_operand(s); 
                    int2 = pop_operand(s); 
                    push_binary_operation(s, int2 | int1); continue;

                case '&': 
                    int1 = pop_operand(s); 
                    int2 = pop_operand(s); 
                    push_binary_operation(s, int2 & int1); continue;

                case '^': 
                    int1 = pop_operand(s);
                    int2 = pop_operand(s); 
                    push_binary_operation(s, int2 ^ int1); continue;

                case '~': 
                    int1 = pop_operand(s); 
                    push_unary_operation(s, ~int1); continue;

                case '(': 
                    double1 = pop_operand(s); 
                    push_unary_operation(s, --double1); continue;

                case ')': 
                    double1 = pop_operand(s); 
                    push_unary_operation(s, ++double1); continue;
            }

            // Operações lógicas

            switch(*token) {
                case '!': push_INT(s, !pop_operand(s)); continue;
                case '=': push_INT(s, pop_operand(s) == pop_operand(s)); continue;
                case '<': push_INT(s, pop_operand(s) > pop_operand(s)); continue;
                case '>': push_INT(s, pop_operand(s) < pop_operand(s)); continue;
                case '?': if_then_else(s); continue;
                case 'e': token++; get_logic_state(s, *token); continue;
            }
        }

        if(Is_array(s)) {
            switch(*token) {
                case ',': range_array(s); continue;
                case '*': multiply_array(s); continue;
                case '=': element_by_index(s); continue;
                case '~': array_to_stack(s); continue;
                case '+': concatenate_array(s); continue;
                case '(': remove_first_element(s); continue;
                case ')': remove_last_element(s); continue;
                case '<': get_elements_by_first (s); continue;
                case '>': get_elements_by_last(s); continue;
            }
        }

        if (Is_String(s)) {
            switch(*token) {
                case '+': continue;
                case '*': continue;
                case ',': continue;
                case '<': continue;
                case '>': continue;
                case '(': continue;
                case ')': continue;
                case '#': continue;
                case 't': continue;
                case '/': continue;
                case 'S': continue;
                case 'N': continue;
            }
        }

        switch(*token) {
            case '\\': swap_data(s); continue;
            case ';': pop(s); continue;
            case '@': rotate_top(s); continue;
            case '$': copy_nth_element(s); continue;
            case '_': push(s, top(s)); continue;
            case 'l': read_line(s, line); continue;
            case 'p': print_data(top(s)); continue;
            case 'c': convert_to_char(s); continue;
            case 'f': convert_to_float(s); continue;
            case 'i': convert_to_int(s); continue;
            case 's': convert_to_string(s); continue;
        }
    }
}
