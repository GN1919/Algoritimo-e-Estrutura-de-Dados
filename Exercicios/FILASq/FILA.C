#include "fila.h"

/* 1. Cria uma fila vazia: fim em -1 e qtd em 0 */
void criar(FILA *f) {
    f->inic = 0;
    f->fim = -1;
    f->qtd = 0;
}

/* 2. Testa se a fila está vazia usando o contador qtd */
int vazia(FILA f) {
    return (f.qtd == 0);
}

/* 3. Obtém o elemento do início sem remover */
int inicio(FILA f, int *elem) {
    if (vazia(f)) return 0;
    *elem = f.v[f.inic];
    return 1;
}

/* 4. Insere no fim com lógica c */
int insere(FILA *f, int dado) {
    
    if (f->fim == MAX-1) return 0;  // s fim = a max-1 q e o ultimo elemento ou pos valida
    
    f->fim ++;
    f->v[f->fim] = dado;
    return 1;
}

/* 5. Remove do início  */
int remove_fila(FILA *f, int *dado) {
    if (f->qtd == 0) return 0;           // fila vazia
    
    *dado = f->v[f->inic];               // pega o elemento do início
    f->inic++;                            // move o índice do início para frente
    f->qtd--;                             // decrementa a quantidade
    
    return 1;                             // sucesso
}

