#include "pilha.h"

/* Inicializa a pilha vazia: o topo aponta para o início da base  */
int inicializa(PILHA *ps) {
    ps->topo = ps->base; //fazer o topo ser igual a base 
    return 1; 
}


int vazia(PILHA *ps) {
    return (ps->topo == ps->base) ? 1 : 0;  //caso for veraderio retorna 1 e se nao retorna 0
}

/* Coloca dado na pilha. Apresenta erro se não houver espaço  */
int push(PILHA *ps, int dado) {
    // Verifica estouro
    if (ps->topo ==MAX)  return 0;
    
    *ps->topo = dado;    // quremos mudar o conteudo dentro de topo,se usassemos ps estariamos a acedere apenas endereco o q daria erro
    ps->topo++;       
    return 1;         
}

/* Retira o valor do topo da pilha e atribui a dado  */
int pop(PILHA *pp, int *dado) {
    if (vazia(pp) == 1) 
        return 0;        
    
    pp->topo--; // pq topo e a ultima pos livre entao decrementamos para conseguir estra na pos em q contem dado        
    *dado = *pp->topo;  
    return 1;           
}

/* Retorna o valor do topo sem remove-lo  */
int topo_pilha(PILHA *ps, int *dado) {
    // faz um po e retorna o dado q esta no topo e dpois faz um push pra colocar a pilha como estav
    if (pop(ps, dado) == 0)
        return 0;         
    
    return push(ps, *dado);
}
