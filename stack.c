/**
 * 
 * @file Ficheiro que contém as funcionalidades relativas a stack do projeto
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 10240
#define STACK_EMPTY (-1)
#define STACK_FULL 10239

long STACK[STACK_SIZE]; 
int pos = STACK_EMPTY; // A posição que contém a posição do topo da stack, sendo -1 quando a stack está vazia

/**
 * \brief Esta função verifica se a stack está vazia
 *
 * @returns o valor 1 se estiver vazia, o valor 0 se não estiver vazia
 *  
 */

int IsStackEmpty () {

    int stack_vazia = 0;

    if (pos == STACK_EMPTY) stack_vazia = 1;

    return stack_vazia;

}

/**
 * \brief Esta função verifica se a stack está cheia
 *
 * @returns o valor 1 se estiver cheia, o valor 0 se não estiver cheia
 * 
 */

int IsStackFull () {

    int stack_cheia = 0;

    if (pos == STACK_FULL) stack_cheia = 1;

    return stack_cheia;

}

/**
 * \brief Esta função adiciona um elemento no topo da stack
 *
 * @param valor O valor que vai ser inserido na stack
 * 
 */

void push (long valor) {

    if (!IsStackFull())
        STACK[++pos] = valor;

}

/**
 * \brief Esta função retira o elemento que está no topo a stack
 *
 * @returns O elemento que foi retirado da stack
 * 
 */

long pop () {

    if (!IsStackEmpty()) 
        return STACK[pos--];

    return 0;

}
