/** @file Arquivo que contém as funções do stack.c que precisam ser passadas entre arquivos */

#ifndef STACK_H
#define STACK_H

typedef enum {INT, DOUBLE, CHAR, STRING, ARRAY} TYPE;

typedef struct data {
   TYPE type;
   union {
      int INT;
      double DOUBLE;
      char CHAR;
      char *STRING;
      struct {
         struct data *elems;
         int size;
      } ARRAY;
   };

} DATA;

typedef struct stack {
   DATA *stack;
   DATA *variables;
   int size;
   int pos;
} STACK;

void create_stack (STACK *s);

void push(STACK *s, DATA elem);

DATA pop(STACK *s);

void swap_data(STACK * s);

void rotate_top(STACK * s);

void copy_nth_element(STACK *s);

DATA top (STACK *s);

// Converts

void convert_to_char(STACK * s);
void convert_to_int(STACK * s);
void convert_to_string(STACK * s);
void convert_to_float(STACK * s);

// ...

void default_variables(STACK *s);

#define STACK_OPERATION_PROTO(_type, _name) \
   void push_##_name(STACK *s, _type);      \
   _type pop_##_name(STACK *s);             

STACK_OPERATION_PROTO(int, INT)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char*, STRING)

#endif
