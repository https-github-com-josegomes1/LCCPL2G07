/** @file Ficheiro principal do programa */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"
#include "parser.h"
#include "IO.h"
#include "variables.h"

/** \brief função principal do programa 
 * Inicializa as variáveis, recebe o input do usuário e faz parse da string obtida
 */

int main () {

    STACK *s = create_stack();
    default_variables_value(s);
    default_variables_type(s);

    char line[10240];
    assert(fgets(line, 10240, stdin) != NULL);
    parse(s, line);

    print_stack(s);
    return 0; 

}
