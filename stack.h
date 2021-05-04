/** @file Arquivo que contém as funções do stack.c e algumas estruturas de dados importantes */

#ifndef STACK_H
#define STACK_H

/** a enumeração dos tipos que os elementos podem ter */

typedef enum {
   INT = 1,     /**< um inteiro */
   DOUBLE = 2,  /**< um double */
   CHAR = 4,    /**< um char */
   STRING = 8,  /**< uma string */
   ARRAY = 16, /**< um array */
   BLOCK = 32 /**< um bloco */
} TYPE;

/** \macro efetua um OU LÓGICO (bitwise) para definir o valor INTEGER como um INT ou CHAR */
#define INTEGER  (INT | CHAR)
/** \macro efetua um OU LÓGICO (bitwise) para definir o valor NUMBER como um INTEGER ou NUMBER */
#define NUMBER   (INTEGER | DOUBLE)

/** struct que defini o array */

typedef struct {
   int size; /**< o tamanho do array */
   struct data *elems; /**< os elementos do array */
} ARRAYS;

/** carrega a forma dos elementos da stack */

typedef struct data {
   TYPE type; /**< o tipo do elemento */
   /** carrega diferentes tipos de elementos */
   union {
      long INT; /**< o elemento quando int */
      double DOUBLE; /**< o elemento quando double */
      char CHAR; /**< o elemento quando char */
      char *STRING; /**< o elemento quando string */
      char *BLOCK; /**< o elemento quando bloco */
      ARRAYS array; /**< o elemento quando array */
   };

} DATA;

/** a stack do programa */

typedef struct stack {
   DATA *stack; /**< os elementos da stack */
   DATA variables[26]; /**< as variáveis */
   int size; /**< o tamanho da stack */
   int pos; /**< a posição em que se encontra o elemento do topo da stack */
} STACK;

/** \brief compara o tipo do elemento com a máscara */
int has_type(DATA elem, int mask);

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
void push_binary_operation(STACK *s, long double val);

/** \brief devolve o elemento do topo da stack consoante o seu tipo */ 
long double pop_operand(STACK *s);

/** \brief declaração das funções push e pop dos tipos STRING, CHAR, DOUBLE, INT*/
#define STACK_OPERATION_PROTO(_type, _name) \
   void push_##_name(STACK *s, _type);      \
   _type pop_##_name(STACK *s);             

STACK_OPERATION_PROTO(long, INT)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char*, STRING)
STACK_OPERATION_PROTO(char*, BLOCK)

#endif
