/** @file Arquivo que contém as funções do IO.c */

#ifndef IO_H
#define IO_H

/** \brief converte uma string em um inteiro */
long convert_string_to_int(char *string);

/** \brief converte uma string em um inteiro */
double convert_string_to_double(char *string);

/** \brief verifica se o número possui um ".": verifica se é um double */
int Is_Double(char *token);

/** \brief verifica se aperação envolve um array */
int Is_array (STACK * s);

/** \brief verifica se aperação envolve uma string */
int Is_String (STACK * s);

/** \brief faz a leitura de uma linha e da push da string para a stack */
void read_line(STACK * s);

/** \brief mostra o conteúdo do array */
void print_array(STACK *s, DATA a);

/** \brief mostra o conteúdo da stack */
void print_stack(STACK *s);

/** \brief mostra o conteudo da DATA */
void print_data(STACK *s, DATA data);

/** \brief faz a leitura de todo o input do usuário até encontrar o EOF */
void read_all_input(STACK *s);

#endif
