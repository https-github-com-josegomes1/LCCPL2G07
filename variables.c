/** @file Ficheiro que contém as funcionalidades relativas as variáveis */

#include "stack.h"

void default_variables_value(STACK *s) { // LETRA CORRESPONDENTE AO NÚMERO NO INDEX
    s->variables[0].INT = 10;            // A
    s->variables[1].INT = 11;            // B
    s->variables[2].INT = 12;            // C
    s->variables[3].INT = 13;            // D
    s->variables[4].INT = 14;            // E
    s->variables[5].INT = 15;            // F
    s->variables[13].STRING = "\n";      // N
    s->variables[18].STRING = " ";       // S
    s->variables[23].INT = 0;            // X
    s->variables[24].INT = 1;            // Y
    s->variables[25].INT = 2;            // Z
}

void default_variables_type(STACK *s) { // LETRA CORRESPONDENTE AO NÚMERO NO INDEX 
    s->variables[0].type = INT;         // A
    s->variables[1].type = INT;         // B
    s->variables[2].type = INT;         // C
    s->variables[3].type = INT;         // D
    s->variables[4].type = INT;         // E
    s->variables[5].type = INT;         // F
    s->variables[13].type = STRING;     // N
    s->variables[18].type = STRING;     // S
    s->variables[23].type = INT;        // X  
    s->variables[24].type = INT;        // Y
    s->variables[25].type = INT;        // Z
}

void push_variables(STACK *s, char *token) { // As variáveis estão entre 'A' e 'Z' e o *token representa uma variável
    push(s, s->variables[*token - 'A']);     // logo, por exemplo, se o *token for 'A', temos 'A' - 'A' que é a posição 0 do array
}                                            // Assim, vamos dar push do elemento que está no array variables na posição 0

void copy_top_to_variable(STACK *s, char *token) {
    token++; // para passar a frente o ":" e ir buscar a variável que está entre 'A' e 'Z' (correspondente ao *token agora)
    s->variables[*token - 'A'] = top(s); // logo, por exemplo, se o *token for 'B', temos 'B' - 'A' que é a posição 1 do array
}                                        // Assim, vamos copiar o elemento que está no topo da stack para o array variables na posição 1  