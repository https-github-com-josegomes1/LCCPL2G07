/**
 * @file Ficheiro que contém as funcionalidades relativas a stack do projeto
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
 * Tamanho do array STACK
 */

#define STACK_SIZE 10240

/**
 * O array que carrega os valores da STACK;
 */

long STACK[STACK_SIZE];

/**
 * A posição que contém o index do topo da stack, sendo -1 quando a stack está vazia
 */

int pos = STACK_EMPTY;

/**
 * \brief Esta função verifica se a stack está vazia
 *
 * @returns o valor 1 se estiver vazia, o valor 0 se não estiver vazia
 *  
 */

int IsStackEmpty () {

    int stack_vazia = 0;

    if (pos == -1) stack_vazia = 1;

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

    if (pos == STACK_SIZE - 1) stack_cheia = 1;

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


/**
 * \brief Esta função prepara uma operação aritmética envolvendo 2 operandos
 * 
 * A função retira os dois elementos que estão no topo da stack
 * Cada elemento retirado é guardado em um endereço de memória 
 * para mais tarde efetuar o push da operação aritmética envolvendo
 * estes dois elementos
 *
 * @param operando1 endereço de memória que vai guardar um elemento retirado da stack
 * @param operando2 endereço de memória que vai guardar o outro elemento retirado da stack
 */

void pop_double (long *operando1, long *operando2) {

    *operando2 = pop();
    *operando1 = pop();
    
}

/**
 * \brief Esta função mostra o conteúdo que está na stack
 */

void PrintStack () {

    for (int i = 0; i <= pos; i++) {

        printf("%ld", STACK[i]);

    }

    putchar('\n');

}
