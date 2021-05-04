/** @file Arquivo que contém as funções do block.c */

#ifndef BLOCK_H
#define BLOCK_H

/** \brief recebe um token do tipo bloco e obtém o conteúdo que está entre os "{" e "}" mais externos */
char* get_block_content(char *block);

/** \brief executa um bloco: da parse dos tokens presentes no bloco */
void execute_block(STACK *s);

/** \brief da parse dos tokens com cada elemento da string */
void apply_block_to_string(STACK *s);

/** \brief da parse dos tokens com cada elemento do array */
void apply_block_to_array(STACK *s);

/** \brief função intermédia para determinar se a operação do token "%" será feita em uma string ou array */
void apply_block_to(STACK *s);

/** \brief da parse dos tokens do bloco de forma a aplicar a operação entre todos elementos */
void fold_array(STACK *s);

/** \brief da parse dos tokens com cada elemento da array e mantém aqueles que estão nas condições de filtragem */
void filter_array(STACK *s);

/** \brief da parse dos tokens com cada elemento da string e mantém aqueles que estão nas condições de filtragem */
void filter_string(STACK *s);

/** \brief função intermédia para determinar se a operação do token "," será feita em uma string ou array */
void filter_by_block(STACK *s);

/** \brief ordena um array de números consoante as condições que estão dentro do bloco */
void sort_by_number(STACK *s, int array_size, int pos_array[]);

/** \brief ordena um array de strings consoante as condições que estão dentro do bloco */
void sort_by_string(STACK *s, int array_size, int pos_array[]);

/** \brief ordena um array consoante as condições que estão dentro do bloco */
void sort_by_block(STACK *s);

/** \brief executa um bloco e depois da pop de um elemento, se for diferente de 0, executa novamente */
void execute_while_true(STACK *s);

/** \brief troca o valor que está no endereço de memória entre dois inteiros */
void swap(int *x, int *y);

/** \brief troca o valor que está no endereço de memória entre duas strings */
void swap_STRINGS(char **x, char **y);

/** \brief ordena um array consoante as strings */
void bubbleSort_String(int pos_array[], char* strings[], int N);

/** \brief ordena um array consoante os inteiros */
void bubbleSort(int pos_array[], int array[], int N);

#endif
