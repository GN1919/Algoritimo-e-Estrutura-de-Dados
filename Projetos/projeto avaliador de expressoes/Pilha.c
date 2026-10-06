#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>

void initPilha(Pilha *P) {
  P->cabeca = NULL;
}

No *getNOPilha(Token tk) {
  No *ptr = (No*)malloc(sizeof(No));
  if(ptr == NULL) {
    perror("Erro de alocacao de memoria.\n");
    exit(-1);
  }
  ptr->prox = NULL;
  ptr->tk = tk;
  return ptr;
}

int vaziaPilha(Pilha *P) {
  return P->cabeca == NULL;
}

int push(Pilha *P, Token tk) {
  No *ptr = getNOPilha(tk);
  if(vaziaPilha(P)) {
    P->cabeca = ptr;
    return 1;
  }
  ptr->prox = P->cabeca;
  P->cabeca = ptr;
  return 1;
}

int pop(Pilha *P) {
  if(vaziaPilha(P)) return 0;
  No *auxi = P->cabeca;
  P->cabeca = P->cabeca->prox;
  free(auxi);
  return 1;
}

Token top(Pilha *P) {
  Token tk = {'n', NONE, -1};
  if(vaziaPilha(P)) return tk;
  return P->cabeca->tk;
}

