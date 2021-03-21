/**
 * @file Ficheiro que contém as funcionalidades relativas ao parser do projeto
 * 
 * 
 */
#include <assert.h>
#include "parser.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * \brief Esta função divide a linha em tokens e interpreta os mesmos
 * 
 * @param line A linha lida do stdin 
 */

void parse(char * line) {

    char *delimits = " \t\n";
    char *sobra;

    long operando1;
    long operando2;

    for (char * token = strtok(line, delimits); token != NULL; token = strtok(NULL, delimits)) {

        operando1 = strtol(token, &sobra, 10);

        if (strlen(sobra) == 0) {

            push(operando1);

        }
