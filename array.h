/** @file Arquivo que contém as funções do array.c que precisam ser passadas entre arquivos */

#ifndef array_H
#define array_H

void create_array(STACK *s, int size);
void range_array(STACK * s);
void multiply_array(STACK * s);
void element_by_index(STACK * s);
void array_to_stack(STACK * s);
void concatenate_array(STACK *s);
void remove_first_element(STACK *s);
void remove_last_element(STACK *s);
void get_elements_by_first(STACK *s);
void get_elements_by_last(STACK *s);

#endif