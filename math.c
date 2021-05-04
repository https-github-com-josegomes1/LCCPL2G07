/** @file Ficheiro que contém as funcionalidades relativas a operações aritmética */

#include <math.h>
#include "stack.h"

void sum(STACK *s) {                 
    long double x = pop_operand(s),        
                y = pop_operand(s);        
    push_binary_operation(s, y + x);  
}

void subtraction(STACK *s) {          
    long double x = pop_operand(s),        
                y = pop_operand(s);        
    push_binary_operation(s, y - x); 
}

void multiplication(STACK *s) {       
    long double x = pop_operand(s),       
                y = pop_operand(s);        
    push_binary_operation(s, y * x); 
}

void division(STACK *s) {            
    long double x = pop_operand(s),       
                y = pop_operand(s);       
    push_binary_operation(s, y / x); 
}

void power(STACK *s) {                   
    long double x = pop_operand(s),          
                y = pop_operand(s);           
    push_binary_operation(s, pow(y,x));
} 

void module(STACK *s) {         
    int x = pop_INT(s),              
        y = pop_INT(s);              
    push_binary_operation(s, y % x); 
}

void or_bitwise(STACK *s) {          
    int x = pop_INT(s),         
        y = pop_INT(s);              
    push_binary_operation(s, y | x); 
}                                

void and_bitwise(STACK *s) {       
    int x = pop_INT(s),              
        y = pop_INT(s);              
    push_binary_operation(s, y & x); 
}                                  

void xor_bitwise(STACK *s) {         
    int x = pop_INT(s),              
        y = pop_INT(s);               
    push_binary_operation(s, y ^ x);
}                                     

void not_bitwise(STACK *s) {       
    int x = pop_operand(s);       
    push_unary_operation(s, ~x); 
}

void increment(STACK *s) {           
    double x = pop_operand(s);      
    push_unary_operation(s, x + 1); 
}

void decrement(STACK *s){            
    double x = pop_operand(s);      
    push_unary_operation(s, x - 1);
}
