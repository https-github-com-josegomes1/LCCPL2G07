/** @file Arquivo que contém as funções do handle_operations.c */

#ifndef HANDLE_OPERATIONS_H
#define HANDLE_OPERATIONS_H

#include "stack.h"

/** \brief função intermédia que passa para outra função efetuar uma operação aritmética conforme o token */
void handle_arithmetic_operation (STACK *s, char *token);

/** \brief função intermédia que passa para outra função efetuar uma operação lógica conforme o token */
void handle_logic_operation (STACK *s, char *token);

/** \brief função intermédia que passa para outra função efetuar uma operação envolvendo string conforme o token */
void handle_string_operation (STACK *s, char *token);

/** \brief função intermédia que passa para outra função efetuar uma operação envolvendo array conforme o token */
void handle_array_operation (STACK *s, char *token);

/** \brief função intermédia que passa para outra função efetuar uma operação de stack conforme o token */
void handle_stack_operation (STACK *s, char *token);

/** \brief função intermédia que passa para outra função efetuar uma operação de input/output conforme o token */
void handle_input_output_operation (STACK *s, char *token);

/** \brief função intermédia que passa para outra função efetuar uma operação envolvendo bloco conforme o token */
void handle_block_operation(STACK *s, char *token);

#endif