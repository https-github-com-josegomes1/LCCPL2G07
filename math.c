/** @file Ficheiro que contém as funcionalidades relativas a operações aritmética */

#include <math.h>
#include "stack.h"

void sum(STACK *s) {                  // 1 2 3 <- STACK -> VALORES <> 3 1.5 2 <- STACK -> VALORES
    double x = pop_operand(s),        // 1 2   <- pop   -> 3       <> 3 1.5   <- pop   -> 2
           y = pop_operand(s);        // 1     <- pop   -> 2       <> 3       <- pop   -> 1.5
    push_binary_operation(s, y + x);  // 1 5   <- push  -> 2+3=5   <> 3 3.5   <- push  -> 1.5+2=3.5
}

void subtraction(STACK *s) {          // 1 5 3 <- STACK -> VALORES <> 3 2 0.5 <- STACK -> VALORES
    double x = pop_operand(s),        // 1 5   <- pop   -> 3       <> 3 2     <- pop   -> 0.5
           y = pop_operand(s);        // 1     <- pop   -> 5       <> 3       <- pop   -> 2
    push_binary_operation(s, y - x);  // 1 2   <- push  -> 5-3=2   <> 3 1.5   <- push  -> 2-0.5=1.5
}

void multiplication(STACK *s) {       // 1 2 3 <- STACK -> VALORES <> 1 2.3 3 <- STACK -> VALORES
    double x = pop_operand(s),        // 1 2   <- pop   -> 3       <> 1 2.3   <- pop   -> 3 
           y = pop_operand(s);        // 1     <- pop   -> 2       <> 1       <- pop   -> 2.3
    push_binary_operation(s, y * x);  // 1 6   <- push  -> 2*3=6   <> 1 6.9   <- push  -> 2.3*3=6.9
}

void division(STACK *s) {            // 1 7 3 <- STACK -> VALORES <> 1 7.0 3 <- STACK -> VALORES
    double x = pop_operand(s),       // 1 7   <- pop   -> 3       <> 1 7.0   <- pop   -> 3
           y = pop_operand(s);       // 1     <- pop   -> 7       <> 1       <- pop   -> 7.0
    push_binary_operation(s, y / x); // 1 2   <- push  -> 7/3=2   <> 1 3.5   <- push  -> 7.0/3=3.5
}

void power(STACK *s) {                   // 1 2 3 <- STACK -> VALORES <> 1 9 0.5 <- STACK -> VALORES
    double x = pop_operand(s),           // 1 2   <- pop   -> 3       <> 1 9     <- pop   -> 0.5 
           y = pop_operand(s);           // 1     <- pop   -> 2       <> 1       <- pop   -> 9
    push_binary_operation(s, pow(y,x));  // 1 8   <- push  -> 2^3=8   <> 1 3.0   <- push  -> 9^0.5=3.0                    
}

void module(STACK *s) {               // 1 7 3 <- STACK -> VALORES
    int x = pop_INT(s),               // 1 7   <- pop   -> 3
        y = pop_INT(s);               // 1     <- pop   -> 7
    push_binary_operation(s, y % x);  // 1 1   <- push  -> 7 % 3 = 1
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
