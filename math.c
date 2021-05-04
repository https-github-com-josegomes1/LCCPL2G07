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

void or_bitwise(STACK *s) {          // 1 2 3 <- STACK -> VALORES
    int x = pop_INT(s),              // 1 2   <- pop   -> 3
        y = pop_INT(s);              // 1     <- pop   -> 2
    push_binary_operation(s, y | x); // 1 3   <- push  -> (10) | (11) -> (11) em base 2
}                                    //                    2      3   ->  3   em decimal

void and_bitwise(STACK *s) {         // 1 2 3 <- STACK -> VALORES
    int x = pop_INT(s),              // 1 2   <- pop   -> 3
        y = pop_INT(s);              // 1     <- pop   -> 2
    push_binary_operation(s, y & x); // 1 3   <- push  -> (10) & (11) -> (10) em base 2
}                                    //                    2      3   ->  2   em decimal

void xor_bitwise(STACK *s) {          // 1 2 3 <- STACK -> VALORES <>
    int x = pop_INT(s),               // 1 2   <- pop   -> 3
        y = pop_INT(s);               // 1     <- pop   -> 2
    push_binary_operation(s, y ^ x);  // 1 3   <- push  -> (10) & (11) -> (01) em base 2
}                                     //                    2      3   ->  1   em decimal

void not_bitwise(STACK *s) {      // 1  2 <- STACK 
    int x = pop_operand(s);       // 1    <- pop  ->  2 -> (010) em base 2, complemento para 2 
    push_unary_operation(s, ~x);  // 1 -3 <- push -> (101) em base 2, complemento para 2
}                                 //                  -3   em decimal

void increment(STACK *s) {           // 3 1 <- STACK -> VALORES <> 'B' <- STACK -> VALORES   <> 0.3 <- STACK -> VALORES
    double x = pop_operand(s);       // 3   <- pop   -> 1       <>     <- pop   -> 'B'       <>     <- pop   -> 0.3
    push_unary_operation(s, x + 1); // 3 2 <- push  -> 1+1=2   <> 'C' <- push  -> 'B'+1='C' <> 1.3 <- push  -> 0.3+1=1.3
}

void decrement(STACK *s){            // 3 1 <- STACK -> VALORES <> 'B' <- STACK -> VALORES   <> 0.3 <- STACK -> VALORES
    double x = pop_operand(s);       // 3   <- pop   -> 1       <>     <- pop   -> 'B'       <>     <- pop   -> 0.3
    push_unary_operation(s, x - 1); // 3 0 <- push  -> 1-1=0   <> 'A' <- push  -> 'B'-1='A' <> 1.3 <- push  -> 0.3-1=-0.7
}
