#include "fila_dinamica.h"

/* Inicialização da fila */
void filaInicializa(fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

/* Verifica se a fila está vazia */
int filaVazia(fila f) {
    return (f.inicio == NULL); //retorna 1 se true ou 0 se false
}

/* Inserção (sempre no fim) */
void filaInsere(fila *f, int elemento) {
    no *novo;
    novo = (no *) malloc(sizeof(no));
    novo->item = elemento;
    novo->prox = NULL; // ainda n entrou na fila mas como sera o ultimo fazemos ele apontar para null
    /*aqui uma vez q a funcao filavazia recebe uma copia da fila(f) se passamos f estaria a passar um ponteiro 
	pq nessa funcao insere temos parametro fil *f,entao fazendo *f estamos a desreferenciar  e faz passar uma copia para a funcao fvazia
	*/
	  if (filaVazia(*f)) {
        f->inicio = novo; //caso a fila estiver vazia faz o novo ser o inicio
    } else {
        f->fim->prox = novo; // caso a fila tiver elemento faz o novo ser o proximo do fim antigo pq o fim atul sera oo novo,ou seja ele nao apontara mais para null
    }

    f->fim = novo; // agora fim aponta para novo no
}

/* Remove e guarda o elemneto (sempre no inicio) */
int filaRemove(fila *f, int *elemento) {
    no *aux; //  tem q ser ponteiro pois precisamos passar a memoria*(endereco) do no a ser liberado no free

    if (filaVazia(*f)) {
        return 0;
    }

    *elemento = f->inicio->item;
    aux = f->inicio; // guardamos pra depois dar ofre pq nao podemos dar o free no inicio pois perderiamos acesso aos restantes elemento da fila

    f->inicio = f->inicio->prox; // agora o inicio passa apontar pra o proximo do incio antigo,ou seja temos um novo inicio

    if (f->inicio == NULL) {  //  se apos a atualizacao do novo inicio for null ou seja a fila so tinha 1 elemento entao faz com q ele esteja vazia
        f->fim = NULL; // fazemos fim null pra fazer a fila estar vazia totalmente 
    }

    free(aux);
    return 1;
}

