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

int potencia (int, int);

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
        
        else if (strcmp(token, "+") == 0) {

            pop_double(&operando1, &operando2);
            push(operando1 + operando2);

        }

        else if (strcmp(token, "-") == 0) {

            pop_double(&operando1, &operando2);
            push(operando1 - operando2);

        }

        else if (strcmp(token, "*") == 0) {

            pop_double(&operando1, &operando2);
            push(operando1 * operando2);

        }
        
        else if (strcmp(token, "#") == 0) {

            pop_double(&operando1, &operando2);
            push(potencia(operando1, operando2));

        }

        else if (strcmp(token, "/") == 0) {

            pop_double(&operando1, &operando2);
            push(operando1 / operando2);

        }

        else if (strcmp(token, "%") == 0) {

            pop_double(&operando1, &operando2);
            push(operando1 % operando2);

        }

        else if (strcmp(token, "&") == 0) {

            pop_double(&operando1, &operando2);
            push(operando1 & operando2);

        }

        else if (strcmp(token, "|") == 0) {

            pop_double(&operando1, &operando2);
            push(operando1 | operando2);

        }

        else if (strcmp(token, "^") == 0) {

            pop_double(&operando1, &operando2);
            push(operando1 ^ operando2);

        }

        else if (strcmp(token, "(") == 0) {

            operando1 = pop();
            push(--operando1);

        }

        else if (strcmp(token, ")") == 0) {

            operando1 = pop();
            push(++operando1);

        }
        
        else if (strcmp(token, "~") == 0) {

            operando1 = pop();
            push(~operando1);

        }

    }

}

/**
 * \brief Esta função faz a operação de exponenciação 
 */

int potencia (int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}
