/** @file Arquivo que contém as funções do IO.c que precisam ser passadas entre arquivos */

#ifndef IO_H
#define IO_H

int Is_array (STACK * s);
int Is_String (STACK * s);
void read_line(STACK * s, char * line);
void print_stack(STACK *s);
void print_data(DATA data);
void print_array(DATA a);

#endif
