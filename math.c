/** @file Ficheiro que contém as funcionalidades relativas a operações aritmética e lógica */

#include "stack.h"

/**
 * \brief da push a um elemento resultante de uma operação unária, consoante o seu tipo
 */

void push_unary_operation(STACK *s, double val) {
    if (s->stack[s->pos + 1].type == DOUBLE) {push_DOUBLE(s, val); return;}
    if (s->stack[s->pos + 1].type == INT) {push_INT(s, val); return;}
    push_CHAR(s, val);
}

/**
 * \brief da push a um elemento resultante de uma operação binária, consoante o seu tipo
 */

void push_binary_operation(STACK *s, double val) {
    if (s->stack[s->pos + 1].type == DOUBLE || s->stack[s->pos + 2].type == DOUBLE) {push_DOUBLE(s, val); return;}
    push_INT(s, val);
}

/**
 * \brief devolve o elemento do topo da stack consoante o seu tipo
 */

double pop_operand(STACK *s) {
    if (s->stack[s->pos].type == INT) return s->stack[s->pos--].INT;
    if (s->stack[s->pos].type == DOUBLE) return s->stack[s->pos--].DOUBLE;
    else return s->stack[s->pos--].CHAR;
}

/**
 * \brief da push do penultimo ou ultimo elemento, consoante o elemento que está na posição corresponde ao IF
 */

void if_then_else (STACK *s) {
    double IF; DATA THEN, ELSE;
    ELSE = pop(s); THEN = pop(s); IF = pop_operand(s);
    if (IF) {push(s, THEN); return;}
    push(s, ELSE);
}

/**
 * \brief da pop aos dois ultimos elementos e push no menor deles
 */

void get_lower(STACK *s) {
    DATA data1 = s->stack[s->pos], 
         data2 = s->stack[s->pos - 1];
    double op1 = pop_operand(s),
           op2 = pop_operand(s);
    if (op1 < op2) {push(s, data1); return;}
    push(s, data2);
}

/**
 * \brief da pop aos dois ultimos elementos e push no maior deles
 */

void get_higher(STACK *s) {
    DATA data1 = s->stack[s->pos], 
         data2 = s->stack[s->pos - 1];
    double op1 = pop_operand(s),
           op2 = pop_operand(s);
    if (op1 > op2) {push(s, data1); return;}
    push(s, data2);
}

/**
 * \brief efetua um ou lógico entre os dois últimos elementos
 * 
 */

void or_shortcut(STACK *s) {
    DATA data1 = s->stack[s->pos], 
         data2 = s->stack[s->pos - 1];
    double op1 = pop_operand(s),
           op2 = pop_operand(s);
    if (op2) {push(s, data2); return;}
    if (op1) {push(s, data1); return;}
    push_INT(s, 0); 
}

/**
 * \brief efetua um e lógico entre os dois últimos elementos
 */

void and_shortcut(STACK *s) {
    DATA data1 = s->stack[s->pos];
    double op1 = pop_operand(s),
           op2 = pop_operand(s);
    if (op1 == 0 || op2 == 0) {push_INT(s, 0); return;}
    push(s, data1);
}

/**
 * \brief efetua uma operação consoante o token
 */

void get_logic_state(STACK *s, char token) {
    switch(token) {
        case '>': get_higher(s); break;
        case '<': get_lower(s); break;
        case '|': or_shortcut(s); break;
        case '&': and_shortcut(s); break;
    }
}