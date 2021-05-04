/** @file Arquivo que contém as funções do parser.c */

#ifndef PARSER_H
#define PARSER_H

#include "stack.h"
#include "tokenizer.h"

/** \brief da parse das variáveis */
void parse_variables(STACK *s, char *token);

/** \brief converte o token em INT ou DOUBLE*/
void parse_number(STACK *s, char *token);

/** \brief converte o token em array e analisa o conteúdo do mesmo */
void parse_array(STACK *s, char *token);

/** \brief converte o token em bloco */
void parse_block(STACK *s, char *token);

/** \brief função intermédia para determinar é o tipo de operando correspondente ao token */
int get_operands_state(char *token);

/** \brief função intermédia para efetuar o parse de um operando */
int parse_operands(STACK *s, char *token);

/** \brief função intermédia para determinar é o tipo de operador correspondente ao token */
int get_operation_state(STACK *s, char *token);

/** \brief função intermédia para efetuar uma operação */
void parse_operations(STACK *s, char *token);

/** \brief faz parse de um operando ou operador */
void parse (STACK *s, char *token);

/** \brief da parse dos tokens presentes na struct tokenizer */
void parse_tokens(STACK *s, TOKENIZER *tokenizer);

#endif
