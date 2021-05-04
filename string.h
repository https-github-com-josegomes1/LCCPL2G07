/** @file Arquivo que contém as funções do string.c */

#ifndef STRING_H
#define STRING_H

#include "stack.h"

/** \brief cria uma string */
void create_string(STACK *s, char *string);

/** \brief concatena uma string com um elemento, nesta ordem */
void concatenate_string_element(STACK *s);

/** \brief concatena um elemento com uma string, nesta ordem */
void concatenate_element_string(STACK *s);

/** \brief concatena uma string com uma string */
void concatenate_string_string(STACK *s);

/** \brief função intermédia para determinar o tipo de concatenação (string->string, elemento->string, string->elemento) */
void concatenate_string(STACK *s);

/** \brief copia a mesma string N vezes para dentro de uma só string */
void multiply_string(STACK *s);

/** \brief dá o tamanho da string */
void string_length(STACK *s);

/** \brief obtém o elemento na posição N (index) */
void string_element_by_index(STACK*s);

/** \brief remove o primeiro elemento da string e coloca no topo da stack*/
void remove_string_first_element(STACK *s);

/** \brief remove o ultimo elemento da string e colcoa no topo da stack */
void remove_string_last_element(STACK *s);

/** \brief  vai buscar N caracteres do início da string */
void get_string_elements_by_first (STACK *s);

/** \brief  vai buscar N caracteres do fim da string */
void get_string_elements_by_last (STACK *s);

/** \brief procura uma substring e devolve o indice que ela ocorre ou -1 se não ocorrer */
void search_substring(STACK *s);

/** \brief separa uma string de acordo com a substring passada com parâmetro delimits */
void separate_string(STACK *s, char *delimits);

/** \brief separa uma string por substrings em um array */
void separate_string_by_substring(STACK *s);

/** \brief separa uma string por espaços brancos em um array */
void separate_string_by_whitespace(STACK *s);

/** \brief separa uma string por novas linhas em um array */
void separate_string_by_newline(STACK *s);

/** \brief função intermédia para determinar que tipo de comparação de strings é */
void compare_strings(STACK *s);

/** \brief compara se uma string é menor do que outra */
void compare_less_than_strings(STACK *s);

/** \brief compara se uma string é maior do que outra */
void compare_greater_than_strings(STACK *s);

/** \brief coloca no topo da stack a menor string entre as duas em comparação */
void get_lower_string(STACK *s);

/** \brief coloca no topo da stack a maior string entre as duas em comparação */
void get_greater_string(STACK *s);

#endif
