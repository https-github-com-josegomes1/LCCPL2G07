/** @file Arquivo que contém as funções do math.c que precisam ser passadas entre arquivos */

#ifndef math_H
#define math_H

void push_unary_operation(STACK *s, double val);
void push_binary_operation(STACK *s, double val);
double pop_operand(STACK *s);

void if_then_else (STACK *s);
void get_logic_state(STACK *s, char token);

#endif