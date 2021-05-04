/** @file Arquivo que contém as funções do lexer.c */

#ifndef LEXER_H
#define LEXER_H

#include "stack.h"

/** \brief determina se o token corresponde a uma operação aritmética */
int Is_arithmetic_operation(STACK *s, char *token);

/** \brief determina se o token corresponde a uma operação lógica */
int Is_logic_operation (STACK *s, char *token);

/** \brief determina se o token corresponde a uma operação envolvendo array */
int Is_array_operation(STACK *s, char *token);

/** \brief determina se o token corresponde a uma operação envolvendo string */
int Is_string_operation(STACK *s, char *token);

/** \brief determina se o token corresponde a uma operação de stack */
int Is_stack_operation(STACK *s, char *token);

/** \brief determina se o token corresponde a uma operação de input/output */
int Is_input_output_operation(STACK *s, char *token);

/** \brief determina se o token corresponde a uma operação envolvendo bloco */
int Is_block_operation(STACK *s, char *token);

/** \brief determina se o token é um número */
int Is_token_number(char *token);

/** \brief determina se o token é um array */
int Is_token_array(char *token);

/** \brief determina se o token é uma string */
int Is_token_string(char * token);

/** \brief determina se o token é uma variável */
int Is_token_variable(char * token);

/** \brief determina se o token é um bloco */
int Is_token_block(char * token);

#endif
