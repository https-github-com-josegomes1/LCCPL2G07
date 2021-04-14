/** @file Ficheiro que contém as funcionalidades relativas ao array do projeto */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

/**
 * \brief Cria um array
 * da pop aos elementos da stack e vai adicionando no array
 */

void create_array(STACK * s, int size) {
    DATA a;
    a.type = ARRAY;
    a.ARRAY.size = size;
    a.ARRAY.elems = malloc(sizeof(struct data) * size);
    for (int i = size - 1; i >= 0; i--) {
        a.ARRAY.elems[i] = pop(s);
    }
    push(s, a);
}

/**
 * \brief da o tamanho do array
 */

void range_array(STACK * s) {
    if (s->stack[s->pos].type == INT) {
        int size = pop_INT(s);
        for (int i = 0; i < size; i++) {
            push_INT(s, i);
        }
        create_array(s, size);
    }
    else {
        DATA a = pop(s);
        push_INT(s, a.ARRAY.size);
    }
}

/**
 * \brief concatena multiplas vezes o array
 */

void multiply_array(STACK * s) {
    int n_times = pop_INT(s);
    DATA a = pop(s);
    a.ARRAY.elems = realloc(a.ARRAY.elems, sizeof(struct data) * a.ARRAY.size * n_times);
    for (int i = 1; i < n_times; i++) {
        for (int j = i * a.ARRAY.size, k = 0; j < (i+1) * a.ARRAY.size; j++, k++) {
            a.ARRAY.elems[j] = a.ARRAY.elems[k];
        }
    }
    a.ARRAY.size *= n_times;
    push(s, a);
}

/**
 * \brief obtém elemento por índice
 */

void element_by_index(STACK * s) {
    int index = pop_INT(s);
    DATA a = pop(s);
    push(s, a.ARRAY.elems[index]);
}

/**
 * \brief coloca os elementos do array na stack
 */

void array_to_stack(STACK * s) {
    DATA a = pop(s);
    for (int i = 0; i < a.ARRAY.size; i++) {
        push(s, a.ARRAY.elems[i]);
    }
}

/**
 * \brief concatena array com um elemento
 */

void concatenate_array_element(STACK *s) {
    DATA elem = pop(s);
    DATA a = pop(s);
    a.ARRAY.size += 1;
    a.ARRAY.elems = realloc(a.ARRAY.elems, sizeof(struct data) * a.ARRAY.size);
    a.ARRAY.elems[a.ARRAY.size - 1] = elem;
    push(s, a);
}

/**
 * \brief concatena elemento com um array
 */

void concatenate_element_array(STACK *s) {
    DATA a = pop(s);
    DATA elem = pop(s);
    a.ARRAY.size += 1;
    a.ARRAY.elems = realloc(a.ARRAY.elems, sizeof(struct data) * a.ARRAY.size);
    for (int i = a.ARRAY.size - 1; i >= 1; i--) {
        a.ARRAY.elems[i] = a.ARRAY.elems[i - 1];
    }
    a.ARRAY.elems[0] = elem;
    push(s, a);
}

/**
 * \brief concatena array com array
 */

void concatenate_array_array (STACK *s) {
    DATA a1 = pop(s);
    DATA a2 = pop(s);
    int size = a2.ARRAY.size + a1.ARRAY.size;
    a2.ARRAY.elems = realloc(a2.ARRAY.elems, sizeof(struct data) * size);
    for (int i = a2.ARRAY.size, j = 0; i < size; i++, j++) {
        a2.ARRAY.elems[i] = a1.ARRAY.elems[j];
    }
    a2.ARRAY.size = size;
    push(s, a2);
}

/**
 * \brief verifica o tipo de concatenação e chama outra função para concatenar
 * array com array || array com elemento || elemento com array
 */

void concatenate_array(STACK *s) {
    if (s->stack[s->pos].type != ARRAY && s->stack[s->pos - 1].type == ARRAY) {
        concatenate_array_element(s); return;
    }
    if (s->stack[s->pos].type == ARRAY && s->stack[s->pos - 1].type != ARRAY) {
        concatenate_element_array(s); return;
    }
    if (s->stack[s->pos].type == ARRAY && s->stack[s->pos - 1].type == ARRAY) {
        concatenate_array_array(s); return;
    }
}

/**
 * \brief remove o primeiro elemento do array e coloca na stack
 */

void remove_first_element(STACK *s) {
    DATA a = pop(s);
    DATA elem = a.ARRAY.elems[0];
    a.ARRAY.size -= 1;
    a.ARRAY.elems = realloc(a.ARRAY.elems, sizeof(struct data) * a.ARRAY.size);
    for(int i = 0; i < a.ARRAY.size; i++) {
        a.ARRAY.elems[i] = a.ARRAY.elems[i+1];
    }
    push(s, a);
    push(s, elem);
}

/**
 * \brief remove o último elemento do array e coloca na stack
 */

void remove_last_element(STACK *s) {
    DATA a = pop(s);
    DATA elem = a.ARRAY.elems[a.ARRAY.size - 1];
    a.ARRAY.size -= 1;
    a.ARRAY.elems = realloc(a.ARRAY.elems, sizeof(struct data) * a.ARRAY.size);
    push(s, a);
    push(s, elem);
}

/**
 * \brief vai buscar X elementos do início do array
 */

void get_elements_by_first (STACK *s) {
    int n_elems = pop_INT(s);
    DATA a = pop(s);
    for (int i = 0; i < n_elems; i++) {
        push(s, a.ARRAY.elems[i]);
    }
}

/**
 * \brief vai buscar X elementos do fim do array
 */

void get_elements_by_last (STACK *s) {
    int n_elems = pop_INT(s);
    DATA a = pop(s);
    for (int i = a.ARRAY.size - n_elems; i < a.ARRAY.size; i++) {
        push(s, a.ARRAY.elems[i]);
    }
}