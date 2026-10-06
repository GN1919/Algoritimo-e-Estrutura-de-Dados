#ifndef LDL_CIRCULAR_H
#define LDL_CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do No
struct ldl {
    int info;
    struct ldl *post;
    struct ldl *ant;    // o mesmo conceito q usei na lista simplesmente ligada 
};
typedef struct ldl *LDL;


struct lista {
    LDL cab; 
};
typedef struct lista *LISTA;

// Protótipos das funções seguindo o arquivo
LISTA criar_lista();
LDL getno();
void freeno(LDL p);
void inserepost(LDL p, int x);
void insereant(LDL p, int x);
void remover(LDL p, int *px);

#endif
