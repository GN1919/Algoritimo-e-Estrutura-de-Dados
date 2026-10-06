#ifndef PILHA_SEQUENCIAL_H
#define PILHA_SEQUENCIAL_H

#include <stdio.h>

#define MAX 100 

/* Estrutura de dados conforme slide 10  */
typedef struct no {
    int base[MAX];
    int *topo;
} PILHA;   

/* Protótipos das operações  */
int inicializa(PILHA *ps);
int vazia(PILHA *ps);
int push(PILHA *ps, int dado);
int pop(PILHA *pp, int *dado);
int topo_pilha(PILHA *ps, int *dado); // Nome alterado para evitar conflito com o tipo

#endif
