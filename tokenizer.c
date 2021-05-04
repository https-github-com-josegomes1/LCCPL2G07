/** @file Ficheiro que contém as funcionalidades relativas ao tokenizer (separa em tokens) */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "stack.h"
#include "lexer.h"
#include "tokenizer.h"

char* get_string_token(char **line) {
    char* string = malloc(sizeof(char) * 10240);
    int i, quotation_marks = 0;
    for (i = 0; quotation_marks != 2; (*line)++, i++) {
        if (**line == '"') quotation_marks++;
        string[i] = **line;
    }
    string[i] = '\0';
    return string;
}

char* get_array_token(char **line) {
    char* array = malloc(sizeof(char) * 10240);
    int number_of_left_square_brackets = 1, number_of_right_square_brackets = 0, i;
    array[0] = '[';
    (*line)++;
    for (i = 1; number_of_left_square_brackets != number_of_right_square_brackets; (*line)++, i++) {
        if (**line == '[') number_of_left_square_brackets++;
        else if (**line == ']') number_of_right_square_brackets++;
        array[i] = **line;
    }
    array[i] = '\0';
    return array;
}

char* get_block_token (char **line) {
    char* block = malloc(sizeof(char) * 10240);
    int number_of_left_brackets = 1, number_of_right_brackets = 0, i;
    block[0] = '{';
    (*line)++;
    for (i = 1; number_of_left_brackets != number_of_right_brackets; (*line)++, i++) {
        if (**line == '{') number_of_left_brackets++;
        else if (**line == '}') number_of_right_brackets++;
        block[i] = **line;
    }
    block[i] = '\0';
    return block;
}

char* get_default_token(char **line) {
    char *token = malloc(sizeof(char) * 32);
    int i = 0;
    for (i = 0; **line != ' ' && **line != '\0'; (*line)++, i++) {
        token[i] = **line;
    }
    token[i] = '\0';
    return token;
}

TOKENIZER* add_token(TOKENIZER *tokenizer, char *token) {
    TOKENIZER *new_token = malloc(sizeof(TOKENIZER));
    new_token->token = token;
    new_token->next_token = NULL;

    if (tokenizer == NULL) tokenizer = new_token;
    else {
        TOKENIZER *current = tokenizer;
        for (; current->next_token != NULL; current = current->next_token);
        current->next_token = new_token;
    }
    return tokenizer;
}

TOKENIZER* tokenize (TOKENIZER *tokenizer, char *line) {
    for (; *line != '\0'; line++) {
        char *token;
        switch(*line) {
            case ' ': continue;
            case '{': token = get_block_token(&line); break;
            case '"': token = get_string_token(&line); break;
            case '[': token = get_array_token(&line); break;
            default: token = get_default_token(&line);
        }
        tokenizer = add_token(tokenizer, token);
    }
    return tokenizer;
} 