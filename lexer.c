#include <stdlib.h>

#include "parser.h"
#include "math.h"
#include "stackManipulation.h"
#include "variables.h"
#include "IO.h"
#include "logic.h"

char** get_operators_token() {
    char **operators = malloc(sizeof(char**) * 100); // 100 <- tamanho reservado para os tokens
    operators[0]  = "+" ; // SOMA ou CONCATENAÇÃO
    operators[1]  = "-" ; // SUBTRAÇÃO
    operators[2]  = "*" ; // MULTIPLICAÇÃO ou CONCATENAÇÃO MÚLTIPLA
    operators[3]  = "/" ; // DIVISÃO ou SEPARAR STRING POR SUBSTRING
    operators[4]  = "(" ; // DECREMENTO ou
    operators[5]  = ")" ; // INCREMENTO ou
    operators[6]  = "%" ; // RESTO DA DIVISÃO INTEIRA ou
    operators[7]  = "#" ; // POTÊNCIA ou
    operators[8]  = "&" ; // "E" LÓGICO EM RELAÇÃO AOS BITS
    operators[9]  = "|" ; // "OU" LÓGICO EM RELAÇÃO AOS BITS
    operators[10] = "^" ; // "OU EXCLUSIVO" LÓGICO EM RELAÇÃO AOS BITS
    operators[11] = "~" ; // "NÃO" LÓGICO EM RELAÇÃO AOS BITS 
    operators[12] = "_" ; // DUPLICAR TOPO DA STACK
    operators[13] = "\\"; // TROCAR OS 2 ELEMENTOS DO TOPO DA STACK
    operators[14] = "@" ; // RODAR OS 3 ELEMENTOS DO TOPO DA STACK
    operators[15] = "$" ; // COPIA N-ÉSIMO ELEMENTO PARA O TOPO DA STACK
    operators[16] = "i" ; // CONVERTER TOPO DA STACK PARA INTEIRO
    operators[17] = "f" ; // CONVERTER TOPO DA STACK PARA FLOAT
    operators[18] = "c" ; // CONVERTER TOPO DA STACK PARA CHAR
    operators[19] = "s" ; // CONVERTER TOPO DA STACK PARA STRING
    operators[20] = "l" ; // LEITURA DE LINHA
    operators[21] = "=" ; // COMPARAR SE SÃO IGUAIS ou 
    operators[22] = "<" ; // MAIOR ou
    operators[23] = ">" ; // MENOR ou
    operators[24] = "!" ; // NEGAR
    operators[25] = "e&"; // "E" LÓGICO
    operators[26] = "e|"; // "OU" LÓGICO
    operators[27] = "e>"; // COLOCAR O MAIOR ELEMENTO NA STACK
    operators[28] = "e<"; // COLOCAR O MENOR ELEMENTO NA STACK
    operators[29] =  "?"; // CONDIÇÃO (IF THEN ELSE)
    operators[30] = ";" ; // POP 
    return operators;
}

parse_operators_function* get_operators_function() {
    parse_operators_function *func_ptr = malloc(sizeof(parse_operators_function*) * 100); // 100 <- tamanho reservado para as funções
    func_ptr[0]  = parse_plus;                // função intermédia para determinar o tipo de operação de "+"
    func_ptr[1]  = subtraction;               // função para efetuar a operação de SUBTRAÇÃO
    func_ptr[2]  = parse_asterisk;            // função intermédia para determinar o tipo de operação de "*"
    func_ptr[3]  = parse_slash;               // função intermédia para determinar o tipo de operação de "/"
    func_ptr[4]  = parse_left_parenthesis;    // função intermédia para determinar o tipo de operação de "("
    func_ptr[5]  = parse_right_parenthesis;   // função intermédia para determinar o tipo de operação de ")"
    func_ptr[6]  = parse_percentage;          // função intermédia para determinar o tipo de operação de "%"
    func_ptr[7]  = power;                     // função para efetuar a operação de POTÊNCIA
    func_ptr[8]  = and_bitwise;               // função para efetuar a operação "E" LÓGICO EM RELAÇÃO AOS BITS
    func_ptr[9]  = or_bitwise;                // função para efetuar a operação "OU" LÓGICO EM RELAÇÃO AOS BITS
    func_ptr[10] = xor_bitwise;               // função para efetuar a operação "OU EXCLUSIVO" LÓGICO EM RELAÇÃO AOS BITS
    func_ptr[11] = parse_tilde;               // função intermédia para determinar o tipo de operação de "~"
    func_ptr[12] = duplicate_top;             // função para efetuar a operação de DUPLICAR O TOPO DA STACK
    func_ptr[13] = swap_top;                  // função para efetuar a operação de TROCAR OS 2 ELEMENTOS DO TOPO DA STACK
    func_ptr[14] = rotate_top;                // função para efetuar a operação de RODAR OS 3 ELEMENTOS DO TOPO DA STACK
    func_ptr[15] = copy_nth_element;          // função para efetuar a operação de COPIA N-ÉSIMO ELEMENTO PARA O TOPO DA STACK
    func_ptr[16] = convert_stack_to_int;      // função para efetuar a operação de CONVERTER TOPO DA STACK PARA INTEIRO
    func_ptr[17] = convert_stack_to_float;    // função para efetuar a operação de CONVERTER TOPO DA STACK PARA FLOAT
    func_ptr[18] = convert_stack_to_char;     // função para efetuar a operação de CONVERTER TOPO DA STACK PARA CHAR
    func_ptr[19] = convert_stack_to_string;   // função para efetuar a operação de CONVERTER TOPO DA STACK PARA STRING
    func_ptr[20] = read_line;                 // função para efetuar a operação de LEITURA DE LINHA
    func_ptr[21] = parse_equal;               // função intermédia para determinar o tipo de operação de "="
    func_ptr[22] = parse_less_than;           // função intermédia para determinar o tipo de operação de "<"
    func_ptr[23] = parse_more_than;           // função intermédia para determinar o tipo de operação de ">"
    func_ptr[24] = negate;                    // função para efetuar a operação de NEGAR
    func_ptr[25] = and_logic;                 // função para efetuar a operação de "E" LÓGICO
    func_ptr[26] = or_logic;                  // função para efetuar a operação de "OU" LÓGICO
    func_ptr[27] = get_greater;               // função para efetuar a operação de COLOCAR O MAIOR ELEMENTO NA STACK
    func_ptr[28] = get_lower;                 // função para efetuar a operação de COLOCAR O MENOR ELEMENTO NA STACK
    func_ptr[29] = if_then_else;              // função para efetuar a operação de CONDIÇÃO (IF THEN ELSE)
    func_ptr[30] = parse_pop;                 // função intermédia para efetuar a operação de POP (evitando erros de conflito de tipo)
    return func_ptr;
}

int* get_operands_state(char *token) {
    int *operands = malloc(sizeof(int) * 20); // 20 <- tamanho reservado para os operandos
    operands[0] = (*token >= '0' && *token <= '9') || (*token == '-' && token[1]>='0' && token[1]<='9'); // Número
    operands[1] = *token >= 'A' && *token <= 'Z'; // Variável
    operands[2] = *token == ':'; // Variável
    return operands;
}

parse_operands_function* get_operands_function() {
    parse_operands_function *func_ptr = malloc(sizeof(parse_operands_function*) * 20); // 20 <- tamanho reservado para as funções
    func_ptr[0] = parse_number; // DOUBLE ou INT
    func_ptr[1] = push_variables; // push do conteúdo da variável
    func_ptr[2] = copy_top_to_variable; // copiar topo da stack para variável
    return func_ptr;
}