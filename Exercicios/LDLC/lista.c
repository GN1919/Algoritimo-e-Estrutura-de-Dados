#include "ldl_circular.h"

// Funcao para criar a lista vazia  com o no Cabeça(no cabeca  e so um no sem dados q vai ajudar nas operacoes da lista)
LISTA criar_lista() {
    LISTA L = (LISTA) malloc(sizeof(struct lista));
    LDL no_cab = getno(); //alloca memoria para o noso no cabeca q aponta para a struct ldl
    
    if (L != NULL && no_cab != NULL) { // verifica se a nosa lista foi criada e se o nosso no cabeca tambem 
        no_cab->info = -1; // sem dado pq e no cabeca 
        no_cab->post = no_cab;
        no_cab->ant = no_cab;
        L->cab = no_cab; // fazer a lista receber o nosso no cabeca 
    }
    return L; // retorna  alista ja com no cabeca 
}

LDL getno() {
    return (LDL) malloc(sizeof(struct ldl));
}

void freeno(LDL p) { //  e um ponteiro para struct ldl(LDL ja e um pponteiro entao automaticamente o p tambem consegue aceder struct no
    free(p);
}

//insere no x a direita de no p
// p pode ser o nó cabeça ou qualquer outro nó
void inserepost(p, x)
LDL p; int x; {
    LDL q, dir; // dir e ponteiro auxiliar para o no q esta direita de p
    if (p == NULL) { // se queremos inserir no x depois de no p,se esse no p for null ou n existir emtao erro
        printf("insercao vazia\n");
        return;
    }
    q = getno();
    q->info = x;
    // a logica e fazer o dir ser o p->post,depois faco o q->post ser o dir e o q->ant ser o p e depois fazer o dir ->ant ser o q e depois o p->post ser o q

    dir = p->post; // dir recebe o no q esta depois(a direita) do no p
    q->post = dir; // o posteirio de no q sera o no depois do no p
    q->ant = p; // faz o anterior de q ser o no p
    dir->ant = q;//dir (q e o p->post(o no depois  de no p))) agora o seu anterior aponta para q
    p->post = q;// o p->post era o no depois de p,agora o no depois de p sera o q
}


void insereant(p, x)
LDL p; int x; {
    LDL q, esq;
    if (p == NULL) {
        printf("insercao vazia\n");
        return;
    }
    q = getno();
    q->info = x;
    //a logica e fazeer o anteiror de q(novo no) ser o anteriror de p e depois o posterior de q ser p,depois fazer o posteriror do anterior ao p  ser q e o anterior do p ser q
    esq = p->ant; // O no que está atualmente a esquerda de p
    
    q->ant = esq; //Faz o anterior de q ser esq, que era o anterior de p
    q->post = p; // faz o proximo de  q ser o  p
    esq->post = q; // faz o posterior do anteriior de p  ser q
    p->ant = q; // agora o anteriro  p sera o q
}

//  remove exatamente o no p passado como parametro
void remover(p, px)
LDL p; int *px; { // px e ponteiro para guardar o no p removido
    LDL q, r;
    if (p == NULL) {
        printf("remocao vazia\n");
        return;
    }
    *px = p->info; // guarda o a informcaoa do no q estamos a remover 
    q = p->ant; // q agora é o no anteiror a p
    r = p->post;// r agora é o no seguinte a p
    
    // Liga o anterior ao próximo, excluindo o p da corrente
    q->post = r; //q é o anterior a p entao fazemos o posterior de q ser o r(r e o posteriior de p)
    r->ant = q; // fazer o anterior de r ser o q
    
    freeno(p);
}
