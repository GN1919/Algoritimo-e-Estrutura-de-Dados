#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

void initFila(Fila *F) {
  F->fim = F->inicio = NULL;
}

int vaziaFila(Fila *F) {
  return F->fim == NULL && F->inicio == NULL;
}

NO *getNOFila(Token tk) {
  NO *ptr = (NO*)malloc(sizeof(NO));
  if(ptr == NULL) {
    perror("Erro de alocacao de memoria.\n");
    exit(-1);
  }
  ptr->tk = tk;
  ptr->prox = NULL;
  return ptr;
}

int inserir(Fila *F, Token tk) {
  NO *ptr = getNOFila(tk);
  if(vaziaFila(F)) {
    F->fim = ptr;
    F->inicio = ptr;
  } else {
    F->fim->prox = ptr;
    F->fim = ptr;
  }
  return 1;
}

int remover(Fila *F) {
  if(vaziaFila(F)) return 0;
  NO *auxi;
  if(F->fim == F->inicio) {
    auxi = F->fim;
    F->fim = F->inicio = NULL;
  } else {
    auxi = F->inicio;
    F->inicio = auxi->prox;
  }
  free(auxi);
  return 1;
}

Token frente(Fila *F) {
  Token tk = {'n', NONE, -1};
  if(vaziaFila(F)) return tk;
  return F->inicio->tk;
}

