/** @file Arquivo que contém as funções do parser.c e os typedefs dos apontadores para função */

#ifndef PARSE_H
#define PARSE_H

#include "stack.h"

/** \brief resultante do token "+", efetua uma operação consoante o tipo do elemento */
void parse_plus(STACK *s);

/** \brief resultante do token "*", efetua uma operação consoante o tipo do elemento */
void parse_asterisk(STACK *s);

/** \brief resultante do token "/", efetua uma operação consoante o tipo do elemento */
void parse_slash(STACK *s);

/** \brief resultante do token "(", efetua uma operação consoante o tipo do elemento */
void parse_left_parenthesis(STACK *s);

/** \brief resultante do token ")", efetua uma operação consoante o tipo do elemento */
void parse_right_parenthesis(STACK *s);

/** \brief resultante do token "%", efetua uma operação consoante o tipo do elemento */
void parse_percentage(STACK *s);

/** \brief resultante do token "~", efetua uma operação consoante o tipo do elemento */
void parse_tilde(STACK *s);

/** \brief resultante do token "=", efetua uma operação consoante o tipo do elemento */
void parse_equal(STACK *s);

/** \brief resultante do token "<", efetua uma operação consoante o tipo do elemento */
void parse_less_than(STACK *s);

/** \brief resultante do token ">", efetua uma operação consoante o tipo do elemento */
void parse_more_than(STACK *s);

/** \brief para não haver conflitos de tipo, esta função passa como intermédia para fazer o pop */
void parse_pop(STACK *s);

/** \brief converte uma string em número e da push deste para stack */
void parse_number(STACK *s, char *token);

/** \brief Compara o token com o array de tokens possíveis e passa para outra função efetuar a operação*/
void parse_operators(STACK *s, char *token);

/** \brief Analise se o token é um operando e em caso positivo, passa para outra função */
int parse_operands(STACK *s, char *token);

/** \brief Divide a string em tokens e passa-os para outra função analisar */
void parse(STACK *s, char*);

/** \brief parse_operators_function - apontador para funções de operadores */
typedef void (*parse_operators_function)(STACK*s);

/** \brief parse_operands_function - apontador para funções de operandos */
typedef void (*parse_operands_function) (STACK*s, char *token);

#endif
