/** @file Arquivo que contém as funções do tokenizer.c */

#ifndef TOKENIZER_H
#define TOKENIZER_H

/** a struct que carrega os tokens */

typedef struct tokenizer {
    char *token; /**< o token */
    struct tokenizer *next_token; /**< o próximo token */
} TOKENIZER;

/** \brief obtém o token da string */
char* get_string_token(char **line);

/** \brief obtém o token do array */
char* get_array_token(char **line);

/** \brief obtém o token do bloco */
char* get_block_token (char **line);

/** \brief obtém o token dos que não são nem array, nem string, nem bloco */
char* get_default_token(char **line);

/** \brief adiciona um token à struct tokenizer */
TOKENIZER* add_token(TOKENIZER *tokenizer, char *token);

/** \brief separa a linha recebida (string) em tokens */
TOKENIZER* tokenize (TOKENIZER *tokenizer, char *line);

#endif
