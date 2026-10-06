#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H
// implemnetcao de fila circular como resolucao do problema da fila sequencial
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
int remove_circular(FILA *f, int *dado); 
#endif
