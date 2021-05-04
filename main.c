/** @file Ficheiro principal do programa */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tokenizer.h"
#include "stack.h"
#include "parser.h"
#include "IO.h"
#include "variables.h"

/** \brief função principal do programa: cria os componentes necessários e chama as funções para efetuar a análise da linha lida */

int main () {

    STACK *s = create_stack();
    TOKENIZER *tokenizer = NULL;

    default_variables_value(s);
    default_variables_type(s);

    char line[10240];
    assert(fgets(line, 10240, stdin) != NULL);

    tokenizer = tokenize(tokenizer, line);

    parse_tokens(s, tokenizer);

    print_stack(s);

    return 0;
}
