/** @file Ficheiro que contém as funcionalidades relativas a manipulação da stack*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "IO.h"

void duplicate_top(STACK *s) {
    push(s, top(s));
}  

void swap_top (STACK *s) { 
    DATA data1 = pop(s);    
    DATA data2 = pop(s);  
    push(s, data1);       
    push(s, data2);                   
}

void rotate_top(STACK *s) { 
    DATA data1 = pop(s);    
    DATA data2 = pop(s);    
    DATA data3 = pop(s);      
    push(s, data2);         
    push(s, data1);         
    push(s, data3);        
}

void copy_nth_element(STACK *s) { 
    int n = pop_INT(s);            
    push(s, s->stack[s->pos - n]);
}

void convert_stack_to_int(STACK *s) {     
    if (s->stack[s->pos].type == INT) return; // Já é um inteiro, não precisa converter                       
    DATA elem = pop(s);                    
    if (elem.type == DOUBLE) {push_INT(s, elem.DOUBLE); return;} // pop DOUBLE -> push INT
    if (elem.type == CHAR) {push_INT(s, elem.CHAR); return;} // pop CHAR -> push INT
    if (elem.type == STRING) {push_INT(s, convert_string_to_int(elem.STRING)); return;} // pop STRING -> push INT
}

void convert_stack_to_float(STACK *s) {
    if (s->stack[s->pos].type == DOUBLE) return; // Já é um float, não precisa converter                                
    DATA elem = pop(s);
    if (elem.type == INT) {push_DOUBLE(s, elem.INT); return;} // pop INT -> push DOUBLE
    if (elem.type == CHAR) {push_DOUBLE(s, elem.CHAR); return;} // pop CHAR -> push DOUBLE
    if (elem.type == STRING) {push_DOUBLE(s, convert_string_to_double(elem.STRING)); return;} // pop STRING -> push DOUBLE
}

void convert_stack_to_char(STACK *s) {
    if (s->stack[s->pos].type == CHAR) return; // Já é um char, não precisa converter                                
    DATA elem = pop(s);
    if (elem.type == INT) {push_CHAR(s, elem.INT); return;} // pop INT -> push CHAR
    if (elem.type == DOUBLE) {push_CHAR(s, elem.DOUBLE); return;} // pop DOUBLE -> push CHAR
    if(elem.type == STRING) {push_CHAR(s, *elem.STRING); return;} // pop STRING -> push CHAR
}

void convert_stack_to_string(STACK * s) {
    if (s->stack[s->pos].type == STRING) return; // Já é uma string, não precisa converter    
    DATA elem = pop(s);
    char * string = malloc(sizeof(char) * 20); // 20 -> QUANTIDADE MÁXIMA DE DÍGITOS
    if (elem.type == INT) {                   
        snprintf(string, 20, "%ld", elem.INT); // INT -> STRING                                   
        push_STRING(s, string); return;
    }
    if (elem.type == DOUBLE) {                   
        snprintf(string, 20, "%g", elem.DOUBLE); // DOUBLE -> STRING
        push_STRING(s, string); return;          
    }
    if(elem.type == CHAR) {              
        string[0] = elem.CHAR;          
        string[1] = '\0';                // Para garantir que é uma string
        push_STRING(s, string); return;  
    }
}
