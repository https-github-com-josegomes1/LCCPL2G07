/** @file Arquivo que contém as funções do stack.c e algumas estruturas de dados importantes */

#ifndef STACK_H
#define STACK_H

/** a enumeração dos tipos que os elementos podem ter */

typedef enum {
   INT,     /**< um inteiro */
   DOUBLE,  /**< um double */
   CHAR,    /**< um char */
   STRING,  /**< uma string */
   ARRAY    /**< um array */
} TYPE;

/** \struct struct que carrega a forma dos elementos da stack */

typedef struct data {
   TYPE type; /**< o tipo do elemento */
   union {
      int INT; /**< o elemento quando int */
      double DOUBLE; /**< o elemento quando double */
      char CHAR; /**< o elemento quando char */
      char *STRING; /**< o elemento quando string */
   };

} DATA;

/** \struct a stack do programa */

typedef struct stack {
   DATA *stack; /**< os elementos da stack */
   DATA *variables; /**< as variáveis */
   int size; /**< o tamanho da stack */
   int pos; /**< a posição em que se encontra o elemento do topo da stack */
} STACK;

/** \brief Inicializa os valores da stack */ 
STACK* create_stack ();

/** \brief adiciona um elemento ao topo da stack */ 
void push(STACK *s, DATA elem);

/** \brief "retira" um elemento do topo da stack */ 
DATA pop(STACK *s);

/** \brief devolve o elemento que está no topo da stack */ 
DATA top (STACK *s);

/** \brief da push a um elemento resultante de uma operação unária, consoante o seu tipo */ 
void push_unary_operation(STACK *s, double val);

/** \brief da push a um elemento resultante de uma operação binária, consoante o seu tipo */ 
void push_binary_operation(STACK *s, double val);

/** \brief devolve o elemento do topo da stack consoante o seu tipo */ 
double pop_operand(STACK *s);

/** \brief declaração das funções push e pop dos tipos STRING, CHAR, DOUBLE, INT*/
#define STACK_OPERATION_PROTO(_type, _name) \
   void push_##_name(STACK *s, _type);      \
   _type pop_##_name(STACK *s);             

STACK_OPERATION_PROTO(int, INT)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char*, STRING)

#endif
