#include "fila_circular.h"

/* Cria uma fila vazia */
void criar(FILA *f) {
    f->inic = 0;
    f->fim = -1; // importante pois nos permimte inserir na pos 0 de acordo a operacao
    f->qtd = 0;
}

/*  Testa se está vazia com base na quantidade */
int vazia(FILA f) {
    return (f.qtd == 0);
}

/*  Obtem o elemento do inicio sem remover */
int inicio(FILA f, int *elem) {
    if (vazia(f)) return 0;
    *elem = f.v[f.inic];
    return 1;
}

/* Insere na fila */
int insere(FILA *f, int dado) {
    
    if (f->qtd == MAX) return 0; // se a f estiver cheia
    
    (f->qtd)++; 
    
    f->fim = (f->fim + 1) % MAX;  //semre q ele chega no fim para inserir(reaproveitar as pos dos elementos q foram removidos) ele volta a pos 0
    f->v[f->fim] = dado;
    return 1;
}


 /*nesta quando removemos os dados continuam la mas nao considerados da fila o qtd so tem os reais,
 se precisarmos preencher os espacos dos elementos removidos basta sobrescrever*/
int remove_circular(FILA *f, int *dado) {
    if (vazia(*f)) return 0;
    
    inicio(*f, dado); // passa uma copia da fila e o ponteiro dado para guardar
    (f->qtd)--;
    
    f->inic = (f->inic + 1) % MAX;  // se removemos o inicio entao ele avanca para proxima pos apos esse inciio e essa pos passa a ser o novo inicio
    
    return 1;
}
