/** @file Ficheiro que contém as funcionalidades relativas à lógica */

#include "string.h"
#include "stack.h"
#include "math.h"

void Is_equal(STACK *s) {
    if (has_type(top(s), STRING)) {
        compare_strings(s);
    }
    else {
        double x = pop_operand(s),
               y = pop_operand(s);
        push_INT(s, y == x);
    }
}

void Is_lower(STACK *s) {      
    if (has_type(top(s), STRING)) {
        compare_less_than_strings(s);
    }
    else {
        double x = pop_operand(s),
               y = pop_operand(s);
        push_INT(s, y < x);
    }
}

void Is_greater(STACK *s) {
    if (has_type(top(s), STRING)) {
        compare_greater_than_strings(s);
    }
    else {
        double x = pop_operand(s),
               y = pop_operand(s);
        push_INT(s, y > x);
    }
}

void negate(STACK*s) {
    double x = pop_operand(s);
    push_INT(s, !x);         
}

void get_lower(STACK *s) {
    if (has_type(top(s), STRING)) {
        get_lower_string(s);
    }
    else {
        double x = pop_operand(s),                     
               y = pop_operand(s);                         
        if (x < y) {push(s, s->stack[s->pos + 2]);return;}  
        push(s, s->stack[s->pos + 1]); 
    }                      
}  

void get_greater(STACK *s) {                           
    if (has_type(top(s), STRING)) {
        get_greater_string(s);
    }
    else {
        double x = pop_operand(s),                     
               y = pop_operand(s);                         
        if (x > y) {push(s, s->stack[s->pos + 2]);return;}  
        push(s, s->stack[s->pos + 1]); 
    }    
}

void or_logic(STACK *s) {              
    double x = pop_operand(s),                    
           y = pop_operand(s);                    
    if (y) {push(s, s->stack[s->pos + 1]);return;} 
    if (x) {push(s, s->stack[s->pos + 2]);return;}
    push_INT(s, 0);
}

void and_logic(STACK *s) {      
    double x = pop_operand(s),                    
           y = pop_operand(s);                      
    if (x == 0 || y == 0) {push_INT(s, 0); return;} 
    push(s, s->stack[s->pos + 2]);
}

void if_then_else (STACK *s) {
    DATA ELSE = pop(s),            
         THEN = pop(s);              
    double IF = pop_operand(s);    
    if (IF) {push(s, THEN); return;}       
    push(s, ELSE);           
}

void logic_shortcut (STACK *s, char *token) {
    token++;
    switch(*token) {
        case '&': and_logic(s); break;
        case '|': or_logic(s); break;
        case '>': get_greater(s); break;
        case '<': get_lower(s); break;
    }
}
