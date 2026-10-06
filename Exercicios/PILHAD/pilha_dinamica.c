#include "pilha_dinamica.h"

/* faz comq a pilha comeca vazia*/
void pInicializa(Pilha *p) {
    p->topo = NULL; 
}

/* Verifica se está vazia: retorna 1 (True) se o topo for NULL  */
int pVazia(Pilha p) {
    return (p.topo == NULL); 
}

/* Insere elemento: aloca memória e atualiza o topo  */
void push(Pilha *p, int ele) {
    NO novoNo; 
    novoNo = malloc(sizeof(struct no)); 
    novoNo->item = ele; 
    // aqui cada novo no deve apontar para seu prox e seu prox esta a baio dele pq a pilha cresce de baixo para cima
    // O novo nó aponta para o antigo topo
    novoNo->prox = p->topo;     
    // O topo passa a ser o novo nó
    p->topo = novoNo; //agora o topo recebe o novono
}

/* Remove elemento: guarda o valor, move o topo e libera o nó  */
int pop(Pilha *p, int *ele) {
    NO aux; 
    
    
    if (pVazia(*p) == FALSE) { 
        *ele = p->topo->item;  // Pega o valor do nó atual E GURADA NO PONTEIRO ELE
        aux = p->topo;        // Guarda o endereço do no  para depois dar free
        p->topo = p->topo->prox; // Move o topo para o próximo nó
        free(aux);            // Libera a memória
        return 1;
    } else {
        fprintf(stderr, MSG_PILHAVAZIA); 
        return 0;
    }
}

/* Retorna o valor do topo sem remover  */
int topo(Pilha p) {
    if (pVazia(p) == FALSE) {
        return p.topo->item;
    }
    return -1; // Ou outro valor de erro
}
