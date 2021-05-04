/** @file Ficheiro que contém as funcionalidades relativas ao bloco */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "parser.h"
#include "stackManipulation.h"
#include "array.h"

char* get_block_content(char *block) {
    block++;
    char* content = malloc(sizeof(char) * 10240);
    int number_of_left_brackets = 1, number_of_right_brackets = 0, i;
    for (i = 0; number_of_left_brackets != number_of_right_brackets; block++, i++) {
        if (*block == '{') number_of_left_brackets++;
        else if (*block == '}') number_of_right_brackets++;
        content[i] = *block;
    }
    content[i - 1] = '\0';
    return content;
}

void execute_block(STACK *s) {
    char *block = pop_BLOCK(s),
         *block_content = get_block_content(block);
    TOKENIZER *tokenizer = NULL;
    tokenizer = tokenize(tokenizer, block_content);
    parse_tokens(s, tokenizer);
}

void apply_block_to_string(STACK *s) {
    char *block = pop_BLOCK(s),
         *block_content = get_block_content(block),
         *string = pop_STRING(s),
         *new_string = strdup(string);
    int i = 0;
    TOKENIZER *tokenizer = NULL;
    for (; string[i] != '\0'; i++) {
        push_CHAR(s, string[i]);
        tokenizer = NULL;
        tokenizer = tokenize(tokenizer, block_content);
        parse_tokens(s, tokenizer);
    }
    new_string[i] = '\0';
    for (i--; i >= 0; i--) {
        new_string[i] = pop_CHAR(s);
    }
    push_STRING(s, new_string);
}

void apply_block_to_array(STACK *s) {
    char *block = pop_BLOCK(s),
         *block_content = get_block_content(block);
    DATA a = pop(s);
    TOKENIZER *tokenizer = NULL;
    for (int i = 0; i < a.array.size; i++) {
        push(s, a.array.elems[i]);
        tokenizer = NULL;
        tokenizer = tokenize(tokenizer, block_content);
        parse_tokens(s, tokenizer);
    }
    create_array(s, a.array.size);
}

void apply_block_to(STACK *s) {
    if (s->stack[s->pos - 1].type == ARRAY) apply_block_to_array(s);
    else if (s->stack[s->pos - 1].type == STRING) apply_block_to_string(s);
}

void fold_array(STACK *s) {
    char *block = pop_BLOCK(s),
         *block_content = get_block_content(block);
    TOKENIZER *tokenizer = NULL;
    tokenizer = tokenize(tokenizer, block_content);
    if (!(s->stack[s->pos].type == ARRAY || s->stack[s->pos].type == STRING)) {
        create_array(s, s->pos + 1);
    }

    DATA a = pop(s);
    push(s, a.array.elems[0]);
    for (int i = 1; i < a.array.size; i++) {
        push(s, a.array.elems[i]);
        parse_tokens(s, tokenizer);
    }
    create_array(s , 1);
}

void filter_array(STACK *s) {
    DATA block = pop(s);
    duplicate_top(s);
    push(s, block);
    apply_block_to_array(s);
    DATA conditions = pop(s), a = pop(s);
    int size = 0;
    for (int i = 0; i < conditions.array.size; i++) {
        if (conditions.array.elems[i].INT) {
            push(s, a.array.elems[i]);
            size++;
        }
    }
    create_array(s, size);
}

void filter_string(STACK *s) {
    DATA block = pop(s);
    duplicate_top(s);
    push(s, block);
    apply_block_to_string(s);
    char * conditions = pop_STRING(s), *string = pop_STRING(s);
    int size = 0;
    for (int i = 0; string[i]; i++) {
        if (conditions[i] != '\0') {
            push_CHAR(s, string[i]);
            size++;
        }
    }
    char *new_string = malloc(sizeof(char) * 10240);
    for (int i = size - 1; i >= 0; i--) {
        new_string[i] = pop_CHAR(s);
    }
    push_STRING(s, new_string);
}

void filter_by_block(STACK *s) {
    if (s->stack[s->pos - 1].type == ARRAY) filter_array(s);
    else if (s->stack[s->pos - 1].type == STRING) filter_string(s);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_STRINGS(char **x, char **y) {
    char *temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort_String(int pos_array[], char* strings[], int N) {
   int i, j;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                swap_STRINGS(&strings[j], &strings[j + 1]);
                swap(&pos_array[j], &pos_array[j + 1]);
            }
        }
    }
}

void bubbleSort(int pos_array[], int array[], int N) {
   int i, j;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swap(&pos_array[j], &pos_array[j + 1]);
            }
        }
    }
}

void sort_by_number(STACK *s, int array_size, int pos_array[]) {
    int array[array_size];
    for (int i = array_size - 1; i >= 0; i--) {
        array[i] = pop_INT(s);
        pos_array[i] = i;
    }
    bubbleSort(pos_array, array, array_size);
}

void sort_by_string(STACK *s, int array_size, int pos_array[]) {
    char* strings[array_size];
    for (int i = array_size - 1; i >= 0; i--) {
        strings[i] = pop_STRING(s);
        pos_array[i] = i;
    }
    bubbleSort_String(pos_array, strings, array_size);
}

void sort_by_block(STACK *s) {
    DATA block = pop(s);
    duplicate_top(s);
    push(s, block);
    apply_block_to_array(s);
    int array_size = s->stack[s->pos].array.size;
    int pos_array[array_size];
    array_to_stack(s);
    if (has_type(top(s), NUMBER)) {
        sort_by_number(s, array_size, pos_array);
    }
    else if (has_type(top(s), STRING)) {
        sort_by_string(s, array_size, pos_array);
    }
    DATA a = pop(s);
    for (int i = 0; i < array_size; i++) {
        push(s, a.array.elems[pos_array[i]]);
    }
    create_array(s, array_size);
}

void execute_while_true(STACK *s) {
    DATA block = top(s);
    execute_block(s);
    if (pop_operand(s) != 0) {
        push(s, block);
        execute_while_true(s);
    }
}
