/** @file Arquivo que contém as funções do stackManipulation.c */

#ifndef STACK_MANIPULATION_H
#define STACK_MANIPULATION_H

#include "stack.h"

/** \brief duplica o topo da stack*/
void duplicate_top(STACK *s);

/** \brief troca os 2 elementos do topo da stack*/
void swap_top(STACK *s);

/** \brief roda os 3 elementos do topo da stack*/
void rotate_top(STACK *s);

/** \brief copia o n-ésimo elemento para o topo da stack*/
void copy_nth_element(STACK *s);

/** \brief Converte o topo da stack para um inteiro */
void convert_stack_to_int(STACK *s);

/** \brief Converte o topo da stack para um float */
void convert_stack_to_float(STACK *s);

/** \brief Converte o topo da stack para um char */
void convert_stack_to_char(STACK *s);

/** \brief Converte o topo da stack para uma string */
void convert_stack_to_string(STACK *s);

#endif
