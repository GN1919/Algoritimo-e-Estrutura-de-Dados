#include "lista.h"

/* Função de Alocação */
NO getno() {
    NO p;  // variavel p qe do tipo no
    p = (NO) malloc(sizeof(struct no)); // Aloca memória dinamicamente      
    
    return p;
}

/* Inicializa a lista com o no Cabeça */
void inicializar(LISTA *L) {//  L aponta para onde LISTA aponta entao e ponteiro para ponreiro
    *L = (LISTA) malloc(sizeof(struct lista));  //quando faco isso estou a fazer lista=...,estou alocando memoria para struct de lista e retorna LISTA  qja foi definido com ponteiro para nossa struc litsa
    (*L)->cab = getno(); // Cria o no cabeça ou seja deveolve um No para cab
    (*L)->cab->prox = NULL; // uso *l->cab e nao l->cab pq tenho como parametro LISTA *l mas LISTA nao e a minha struct lista e apenas o ponteiro para a minha struct lista entao baiscamente o l aponta para quem vai apontar para a minha struc lista e e assimq acedemos o campo cab
}


// insered(p, x) insere x DEPOIS do no p.
void insered_base(NO p, int x) {
    NO novo;
    if (p == NULL) {  // caso o no p nao existir(ou seja se queremos inserir no x depois de no p e esse no p n existir)
        exit(1);  //terminou com erro
    }
    novo = getno();             // Aloca novo no
    novo->info_int = x;         // Atribui o valor ,para atribuir os outros campos tera q criar outras funcoes o mesmo genero e passar parametro char e registo
    novo->prox = p->prox;       // Novo aponta para o próximo de p,e apartir deste momento op->pro ja nao tem por onde apontar
    p->prox = novo;             // entao P->prox aponta para o novo 
}

/* Inserir no Início - trivial usando o no cabeça  */
void inserir_inicio(LISTA L, int x) {
    
    insered_base(L->cab, x);
}

/* Inserir no Fim - Requer encontrar o último elemento */
void inserir_fim(LISTA L, int x) {
    NO aux = L->cab; //aux aqui e o tipo NO e recebe o no cabeca 
    while (aux->prox != NULL) { // Percorre até o último 
        aux = aux->prox;
    }
    insered_base(aux, x); // insere o novo no apos aux q e o ultimo no
}

/* Inserir em qualquer posição k */
void inserir_posicao_k(LISTA L, int x, int k) {
    NO aux = L->cab;
    // Para inserir na posição k, caminhamos k-1 vezes
    for (int i = 0; i < k - 1 && aux != NULL; i++) {
        aux = aux->prox;
    }
    insered_base(aux, x); // apos o p esta r na pos em q i=k-1 ele ja esta na posicao do no no anteiror a posicao q queremos inseriri
}


// A removed(p, px) remove o nó DEPOIS de p.
void removed_base(NO p, int *px) {
    NO q;
    if ((p == NULL) || (p->prox == NULL)) { 
        printf("remocao nula\n");  
        return;
    }
    q = p->prox;             // guardar o no a ser remoovido em q e o q sera o nosso no q vai ser removido
    *px = q->info_int;       // Guarda a informcao de no q  em px,para podermos ter acesso a ele fora da lista,o *px e o cpnteudo e o px e endereco
    p->prox = q->prox;       // faz o no p apopntar para o proximo no de q
    free(q);                 // Desaloca a memória [cite: 104, 74]
}

/* Remoção no início */
void remover_inicio(LISTA L, int *px) {
    removed_base(L->cab, px); // Remove o que está após o cabeça
}

/* Remoção no fim  */
void remover_fim(LISTA L, int *px) {
    NO p = L->cab;
    if (p->prox == NULL) return;  // lista vazia
    // Busca o penúltimo para remover o último
    while (p->prox->prox != NULL) {
        p = p->prox;  //  o proximo do proximo do no p , ou sej quando o proximo do proximo do no p for igual a null ai sim temos o no anteirior ao ultimmo no da lsita 
    }
    removed_base(p, px);
}

/* Remoção em posição k  */
void remover_posicao_k(LISTA L, int k, int *px) {
    NO p = L->cab;
    for (int i = 0; i < k - 1 && p != NULL; i++) { //  funciona de forma parecida a funcao inserir em k pos o q muda e so nof inal aqui cha,mamos removebase
        p = p->prox;
    }
    removed_base(p, px);
}

/* Pesquisa - Percorre a lista comparando o valor  */
void pesquisa(LISTA L, int x) {
    NO p = L->cab->prox;
    int pos = 1;
    while (p != NULL) {
        if (p->info_int == x) {
            printf("Elemento %d encontrado na posicao %d\n", x, pos);
            return;
        }
        p = p->prox;
        pos++;
    }
    printf("Elemento nao encontrado.\n");
}
