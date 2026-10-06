#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>

/* Estrutura do nó da fila */
typedef struct no {
    int item;
    struct no *prox;
} no;

/* Estrutura da fila */
typedef struct {
    no *inicio;
    no *fim;
} fila;

/* Protótipos das funções */
void filaInicializa(fila *f);
int filaVazia(fila f);
void filaInsere(fila *f, int elemento);
int filaRemove(fila *f, int *elemento);

#endif

