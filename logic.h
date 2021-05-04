/** @file Arquivo que contém as funções do logic.c */

#ifndef LOGIC_H
#define LOGIC_H

#include "stack.h"

/** \brief da push do resultado da comparação (=) entre os dois ultimos elementos */
void Is_equal(STACK *s);

/** \brief da push do resultado da comparação (<) entre os dois ultimos elementos */
void Is_lower(STACK *s);

/** \brief da push do resultado da comparação (>) entre os dois ultimos elementos */
void Is_greater(STACK *s);

/** \brief da pop a um elemento e da push do seu valor contrário */
void negate(STACK*s);

/** \brief da pop aos dois ultimos elementos e push no menor deles */
void get_lower(STACK *s);

/** \brief da pop aos dois ultimos elementos e push no maior deles */
void get_greater(STACK *s);

/** \brief efetua um "ou" lógico entre os dois últimos elementos */
void or_logic(STACK *s);

/** \brief efetua um "e" lógico entre os dois últimos elementos */
void and_logic(STACK *s);

/** \brief da push do penultimo ou ultimo elemento, consoante o elemento que está na posição corresponde ao IF */
void if_then_else (STACK *s);

/** \brief função intermédia que determina o tipo de operação do token começado em "e", podendo ser e>, e<, e| ou e& */
void logic_shortcut (STACK *s, char *token);

#endif
