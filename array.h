/** @file Arquivo que contém as funções do array.c */

#ifndef ARRAY_H
#define ARRAY_H

#include "stack.h"

/** \brief recebe um token do tipo array e obtém o conteúdo que está entre os "[" e "]" mais externos */
char* get_array_content(char *array);

/** \brief da pop a N elementos da stack, corresponde ao tamanho do array e coloca todos eles em um array */
void create_array(STACK * s, int size);

/** \brief da o tamanho de um array ou cria um array com range N*/
void range_array(STACK * s);

/** \brief copia o mesmo array N vezes para dentro de um só array */
void multiply_array(STACK * s);

/** \brief devolve o elemento corresponde ao index */
void array_element_by_index(STACK * s);

/** \brief coloca todos os elementos do array na stack */
void array_to_stack(STACK * s);

/** \brief concatena um array e um elemento */
void concatenate_array_element(STACK *s);

/** \brief concatena um elemento e um array */
void concatenate_element_array(STACK *s);

/** \brief concatena um array e um array */
void concatenate_array_array (STACK *s);

/** \brief função intermédia para determinar o tipo de concatenação (array->array, elemento->array, array->elemento) */
void concatenate_array(STACK *s);

/** \brief remove o primeiro elemento do array e coloca no topo da stack */
void remove_array_first_element(STACK *s);

/** \brief remove o último elemento do array e coloca no topo da stack */
void remove_array_last_element(STACK *s);

/** \brief vai buscar N elementos do início do array */
void get_array_elements_by_first (STACK *s);

/** \brief vai buscar N elementos do fim do array */
void get_array_elements_by_last (STACK *s);

#endif