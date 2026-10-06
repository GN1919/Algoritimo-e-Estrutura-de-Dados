#ifndef pilha_dinamica_h
#define pilha_dinamica_h

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

#define MSG_PILHAVAZIA "\nA Pilha está vazia\n"  // quando a pilha estiver vazia ao inves de escrever a mensgame pilha vazia em tds os printfs usaomo a macro msg...
#define TRUE 1  // ao inves de usar boolean usamos a constantes true e false para verdadeiro e falso
#define FALSE 0

/* Estrutura do Nó e da Pilha */
typedef struct no {
    int item;
    struct no *prox;
} *NO;

typedef struct {
    NO topo; // apartir do topo consigo percorrer a lista e aceder a outros nos
} Pilha;


void pInicializa(Pilha *p);
int pVazia(Pilha p);
void push(Pilha *p, int ele);
int pop(Pilha *p, int *ele);
int topo(Pilha p);

#endif
