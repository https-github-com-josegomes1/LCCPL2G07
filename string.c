/** @file Ficheiro que contém as funcionalidades relativas à string */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stack.h"
#include "stackManipulation.h"
#include "array.h"

void create_string(STACK *s, char *string) {
    char *new_string = malloc(sizeof(char) * 10240);
    int i = 0;
    string++;
    for (; string[i] != '"'; i++) {
        new_string[i] = string[i];
    }
    new_string[i] = '\0';
    push_STRING(s, new_string);
}

void concatenate_string_element(STACK *s) {
    char elem = pop_CHAR(s),
         *string = pop_STRING(s);
    int length = strlen(string), i;
    char *new_string = malloc(sizeof(char) * length + 1);
    for (i = 0; string[i]; i++) {
        new_string[i] = string[i]; 
    }
    new_string[i] = elem;
    push_STRING(s, new_string);
}

void concatenate_element_string(STACK *s) {
    char *string = pop_STRING(s),
         *new_string = malloc(sizeof(char) * strlen(string)),
          elem = pop_CHAR(s);

    new_string[0] = elem;

    for (int j = 0, i = 1; string[j]; i++, j++) {
        new_string[i] = string[j];
    }
    push_STRING(s, new_string);
}

void concatenate_string_string(STACK *s) {
    char *string1 = pop_STRING(s),
         *string2 = pop_STRING(s);

    int length1 = strlen(string1),
        length2 = strlen(string2),
        i, j;
    
    char* new_string = malloc(sizeof(char) * (length1 + length2));

    for (i = 0; i < length2; i++) {
        new_string[i] = string2[i];
    }
    for (j = 0; j < length1; i++, j++) {
        new_string[i] = string1[j];
    }
    new_string[i] = '\0';
    push_STRING(s, new_string);
}

void concatenate_string(STACK *s) {
    if (s->stack[s->pos].type != STRING && s->stack[s->pos - 1].type == STRING) {
        concatenate_string_element(s); return;
    }

    if (s->stack[s->pos].type == STRING && s->stack[s->pos - 1].type != STRING) {
        concatenate_element_string(s); return;
    }

    if (s->stack[s->pos].type == STRING && s->stack[s->pos - 1].type == STRING) {
        concatenate_string_string(s); return;
    }
}

void multiply_string(STACK *s) {
    int n_times = pop_INT(s);
    char* string = pop_STRING(s);
    int length = strlen(string), i, j, k;
    char *new_string = malloc(sizeof(char) * strlen(string) * n_times);
    for (i = 0; i < n_times; i++) {
        for (j = i * length, k = 0; k < length; j++, k++) {
            new_string[j] = string[k];
        }
    }
    push_STRING(s, new_string);
}

void string_length(STACK *s) {
    DATA string = pop(s);
    int length = strlen(string.STRING);
    push_INT(s, length);
}

void string_element_by_index(STACK*s) {
    int index = pop_INT(s);
    DATA string = pop(s);
    char elem = string.STRING[index];
    push_CHAR(s, elem);
}

void remove_string_first_element(STACK *s) {
    char elem = s->stack[s->pos].STRING[0];
    s->stack[s->pos].STRING++;
    push_CHAR(s, elem);
}

void remove_string_last_element(STACK *s) {
    int length = strlen(s->stack[s->pos].STRING);
    char elem = s->stack[s->pos].STRING[length - 1];
    s->stack[s->pos].STRING[length - 1] = '\0';
    push_CHAR(s, elem);
}

void get_string_elements_by_first (STACK *s) {
    int x_elems = pop_INT(s);
    DATA string = pop(s);
    for (int i = 0; i < x_elems; i++) {
        push_CHAR(s, string.STRING[i]);
    }
}

void get_string_elements_by_last (STACK *s) {
    int x_elems = pop_INT(s);
    DATA string = pop(s);
    int length = strlen(string.STRING);
    for (int i = length - x_elems; i < length; i++) {
        push_CHAR(s, string.STRING[i]);
    }
}

void search_substring(STACK *s) {
    if (top(s).type == CHAR) convert_stack_to_string(s);
    char *substring = pop_STRING(s);
    char *string = pop_STRING(s);

    int Index = -1, length = strlen(substring);
    
    for (int i = 0, j = 0; string[i]; i++) {
        if (string[i] == substring[j]) {
            if (j == length - 1) {
                Index = i - j;
                break;
            }
            j++;
        }
        else {
            j = 0;
            if (string[i] == substring[j]) j++;
        }
    }
    push_INT(s, Index);
}

void separate_string(STACK *s, char *delimits) {
    char *original = pop_STRING(s), *string = strdup(original);
    int size = 0;
    for (char *new_string = strtok(string, delimits); new_string != NULL; new_string = strtok(NULL, delimits)) {
        push_STRING(s, new_string);
        size++;
    }
    create_array(s, size);
}

void separate_string_by_substring(STACK *s) {
    char *substring = pop_STRING(s);
    separate_string(s, substring);
}

void separate_string_by_whitespace(STACK *s) {
    separate_string(s, " \t\n");
}

void separate_string_by_newline(STACK *s) {
    separate_string(s, "\n");
}

void compare_strings(STACK *s) {
    char *string1 = pop_STRING(s);
    char *string2 = pop_STRING(s);
    if (strcmp(string1, string2) == 0) push_INT(s, 1);
    else push_INT(s, 0);
}

void compare_less_than_strings(STACK *s) {
    char *string1 = pop_STRING(s);
    char *string2 = pop_STRING(s);
    if (strcmp(string2, string1) < 0) push_INT(s, 1);
    else push_INT(s, 0);
}

void compare_greater_than_strings(STACK *s) {
    char *string1 = pop_STRING(s);
    char *string2 = pop_STRING(s);
    if (strcmp(string2, string1) > 0) push_INT(s, 1);
    else push_INT(s, 0);    
}

void get_lower_string(STACK *s) {
    char *string1 = pop_STRING(s);
    char *string2 = pop_STRING(s);
    if (strcmp(string2, string1) < 0) push_STRING(s, string2);
    else push_STRING(s, string1);    
}

void get_greater_string(STACK *s) {
    char *string1 = pop_STRING(s);
    char *string2 = pop_STRING(s);
    if (strcmp(string2, string1) > 0) push_STRING(s, string2);
    else push_STRING(s, string1); 
}