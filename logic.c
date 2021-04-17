#include "stack.h"
#include "math.h"

void Is_equal(STACK *s) {       // 1 5 3 <- STACK -> VALORES  <> 3 2 2.0 <- STACK -> VALORES
    double x = pop_operand(s),  // 1 5   <- pop   -> 3        <> 3 2     <- pop   -> 2.0
           y = pop_operand(s);  // 1     <- pop   -> 5        <> 3       <- pop   -> 2
    push_INT(s, y == x);        // 1 0   <- push  -> (5==3)=0 <> 3 1     <- push  -> (2==2.0)=1
}

void Is_lower(STACK *s) {      // 1 5 3 <- STACK -> VALORES  <> 2 3 5.1 <- STACK -> VALORES
    double x = pop_operand(s), // 1 5   <- pop   -> 3        <> 2 3     <- pop   -> 5.1
           y = pop_operand(s); // 1     <- pop   -> 5        <> 2       <- pop   -> 3
    push_INT(s, y < x);        // 1 0   <- push  -> (5<3)=0  <> 2 1     <- push  -> (3<5.1)=1
}

void Is_greater(STACK *s) {    // 1 5 3 <- STACK -> VALORES  <> 2 3 5.1 <- STACK -> VALORES
    double x = pop_operand(s), // 1 5   <- pop   -> 3        <> 2 3     <- pop   -> 5.1
           y = pop_operand(s); // 1     <- pop   -> 5        <> 2       <- pop   -> 3
    push_INT(s, y > x);        // 1 1   <- push  -> (5>3)=1  <> 2 0     <- push  -> (3>5.1)=0
}

void negate(STACK*s) {         // 5 0 <- STACK -> VALORES  <> 7 3 <- STACK -> VALORES
    double x = pop_operand(s); // 5   <- pop   -> 0        <> 7   <- pop   -> 3
    push_INT(s, !x);           // 5 1 <- push  -> !0 = 1   <> 7 0 <- push  -> !3 = 0
}

void get_lower(STACK *s) {                              // 1 5 3 <- STACK -> VALORES
    double x = pop_operand(s),                          // 1 5   <- pop   -> 3
           y = pop_operand(s);                          // 1     <- pop   -> 5
    if (x < y) {push(s, s->stack[s->pos + 2]);return;}  // 1 3   <- push  -> 3<5 -> 3
    push(s, s->stack[s->pos + 1]); // Se a stack inicial fosse -> 1 3 5 <- iria cair neste caso 
}                                  // esta função sempre da push no menor valor entre os dois do topo   

void get_greater(STACK *s) {                           // 1 3 5 <- STACK -> VALORES
    double x = pop_operand(s),                         // 1 3   <- pop   -> 5
           y = pop_operand(s);                         // 1     <- pop   -> 3
    if (x > y) {push(s, s->stack[s->pos + 2]);return;} // 1 5   <- push  -> 5>3 -> 5 
    push(s, s->stack[s->pos + 1]); // Se a stack inicial fosse -> 1 5 3 <- iria cair neste caso
}                                  // esta função sempre da push no maior valor entre os dois do topo 

void or_logic(STACK *s) {                          // 3 0 5 <- STACK -> VALORES
    double x = pop_operand(s),                     // 3 0   <- pop   -> 5
           y = pop_operand(s);                     // 3     <- pop   -> 0
    if (y) {push(s, s->stack[s->pos + 1]);return;} // 3 5   <- push  -> 0 ou 5 -> 5
    // segundo a regra desta linguagem, quando ambos são diferentes de 0, damos push ao elemento da esquerda
    // portanto nem precisamos testar o outro caso se y for diferente de 0 (o y é o elemento da esquerda)
    if (x) {push(s, s->stack[s->pos + 2]);return;}
    push_INT(s, 0); // só cai neste caso quando ambos x e y são 0, sendo 0 ou 0 = 0
}

void and_logic(STACK *s) {                          // 3 5 0 <- STACK -> VALORES
    double x = pop_operand(s),                      // 3 5   <- pop   -> 0
           y = pop_operand(s);                      // 3     <- pop   -> 5
    if (x == 0 || y == 0) {push_INT(s, 0); return;} // 3 0   <- push  -> 5 e 0 -> 0
    push(s, s->stack[s->pos + 2]); // só cai neste caso quando ambos x e y são diferentes de 0
    // e portanto segundo a regra desta linguagem, damos push no elemento que está a direita
}

void if_then_else (STACK *s) {       // 1 2 3 <- STACK -> VALORES   <> 0 2 3 <- STACK -> VALORES
    DATA ELSE = pop(s),              // 1 2   <- pop   -> 3         <> 0 2   <- pop   -> 3
         THEN = pop(s);              // 1     <- pop   -> 2         <> 0     <- pop   -> 2
    double IF = pop_operand(s);      //       <- pop   -> 1         <>       <- pop   -> 0
    if (IF) {push(s, THEN); return;} // 2     <- push  -> if(1)->2  <>       
    push(s, ELSE);                   //                             <> 3     <- push  -> if(0)->3
}