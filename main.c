#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"
#include "parser.h"
#include "IO.h"

int main () {

    STACK s;
    char line[10240];

    create_stack(&s);
    default_variables(&s);

    assert(fgets(line, 10240, stdin) != NULL);

    parse(&s, line);

    print_stack(&s);

    return 0; 

}
