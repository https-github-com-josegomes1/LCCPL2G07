/** @file Arquivo que contém as funções do math.c */

#ifndef MATH_H
#define MATH_H

#include "stack.h"

/** \brief efetua uma operação de soma e da push do resultado para stack */
void sum(STACK *s);

/** \brief efetua uma operação de subtração e da push do resultado para stack */
void subtraction(STACK *s);

/** \brief efetua uma operação de multiplicação e da push do resultado para stack */
void multiplication(STACK *s);

/** \brief efetua uma operação de divisão e da push do resultado para stack */
void division(STACK *s);

/** \brief efetua uma operação de potência e da push do resultado para stack */
void power(STACK *s);

/** \brief efetua uma operação de módulo (resto da divisão) e da push do resultado para stack */
void module(STACK *s);

/** \brief efetua uma operação de "ou" (em relação aos bits) e da push do resultado para stack */
void or_bitwise(STACK *s);

/** \brief efetua uma operação de "e" (em relação aos bits) e da push do resultado para stack */
void and_bitwise(STACK *s);

/** \brief efetua uma operação de "ou exclusivo" (em relação aos bits) e da push do resultado para stack */
void xor_bitwise(STACK *s);

/** \brief efetua uma operação de "negar" (em relação aos bits) e da push do resultado para stack */
void not_bitwise(STACK *s);

/** \brief efetua uma operação de incremento e da push do resultado para stack */
void increment(STACK *s);

/** \brief efetua uma operação de decremento e da push do resultado para stack */
void decrement(STACK *s);

#endif
