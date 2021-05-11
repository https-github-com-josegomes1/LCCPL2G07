/** @file Ficheiro que contém as funcionalidades relativas ao array */

#include "stack.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "string.h"
#include "parser.h"

char* get_array_content(char *array) {
    array++;
    char* content = malloc(sizeof(char) * 10240);
    int number_of_left_square_brackets = 1, number_of_right_square_brackets = 0, i;
    for (i = 0; number_of_left_square_brackets != number_of_right_square_brackets; array++, i++) {
        if (*array == '[') number_of_left_square_brackets++;
        else if (*array == ']') number_of_right_square_brackets++;
        content[i] = *array;
    }
    content[i - 1] = '\0';
    return content;
}

void create_array(STACK * s, int size) {
    DATA a;
    a.type = ARRAY;
    a.array.size = size;
    a.array.elems = malloc((sizeof(ARRAYS) + sizeof(struct data)) * size);
    for (int i = size - 1; i >= 0; i--) {
        a.array.elems[i] = pop(s);
    }
    push(s, a);
}

void range_array(STACK * s) {
    if (has_type(s->stack[s->pos], INTEGER)) {
        int size = pop_operand(s);
        for (int i = 0; i < size; i++) {
            push_INT(s, i);
        }
        create_array(s, size);
    }
    else if (has_type(s->stack[s->pos], ARRAY)) {
        DATA a = pop(s);
        push_INT(s, a.array.size);
    }
}

void multiply_array(STACK * s) {
    int n_times = pop_INT(s);
    DATA a = pop(s);
    a.array.elems = realloc(a.array.elems, sizeof(struct data) * a.array.size * n_times);
    for (int i = 1; i < n_times; i++) {
        for (int j = i * a.array.size, k = 0; j < (i+1) * a.array.size; j++, k++) {
            a.array.elems[j] = a.array.elems[k];
        }
    }
    a.array.size *= n_times;
    push(s, a);
}

void array_element_by_index(STACK * s) {
    int index = pop_INT(s);
    DATA a = pop(s);
    push(s, a.array.elems[index]);
}

void array_to_stack(STACK * s) {
    DATA a = pop(s);
    for (int i = 0; i < a.array.size; i++) {
        push(s, a.array.elems[i]);
    }
}

void concatenate_array_element(STACK *s) {
    DATA elem = pop(s);
    int old_size = top(s).array.size;
    array_to_stack(s);
    push(s, elem);
    create_array(s, old_size + 1);
}

void concatenate_element_array(STACK *s) {
    DATA a = pop(s);
    DATA elem = pop(s);
    a.array.size += 1;
    a.array.elems = realloc(a.array.elems, (sizeof(ARRAYS) + sizeof(struct data)) * a.array.size);
    for (int i = a.array.size - 1; i >= 1; i--) {
        a.array.elems[i] = a.array.elems[i - 1];
    }
    a.array.elems[0] = elem;
    push(s, a);
}

void concatenate_array_array (STACK *s) {
    DATA a1 = pop(s);
    DATA a2 = pop(s);
    int size = a2.array.size + a1.array.size;
    a2.array.elems = realloc(a2.array.elems, (sizeof(ARRAYS) + sizeof(struct data)) * size);
    for (int i = a2.array.size, j = 0; i < size; i++, j++) {
        a2.array.elems[i] = a1.array.elems[j];
    }
    a2.array.size = size;
    push(s, a2);
}

void concatenate_array(STACK *s) {

    if (!has_type(s->stack[s->pos], ARRAY) && has_type(s->stack[s->pos - 1], ARRAY)) {
        concatenate_array_element(s); return;
    }

    if (has_type(s->stack[s->pos], ARRAY) && !has_type(s->stack[s->pos - 1], ARRAY)) {
        concatenate_element_array(s); return;
    }

    if (has_type(s->stack[s->pos], ARRAY) && has_type(s->stack[s->pos - 1], ARRAY)) {
        concatenate_array_array(s); return;
    }
}

void remove_array_first_element(STACK *s) {
    DATA a = pop(s);
    DATA elem = a.array.elems[0];
    for(int i = 1; i < a.array.size; i++) {
        push(s, a.array.elems[i]);
    }
    create_array(s, a.array.size - 1);
    push(s, elem);
}

void remove_array_last_element(STACK *s) {
    DATA a = pop(s);
    DATA elem = a.array.elems[a.array.size - 1];
    a.array.size -= 1;
    push(s, a);
    push(s, elem);
}

void get_array_elements_by_first (STACK *s) {
    int n_elems = pop_INT(s);
    DATA a = pop(s);
    for (int i = 0; i < n_elems; i++) {
        push(s, a.array.elems[i]);
    }
    create_array(s, n_elems);
}

void get_array_elements_by_last (STACK *s) {
    int n_elems = pop_INT(s);
    DATA a = pop(s);
    for (int i = a.array.size - n_elems; i < a.array.size; i++) {
        push(s, a.array.elems[i]);
    }
    create_array(s, n_elems);
}
