/** @file Arquivo que contém as funções do lexer.c */

#ifndef LEXER_H
#define LEXER_H

#include "parser.h"

/** \brief Define todos os tokens dos operadores */
char** get_operators_token();

/** \brief Define todas as funções dos operadores */
parse_operators_function* get_operators_function();

/** \brief Define o estado das condições dos operandos*/
int* get_operands_state(char *token);

/** \brief Define todas as funções dos operandos */
parse_operands_function* get_operands_function();

#endif