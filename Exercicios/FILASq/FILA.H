#ifndef FILA_H
#define FILA_H

#include <stdio.h>

#define MAX 100


typedef struct fila {
    int v[MAX];
    int inic, fim, qtd;
} FILA;


void criar(FILA *f);
int vazia(FILA f);
int inicio(FILA f, int *elem);
int insere(FILA *f, int dado);
int remove_fila(FILA *f, int *dado); // Alterado para 'remove_fila' pois 'remove' é reservada em C

#endif
