/** @file Arquivo que contém as funções do variables.c */

#ifndef VARIABLES_H
#define VARIABLES_H

#include "stack.h"

/** \brief Define os valores por omissão das variáveis*/
void default_variables_value(STACK *s);

/** \brief Define o tipo dos valores por omissão das variáveis */
void default_variables_type(STACK *s);

/** \brief Da push na stack do conteúdo da variável*/
void push_variables(STACK *s, char *token);

/** \brief Copia o topo da stack para a variável*/
void copy_top_to_variable(STACK *s, char *token);

#endif