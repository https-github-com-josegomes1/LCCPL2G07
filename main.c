/**
 * 
 * @file Ficheiro principal do programa
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "parser.h"
#include "stack.h"

/**
 * \brief Esta é a função principal do programa
 *
 * @returns o valor 0
 *  
 */

int main () {

    char line[10240];

    assert (fgets(line, 10240, stdin) != NULL);
    assert ( line [strlen(line) - 1] == '\n');

    parse(line);
    PrintStack();
    

    return 0;
}